#include "Mozhina_Alina_201731143_Task5.h"

namespace mvms_2017
{
    Mozhina_Alina_201731143_Task5::Color::Color(float red, float green, float blue) : red(red), green(green), blue(blue)
    {

    }

    void Mozhina_Alina_201731143_Task5::setPixel(cv::Mat &image, int x, int y, Color rgb) const
    {
        auto color = image.at<cv::Vec3f>(cv::Point(x, y));

        color[2] = rgb.red;
        color[1] = rgb.green;
        color[0] = rgb.blue;

        image.at<cv::Vec3f>(cv::Point(x, y)) = color;
    }

    Mozhina_Alina_201731143_Task5::Color Mozhina_Alina_201731143_Task5::getPixel(const cv::Mat &image, int x, int y) const
    {
        auto color = image.at<cv::Vec3b>(cv::Point(x, y));

        return Color(color[2], color[1], color[0]);
    }

    Mozhina_Alina_201731143_Task5::Mozhina_Alina_201731143_Task5(bool verbose) : Task5(verbose)
    {

    }

    int Mozhina_Alina_201731143_Task5::variant()
    {
        return VARIANT;
    }

    std::string Mozhina_Alina_201731143_Task5::getFirstName()
    {
        return FIRST_NAME;
    }

    std::string Mozhina_Alina_201731143_Task5::getSecondName()
    {
        return LAST_NAME;
    }

    cv::Mat Mozhina_Alina_201731143_Task5::correctLensDistorsions(cv::Mat image, double r2, double r4, double k1, double k2)
    {
        cv::Mat corrected(image.size(), CV_32FC3);
        
        auto size = image.size();

        float center_x = size.width / 2;
        float center_y = size.height / 2;

        for (int x = 0; x < size.width; ++x)
            for (int y = 0; y < size.height; ++y)
            {
                Color color = getPixel(image, x, y);

                float rx = (x - center_x) / size.width;
                float ry = (y - center_y) / size.height;

                float center_dist2 = rx * rx + ry * ry;

                float radial_factor = 1 + r2 * center_dist2 + r4 * center_dist2 * center_dist2;

                float corrected_rx = rx * radial_factor + (2 * k1 * rx * ry + k2 * (center_dist2 + 2 * rx * rx));
                float corrected_ry = ry * radial_factor + (k1 * (center_dist2 + 2 * ry * ry) + 2 * k2 * rx * ry);

                int corrected_x = (corrected_rx * size.width) + center_x;
                int corrected_y = (corrected_ry * size.height) + center_y;

                if (0 > corrected_x || corrected_x >= size.width ||
                    0 > corrected_y || corrected_y >= size.height)
                    continue;

                setPixel(corrected, corrected_x, corrected_y, color);
            }

        return std::move(corrected);
    }
}