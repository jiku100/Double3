// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2019 Intel Corporation. All Rights Reserved.

#include <librealsense2/rs.hpp> // Include RealSense Cross Platform API
#include <opencv2/opencv.hpp>  // Include main OpenCV header
#include <iostream>             // for cout
#include <string>

// Hello RealSense example demonstrates the basics of connecting to a RealSense device
// and taking advantage of depth data
int main(int argc, char * argv[]) 
try
{
    rs2::pipeline pipe;
    rs2::config cfg;

    cfg.enable_device("213322070551");
    
    cfg.enable_stream(RS2_STREAM_INFRARED, 640, 480, RS2_FORMAT_Y8, 30);
    cfg.enable_stream(RS2_STREAM_DEPTH, 640, 480, RS2_FORMAT_Z16, 30);

    pipe.start(cfg);

    rs2::frameset frames;
    for(int i = 0; i < 30; i++)
    {
        frames = pipe.wait_for_frames();
    }

    rs2::frame ir_frame = frames.first(RS2_STREAM_INFRARED);
    rs2::frame depth_frame = frames.get_depth_frame();

    // Creating OpenCV Matrix from a color image
    cv::Mat ir(cv::Size(640, 480), CV_8UC1, (void*)ir_frame.get_data(), cv::Mat::AUTO_STEP);

    equalizeHist( ir, ir );
    applyColorMap(ir, ir, cv::COLORMAP_JET);

    cv::Mat depth(cv::Size(640, 480), CV_8UC1, (void*)depth_frame.get_data(), cv::Mat::AUTO_STEP);
    
    cv::imwrite("front_ir.png", ir);
    cv::imwrite("front_depth.png", depth);

    return EXIT_SUCCESS;
}
catch (const rs2::error & e)
{
    std::cerr << "RealSense error calling " << e.get_failed_function() << "(" << e.get_failed_args() << "):\n    " << e.what() << std::endl;
    return EXIT_FAILURE;
}
catch (const std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}