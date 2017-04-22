#include "Mozhina_Alina_201731143_Task3.h"

namespace mvms_2017
{
    Filter Mozhina_Alina_201731143_Task3::computeMean(int filter_size) const
    {
        return Filter(filter_size, std::vector<float>(filter_size, 1.0 / (filter_size * filter_size)));
    }

    void Mozhina_Alina_201731143_Task3::setPixel(cv::Mat &image, int x, int y, uchar intensity) const
    {
        image.at<uchar>(cv::Point(x, y)) = intensity;
    }

    uchar Mozhina_Alina_201731143_Task3::getPixel(cv::Mat &image, int x, int y) const
    {
        return image.at<uchar>(cv::Point(x, y));
    }

    float Mozhina_Alina_201731143_Task3::convolution(cv::Mat &image, const Filter &filter, int x, int y) const
    {
        float sum = 0;

        int fwidth = filter[0].size();
        int fheight = filter.size();

        for (int i = 0; i < fwidth; ++i)
            for (int j = 0; j < fheight; ++j)
            {
                int dx = i - fwidth / 2;
                int dy = j - fheight / 2;

                if (0 > x + dx || x + dx > image.size().width ||
                    0 > y + dy || y + dy > image.size().height)
                    continue;

                uchar intensity = getPixel(image, x + dx, y + dy);

                sum += intensity * filter[i][j];
            }

        return sum;
    }

    cv::Mat Mozhina_Alina_201731143_Task3::applyFilter(cv::Mat &image, const Filter &filter, int c) const
    {
        cv::Mat filtered(image.size(), image.type());

        auto size = filtered.size();

        for (int x = 0; x < size.width; ++x)
            for (int y = 0; y < size.height; ++y)
            {
                float threshold = convolution(image, filter, x, y);

                uchar intensity = 0;

                if (getPixel(image, x, y) > threshold - c)
                    intensity = 255;

                setPixel(filtered, x, y, intensity);
            }

        return std::move(filtered);
    }

    Mozhina_Alina_201731143_Task3::Mozhina_Alina_201731143_Task3(bool verbose) : Task3(verbose)
    {

    }

    int Mozhina_Alina_201731143_Task3::variant()
    {
        return VARIANT;
    }

    std::string Mozhina_Alina_201731143_Task3::getFirstName()
    {
        return FIRST_NAME;
    }

    std::string Mozhina_Alina_201731143_Task3::getSecondName()
    {
        return LAST_NAME;
    }

    cv::Mat Mozhina_Alina_201731143_Task3::adaptiveBinary(cv::Mat grayimage, int filter_size, int c)
    {
        Filter meanFilter = computeMean(filter_size);

        return applyFilter(grayimage, meanFilter, c);
    }
}