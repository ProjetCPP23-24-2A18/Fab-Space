/****************************************************************************
** Meta object code from reading C++ file 'arduinotemp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../arduinotemp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arduinotemp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_arduinotemp_t {
    QByteArrayData data[6];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_arduinotemp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_arduinotemp_t qt_meta_stringdata_arduinotemp = {
    {
QT_MOC_LITERAL(0, 0, 11), // "arduinotemp"
QT_MOC_LITERAL(1, 12, 12), // "update_label"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 37), // "control_ventilation_based_on_..."
QT_MOC_LITERAL(4, 64, 17), // "on_onlm35_clicked"
QT_MOC_LITERAL(5, 82, 18) // "on_offlm35_clicked"

    },
    "arduinotemp\0update_label\0\0"
    "control_ventilation_based_on_database\0"
    "on_onlm35_clicked\0on_offlm35_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_arduinotemp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void arduinotemp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        arduinotemp *_t = static_cast<arduinotemp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_label(); break;
        case 1: _t->control_ventilation_based_on_database(); break;
        case 2: _t->on_onlm35_clicked(); break;
        case 3: _t->on_offlm35_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject arduinotemp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_arduinotemp.data,
      qt_meta_data_arduinotemp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *arduinotemp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *arduinotemp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_arduinotemp.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int arduinotemp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
