/*
 * global_types.h
 *
 *  Created on: Apr 5, 2018
 *      Author: fernando
 */

#ifndef GLOBAL_TYPES_H_
#define GLOBAL_TYPES_H_

#include <iostream>

enum class TrafficType {
    Invalid, FullBuffer, VideoStream, Http, Iot
};

/**
 * Convert a TrafficType to the corresponding string
 * @param value a TrafficType
 * @return a string. In case of out of range or unknown value returns invalid
 */
std::string TrafficType_enum2str(TrafficType value);

/**
 *
 * @param str
 * @return
 */
TrafficType TrafficType_str2enum(const std::string& str);

/**
 *
 * @param str
 * @return
 */
TrafficType TrafficType_str2enum_v0(const std::string& str);

#endif /* GLOBAL_TYPES_H_ */
