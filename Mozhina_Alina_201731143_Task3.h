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

        short convolution(cv::Mat &image, const Filter &filter, int x, int y) const;

    public:
        Mozhina_Alina_201731143_Task3(bool verbose);

        int variant() override;
        std::string getFirstName() override;
        std::string getSecondName() override;

        cv::Mat adaptiveBinary(cv::Mat grayimage, int filter_size, int c);
    };
}