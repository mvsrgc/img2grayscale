#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <in-path> <out-path>" << std::endl;
        return -1;
    }
    
    const std::string inPath = argv[1];
    const std::string outPath = argv[2];

    auto img = cv::imread(inPath, cv::IMREAD_UNCHANGED);
    if (img.empty()) {
        std::cerr << "Failed to open image file." << std::endl;
        return -1;
    }
    
    const auto width = img.cols;
    const auto height = img.rows;
    
    std::cout << "Found image: " << inPath << std::endl;
    std::cout << "Image width: " << width << ", Image height: " << height << std::endl;
    
    cv::Mat gray_img(img.rows, img.cols, CV_8UC1);
    
    for (int i = 0; i < img.total(); ++i) {
        auto* pixel = &img.data[i * 3];
        uchar gray_value = static_cast<uchar>(0.299f * pixel[2] + 0.587f * pixel[1] + 0.114f * pixel[0]);
        gray_img.data[i] = gray_value;
    }
    
    if (!cv::imwrite(outPath, gray_img)) {
        std::cerr << "Failed to write image file: " << outPath << std::endl;
        return -1;
    }

    std::cout << "Wrote grayscale image: " << outPath << std::endl;

    return 0;
}