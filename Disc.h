#ifndef DISC_H
#define DISC_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

/**
* \file Disc.h
* \brief Manages the discs during gameplay
* initializes disc colors and a timer for disc spawning. Also has a turn grey function when a disc is hit and ends the game after 3 lives are lost.
*/
class Disc : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Disc(QObject *parent = nullptr , char color='r');

    QTimer* timer;

    static float moveSpeed;
    static int livesLeft;
    char color='x'; //"x" , "r" , "g" , "b" for grey/hit, red,green,blue respectively

    void TurnGrey();

private:
    void EndGame();

private slots:
    void LowerPosition();

signals:

};

#endif // DISC_H
