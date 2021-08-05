/****************************************************************************
** Meta object code from reading C++ file 'grvideorecorder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../grvideorecorder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grvideorecorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GRVideoRecorder_t {
    QByteArrayData data[7];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GRVideoRecorder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GRVideoRecorder_t qt_meta_stringdata_GRVideoRecorder = {
    {
QT_MOC_LITERAL(0, 0, 15), // "GRVideoRecorder"
QT_MOC_LITERAL(1, 16, 6), // "record"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "Mat"
QT_MOC_LITERAL(4, 28, 5), // "frame"
QT_MOC_LITERAL(5, 34, 13), // "startRecorder"
QT_MOC_LITERAL(6, 48, 7) // "release"

    },
    "GRVideoRecorder\0record\0\0Mat\0frame\0"
    "startRecorder\0release"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GRVideoRecorder[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    0,   32,    2, 0x0a /* Public */,
       6,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void GRVideoRecorder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GRVideoRecorder *_t = static_cast<GRVideoRecorder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->record((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 1: { bool _r = _t->startRecorder();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->release(); break;
        default: ;
        }
    }
}

const QMetaObject GRVideoRecorder::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GRVideoRecorder.data,
      qt_meta_data_GRVideoRecorder,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GRVideoRecorder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GRVideoRecorder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GRVideoRecorder.stringdata0))
        return static_cast<void*>(const_cast< GRVideoRecorder*>(this));
    return QThread::qt_metacast(_clname);
}

int GRVideoRecorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
