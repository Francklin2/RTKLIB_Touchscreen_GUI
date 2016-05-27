#include "magraphicsscene.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include "qmath.h"
#include <stdlib.h>
#include <iostream>
#include<QPalette>
#include <QPainter>
using namespace std;


//------------------------http://stackoverflow.com/questions/26901540/arc-in-qgraphicsscene/26903599#26903599
/* lorsque erreur "vtable... "
http://30minparjour.la-bnbox.fr/blog/2012/02/06/qt-undefined-reference-to-vtable-for
il faut "clean all"...
*/

MaGraphicsScene::MaGraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
    //this->setBackgroundBrush(Qt::gray);

}

void MaGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    qDebug() << Q_FUNC_INFO << mouseEvent->scenePos();
    QGraphicsScene::mousePressEvent(mouseEvent);
    emit SignalMouseMagraphicsScene(true);


    cout<<"le clique sur graphicsScene fonctionne"<<endl;
}

void MaGraphicsScene::paintEvent(QPaintEvent*)
{
    QColor backgroundColor=palette().light().color();
    backgroundColor.setAlpha(200);
    /*QPainter customPainter(this);
    customPainter.fillRect(rect(),backgroundColor);*/
}


/*

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * me)
{
    qDebug() << Q_FUNC_INFO << me->scenePos();
    int radius = 20;
    QGraphicsEllipseItem * ellipse = this->addEllipse(me->scenePos().x() - radius, me->scenePos().y() - radius, radius*2, radius*2);

    ellipse->setBrush(Qt::white);
    m_points.append(me->scenePos());
    if(m_points.size() == 3)
    {
        // use math to define the circle
        QLineF lineBC(m_points.at(1), m_points.at(2));
        QLineF lineAC(m_points.at(0), m_points.at(2));
        QLineF lineBA(m_points.at(1), m_points.at(0));
        qreal rad = qAbs(lineBC.length()/(2*qSin(qDegreesToRadians(lineAC.angleTo(lineBA)))));

        QLineF bisectorBC(lineBC.pointAt(0.5), lineBC.p2());
        bisectorBC.setAngle(lineBC.normalVector().angle());

        QLineF bisectorBA(lineBA.pointAt(0.5), lineBA.p2());
        bisectorBA.setAngle(lineBA.normalVector().angle());

        QPointF center;
        bisectorBA.intersect(bisectorBC, &center);

        qDebug() << rad << center;

        bool drawCircle = true;

        QGraphicsEllipseItem * ellipse = new QGraphicsEllipseItem(center.x() - rad, center.y() - rad, rad*2, rad*2);
        if(drawCircle)
            this->addItem(ellipse);

        // add arc
        // this->addItem(path);
        QPainterPath path;
        QLineF lineOA(center, m_points.at(0));
        QLineF lineOC(center, m_points.at(2));
        path.arcMoveTo(ellipse->boundingRect(),lineOA.angle());
        path.arcTo(ellipse->boundingRect(), lineOA.angle(), lineOC.angle() - lineOA.angle());
        QGraphicsPathItem * pathItem = new QGraphicsPathItem(path);
        pathItem->setPen(QPen(Qt::red,10));
        this->addItem(pathItem);

        if(!drawCircle)
            delete ellipse;
        m_points.clear();
    }

    QGraphicsScene::mouseReleaseEvent(me);
*/

