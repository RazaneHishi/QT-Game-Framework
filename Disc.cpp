#include "Disc.h"
#include "AccountsUIhandler.h"
#include "DiscShooterGamePage.h"

float Disc::moveSpeed=5;
int Disc::livesLeft=3;

/**
* \file Disc.cpp
* \brief Manages the discs during gameplay
* spawns, recolors, and despawns discs.
* Has separate functions to lower the position of a disc, turn it grey, and end the game.
* \author Yvan and Razane
*/
Disc::Disc(QObject *parent , char color) : QObject(parent)
{
    this->color=color;
    if (color=='r') {setPixmap(QPixmap(":/redR.png").scaled(120,120));setPos(100,-50);}//left
    else if (color=='g') {setPixmap(QPixmap(":/greenR.png").scaled(100,100));setPos(300,-25);}//mid
    else if (color=='b') {setPixmap(QPixmap(":/blueR.png").scaled(80,80));setPos(500,5);setRotation(39);}//right

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(LowerPosition()));
    timer->start(100);



}

/**
* \brief Lowers the position of a disc game object by a certain move speed which increases with respect to the score.
* Based on the lives left it may end the game. The disc is deleted if it goes out of the screen bounds.
*\return void
*/
void Disc::LowerPosition(){
    setPos(x(),y()+moveSpeed);

    if (y()>=425){
        if (color!='x'){
            if (--livesLeft<=0) EndGame();
            DiscShooterGamePage::livesLeftText->setText("lives: "+QString::number(livesLeft));
            if (color=='r') DiscShooterGamePage::redDiscQueue->dequeue();
            else if (color=='g') DiscShooterGamePage::greenDiscQueue->dequeue();
            else if (color=='b') DiscShooterGamePage::blueDiscQueue->dequeue();
        }
        delete this;
    }

}

/**
* \brief Ends the game by displaying the Disc Shooter results page
*\return void
*/
void Disc::EndGame(){
    AccountsUIhandler::GoToPage(12);
}

/**
* \brief Changes the color of a hit disc to grey
*\return void
*/
void Disc::TurnGrey(){
    if(color=='b')
        setRotation(0);
    this->color='x';
    setPixmap(QPixmap(":/blackR.png").scaled(100,100));
}
