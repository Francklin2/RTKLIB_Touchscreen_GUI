/****************************************************************************
** Meta object code from reading C++ file 'MainthreadStr2str.h'
**
** Created: Sun May 22 00:33:05 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainthreadStr2str.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainthreadStr2str.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainthreadStr2str[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   51,   51,   51, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   51,   51,   51, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainthreadStr2str[] = {
    "MainthreadStr2str\0etatFermetureThreadStr2str(bool)\0"
    "\0close(int)\0"
};

void MainthreadStr2str::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainthreadStr2str *_t = static_cast<MainthreadStr2str *>(_o);
        switch (_id) {
        case 0: _t->etatFermetureThreadStr2str((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->close((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainthreadStr2str::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainthreadStr2str::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MainthreadStr2str,
      qt_meta_data_MainthreadStr2str, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainthreadStr2str::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainthreadStr2str::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainthreadStr2str::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainthreadStr2str))
        return static_cast<void*>(const_cast< MainthreadStr2str*>(this));
    return QThread::qt_metacast(_clname);
}

int MainthreadStr2str::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MainthreadStr2str::etatFermetureThreadStr2str(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
