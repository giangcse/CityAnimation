#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QPointF>
#include <QString>

class graphics : public QWidget
{
    Q_OBJECT
public:
    explicit graphics(QWidget *parent = 0);

    void timerEvent(QTimerEvent *);
    double positionC, position;
    double timerId;

    void paintEvent(QPaintEvent *);
    double h=height();
    double w=width();
    double positionW, positionBW;
    double positionH, positionBH;

    QPointF pstart, pcenter, pnew;
    int size;
    float sizel;
//    QPointF tinhtien(QPointF c, float x, float y);
    void drawBackground(QPainter& painter);
    void drawGround(QPainter& painter, float x, float y);
    void drawFrontBuilding(QPainter& painter, float x, float y, float sizel);
    void drawBackBuilding(QPainter& painter, float x, float y);
    void drawCloudLeft(QPainter& painter, float x, float y, double position);
    void drawCloudRight(QPainter& painter, float x, float y, double position);
    void drawTree(QPainter& painter, float x, float y, double size);
    void loadLogo(QPainter& painter, float x, float y, double sizel);

};

#endif // GRAPHICS_H
