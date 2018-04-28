/****************************************************************************
** Meta object code from reading C++ file 'choixstr2str.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "choixstr2str.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'choixstr2str.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChoixStr2Str_t {
    QByteArrayData data[19];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChoixStr2Str_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChoixStr2Str_t qt_meta_stringdata_ChoixStr2Str = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ChoixStr2Str"
QT_MOC_LITERAL(1, 13, 6), // "Charge"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "file"
QT_MOC_LITERAL(4, 26, 11), // "SelectBase1"
QT_MOC_LITERAL(5, 38, 11), // "SelectBase2"
QT_MOC_LITERAL(6, 50, 11), // "SelectBase3"
QT_MOC_LITERAL(7, 62, 11), // "SelectBase4"
QT_MOC_LITERAL(8, 74, 11), // "SelectBase5"
QT_MOC_LITERAL(9, 86, 11), // "SelectBase6"
QT_MOC_LITERAL(10, 98, 11), // "SelectBase7"
QT_MOC_LITERAL(11, 110, 11), // "SelectBase8"
QT_MOC_LITERAL(12, 122, 11), // "SelectBase9"
QT_MOC_LITERAL(13, 134, 12), // "SelectBase10"
QT_MOC_LITERAL(14, 147, 12), // "SelectBase11"
QT_MOC_LITERAL(15, 160, 12), // "SelectBase12"
QT_MOC_LITERAL(16, 173, 6), // "Retour"
QT_MOC_LITERAL(17, 180, 8), // "SauveNom"
QT_MOC_LITERAL(18, 189, 7) // "newName"

    },
    "ChoixStr2Str\0Charge\0\0file\0SelectBase1\0"
    "SelectBase2\0SelectBase3\0SelectBase4\0"
    "SelectBase5\0SelectBase6\0SelectBase7\0"
    "SelectBase8\0SelectBase9\0SelectBase10\0"
    "SelectBase11\0SelectBase12\0Retour\0"
    "SauveNom\0newName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChoixStr2Str[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   92,    2, 0x0a /* Public */,
       5,    0,   93,    2, 0x0a /* Public */,
       6,    0,   94,    2, 0x0a /* Public */,
       7,    0,   95,    2, 0x0a /* Public */,
       8,    0,   96,    2, 0x0a /* Public */,
       9,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void ChoixStr2Str::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChoixStr2Str *_t = static_cast<ChoixStr2Str *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Charge((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SelectBase1(); break;
        case 2: _t->SelectBase2(); break;
        case 3: _t->SelectBase3(); break;
        case 4: _t->SelectBase4(); break;
        case 5: _t->SelectBase5(); break;
        case 6: _t->SelectBase6(); break;
        case 7: _t->SelectBase7(); break;
        case 8: _t->SelectBase8(); break;
        case 9: _t->SelectBase9(); break;
        case 10: _t->SelectBase10(); break;
        case 11: _t->SelectBase11(); break;
        case 12: _t->SelectBase12(); break;
        case 13: _t->Retour(); break;
        case 14: _t->SauveNom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChoixStr2Str::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChoixStr2Str::Charge)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ChoixStr2Str::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChoixStr2Str.data,
      qt_meta_data_ChoixStr2Str,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ChoixStr2Str::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChoixStr2Str::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChoixStr2Str.stringdata0))
        return static_cast<void*>(const_cast< ChoixStr2Str*>(this));
    return QDialog::qt_metacast(_clname);
}

int ChoixStr2Str::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ChoixStr2Str::Charge(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
