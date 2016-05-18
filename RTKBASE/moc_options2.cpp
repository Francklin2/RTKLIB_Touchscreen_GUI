/****************************************************************************
** Meta object code from reading C++ file 'options2.h'
**
** Created: Mon May 16 01:24:10 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "options2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'options2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Options2[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,   27,   27,   27, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x0a,
      38,   27,   27,   27, 0x0a,
      49,   27,   27,   27, 0x0a,
      60,   27,   27,   27, 0x0a,
      71,   27,   27,   27, 0x0a,
      82,   27,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Options2[] = {
    "Options2\0Options2emit(int)\0\0emitSat()\0"
    "emitSat1()\0emitSat2()\0emitSat4()\0"
    "emitSat5()\0emitSat6()\0"
};

void Options2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Options2 *_t = static_cast<Options2 *>(_o);
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
    }
}

const QMetaObjectExtraData Options2::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Options2::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Options2,
      qt_meta_data_Options2, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Options2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Options2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Options2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Options2))
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
    }
    return _id;
}

// SIGNAL 0
void Options2::Options2emit(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
