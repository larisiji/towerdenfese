#ifndef SCENE1_H
#define SCENE1_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QList>
#include"tower.h"
#include"towerposition.h"
class WayPoint;
class scene1:public QMainWindow
{
     Q_OBJECT;
public:
    explicit scene1(QWidget *parent = nullptr);
void paintEvent(QPaintEvent*);
void addWayPoints();

void mousePressEvent(QMouseEvent *);
bool canBuyTower();
void loadTowerPositions();
private:
QList<WayPoint *>		m_wayPointsList;
QList<Tower *>			m_towersList;
QList<TowerPosition>	m_towerPositionsList;
};

#endif // SCENE1_H
