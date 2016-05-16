#ifndef MAGRAPHICSSCENE_H
#define MAGRAPHICSSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QList>
#include <QPaintEvent>

class MaGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MaGraphicsScene(QObject *parent = 0);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);

protected:
    void paintEvent(QPaintEvent* event);

signals:
    void SignalMouseMagraphicsScene(bool);

public slots:

private:
    //QList <QPointF> m_points;
};

#endif // MAGRAPHICSSCENE_H
