/****************************************************************************
** Meta object code from reading C++ file 'affichestr2str.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "affichestr2str.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'affichestr2str.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AfficheStr2str_t {
    QByteArrayData data[6];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AfficheStr2str_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AfficheStr2str_t qt_meta_stringdata_AfficheStr2str = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AfficheStr2str"
QT_MOC_LITERAL(1, 15, 11), // "closeSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "recupdonneesStr2str"
QT_MOC_LITERAL(4, 48, 12), // "FermeStr2str"
QT_MOC_LITERAL(5, 61, 9) // "finThread"

    },
    "AfficheStr2str\0closeSignal\0\0"
    "recupdonneesStr2str\0FermeStr2str\0"
    "finThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AfficheStr2str[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   37,    2, 0x0a /* Public */,
       4,    0,   40,    2, 0x0a /* Public */,
       5,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void AfficheStr2str::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AfficheStr2str *_t = static_cast<AfficheStr2str *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->recupdonneesStr2str((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->FermeStr2str(); break;
        case 3: _t->finThread((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AfficheStr2str::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AfficheStr2str::closeSignal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AfficheStr2str::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AfficheStr2str.data,
      qt_meta_data_AfficheStr2str,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AfficheStr2str::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AfficheStr2str::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AfficheStr2str.stringdata0))
        return static_cast<void*>(const_cast< AfficheStr2str*>(this));
    return QDialog::qt_metacast(_clname);
}

int AfficheStr2str::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AfficheStr2str::closeSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
