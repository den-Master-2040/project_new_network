/****************************************************************************
** Meta object code from reading C++ file 'form_create_group.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../untitled1/form_create_group.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_create_group.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_form_create_group_t {
    QByteArrayData data[12];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_form_create_group_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_form_create_group_t qt_meta_stringdata_form_create_group = {
    {
QT_MOC_LITERAL(0, 0, 17), // "form_create_group"
QT_MOC_LITERAL(1, 18, 10), // "signalExit"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "SendToServer"
QT_MOC_LITERAL(4, 43, 3), // "str"
QT_MOC_LITERAL(5, 47, 26), // "on_pb_create_group_clicked"
QT_MOC_LITERAL(6, 74, 13), // "slotReadyRead"
QT_MOC_LITERAL(7, 88, 19), // "RequaredRecvMessage"
QT_MOC_LITERAL(8, 108, 7), // "message"
QT_MOC_LITERAL(9, 116, 19), // "slotOkToCreateGroup"
QT_MOC_LITERAL(10, 136, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(11, 159, 23) // "on_pushButton_2_clicked"

    },
    "form_create_group\0signalExit\0\0"
    "SendToServer\0str\0on_pb_create_group_clicked\0"
    "slotReadyRead\0RequaredRecvMessage\0"
    "message\0slotOkToCreateGroup\0"
    "on_radioButton_clicked\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_form_create_group[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   55,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void form_create_group::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<form_create_group *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalExit(); break;
        case 1: _t->SendToServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_pb_create_group_clicked(); break;
        case 3: _t->slotReadyRead(); break;
        case 4: _t->RequaredRecvMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slotOkToCreateGroup(); break;
        case 6: _t->on_radioButton_clicked(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (form_create_group::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&form_create_group::signalExit)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject form_create_group::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_form_create_group.data,
    qt_meta_data_form_create_group,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *form_create_group::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *form_create_group::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_form_create_group.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int form_create_group::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void form_create_group::signalExit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
