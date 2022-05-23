// Функция перевода слова

#include "mainclass.h"

void MainClass::btnClicked()
{
    QString str=lnEdit->text();                     // Перенос поискового запроса в строку    

    file=new QFile(resources+"/"+str+".d");         // Привязка объекта к нужному файлу
    if(file->open(QIODevice::ReadOnly))             // Если файл открыт
    {
        txtEdit->setVisible(true);                  // Сделать поле вывода перевода видимым
        txtEdit->setText("");                       // Очистка поля перевода
        QByteArray byteArr=file->readAll();         // Чтение данных
        QString str2=QString::fromUtf8(byteArr);    // Смена кодировки
        txtEdit->setText(str2);                     // Заполнение области перевода
        file->close();                              // Закрытие файла
    }
    else                                            // Если файл не открыт
    {
        txtEdit->setVisible(false);                         // Сделать поле вывода перевода невидимым
        if(language==0)                                     // Если выбран английский язык
        {
            // Вывод сообщения об ошибке
            QMessageBox msgBox;
            msgBox.setWindowTitle("Searching mistake");
            if(str=="")                                     // Если строка запроса пуста
            {
                msgBox.setText("Entered empty request!");
            }
            else                                            // Если строка запроса не пуста
            {
                msgBox.setText("Word '"+str+"' wasn't found!");
            }
            msgBox.exec();
        }
        else                                                // Если выбран русский язык
        {
            // Вывод сообщения об ошибке
            QMessageBox msgBox;
            msgBox.setWindowTitle("Ошибка поиска");
            if(str=="")                                     // Если строка запроса пуста
            {
                msgBox.setText("Введен пустой запрос!");
            }
            else                                            // Если строка запроса не пуста
            {
                msgBox.setText("Слово '"+str+"' не найдено!");
            }
            msgBox.exec();
        }
    }
    delete file;                                    // Удаление файлового объекта
    lnEdit->setText("");                            // Очистка поля ввода
}
