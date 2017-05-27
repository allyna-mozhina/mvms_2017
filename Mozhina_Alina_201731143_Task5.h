#pragma once

#include "task5.h"

namespace mvms_2017
{ 
    class Mozhina_Alina_201731143_Task5 : public Task5
    {
    public:
        struct Color
        {
            float red, green, blue;
            Color(float red, float green, float blue);
        };

    private:
        const int VARIANT = 201731143;
        const std::string FIRST_NAME = "Алина";
        const std::string LAST_NAME = "Можина";

        void setPixel(cv::Mat &image, int x, int y, Color rgb) const;
        Color getPixel(const cv::Mat &image, int x, int y) const;

    public:
        Mozhina_Alina_201731143_Task5(bool verbose);

        int variant() override;
        std::string getFirstName() override;
        std::string getSecondName() override;
        
        cv::Mat correctLensDistorsions(cv::Mat image, double r2, double r4, double k1, double k2);
    };
}