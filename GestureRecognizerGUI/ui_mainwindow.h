/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <animatedqcheckbox.h>
#include <animatedqcombobox.h>
#include <animatedqframe.h>
#include <animatedqlabel.h>
#include <animatedqlistwidget.h>
#include <animatedqprogressbar.h>
#include <animatedqpushbutton.h>
#include <animatedqtextedit.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tbVideo;
    QGroupBox *groupBox_4;
    AnimatedQComboBox *cmbCaptureDevices;
    AnimatedQPushButton *pbStartVideoAcquisition;
    AnimatedQPushButton *pbStopVideoAcquisition;
    AnimatedQPushButton *pbRefreshCaptureDevices;
    AnimatedQCheckBox *chkMirrored;
    QGroupBox *groupBox_5;
    AnimatedQPushButton *pbRecord;
    AnimatedQPushButton *pbStopRecording;
    AnimatedQPushButton *pbRecordingPath;
    QLabel *lblRecordingPath;
    QGroupBox *groupBox_6;
    AnimatedQPushButton *pbSnapshot;
    AnimatedQPushButton *pbSnapshotPath;
    QLabel *lblSnapshotPath;
    QWidget *tbSpeech;
    QGroupBox *groupBox_14;
    AnimatedQFrame *frmEngine;
    QLabel *label_5;
    QComboBox *engine;
    AnimatedQPushButton *pbTestTextToSpeech;
    AnimatedQFrame *frmRate;
    QSlider *rate;
    QLabel *label;
    AnimatedQFrame *frmLanguage;
    QLabel *label_4;
    QComboBox *language;
    AnimatedQFrame *frmVolume;
    QSlider *volume;
    QLabel *label_2;
    AnimatedQFrame *frmVoiceName;
    QComboBox *voice;
    QLabel *label_6;
    AnimatedQFrame *frmPitch;
    QLabel *label_3;
    QSlider *pitch;
    AnimatedQPushButton *pbSpeakAll;
    QGroupBox *groupBox_15;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    AnimatedQPushButton *pbLoadText;
    AnimatedQPushButton *pbDelLastCharacter;
    AnimatedQPushButton *pbReset;
    AnimatedQPushButton *pbEditColor;
    AnimatedQPushButton *pbEditFont;
    AnimatedQPushButton *pbSaveText;
    QWidget *tab;
    QGroupBox *groupBox_11;
    AnimatedQFrame *frmLTR;
    QSlider *hsLtRed;
    QLabel *lblLtRed;
    QLabel *lblLtRedValue;
    AnimatedQFrame *frmLTG;
    QSlider *hsLtGreen;
    QLabel *lblLtGreen;
    QLabel *lblLtGreenValue;
    AnimatedQFrame *frmLTB;
    QSlider *hsLtBlue;
    QLabel *lblLtRed_3;
    QLabel *lblLtBlueValue;
    QGroupBox *groupBox_12;
    AnimatedQFrame *frmUTR;
    QSlider *hsGtRed;
    QLabel *lblGtRed;
    QLabel *lblGtRedValue;
    AnimatedQFrame *frmUTG;
    QSlider *hsGtGreen;
    QLabel *lblGtGreen;
    QLabel *lblGtGreenValue;
    AnimatedQFrame *frmUTB;
    QSlider *hsGtBlue;
    QLabel *lblBlue;
    QLabel *lblGtBlueValue;
    QGroupBox *groupBox_13;
    AnimatedQPushButton *pbSetBackground;
    AnimatedQCheckBox *chkBackgroundSubstractionActivated;
    AnimatedQFrame *frmBST;
    QSlider *hsBS;
    QLabel *lblBS;
    QLabel *lblBSValue;
    QWidget *tbRecognition;
    QGroupBox *groupBox_7;
    AnimatedQPushButton *pbStopRecognitionEngine;
    AnimatedQPushButton *pbStartRecognitionEngine;
    QGroupBox *groupBox_8;
    AnimatedQPushButton *pbUp;
    AnimatedQPushButton *pbRight;
    AnimatedQPushButton *pbLeft;
    AnimatedQPushButton *pbDown;
    QGroupBox *groupBox_9;
    AnimatedQListWidget *listWidget;
    QWidget *tbUpdate;
    QGroupBox *groupBox_10;
    AnimatedQPushButton *pbStartUpdate;
    AnimatedQProgressBar *progressBar;
    QGroupBox *groupBox_2;
    AnimatedQTextEdit *teLog;
    QGroupBox *groupBox_3;
    AnimatedQTextEdit *teText;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    AnimatedQLabel *lblVideo;
    AnimatedQLabel *lblVideo_2;
    AnimatedQLabel *lblVideo_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1300, 660);
        MainWindow->setMinimumSize(QSize(1300, 660));
        MainWindow->setMaximumSize(QSize(1300, 660));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("*\n"
"{\n"
"background-color:white;\n"
"font-size:10pt;\n"
"/*color:white;*/\n"
"}\n"
"\n"
"QLabel#lblVideo\n"
"{\n"
"	border-style:solid;\n"
"	border-width:4px;\n"
"	border-radius: 10px;\n"
"	border-color:red;\n"
"	background-color: #000000;\n"
"}\n"
"QLabel#lblVideo:hover\n"
"{\n"
"	border-color:green;\n"
"	min-width:520px;\n"
"	max-width:520px;\n"
"	min-height:420px;\n"
"	max-height:420px;\n"
"}\n"
"\n"
"QLabel#lblVideo_2\n"
"{\n"
"	border-style:solid;\n"
"	border-width:4px;\n"
"	border-radius: 10px;\n"
"	border-color:red;\n"
"	background-color: #000000;\n"
"}\n"
"QLabel#lblVideo_2:hover\n"
"{\n"
"	border-color:green\n"
"}\n"
"\n"
"QLabel#lblVideo_3\n"
"{\n"
"	border-style:solid;\n"
"	border-width:4px;\n"
"	border-radius: 10px;\n"
"	border-color:red;\n"
"	background-color: #000000;\n"
"}\n"
"QLabel#lblVideo_3:hover\n"
"{\n"
"	border-color:green\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	color: white;\n"
"	background-color: #27a9e3;\n"
"	border-width: 0px;\n"
"	border-radius: 3px;\n"
"	min-height:25px;\n"
"	min-w"
                        "idth:70px;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover { background-color: #66c011; }\n"
"QPushButton:pressed { background-color: #000000; }\n"
"QPushButton:disabled{background-color: darkgray;}\n"
"\n"
"QTextEdit#teText\n"
"{\n"
"	background-color: #ffffff;\n"
"	border-style:solid;\n"
"	border-radius:10px;\n"
"	border-width: 4px;\n"
"	border-color:red;\n"
"}\n"
"QTextEdit#teText:hover\n"
"{\n"
"	border-color:green\n"
"}\n"
"QTextEdit#teLog\n"
"{\n"
"	background-color: #ffffff;\n"
"	border-style:solid;\n"
"	border-radius:10px;\n"
"	border-width: 4px;\n"
"	border-color:red;\n"
"}\n"
"QTextEdit#teLog:hover\n"
"{\n"
"	border-color:green\n"
"}\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"	border:1px solid #E0E0E0;\n"
"  }\n"
"\n"
"\n"
"  /* Style the tab using the tab sub-control. Note that\n"
"      it reads QTabBar _not_ QTabWidget */\n"
"  QTabBar::tab {\n"
"     border: 1px solid #E0E0E0;\n"
"      min-height: 39ex;\n"
"      min-width:10ex;\n"
"      background: #AAAAAA;\n"
"\n"
"  }\n"
"\n"
"  QTabBar::ta"
                        "b:selected, QTabBar::tab:hover {\n"
"      background: #FFFFFF;\n"
"  }\n"
"QCheckBox#chkMirrored\n"
"{\n"
"	color: white;\n"
"	background-color: #000000;\n"
"	border-width: 0px;\n"
"	border-radius: 3px;\n"
"	padding:10px;\n"
"}\n"
"\n"
"QCheckBox:hover\n"
"{\n"
"	color: black;\n"
"	background-color: #f0f0f0;\n"
"}\n"
"\n"
"QFrame#frmVolume:hover ,\n"
"QFrame#frmRate:hover,\n"
"QFrame#frmPitch:hover,\n"
"QFrame#frmEngine:hover,\n"
"QFrame#frmLanguage:hover,\n"
"QFrame#frmVoiceName:hover,\n"
"QFrame#frmLTR:hover,\n"
"QFrame#frmLTG:hover,\n"
"QFrame#frmLTB:hover,\n"
"QFrame#frmUTR:hover,\n"
"QFrame#frmUTG:hover,\n"
"QFrame#frmUTB:hover,\n"
"QFrame#frmBST:hover\n"
"{\n"
"	border-style:solid;\n"
"	border-color: green;\n"
"	border-width: 2px;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QProgressBar {\n"
"      border: 2px solid grey;\n"
"      border-radius: 5px;\n"
"  }\n"
"\n"
"  QProgressBar::chunk {\n"
"      background-color: #05B8CC;\n"
"      width: 20px;\n"
"  }\n"
"  QProgressBar::chunk:hover {\n"
"      backg"
                        "round-color: #0000ff;\n"
"      width: 20px;\n"
"  }\n"
"QProgressBar {\n"
"      border: 2px solid grey;\n"
"      border-radius: 5px;\n"
"      text-align: center;\n"
"  }\n"
"\n"
"QListView {\n"
"      show-decoration-selected: 1; /* make the selection span the entire width of the view */\n"
"  }\n"
"\n"
"  QListView::item:alternate {\n"
"      background: #EEEEEE;\n"
"  }\n"
"\n"
"  QListView::item:selected {\n"
"      border: 1px solid #6a6ea9;\n"
"  }\n"
"\n"
"  QListView::item:selected:!active {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #ABAFE5, stop: 1 #8588B2);\n"
"  }\n"
"\n"
"  QListView::item:selected:active {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #6a6ea9, stop: 1 #888dd9);\n"
"  }\n"
"\n"
"  QListView::item:hover {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #FAFBFE, stop: 1 #DCDEF1);\n"
""
                        "  }\n"
" QListView::item {\n"
"	min-height:35;\n"
"  }\n"
""));
        MainWindow->setIconSize(QSize(64, 64));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(900, 9, 391, 601));
        tabWidget->setTabPosition(QTabWidget::East);
        tbVideo = new QWidget();
        tbVideo->setObjectName(QStringLiteral("tbVideo"));
        groupBox_4 = new QGroupBox(tbVideo);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 20, 331, 181));
        groupBox_4->setMouseTracking(true);
        cmbCaptureDevices = new AnimatedQComboBox(groupBox_4);
        cmbCaptureDevices->setObjectName(QStringLiteral("cmbCaptureDevices"));
        cmbCaptureDevices->setGeometry(QRect(20, 30, 291, 35));
        cmbCaptureDevices->setMinimumSize(QSize(0, 35));
        pbStartVideoAcquisition = new AnimatedQPushButton(groupBox_4);
        pbStartVideoAcquisition->setObjectName(QStringLiteral("pbStartVideoAcquisition"));
        pbStartVideoAcquisition->setGeometry(QRect(20, 80, 81, 35));
        pbStartVideoAcquisition->setMinimumSize(QSize(70, 25));
        pbStopVideoAcquisition = new AnimatedQPushButton(groupBox_4);
        pbStopVideoAcquisition->setObjectName(QStringLiteral("pbStopVideoAcquisition"));
        pbStopVideoAcquisition->setEnabled(false);
        pbStopVideoAcquisition->setGeometry(QRect(125, 80, 80, 35));
        pbStopVideoAcquisition->setMinimumSize(QSize(70, 25));
        pbRefreshCaptureDevices = new AnimatedQPushButton(groupBox_4);
        pbRefreshCaptureDevices->setObjectName(QStringLiteral("pbRefreshCaptureDevices"));
        pbRefreshCaptureDevices->setGeometry(QRect(230, 80, 80, 35));
        pbRefreshCaptureDevices->setMinimumSize(QSize(70, 25));
        chkMirrored = new AnimatedQCheckBox(groupBox_4);
        chkMirrored->setObjectName(QStringLiteral("chkMirrored"));
        chkMirrored->setGeometry(QRect(20, 130, 81, 35));
        chkMirrored->setIconSize(QSize(16, 16));
        chkMirrored->setChecked(true);
        groupBox_5 = new QGroupBox(tbVideo);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 220, 331, 181));
        pbRecord = new AnimatedQPushButton(groupBox_5);
        pbRecord->setObjectName(QStringLiteral("pbRecord"));
        pbRecord->setEnabled(false);
        pbRecord->setGeometry(QRect(11, 31, 80, 35));
        pbRecord->setMinimumSize(QSize(70, 25));
        pbStopRecording = new AnimatedQPushButton(groupBox_5);
        pbStopRecording->setObjectName(QStringLiteral("pbStopRecording"));
        pbStopRecording->setEnabled(false);
        pbStopRecording->setGeometry(QRect(116, 31, 80, 35));
        pbStopRecording->setMinimumSize(QSize(70, 25));
        pbRecordingPath = new AnimatedQPushButton(groupBox_5);
        pbRecordingPath->setObjectName(QStringLiteral("pbRecordingPath"));
        pbRecordingPath->setGeometry(QRect(221, 31, 80, 35));
        pbRecordingPath->setMinimumSize(QSize(70, 25));
        lblRecordingPath = new QLabel(groupBox_5);
        lblRecordingPath->setObjectName(QStringLiteral("lblRecordingPath"));
        lblRecordingPath->setGeometry(QRect(11, 72, 291, 91));
        lblRecordingPath->setWordWrap(true);
        groupBox_6 = new QGroupBox(tbVideo);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 420, 331, 161));
        pbSnapshot = new AnimatedQPushButton(groupBox_6);
        pbSnapshot->setObjectName(QStringLiteral("pbSnapshot"));
        pbSnapshot->setEnabled(false);
        pbSnapshot->setGeometry(QRect(11, 31, 100, 35));
        pbSnapshot->setMinimumSize(QSize(70, 25));
        pbSnapshotPath = new AnimatedQPushButton(groupBox_6);
        pbSnapshotPath->setObjectName(QStringLiteral("pbSnapshotPath"));
        pbSnapshotPath->setGeometry(QRect(200, 30, 100, 35));
        pbSnapshotPath->setMinimumSize(QSize(70, 25));
        lblSnapshotPath = new QLabel(groupBox_6);
        lblSnapshotPath->setObjectName(QStringLiteral("lblSnapshotPath"));
        lblSnapshotPath->setGeometry(QRect(11, 72, 291, 81));
        lblSnapshotPath->setWordWrap(true);
        tabWidget->addTab(tbVideo, QString());
        tbSpeech = new QWidget();
        tbSpeech->setObjectName(QStringLiteral("tbSpeech"));
        groupBox_14 = new QGroupBox(tbSpeech);
        groupBox_14->setObjectName(QStringLiteral("groupBox_14"));
        groupBox_14->setGeometry(QRect(10, 10, 341, 381));
        frmEngine = new AnimatedQFrame(groupBox_14);
        frmEngine->setObjectName(QStringLiteral("frmEngine"));
        frmEngine->setGeometry(QRect(10, 180, 321, 44));
        frmEngine->setFrameShape(QFrame::StyledPanel);
        frmEngine->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frmEngine);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 51, 16));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        engine = new QComboBox(frmEngine);
        engine->setObjectName(QStringLiteral("engine"));
        engine->setGeometry(QRect(95, 10, 210, 25));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(engine->sizePolicy().hasHeightForWidth());
        engine->setSizePolicy(sizePolicy1);
        engine->setMinimumSize(QSize(0, 25));
        engine->setMaximumSize(QSize(16777215, 40));
        pbTestTextToSpeech = new AnimatedQPushButton(groupBox_14);
        pbTestTextToSpeech->setObjectName(QStringLiteral("pbTestTextToSpeech"));
        pbTestTextToSpeech->setGeometry(QRect(10, 330, 141, 30));
        pbTestTextToSpeech->setMinimumSize(QSize(70, 25));
        frmRate = new AnimatedQFrame(groupBox_14);
        frmRate->setObjectName(QStringLiteral("frmRate"));
        frmRate->setGeometry(QRect(10, 80, 321, 44));
        frmRate->setFrameShape(QFrame::StyledPanel);
        frmRate->setFrameShadow(QFrame::Raised);
        rate = new QSlider(frmRate);
        rate->setObjectName(QStringLiteral("rate"));
        rate->setGeometry(QRect(75, 10, 230, 25));
        rate->setMinimumSize(QSize(0, 25));
        rate->setMaximumSize(QSize(16777215, 40));
        rate->setMinimum(-10);
        rate->setMaximum(10);
        rate->setOrientation(Qt::Horizontal);
        label = new QLabel(frmRate);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 31, 16));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frmLanguage = new AnimatedQFrame(groupBox_14);
        frmLanguage->setObjectName(QStringLiteral("frmLanguage"));
        frmLanguage->setGeometry(QRect(10, 230, 321, 44));
        frmLanguage->setFrameShape(QFrame::StyledPanel);
        frmLanguage->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frmLanguage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 60, 16));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        language = new QComboBox(frmLanguage);
        language->setObjectName(QStringLiteral("language"));
        language->setGeometry(QRect(95, 10, 210, 25));
        sizePolicy1.setHeightForWidth(language->sizePolicy().hasHeightForWidth());
        language->setSizePolicy(sizePolicy1);
        language->setMinimumSize(QSize(0, 25));
        language->setMaximumSize(QSize(16777215, 40));
        language->setFocusPolicy(Qt::NoFocus);
        frmVolume = new AnimatedQFrame(groupBox_14);
        frmVolume->setObjectName(QStringLiteral("frmVolume"));
        frmVolume->setGeometry(QRect(10, 30, 321, 44));
        frmVolume->setFrameShape(QFrame::StyledPanel);
        frmVolume->setFrameShadow(QFrame::Raised);
        volume = new QSlider(frmVolume);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setGeometry(QRect(75, 10, 231, 25));
        volume->setMinimumSize(QSize(0, 25));
        volume->setMaximumSize(QSize(16777215, 16777215));
        volume->setMaximum(100);
        volume->setSingleStep(5);
        volume->setPageStep(20);
        volume->setValue(70);
        volume->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(frmVolume);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 48, 16));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frmVoiceName = new AnimatedQFrame(groupBox_14);
        frmVoiceName->setObjectName(QStringLiteral("frmVoiceName"));
        frmVoiceName->setGeometry(QRect(10, 280, 321, 44));
        frmVoiceName->setFrameShape(QFrame::StyledPanel);
        frmVoiceName->setFrameShadow(QFrame::Raised);
        voice = new QComboBox(frmVoiceName);
        voice->setObjectName(QStringLiteral("voice"));
        voice->setGeometry(QRect(95, 10, 210, 25));
        voice->setMinimumSize(QSize(0, 25));
        voice->setMaximumSize(QSize(16777215, 40));
        label_6 = new QLabel(frmVoiceName);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 10, 72, 16));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frmPitch = new AnimatedQFrame(groupBox_14);
        frmPitch->setObjectName(QStringLiteral("frmPitch"));
        frmPitch->setGeometry(QRect(10, 130, 321, 44));
        frmPitch->setFrameShape(QFrame::StyledPanel);
        frmPitch->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frmPitch);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 32, 16));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pitch = new QSlider(frmPitch);
        pitch->setObjectName(QStringLiteral("pitch"));
        pitch->setGeometry(QRect(75, 10, 230, 25));
        pitch->setMinimumSize(QSize(0, 25));
        pitch->setMaximumSize(QSize(16777215, 40));
        pitch->setMinimum(-10);
        pitch->setMaximum(10);
        pitch->setSingleStep(1);
        pitch->setOrientation(Qt::Horizontal);
        pbSpeakAll = new AnimatedQPushButton(groupBox_14);
        pbSpeakAll->setObjectName(QStringLiteral("pbSpeakAll"));
        pbSpeakAll->setGeometry(QRect(180, 330, 141, 30));
        pbSpeakAll->setMinimumSize(QSize(70, 25));
        groupBox_15 = new QGroupBox(tbSpeech);
        groupBox_15->setObjectName(QStringLiteral("groupBox_15"));
        groupBox_15->setGeometry(QRect(10, 410, 341, 181));
        layoutWidget = new QWidget(groupBox_15);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 321, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pbLoadText = new AnimatedQPushButton(layoutWidget);
        pbLoadText->setObjectName(QStringLiteral("pbLoadText"));
        pbLoadText->setMinimumSize(QSize(70, 25));

        gridLayout->addWidget(pbLoadText, 1, 1, 1, 1);

        pbDelLastCharacter = new AnimatedQPushButton(layoutWidget);
        pbDelLastCharacter->setObjectName(QStringLiteral("pbDelLastCharacter"));
        pbDelLastCharacter->setMinimumSize(QSize(70, 25));

        gridLayout->addWidget(pbDelLastCharacter, 2, 0, 1, 1);

        pbReset = new AnimatedQPushButton(layoutWidget);
        pbReset->setObjectName(QStringLiteral("pbReset"));
        pbReset->setMinimumSize(QSize(70, 25));

        gridLayout->addWidget(pbReset, 2, 1, 1, 1);

        pbEditColor = new AnimatedQPushButton(layoutWidget);
        pbEditColor->setObjectName(QStringLiteral("pbEditColor"));
        pbEditColor->setMinimumSize(QSize(70, 25));

        gridLayout->addWidget(pbEditColor, 0, 0, 1, 1);

        pbEditFont = new AnimatedQPushButton(layoutWidget);
        pbEditFont->setObjectName(QStringLiteral("pbEditFont"));
        pbEditFont->setMinimumSize(QSize(70, 25));

        gridLayout->addWidget(pbEditFont, 0, 1, 1, 1);

        pbSaveText = new AnimatedQPushButton(layoutWidget);
        pbSaveText->setObjectName(QStringLiteral("pbSaveText"));
        pbSaveText->setMinimumSize(QSize(70, 25));

        gridLayout->addWidget(pbSaveText, 1, 0, 1, 1);

        tabWidget->addTab(tbSpeech, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_11 = new QGroupBox(tab);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setGeometry(QRect(9, 19, 341, 201));
        frmLTR = new AnimatedQFrame(groupBox_11);
        frmLTR->setObjectName(QStringLiteral("frmLTR"));
        frmLTR->setGeometry(QRect(10, 20, 321, 51));
        frmLTR->setFrameShape(QFrame::StyledPanel);
        frmLTR->setFrameShadow(QFrame::Raised);
        hsLtRed = new QSlider(frmLTR);
        hsLtRed->setObjectName(QStringLiteral("hsLtRed"));
        hsLtRed->setGeometry(QRect(40, 10, 221, 35));
        hsLtRed->setMinimumSize(QSize(0, 35));
        hsLtRed->setMaximumSize(QSize(16777215, 16777215));
        hsLtRed->setMaximum(255);
        hsLtRed->setSingleStep(1);
        hsLtRed->setPageStep(5);
        hsLtRed->setValue(0);
        hsLtRed->setOrientation(Qt::Horizontal);
        lblLtRed = new QLabel(frmLTR);
        lblLtRed->setObjectName(QStringLiteral("lblLtRed"));
        lblLtRed->setGeometry(QRect(10, 20, 16, 16));
        sizePolicy.setHeightForWidth(lblLtRed->sizePolicy().hasHeightForWidth());
        lblLtRed->setSizePolicy(sizePolicy);
        lblLtRed->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblLtRedValue = new QLabel(frmLTR);
        lblLtRedValue->setObjectName(QStringLiteral("lblLtRedValue"));
        lblLtRedValue->setGeometry(QRect(280, 20, 31, 20));
        frmLTG = new AnimatedQFrame(groupBox_11);
        frmLTG->setObjectName(QStringLiteral("frmLTG"));
        frmLTG->setGeometry(QRect(10, 80, 321, 51));
        frmLTG->setFrameShape(QFrame::StyledPanel);
        frmLTG->setFrameShadow(QFrame::Raised);
        hsLtGreen = new QSlider(frmLTG);
        hsLtGreen->setObjectName(QStringLiteral("hsLtGreen"));
        hsLtGreen->setGeometry(QRect(40, 10, 221, 35));
        hsLtGreen->setMinimumSize(QSize(0, 35));
        hsLtGreen->setMaximumSize(QSize(16777215, 16777215));
        hsLtGreen->setMaximum(255);
        hsLtGreen->setSingleStep(1);
        hsLtGreen->setPageStep(5);
        hsLtGreen->setValue(0);
        hsLtGreen->setOrientation(Qt::Horizontal);
        lblLtGreen = new QLabel(frmLTG);
        lblLtGreen->setObjectName(QStringLiteral("lblLtGreen"));
        lblLtGreen->setGeometry(QRect(10, 20, 16, 16));
        sizePolicy.setHeightForWidth(lblLtGreen->sizePolicy().hasHeightForWidth());
        lblLtGreen->setSizePolicy(sizePolicy);
        lblLtGreen->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblLtGreenValue = new QLabel(frmLTG);
        lblLtGreenValue->setObjectName(QStringLiteral("lblLtGreenValue"));
        lblLtGreenValue->setGeometry(QRect(280, 20, 31, 20));
        frmLTB = new AnimatedQFrame(groupBox_11);
        frmLTB->setObjectName(QStringLiteral("frmLTB"));
        frmLTB->setGeometry(QRect(10, 140, 321, 51));
        frmLTB->setFrameShape(QFrame::StyledPanel);
        frmLTB->setFrameShadow(QFrame::Raised);
        hsLtBlue = new QSlider(frmLTB);
        hsLtBlue->setObjectName(QStringLiteral("hsLtBlue"));
        hsLtBlue->setGeometry(QRect(40, 10, 221, 35));
        hsLtBlue->setMinimumSize(QSize(0, 35));
        hsLtBlue->setMaximumSize(QSize(16777215, 16777215));
        hsLtBlue->setMaximum(255);
        hsLtBlue->setSingleStep(1);
        hsLtBlue->setPageStep(5);
        hsLtBlue->setValue(0);
        hsLtBlue->setOrientation(Qt::Horizontal);
        lblLtRed_3 = new QLabel(frmLTB);
        lblLtRed_3->setObjectName(QStringLiteral("lblLtRed_3"));
        lblLtRed_3->setGeometry(QRect(10, 20, 16, 16));
        sizePolicy.setHeightForWidth(lblLtRed_3->sizePolicy().hasHeightForWidth());
        lblLtRed_3->setSizePolicy(sizePolicy);
        lblLtRed_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblLtBlueValue = new QLabel(frmLTB);
        lblLtBlueValue->setObjectName(QStringLiteral("lblLtBlueValue"));
        lblLtBlueValue->setGeometry(QRect(280, 20, 31, 20));
        groupBox_12 = new QGroupBox(tab);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        groupBox_12->setGeometry(QRect(10, 230, 341, 201));
        frmUTR = new AnimatedQFrame(groupBox_12);
        frmUTR->setObjectName(QStringLiteral("frmUTR"));
        frmUTR->setGeometry(QRect(10, 20, 321, 51));
        frmUTR->setFrameShape(QFrame::StyledPanel);
        frmUTR->setFrameShadow(QFrame::Raised);
        hsGtRed = new QSlider(frmUTR);
        hsGtRed->setObjectName(QStringLiteral("hsGtRed"));
        hsGtRed->setGeometry(QRect(40, 10, 221, 35));
        hsGtRed->setMinimumSize(QSize(0, 35));
        hsGtRed->setMaximumSize(QSize(16777215, 16777215));
        hsGtRed->setMaximum(255);
        hsGtRed->setSingleStep(1);
        hsGtRed->setPageStep(5);
        hsGtRed->setValue(100);
        hsGtRed->setOrientation(Qt::Horizontal);
        lblGtRed = new QLabel(frmUTR);
        lblGtRed->setObjectName(QStringLiteral("lblGtRed"));
        lblGtRed->setGeometry(QRect(10, 20, 16, 16));
        sizePolicy.setHeightForWidth(lblGtRed->sizePolicy().hasHeightForWidth());
        lblGtRed->setSizePolicy(sizePolicy);
        lblGtRed->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblGtRedValue = new QLabel(frmUTR);
        lblGtRedValue->setObjectName(QStringLiteral("lblGtRedValue"));
        lblGtRedValue->setGeometry(QRect(280, 20, 31, 20));
        frmUTG = new AnimatedQFrame(groupBox_12);
        frmUTG->setObjectName(QStringLiteral("frmUTG"));
        frmUTG->setGeometry(QRect(10, 80, 321, 51));
        frmUTG->setFrameShape(QFrame::StyledPanel);
        frmUTG->setFrameShadow(QFrame::Raised);
        hsGtGreen = new QSlider(frmUTG);
        hsGtGreen->setObjectName(QStringLiteral("hsGtGreen"));
        hsGtGreen->setGeometry(QRect(40, 10, 221, 35));
        hsGtGreen->setMinimumSize(QSize(0, 35));
        hsGtGreen->setMaximumSize(QSize(16777215, 16777215));
        hsGtGreen->setMaximum(255);
        hsGtGreen->setSingleStep(1);
        hsGtGreen->setPageStep(5);
        hsGtGreen->setValue(100);
        hsGtGreen->setOrientation(Qt::Horizontal);
        lblGtGreen = new QLabel(frmUTG);
        lblGtGreen->setObjectName(QStringLiteral("lblGtGreen"));
        lblGtGreen->setGeometry(QRect(10, 20, 16, 16));
        sizePolicy.setHeightForWidth(lblGtGreen->sizePolicy().hasHeightForWidth());
        lblGtGreen->setSizePolicy(sizePolicy);
        lblGtGreen->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblGtGreenValue = new QLabel(frmUTG);
        lblGtGreenValue->setObjectName(QStringLiteral("lblGtGreenValue"));
        lblGtGreenValue->setGeometry(QRect(280, 20, 31, 20));
        frmUTB = new AnimatedQFrame(groupBox_12);
        frmUTB->setObjectName(QStringLiteral("frmUTB"));
        frmUTB->setGeometry(QRect(10, 140, 321, 51));
        frmUTB->setFrameShape(QFrame::StyledPanel);
        frmUTB->setFrameShadow(QFrame::Raised);
        hsGtBlue = new QSlider(frmUTB);
        hsGtBlue->setObjectName(QStringLiteral("hsGtBlue"));
        hsGtBlue->setGeometry(QRect(40, 10, 221, 35));
        hsGtBlue->setMinimumSize(QSize(0, 35));
        hsGtBlue->setMaximumSize(QSize(16777215, 16777215));
        hsGtBlue->setMaximum(255);
        hsGtBlue->setSingleStep(1);
        hsGtBlue->setPageStep(5);
        hsGtBlue->setValue(100);
        hsGtBlue->setOrientation(Qt::Horizontal);
        lblBlue = new QLabel(frmUTB);
        lblBlue->setObjectName(QStringLiteral("lblBlue"));
        lblBlue->setGeometry(QRect(10, 20, 16, 16));
        sizePolicy.setHeightForWidth(lblBlue->sizePolicy().hasHeightForWidth());
        lblBlue->setSizePolicy(sizePolicy);
        lblBlue->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblGtBlueValue = new QLabel(frmUTB);
        lblGtBlueValue->setObjectName(QStringLiteral("lblGtBlueValue"));
        lblGtBlueValue->setGeometry(QRect(280, 20, 31, 20));
        groupBox_13 = new QGroupBox(tab);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        groupBox_13->setGeometry(QRect(10, 439, 341, 131));
        pbSetBackground = new AnimatedQPushButton(groupBox_13);
        pbSetBackground->setObjectName(QStringLiteral("pbSetBackground"));
        pbSetBackground->setEnabled(false);
        pbSetBackground->setGeometry(QRect(140, 30, 171, 35));
        pbSetBackground->setMinimumSize(QSize(70, 25));
        chkBackgroundSubstractionActivated = new AnimatedQCheckBox(groupBox_13);
        chkBackgroundSubstractionActivated->setObjectName(QStringLiteral("chkBackgroundSubstractionActivated"));
        chkBackgroundSubstractionActivated->setGeometry(QRect(10, 30, 91, 35));
        chkBackgroundSubstractionActivated->setIconSize(QSize(16, 16));
        chkBackgroundSubstractionActivated->setChecked(false);
        frmBST = new AnimatedQFrame(groupBox_13);
        frmBST->setObjectName(QStringLiteral("frmBST"));
        frmBST->setGeometry(QRect(10, 70, 321, 51));
        frmBST->setFrameShape(QFrame::StyledPanel);
        frmBST->setFrameShadow(QFrame::Raised);
        hsBS = new QSlider(frmBST);
        hsBS->setObjectName(QStringLiteral("hsBS"));
        hsBS->setGeometry(QRect(40, 10, 221, 35));
        hsBS->setMinimumSize(QSize(0, 35));
        hsBS->setMaximumSize(QSize(16777215, 16777215));
        hsBS->setMaximum(765);
        hsBS->setSingleStep(1);
        hsBS->setPageStep(5);
        hsBS->setValue(150);
        hsBS->setOrientation(Qt::Horizontal);
        lblBS = new QLabel(frmBST);
        lblBS->setObjectName(QStringLiteral("lblBS"));
        lblBS->setGeometry(QRect(10, 20, 16, 16));
        sizePolicy.setHeightForWidth(lblBS->sizePolicy().hasHeightForWidth());
        lblBS->setSizePolicy(sizePolicy);
        lblBS->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblBSValue = new QLabel(frmBST);
        lblBSValue->setObjectName(QStringLiteral("lblBSValue"));
        lblBSValue->setGeometry(QRect(280, 20, 31, 20));
        tabWidget->addTab(tab, QString());
        tbRecognition = new QWidget();
        tbRecognition->setObjectName(QStringLiteral("tbRecognition"));
        groupBox_7 = new QGroupBox(tbRecognition);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 20, 331, 80));
        pbStopRecognitionEngine = new AnimatedQPushButton(groupBox_7);
        pbStopRecognitionEngine->setObjectName(QStringLiteral("pbStopRecognitionEngine"));
        pbStopRecognitionEngine->setEnabled(false);
        pbStopRecognitionEngine->setGeometry(QRect(240, 30, 80, 35));
        pbStopRecognitionEngine->setMinimumSize(QSize(70, 25));
        pbStartRecognitionEngine = new AnimatedQPushButton(groupBox_7);
        pbStartRecognitionEngine->setObjectName(QStringLiteral("pbStartRecognitionEngine"));
        pbStartRecognitionEngine->setGeometry(QRect(20, 30, 81, 35));
        pbStartRecognitionEngine->setMinimumSize(QSize(70, 25));
        groupBox_8 = new QGroupBox(tbRecognition);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 120, 331, 191));
        pbUp = new AnimatedQPushButton(groupBox_8);
        pbUp->setObjectName(QStringLiteral("pbUp"));
        pbUp->setGeometry(QRect(130, 30, 81, 35));
        pbUp->setMinimumSize(QSize(70, 25));
        pbRight = new AnimatedQPushButton(groupBox_8);
        pbRight->setObjectName(QStringLiteral("pbRight"));
        pbRight->setGeometry(QRect(220, 80, 81, 35));
        pbRight->setMinimumSize(QSize(70, 25));
        pbLeft = new AnimatedQPushButton(groupBox_8);
        pbLeft->setObjectName(QStringLiteral("pbLeft"));
        pbLeft->setGeometry(QRect(40, 80, 81, 35));
        pbLeft->setMinimumSize(QSize(70, 25));
        pbDown = new AnimatedQPushButton(groupBox_8);
        pbDown->setObjectName(QStringLiteral("pbDown"));
        pbDown->setGeometry(QRect(130, 130, 81, 35));
        pbDown->setMinimumSize(QSize(70, 25));
        groupBox_9 = new QGroupBox(tbRecognition);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 320, 331, 261));
        listWidget = new AnimatedQListWidget(groupBox_9);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 31, 291, 221));
        listWidget->setAlternatingRowColors(true);
        listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabWidget->addTab(tbRecognition, QString());
        tbUpdate = new QWidget();
        tbUpdate->setObjectName(QStringLiteral("tbUpdate"));
        groupBox_10 = new QGroupBox(tbUpdate);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(10, 20, 331, 151));
        pbStartUpdate = new AnimatedQPushButton(groupBox_10);
        pbStartUpdate->setObjectName(QStringLiteral("pbStartUpdate"));
        pbStartUpdate->setGeometry(QRect(20, 30, 301, 35));
        pbStartUpdate->setMinimumSize(QSize(70, 25));
        progressBar = new AnimatedQProgressBar(groupBox_10);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 90, 301, 41));
        progressBar->setValue(0);
        progressBar->setInvertedAppearance(false);
        tabWidget->addTab(tbUpdate, QString());
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 370, 311, 241));
        teLog = new AnimatedQTextEdit(groupBox_2);
        teLog->setObjectName(QStringLiteral("teLog"));
        teLog->setGeometry(QRect(20, 30, 266, 200));
        teLog->setMinimumSize(QSize(266, 200));
        teLog->setMaximumSize(QSize(288, 220));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 0, 311, 361));
        teText = new AnimatedQTextEdit(groupBox_3);
        teText->setObjectName(QStringLiteral("teText"));
        teText->setGeometry(QRect(20, 30, 266, 300));
        teText->setMinimumSize(QSize(266, 300));
        teText->setMaximumSize(QSize(288, 320));
        teText->setAutoFillBackground(true);
        teText->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(340, 0, 550, 615));
        groupBox->setMinimumSize(QSize(550, 615));
        groupBox->setMaximumSize(QSize(550, 615));
        lblVideo = new AnimatedQLabel(groupBox);
        lblVideo->setObjectName(QStringLiteral("lblVideo"));
        lblVideo->setGeometry(QRect(20, 30, 500, 380));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(50);
        sizePolicy2.setVerticalStretch(50);
        sizePolicy2.setHeightForWidth(lblVideo->sizePolicy().hasHeightForWidth());
        lblVideo->setSizePolicy(sizePolicy2);
        lblVideo->setMinimumSize(QSize(500, 380));
        lblVideo->setMaximumSize(QSize(520, 400));
        lblVideo->setSizeIncrement(QSize(10, 10));
        lblVideo->setMouseTracking(true);
        lblVideo->setStyleSheet(QLatin1String("hover:\n"
"{	\n"
"min-width:520px;\n"
"	max-width:520px;\n"
"	min-height:420px;\n"
"	max-height:420px;\n"
"}"));
        lblVideo->setFrameShape(QFrame::NoFrame);
        lblVideo_2 = new AnimatedQLabel(groupBox);
        lblVideo_2->setObjectName(QStringLiteral("lblVideo_2"));
        lblVideo_2->setGeometry(QRect(20, 440, 181, 161));
        sizePolicy2.setHeightForWidth(lblVideo_2->sizePolicy().hasHeightForWidth());
        lblVideo_2->setSizePolicy(sizePolicy2);
        lblVideo_2->setMinimumSize(QSize(100, 100));
        lblVideo_2->setMaximumSize(QSize(1000, 1000));
        lblVideo_2->setSizeIncrement(QSize(10, 10));
        lblVideo_2->setMouseTracking(true);
        lblVideo_2->setStyleSheet(QLatin1String("hover:\n"
"{	\n"
"min-width:520px;\n"
"	max-width:520px;\n"
"	min-height:420px;\n"
"	max-height:420px;\n"
"}"));
        lblVideo_2->setFrameShape(QFrame::NoFrame);
        lblVideo_3 = new AnimatedQLabel(groupBox);
        lblVideo_3->setObjectName(QStringLiteral("lblVideo_3"));
        lblVideo_3->setGeometry(QRect(340, 440, 181, 161));
        sizePolicy2.setHeightForWidth(lblVideo_3->sizePolicy().hasHeightForWidth());
        lblVideo_3->setSizePolicy(sizePolicy2);
        lblVideo_3->setMinimumSize(QSize(100, 100));
        lblVideo_3->setMaximumSize(QSize(1000, 1000));
        lblVideo_3->setSizeIncrement(QSize(10, 10));
        lblVideo_3->setMouseTracking(true);
        lblVideo_3->setStyleSheet(QLatin1String("hover:\n"
"{	\n"
"min-width:520px;\n"
"	max-width:520px;\n"
"	min-height:420px;\n"
"	max-height:420px;\n"
"}"));
        lblVideo_3->setFrameShape(QFrame::NoFrame);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
#ifndef QT_NO_SHORTCUT
        label_4->setBuddy(language);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gesture Recognizer", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Select capture device:", Q_NULLPTR));
        pbStartVideoAcquisition->setText(QApplication::translate("MainWindow", "&Start", Q_NULLPTR));
        pbStopVideoAcquisition->setText(QApplication::translate("MainWindow", "S&top", Q_NULLPTR));
        pbRefreshCaptureDevices->setText(QApplication::translate("MainWindow", "&Refresh", Q_NULLPTR));
        chkMirrored->setText(QApplication::translate("MainWindow", "Mirror", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Recording:", Q_NULLPTR));
        pbRecord->setText(QApplication::translate("MainWindow", "&Record", Q_NULLPTR));
        pbStopRecording->setText(QApplication::translate("MainWindow", "St&op", Q_NULLPTR));
        pbRecordingPath->setText(QApplication::translate("MainWindow", "Path", Q_NULLPTR));
        lblRecordingPath->setText(QString());
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Snapshot:", Q_NULLPTR));
        pbSnapshot->setText(QApplication::translate("MainWindow", "Snapshot", Q_NULLPTR));
        pbSnapshotPath->setText(QApplication::translate("MainWindow", "Path", Q_NULLPTR));
        lblSnapshotPath->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tbVideo), QApplication::translate("MainWindow", "Video", Q_NULLPTR));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "Speech", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Engine:", Q_NULLPTR));
        pbTestTextToSpeech->setText(QApplication::translate("MainWindow", "Test", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Rate:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "&Language:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Volume:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Voice name:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Pitch:", Q_NULLPTR));
        pbSpeakAll->setText(QApplication::translate("MainWindow", "Speak All", Q_NULLPTR));
        groupBox_15->setTitle(QApplication::translate("MainWindow", "Text", Q_NULLPTR));
        pbLoadText->setText(QApplication::translate("MainWindow", "Load Text", Q_NULLPTR));
        pbDelLastCharacter->setText(QApplication::translate("MainWindow", "Del", Q_NULLPTR));
        pbReset->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        pbEditColor->setText(QApplication::translate("MainWindow", "Edit Color", Q_NULLPTR));
        pbEditFont->setText(QApplication::translate("MainWindow", "Edit Font", Q_NULLPTR));
        pbSaveText->setText(QApplication::translate("MainWindow", "Save Text", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tbSpeech), QApplication::translate("MainWindow", "Speech / Text", Q_NULLPTR));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "Lower Threshold", Q_NULLPTR));
        lblLtRed->setText(QApplication::translate("MainWindow", "R:", Q_NULLPTR));
        lblLtRedValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lblLtGreen->setText(QApplication::translate("MainWindow", "G:", Q_NULLPTR));
        lblLtGreenValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lblLtRed_3->setText(QApplication::translate("MainWindow", "B:", Q_NULLPTR));
        lblLtBlueValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        groupBox_12->setTitle(QApplication::translate("MainWindow", "Upper Threshold", Q_NULLPTR));
        lblGtRed->setText(QApplication::translate("MainWindow", "R:", Q_NULLPTR));
        lblGtRedValue->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        lblGtGreen->setText(QApplication::translate("MainWindow", "G:", Q_NULLPTR));
        lblGtGreenValue->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        lblBlue->setText(QApplication::translate("MainWindow", "B:", Q_NULLPTR));
        lblGtBlueValue->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        groupBox_13->setTitle(QApplication::translate("MainWindow", "Background Substraction", Q_NULLPTR));
        pbSetBackground->setText(QApplication::translate("MainWindow", "Set Background", Q_NULLPTR));
        chkBackgroundSubstractionActivated->setText(QApplication::translate("MainWindow", "Activated", Q_NULLPTR));
        lblBS->setText(QApplication::translate("MainWindow", "T:", Q_NULLPTR));
        lblBSValue->setText(QApplication::translate("MainWindow", "150", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Detection", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Recognition Engine", Q_NULLPTR));
        pbStopRecognitionEngine->setText(QApplication::translate("MainWindow", "S&top", Q_NULLPTR));
        pbStartRecognitionEngine->setText(QApplication::translate("MainWindow", "&Start", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Region Of Interest", Q_NULLPTR));
        pbUp->setText(QApplication::translate("MainWindow", "Up", Q_NULLPTR));
        pbRight->setText(QApplication::translate("MainWindow", "Right", Q_NULLPTR));
        pbLeft->setText(QApplication::translate("MainWindow", "Left", Q_NULLPTR));
        pbDown->setText(QApplication::translate("MainWindow", "Down", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Recognition Methods", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tbRecognition), QApplication::translate("MainWindow", "Recognition", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Update Engine", Q_NULLPTR));
        pbStartUpdate->setText(QApplication::translate("MainWindow", "&Start", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tbUpdate), QApplication::translate("MainWindow", "Update", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Messages", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Text", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Video", Q_NULLPTR));
        lblVideo->setText(QString());
        lblVideo_2->setText(QString());
        lblVideo_3->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
