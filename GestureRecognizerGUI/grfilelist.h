#ifndef GRFILELIST_H
#define GRFILELIST_H
#include <QtCore>
#include "grfileinfo.h"

/*!
 * \brief The GRFileList class describes a downloadable or an existing list of files.
 *
 * The GRFileList class provides means to:
 * - describe a group of files to be downloaded or that are already present.
 * - parse an xml file with a specific structure to read information about a group of files.
 * - save the files that this class refer to as an xml file.
 * - differentiate between two lists of files in order to obtain the files that need to be changed.
 */
class GRFileList
{
public:
    /*!
     * Constructs a GRFileList object.
     */
    GRFileList();

    QList<GRFileInfo> fileList;/*!< The container in which files information are listed. */

    /*!
     *
     * Parses an xml file with the following structure:
     * \code
     * <?xml version="1.0" encoding="UTF-8"?>
     * <filelist>
     *      <file>
     *          <fileName>file1</fileName>
     *          <version>1</version>
     *          <destination>Plugins</destination>
     *      </file>
     *         .
     *         .
     *      <file>
     *          <fileName>filen</fileName>
     *          <version>1</version>
     *          <destination>Plugins</destination>
     *      </file>
     * </filelist>
     * \endcode
     * and saves files information to \ref fileList.
     * \param xmlFile The path to the xml file
     * \return true if all went allright and false if something wrong happened e.g. wrong file format.
     */
    bool parse(QString xmlFile);

    /*!
     *
     * Saves  the file list to an xml file with the following structure:
     * \code
     * <?xml version="1.0" encoding="UTF-8"?>
     * <filelist>
     *      <file>
     *          <fileName>file1</fileName>
     *          <version>1</version>
     *          <destination>Plugins</destination>
     *      </file>
     *         .
     *         .
     *      <file>
     *          <fileName>filen</fileName>
     *          <version>1</version>
     *          <destination>Plugins</destination>
     *      </file>
     * </filelist>
     * \endcode
     *
     * \param fileName The path (including the name) to which the xml file is to be saved.
     * \return true if all went allright and false if something wrong happened.
     */
    bool save(QString fileName);

    /*!
     * Finds the files that exist in both \em fileList and in \em otherFileList but are newer in \em fileList
     *  as well as files that exist only in \em fileList.
     * \param otherFileList The file list to which \em fileList is to be compared.
     * \return A list of new and files most recent files in \em fileList as QList<GRFileInfo>.
     */
    QList<GRFileInfo> getFilesToBeUpdated(QList<GRFileInfo> otherFileList);

    /*!
     * Converts \em fileList to a readable QString that contains a list
     * of files and information about these files.
     * \return A QString representing \em fileList.
     */
    QString getString();
};

#endif // GRFILELIST_H
