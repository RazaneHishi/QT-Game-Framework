#ifndef BATTLESHIPRESULTS_H
#define BATTLESHIPRESULTS_H
#include "BattleshipGamePage.h"

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>

/**
* \file BattleShipResults.h
* \brief Displays Battleships results
* displays the result and number of right and wrong anwsers
*/
class BattleShipResults : public QWidget
{
    Q_OBJECT
public:
    explicit BattleShipResults(QWidget *parent = nullptr);
private:
    QLabel* gameResultLabel;
    QLabel* scoreLabel;
    QPushButton* backButton = new QPushButton("Back to main menu");
signals:

private slots:
    void backToMainMenu();
};

#endif // BATTLESHIPRESULTS_H
