
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

メモ

- 引数の解釈と値の構築 : https://docs.python.org/ja/3.7/c-api/arg.html
- bytearray を受け取る : `PyArg_ParseTuple(args, "yy", &str1, &str2)`
- Pythonオブジェクトの作成 : https://docs.python.org/ja/3.8/c-api/concrete.html
- bytearray を返す : https://docs.python.org/ja/3.8/c-api/bytearray.html
- bytearray の受け取りと `y*` の使い方 : https://github.com/python/cpython/blob/master/Modules/_testcapimodule.c#L1419
