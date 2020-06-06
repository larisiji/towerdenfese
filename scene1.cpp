#include "scene1.h"
#include<QMenu>
#include<QMenuBar>
#include<QPainter>
#include"mypushbutton.h"
#include "waypoint.h"
QList<WayPoint *> m_wayPointsList;
#include <QColor>
#include<QEvent>
#include<QMouseEvent>
scene1::scene1(QWidget *parent) : QMainWindow(parent)
{

    //配置选择关卡场景
        this->setFixedSize(1080,810);
        this->setWindowIcon(QIcon(":/back/icon.jpg"));
        this->setWindowTitle("Play with Doraemon");
        //创建菜单栏
        QMenuBar *bar=menuBar();
        setMenuBar(bar);
        //创建开始菜单
        QMenu * startMenu=bar->addMenu("start");
        QAction * quitAction=startMenu->addAction("quit");
        //点击实现退出
        connect(quitAction,&QAction::triggered,[=](){
            this->close();
        });
     addWayPoints();
loadTowerPositions();
}
void scene1:: paintEvent(QPaintEvent*)
{

    QPixmap cachePix(":/back/background.jpg");
    QPainter cachePainter(&cachePix);
    foreach (const WayPoint *wayPoint, m_wayPointsList)
        wayPoint->draw(&cachePainter);
    foreach (const Tower *tower, m_towersList)
        tower->draw(&cachePainter);
    QPainter painter(this);
    painter.drawPixmap(0, 0, cachePix);

}
void scene1::addWayPoints()
{
    WayPoint *wayPoint1 = new WayPoint(QPoint(480, 230));
    m_wayPointsList.push_back(wayPoint1);

    WayPoint *wayPoint2 = new WayPoint(QPoint(35, 230));
    m_wayPointsList.push_back(wayPoint2);
    wayPoint2->setNextWayPoint(wayPoint1);

    WayPoint *wayPoint3 = new WayPoint(QPoint(35, 550));
    m_wayPointsList.push_back(wayPoint3);
    wayPoint3->setNextWayPoint(wayPoint2);

    WayPoint *wayPoint4 = new WayPoint(QPoint(445, 550));
    m_wayPointsList.push_back(wayPoint4);
    wayPoint4->setNextWayPoint(wayPoint3);

    WayPoint *wayPoint5 = new WayPoint(QPoint(445, 440));
    m_wayPointsList.push_back(wayPoint5);
    wayPoint5->setNextWayPoint(wayPoint4);

    WayPoint *wayPoint6 = new WayPoint(QPoint(830, 440));
    m_wayPointsList.push_back(wayPoint6);
    wayPoint6->setNextWayPoint(wayPoint5);
    WayPoint *wayPoint7 = new WayPoint(QPoint(830,550));
    m_wayPointsList.push_back(wayPoint7);
    wayPoint7->setNextWayPoint(wayPoint6);
    WayPoint *wayPoint8 = new WayPoint(QPoint(880,550));
    m_wayPointsList.push_back(wayPoint8);
    wayPoint8->setNextWayPoint(wayPoint7);
}

void scene1::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    auto it = m_towerPositionsList.begin();
    while (it != m_towerPositionsList.end())
    {
        if (canBuyTower() && it->containPoint(pressPos) && !it->hasTower())
        {
            it->setHasTower();
            Tower *tower = new Tower(it->centerPos());
            m_towersList.push_back(tower);
            update();
            break;
        }

        ++it;
    }
}
void scene1::loadTowerPositions()
{
    QPoint pos[] =
    {
        QPoint(380, 90),
        QPoint(220,90),
       QPoint(60, 90),
       QPoint(380, 300),

       QPoint(280,300),
      QPoint(100,300),
      //  QPoint(280, 125),
       // QPoint(370, 125),
//
      //  QPoint(80, 35),
      //  QPoint(170, 35),
      //  QPoint(260, 35),
     //   QPoint(350, 35)
    };
    int len	= sizeof(pos) / sizeof(pos[0]);

    for (int i = 0; i < len; ++i)
        m_towerPositionsList.push_back(pos[i]);

}
bool scene1::canBuyTower()
{
    return true;
}

