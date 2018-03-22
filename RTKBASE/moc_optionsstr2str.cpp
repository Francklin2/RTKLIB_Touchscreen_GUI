/****************************************************************************
** Meta object code from reading C++ file 'optionsstr2str.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "optionsstr2str.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionsstr2str.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OptionsStr2str_t {
    QByteArrayData data[14];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionsStr2str_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionsStr2str_t qt_meta_stringdata_OptionsStr2str = {
    {
QT_MOC_LITERAL(0, 0, 14), // "OptionsStr2str"
QT_MOC_LITERAL(1, 15, 13), // "OuvreDefault1"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "SaveBase"
QT_MOC_LITERAL(4, 39, 8), // "LoadBase"
QT_MOC_LITERAL(5, 48, 14), // "AppelleClavier"
QT_MOC_LITERAL(6, 63, 11), // "MyLineEdit*"
QT_MOC_LITERAL(7, 75, 4), // "line"
QT_MOC_LITERAL(8, 80, 27), // "on_pushButtonManual_clicked"
QT_MOC_LITERAL(9, 108, 34), // "on_radioButtonPositionAuto_cl..."
QT_MOC_LITERAL(10, 143, 36), // "on_radioButtonPositionManual_..."
QT_MOC_LITERAL(11, 180, 34), // "on_UpdateOptionspushButton_cl..."
QT_MOC_LITERAL(12, 215, 6), // "Charge"
QT_MOC_LITERAL(13, 222, 8) // "baseFile"

    },
    "OptionsStr2str\0OuvreDefault1\0\0SaveBase\0"
    "LoadBase\0AppelleClavier\0MyLineEdit*\0"
    "line\0on_pushButtonManual_clicked\0"
    "on_radioButtonPositionAuto_clicked\0"
    "on_radioButtonPositionManual_clicked\0"
    "on_UpdateOptionspushButton_clicked\0"
    "Charge\0baseFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionsStr2str[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    1,   62,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void OptionsStr2str::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionsStr2str *_t = static_cast<OptionsStr2str *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OuvreDefault1(); break;
        case 1: _t->SaveBase(); break;
        case 2: _t->LoadBase(); break;
        case 3: _t->AppelleClavier((*reinterpret_cast< MyLineEdit*(*)>(_a[1]))); break;
        case 4: _t->on_pushButtonManual_clicked(); break;
        case 5: _t->on_radioButtonPositionAuto_clicked(); break;
        case 6: _t->on_radioButtonPositionManual_clicked(); break;
        case 7: _t->on_UpdateOptionspushButton_clicked(); break;
        case 8: _t->Charge((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyLineEdit* >(); break;
            }
            break;
        }
    }
}

const QMetaObject OptionsStr2str::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OptionsStr2str.data,
      qt_meta_data_OptionsStr2str,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OptionsStr2str::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionsStr2str::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsStr2str.stringdata0))
        return static_cast<void*>(const_cast< OptionsStr2str*>(this));
    return QDialog::qt_metacast(_clname);
}

int OptionsStr2str::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
