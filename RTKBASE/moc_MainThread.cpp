/****************************************************************************
** Meta object code from reading C++ file 'MainThread.h'
**
** Created: Mon May 16 01:24:19 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   42,   42,   42, 0x05,
      43,   82,   42,   42, 0x05,
      84,  101,   42,   42, 0x05,
     103,   82,   42,   42, 0x05,
     138,   42,   42,   42, 0x05,
     148,   42,   42,   42, 0x05,
     166,   42,   42,   42, 0x05,

 // slots: signature, parameters, type, tag, flags
     188,  101,   42,   42, 0x0a,
     216,   42,   42,   42, 0x0a,
     232,   42,   42,   42, 0x0a,
     245,   42,   42,   42, 0x0a,
     260,   42,   42,   42, 0x0a,
     273,   42,   42,   42, 0x0a,
     288,   42,   42,   42, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainThread[] = {
    "MainThread\0emitdonneesStatus(QStringList)\0"
    "\0emitdonneesSatellites(QStringList,int)\0"
    ",\0emitinterne(int)\0i\0"
    "emitdonneesStream(QStringList,int)\0"
    "save(int)\0savePointNbr(int)\0"
    "etatFermetureVT(bool)\0afficheRtkrcvsatellite(int)\0"
    "etatsatellite()\0etatstatut()\0"
    "etatNaviData()\0etatStream()\0saveposition()\0"
    "sauvegardedansfichier()\0"
};

void MainThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainThread *_t = static_cast<MainThread *>(_o);
        switch (_id) {
        case 0: _t->emitdonneesStatus((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->emitdonneesSatellites((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->emitinterne((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->emitdonneesStream((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->save((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->savePointNbr((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->etatFermetureVT((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->afficheRtkrcvsatellite((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->etatsatellite(); break;
        case 9: _t->etatstatut(); break;
        case 10: _t->etatNaviData(); break;
        case 11: _t->etatStream(); break;
        case 12: _t->saveposition(); break;
        case 13: _t->sauvegardedansfichier(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MainThread,
      qt_meta_data_MainThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainThread))
        return static_cast<void*>(const_cast< MainThread*>(this));
    return QThread::qt_metacast(_clname);
}

int MainThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainThread::emitdonneesStatus(QStringList _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainThread::emitdonneesSatellites(QStringList _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainThread::emitinterne(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainThread::emitdonneesStream(QStringList _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainThread::save(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainThread::savePointNbr(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainThread::etatFermetureVT(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
