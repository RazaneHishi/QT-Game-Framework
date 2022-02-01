#ifndef MAINMENUGAME1_H
#define MAINMENUGAME1_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>

#include "AccountsUIhandler.h"
#include "GridCell.h"

/**
* \file MainMenuGame1.h
* \brief The main menu for Battleships
* declares a how to play button, a play button, a back button, and topic selection.
*/
class MainMenuGame1 : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenuGame1(QWidget *parent = nullptr);
private:
    QLabel* gameTitleLabel = new QLabel("BATTLESHIPS QUIZ");

    QPushButton* backButton = new QPushButton("Back");
    QPushButton* howToPlayButton = new QPushButton("How To Play");
    QPushButton* playButton = new QPushButton("Play (F1)");

    QLabel* chooseTopicLabel = new QLabel("choose topic:");
    QRadioButton* topic1RadioButton = new QRadioButton("Good Software Practices");
    QRadioButton* topic2RadioButton = new QRadioButton("food trivia!");


    void SetGridWidgets();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void BackToAccountInfoPage();
    void HowToPlayGame1Page();
    void GoToGame1();


signals:

};

#endif // MAINMENUGAME1_H
