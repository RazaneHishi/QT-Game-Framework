#ifndef HOWTOPLAYPAGEGAME2_H
#define HOWTOPLAYPAGEGAME2_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>
#include "AccountsUIhandler.h"

/**
* \file HowToPlayPageGame1.h
* \brief The instructions page for Disc Shooter
* states the 'how to play' of Disc Shooter and declares a back button.
*/
class HowToPlayPageGame2 : public QWidget
{
    Q_OBJECT
public:
    explicit HowToPlayPageGame2(QWidget *parent = nullptr);

private:
    QLabel* instruction1Label;
    QLabel* instruction2Label;
    QLabel* instruction3Label;
    QLabel* instruction4Label;
    QLabel* instruction5Label;
    QPushButton* backButton= new QPushButton("back");
private slots:
    void BackToMainMenuGame2Button();



signals:

};

#endif // HOWTOPLAYPAGEGAME2_H
