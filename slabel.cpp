
#include "slabel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

SLabel::SLabel(QWidget *parent)
    : QLabel(parent)
{

}

SLabel::~SLabel()
{

}

void SLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QString s(QString("%1:pos:x:%2:y:%3")
                  .arg(__FUNCTION__)
                  .arg(event->x())
                  .arg(event->y())
                  );

        this->setText(s);

        this->setForegroundRole(QPalette::Highlight);
    }
}

void SLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QString s(QString("%1:pos:x:%2:y:%3")
                  .arg(__FUNCTION__)
                  .arg(event->x())
                  .arg(event->y())
                  );

        this->setText(s);

        QPoint p = this->parentWidget()->mapFromGlobal(QCursor::pos());

        if (this->parentWidget()->rect().contains(p))
        {
            this->move(p);
        }

        this->setForegroundRole(QPalette::Foreground);
    }
}
