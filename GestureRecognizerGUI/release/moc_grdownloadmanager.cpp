/****************************************************************************
** Meta object code from reading C++ file 'grdownloadmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../grdownloadmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grdownloadmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GRDownloadManager_t {
    QByteArrayData data[15];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GRDownloadManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GRDownloadManager_t qt_meta_stringdata_GRDownloadManager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "GRDownloadManager"
QT_MOC_LITERAL(1, 18, 12), // "downloadDone"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "log"
QT_MOC_LITERAL(4, 36, 3), // "msg"
QT_MOC_LITERAL(5, 40, 14), // "progressStatus"
QT_MOC_LITERAL(6, 55, 13), // "bytesReceived"
QT_MOC_LITERAL(7, 69, 10), // "bytesTotal"
QT_MOC_LITERAL(8, 80, 5), // "speed"
QT_MOC_LITERAL(9, 86, 4), // "unit"
QT_MOC_LITERAL(10, 91, 17), // "progressCompleted"
QT_MOC_LITERAL(11, 109, 17), // "startNextDownload"
QT_MOC_LITERAL(12, 127, 16), // "downloadProgress"
QT_MOC_LITERAL(13, 144, 16), // "downloadFinished"
QT_MOC_LITERAL(14, 161, 17) // "downloadReadyRead"

    },
    "GRDownloadManager\0downloadDone\0\0log\0"
    "msg\0progressStatus\0bytesReceived\0"
    "bytesTotal\0speed\0unit\0progressCompleted\0"
    "startNextDownload\0downloadProgress\0"
    "downloadFinished\0downloadReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GRDownloadManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    4,   58,    2, 0x06 /* Public */,
      10,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   68,    2, 0x08 /* Private */,
      12,    2,   69,    2, 0x08 /* Private */,
      13,    0,   74,    2, 0x08 /* Private */,
      14,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::Double, QMetaType::QString,    6,    7,    8,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GRDownloadManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GRDownloadManager *_t = static_cast<GRDownloadManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadDone(); break;
        case 1: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->progressStatus((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 3: _t->progressCompleted(); break;
        case 4: _t->startNextDownload(); break;
        case 5: _t->downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 6: _t->downloadFinished(); break;
        case 7: _t->downloadReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GRDownloadManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GRDownloadManager::downloadDone)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GRDownloadManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GRDownloadManager::log)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GRDownloadManager::*_t)(qint64 , qint64 , double , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GRDownloadManager::progressStatus)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GRDownloadManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GRDownloadManager::progressCompleted)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject GRDownloadManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GRDownloadManager.data,
      qt_meta_data_GRDownloadManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GRDownloadManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GRDownloadManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GRDownloadManager.stringdata0))
        return static_cast<void*>(const_cast< GRDownloadManager*>(this));
    return QObject::qt_metacast(_clname);
}

int GRDownloadManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void GRDownloadManager::downloadDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GRDownloadManager::log(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GRDownloadManager::progressStatus(qint64 _t1, qint64 _t2, double _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GRDownloadManager::progressCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
