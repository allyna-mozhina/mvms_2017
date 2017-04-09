#include "Mozhina_Alina_201731143_Task2.h"

namespace mvms_2017
{
    Color::Color(float red, float green, float blue) : red(red), green(green), blue(blue)
    {

    }

    Filter Mozhina_Alina_201731143_Task2::computeGauss(int filter_size, float sigma) const
    {
        Filter gaussFilter(filter_size, std::vector<float>(filter_size, 0));

        float sum = 0;

        for (int i = 0; i < filter_size; ++i)
            for (int j = 0; j < filter_size; ++j)
            {
                gaussFilter[i][j] = expf(-(i * i + j * j) / (2 * sigma * sigma)) / (2 * M_PI * sigma * sigma);
                sum += gaussFilter[i][j];
            }

        for (int i = 0; i < filter_size; ++i)
            for (int j = 0; j < filter_size; ++j)
                gaussFilter[i][j] /= sum;

        return std::move(gaussFilter);
    }

    void Mozhina_Alina_201731143_Task2::setPixel(cv::Mat &image, int x, int y, Color rgb) const
    {
        auto color = image.at<cv::Vec3f>(cv::Point(x, y));

        color[2] = rgb.red;
        color[1] = rgb.green;
        color[0] = rgb.blue;

        image.at<cv::Vec3f>(cv::Point(x, y)) = color;
    }

    Color Mozhina_Alina_201731143_Task2::getPixel(const cv::Mat &image, int x, int y) const
    {
        auto color = image.at<cv::Vec3b>(cv::Point(x, y));

        return Color(color[2], color[1], color[0]);
    }

    Color Mozhina_Alina_201731143_Task2::convolution(cv::Mat &image, const Filter &filter, int x, int y) const
    {
        float rsum = 0, gsum = 0, bsum = 0;

        int fwidth = filter[0].size();
        int fheight = filter.size();

        for (int i = 0; i < fwidth; ++i)
            for (int j = 0; j < fheight; ++j)
            {
                int dx = i - fwidth / 2;
                int dy = j - fheight / 2;

                Color color = getPixel(image, x + dx, y + dy);

                rsum += color.red * filter[i][j];
                gsum += color.green * filter[i][j];
                bsum += color.blue * filter[i][j];
            }

        return Color(rsum, gsum, bsum);
    }

    cv::Mat Mozhina_Alina_201731143_Task2::applyFilter(cv::Mat &image, const Filter &filter) const
    {
        int fwidth = filter[0].size();
        int fheight = filter.size();

        cv::Mat filtered(image.size().height - (fheight - 1), 
                         image.size().width - (fwidth - 1),
                         CV_32FC3);
        
        auto size = filtered.size();

        for (int x = 0; x < size.width; ++x)
            for (int y = 0; y < size.height; ++y)
            {
                Color color = convolution(image, filter, x + fwidth / 2, y + fheight / 2);
                setPixel(filtered, x, y, color);
            }

        return std::move(filtered);
    }

    Mozhina_Alina_201731143_Task2::Mozhina_Alina_201731143_Task2(bool verbose) : Task2(verbose)
    {

    }

    int Mozhina_Alina_201731143_Task2::variant()
    {
        return VARIANT;
    }

    std::string Mozhina_Alina_201731143_Task2::getFirstName()
    {
        return FIRST_NAME;
    }

    std::string Mozhina_Alina_201731143_Task2::getSecondName()
    {
        return LAST_NAME;
    }

    cv::Mat Mozhina_Alina_201731143_Task2::gauss(cv::Mat image, int filter_size, float sigma)
    {
        Filter gaussFilter = computeGauss(filter_size, sigma);

        auto result = applyFilter(image, gaussFilter);
        result.convertTo(result, CV_8U);
        return result;
    }
}