#include "mouse/mouse.hpp"

int mouseInterface::runloop()
{
    cv::Mat img_original, img_gray;

    //이미지파일을 로드하여 image에 저장
    img_original = cv::imread(mouseInterface::path, cv::IMREAD_COLOR);
    if (img_original.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    //그레이스케일 이미지로 변환
    cv::cvtColor(img_original, img_gray, cv::COLOR_BGR2GRAY);

    //윈도우 생성
    cv::namedWindow("original image", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("gray image", cv::WINDOW_AUTOSIZE);

    //윈도우에 출력
    cv::imshow("original image", img_original);
    cv::imshow("gray image", img_gray);

    //윈도우에 콜백함수를 등록
    cv::setMouseCallback("gray image", mouseInterface::mouse_CallBackFunc, NULL);

    //키보드 입력이 될때까지 대기
    cv::waitKey(0);
}

int main(int argc, char **argv)
{
    mouseInterface mouse = mouseInterface();

    return 0;
}
