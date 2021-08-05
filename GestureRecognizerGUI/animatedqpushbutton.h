#ifndef ANIMATEDQPUSHBUTTON_H
#define ANIMATEDQPUSHBUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>

/*!
 * \brief The AnimatedQPushButton  widget provides a command button
 *
 * The AnimatedQLabel inherits QPushButton class and adds visual effects to its normal appearance.
 * its dimensions.
 */
class AnimatedQPushButton : public QPushButton
{
public:
    /*!
     * Constructs an AnimatedQPushButton object.
     * \param parent The parent widget.
     */
    AnimatedQPushButton(QWidget *parent=0);

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

#endif // ANIMATEDQPUSHBUTTON_H
