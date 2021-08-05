#include "grtexttospeach.h"

GRTextToSpeech::GRTextToSpeech()
{
    volume=0;
    rate=0;
    pitch=0;
    language=0;
    voice=0;
    engine=0;
}

GRTextToSpeech::GRTextToSpeech(QSlider *volume,QSlider *rate,QSlider *pitch,
               QComboBox *language,QComboBox *voice, QComboBox *engine )
{
    setParams(volume, rate, pitch,language, voice, engine);
}

void GRTextToSpeech::setParams(QSlider *volume, QSlider *rate, QSlider *pitch, QComboBox *language, QComboBox *voice, QComboBox *engine)
{
    this->volume=volume;
    this->rate=rate;
    this->pitch=pitch;
    this->language=language;
    this->voice=voice;
    this->engine=engine;
    this->volume->setMinimum(0);
    this->volume->setMaximum(100);
    this->pitch->setMinimum(-10);
    this->pitch->setMaximum(10);
    this->rate->setMinimum(-10);
    this->rate->setMaximum(10);
    this->engine->clear();
    this->voice->clear();
    this->language->clear();

    m_speech=0;
    QLoggingCategory::setFilterRules(QStringLiteral("qt.speech.tts=true \n qt.speech.tts.*=true"));

    // Populate engine selection list
    this->engine->addItem("Default", QString("default"));
    foreach (QString engine_, QTextToSpeech::availableEngines())
        this->engine->addItem(engine_, engine_);
    this->engine->setCurrentIndex(0);
    engineSelected(0);
    connect(this->pitch, SIGNAL(valueChanged(int)), this, SLOT(setPitch(int)));
    connect(this->rate, SIGNAL(valueChanged(int)), this, SLOT(setRate(int)));
    connect(this->volume, SIGNAL(valueChanged(int)), this, SLOT(setVolume(int)));
    connect(this->engine, SIGNAL(currentIndexChanged(int)), this, SLOT(engineSelected(int)));
    this->volume->setValue(70);
    this->pitch->setValue(0);
    this->rate->setValue(0);
}

void GRTextToSpeech::speak(QString saying)
{
    m_speech->say(saying);
}
void GRTextToSpeech::setRate(int rate)
{
    m_speech->setRate(rate / 10.0);
}

void GRTextToSpeech::setPitch(int pitch)
{
    m_speech->setPitch(pitch / 10.0);
}

void GRTextToSpeech::setVolume(int volume)
{
    m_speech->setVolume(volume / 100.0);
}

void GRTextToSpeech::engineSelected(int index)
{
    QString engineName = engine->itemData(index).toString();
    delete m_speech;
    if (engineName == "default")
        m_speech = new QTextToSpeech(this);
    else
        m_speech = new QTextToSpeech(engineName, this);
    disconnect(language, SIGNAL(currentIndexChanged(int)), this,SLOT(languageSelected(int)));
    language->clear();
    // Populate the languages combobox before connecting its signal.
    QVector<QLocale> locales = m_speech->availableLocales();
    QLocale current = m_speech->locale();
    foreach (const QLocale &locale, locales) {
        QString name(QString("%1 (%2)")
                     .arg(QLocale::languageToString(locale.language()))
                     .arg(QLocale::countryToString(locale.country())));
        QVariant localeVariant(locale);
        language->addItem(name, localeVariant);
        if (locale.name() == current.name())
            current = locale;
    }
    setRate(rate->value());
    setPitch(pitch->value());
    setVolume(volume->value());

    connect(m_speech, SIGNAL(localeChanged(const QLocale &)), this, SLOT(localeChanged (const QLocale &)));

    connect(language,SIGNAL(currentIndexChanged(int)), this, SLOT(languageSelected(int)));

    localeChanged(current);
}

void GRTextToSpeech::languageSelected(int language)
{
    QLocale locale = this->language->itemData(language).toLocale();
    m_speech->setLocale(locale);
}

void GRTextToSpeech::voiceSelected(int index)
{
    m_speech->setVoice(m_voices.at(index));
}

void GRTextToSpeech::localeChanged(const QLocale &locale)
{
    QVariant localeVariant(locale);
    language->setCurrentIndex(language->findData(localeVariant));

    disconnect(voice, SIGNAL(currentIndexChanged(int)), this, SLOT(voiceSelected(int)));
    voice->clear();

    m_voices = m_speech->availableVoices();
    QVoice currentVoice = m_speech->voice();
    foreach (const QVoice &voice, m_voices) {
        this->voice->addItem(QString("%1 - %2 - %3").arg(voice.name())
                          .arg(QVoice::genderName(voice.gender()))
                          .arg(QVoice::ageName(voice.age())));
        if (voice.name() == currentVoice.name())
            this->voice->setCurrentIndex(this->voice->count() - 1);
    }
    connect(voice, SIGNAL(currentIndexChanged(int)), this, SLOT(voiceSelected(int)));
}
