#ifndef GRWORDSYTHESIZER_H
#define GRWORDSYTHESIZER_H
#include <QtCore>
/*!
 * \brief The GRWordSynthesizer class constructs words and text from the recognized gestures.
 *
 * The GRDownloadManager class accepts the gestures resulting from the recognition
 * process in order to synthesize whole words and meaningful text.
 */
class GRWordSynthesizer: public QObject
{
    Q_OBJECT
public:

    /*!
     * Constructs a GRWordSynthesizer object.
     */
    GRWordSynthesizer();

    /*!
     * Adds a new gesture and synthesizes speech.
     * \param gest The most recently recognized gesture.
     * \return Returns a whole word after a gesture that indicates a space or end of word.
     */
    QString whatToSay(int gest);

    /*!
     * Returns the whole text resulting from the recognition process.
     * \return
     */
    QString getText();

    /*!
     * Clears the wole text.
     */
    void clear();

    /*!
     * Deletes the last character.
     */
    void del();

    /*!
     * Sets the text representing the outcome of the recognition process.
     */
    void setText(QString txt);

private:
    QString str;/*!< The word currently being constructed. */
    QString text;/*!< The text constructed so far. */
signals:
    /*!
     * A signal emitted when the "text" variable changes.
     */
    void textChanged(QString str_);
};

#endif // GRWORDSYTHESIZER_H
