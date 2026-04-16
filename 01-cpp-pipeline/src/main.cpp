#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Enter an image path" << std::endl;
		return (1);
	}
	cv::Mat image = cv::imread(argv[1]);
	if (image.empty())
	{
		std::cout << "Image is Empty" << std::endl;
		return (1);
	}
	std::cout << "Width       " << image.cols << std::endl;
	std::cout << "Height      " << image.rows << std::endl;
	std::cout << "Channels    " << image.channels() << std::endl;\
	std::cout << "Total Bytes " << image.total() * image.elemSize() << std::endl;


	cv::Mat gray;
	cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
	std::cout << "Gray Channels " << gray.channels() << std::endl;

	std::cout << "Creating GrayScale Image..." << std::endl;
	cv::imwrite("../GrayScale.jpg", gray);
	std::cout << "Done" << std::endl;

	cv::Mat blurred;
	std::cout << "Blurring image..." << std::endl;
	cv::GaussianBlur(gray, blurred, cv::Size(15,15), 0);
	cv::imwrite("../blurred.jpg", gray);
	std::cout << "Done" << std::endl;
	return (0);
}