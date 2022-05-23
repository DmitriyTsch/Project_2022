#ifndef MAINCLASS_H
#define MAINCLASS_H
#include <QtWidgets>

class MainClass: public QWidget
{
    Q_OBJECT
public:
    short language=1;           // Текущий язык: 0 - английский, 1 - русский
    short colourSetting=0;      // Текущее состояние кнопки выбора настроек цвета:
                                // меню, фон, поля ввода или кнопок

    short currentCol[4];        // Текущие цвета для элементов: меню, фон, поля ввода или кнопок
    short currentTextType=0;    // Текущий тип шрифта

    QString resources={QCoreApplication::applicationDirPath()+"/Qt_resources"};         // Директория папки с ресурсами
    QString pictures={QCoreApplication::applicationDirPath()+"/Qt_pictures"};           // Директория папки с картинками
    QString settings={QCoreApplication::applicationDirPath()+"/Qt_settings"};           // Директория папки с настройками
    QString colourStr[5]={"Arial", "Calibri", "Impact", "Tahoma", "Times New Roman"};   // Названия шрифтов

    QFile *file=0;                          // Файловый объект для перевода текста
    QFile *settingFile=0;                   // Файловый объект для настроек
    QLineEdit *lnEdit;                      // Строка ввода
    QTextEdit *txtEdit;                     // Поле с переводом
    QPushButton *searchBtn;                 // Кнопка перевода
    QAction *exit, *about, *setting;        // Кнопки меню выхода, о программе и настроек
    QMenu *menu, *menu2;                    // Блоки меню
    QMenuBar *menuBar;                      // Общий блок меню

    QWidget *settingWgt;                    // Окно настроек
    QPushButton *langBtn, *closeBtn;        // Кнопки выбора языка и закрытия окна
    QAction *rusAction, *enAction;          // Меню выбора языка
    QMenu *langMenu;                        // Блоки меню выбора языка
    QLabel *langLbl;                        // Надпись текущего языка
    QLabel *splitterLbl[2];                 // Разделители
    QPushButton *colBtn;                    // Кнопка выбора цвета элементов

    QAction *menuColAction, *backgroundColAction,
        *editColAction, *buttonColAction;   // Меню выбора настроек цвета элементов
    QMenu *menuCol;                         // Блок меню настроек цвета элементов
    QRadioButton *colRadioBtn[5];           // Кнопки-переключатели цветов
    QRadioButton *typeTextBtn[5];           // Кнопки-переключатели шрифта
    QButtonGroup *btnGroup[2];              // Группировка кнопок-переключателей

    MainClass();
    virtual void resizeEvent(QResizeEvent*);// Изменение размера главного окна
public slots:
    void btnClicked();                      // Нажатие кнопки перевода
    void aboutFunction();                   // Сведения о программе
    void exitFunction();                    // Выход из программы
    void settingFunction();                 // Настройки приложения

    void cancelBtn();                       // Выход из окна настроек
    void enFunction();                      // Изменение языка на английский
    void rusFunction();                     // Изменение языка на русский
    void menuColFunction();                 // Изменение цвета меню
    void backgroundColFunction();           // Изменение цвета фона
    void editColFunction();                 // Изменение цвета текстовых полей
    void buttonColFunction();               // Изменение цвета кнопок
    void radioBtnFunction();                // Изменение цвета элементов
    void typeTextBtnFunction();             // Изменение шрифта элементов
};

#endif // MAINCLASS_H
