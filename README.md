
# Extending Python by C

[C や C++ による Python の拡張](https://docs.python.org/ja/3/extending/extending.html) の練習

```
$ python setup.py build_ext -i
$ python
>>> import spam
>>> spam.system("ls")
README.md			spam.cpython-37m-darwin.so
build				spammodule.c
setup.py
0
>>>
```
