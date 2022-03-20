#include <QCoreApplication>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>


#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void thread_entry()
{

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    while(true)
    {

        end = std::chrono::system_clock::now();
        std::chrono::duration<double> duration = end-start;

        //std::cout << duration.count() << "s" << std::endl;

        if(duration.count() > 2)
        {
            cout<< "---------------------------------" << endl;

            std::cout << duration.count() << " seconds" << std::endl;
            start = std::chrono::system_clock::now();

            //auto start = std::chrono::system_clock::now();

        } // 2 segundos

    }
    // Do something with that, I guess
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Elsewhere in some part of the galaxy
    std::thread thread(thread_entry);
    // And probably
    thread.detach();


    VideoCapture cap;
    cap.open("http://90.171.76.53/mjpg/video.mjpg");
    Mat img;
    namedWindow("in",0);
    char key;
    while(true)
    {
        if(cap.isOpened())
        {
            cap >> img;

            if(!img.empty())
            {
                imshow("in", img);
                key = waitKey(1);
                if(key == 'q' || key == 'Q' || key == 'S' || key == 's')
                {
                    break;
                } // key q s salir
            }

        } // cap open

    } // while true


    // Or
    //std::thread(thread_entry).detach();


    destroyAllWindows();

    return 0;
}











