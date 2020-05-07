#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string.h>

class mouseInterface
{
public:

    static void mouse_CallBackFunc(int event, int x, int y, int flags, void *userdata)
    {
        if (event == cv::EVENT_LBUTTONDOWN)
        {
            std::cout << "userdata = " << userdata << std::endl;
            std::cout << "flag = " << flags << std::endl;
            std::cout << "왼쪽 마우스 버튼 클릭.. 좌표 = (" << x << ", " << y << ")" << std::endl;
        }
    };

    int runloop();
    
    std::string user_path = "/home/cona/";
    std::string file_path = "tm_gui/src/mouse/data/test.png";
    std::string path = user_path + file_path;
    
    mouseInterface()
    {
        runloop();
    }

    ~mouseInterface()
    {
    }
};