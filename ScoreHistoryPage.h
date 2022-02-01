#ifndef SOREHISTORYPAGE_H
#define SOREHISTORYPAGE_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>
#include "AccountsUIhandler.h"

/**
* \file ScoreHistoryPage.h
* \brief The score history of a user
* declares the history of wins and losses for each game.
*/
class ScoreHistoryPage : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreHistoryPage(QWidget *parent = nullptr);

signals:
private:
    QLabel *scoreHistoryLabel;
    QPushButton* backButton = new QPushButton("Back");
    QLabel* wins1Label;
    QLabel* losses1Label;
    QLabel* wins2Label;
    QLabel* losses2Label;
    QLabel* bonusPoints2Label;


private slots:
    void GoBackToAccountInfoPage();

};

#endif // SOREHISTORYPAGE_H
