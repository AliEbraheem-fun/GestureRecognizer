/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[55];
    char stringdata0[1104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 3), // "log"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 3), // "str"
QT_MOC_LITERAL(4, 20, 17), // "gestureRecognized"
QT_MOC_LITERAL(5, 38, 4), // "gest"
QT_MOC_LITERAL(6, 43, 14), // "progressStatus"
QT_MOC_LITERAL(7, 58, 13), // "bytesReceived"
QT_MOC_LITERAL(8, 72, 10), // "bytesTotal"
QT_MOC_LITERAL(9, 83, 5), // "speed"
QT_MOC_LITERAL(10, 89, 4), // "unit"
QT_MOC_LITERAL(11, 94, 20), // "updateRecognizerList"
QT_MOC_LITERAL(12, 115, 12), // "frameGrabbed"
QT_MOC_LITERAL(13, 128, 3), // "Mat"
QT_MOC_LITERAL(14, 132, 5), // "frame"
QT_MOC_LITERAL(15, 138, 29), // "fillCaptureDevicesInformation"
QT_MOC_LITERAL(16, 168, 11), // "recordFrame"
QT_MOC_LITERAL(17, 180, 24), // "recognitionEngineStarter"
QT_MOC_LITERAL(18, 205, 34), // "on_pbStartVideoAcquisition_cl..."
QT_MOC_LITERAL(19, 240, 33), // "on_pbStopVideoAcquisition_cli..."
QT_MOC_LITERAL(20, 274, 34), // "on_pbRefreshCaptureDevices_cl..."
QT_MOC_LITERAL(21, 309, 19), // "on_pbRecord_clicked"
QT_MOC_LITERAL(22, 329, 26), // "on_pbStopRecording_clicked"
QT_MOC_LITERAL(23, 356, 26), // "on_pbRecordingPath_clicked"
QT_MOC_LITERAL(24, 383, 25), // "on_pbSnapshotPath_clicked"
QT_MOC_LITERAL(25, 409, 21), // "on_pbSnapshot_clicked"
QT_MOC_LITERAL(26, 431, 29), // "on_pbTestTextToSpeech_clicked"
QT_MOC_LITERAL(27, 461, 15), // "on_pbUp_clicked"
QT_MOC_LITERAL(28, 477, 17), // "on_pbDown_clicked"
QT_MOC_LITERAL(29, 495, 18), // "on_pbRight_clicked"
QT_MOC_LITERAL(30, 514, 17), // "on_pbLeft_clicked"
QT_MOC_LITERAL(31, 532, 35), // "on_pbStartRecognitionEngine_c..."
QT_MOC_LITERAL(32, 568, 34), // "on_pbStopRecognitionEngine_cl..."
QT_MOC_LITERAL(33, 603, 16), // "updateThresholds"
QT_MOC_LITERAL(34, 620, 23), // "on_hsLtRed_valueChanged"
QT_MOC_LITERAL(35, 644, 5), // "value"
QT_MOC_LITERAL(36, 650, 25), // "on_hsLtGreen_valueChanged"
QT_MOC_LITERAL(37, 676, 24), // "on_hsLtBlue_valueChanged"
QT_MOC_LITERAL(38, 701, 23), // "on_hsGtRed_valueChanged"
QT_MOC_LITERAL(39, 725, 25), // "on_hsGtGreen_valueChanged"
QT_MOC_LITERAL(40, 751, 24), // "on_hsGtBlue_valueChanged"
QT_MOC_LITERAL(41, 776, 20), // "on_hsBS_valueChanged"
QT_MOC_LITERAL(42, 797, 45), // "on_chkBackgroundSubstractionA..."
QT_MOC_LITERAL(43, 843, 7), // "checked"
QT_MOC_LITERAL(44, 851, 26), // "on_pbSetBackground_clicked"
QT_MOC_LITERAL(45, 878, 24), // "on_pbStartUpdate_clicked"
QT_MOC_LITERAL(46, 903, 22), // "on_pbEditColor_clicked"
QT_MOC_LITERAL(47, 926, 21), // "on_pbEditFont_clicked"
QT_MOC_LITERAL(48, 948, 21), // "on_pbSaveText_clicked"
QT_MOC_LITERAL(49, 970, 21), // "on_pbLoadText_clicked"
QT_MOC_LITERAL(50, 992, 16), // "onGrabberStopped"
QT_MOC_LITERAL(51, 1009, 29), // "on_pbDelLastCharacter_clicked"
QT_MOC_LITERAL(52, 1039, 18), // "on_pbReset_clicked"
QT_MOC_LITERAL(53, 1058, 21), // "on_pbSpeakAll_clicked"
QT_MOC_LITERAL(54, 1080, 23) // "on_actionExit_triggered"

    },
    "MainWindow\0log\0\0str\0gestureRecognized\0"
    "gest\0progressStatus\0bytesReceived\0"
    "bytesTotal\0speed\0unit\0updateRecognizerList\0"
    "frameGrabbed\0Mat\0frame\0"
    "fillCaptureDevicesInformation\0recordFrame\0"
    "recognitionEngineStarter\0"
    "on_pbStartVideoAcquisition_clicked\0"
    "on_pbStopVideoAcquisition_clicked\0"
    "on_pbRefreshCaptureDevices_clicked\0"
    "on_pbRecord_clicked\0on_pbStopRecording_clicked\0"
    "on_pbRecordingPath_clicked\0"
    "on_pbSnapshotPath_clicked\0"
    "on_pbSnapshot_clicked\0"
    "on_pbTestTextToSpeech_clicked\0"
    "on_pbUp_clicked\0on_pbDown_clicked\0"
    "on_pbRight_clicked\0on_pbLeft_clicked\0"
    "on_pbStartRecognitionEngine_clicked\0"
    "on_pbStopRecognitionEngine_clicked\0"
    "updateThresholds\0on_hsLtRed_valueChanged\0"
    "value\0on_hsLtGreen_valueChanged\0"
    "on_hsLtBlue_valueChanged\0"
    "on_hsGtRed_valueChanged\0"
    "on_hsGtGreen_valueChanged\0"
    "on_hsGtBlue_valueChanged\0on_hsBS_valueChanged\0"
    "on_chkBackgroundSubstractionActivated_toggled\0"
    "checked\0on_pbSetBackground_clicked\0"
    "on_pbStartUpdate_clicked\0"
    "on_pbEditColor_clicked\0on_pbEditFont_clicked\0"
    "on_pbSaveText_clicked\0on_pbLoadText_clicked\0"
    "onGrabberStopped\0on_pbDelLastCharacter_clicked\0"
    "on_pbReset_clicked\0on_pbSpeakAll_clicked\0"
    "on_actionExit_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  229,    2, 0x0a /* Public */,
       4,    1,  232,    2, 0x0a /* Public */,
       6,    4,  235,    2, 0x0a /* Public */,
      11,    0,  244,    2, 0x08 /* Private */,
      12,    1,  245,    2, 0x08 /* Private */,
      15,    0,  248,    2, 0x08 /* Private */,
      16,    1,  249,    2, 0x08 /* Private */,
      17,    0,  252,    2, 0x08 /* Private */,
      18,    0,  253,    2, 0x08 /* Private */,
      19,    0,  254,    2, 0x08 /* Private */,
      20,    0,  255,    2, 0x08 /* Private */,
      21,    0,  256,    2, 0x08 /* Private */,
      22,    0,  257,    2, 0x08 /* Private */,
      23,    0,  258,    2, 0x08 /* Private */,
      24,    0,  259,    2, 0x08 /* Private */,
      25,    0,  260,    2, 0x08 /* Private */,
      26,    0,  261,    2, 0x08 /* Private */,
      27,    0,  262,    2, 0x08 /* Private */,
      28,    0,  263,    2, 0x08 /* Private */,
      29,    0,  264,    2, 0x08 /* Private */,
      30,    0,  265,    2, 0x08 /* Private */,
      31,    0,  266,    2, 0x08 /* Private */,
      32,    0,  267,    2, 0x08 /* Private */,
      33,    0,  268,    2, 0x08 /* Private */,
      34,    1,  269,    2, 0x08 /* Private */,
      36,    1,  272,    2, 0x08 /* Private */,
      37,    1,  275,    2, 0x08 /* Private */,
      38,    1,  278,    2, 0x08 /* Private */,
      39,    1,  281,    2, 0x08 /* Private */,
      40,    1,  284,    2, 0x08 /* Private */,
      41,    1,  287,    2, 0x08 /* Private */,
      42,    1,  290,    2, 0x08 /* Private */,
      44,    0,  293,    2, 0x08 /* Private */,
      45,    0,  294,    2, 0x08 /* Private */,
      46,    0,  295,    2, 0x08 /* Private */,
      47,    0,  296,    2, 0x08 /* Private */,
      48,    0,  297,    2, 0x08 /* Private */,
      49,    0,  298,    2, 0x08 /* Private */,
      50,    0,  299,    2, 0x08 /* Private */,
      51,    0,  300,    2, 0x08 /* Private */,
      52,    0,  301,    2, 0x08 /* Private */,
      53,    0,  302,    2, 0x08 /* Private */,
      54,    0,  303,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, QMetaType::Double, QMetaType::QString,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Bool,   43,
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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->gestureRecognized((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->progressStatus((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 3: _t->updateRecognizerList(); break;
        case 4: _t->frameGrabbed((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 5: _t->fillCaptureDevicesInformation(); break;
        case 6: _t->recordFrame((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 7: _t->recognitionEngineStarter(); break;
        case 8: _t->on_pbStartVideoAcquisition_clicked(); break;
        case 9: _t->on_pbStopVideoAcquisition_clicked(); break;
        case 10: _t->on_pbRefreshCaptureDevices_clicked(); break;
        case 11: _t->on_pbRecord_clicked(); break;
        case 12: _t->on_pbStopRecording_clicked(); break;
        case 13: _t->on_pbRecordingPath_clicked(); break;
        case 14: _t->on_pbSnapshotPath_clicked(); break;
        case 15: _t->on_pbSnapshot_clicked(); break;
        case 16: _t->on_pbTestTextToSpeech_clicked(); break;
        case 17: _t->on_pbUp_clicked(); break;
        case 18: _t->on_pbDown_clicked(); break;
        case 19: _t->on_pbRight_clicked(); break;
        case 20: _t->on_pbLeft_clicked(); break;
        case 21: _t->on_pbStartRecognitionEngine_clicked(); break;
        case 22: _t->on_pbStopRecognitionEngine_clicked(); break;
        case 23: _t->updateThresholds(); break;
        case 24: _t->on_hsLtRed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_hsLtGreen_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_hsLtBlue_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_hsGtRed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_hsGtGreen_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_hsGtBlue_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->on_hsBS_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->on_chkBackgroundSubstractionActivated_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_pbSetBackground_clicked(); break;
        case 33: _t->on_pbStartUpdate_clicked(); break;
        case 34: _t->on_pbEditColor_clicked(); break;
        case 35: _t->on_pbEditFont_clicked(); break;
        case 36: _t->on_pbSaveText_clicked(); break;
        case 37: _t->on_pbLoadText_clicked(); break;
        case 38: _t->onGrabberStopped(); break;
        case 39: _t->on_pbDelLastCharacter_clicked(); break;
        case 40: _t->on_pbReset_clicked(); break;
        case 41: _t->on_pbSpeakAll_clicked(); break;
        case 42: _t->on_actionExit_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 43;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
