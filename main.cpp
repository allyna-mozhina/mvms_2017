#include <QCoreApplication>
#include "task1.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    mvms_2017::Task1 x(true);
    try{
        x.drawCircle("Test",1,1,1);
    }catch(std::exception ex){
        std::cout << ex.what();
    }

    return 0;
}
