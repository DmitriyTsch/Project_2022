// Описание конструктора

#include "mainclass.h"

MainClass::MainClass()
{
    // Получение настроек из файла

    settingFile=new QFile(settings+"/setting.set");     // Привязка объекта к файлу с настройками
    if(settingFile->open(QIODevice::ReadWrite))         // Если файл открыт
    {
        QByteArray array;                               // Массив для чтения настроек из файла

        array=settingFile->read(1);                     // Чтение в массив
        currentCol[0]=array.toInt();                    // Получение цвета меню

        settingFile->read(1);                           // Пропуск пробела
        array=settingFile->read(1);                     // Чтение в массив
        currentCol[1]=array.toInt();                    // Получение цвета фона

        settingFile->read(1);                           // Пропуск пробела
        array=settingFile->read(1);                     // Чтение в массив
        currentCol[2]=array.toInt();                    // Получение цвета поля записи

        settingFile->read(1);                           // Пропуск пробела
        array=settingFile->read(1);                     // Чтение в массив
        currentCol[3]=array.toInt();                    // Получение цвета кнопок

        settingFile->read(1);                           // Пропуск пробела
        array=settingFile->read(1);                     // Чтение в массив
        currentTextType=array.toShort();                // Получение шрифта

        settingFile->read(1);                           // Пропуск пробела
        array=settingFile->read(1);                     // Чтение в массив
        language=array.toShort();                       // Получение языка

        settingFile->close();                           // Закрытие файла
    }
    else                                                // Если файл не открыт
    {
        for(int i=0; i<4; ++i)
        {
            currentCol[i]=4;                            // Установка серого цвета по умолчанию
        }
    }
    delete settingFile;                                 // Освобождение памяти


    // Создание меню

    about=new QAction(this);                                    // Выделение памяти для действия меню
    about->setIcon(QIcon(pictures+"/abouticon"));               // Добавление иконки
    about->setShortcut(tr("Ctrl+A"));                           // Добавление кнопок быстрого доступа
    about->setFont(QFont(colourStr[currentTextType], 12));      // Изменение шрифта с размером
    connect(about, SIGNAL(triggered()),
            this, SLOT(aboutFunction()));                       // Обработка нажатия

    exit=new QAction(this);    
    exit->setIcon(QIcon(pictures+"/exiticon"));
    exit->setShortcut(tr("Ctrl+E"));
    exit->setFont(QFont(colourStr[currentTextType], 12));
    connect(exit, SIGNAL(triggered()),
            this, SLOT(exitFunction()));

    setting=new QAction(this);    
    setting->setIcon(QIcon(pictures+"/settingicon"));
    setting->setFont(QFont(colourStr[currentTextType], 12));
    connect(setting, SIGNAL(triggered()),
            this, SLOT(settingFunction()));

    menu=new QMenu(this);                                       // Выделение памяти для блока меню
    menu->setFont(QFont(colourStr[currentTextType], 12));       // Изменение шрифта с размером
    menu->addAction(setting);                                   // Добавление элемента
    menu->addSeparator();                                       // Добавление разграничителя
    menu->addAction(exit);                                      // Добавление элемента

    menu2=new QMenu(this);
    menu2->setFont(QFont(colourStr[currentTextType], 12));
    menu2->addAction(about);

    menuBar=new QMenuBar(this);                                 // Выделение памяти для блоков меню
    menuBar->addMenu(menu);                                     // Добавление блока
    menuBar->addMenu(menu2);                                    // Добавление блока
    menuBar->setFont(QFont(colourStr[currentTextType], 12));    // Изменение шрифта с размером


    // Создание элементов на главном экране

    lnEdit=new QLineEdit(this);                                 // Выделение памяти для строки поиска
    lnEdit->setFont(QFont(colourStr[currentTextType], 12));     // Изменение шрифта с размером

    searchBtn=new QPushButton(this);                            // Выделение памяти для кнопки поиска
    searchBtn->setFont(QFont(colourStr[currentTextType], 12));  // Изменение шрифта с размером
    connect(searchBtn, SIGNAL(clicked()),
            this, SLOT(btnClicked()));                          // Обработка нажатия

    txtEdit=new QTextEdit(this);                                // Выделение памяти для поля вывода
    txtEdit->setVisible(false);                                 // Сделать поле невидимым
    txtEdit->setReadOnly(true);                                 // Поле доступно только для чтения
    txtEdit->setFont(QFont(colourStr[currentTextType], 12));    // Изменение шрифта с размером


    // Изменение цвета меню

    if(currentCol[0]==0)                                                // Если цвет меню белый
    {
        menu->setStyleSheet("background-color: rgb(255, 255, 255)");
        menu2->setStyleSheet("background-color: rgb(255, 255, 255)");
        menuBar->setStyleSheet("background-color: rgb(255, 255, 255)");
    }
    else if(currentCol[0]==1)                                           // Если цвет меню красный
    {
        menu->setStyleSheet("background-color: rgb(255, 0, 0)");
        menu2->setStyleSheet("background-color: rgb(255, 0, 0)");
        menuBar->setStyleSheet("background-color: rgb(255, 0, 0)");
    }
    else if(currentCol[0]==2)                                           // Если цвет меню зеленый
    {
        menu->setStyleSheet("background-color: rgb(0, 255, 0)");
        menu2->setStyleSheet("background-color: rgb(0, 255, 0)");
        menuBar->setStyleSheet("background-color: rgb(0, 255, 0)");
    }
    else if(currentCol[0]==3)                                           // Если цвет меню синий
    {
        menu->setStyleSheet("background-color: rgb(0, 0, 255)");
        menu2->setStyleSheet("background-color: rgb(0, 0, 255)");
        menuBar->setStyleSheet("background-color: rgb(0, 0, 255)");
    }
    else                                                                // Если цвет меню серый
    {
        menu->setStyleSheet("background-color: rgb(230, 230, 230)");
        menu2->setStyleSheet("background-color: rgb(230, 230, 230)");
        menuBar->setStyleSheet("background-color: rgb(230, 230, 230)");
    }


    // Изменение цвета фона

    if(currentCol[1]==0)                                                // Если цвет фона белый
    {
        setStyleSheet("background-color: rgb(255, 255, 255)");
    }
    else if(currentCol[1]==1)                                           // Если цвет фона красный
    {
        setStyleSheet("background-color: rgb(255, 0, 0)");
    }
    else if(currentCol[1]==2)                                           // Если цвет фона зеленый
    {
        setStyleSheet("background-color: rgb(0, 255, 0)");
    }
    else if(currentCol[1]==3)                                           // Если цвет фона синий
    {
        setStyleSheet("background-color: rgb(0, 0, 255)");
    }
    else                                                                // Если цвет фона серый
    {
        setStyleSheet("background-color: rgb(230, 230, 230)");
    }


    // Изменение цвета текстового поля

    if(currentCol[2]==0)                                                // Если цвет поля белый
    {
        lnEdit->setStyleSheet("background-color: rgb(255, 255, 255)");
        txtEdit->setStyleSheet("background-color: rgb(255, 255, 255)");
    }
    else if(currentCol[2]==1)                                           // Если цвет поля красный
    {
        lnEdit->setStyleSheet("background-color: rgb(255, 0, 0)");
        txtEdit->setStyleSheet("background-color: rgb(255, 0, 0)");
    }
    else if(currentCol[2]==2)                                           // Если цвет поля зеленый
    {
        lnEdit->setStyleSheet("background-color: rgb(0, 255, 0)");
        txtEdit->setStyleSheet("background-color: rgb(0, 255, 0)");
    }
    else if(currentCol[2]==3)                                           // Если цвет поля синий
    {
        lnEdit->setStyleSheet("background-color: rgb(0, 0, 255)");
        txtEdit->setStyleSheet("background-color: rgb(0, 0, 255)");
    }
    else                                                                // Если цвет поля серый
    {
        lnEdit->setStyleSheet("background-color: rgb(230, 230, 230)");
        txtEdit->setStyleSheet("background-color: rgb(230, 230, 230)");
    }


    // Изменение цвета кнопок

    if(currentCol[3]==0)                                                // Если цвет кнопок белый
    {
        searchBtn->setStyleSheet("background-color: rgb(255, 255, 255)");
    }
    else if(currentCol[3]==1)                                           // Если цвет кнопок красный
    {
        searchBtn->setStyleSheet("background-color: rgb(255, 0, 0)");
    }
    else if(currentCol[3]==2)                                           // Если цвет кнопок зеленый
    {
        searchBtn->setStyleSheet("background-color: rgb(0, 255, 0)");
    }
    else if(currentCol[3]==3)                                           // Если цвет кнопок синий
    {
        searchBtn->setStyleSheet("background-color: rgb(0, 0, 255)");
    }
    else                                                                // Если цвет кнопок серый
    {
        searchBtn->setStyleSheet("background-color: rgb(230, 230, 230)");
    }


    // Установка текста на элементы

    if(language==0)                             // Если выбран английский язык
    {
        setWindowTitle("Dictionary");
        about->setText("About programme");
        exit->setText("Exit");
        setting->setText("Settings");
        menu->setTitle("Menu");
        menu2->setTitle("Programme");
        searchBtn->setText("Search");
    }
    else                                        // Если выбран русский язык
    {
        setWindowTitle("Словарь");
        about->setText("О программе");
        exit->setText("Выход");
        setting->setText("Настройки");
        menu->setTitle("Меню");
        menu2->setTitle("Программа");
        searchBtn->setText("Поиск");
    }


    resize(600, 500);                           // Установка размера окна
    setMinimumHeight(400);                      // Установка минимальной высоты
    setMinimumWidth(500);                       // Установка минимальной ширины
}
