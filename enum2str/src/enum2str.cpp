//============================================================================
// Name        : enum2str.cpp
// Author      : frv
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>

#include <chrono>

enum class TrafficType {
    Invalid, FullBuffer, VideoStream, Http, Iot
};

std::string TrafficType_enum2str(TrafficType value) {
    static const std::map<TrafficType, std::string> mappingTable = {
    		{TrafficType::FullBuffer , "full_buffer"},
			{TrafficType::VideoStream, "video"},
			{TrafficType::Http       , "http"},
            {TrafficType::Iot        , "iot"}
    };

    auto it = mappingTable.find(value);
    if (it != mappingTable.end())
    	return it->second;

	return "invalid";
}

TrafficType TrafficType_str2enum(const std::string& str) {
    static const std::map<std::string, TrafficType> mappingTable = {
    		{"full_buffer", TrafficType::FullBuffer },
			{"video"      , TrafficType::VideoStream },
			{"http"       , TrafficType::Http },
            {"iot"        , TrafficType::Iot}
    };

    auto it = mappingTable.find(str);
    if (it != mappingTable.end())
    	return it->second;

    return TrafficType::Invalid;
}

TrafficType TrafficType_str2enum_v0(const std::string& str)
{
	TrafficType result = TrafficType::FullBuffer;
    if (str == "full_buffer")
    	result = TrafficType::FullBuffer;
    else if (str == "video")
    	result = TrafficType::VideoStream;
    else if (str == "http")
		result = TrafficType::Http;
    else if (str == "iot")
		result = TrafficType::Iot;
	else
		result = TrafficType::Invalid;

    return result;
}


int main() {
    std::cout << "!!!Hello World!!!" << std::endl;

    std::string test_var = "http";

    TrafficType enum_var;

    using milli = std::chrono::milliseconds;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
    {
    	enum_var = TrafficType_str2enum(test_var);
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "str2enum() took "
                  << std::chrono::duration_cast<milli>(finish - start).count()
                  << " milliseconds\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++)
    {
    	enum_var = TrafficType_str2enum_v0(test_var);
    }
    finish = std::chrono::high_resolution_clock::now();
    std::cout << "str2enum_v0() took "
                  << std::chrono::duration_cast<milli>(finish - start).count()
                  << " milliseconds\n";

    std::cout << "As string: " << TrafficType_enum2str(enum_var) << std::endl;

    return 0;
}
