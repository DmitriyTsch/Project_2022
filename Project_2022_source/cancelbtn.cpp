// Функция высвобождения памяти от эл-тов в меню настроек при закрытии

#include "mainclass.h"

void MainClass::cancelBtn()
{
    delete langMenu;
    delete enAction;
    delete rusAction;
    delete langBtn;
    delete closeBtn;
    delete langLbl;
    delete splitterLbl[0];

    delete menuCol;
    delete menuColAction;
    delete backgroundColAction;
    delete editColAction;
    delete buttonColAction;
    delete colBtn;
    for(int i=0; i<5; ++i)
    {
        delete colRadioBtn[i];
    }
    delete splitterLbl[1];

    delete btnGroup[0];
    delete btnGroup[1];
    for(int i=0; i<5; ++i)
    {
        delete typeTextBtn[i];
    }

    delete settingWgt;
}
