

#include "tower.h"
#include "enemy.h"

#include "mainwindow.h"

#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QVector2D>
#include <QtMath>

const QSize Tower::ms_fixedSize(42, 42);

Tower::Tower(QPoint pos, const QPixmap &sprite)
    :
     m_pos(pos)
    , m_sprite(sprite)
{

}

Tower::~Tower()
{

}



void Tower::draw(QPainter *painter) const
{
    painter->save();
    painter->setPen(Qt::blue);
    // 绘制攻击范围
    painter->drawEllipse(m_pos,150,150);

    // 绘制偏转坐标,由中心+偏移=左上
    static const QPoint offsetPoint(-ms_fixedSize.width() / 2, -ms_fixedSize.height() / 2);
    // 绘制炮塔并选择炮塔
    painter->translate(m_pos);

    painter->drawPixmap(offsetPoint, m_sprite);
    painter->restore();
}

