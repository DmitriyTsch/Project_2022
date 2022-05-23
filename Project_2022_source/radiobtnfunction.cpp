// Функция изменения цвета элементов

#include "mainclass.h"

void MainClass::radioBtnFunction()
{
    if(colRadioBtn[0]->isChecked())                                             // Если выбран белый цвет
    {
        if(colourSetting==0)                                                    // Если выбран цвет меню
        {
            currentCol[0]=0;                                                    // Установка цвета для меню
            menu->setStyleSheet("background-color: rgb(255, 255, 255)");
            menu2->setStyleSheet("background-color: rgb(255, 255, 255)");
            menuBar->setStyleSheet("background-color: rgb(255, 255, 255)");
        }
        else if(colourSetting==1)                                               // Если выбран цвет фона
        {
            currentCol[1]=0;                                                    // Установка цвета для фона
            setStyleSheet("background-color: rgb(255, 255, 255)");
            settingWgt->setStyleSheet("background-color: rgb(255, 255, 255)");
        }
        else if(colourSetting==2)                                               // Если выбран цвет поля записи
        {
            currentCol[2]=0;                                                    // Установка цвета для поля записи
            lnEdit->setStyleSheet("background-color: rgb(255, 255, 255)");
            txtEdit->setStyleSheet("background-color: rgb(255, 255, 255)");
        }
        else                                                                    // Если выбран цвет кнопок
        {
            currentCol[3]=0;                                                    // Установка цвета для кнопок
            searchBtn->setStyleSheet("background-color: rgb(255, 255, 255)");
            langBtn->setStyleSheet("background-color: rgb(255, 255, 255)");
            closeBtn->setStyleSheet("background-color: rgb(255, 255, 255)");
            langMenu->setStyleSheet("background-color: rgb(255, 255, 255)");
            colBtn->setStyleSheet("background-color: rgb(255, 255, 255)");
            menuCol->setStyleSheet("background-color: rgb(255, 255, 255)");
        }
    }
    else if(colRadioBtn[1]->isChecked())                                        // Если выбран красный цвет
    {
        if(colourSetting==0)
        {
            currentCol[0]=1;
            menu->setStyleSheet("background-color: rgb(255, 0, 0)");
            menu2->setStyleSheet("background-color: rgb(255, 0, 0)");
            menuBar->setStyleSheet("background-color: rgb(255, 0, 0)");
        }
        else if(colourSetting==1)
        {
            currentCol[1]=1;
            setStyleSheet("background-color: rgb(255, 0, 0)");
            settingWgt->setStyleSheet("background-color: rgb(255, 0, 0)");
        }
        else if(colourSetting==2)
        {
            currentCol[2]=1;
            lnEdit->setStyleSheet("background-color: rgb(255, 0, 0)");
            txtEdit->setStyleSheet("background-color: rgb(255, 0, 0)");
        }
        else
        {
            currentCol[3]=1;
            searchBtn->setStyleSheet("background-color: rgb(255, 0, 0)");
            langBtn->setStyleSheet("background-color: rgb(255, 0, 0)");
            closeBtn->setStyleSheet("background-color: rgb(255, 0, 0)");
            langMenu->setStyleSheet("background-color: rgb(255, 0, 0)");
            colBtn->setStyleSheet("background-color: rgb(255, 0, 0)");
            menuCol->setStyleSheet("background-color: rgb(255, 0, 0)");
        }
    }
    else if(colRadioBtn[2]->isChecked())                                        // Если выбран зеленый цвет
    {
        if(colourSetting==0)
        {
            currentCol[0]=2;
            menu->setStyleSheet("background-color: rgb(0, 255, 0)");
            menu2->setStyleSheet("background-color: rgb(0, 255, 0)");
            menuBar->setStyleSheet("background-color: rgb(0, 255, 0)");
        }
        else if(colourSetting==1)
        {
            currentCol[1]=2;
            setStyleSheet("background-color: rgb(0, 255, 0)");
            settingWgt->setStyleSheet("background-color: rgb(0, 255, 0)");
        }
        else if(colourSetting==2)
        {
            currentCol[2]=2;
            lnEdit->setStyleSheet("background-color: rgb(0, 255, 0)");
            txtEdit->setStyleSheet("background-color: rgb(0, 255, 0)");
        }
        else
        {
            currentCol[3]=2;
            searchBtn->setStyleSheet("background-color: rgb(0, 255, 0)");
            langBtn->setStyleSheet("background-color: rgb(0, 255, 0)");
            closeBtn->setStyleSheet("background-color: rgb(0, 255, 0)");
            langMenu->setStyleSheet("background-color: rgb(0, 255, 0)");
            colBtn->setStyleSheet("background-color: rgb(0, 255, 0)");
            menuCol->setStyleSheet("background-color: rgb(0, 255, 0)");
        }
    }
    else if(colRadioBtn[3]->isChecked())                                        // Если выбран синий цвет
    {
        if(colourSetting==0)
        {
            currentCol[0]=3;
            menu->setStyleSheet("background-color: rgb(0, 0, 255)");
            menu2->setStyleSheet("background-color: rgb(0, 0, 255)");
            menuBar->setStyleSheet("background-color: rgb(0, 0, 255)");
        }
        else if(colourSetting==1)
        {
            currentCol[1]=3;
            setStyleSheet("background-color: rgb(0, 0, 255)");
            settingWgt->setStyleSheet("background-color: rgb(0, 0, 255)");
        }
        else if(colourSetting==2)
        {
            currentCol[2]=3;
            lnEdit->setStyleSheet("background-color: rgb(0, 0, 255)");
            txtEdit->setStyleSheet("background-color: rgb(0, 0, 255)");
        }
        else
        {
            currentCol[3]=3;
            searchBtn->setStyleSheet("background-color: rgb(0, 0, 255)");
            langBtn->setStyleSheet("background-color: rgb(0, 0, 255)");
            closeBtn->setStyleSheet("background-color: rgb(0, 0, 255)");
            langMenu->setStyleSheet("background-color: rgb(0, 0, 255)");
            colBtn->setStyleSheet("background-color: rgb(0, 0, 255)");
            menuCol->setStyleSheet("background-color: rgb(0, 0, 255)");
        }
    }
    else                                                                        // Если выбран серый цвет
    {
        if(colourSetting==0)
        {
            currentCol[0]=4;
            menu->setStyleSheet("background-color: rgb(230, 230, 230)");
            menu2->setStyleSheet("background-color: rgb(230, 230, 230)");
            menuBar->setStyleSheet("background-color: rgb(230, 230, 230)");
        }
        else if(colourSetting==1)
        {
            currentCol[1]=4;
            setStyleSheet("background-color: rgb(230, 230, 230)");
            settingWgt->setStyleSheet("background-color: rgb(230, 230, 230)");
        }
        else if(colourSetting==2)
        {
            currentCol[2]=4;
            lnEdit->setStyleSheet("background-color: rgb(230, 230, 230)");
            txtEdit->setStyleSheet("background-color: rgb(230, 230, 230)");
        }
        else
        {
            currentCol[3]=4;
            searchBtn->setStyleSheet("background-color: rgb(230, 230, 230)");
            langBtn->setStyleSheet("background-color: rgb(230, 230, 230)");
            closeBtn->setStyleSheet("background-color: rgb(230, 230, 230)");
            langMenu->setStyleSheet("background-color: rgb(230, 230, 230)");
            colBtn->setStyleSheet("background-color: rgb(230, 230, 230)");
            menuCol->setStyleSheet("background-color: rgb(230, 230, 230)");
        }
    }


    // Запись настроек в файл

    settingFile=new QFile(settings+"/setting.set");         // Привязка объекта к файлу настроек
    if(settingFile->open(QIODevice::WriteOnly))             // Если файл открыт
    {
        QTextStream stream(settingFile);                    // Создание текстового потока
        for(int i=0; i<4; ++i)
        {
            stream<<QString::number(currentCol[i])<<" ";    // Запись текущих цветов
        }
        stream<<QString::number(currentTextType)<<" ";      // Запись текущего шрифта
        stream<<QString::number(language);                  // Запись текущего языка
        settingFile->close();                               // Закрытие файла
    }
    delete settingFile;                                     // Освобождение памяти
}
