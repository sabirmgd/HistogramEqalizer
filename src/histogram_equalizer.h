#pragma once
#include <opencv2/opencv.hpp>
using namespace cv;
class HistogramEqualizer
{
public:
	static void compute_hist_16U(Mat &img, long* hist);
	static void equalizeHist_16U(Mat &img);
	HistogramEqualizer();
	~HistogramEqualizer();
};

