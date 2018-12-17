#include "histogram_equalizer.h"

void HistogramEqualizer::compute_hist_16U(Mat & img, long* hist)
{
	unsigned short i, j;
	long* b;


	if (2 != img.depth()) {
		std::cerr << "Error: this is not a 16 bit image, you can use calcHist opencv native function for 8 bits images\n";
		exit(-1);
	}
	
	if (img.channels() != 1) { //colored
		std::cerr << "Error: this is a colored image, please choose grey image\n";
		exit(-1);
	}

	
	for (i = 0; i <= img.cols - 1; i++)
	{
		for (j = 0; j <= img.rows - 1; j++)
		{
			hist[img.at<unsigned short>(j, i)]++;
		}
	}

	//calculate cumulative histogram
	for (b = hist; b<hist + 65535; b++)
	{
		*(b + 1) += *b;
	}
}

void HistogramEqualizer::equalizeHist_16U(Mat & img)
{
	long hist[65536] = { 0 };
	int i, j;

	//assert(img.channels() == 1);
	//assert(img.type() == CV_16U);

	HistogramEqualizer::compute_hist_16U(img, hist);

	for (i = 0; i <= img.cols - 1; i++)
	{
		for (j = 0; j <= img.rows - 1; j++)
		{
			img.at<unsigned short>(j, i) = 65535.0*hist[img.at<unsigned short>(j, i)] / (img.cols*img.rows);
		}
	}
}

HistogramEqualizer::HistogramEqualizer()
{
}

HistogramEqualizer::~HistogramEqualizer()
{
}
