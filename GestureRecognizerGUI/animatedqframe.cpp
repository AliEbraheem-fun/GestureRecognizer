#include "animatedqframe.h"

AnimatedQFrame::AnimatedQFrame(QWidget *parent): QFrame(parent)
{
    animation=0;
    animationStarted=false;
    paramsSet=false;
    setMouseTracking(true);
}

void AnimatedQFrame::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)
    if(animationStarted && paramsSet)
    {
        animationStarted=false;
        animation->stop();
        delete animation;
        animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(100);
        animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
        animation->setEndValue(QRect(originalX, originalY, originalWidth, originalHeight));
        animation->start();
        for(int i=0;i<this->children().length();i++)
        {
             delete childrenAnimation[i];
             childrenAnimation[i] = new QPropertyAnimation(((QWidget *) this->children()[i]), "geometry");
             childrenAnimation[i]->setDuration(100);
             childrenAnimation[i]->setStartValue(QRect(((QWidget *) this->children()[i])->x(), ((QWidget *) this->children()[i])->y(), ((QWidget *) this->children()[i])->width(), ((QWidget *) this->children()[i])->height()));
             childrenAnimation[i]->setEndValue(QRect(childrenOriginalX[i], childrenOriginalY[i], childrenOriginalWidth[i], childrenOriginalHeight[i]));
             childrenAnimation[i]->start();
        }
    }
}

void AnimatedQFrame::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    if(!paramsSet)
    {
        originalX=this->x();
        originalY=this->y();
        originalWidth=this->width();
        originalHeight=this->height();
        for(int i=0;i<this->children().length();i++)
        {
            childrenOriginalX<< ((QWidget *) this->children()[i])->x();
            childrenOriginalY<< ((QWidget *) this->children()[i])->y();
            childrenOriginalWidth<< ((QWidget *) this->children()[i])->width();
            childrenOriginalHeight<< ((QWidget *) this->children()[i])->height();
            childrenAnimation<<Q_NULLPTR;
        }
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
        for(int i=0;i<this->children().length();i++)
        {
            if(childrenAnimation[i]!=0)
            {
                childrenAnimation[i]->stop();
                delete childrenAnimation[i];
            }
        }
        animation = new QPropertyAnimation(this, "geometry");
        animation->setDuration(100);
        animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
        animation->setEndValue(QRect(originalX-int(5), originalY-int(5), originalWidth+int(10), originalHeight+int(10)));
        animation->start();
        for(int i=0;i<this->children().length();i++)
        {
            childrenAnimation[i] = new QPropertyAnimation(((QWidget *) (this->children()[i])), "geometry");
            childrenAnimation[i]->setDuration(100);
            childrenAnimation[i]->setStartValue(QRect(((QWidget *) (this->children()[i]))->x(), ((QWidget *) (this->children()[i]))->y(), ((QWidget *) this->children()[i])->width(), ((QWidget *) this->children()[i])->height()));
            childrenAnimation[i]->setEndValue(QRect(childrenOriginalX[i]-int(5), childrenOriginalY[i]-int(5), childrenOriginalWidth[i]+int(10), childrenOriginalHeight[i]+int(10)));
            childrenAnimation[i]->start();
        }
    }
}
