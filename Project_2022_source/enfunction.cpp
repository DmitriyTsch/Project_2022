// Функция перевода меню на английский язык

#include "mainclass.h"

void MainClass::enFunction()
{
    language=0;                                         // Смена языка на английский

    setWindowTitle("Dictionary");
    searchBtn->setText("Search");
    exit->setText("Exit");
    about->setText("About programme");
    setting->setText("Settings");
    menu->setTitle("Menu");
    menu2->setTitle("Programme");

    settingWgt->setWindowTitle("Settings");
    langBtn->setText("English");
    closeBtn->setText("Close");
    rusAction->setText("Russian");
    enAction->setText("English");
    langLbl->setText("Current language");
    colRadioBtn[0]->setText("White");
    colRadioBtn[1]->setText("Red");
    colRadioBtn[2]->setText("Green");
    colRadioBtn[3]->setText("Blue");
    colRadioBtn[4]->setText("Grey");
    menuColAction->setText("Menu colour");
    backgroundColAction->setText("Background colour");
    editColAction->setText("Edit colour");
    buttonColAction->setText("Button colour");

    if(colourSetting==0)                                // Если выбрано изменение цвета меню
    {
        colBtn->setText("Menu colour");                 // Изменение текста на кнопке меню изменения цвета
    }
    else if(colourSetting==1)                           // Если выбрано изменение цвета фона
    {
        colBtn->setText("Background colour");           // Изменение текста на кнопке меню изменения цвета
    }
    else if(colourSetting==2)                           // Если выбрано изменение цвета текстовых полей
    {
        colBtn->setText("Edit colour");                 // Изменение текста на кнопке меню изменения цвета
    }
    else                                                // Если выбрано изменение цвета кнопок
    {
        colBtn->setText("Button colour");               // Изменение текста на кнопке меню изменения цвета
    }


    // Запись настроек в файл

    settingFile=new QFile(settings+"/setting.set");     // Привязка объекта к файлу настроек
    if(settingFile->open(QIODevice::WriteOnly))         // Если файл открыт
    {
        QTextStream stream(settingFile);                // Создание текстового потока
        for(int i=0; i<4; ++i)
        {
            stream<<QString::number(currentCol[i])<<" ";// Запись текущих цветов
        }
        stream<<QString::number(currentTextType)<<" ";  // Запись текущего шрифта
        stream<<QString::number(language);              // Запись текущего языка
        settingFile->close();                           // Закрытие файла
    }
    delete settingFile;                                 // Освобождение памяти
}
