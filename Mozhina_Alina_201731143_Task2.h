#pragma once

#include "task2.h"

namespace mvms_2017
{
    struct Color
    {
        float red, green, blue;
        Color(float red, float green, float blue);
    };

    class Mozhina_Alina_201731143_Task2 : public Task2
    {
    private:
        const int VARIANT = 201731143;
        const std::string FIRST_NAME = "Алина";
        const std::string LAST_NAME = "Можина";

        using Filter = std::vector<std::vector<double>>;
        Filter computeGauss(int filter_size, float sigma) const;

        void setPixel(cv::Mat &image, float x, float y, Color rgb) const;
        Color getPixel(cv::Mat &image, float x, float y) const;

        Color convolution(cv::Mat &image, const Filter &filter, float x, float y) const;
        cv::Mat convolution(cv::Mat &image, const Filter &filter) const;
 
    public:
        Mozhina_Alina_201731143_Task2(bool verbose);

        int variant() override;
        std::string getFirstName() override;
        std::string getSecondName() override;

        cv::Mat gauss(cv::Mat image, int filter_size, float sigma);
    };
}
