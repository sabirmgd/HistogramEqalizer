#include "histogram_equalizer.h"

using namespace std;
int main(int argc, char** argv )
{
	string imgFileName = argv[1];
	Mat img = imread(imgFileName, CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
	if (!img.data)
	{
		std::cout << "Image not loaded";
		return -1;
	}
	

	imwrite("input.TIF", img);
	//equalize histogram 
	HistogramEqualizer::equalizeHist_16U(img);

    // save Result
	imwrite("output.TIF", img);
	
	waitKey(0); // Wait for any keystroke in the window


}
