/*
 * global_types.cpp
 *
 *  Created on: Apr 5, 2018
 *      Author: fernando
 */
#include "global_types.h"

#include <map>

std::string TrafficType_enum2str(TrafficType value) {
    static const std::map<TrafficType, std::string> mappingTable = { {
            TrafficType::FullBuffer, "full_buffer" }, {
            TrafficType::VideoStream, "video" }, { TrafficType::Http, "http" },
            { TrafficType::Iot, "iot" } };

    auto it = mappingTable.find(value);
    if (it != mappingTable.end())
        return it->second;

    return "invalid";
}

TrafficType TrafficType_str2enum(const std::string& str) {
    static const std::map<std::string, TrafficType> mappingTable = { {
            "full_buffer", TrafficType::FullBuffer }, { "video",
            TrafficType::VideoStream }, { "http", TrafficType::Http }, { "iot",
            TrafficType::Iot } };

    auto it = mappingTable.find(str);
    if (it != mappingTable.end())
        return it->second;

    return TrafficType::Invalid;
}

TrafficType TrafficType_str2enum_v0(const std::string& str) {
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

