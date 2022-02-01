#ifndef DISCSHOOTERRESULTS_H
#define DISCSHOOTERRESULTS_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>
#include "DiscShooterGamePage.h"

/**
* \file DiscShooterResults.h
* \brief Displays Disc Shooter results
* declares win and lose labels along with a back button that returns you to the main game menu.
*/
class DiscShooterResults : public QWidget
{
    Q_OBJECT
public:
    explicit DiscShooterResults(QWidget *parent = nullptr);
    QLabel* winLabel = new QLabel("YOU WIN!");
    QLabel* loseLabel = new QLabel("YOU LOSE!");
    QLabel* scoreLabel;
    QLabel* bonusLabel;
    QPushButton* backButton= new QPushButton("back");


signals:

private slots:
    void backToMainMenu();

};

#endif // DISCSHOOTERRESULTS_H
