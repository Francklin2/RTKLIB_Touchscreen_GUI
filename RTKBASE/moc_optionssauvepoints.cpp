/****************************************************************************
** Meta object code from reading C++ file 'optionssauvepoints.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "optionssauvepoints.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionssauvepoints.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_optionssauvepoints_t {
    QByteArrayData data[6];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_optionssauvepoints_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_optionssauvepoints_t qt_meta_stringdata_optionssauvepoints = {
    {
QT_MOC_LITERAL(0, 0, 18), // "optionssauvepoints"
QT_MOC_LITERAL(1, 19, 11), // "SaveOptions"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "ChoixFilepath"
QT_MOC_LITERAL(4, 46, 6), // "Cancel"
QT_MOC_LITERAL(5, 53, 4) // "Save"

    },
    "optionssauvepoints\0SaveOptions\0\0"
    "ChoixFilepath\0Cancel\0Save"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_optionssauvepoints[] = {

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
       3,    0,   37,    2, 0x0a /* Public */,
       4,    0,   38,    2, 0x0a /* Public */,
       5,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void optionssauvepoints::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        optionssauvepoints *_t = static_cast<optionssauvepoints *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SaveOptions((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->ChoixFilepath(); break;
        case 2: _t->Cancel(); break;
        case 3: _t->Save(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (optionssauvepoints::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&optionssauvepoints::SaveOptions)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject optionssauvepoints::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_optionssauvepoints.data,
      qt_meta_data_optionssauvepoints,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *optionssauvepoints::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *optionssauvepoints::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_optionssauvepoints.stringdata0))
        return static_cast<void*>(const_cast< optionssauvepoints*>(this));
    return QDialog::qt_metacast(_clname);
}

int optionssauvepoints::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void optionssauvepoints::SaveOptions(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
