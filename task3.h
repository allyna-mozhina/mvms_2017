#ifndef TASK3_H
#define TASK3_H

#include "commun_task.h"
/*!
 * Пространство имен, соответсвующее этому году
 */
namespace mvms_2017
{
class Task3 : public Commun_Task
{
public:
    Task3(bool verbose);
    //Реализовать  алгоритм вычисления порога бинаризации методом Оцу
    cv::Mat Otsu(cv::Mat grayimage,float &threshold);

    //Реализовать алгоритм адаптивной бинаризации по порогу
    cv::Mat adaptiveBinary(cv::Mat grayimage,int filter_size,int c);
    //Реализовать алгоритм разметки бинарного изображения
    cv::Mat labelImage(cv::Mat binimage);

    //Реализовать алгоритм расчета расстояния до границы (Distance transform)
    cv::Mat distanceTransform(cv::Mat binimage);
    //Реализовать детектор краев Кенни
    cv::Mat Canny(cv::Mat grayimage,int low_th,int high_th);
    //Реализовать алгоритм сегментации методом водораздела (Watershed)
    cv::Mat watershed(cv::Mat grayimage);
};
}

#endif // TASK3_H
