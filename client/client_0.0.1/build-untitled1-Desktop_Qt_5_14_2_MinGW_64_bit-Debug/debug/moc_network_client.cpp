/****************************************************************************
** Meta object code from reading C++ file 'network_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../untitled1/network_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_network_client_t {
    QByteArrayData data[8];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_client_t qt_meta_stringdata_network_client = {
    {
QT_MOC_LITERAL(0, 0, 14), // "network_client"
QT_MOC_LITERAL(1, 15, 21), // "signalOkToCreateGroup"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 15), // "signalSizeUsers"
QT_MOC_LITERAL(4, 54, 18), // "signalendDataGroup"
QT_MOC_LITERAL(5, 73, 17), // "signalSecondLogin"
QT_MOC_LITERAL(6, 91, 32), // "signalRecvMessageFromAnotherUser"
QT_MOC_LITERAL(7, 124, 13) // "slotReadyRead"

    },
    "network_client\0signalOkToCreateGroup\0"
    "\0signalSizeUsers\0signalendDataGroup\0"
    "signalSecondLogin\0signalRecvMessageFromAnotherUser\0"
    "slotReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network_client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void network_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<network_client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalOkToCreateGroup(); break;
        case 1: _t->signalSizeUsers(); break;
        case 2: _t->signalendDataGroup(); break;
        case 3: _t->signalSecondLogin(); break;
        case 4: _t->signalRecvMessageFromAnotherUser(); break;
        case 5: _t->slotReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (network_client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&network_client::signalOkToCreateGroup)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (network_client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&network_client::signalSizeUsers)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (network_client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&network_client::signalendDataGroup)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (network_client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&network_client::signalSecondLogin)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (network_client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&network_client::signalRecvMessageFromAnotherUser)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject network_client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_network_client.data,
    qt_meta_data_network_client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *network_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network_client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_network_client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int network_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void network_client::signalOkToCreateGroup()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void network_client::signalSizeUsers()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void network_client::signalendDataGroup()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void network_client::signalSecondLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void network_client::signalRecvMessageFromAnotherUser()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
