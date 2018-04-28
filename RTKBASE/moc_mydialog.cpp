/****************************************************************************
** Meta object code from reading C++ file 'mydialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mydialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyDialog_t {
    QByteArrayData data[18];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyDialog_t qt_meta_stringdata_MyDialog = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyDialog"
QT_MOC_LITERAL(1, 9, 11), // "closeSignal"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 15), // "Run_Log_str2str"
QT_MOC_LITERAL(4, 38, 16), // "Run_Base_str2str"
QT_MOC_LITERAL(5, 55, 19), // "recupdonneesStr2str"
QT_MOC_LITERAL(6, 75, 1), // "i"
QT_MOC_LITERAL(7, 77, 12), // "FermeStr2str"
QT_MOC_LITERAL(8, 90, 9), // "finThread"
QT_MOC_LITERAL(9, 100, 12), // "Close_Window"
QT_MOC_LITERAL(10, 113, 12), // "Start_AutoPP"
QT_MOC_LITERAL(11, 126, 10), // "Test_start"
QT_MOC_LITERAL(12, 137, 9), // "Test_stop"
QT_MOC_LITERAL(13, 147, 7), // "StopLog"
QT_MOC_LITERAL(14, 155, 45), // "on_pushButton_run_rnx2rtk_pro..."
QT_MOC_LITERAL(15, 201, 27), // "on_progressBar_valueChanged"
QT_MOC_LITERAL(16, 229, 5), // "value"
QT_MOC_LITERAL(17, 235, 12) // "Save_Options"

    },
    "MyDialog\0closeSignal\0\0Run_Log_str2str\0"
    "Run_Base_str2str\0recupdonneesStr2str\0"
    "i\0FermeStr2str\0finThread\0Close_Window\0"
    "Start_AutoPP\0Test_start\0Test_stop\0"
    "StopLog\0on_pushButton_run_rnx2rtk_process_RGP_clicked\0"
    "on_progressBar_valueChanged\0value\0"
    "Save_Options"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   87,    2, 0x0a /* Public */,
       4,    0,   88,    2, 0x0a /* Public */,
       5,    1,   89,    2, 0x0a /* Public */,
       7,    0,   92,    2, 0x0a /* Public */,
       8,    1,   93,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x0a /* Public */,
      15,    1,  102,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,

       0        // eod
};

void MyDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyDialog *_t = static_cast<MyDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Run_Log_str2str(); break;
        case 2: _t->Run_Base_str2str(); break;
        case 3: _t->recupdonneesStr2str((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->FermeStr2str(); break;
        case 5: _t->finThread((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->Close_Window(); break;
        case 7: _t->Start_AutoPP(); break;
        case 8: _t->Test_start(); break;
        case 9: _t->Test_stop(); break;
        case 10: _t->StopLog(); break;
        case 11: _t->on_pushButton_run_rnx2rtk_process_RGP_clicked(); break;
        case 12: _t->on_progressBar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->Save_Options(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyDialog::closeSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MyDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MyDialog.data,
      qt_meta_data_MyDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyDialog.stringdata0))
        return static_cast<void*>(const_cast< MyDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MyDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MyDialog::closeSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
