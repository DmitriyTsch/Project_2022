// Функция перевода меню на русский язык

#include "mainclass.h"

void MainClass::rusFunction()
{
    language=1;                                     // Смена языка на русский

    setWindowTitle("Словарь");
    searchBtn->setText("Поиск");
    exit->setText("Выход");
    about->setText("О программе");
    setting->setText("Настройки");
    menu->setTitle("Меню");
    menu2->setTitle("Программа");

    settingWgt->setWindowTitle("Настройки");
    langBtn->setText("Русский");
    closeBtn->setText("Закрыть");
    rusAction->setText("Русский");
    enAction->setText("Английский");
    langLbl->setText("Текущий язык");
    colRadioBtn[0]->setText("Белый");
    colRadioBtn[1]->setText("Красный");
    colRadioBtn[2]->setText("Зеленый");
    colRadioBtn[3]->setText("Синий");
    colRadioBtn[4]->setText("Серый");
    menuColAction->setText("Цвет меню");
    backgroundColAction->setText("Цвет фона");
    editColAction->setText("Цвет записи");
    buttonColAction->setText("Цвет кнопок");

    if(colourSetting==0)                            // Если выбрано изменение цвета меню
    {
        colBtn->setText("Цвет меню");               // Изменение текста на кнопке меню изменения цвета
    }
    else if(colourSetting==1)                       // Если выбрано изменение цвета фона
    {
        colBtn->setText("Цвет фона");               // Изменение текста на кнопке меню изменения цвета
    }
    else if(colourSetting==2)                       // Если выбрано изменение цвета текстовых полей
    {
        colBtn->setText("Цвет записи");             // Изменение текста на кнопке меню изменения цвета
    }
    else                                            // Если выбрано изменение цвета кнопок
    {
        colBtn->setText("Цвет кнопок");             // Изменение текста на кнопке меню изменения цвета
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

