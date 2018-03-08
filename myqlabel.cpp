
#include "myqlabel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MyQLabel::MyQLabel(QWidget *parent)
    : QLabel(parent)
    , m_offs()
{

}

MyQLabel::~MyQLabel()
{

}

void MyQLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_offs = event->pos();

        QString s(QString("%1:pos:x:%2:y:%3")
                  .arg(__FUNCTION__)
                  .arg(event->x())
                  .arg(event->y())
                  );

        this->setText(s);

        this->setForegroundRole(QPalette::Highlight);
    }
}

void MyQLabel::mouseReleaseEvent(QMouseEvent *event)
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
            this->move(p - m_offs);
        }

        this->setForegroundRole(QPalette::Foreground);
    }
}
