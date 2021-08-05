/****************************************************************************
** Meta object code from reading C++ file 'grtexttospeach.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../grtexttospeach.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grtexttospeach.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GRTextToSpeech_t {
    QByteArrayData data[17];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GRTextToSpeech_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GRTextToSpeech_t qt_meta_stringdata_GRTextToSpeech = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GRTextToSpeech"
QT_MOC_LITERAL(1, 15, 5), // "speak"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "saying"
QT_MOC_LITERAL(4, 29, 7), // "setRate"
QT_MOC_LITERAL(5, 37, 4), // "rate"
QT_MOC_LITERAL(6, 42, 8), // "setPitch"
QT_MOC_LITERAL(7, 51, 5), // "pitch"
QT_MOC_LITERAL(8, 57, 9), // "setVolume"
QT_MOC_LITERAL(9, 67, 6), // "volume"
QT_MOC_LITERAL(10, 74, 14), // "engineSelected"
QT_MOC_LITERAL(11, 89, 5), // "index"
QT_MOC_LITERAL(12, 95, 16), // "languageSelected"
QT_MOC_LITERAL(13, 112, 8), // "language"
QT_MOC_LITERAL(14, 121, 13), // "voiceSelected"
QT_MOC_LITERAL(15, 135, 13), // "localeChanged"
QT_MOC_LITERAL(16, 149, 6) // "locale"

    },
    "GRTextToSpeech\0speak\0\0saying\0setRate\0"
    "rate\0setPitch\0pitch\0setVolume\0volume\0"
    "engineSelected\0index\0languageSelected\0"
    "language\0voiceSelected\0localeChanged\0"
    "locale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GRTextToSpeech[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    1,   57,    2, 0x08 /* Private */,
       6,    1,   60,    2, 0x08 /* Private */,
       8,    1,   63,    2, 0x08 /* Private */,
      10,    1,   66,    2, 0x08 /* Private */,
      12,    1,   69,    2, 0x08 /* Private */,
      14,    1,   72,    2, 0x08 /* Private */,
      15,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QLocale,   16,

       0        // eod
};

void GRTextToSpeech::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GRTextToSpeech *_t = static_cast<GRTextToSpeech *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->speak((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setRate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setPitch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->engineSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->languageSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->voiceSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->localeChanged((*reinterpret_cast< const QLocale(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GRTextToSpeech::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GRTextToSpeech.data,
      qt_meta_data_GRTextToSpeech,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GRTextToSpeech::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GRTextToSpeech::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GRTextToSpeech.stringdata0))
        return static_cast<void*>(const_cast< GRTextToSpeech*>(this));
    return QObject::qt_metacast(_clname);
}

int GRTextToSpeech::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
