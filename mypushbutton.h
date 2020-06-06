#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include<QString>
#include <QPushButton>
#include<Qpoint>
class mypushbutton : public QPushButton
{
    Q_OBJECT
public:
   // explicit mypushbutton(QWidget *parent = nullptr);
mypushbutton(QString normalImg,QString pressImg="");
//成员属性 保存用户传入图片
QString normalImgPath;
QString pressImgPath;
signals:

};

#endif // MYPUSHBUTTON_H
