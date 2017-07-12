/*
 * clock_time.cpp
 *
 *  Created on: Jul 12, 2017
 *      Author: yashkalebere
 */

#include "clock_time.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const int SEC_PER_MIN = 60;
const int MIN_PER_HOUR = 60;
const int HOUR_PER_DAY = 24;
const int SEC_PER_HOUR = SEC_PER_MIN * MIN_PER_HOUR;
const int SEC_PER_DAY = SEC_PER_HOUR * HOUR_PER_DAY;

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
	return SEC_PER_DAY * days_ + SEC_PER_HOUR * hours_ + SEC_PER_MIN * minutes_ + seconds_;
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

//Boolean Comparisons
bool operator<(const clock_time& a, const clock_time& b)
{
	return a.totalSeconds() < b.totalSeconds();
}
bool operator>(const clock_time& a, const clock_time& b)
{
	return a.totalSeconds() > b.totalSeconds();
}
bool operator==(const clock_time& a, const clock_time& b)
{
	return a.totalSeconds() == b.totalSeconds();
}
bool operator<=(const clock_time& a, const clock_time& b)
{
	return a.totalSeconds() <= b.totalSeconds();
}
bool operator>=(const clock_time& a, const clock_time& b)
{
	return a.totalSeconds() >= b.totalSeconds();
}

//Add times
//(1 day, 3 hours, 7 minutes, 28 seconds)
//+ (3 days, 22 hours, 54 minutes, 33 seconds)
//--------------------------------------------
//(5 days, 2 hours, 2 minutes, 1 seconds)
clock_time operator+(const clock_time& a, const clock_time& b)
{
	int seconds = a.getSeconds() + b.getSeconds();

	int minutes = a.getMinutes() + b.getMinutes() + seconds/SEC_PER_MIN;
	seconds = seconds % SEC_PER_MIN;

	int hours = a.getHours() + b.getHours() + seconds/SEC_PER_MIN;
	minutes = seconds % SEC_PER_MIN;

}
//Print out as (D days, H hours, M minutes, S seconds)
ostream & operator<<(ostream & out, const clock_time& a);

