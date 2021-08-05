#include "animatedqlabel.h"

AnimatedQLabel::AnimatedQLabel(QWidget *parent): QLabel(parent)
{
    animation=0;
    animationStarted=false;
    paramsSet=false;
    setMouseTracking(true);
}

void AnimatedQLabel::leaveEvent(QEvent *event)
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

void AnimatedQLabel::mouseMoveEvent(QMouseEvent *event)
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
        animation->setEndValue(QRect(originalX-int(5), originalY-int(5), originalWidth+int(10), originalHeight+int(10)));
        animation->start();
    }
}
