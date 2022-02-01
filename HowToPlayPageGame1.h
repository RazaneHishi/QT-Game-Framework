#ifndef HOWTOPLAYPAGEGAME1_H
#define HOWTOPLAYPAGEGAME1_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>

/**
* \file HowToPlayPageGame1.h
* \brief The instructions page for Battleships
* states the 'how to play' of Battleships and declares a back button.
*/
class HowToPlayPageGame1 : public QWidget
{
    Q_OBJECT

private:
    QLabel* instruction1Label;
    QLabel* instruction2Label;
    QLabel* instruction3Label;
    QLabel* instruction4Label;
    QLabel* instruction5Label;
    QLabel* instruction6Label;
    QPushButton* backButton= new QPushButton("back");
public:
    explicit HowToPlayPageGame1(QWidget *parent = nullptr);
private slots:
    void BackToMainMenuGame1Button();
signals:

};

#endif // HOWTOPLAYPAGEGAME1_H
