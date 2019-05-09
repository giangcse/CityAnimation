#include "graphics.h"
#include <QPainter>
#include <math.h>
#include <QString>
#include <QPointF>
#include <QRectF>

graphics::graphics(QWidget *parent):
    QWidget(parent)
{
    positionW=800;
    positionH=800;
    positionBH=1600;
    position=0;
    timerId=startTimer(100);
    size=0;
    sizel=0;
}

void graphics::timerEvent(QTimerEvent *){
    if (position < width())
        position+=5;
    else
        position=0;
    //------------------
    if (positionH > height()){
        positionH-=50;
    }
    else{
        positionH=height();
        if(positionBH > height())
            positionBH-=100;
        else
            positionBH=height();

        if(sizel < 40)
            sizel+=5;
        else
            sizel=40;
    }
//    --------------------

    repaint();
}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    drawBackground(painter);
    drawBackBuilding(painter, width(), positionBH);
    drawCloudLeft(painter, width(), height(), position);
    drawCloudRight(painter, width(), height(), -position+width());
    drawFrontBuilding(painter, width(), positionH, sizel);
    drawTree(painter, width(), height(), positionH);
    drawGround(painter, width(), height());
}

void graphics::drawBackground(QPainter &painter){
    float w=width(), h=height();
    painter.setPen(Qt::NoPen);
    //Ve nen
    painter.setBrush(QColor("#FFF98A"));
    painter.drawRect(0, 0, w, h);
}

void graphics::drawGround(QPainter &painter, float x, float y){
    //Ve nen dat
    painter.setBrush(QColor("#FFF98A"));
    QRectF below(0, y/2+y/3, x, y);
    painter.drawRect(below);
    QRectF nen(x/2 - x/3, y/2 + y/3, x/1.5, y/30);
    painter.setBrush(QColor("#066060"));
    painter.drawRoundedRect(nen, 10,10);
}

void graphics::drawFrontBuilding(QPainter &painter, float x, float y, float sizel){
    float n=x/2, m=y/2;
    //Ve hinh ngoi nha
    QPointF building[5]={
        QPointF(n+n/3, y/2+y/3),
        QPointF(n-n/3, y/2+y/3),
        QPointF(n-n/3, m-m/3),
        QPointF(n+n/4, m-m/3),
        QPointF(n+n/3, m-m/4)
    };
    painter.setBrush(QColor("#BDC1C1"));
    painter.drawPolygon(building, 5);
    //Ve mat sang
    QPointF frontBuilding[4]={
        QPointF(n+n/4, y/2+y/3),
        QPointF(n-n/3, y/2+y/3),
        QPointF(n-n/3, m-m/3),
        QPointF(n+n/4, m-m/3)
    };
    painter.setBrush(QColor("#E0E0E0"));
    painter.drawPolygon(frontBuilding, 4);
    //Ve vien sang
    QPointF buildingBolder1[4]={
        QPointF(n+n/4, y/2-y/8),
        QPointF(n-n/3, y/2-y/8),
        QPointF(n-n/3, m-m/3),
        QPointF(n+n/4, m-m/3),
    };
    painter.setBrush(QColor("#1F9191"));
    painter.drawPolygon(buildingBolder1, 4);
    //Ve vien toi
    QPointF buildingBolder2[4]={
        QPointF(n+n/4, m-m/3),
        QPointF(n+n/3, m-m/4),
        QPointF(n+n/3, m-y/11),
        QPointF(n+n/4, y/2-y/8)
    };
    painter.setBrush(QColor("#0D7C74"));
    painter.drawPolygon(buildingBolder2, 4);
    //Ve cua so 1
    painter.setBrush(QColor("#13E8E8"));
    QRectF window1(n-n/4, y/2-y/16, n/8, m/6);
    painter.drawRect(window1);
    //Ve cua so 2
    QRectF window2(n+n/24, y/2-y/16, n/8, m/6);
    painter.drawRect(window2);
    //Ve cua so 3
    QRectF window3(n-n/4, y/2+y/16, n/8, m/6);
    painter.drawRect(window3);
    //Ve cua so 4
    QRectF window4(n+n/24, y/2+y/16, n/8, m/6);
    painter.drawRect(window4);
    //Ve cua chinh
    painter.setBrush(QColor("#129B97"));
    QRectF door(n-n/6, y/2+y/6, n/4, y/6);
    painter.drawRect(door);
    //Ve logo
    loadLogo(painter, 23*n/24 - sizel/2, y/2.3, sizel);
}

void graphics::drawBackBuilding(QPainter &painter, float x, float y){
    float n=x/2, m=y/2;
    //Nha trai
    //Ve mat sang
    QPointF buildingLeft[5]={
        QPointF(n-n/20, y/2+y/3),
        QPointF(n-n/2, y/2+y/3),
        QPointF(n-n/2, m-m/2),
        QPointF(n-n/10, m-m/2),
        QPointF(n-n/20, m-m/2.5)
    };
    painter.setBrush(QColor("#F9EF75"));
    painter.drawPolygon(buildingLeft, 5);
    //Ve mat toi
    QPointF backBuildingLeft[4]={
        QPointF(n-n/20, y/2+y/3),
        QPointF(n-n/10, y/2+y/3),
        QPointF(n-n/10, m-m/2),
        QPointF(n-n/20, m-m/2.5)
    };
    painter.setBrush(QColor("#EFDE65"));
    painter.drawPolygon(backBuildingLeft, 4);
    //Nha giua
    //Ve mat sang
    QPointF buildingCenter[5]={
        QPointF(n+n/4, y/2+y/3),
        QPointF(n-n/20, y/2+y/3),
        QPointF(n-n/20, m-m/1.5),
        QPointF(n+n/5, m-m/1.5),
        QPointF(n+n/4, m-m/2)
    };
    painter.setBrush(QColor("#EFDE65"));
    painter.drawPolygon(buildingCenter, 5);
    //Ve mat toi
    QPointF backBuildingCenter[4]={
        QPointF(n+n/5, y/2+y/3),
        QPointF(n-n/20, y/2+y/3),
        QPointF(n-n/20, m-m/1.5),
        QPointF(n+n/5, m-m/1.5)
    };
    painter.setBrush(QColor("#F9EF75"));
    painter.drawPolygon(backBuildingCenter, 4);
    //Nha phai
    //Ve mat sang
    QPointF buildingRight[5]={
        QPointF(n+n/2, y/2+y/3),
        QPointF(n+n/4, y/2+y/3),
        QPointF(n+n/4, m-m/5),
        QPointF(n+n/2.2, m-m/5),
        QPointF(n+n/2, m-m/7)
    };
    painter.setBrush(QColor("#EFDE65"));
    painter.drawPolygon(buildingRight, 5);
    //Ve mat toi
    QPointF backBuildingRight[4]={
        QPointF(n+n/4, y/2+y/3),
        QPointF(n+n/2.2, y/2+y/3),
        QPointF(n+n/2.2, m-m/5),
        QPointF(n+n/4, m-m/5)
    };
    painter.setBrush(QColor("#F9EF75"));
    painter.drawPolygon(backBuildingRight, 4);
}

void graphics::drawCloudLeft(QPainter &painter, float x, float y, double position){
    float i=x/2, j=y/2;
    painter.setBrush(QColor("#ffffff"));
    QRectF c1(position+i/6, j-j/1.8, i/4, j/15);
    painter.drawRoundedRect(c1, i/60, i/60);
    QRectF c2(position-i/8, j-j/2, i/2, j/10);
    painter.drawRoundedRect(c2, i/30, i/30);
    QRectF c3(position-i/6, j-j/2.4, i/4, j/15);
    painter.drawRoundedRect(c3, i/60, i/60);
}

void graphics::drawCloudRight(QPainter &painter, float x, float y, double position){
    float i=x/2, j=y/2;
    painter.setBrush(QColor("#ffffff"));
    QRectF c1(position+i/6, j-j/1.45, i/4, j/15);
    painter.drawRoundedRect(c1, i/60, i/60);
    QRectF c2(position-i/8, j-j/1.3, i/2, j/10);
    painter.drawRoundedRect(c2, i/30, i/30);
    QRectF c3(position-i/6, j-j/1.2, i/4, j/15);
    painter.drawRoundedRect(c3, i/60, i/60);
}

void graphics::drawTree(QPainter &painter, float x, float y, double size){
    QString tree="F:/Study/CT203 - Computer Graphic/Animation/Images/Tree.png";
    painter.drawPixmap(x/2-x/4, y/2+y/7, x/15, 2*(size/10), QPixmap(tree));
    painter.drawPixmap(x/2-x/3, y/2+y/7, x/15, 2*(size/10), QPixmap(tree));
    painter.drawPixmap(x/2+x/4, y/2+y/7, x/15, 2*(size/10), QPixmap(tree));
    painter.drawPixmap(x/2+x/6, y/2+y/7, x/15, 2*(size/10), QPixmap(tree));
}

void graphics::loadLogo(QPainter &painter, float x, float y, double sizel){
    QString logo="F:/Study/CT203 - Computer Graphic/Animation/Images/logo.png";
    painter.drawPixmap(x, y, sizel, sizel, QPixmap(logo));
}
