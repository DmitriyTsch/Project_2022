// Русско-английский / англо-русский словарь
// Автор: Чиликин Дмитрий

#include "mainclass.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./Qt_pictures/icon"));
    MainClass mainClass;
    mainClass.show();
    return a.exec();
}
