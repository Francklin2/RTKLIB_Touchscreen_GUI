/****************************************************************************
** Meta object code from reading C++ file 'options2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "options2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'options2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Options2_t {
    QByteArrayData data[9];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Options2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Options2_t qt_meta_stringdata_Options2 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Options2"
QT_MOC_LITERAL(1, 9, 12), // "Options2emit"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "emitSat"
QT_MOC_LITERAL(4, 31, 8), // "emitSat1"
QT_MOC_LITERAL(5, 40, 8), // "emitSat2"
QT_MOC_LITERAL(6, 49, 8), // "emitSat4"
QT_MOC_LITERAL(7, 58, 8), // "emitSat5"
QT_MOC_LITERAL(8, 67, 8) // "emitSat6"

    },
    "Options2\0Options2emit\0\0emitSat\0emitSat1\0"
    "emitSat2\0emitSat4\0emitSat5\0emitSat6"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Options2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   52,    2, 0x0a /* Public */,
       4,    0,   53,    2, 0x0a /* Public */,
       5,    0,   54,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Options2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Options2 *_t = static_cast<Options2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Options2emit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->emitSat(); break;
        case 2: _t->emitSat1(); break;
        case 3: _t->emitSat2(); break;
        case 4: _t->emitSat4(); break;
        case 5: _t->emitSat5(); break;
        case 6: _t->emitSat6(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Options2::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Options2::Options2emit)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Options2::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Options2.data,
      qt_meta_data_Options2,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Options2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Options2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Options2.stringdata0))
        return static_cast<void*>(const_cast< Options2*>(this));
    return QDialog::qt_metacast(_clname);
}

int Options2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Options2::Options2emit(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
