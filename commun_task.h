#ifndef COMMUN_TASK_H
#define COMMUN_TASK_H

#include <string>
#include <opencv2/opencv.hpp>

namespace mvms_2017
{
class Commun_Task{
public:
    ~Commun_Task(){}
    /* Вариант. Возвращает число, указанное в письме
     */
    virtual int variant(){
        return 201700000;
    }

    /*!
     * \brief getFirstName
     * \return Возвращает имя студента
     */
    virtual std::string getFirstName(){
        return "Виктор";
    }

    /*!
     * \brief getSecondName
     * \return Возвращает фамилию студента
     */
    virtual std::string getSecondName(){
        return "Куликов";
    }
protected:
    //Флаг для отладки (если установлен на false - нельзя рисовать или прирывать исполнение)
    bool _verbose;
};
}

#endif // COMMUN_TASK_H
