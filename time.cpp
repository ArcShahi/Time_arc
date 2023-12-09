#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#include "color_arc.hpp"

const char* getDayName(int day) {
	static const char* dayNames[] = { "SUN", "MON", "TUE", "WED", "THRUS", "FRI", "SAT" };
	return dayNames[day];
}

void systemTime() {
	while (true) {
		// Time based greeting
		auto now = std::chrono::system_clock::now();
		auto time = std::chrono::system_clock::to_time_t(now);
		tm currentTime{};
		localtime_s(&currentTime, &time);

		auto hours = currentTime.tm_hour;
		auto min = currentTime.tm_min;
		auto sec = currentTime.tm_sec;
		auto day = currentTime.tm_mday;
		auto dayName = getDayName(currentTime.tm_wday);
		auto month = currentTime.tm_mon + 1;  // Adding 1 because months are zero-based
		auto year = currentTime.tm_year + 1900;

		std::cout << Color::green << "[[ Time: " << std::setw(2) << std::setfill('0') << hours << ':'
			<< std::setw(2) << min << ':' << std::setw(2) << sec << RESET
			<< Color::sky_blue << " | Date: " << dayName << "- " << day << '/' << month << '/' << year << " ]]\r" << RESET;

		std::this_thread::sleep_for(std::chrono::seconds(1));  // Pause for 1 second
	}
}

int main() {
	systemTime();
	return 0;
}
