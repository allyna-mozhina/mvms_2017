#pragma once

#include "task1.h"

namespace mvms_2017
{
    class Mozhina_Alina_201731143_Task1 : public Task1
    {
    private:
        const int VARIANT = 201731143;
        const std::string FIRST_NAME = "Алина";
        const std::string LAST_NAME = "Можина";

        void setPixel(cv::Mat &image, float x1, float y1, int rgb);
        void drawLine(cv::Mat &image, float x1, float y1, float x2, float y2);
        
    public:
        int variant() override;
        std::string getFirstName() override;
        std::string getSecondName() override;

        cv::Mat drawTriangle(std::string filename, float x1, float y1, float x2, float y2, float x3, float y3) override;
    };
}