
#define PY_SSIZE_T_CLEAN
#include <Python.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static PyObject *
xor_xor(PyObject *self, PyObject *args)
{
    char *buffer1, *buffer2;
    char *xored_bytes;
    Py_ssize_t buffer1_len, buffer2_len;
    Py_ssize_t len;
    PyObject *py_bytes;

    // 引数でバイト列を2個受け取る
    if (!PyArg_ParseTuple(args, "y#y#",
            &buffer1, &buffer1_len, &buffer2, &buffer2_len))
        return NULL;

    // XORした結果を返すための文字列領域の確保
    len = MIN(buffer1_len, buffer2_len);
    xored_bytes = (char *)malloc(sizeof(char) * len);

    // XOR演算
    for (int i = 0; i < len; i++) {
        xored_bytes[i] = *buffer1++ ^ *buffer2++;
    }

    // Pythonのバイト文字列に変換
    py_bytes = PyBytes_FromStringAndSize(xored_bytes, len);
    free(xored_bytes);
    return py_bytes;
}

// メソッドテーブル
static PyMethodDef MethodTable[] = {
    // {関数名, アドレス, 引数, ドキュメント}
    {"xor", xor_xor, METH_VARARGS, "xor two bytes."},
    {NULL, NULL, 0, NULL} // 番兵
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "xor",      // モジュール名
    NULL,       // モジュールのドキュメント
    -1,         // モジュールがグローバル変数に状態を保持する場合は -1
    MethodTable // モジュールのメソッドテーブル
};

// モジュール初期化関数
PyMODINIT_FUNC
PyInit_xor(void)
{
    return PyModule_Create(&module);
}
