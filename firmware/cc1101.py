from math import log
from textwrap import dedent


def limit(bits):
    def limit_decorator(func):
        def wrapped_function(*args, **kwargs):
            ret = func(*args, **kwargs)
            return (ret if (ret < 2 ** bits - 1) else 2 ** bits - 1) if ret > 0 else 0

        return wrapped_function

    return limit_decorator


class CC1101(object):
    def __init__(
        self,
        *,
        oscilator_frequency=26_000_000,
        oscilator_error=0,
        carier_frequency,
        data_rate,
        channel_spacing=200_000,
    ):
        self._fosc = oscilator_frequency * (1 - oscilator_error)
        self._freq = carier_frequency
        self._baud = data_rate
        self._cspc = channel_spacing

    @property
    def FREQ(self):
        return round(self._freq / (self._fosc / 2 ** 16)).to_bytes(
            length=3, byteorder="big", signed=False
        )

    @property
    @limit(4)
    def DRATE_E(self):
        return int(log(self._baud * 2 ** 20 / self._fosc) / log(2))

    @property
    @limit(8)
    def DRATE_M(self):
        return int((self._baud * 2 ** 28) / (self._fosc * 2 ** self.DRATE_E) - 256)

    @property
    @limit(2)
    def CHANSPC_E(self):
        return int(log(self._cspc * 2 ** 10 / self._fosc) / log(2))

    @property
    @limit(8)
    def CHANSPC_M(self):
        return int((self._cspc * 2 ** 18) / (self._fosc * 2 ** self.CHANSPC_E) - 256)

    @property
    def freq(self):
        return (
            self._fosc
            / 2 ** 16
            * (int.from_bytes(self.FREQ, byteorder="big", signed=False))
        )

    @property
    def baud(self):
        return (256 + self.DRATE_M) * 2 ** self.DRATE_E * self._fosc / 2 ** 28

    @property
    def cspc(self):
        return (256 + self.CHANSPC_M) * 2 ** self.CHANSPC_E * self._fosc / 2 ** 18

    def __str__(self):
        return dedent(
            f"""\
            CC1101 Configuration:
                Carier Frequency: {self.freq}
                Data Rate:        {self.baud}
                Channel spacing:  {self.cspc}
            """
        )
