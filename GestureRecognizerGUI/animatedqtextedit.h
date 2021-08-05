#ifndef ANIMATEDQTEXTEDIT_H
#define ANIMATEDQTEXTEDIT_H

#include <QPropertyAnimation>
#include <QTextEdit>

/*!
 * \brief The AnimatedQTextEdit widget provides means to display and edit both plain and rich text.
 *
 * The AnimatedQTextEdit inherits QTextEdit class and adds visual effects to its normal appearance.
 */
class AnimatedQTextEdit : public QTextEdit
{
    Q_OBJECT
public:

    /*!
     * Constructs an AnimatedQTextEdit object.
     * \param parent The parent widget.
     */
    AnimatedQTextEdit(QWidget *parent=0);

    /*!
     * A reimplemented event handler that receives an event when the mouse cursor leaves the widget.
     * \param event A pointer to the QEvent object that contains event information.
     */
    void leaveEvent(QEvent *event);

    /*!
     * A reimplemented event handler that receives an event when the mouse cursor is moving over the widget.
     * \param event A pointer to the QMouseEvent object that contains event information such as mouse position.
     */
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPropertyAnimation *animation;/*!< Used to make the AnimatedQLabel object's size change. */
    int originalWidth;/*!< The original width of the widget when it is first created. */
    int originalHeight;/*!< The original height of the widget when it is first created. */
    int originalX;/*!< The original x-coordinate of the widget when it is first created. */
    int originalY;/*!< The original y-coordinate of the widget when it is first created. */
    bool animationStarted;/*!< A flag that indicates there is an ongoing size change operation so the same operation is not started again in the \ref mouseMoveEvent event handler. */
    bool paramsSet;/*! A flag that indicates that \ref originalWidth \ref originalHeight \ref originalX \ref originalY are set. */
};

#endif // ANIMATEDQTEXTEDIT_H
