/****************************************************************************
** Meta object code from reading C++ file 'OpenFace.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OpenFace.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenFace.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OpenFace_t {
    QByteArrayData data[7];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenFace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenFace_t qt_meta_stringdata_OpenFace = {
    {
QT_MOC_LITERAL(0, 0, 8), // "OpenFace"
QT_MOC_LITERAL(1, 9, 10), // "send_frame"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "cv::Mat&"
QT_MOC_LITERAL(4, 30, 5), // "frame"
QT_MOC_LITERAL(5, 36, 11), // "change_mask"
QT_MOC_LITERAL(6, 48, 7) // "mask_id"

    },
    "OpenFace\0send_frame\0\0cv::Mat&\0frame\0"
    "change_mask\0mask_id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenFace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void OpenFace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OpenFace *_t = static_cast<OpenFace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_frame((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->change_mask((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OpenFace::*_t)(cv::Mat & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OpenFace::send_frame)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject OpenFace::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OpenFace.data,
      qt_meta_data_OpenFace,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OpenFace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenFace::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OpenFace.stringdata0))
        return static_cast<void*>(const_cast< OpenFace*>(this));
    return QObject::qt_metacast(_clname);
}

int OpenFace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void OpenFace::send_frame(cv::Mat & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
