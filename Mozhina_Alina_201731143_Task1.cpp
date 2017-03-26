#include "Mozhina_Alina_201731143_Task1.h"

namespace mvms_2017
{
    void Mozhina_Alina_201731143_Task1::setPixel(cv::Mat &image, float x1, float y1, int rgb)
    {
        cv::Vec3b color = image.at<cv::Vec3b>(cv::Point(x1, y1));

        color[2] = (rgb >> 16) & 0xFF;
        color[1] = (rgb >> 8) & 0xFF;
        color[0] = rgb & 0xFF;

        image.at<cv::Vec3b>(cv::Point(x1, y1)) = color;
    }

    void Mozhina_Alina_201731143_Task1::drawLine(cv::Mat &image, float x1, float y1, float x2, float y2, int rgb)
    {
        int dx = std::abs(x2 - x1), dy = std::abs(y2 - y1);
        int err = 0;

        if (dy <= dx)
        {            
            float start_x = x1 < x2 ? x1 : x2, start_y = x1 < x2 ? y1 : y2;
            float end_x = x1 >= x2 ? x1 : x2, end_y = x1 >= x2 ? y1 : y2;

            float y = start_y;
            int step = start_y < end_y ? 1 : -1;

            for (float x = start_x; x <= end_x; ++x)
            {
                setPixel(image, x, y, rgb);
                
                err += dy;
                if (2 * err > dx)
                {
                    y += step;
                    err -= dx;
                }
            }
        }
        else
        {
            float start_x = y1 > y2 ? x1 : x2, start_y = y1 > y2 ? y1 : y2;
            float end_x = y1 <= y2 ? x1 : x2, end_y = y1 <= y2 ? y1 : y2;

            float x = start_x;
            int step = start_x < end_x ? 1 : -1;

            for (float y = start_y; y >= end_y; --y)
            {
                setPixel(image, x, y, rgb);
                
                err += dx;
                if (2 * err > dy)
                {
                    x += step;
                    err -= dy;
                }
            }
        }
    }

    Mozhina_Alina_201731143_Task1::Mozhina_Alina_201731143_Task1(bool verbose) : Task1(verbose)
    {

    }

    int Mozhina_Alina_201731143_Task1::variant()
    {
        return VARIANT;
    }

    std::string Mozhina_Alina_201731143_Task1::getFirstName()
    {
        return FIRST_NAME;
    }

    std::string Mozhina_Alina_201731143_Task1::getSecondName()
    {
        return LAST_NAME;
    }

    cv::Mat Mozhina_Alina_201731143_Task1::drawTriangle(std::string filename, float x1, float y1, 
                                                                              float x2, float y2, 
                                                                              float x3, float y3)
    {
        cv::Mat image = cv::imread(filename, CV_LOAD_IMAGE_COLOR);

        drawLine(image, x1, y1, x2, y2, LINE_COLOR);
        drawLine(image, x2, y2, x3, y3, LINE_COLOR);
        drawLine(image, x3, y3, x1, y1, LINE_COLOR);

        return image;
    }
}