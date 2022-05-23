// Функция перерасчета размеров элементов при изменении размера окна

#include "mainclass.h"

void MainClass::resizeEvent(QResizeEvent *re)
{
    int widthW=re->size().width();                                      // Размер по ширине
    int heightW=re->size().height();                                    // Размер по высоте

    lnEdit->setGeometry(30, 50, widthW-170, 30);                        // Перерасчет размера текстового поля
    searchBtn->setGeometry(widthW-110, 50, 80, 30);                     // Перерасчет размера кнопки поиска
    txtEdit->setGeometry(30, 100, widthW-60, heightW-130);              // Перерасчет размера поля вывода


    if(currentCol[0]==0)                                                // Если цвет меню белый
    {
        menuBar->setStyleSheet("background-color: rgb(255, 255, 255)"); // Установка цвета меню
    }
    else if(currentCol[0]==1)                                           // Если цвет меню красный
    {
        menuBar->setStyleSheet("background-color: rgb(255, 0, 0)");     // Установка цвета меню
    }
    else if(currentCol[0]==2)                                           // Если цвет меню зеленый
    {
        menuBar->setStyleSheet("background-color: rgb(0, 255, 0)");     // Установка цвета меню
    }
    else if(currentCol[0]==3)                                           // Если цвет меню синий
    {
        menuBar->setStyleSheet("background-color: rgb(0, 0, 255)");     // Установка цвета меню
    }
    else                                                                // Если цвет меню серый
    {
        menuBar->setStyleSheet("background-color: rgb(230, 230, 230)"); // Установка цвета меню
    }
}
