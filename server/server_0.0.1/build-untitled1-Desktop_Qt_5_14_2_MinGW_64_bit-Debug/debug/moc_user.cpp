/****************************************************************************
** Meta object code from reading C++ file 'user.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../untitled1/user.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_user_t {
    QByteArrayData data[15];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_user_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_user_t qt_meta_stringdata_user = {
    {
QT_MOC_LITERAL(0, 0, 4), // "user"
QT_MOC_LITERAL(1, 5, 16), // "signalDisconnect"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "signalEnable"
QT_MOC_LITERAL(4, 36, 17), // "signalsendMessage"
QT_MOC_LITERAL(5, 54, 17), // "signalCreateGroup"
QT_MOC_LITERAL(6, 72, 18), // "signalGetDataGroup"
QT_MOC_LITERAL(7, 91, 20), // "signalConnectToGroup"
QT_MOC_LITERAL(8, 112, 15), // "signalExitGroup"
QT_MOC_LITERAL(9, 128, 8), // "signalGo"
QT_MOC_LITERAL(10, 137, 15), // "signalFindUsers"
QT_MOC_LITERAL(11, 153, 14), // "connectViewers"
QT_MOC_LITERAL(12, 168, 17), // "disconnectViewers"
QT_MOC_LITERAL(13, 186, 13), // "slotReadyRead"
QT_MOC_LITERAL(14, 200, 12) // "slotReadBuff"

    },
    "user\0signalDisconnect\0\0signalEnable\0"
    "signalsendMessage\0signalCreateGroup\0"
    "signalGetDataGroup\0signalConnectToGroup\0"
    "signalExitGroup\0signalGo\0signalFindUsers\0"
    "connectViewers\0disconnectViewers\0"
    "slotReadyRead\0slotReadBuff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_user[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,
       8,    0,   85,    2, 0x06 /* Public */,
       9,    0,   86,    2, 0x06 /* Public */,
      10,    0,   87,    2, 0x06 /* Public */,
      11,    0,   88,    2, 0x06 /* Public */,
      12,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
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

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void user::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<user *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalDisconnect(); break;
        case 1: _t->signalEnable(); break;
        case 2: _t->signalsendMessage(); break;
        case 3: _t->signalCreateGroup(); break;
        case 4: _t->signalGetDataGroup(); break;
        case 5: _t->signalConnectToGroup(); break;
        case 6: _t->signalExitGroup(); break;
        case 7: _t->signalGo(); break;
        case 8: _t->signalFindUsers(); break;
        case 9: _t->connectViewers(); break;
        case 10: _t->disconnectViewers(); break;
        case 11: _t->slotReadyRead(); break;
        case 12: _t->slotReadBuff(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::signalDisconnect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::signalEnable)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::signalsendMessage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::signalCreateGroup)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::signalGetDataGroup)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::signalConnectToGroup)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::signalExitGroup)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::signalGo)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::signalFindUsers)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::connectViewers)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::disconnectViewers)) {
                *result = 10;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject user::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_user.data,
    qt_meta_data_user,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *user::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *user::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_user.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int user::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void user::signalDisconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void user::signalEnable()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void user::signalsendMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void user::signalCreateGroup()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void user::signalGetDataGroup()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void user::signalConnectToGroup()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void user::signalExitGroup()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void user::signalGo()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void user::signalFindUsers()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void user::connectViewers()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void user::disconnectViewers()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
