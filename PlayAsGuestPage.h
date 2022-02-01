#ifndef PLAYASGUESTPAGE_H
#define PLAYASGUESTPAGE_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>

/**
* \file PlayAsGuestPage.h
* \brief The main menu for guest players
* declares a play Battleships button, a play Disc Shooter button, and a back button.
*/
class PlayAsGuestPage : public QWidget
{
    Q_OBJECT
public:
    explicit PlayAsGuestPage(QWidget *parent = nullptr);
private:
    QPushButton* playGame1Button = new QPushButton("Play Battleships");
    QPushButton* playGame2Button = new QPushButton("Play Space Shooter");
    QPushButton* backButton  = new QPushButton("Back");

public slots:
    void GoToGame1();
    void GoToGame2();
    void BackToWelcomePage();
signals:

};

#endif // PLAYASGUESTPAGE_H
