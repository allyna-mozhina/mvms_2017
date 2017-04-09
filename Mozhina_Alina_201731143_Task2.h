#pragma once

#define _USE_MATH_DEFINES

#include <cmath>

#include "task2.h"

namespace mvms_2017
{
    struct Color
    {
        float red, green, blue;
        Color(float red, float green, float blue);
    };

    using Filter = std::vector<std::vector<float>>;

    class Mozhina_Alina_201731143_Task2 : public Task2
    {
    private:
        const int VARIANT = 201731143;
        const std::string FIRST_NAME = "Алина";
        const std::string LAST_NAME = "Можина";

        Filter computeGauss(int filter_size, float sigma);

        void setPixel(cv::Mat &image, int x, int y, Color rgb);
        Color getPixel(const cv::Mat &image, int x, int y);

        Color convolution(cv::Mat &image, const Filter &filter, int x, int y);
        cv::Mat applyFilter(cv::Mat &image, const Filter &filter);
 
    public:
        Mozhina_Alina_201731143_Task2(bool verbose);

        int variant() override;
        std::string getFirstName() override;
        std::string getSecondName() override;

        cv::Mat gauss(cv::Mat image, int filter_size, float sigma);
    };
}
