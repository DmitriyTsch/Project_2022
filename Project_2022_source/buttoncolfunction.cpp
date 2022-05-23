// Функция выбора цвета кнопок

#include "mainclass.h"

void MainClass::buttonColFunction()
{
    colourSetting=3;                            // Текущее положение кнопки изменения цвета
    if(language==0)                             // Если выбран английский язык
    {
        colBtn->setText("Button colour");       // Изменение текста на кнопке изменения цвета
    }
    else                                        // Если выбран русский язык
    {
        colBtn->setText("Цвет кнопок");         // Изменение текста на кнопке изменения цвета
    }

    if(currentCol[3]==0)                        // Если выбран белый цвет
    {
        colRadioBtn[0]->setChecked(true);       // включение переключателя
    }
    else if(currentCol[3]==1)                   // Если выбран красный цвет
    {
        colRadioBtn[1]->setChecked(true);       // включение переключателя
    }
    else if(currentCol[3]==2)                   // Если выбран зеленый цвет
    {
        colRadioBtn[2]->setChecked(true);       // включение переключателя
    }
    else if(currentCol[3]==3)                   // Если выбран синий цвет
    {
        colRadioBtn[3]->setChecked(true);       // включение переключателя
    }
    else                                        // Если выбран серый цвет
    {
        colRadioBtn[4]->setChecked(true);       // включение переключателя
    }
}
