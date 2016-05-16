/****************************************************************************
** Meta object code from reading C++ file 'threadheuresysteme.h'
**
** Created: Mon May 16 01:23:32 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "threadheuresysteme.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadheuresysteme.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreadHeureSysteme[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   39,   39,   39, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ThreadHeureSysteme[] = {
    "ThreadHeureSysteme\0heureretournee(int)\0"
    "\0"
};

void ThreadHeureSysteme::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadHeureSysteme *_t = static_cast<ThreadHeureSysteme *>(_o);
        switch (_id) {
        case 0: _t->heureretournee((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ThreadHeureSysteme::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadHeureSysteme::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadHeureSysteme,
      qt_meta_data_ThreadHeureSysteme, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadHeureSysteme::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadHeureSysteme::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadHeureSysteme::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadHeureSysteme))
        return static_cast<void*>(const_cast< ThreadHeureSysteme*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadHeureSysteme::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ThreadHeureSysteme::heureretournee(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
