#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QMainWindow>

class choosescene : public QMainWindow
{
    Q_OBJECT
public:
    explicit choosescene(QWidget *parent = nullptr);
void paintEvent(QPaintEvent*);
signals:

};

#endif // CHOOSESCENE_H
