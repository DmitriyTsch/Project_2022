// Функция "о программе"

#include "mainclass.h"

void MainClass::aboutFunction()
{
    if(language==0)     // Если выбран английский язык
    {
        // Вызов диалогового окна
        QMessageBox::information(this, "About", "Russian-English / English-Russian distionary."
                                    "\nAuthor: Chilikin Dmitriy.");
    }
    else                // Если выбран русский язык
    {
        // Вызов диалогового окна
        QMessageBox::information(this, "О программе", "Русско-английский / англо-русский словарь."
                                    "\nАвтор: Чиликин Дмитрий.");
    }
}
