/****************************************************************************
** Meta object code from reading C++ file 'options1.h'
**
** Created: Mon May 16 01:23:48 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "options1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'options1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Options1[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,   23,   23,   23, 0x0a,
      24,   23,   23,   23, 0x0a,
      36,   23,   23,   23, 0x0a,
      48,   23,   23,   23, 0x0a,
      59,   23,   23,   23, 0x0a,
      76,   23,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Options1[] = {
    "Options1\0ouvreSingle()\0\0ouvreSBAS()\0"
    "ouvreDGPS()\0ouvrePPP()\0ouvreRTKstatic()\0"
    "ouvreRTKkinematic()\0"
};

void Options1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Options1 *_t = static_cast<Options1 *>(_o);
        switch (_id) {
        case 0: _t->ouvreSingle(); break;
        case 1: _t->ouvreSBAS(); break;
        case 2: _t->ouvreDGPS(); break;
        case 3: _t->ouvrePPP(); break;
        case 4: _t->ouvreRTKstatic(); break;
        case 5: _t->ouvreRTKkinematic(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Options1::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Options1::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Options1,
      qt_meta_data_Options1, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Options1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Options1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Options1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Options1))
        return static_cast<void*>(const_cast< Options1*>(this));
    return QDialog::qt_metacast(_clname);
}

int Options1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
