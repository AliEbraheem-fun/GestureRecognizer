#include "animatedqpushbutton.h"

AnimatedQPushButton::AnimatedQPushButton(QWidget *parent):QPushButton(parent)
{
    animation=0;
    animationStarted=false;
    paramsSet=false;
    setMouseTracking(true);
}
void AnimatedQPushButton::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)
    if(animationStarted)
    {
        animationStarted=false;
        animation->stop();
        delete animation;
        animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(100);
        animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
        animation->setEndValue(QRect(originalX, originalY, originalWidth, originalHeight));
        animation->start();
    }
}

void AnimatedQPushButton::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    if(!paramsSet)
    {
        originalX=this->x();
        originalY=this->y();
        originalWidth=this->width();
        originalHeight=this->height();
        paramsSet=true;
    }
    if(!animationStarted)
    {
        animationStarted=true;
        if(animation!=0)
        {
            animation->stop();
            delete animation;
        }
        animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(100);
        animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
        animation->setEndValue(QRect(originalX-5, originalY-5, originalWidth+10, originalHeight+10));
        animation->start();
    }
}
