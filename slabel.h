#ifndef SLABEL_H
#define SLABEL_H

#include <QLabel>
#include <QMouseEvent>

class SLabel : public QLabel
{
    Q_OBJECT

public:
    explicit SLabel(QWidget *parent = 0);
    ~SLabel();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // SLABEL_H

