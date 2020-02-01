
#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command)) // 文字列を1つ受け取る
        return NULL;
    sts = system(command); // シェルを実行する
    return PyLong_FromLong(sts); // Pythonオブジェクトに変換して返す
}

// メソッドテーブル
static PyMethodDef SpamMethods[] = {
    // {関数名, アドレス, 引数, ドキュメント}
    {"system", spam_system, METH_VARARGS,
     "Execute a shell command."},
    {NULL, NULL, 0, NULL} // 番兵
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",     // モジュール名
    NULL,       // モジュールのドキュメント
    -1,         // モジュールがグローバル変数に状態を保持する場合は -1
    SpamMethods // モジュールのメソッドテーブル
};

// 初期化関数
PyMODINIT_FUNC
PyInit_spam(void)
{
    return PyModule_Create(&spammodule);
}
