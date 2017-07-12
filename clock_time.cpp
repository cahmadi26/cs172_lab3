/*
 * clock_time.cpp
 *
 *  Created on: Jul 12, 2017
 *      Author: yashkalebere
 */

#include "clock_time.h"
#include <iostream>
#include <string>

using namespace std;

const int SECONDS_PER_MIN = 60;
const int SECONDS_PER_HOUR = SECONDS_PER_MIN * 60;
const int SECONDS_PER_DAY = SECONDS_PER_HOUR * 24;

clock_time::clock_time(int s, int m, int h, int d)
{
	seconds_ = s;
	minutes_ = m;
	hours_ = h;
	days_ = d;
};

//Accessors
int clock_time::getSeconds() const
{
	return seconds_;
};

int clock_time::getMinutes() const
{
	return minutes_;
};
int clock_time::getHours() const
{
	return hours_;
};
int clock_time::getDays() const
{
	return days_;
};
//Return the total time in seconds
int clock_time::totalSeconds() const
{
	return SECONDS_PER_DAY * days_ + SECONDS_PER_HOUR * hours_ + SECONDS_PER_MIN * minutes_ + seconds_;
};
//Mutators
void clock_time::setSeconds(int s){
	seconds_ = s;
};
void clock_time::setMinutes(int m){
	minutes_ = m;
};
void clock_time::setHours(int h){
	hours_ = h;
};
void clock_time::setDays(int d){
	days_ = d;
};

