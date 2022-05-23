// Функция изменения шрифта приложения

#include "mainclass.h"

void MainClass::typeTextBtnFunction()
{
    int j=0;
    for(int i=0; i<5; ++i)
    {
        if(typeTextBtn[i]->isChecked())
        {
            j=i;
            currentTextType=i;                              // Перезапись типа шрифта
        }
    }
    exit->setFont(QFont(colourStr[j], 12));                 // Изменение шрифта с размером
    about->setFont(QFont(colourStr[j], 12));
    setting->setFont(QFont(colourStr[j], 12));
    menu->setFont(QFont(colourStr[j], 12));
    menu2->setFont(QFont(colourStr[j], 12));
    menuBar->setFont(QFont(colourStr[j], 12));

    lnEdit->setFont(QFont(colourStr[j], 12));
    txtEdit->setFont(QFont(colourStr[j], 12));
    searchBtn->setFont(QFont(colourStr[j], 12));

    langBtn->setFont(QFont(colourStr[j], 12));
    closeBtn->setFont(QFont(colourStr[j], 12));
    rusAction->setFont(QFont(colourStr[j], 12));
    enAction->setFont(QFont(colourStr[j], 12));
    langMenu->setFont(QFont(colourStr[j], 12));
    langLbl->setFont(QFont(colourStr[j], 12));
    colBtn->setFont(QFont(colourStr[j], 12));
    menuColAction->setFont(QFont(colourStr[j], 12));
    backgroundColAction->setFont(QFont(colourStr[j], 12));
    editColAction->setFont(QFont(colourStr[j], 12));
    buttonColAction->setFont(QFont(colourStr[j], 12));
    menuCol->setFont(QFont(colourStr[j], 12));
    for(int i=0; i<5; ++i)
    {
        colRadioBtn[i]->setFont(QFont(colourStr[j], 12));
    }  


    // Запись настроек в файл

    settingFile=new QFile(settings+"/setting.set"); // Привязка объекта к файлу настроек
    if(settingFile->open(QIODevice::WriteOnly))     // Если файл открыт
    {
        QTextStream stream(settingFile);            // Создание текстового потока
        for(int i=0; i<4; ++i)
        {
            stream<<QString::number(currentCol[i])<<" ";    // Запись текущих цветов
        }
        stream<<QString::number(currentTextType)<<" ";      // Запись текущего шрифта
        stream<<QString::number(language);                  // Запись текущего языка

        settingFile->close();                       // Закрытие файла
    }
    delete settingFile;                             // Освобождение памяти
}
