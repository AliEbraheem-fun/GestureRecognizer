#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::unloadDlls()
{
    for(int i=1;i<plugins.length();i++)
    {
        delete plugins[i];
    }
    plugins.clear();
    for(int i=0;i<loaders.length();i++)
    {
        loaders[i]->unload();
        delete loaders[i];
    }
    loaders.clear();

}

void MainWindow::loadDlls()
{
    QDir pluginsDir = QDir(QApplication::applicationDirPath()+"/plugins");
    unloadDlls();
    foreach (QString fileName, pluginsDir.entryList(QDir::Files))
    {
        QPluginLoader *loader=new QPluginLoader(pluginsDir.absoluteFilePath(fileName),this);
        if (GRAbstractRecognizerPlugin* obj = qobject_cast<GRAbstractRecognizerPlugin *>(loader->instance()))
        {
            loaders.append(loader);
            plugins.append(obj);
        }
    }
}


void MainWindow::updateRecognizerList()
{
    loadDlls();
    ui->listWidget->clear();
    for(int i=0;i<plugins.length();i++)
    {
        ui->listWidget->addItem(plugins[i]->getName());
    }


}

void MainWindow::on_pbUp_clicked()
{
    roi.y--;
}

void MainWindow::on_pbDown_clicked()
{
    roi.y++;
}

void MainWindow::on_pbRight_clicked()
{
    roi.x++;
}

void MainWindow::on_pbLeft_clicked()
{
    roi.x--;
}

void MainWindow::initSamplesPath()
{
    paths
    <<"data/A"
    <<"data/B"
    <<"data/C"
    <<"data/D"
    <<"data/E"
    <<"data/F"
    <<"data/G"
    <<"data/H"
    <<"data/I"
    <<"data/J"
    <<"data/K"
    <<"data/L"
    <<"data/M"
    <<"data/N"
    <<"data/O"
    <<"data/P"
    <<"data/Q"
    <<"data/R"
    <<"data/S"
    <<"data/T"
    <<"data/U"
    <<"data/V"
    <<"data/W"
    <<"data/X"
    <<"data/Y"
    <<"data/Z"
    <<"data/SPACE"
    <<"data/UNKNOWN";
;
    labels.push_back(int('A'));
    labels.push_back(int('B'));
    labels.push_back(int('C'));
    labels.push_back(int('D'));
    labels.push_back(int('E'));
    labels.push_back(int('F'));
    labels.push_back(int('G'));
    labels.push_back(int('H'));
    labels.push_back(int('I'));
    labels.push_back(int('J'));
    labels.push_back(int('K'));
    labels.push_back(int('L'));
    labels.push_back(int('M'));
    labels.push_back(int('N'));
    labels.push_back(int('O'));
    labels.push_back(int('P'));
    labels.push_back(int('Q'));
    labels.push_back(int('R'));
    labels.push_back(int('S'));
    labels.push_back(int('T'));
    labels.push_back(int('U'));
    labels.push_back(int('V'));
    labels.push_back(int('W'));
    labels.push_back(int('X'));
    labels.push_back(int('Y'));
    labels.push_back(int('Z'));
    labels.push_back(int(' '));
    labels.push_back(int('?'));
}

void MainWindow::initROI()
{
    roi.x=frameWidth-HAND_REGION_X_OFFSET-HAND_REGION_WIDTH;
    roi.y=HAND_REGION_Y_OFFSET;
    roi.width=HAND_REGION_WIDTH;
    roi.height=HAND_REGION_HEIGHT;
}


void MainWindow::on_pbStartRecognitionEngine_clicked()
{
    currentRecognizer=ui->listWidget->currentRow();
    if(currentRecognizer>=0)
    {
        QList<GRAbstractRecognizerPlugin *> plugin;
        plugin<<plugins[currentRecognizer];
        bgl=new GRBackgroundLoader(paths,labels,plugin);
        connect(bgl,SIGNAL(log(QString)),this,SLOT(log(QString)));
        connect(bgl,SIGNAL(complete()),this,SLOT(recognitionEngineStarter()));
        bgl->start();
        ui->pbStartRecognitionEngine->setEnabled(false);
    }
}

void MainWindow::on_pbStopRecognitionEngine_clicked()
{
    if(engine!=0)
    {
        engine->stopRecognitionEngine();
        engine=0;
        ui->pbStartRecognitionEngine->setEnabled(true);
        ui->pbStopRecognitionEngine->setEnabled(false);
        for(int i=0;i<plugins.length();i++)
        {
            delete plugins[i];
        }
        plugins.clear();
        updateRecognizerList();
        if(-1<currentRecognizer&& currentRecognizer<plugins.length())
        {
            ui->listWidget->setCurrentRow(currentRecognizer);
        }
        ui->pbStartUpdate->setEnabled(true);

    }
}

void MainWindow::recognitionEngineStarter()
{
    engine=new GRRecognitionEngine();
    engine->addRecognizer(plugins[currentRecognizer]);
    connect(engine,SIGNAL(gestureRecognized(int)),this,SLOT(gestureRecognized(int)));
    engine->startRecognitionEngine();
    ui->pbStopRecognitionEngine->setEnabled(true);
}

void MainWindow::gestureRecognized(int gest)
{
    m_speech->speak(synthesizer.whatToSay(gest));
}
