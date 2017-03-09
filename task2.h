#ifndef TASK2_H
#define TASK2_H

#include "commun_task.h"
/*!
 * Пространство имен, соответсвующее этому году
 */
namespace mvms_2017
{
class Task2 : public Commun_Task
{
public:
    /*!
     * \brief Task2 задачи по теме обработка изображений
     * \param verbose
     */
    Task2(bool verbose);
    /*!
     * \brief mean Реализовать свертку изображения. Написать усредняющий фильтр
     * \param image Изображение
     * \param filter_size размер усредняющего фильтра
     * \return
     */
    cv::Mat mean(cv::Mat image,int filter_size);
    /*!
     * \brief gauss Реализовать свертку изображения. Сглаживающий фильтр Гаусса
     * \param image Изображение
     * \param filter_size размер фильтра Гаусса
     * \param sigma Дисперсия фильтра гаусса
     * \return
     */
    cv::Mat gauss(cv::Mat image,int filter_size,float sigma);
    /*!
     * \brief sobel Реализовать свертку изображения. Дифференцирующий фильтр Собеля 3x3
     * \param image Изображение
     * \param dir напраление дифференцирования 0 - dI/dx, 1 - dI/dy
     * \return
     */
    cv::Mat sobel(cv::Mat image,int dir);
    /*!
     * \brief median Реализовать медианный фильтр
     * \param image Изображение
     * \param filter_size размер медианного фильтра
     * \return
     */
    cv::Mat median(cv::Mat image,int filter_size);
    /*!
     * \brief histeq Реализовать алгоритм эквализации гистограммы
     * \param image Изображение полутоновое
     * \param nbins количество карманов в эквализированной гистограмме
     * \return
     */
    cv::Mat histeq(cv::Mat image,int nbins);
    /*!
     * \brief addnoises Наложить на изображение нормальный шум с заданной дисперсией и средним значением и шум соль/перец.
     * \param image Изображение
     * \param sigma Дисперсия нормального шума
     * \param solt_prob Вероятность получения белого пикселя из равномерного распределения
     * \param papper_prob Вероятность получения черного пикселя из равномерного распределения
     * \return
     */
    cv::Mat addnoises(cv::Mat image,float sigma,int solt_prob,int papper_prob);
};
}

#endif // TASK2_H
