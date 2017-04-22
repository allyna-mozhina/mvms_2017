#pragma once

#include "task3.h"

namespace mvms_2017
{
    using Filter = std::vector<std::vector<float>>;

    class Mozhina_Alina_201731143_Task3 : public Task3
    {
    private:
        const int VARIANT = 201731143;
        const std::string FIRST_NAME = "Алина";
        const std::string LAST_NAME = "Можина";

        Filter computeMean(int filter_size) const;
        
        void setPixel(cv::Mat &image, int x, int y, uchar intensity) const;
        uchar getPixel(cv::Mat &image, int x, int y) const;

        float convolution(cv::Mat &image, const Filter &filter, int x, int y) const;
        cv::Mat applyFilter(cv::Mat &image, const Filter &filter, int c) const;

    public:
        Mozhina_Alina_201731143_Task3(bool verbose);

        int variant() override;
        std::string getFirstName() override;
        std::string getSecondName() override;

        cv::Mat adaptiveBinary(cv::Mat grayimage, int filter_size, int c);
    };
}