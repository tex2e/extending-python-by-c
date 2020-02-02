
#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    // 文字列を1つ受け取る
    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command); // シェルを実行する
    return PyLong_FromLong(sts); // 結果をPythonオブジェクトに変換して返す
}

// メソッドテーブル
static PyMethodDef MethodTable[] = {
    // {関数名, アドレス, 引数, ドキュメント}
    {"system", spam_system, METH_VARARGS,
     "Execute a shell command."},
    {NULL, NULL, 0, NULL} // 番兵
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "spam",     // モジュール名
    NULL,       // モジュールのドキュメント
    -1,         // モジュールがグローバル変数に状態を保持する場合は -1
    MethodTable // モジュールのメソッドテーブル
};

// モジュール初期化関数
PyMODINIT_FUNC
PyInit_spam(void)
{
    return PyModule_Create(&module);
}
