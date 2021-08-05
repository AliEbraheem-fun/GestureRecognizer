#include "animatedqtextedit.h"

AnimatedQTextEdit::AnimatedQTextEdit(QWidget *parent): QTextEdit(parent)
{
    animation=0;
    animationStarted=false;
    paramsSet=false;
    setMouseTracking(true);
}
void AnimatedQTextEdit::leaveEvent(QEvent *event)
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

void AnimatedQTextEdit::mouseMoveEvent(QMouseEvent *event)
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
        animation->setEndValue(QRect(originalX-int(0.01*originalWidth), originalY-int(0.01*originalHeight), originalWidth+int(0.02*originalWidth), originalHeight+int(0.02*originalHeight)));
        animation->start();
    }
}
