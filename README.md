# 16 Bit Images Histogram Equalization

This project is a simple histogram equalizer for 16 bit images.

# Motivation

OpenCV (Open Source Computer Vision Library) is an open source computer vision and machine learning software library. It allows you to do process your images and do cool stuff such as object tracking, face recofnition etc. Most of the OpenCV functions cater for 8 bits images (perhaps for performance issues) and they don't cater for 16 bits images. 

One example of these functions in OpenCV is calcHist, what it does basically is that, it reads and 8 bits image and calculte the histogram. This simple project has a 16 bit histogram equalizer instead for your 16 bits images.

# Background:
### Histogram Equalization:

I couldn't find better words to describe Histogram Equalization than what Wikipedia has, so I am going to to quote the definition from Wikipedia:

> Histogram equalization is a method in image processing of contrast
> adjustment using the image's histogram. This method usually increases
> the global contrast of many images, especially when the usable data of
> the image is represented by close contrast values. Through this
> adjustment, the intensities can be better distributed on the
> histogram. This allows for areas of lower local contrast to gain a
> higher contrast. Histogram equalization accomplishes this by
> effectively spreading out the most frequent intensity values.

### Difference between 8 bit images and 16 bit images:
The difference between 8 is the amount of tones available for each color, in the case of 8 bits images, the amount of available tones is (2 to the power 8 ) which is 256, while for 16 bits images, the available amount of tones for each color is (2 to the power 16 ) which is 65536.


##  Tech/framework used

This project is built in:
- Visual Studio 
- C++
- OpenCV 3.3.1
- CMake 3.10.0
- Google Test


## Installation

In order to be able to use this code, you need to have CMake and OpenCV installed, because you need to build the app with CMake, and the top level CMakeLists.txt includes the open CV include directories as follow :

    set(COMMON_INCLUDES ${OpenCV_INCLUDE_DIRS})

In the Project directory , create a build directory:

    #create build directory
	[HistogramEqualizer] $ mkdir build
	[HistogramEqualizer] $ cd build
	#create Visual Studio project files using cmake
	[HistogramEqualizer/build] $ cmake -G "Visual Studio 14 2015 Win64" ..

now build the application:

    # build the application
	[HistogramEqualizer/build]$ cmake --build . --config Release
	#once the build is complete, it will generate exe file in build\Release directory


## Usage

after the installation is done, you can simply use the application by passing the image you want to calculate the histogram for as a parameter, from the project directory:

    [HistogramEqualizer]$./build/src/Release/histogram_equalizer.exe "16bit_grayscale.TIF"

you can replace the image file name "16bit_grayscale.TIF" in this case with your image 


## Sample input and outputs:

**Successful scenario :**

     [HistogramEqualizer]$./build/src/Release/histogram_equalizer.exe "16bit_grayscale.TIF"

a new file **output.TIF**  will be generated having the  output.


**In case its a colored image:** 

    [HistogramEqualizer]$./build/src/Release/histogram_equalizer.exe "16bit_colored.tif"

The output:

    Error: this is a colored image, please choose grey image

**In case of a non-16bit image:**


    [HistogramEqualizer]$./build/src/Release/histogram_equalizer.exe "8bit.jpg"

the output:

    Error: this is not a 16 bit image, you can use calcHist opencv native function for 8 bits images
