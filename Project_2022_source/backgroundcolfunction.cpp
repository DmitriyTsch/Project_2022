// Функция выбора цвета фона

#include "mainclass.h"

void MainClass::backgroundColFunction()
{
    colourSetting=1;                        // Текущее положение кнопки изменения цвета
    if(language==0)                         // Если выбран английский язык
    {
        colBtn->setText("Background colour");
    }
    else                                    // Если выбран русский язык
    {
        colBtn->setText("Цвет фона");
    }

    if(currentCol[1]==0)                    // Если выбран белый цвет
    {
        colRadioBtn[0]->setChecked(true);   // включение переключателя
    }
    else if(currentCol[1]==1)               // Если выбран красный цвет
    {
        colRadioBtn[1]->setChecked(true);   // включение переключателя
    }
    else if(currentCol[1]==2)               // Если выбран зеленый цвет
    {
        colRadioBtn[2]->setChecked(true);   // включение переключателя
    }
    else if(currentCol[1]==3)               // Если выбран синий цвет
    {
        colRadioBtn[3]->setChecked(true);   // включение переключателя
    }
    else                                    // Если выбран серый цвет
    {
        colRadioBtn[4]->setChecked(true);   // включение переключателя
    }
}
