#ifndef MAINMENUGAME2_H
#define MAINMENUGAME2_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>
#include "AccountsUIhandler.h"

/**
* \file MainMenuGame2.h
* \brief The main menu for Disc Shooter
* declares a how to play button, a play button, and back button.
*/
class MainMenuGame2 : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenuGame2(QWidget *parent = nullptr);

private:
    QLabel* gameTitleLabel = new QLabel("SPACE SHOOTER");

    QPushButton* backButton = new QPushButton("Back");
    QPushButton* howToPlayButton = new QPushButton("How To Play");
    QPushButton* playButton = new QPushButton("Play (F1)");

    void SetGridWidgets();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void BackToAccountInfoPage();
    void HowToPlayGame2Page();
    void GoToGame2();



signals:

};

#endif // MAINMENUGAME2_H
