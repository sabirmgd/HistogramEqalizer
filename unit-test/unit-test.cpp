#include <stdio.h>
#include "histogram_equalizer.h"
#include "histogram_equalizer.cpp"
#include <gtest/gtest.h>



using namespace std;
using namespace cv;


TEST(EqualizerTest, NON_U16_image) {
	
	string eight_bits_image = "../../unit-test/8bit.jpg";
	Mat img = imread(eight_bits_image, CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);

	if (!img.data)
	{
		std::cout << "Image not loaded";

	}
	
	ASSERT_EXIT(HistogramEqualizer::equalizeHist_16U(img), ::testing::ExitedWithCode(-1), "Error: this is not a 16 bit image, you can use calcHist opencv native function for 8 bits images");
}


TEST(EqualizerTest, colored_image) {

	string sixteen_bit_image = "../../unit-test/16bit_colored.tif";
	Mat img2 = imread(sixteen_bit_image, CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);

	if (!img2.data)
	{
		std::cout << "Image not loaded";

	}
	ASSERT_EXIT(HistogramEqualizer::equalizeHist_16U(img2), ::testing::ExitedWithCode(-1), "Error: this is a colored image, please choose grey image");
}

