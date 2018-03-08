#ifndef SLABEL_H
#define SLABEL_H

#include <QLabel>
#include <QMouseEvent>

class MyQLabel : public QLabel
{
    Q_OBJECT

public:
    explicit MyQLabel(QWidget *parent = 0);
    ~MyQLabel();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPoint m_offs;
};

#endif // SLABEL_H

