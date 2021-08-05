#ifndef GRFILEINFO_H
#define GRFILEINFO_H
#include <QString>
#include <QDomDocument>

/*!
 *\brief The GRFileInfo class describes a downloadable or an existing file.
 *
 * The GRFileInfo class provides means to:
 * - describe files to be downloaded or that are already present.
 * - import information from a QDomElement.
 * - export information to QDomNode.
 */
class GRFileInfo
{
public:

    /*!
     * Constructs an empty object.
     */
    GRFileInfo();

    /*!
     * Constructs an object with the specified file name, destination and version.
     * \param fileName The name of the described file.
     * \param destination The destination of the described file.
     * \param version The version of the described file.
     */
    GRFileInfo(QString fileName,QString destination,int version);

    /*!
     * The xCompareResults enum includes the possible results of comparing two GRFileInfo objects:
     * - The first object is the object calling \em compare function.
     * - The second object is the object passed as argument to \em compare function.
     * \sa #compare
     */
    enum xCompareResults{
                  DifferentFileNames,/*!< The two GRFileInfo objects describe files with different names. */
                  DifferentDestination,/*!< The two GRFileInfo objects describe files with the same name but different destination. */
                  Newer,/*!< The two GRFileInfo objects describe files with the same name and destination and the first file's version is greater than the other file's version. */
                  Older,/*!< The two GRFileInfo objects describe files with the same name and destination and the first file's version is lower than the other file's version. */
                  Same /*!< The two GRFileInfo objects describe files with different names. */
    } ;

    /*!
     * CompareResults is a type definition for xCompareResults
     * \sa xCompareResults
     */
    typedef xCompareResults CompareResults;


    QString fileName;/*!< The name of the described file. */
    /*!
     * The destination of the described file.
     *
     * \note The charecter * refers to the application executable
     * file path which is the parent to all destinations.
     * when the destination is not the parent but a folder inside do not use the star.
     */
    QString destination;

    int version;/*!< The version of the described file. */

    /*!
     * Compares between the calling object and another object.
     * \param file The object that the calling object is to be compared against.
     * \return Comparison results \sa CompareResults .
     */
    CompareResults compare(GRFileInfo &file);

    /*!
     * Fills the class data members with values from a QDomElement that describes the following xml pattern:
     * \code
     * <file>
     *  <fileName>fileName</fileName>
     *   <version>version</version>
     *  <destination>destination</destination>
     *  </file>
     * \endcode
     * \param element The QDomElement object.
     * \return true when \em element has the right structure and the update process is successful and false otherwise.
     */
    bool updateFromXMLElement(QDomElement element);

    /*!
     * Exports class data members to a QDomNode object that describes the following xml pattern:
     * \code
     * <file>
     *  <fileName>fileName</fileName>
     *   <version>version</version>
     *  <destination>destination</destination>
     *  </file>
     * \endcode
     * \return The QDomNode object described earlier.
     */
    QDomNode exportToXMLNode();
};

#endif // GRFILEINFO_H
