
# XOR speed test (C vs Python vs PyCryptodome)

from benchmarker import Benchmarker # pip install Benchmarker
import secrets

import xor # My XOR module written by C
from Crypto.Util import strxor # pip install pycryptodome

# C
c_xor = xor.xor

# Python
def py_xor(bytes1, bytes2):
    return bytearray([c1 ^ c2 for (c1,c2) in zip(bytes1, bytes2)])

# PyCryptodome
cryptodome_xor = strxor.strxor


def initdata():
    return secrets.token_bytes(2048), secrets.token_bytes(2048)

with Benchmarker(10000, width=20) as bench:

    @bench('c_xor')
    def _(bm):
        for i in bm:
            b1, b2 = initdata()
            c_xor(b1, b2)

    @bench('py_xor')
    def _(bm):
        for i in bm:
            b1, b2 = initdata()
            py_xor(b1, b2)

    @bench('pycrypto_xor')
    def _(bm):
        for i in bm:
            b1, b2 = initdata()
            cryptodome_xor(b1, b2)
