
# Extending Python by C

[C や C++ による Python の拡張](https://docs.python.org/ja/3/extending/extending.html) の練習

ビルド：

```
$ python setup.py build_ext -i
```

実行：

```
$ python
>>> import spam
>>> spam.system("date +%Y-%m-%d")
2020-02-02
0
>>>
>>> import xor
>>> xor.xor(b'\x00\x01\x02', b'\x00\x03\x04')
b'\x00\x02\x06'
>>>
```


-----

XORのベンチマーク

```
$ python xor_benchmark.py
## benchmarker:         release 4.0.1 (for python)
## python version:      3.7.6
## python compiler:     Clang 11.0.0 (clang-1100.0.33.16)
## python platform:     Darwin-18.7.0-x86_64-i386-64bit
## python executable:   /usr/local/opt/python/bin/python3.7
## cpu model:           Intel(R) Core(TM) i7-3770S CPU @ 3.10GHz
## parameters:          loop=10000, cycle=1, extra=0

##                        real    (total    = user    + sys)
c_xor                   1.3695    1.3700    0.0900    1.2800
py_xor                  3.3671    3.3600    2.0800    1.2800
pycrypto_xor            1.3490    1.3500    0.0700    1.2800

## Ranking                real
pycrypto_xor            1.3490  (100.0) ********************
c_xor                   1.3695  ( 98.5) ********************
py_xor                  3.3671  ( 40.1) ********

## Matrix                 real    [01]    [02]    [03]
[01] pycrypto_xor       1.3490   100.0   101.5   249.6
[02] c_xor              1.3695    98.5   100.0   245.9
[03] py_xor             3.3671    40.1    40.7   100.0
```

XORの処理はPythonで書くよりCで書いた方が 2.5 倍高速化する


-----

メモ

- 引数の解釈と値の構築 : https://docs.python.org/ja/3.7/c-api/arg.html
- bytearray を受け取る : `PyArg_ParseTuple(args, "yy", &str1, &str2)`
- Pythonオブジェクトの作成 : https://docs.python.org/ja/3.8/c-api/concrete.html
- bytearray を返す : https://docs.python.org/ja/3.8/c-api/bytearray.html
- bytearray の受け取りと `y*` の使い方 : https://github.com/python/cpython/blob/master/Modules/_testcapimodule.c#L1419
