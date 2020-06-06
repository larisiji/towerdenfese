#include "mypushbutton.h"

mypushbutton::mypushbutton(QString normalImg,QString pressImg){
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;
    QPixmap pic;
    pic.load(normalImg);
    //设置固定大小
    this->setFixedSize(pic.width()*0.3,pic.height()*0.3);
    //设置不规则图片形式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pic);
   this->setIconSize(QSize(pic.width()*0.3,pic.height()*0.3));
}
