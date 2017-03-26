#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"

#include "Mozhina_Alina_201731143_Task1.h"

int main(int argc, char *argv[])
{
    mvms_2017::Task1 x(true);
    mvms_2017::Task2 x1(true);
    mvms_2017::Task3 x2(true);
    mvms_2017::Task4 x3(true);
    mvms_2017::Task5 x4(true);

    mvms_2017::Mozhina_Alina_201731143_Task1 task1(true);

    try
    {
        cv::Mat image = task1.drawTriangle("src.jpg", 2, 2, 90, 30, 60, 90);

        cv::imshow("Image", image);
        cv::waitKey(0);
    }
    catch (std::exception ex)
    {
        std::cout << ex.what();
    }

    return 0;
}
