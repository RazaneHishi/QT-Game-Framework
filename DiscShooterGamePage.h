#ifndef DISCSHOOTERGAMEPAGE_H
#define DISCSHOOTERGAMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QQueue>
#include <QFont>
#include "Disc.h"

/**
* \file DiscShooterGamePage.h
* \brief The main game page for Disc Shooter
* declares the three different scores along with queues for every disc color. Ends game when lives are lost.
*/
class DiscShooterGamePage : public QGraphicsScene
{
    Q_OBJECT
public:

    static int redScore;
    static int greenScore;
    static int blueScore;

    static QGraphicsSimpleTextItem* livesLeftText;

    static QQueue<Disc*>* redDiscQueue;
    static QQueue<Disc*>* greenDiscQueue;
    static QQueue<Disc*>* blueDiscQueue;


    int scoreToNextSpeedIncrease=30;

    DiscShooterGamePage();

    void EndGame();

private:
    QTimer* timer;
    QTimer* shootTimer;
    QGraphicsPixmapItem* bg;

    QGraphicsPixmapItem* redCannon = new QGraphicsPixmapItem();
    QGraphicsPixmapItem* greenCannon= new QGraphicsPixmapItem();
    QGraphicsPixmapItem* blueCannon= new QGraphicsPixmapItem();

    QGraphicsPixmapItem* shootImage = new QGraphicsPixmapItem();

    QGraphicsSimpleTextItem* redScoreText = new QGraphicsSimpleTextItem();
    QGraphicsSimpleTextItem* greenScoreText = new QGraphicsSimpleTextItem();
    QGraphicsSimpleTextItem* blueScoreText = new QGraphicsSimpleTextItem();


    void keyPressEvent(QKeyEvent *event);
    void Shoot(char color);
    void SetGameStartParameters();
    void AddCannonsToScene();
    void AddScores();


private slots:
    void SpawnDiscs();
    void UpdateScoreAndSpeed(char shotDiscType);

};

#endif // DISCSHOOTERGAMEPAGE_H
