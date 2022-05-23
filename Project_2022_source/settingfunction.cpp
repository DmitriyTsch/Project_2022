// Вызов меню настроек

#include "mainclass.h"

void MainClass::settingFunction()
{
    settingWgt=new QWidget(this);                                           // Окно настроек
    settingWgt->setWindowFlags(Qt::Window | Qt::WindowTitleHint);           // Параметры окна
    settingWgt->setWindowModality(Qt::WindowModal);                         // Параметры окна


    // Установка фона окна

    if(currentCol[1]==0)                                                    // Если цвет фона белый
    {
        settingWgt->setStyleSheet("background-color: rgb(255, 255, 255)");
    }
    else if(currentCol[1]==1)                                               // Если цвет фона красный
    {
        settingWgt->setStyleSheet("background-color: rgb(255, 0, 0)");
    }
    else if(currentCol[1]==2)                                               // Если цвет фона зеленый
    {
        settingWgt->setStyleSheet("background-color: rgb(0, 255, 0)");
    }
    else if(currentCol[1]==3)                                               // Если цвет фона синий
    {
        settingWgt->setStyleSheet("background-color: rgb(0, 0, 255)");
    }
    else                                                                    // Если цвет фона серый
    {
        settingWgt->setStyleSheet("background-color: rgb(230, 230, 230)");
    }


    langBtn=new QPushButton(settingWgt);                                    // Создание кнопки выбор языка
    langBtn->setGeometry(220, 30, 150, 30);                                 // Установка размера кнопки
    langBtn->setFont(QFont(colourStr[currentTextType], 12));                // Изменение шрифта с размером

    rusAction=new QAction(this);                                            // Создание кнопки с русским языком
    rusAction->setFont(QFont(colourStr[currentTextType], 12));              // Изменение шрифта с размером
    connect(rusAction, SIGNAL(triggered()),
            this, SLOT(rusFunction()));                                     // Обработка нажатия кнопки

    enAction=new QAction(this);                                             // Создание кнопки с английским языком
    enAction->setFont(QFont(colourStr[currentTextType], 12));               // Изменение шрифта с размером
    connect(enAction, SIGNAL(triggered()),
            this, SLOT(enFunction()));                                      // Обработка нажатия кнопки

    langMenu=new QMenu(langBtn);                                            // Создания блока кнопок
    langMenu->addAction(rusAction);                                         // Добавление элемента в блок
    langMenu->addAction(enAction);                                          // Добавление элемента в блок
    langBtn->setMenu(langMenu);                                             // Установка блока на кнопку

    langLbl=new QLabel(settingWgt);                                         // Создание надписи текущего языка
    langLbl->setGeometry(30, 30, 200, 30);                                  // Установка размеров
    langLbl->setFont(QFont(colourStr[currentTextType], 12));                // Изменение шрифта с размером

    splitterLbl[0]=new QLabel(settingWgt);                                  // Создание первого разделителя
    splitterLbl[0]->setStyleSheet("background-color: rgb(0, 0, 0)");        // Установка цвета
    splitterLbl[0]->setGeometry(30, 85, 340, 1);                            // Установка размеров

    colBtn=new QPushButton(settingWgt);                                     // Создание кнопки выбора цветов элементов
    colBtn->setFont(QFont(colourStr[currentTextType], 12));                 // Изменение шрифта с размером
    colBtn->setGeometry(30, 110, 200, 30);                                  // Установка размеров


    // Элементы меню кнопки colBtn

    menuColAction=new QAction(this);                                        // Изменение цвета меню
    menuColAction->setFont(QFont(colourStr[currentTextType], 12));          // Изменение шрифта с размером
    connect(menuColAction, SIGNAL(triggered()),
            this, SLOT(menuColFunction()));                                 // Обработка нажатия кнопки

    backgroundColAction=new QAction(this);                                  // Изменение цвета фона
    backgroundColAction->setFont(QFont(colourStr[currentTextType], 12));
    connect(backgroundColAction, SIGNAL(triggered()),
            this, SLOT(backgroundColFunction()));

    editColAction=new QAction(this);                                        // Изменение цвета текстового поля
    editColAction->setFont(QFont(colourStr[currentTextType], 12));
    connect(editColAction, SIGNAL(triggered()),
            this, SLOT(editColFunction()));

    buttonColAction=new QAction(this);                                      // Изменение цвета кнопок
    buttonColAction->setFont(QFont(colourStr[currentTextType], 12));
    connect(buttonColAction, SIGNAL(triggered()),
            this, SLOT(buttonColFunction()));


    // Добавление элементов на кнопку colBtn

    menuCol=new QMenu(colBtn);
    menuCol->addAction(menuColAction);
    menuCol->addAction(backgroundColAction);
    menuCol->addAction(editColAction);
    menuCol->addAction(buttonColAction);
    colBtn->setMenu(menuCol);


    // Создание кнопок-переключателей цветов

    for(int i=0; i<5; ++i)
    {
        colRadioBtn[i]=new QRadioButton(settingWgt);                        // Создание переключателя
        colRadioBtn[i]->setGeometry(30, 165+i*40, 200, 30);                 // Установка размеров
        colRadioBtn[i]->setFont(QFont(colourStr[currentTextType], 12));     // Изменение шрифта с размером
        if(currentCol[0]==i)
        {
            colRadioBtn[i]->setChecked(true);                               // Установка цвета меню
        }
        connect(colRadioBtn[i], SIGNAL(clicked()),
                this, SLOT(radioBtnFunction()));                            // Обработка нажатия кнопки
    }


    // Группировка кнопок-переключателей цветов

    btnGroup[0]=new QButtonGroup(settingWgt);
    for(int i=0; i<5; ++i)
    {
        btnGroup[0]->addButton(colRadioBtn[i]);
    }


    // Создание второго разделителя

    splitterLbl[1]=new QLabel(settingWgt);
    splitterLbl[1]->setStyleSheet("background-color: rgb(0, 0, 0)");
    splitterLbl[1]->setGeometry(30, 380, 340, 1);


    // Создание кнопок-переключателей шрифтов

    for(int i=0; i<5; ++i)
    {
        typeTextBtn[i]=new QRadioButton(settingWgt);                        // Создание переключателя
        typeTextBtn[i]->setGeometry(30, 405+i*40, 200, 30);                 // Установка размеров
        if(currentTextType==i)
        {
            typeTextBtn[i]->setChecked(true);                               // Установка шрифта
        }
        connect(typeTextBtn[i], SIGNAL(clicked()),
                this, SLOT(typeTextBtnFunction()));                         // Обработка нажатия кнопки
    }
    typeTextBtn[0]->setFont(QFont("Arial", 12));                            // Изменение шрифта с размером
    typeTextBtn[1]->setFont(QFont("Calibri", 12));
    typeTextBtn[2]->setFont(QFont("Impact", 12));
    typeTextBtn[3]->setFont(QFont("Tahoma", 12));
    typeTextBtn[4]->setFont(QFont("Times New Roman", 12));


    // Группировка кнопок-переключателей шрифтов

    btnGroup[1]=new QButtonGroup(settingWgt);
    for(int i=0; i<5; ++i)
    {
        btnGroup[1]->addButton(typeTextBtn[i]);
    }


    // Создание кнопки закрытия меню настроек

    closeBtn=new QPushButton(settingWgt);                                   // Создание кнопки закрытия
    closeBtn->setGeometry(150, 620, 100, 30);                               // Установка размеров
    closeBtn->setFont(QFont(colourStr[currentTextType], 12));               // Изменение шрифта с размером
    connect(closeBtn, SIGNAL(clicked()),
            this, SLOT(cancelBtn()));                                       // Обработка нажатия кнопки


    // Установка цвета кнопок

    if(currentCol[3]==0)
    {
        langBtn->setStyleSheet("background-color: rgb(255, 255, 255)");
        closeBtn->setStyleSheet("background-color: rgb(255, 255, 255)");
        langMenu->setStyleSheet("background-color: rgb(255, 255, 255)");
        colBtn->setStyleSheet("background-color: rgb(255, 255, 255)");
        menuCol->setStyleSheet("background-color: rgb(255, 255, 255)");
    }
    else if(currentCol[3]==1)
    {
        langBtn->setStyleSheet("background-color: rgb(255, 0, 0)");
        closeBtn->setStyleSheet("background-color: rgb(255, 0, 0)");
        langMenu->setStyleSheet("background-color: rgb(255, 0, 0)");
        colBtn->setStyleSheet("background-color: rgb(255, 0, 0)");
        menuCol->setStyleSheet("background-color: rgb(255, 0, 0)");
    }
    else if(currentCol[3]==2)
    {
        langBtn->setStyleSheet("background-color: rgb(0, 255, 0)");
        closeBtn->setStyleSheet("background-color: rgb(0, 255, 0)");
        langMenu->setStyleSheet("background-color: rgb(0, 255, 0)");
        colBtn->setStyleSheet("background-color: rgb(0, 255, 0)");
        menuCol->setStyleSheet("background-color: rgb(0, 255, 0)");
    }
    else if(currentCol[3]==3)
    {
        langBtn->setStyleSheet("background-color: rgb(0, 0, 255)");
        closeBtn->setStyleSheet("background-color: rgb(0, 0, 255)");
        langMenu->setStyleSheet("background-color: rgb(0, 0, 255)");
        colBtn->setStyleSheet("background-color: rgb(0, 0, 255)");
        menuCol->setStyleSheet("background-color: rgb(0, 0, 255)");
    }
    else
    {
        langBtn->setStyleSheet("background-color: rgb(230, 230, 230)");
        closeBtn->setStyleSheet("background-color: rgb(230, 230, 230)");
        langMenu->setStyleSheet("background-color: rgb(230, 230, 230)");
        colBtn->setStyleSheet("background-color: rgb(230, 230, 230)");
        menuCol->setStyleSheet("background-color: rgb(230, 230, 230)");
    }


    // Установка размера окна и установка его видимости

    settingWgt->setFixedSize(400, 680);
    settingWgt->show();


    // Установка всех надписей на окне

    if(language==0)                                                         // Если выбран английский язык
    {
        settingWgt->setWindowTitle("Settings");
        langLbl->setText("Current language");
        rusAction->setText("Russian");
        enAction->setText("English");
        langBtn->setText("English");
        colBtn->setText("Menu colour");

        menuColAction->setText("Menu colour");
        backgroundColAction->setText("Background colour");
        editColAction->setText("Edit colour");
        buttonColAction->setText("Button colour");

        colRadioBtn[0]->setText("White");
        colRadioBtn[1]->setText("Red");
        colRadioBtn[2]->setText("Green");
        colRadioBtn[3]->setText("Blue");
        colRadioBtn[4]->setText("Grey");

        closeBtn->setText("Close");
    }
    else                                                                    // Если выбран русский язык
    {
        settingWgt->setWindowTitle("Настройки");
        langLbl->setText("Текущий язык");
        rusAction->setText("Русский");
        enAction->setText("Английский");
        langBtn->setText("Русский");
        colBtn->setText("Цвет меню");

        menuColAction->setText("Цвет меню");
        backgroundColAction->setText("Цвет фона");
        editColAction->setText("Цвет записи");
        buttonColAction->setText("Цвет кнопок");

        colRadioBtn[0]->setText("Белый");
        colRadioBtn[1]->setText("Красный");
        colRadioBtn[2]->setText("Зеленый");
        colRadioBtn[3]->setText("Синий");
        colRadioBtn[4]->setText("Серый");

        closeBtn->setText("Закрыть");
    }

    for(int i=0; i<5; ++i)
    {
        typeTextBtn[i]->setText(colourStr[i]);                              // Установка названий шрифтов на кнопки-переключатели
    }
}
