/****************************************************************************
** Meta object code from reading C++ file 'IVFDHeartBeat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IVFDHeartBeat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVFDHeartBeat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IVFDHeartBeat_t {
    QByteArrayData data[9];
    char stringdata[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVFDHeartBeat_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVFDHeartBeat_t qt_meta_stringdata_IVFDHeartBeat = {
    {
QT_MOC_LITERAL(0, 0, 13), // "IVFDHeartBeat"
QT_MOC_LITERAL(1, 14, 11), // "SIG_TellTop"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "sysstat"
QT_MOC_LITERAL(4, 35, 18), // "SIG_StartHeartBeat"
QT_MOC_LITERAL(5, 54, 16), // "SIG_StopHeatBeat"
QT_MOC_LITERAL(6, 71, 19), // "SLOT_StartHeartBeat"
QT_MOC_LITERAL(7, 91, 18), // "SLOT_StopHeartBeat"
QT_MOC_LITERAL(8, 110, 17) // "SLOT_GetSysStatus"

    },
    "IVFDHeartBeat\0SIG_TellTop\0\0sysstat\0"
    "SIG_StartHeartBeat\0SIG_StopHeatBeat\0"
    "SLOT_StartHeartBeat\0SLOT_StopHeartBeat\0"
    "SLOT_GetSysStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVFDHeartBeat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IVFDHeartBeat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IVFDHeartBeat *_t = static_cast<IVFDHeartBeat *>(_o);
        switch (_id) {
        case 0: _t->SIG_TellTop((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->SIG_StartHeartBeat(); break;
        case 2: _t->SIG_StopHeatBeat(); break;
        case 3: _t->SLOT_StartHeartBeat(); break;
        case 4: _t->SLOT_StopHeartBeat(); break;
        case 5: _t->SLOT_GetSysStatus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IVFDHeartBeat::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDHeartBeat::SIG_TellTop)) {
                *result = 0;
            }
        }
        {
            typedef void (IVFDHeartBeat::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDHeartBeat::SIG_StartHeartBeat)) {
                *result = 1;
            }
        }
        {
            typedef void (IVFDHeartBeat::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDHeartBeat::SIG_StopHeatBeat)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject IVFDHeartBeat::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IVFDHeartBeat.data,
      qt_meta_data_IVFDHeartBeat,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IVFDHeartBeat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVFDHeartBeat::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IVFDHeartBeat.stringdata))
        return static_cast<void*>(const_cast< IVFDHeartBeat*>(this));
    return QObject::qt_metacast(_clname);
}

int IVFDHeartBeat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void IVFDHeartBeat::SIG_TellTop(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IVFDHeartBeat::SIG_StartHeartBeat()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void IVFDHeartBeat::SIG_StopHeatBeat()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
