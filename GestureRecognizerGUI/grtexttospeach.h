#ifndef GRTEXTTOSPEACH_H
#define GRTEXTTOSPEACH_H

#include <QtCore>
#include <QtWidgets>
#include <QtMultimedia>
#include <QtTextToSpeech>

/*!
 * \brief The GRTextToSpeech class controls the sound settings and converts text to speech.
 *
 * The GRTextToSpeech class controlls the different sound parameters such as
 * the sound volume, rate and pitch. It also controls the process of converting
 * text to speech such as the language, the voice (speaking person) and the
 * conversion engine.
 */
class GRTextToSpeech: public QObject
{
    Q_OBJECT
public:

    /*!
     * Constructs a GRTextToSpeech object.
     */
    GRTextToSpeech();

    /*!
     * Constructs a GRTextToSpeech object passing the necessary control widgets.
     * \param volume A QSlider object whose value controls the sound volume.
     * \param rate A QSlider object whose value controls the speech rate.
     * \param pitch A QSlider object whose value controls the speech pitch.
     * \param language A QComboBox object whose selected value determines the used language.
     * \param voice A QComboBox object whose selected value determines the used voice.
     * \param engine A QComboBox object whose selected value determines the used text to speech engine.
     */
    GRTextToSpeech(QSlider *volume,QSlider *rate,QSlider *pitch,
                   QComboBox *language,QComboBox *voice, QComboBox *engine );

    /*!
     * Sets the necessary control widgets.
     * \param volume A QSlider object whose value controls the sound volume.
     * \param rate A QSlider object whose value controls the speech rate.
     * \param pitch A QSlider object whose value controls the speech pitch.
     * \param language A QComboBox object whose selected value determines the used language.
     * \param voice A QComboBox object whose selected value determines the used voice.
     * \param engine A QComboBox object whose selected value determines the used text to speech engine.
     */
    void setParams(QSlider *volume,QSlider *rate,QSlider *pitch,
                   QComboBox *language,QComboBox *voice, QComboBox *engine );
public slots:

    /*!
     * Converts a specific text to speech.
     * \param saying The text to be converted to speech.
     */
    void speak(QString saying);

private slots:

    /*!
     * Sets speech rate.
     * \param rate the selected rate of speech.
     */
    void setRate(int rate);

    /*!
     * Sets speech pitch.
     * \param rate the selected pitch of speech.
     */
    void setPitch(int pitch);

    /*!
     * Sets speech volume.
     * \param rate the selected volume of speech.
     */
    void setVolume(int volume);

    /*!
     * Takes the necessary measures when a new text to speech engine is selected.
     * \param index The index of selected engine in the corresponding combo box.
     */
    void engineSelected(int index);

    /*!
     * Takes the necessary measures when a new language is selected.
     * \param index The index of selected language in the corresponding combo box.
     */
    void languageSelected(int language);

    /*!
     * Takes the necessary measures when a new voice is selected.
     * \param index The index of selected voice in the corresponding combo box.
     */
    void voiceSelected(int index);

    /*!
     * Takes the necessary measures when a new language and therefore a new locale is selected.
     * \param locale The new locale.
     */
    void localeChanged(const QLocale &locale);

private:

    QTextToSpeech *m_speech; /*!< A pointer to  a QTextToSpeech object which provides a convenient access to text-to-speech engines.*/

    QVector<QVoice> m_voices;/*!< A vector containing the available voices. */

    QSlider *volume; /*!< A pointer to the slider controlling the volume level. */
    QSlider *rate; /*!< A pointer to the slider controlling the speech rate. */
    QSlider *pitch; /*!< A pointer to the slider controlling the speech pitch. */
    QComboBox *language; /*!< A pointer to the combo box controlling the speech language.*/
    QComboBox *voice; /*!< A pointer to the combo box controlling the speech voice.*/
    QComboBox *engine;/*!< A pointer to the combo box controlling the speech engine.*/

};

#endif // GRTEXTTOSPEACH_H
