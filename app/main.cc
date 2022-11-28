#include <iostream>

#include <catch2/catch.hpp>
#include <cxxopts.hpp>
#include <fmt/format.h>
#include <range/v3/view.hpp>

#include <httplib.h>
#include <json/json.h>
#include <nadjieb/mjpeg_streamer.hpp>
#include <open62541/server.h>
#include <opencv2/opencv.hpp>

#include "my_lib.h"

int main(int argc, char **argv)
{
    std::cout << "CV: " << CV_VERSION << '\n';
    std::cout << "JSON: " << JSONCPP_VERSION_STRING << '\n';
    std::cout << "UA: " << UA_OPEN62541_VER_COMMIT << '\n';
    std::cout << "MJPEG: " << NADJIEB_MJPEG_STREAMER_VERSION_STRING << '\n';
    std::cout << "Range: " << RANGE_V3_VERSION << '\n';
    std::cout << "FMT: " << FMT_VERSION << '\n';
    std::cout << "CXXOPTS: " << CXXOPTS__VERSION_MAJOR << '\n';
    std::cout << "Catch: " << CATCH_VERSION_MAJOR << '\n';

    print_hello_world();
}
