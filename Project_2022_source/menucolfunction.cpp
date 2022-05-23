// Функция выбора цвета меню

#include "mainclass.h"

void MainClass::menuColFunction()
{
    colourSetting=0;                        // Текущее положение кнопки изменения цвета
    if(language==0)                         // Если выбран аглийский язык
    {
        colBtn->setText("Menu colour");     // Изменение текста на кнопке изменения цвета
    }
    else                                    // Если выбран русский язык
    {
        colBtn->setText("Цвет меню");       // Изменение текста на кнопке изменения цвета
    }

    if(currentCol[0]==0)                    // Если выбран белый цвет
    {
        colRadioBtn[0]->setChecked(true);   // включение переключателя
    }
    else if(currentCol[0]==1)               // Если выбран красный цвет
    {
        colRadioBtn[1]->setChecked(true);   // включение переключателя
    }
    else if(currentCol[0]==2)               // Если выбран зеленый цвет
    {
        colRadioBtn[2]->setChecked(true);   // включение переключателя
    }
    else if(currentCol[0]==3)               // Если выбран синий цвет
    {
        colRadioBtn[3]->setChecked(true);   // включение переключателя
    }
    else                                    // Если выбран серый цвет
    {
        colRadioBtn[4]->setChecked(true);   // включение переключателя
    }
}
