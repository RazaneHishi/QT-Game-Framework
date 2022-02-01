#include "DiscShooterGamePage.h"

int DiscShooterGamePage::redScore=0;
int DiscShooterGamePage::greenScore=0;
int DiscShooterGamePage::blueScore=0;

QGraphicsSimpleTextItem* DiscShooterGamePage::livesLeftText = new QGraphicsSimpleTextItem();
QQueue<Disc*>* DiscShooterGamePage::redDiscQueue = new QQueue<Disc*>();
QQueue<Disc*>* DiscShooterGamePage::greenDiscQueue = new QQueue<Disc*>();
QQueue<Disc*>* DiscShooterGamePage::blueDiscQueue = new QQueue<Disc*>();

/**
* \file DiscShooterGamePage.cpp
* \brief The main game page for Disc Shooter
* manages the gameplay for Disc Shooter and sets the initial game elements in the scene.
* Has separate functions to add cannons to scene, set the disc queues, update the scores and disc movement, and shoot discs.
* \author Yvan and Razane
*/
DiscShooterGamePage::DiscShooterGamePage()
{
    bg = new QGraphicsPixmapItem();
    bg->setPixmap(QPixmap(":/spaceBg.jpg").scaledToWidth(600).scaledToHeight(500));
    addItem(bg);

    AddCannonsToScene();
    SetGameStartParameters();
    AddScores();

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(SpawnDiscs()));
    timer->start(1500);
}

/**
* \brief Adds the cannon icons to the Disc Shooter game page
*\return void
*/
void DiscShooterGamePage::AddCannonsToScene(){

    redCannon->setPixmap(QPixmap(":/redC-PhotoRoom.png").scaledToWidth(100).scaledToHeight(100));
    redCannon->setPos(100,400);
    redCannon->setZValue(1);

    greenCannon->setPixmap(QPixmap(":/greenC-PhotoRoom.png").scaled(100,100));
    greenCannon->setPos(300,400);
    greenCannon->setZValue(1);

    blueCannon->setPixmap(QPixmap(":/blueC-PhotoRoom.png").scaled(100,100));
    blueCannon->setPos(500,400);
    blueCannon->setZValue(1);

    addItem(redCannon);
    addItem(greenCannon);
    addItem(blueCannon);
}

/**
* \brief Initializes the disc queues, the move speed, scores, and lives left.
*\return void
*/
void DiscShooterGamePage::SetGameStartParameters(){
    while (!redDiscQueue->isEmpty()){
        Disc* disc = redDiscQueue->dequeue();
        disc->timer->stop();
        delete disc;
    }
    while (!greenDiscQueue->isEmpty()){
        Disc* disc = greenDiscQueue->dequeue();
        disc->timer->stop();
        delete disc;
    }
    while (!blueDiscQueue->isEmpty()){
        Disc* disc = blueDiscQueue->dequeue();
        disc->timer->stop();
        delete disc;
    }
    Disc::moveSpeed=5;
    Disc::livesLeft=3;
    redScore=0;
    blueScore=0;
    greenScore=0;
}

/**
* \brief Adds initial scores to screen.
*\return void
*/
void DiscShooterGamePage::AddScores(){

    QFont arielFont("Ariel",30);
    arielFont.setBold(true);

    redScoreText->setPos(100,5);
    redScoreText->setText(QString::number(redScore));
    redScoreText->setFont(arielFont);
    redScoreText->setPen(QPen(QColor(Qt::white)));

    greenScoreText->setPos(300,5);
    greenScoreText->setText(QString::number(greenScore));
    greenScoreText->setFont(arielFont);
    greenScoreText->setPen(QPen(QColor(Qt::white)));

    blueScoreText->setPos(500,5);
    blueScoreText->setText(QString::number(blueScore));
    blueScoreText->setFont(arielFont);
    blueScoreText->setPen(QPen(QColor(Qt::white)));

    livesLeftText->setPos(250,100);
    livesLeftText->setText("lives: "+QString::number(Disc::livesLeft));
    livesLeftText->setFont(arielFont);
    livesLeftText->setPen(QPen(QColor(Qt::white)));

    addItem(redScoreText);
    addItem(greenScoreText);
    addItem(blueScoreText);
    addItem(livesLeftText);

}

/**
* \brief Spawns a colored disc if it hits a probability higher than 30% and enqueues it from its corresponding disc queue.
*\return void
*/
void DiscShooterGamePage::SpawnDiscs(){

    //random floats between 0 and 1
    srand(time(0));
    float redChance = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    float greenChance=static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    float blueChance=static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

    if (redChance <=0.3){
        Disc* redDisc = new Disc(nullptr,'r');
        redDiscQueue->enqueue(redDisc);
        addItem(redDisc);
    }
    if (greenChance <=0.3){
        Disc* greenDisc = new Disc(nullptr,'g');
        greenDiscQueue->enqueue(greenDisc);
        addItem(greenDisc);
    }
    if (blueChance <=0.3){
        Disc* blueDisc = new Disc(nullptr,'b');
        blueDiscQueue->enqueue(blueDisc);
        addItem(blueDisc);

    }
}

/**
* \brief Updates the scores on the screen based on the hit color, along with increasing the speed of the discs.
* \shotDiscType indicates the hit disc color.
*\return void
*/
void DiscShooterGamePage::UpdateScoreAndSpeed(char shotDiscType){
    if (shotDiscType=='r')
        redScore+=3;
    else if(shotDiscType=='g')
        greenScore+=5;
    else if (shotDiscType=='b')
        blueScore+=7;

    greenScoreText->setText(QString::number(greenScore));
    blueScoreText->setText(QString::number(blueScore));
    redScoreText->setText(QString::number(redScore));

    if (redScore+greenScore+blueScore >= scoreToNextSpeedIncrease && scoreToNextSpeedIncrease<150){
        scoreToNextSpeedIncrease+=30;
        Disc::moveSpeed*=2;
    }

}

/**
* \brief Checks if there are any queued disc to shoot based on the key pressed and its corresponding allocated color.
*\event is the key pressing trigger, either left bottom or right arroow keys.
*\return void
*/
void DiscShooterGamePage::keyPressEvent(QKeyEvent *event){


    if (event->key()==Qt::Key_Left && !redDiscQueue->isEmpty())
        Shoot('r');
    if (event->key()==Qt::Key_Down && !greenDiscQueue->isEmpty())
        Shoot('g');
    if (event->key()==Qt::Key_Right && !blueDiscQueue->isEmpty())
        Shoot('b');

}

/**
* \brief Dequeus a disc if it's shot.
*\color is the color of the shot disc.
*\return void
*/
void DiscShooterGamePage::Shoot(char color){

    Disc* shotDisc = nullptr;

    if(color=='r')
        shotDisc = redDiscQueue->dequeue();
    else if(color=='g')
        shotDisc = greenDiscQueue->dequeue();
    else if(color=='b')
        shotDisc = blueDiscQueue->dequeue();



    shotDisc->TurnGrey();
    UpdateScoreAndSpeed(color);

}

/**
* \brief Stops the spawning timer and discs to end the game
*\return void
*/
void DiscShooterGamePage::EndGame(){
    timer->stop();
    Disc::moveSpeed=0;

}






