/*

* UUDate.cpp

*

* Version information

* Author: TODO - Add your name here

* Date: TODO - Add date you started working on the code

* Description: This file is the implementation file for the UUDate class and defines (implements) the functions of the class

*

* Copyright notice -

*/





#include "UUDate.h"

#include <sstream>

#include <string>

#include <vector>

#include <stdio.h>

#include <array>



bool UUDate::validateLeapYear(int year) {

	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;

}






UUDate::UUDate() {

	//Initialise the date to 01/01/2000

	//TODO - Add your implementation here

	SetYear(2000);

	SetMonth(01);

	SetDay(01);

}



UUDate::UUDate(int day, int month, int year) {

	//TODO - Add your implementation here

	year_ = 2000;

	month_ = 01;

	day_ = 01;

	SetYear(year);

	SetMonth(month);

	SetDay(day);



}


bool UUDate::validateDay(int day) {

//	int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//	for (int i = 1; i < monthDays[12]; i++) {
//
//
//		if ((validateLeapYear(year_) == true && monthDays[2]) && (day > 0 && day <= 29)) {
//			return true;
//		}
//		else if ((validateLeapYear(year_) != true && monthDays[2]) && (day > 0 && day <= 28)) {
//			return true;
//		}
//		else if (monthDays[i] == 31 && day > 0 && day < 31) {
//			return true;
//		}
//		else if (monthDays[i] == 30 && day > 0 && day < 31) {
//			return true;
//		}
//	}
//}
	
	if ((validateLeapYear(year_) == true && month_ == 2) && (day > 0 && day <= 29)) {
		return true;
	}
	else if ((validateLeapYear(year_) != true && month_ == 2) && (day > 0 && day <= 28)) {
		return true;
	}
	else if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12) {
		if (day > 0 && day <= 31) {
			return true;
		}
	}
	else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {

		if (day > 0 && day <= 30) {
			return true;
		}
	}
	else {
		return false;
	}
}





UUDate::UUDate(std::string date) {

	//TODO - Add your implementation here

	int day, month, year;



	std::stringstream Date(date);

	std::string tmpStr;

	std::vector <std::string> dateVector;

	while (std::getline(Date, tmpStr, '/')) {

		dateVector.push_back(tmpStr);

	}

	day = atoi(dateVector[0].c_str());

	month = atoi(dateVector[1].c_str());

	year = atoi(dateVector[2].c_str());

	
	day_ = day;
	month_ = month;
	year_ = year;

}



void UUDate::IncrementDate() {

	//TODO - Add your implementation here

//	int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	
//	if (validateLeapYear(year_) == true && monthDays[2]) {
//		if (day_ > 0 && day_ < 29) {
//			day_++;
//		}
//		else if (day_ == 29) {
//			month_++;
//			day_ = 1;
//		}
//	}
//	else if (monthDays[2]) {
//		if (day_ > 0 && day_ < 28) {
//			day_++;
//		}
//		else if (day_ == 28) {
//			month_++;
//			day_ = 1;
//		}
//	}
//	else if (monthDays[12]) {
//		if (day_ > 0 && day_ < 31) {
//			day_++;
//		}
//		else if (day_ == 31) {
//			year_++;
//			month_ = monthDays[1];
//			day_ = 1;
//		}
//	} else for (int i = 1; i < monthDays[12]; i++) {
//
//		if (monthDays[i] == 31) {
//			if (day_ > 0 && day_ < 31) {
//				day_++;
//			}
//			else if (day_ == 31) {
//				month_++;
//				day_ = 1;
//			}
//		}
//		else if (monthDays[i] == 30) {
//			if (day_ > 0 && day_ < 30) {
//				day_++;
//			}
//			else if (day_ == 30) {
//				month_++;
//				day_ = 1;
//			}
//		}
//	} 	
//}


	if (month_ == 2 && validateLeapYear(year_) == true) {

		if (day_ > 0 && day_ < 29) {

			day_++;

		}

		else if (day_ == 29) {

			month_++;

			day_ = 1;

		}

	}
	else if (month_ == 2 && validateLeapYear(year_) != true) {

		if (day_ > 0 && day_ < 28) {

			day_++;

		}

		else if (day_ == 28) {

			month_++;

			day_ = 1;

		}

	}
	else if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10) {

		if (day_ > 0 && day_ < 31) {

			day_++;

		}

		else if (day_ == 31) {

			month_++;

			day_ = 1;

		}

	}

	else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {

		if (day_ > 0 && day_ < 30) {

			day_++;

		}

		else if (day_ == 30) {

			month_++;

			day_ = 1;

		}

	}

	else if (month_ == 12) {

		if (day_ > 0 && day_ < 31) {

			day_++;

		}

		else if (day_ == 31) {

			year_++;

			month_ = 1;

			day_ = 1;

		}

	}

	else {

		day_ = 1;

	}

}


int UUDate::leapYearAmount(int month, int year) {
	int years = year;
	if (month <= 2) {
		years--;
	}
	return years / 4 - years / 100 + years / 400;
}

int UUDate::Between(UUDate date) {

	//TODO - Add your implementation here
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int presentDate[3] = { day_, month_, year_ };
	int nxtDate[3] = { date.day_, date.month_, date.year_ };

	long int dateCount1 = presentDate[2] * 365 + presentDate[0];

	for (int i = 0; i < presentDate[1] - 1; i++) 
		dateCount1 += monthDays[i];
		dateCount1 += leapYearAmount(presentDate[1], presentDate[2]);
	
		
	long int dateCount2 = nxtDate[2] * 365 + nxtDate[0];
		
		
	for (int i = 0; i < nxtDate[1] - 1; i++) 
			dateCount2 += monthDays[i];
			dateCount2 += leapYearAmount(nxtDate[1], nxtDate[2]);

			
		

	return (dateCount2 - dateCount1);
	

}



int UUDate::GetDay() const {

	//TODO - Add your implementation here

	return day_;

}



void UUDate::SetDay(int day) {

	//TODO - Add your implementation here

	if (validateDay(day) == true) {
		day_ = day;
	}

}



int UUDate::GetMonth() const {

	//TODO - Add your implementation here

	return month_;

}



void UUDate::SetMonth(int month) {

	//TODO - Add your implementation here

	if (month > 0 && month < 13) {

		month_ = month;

	}

}



int UUDate::GetYear() const {

	//TODO - Add your implementation here

	return year_;

}



void UUDate::SetYear(int year) {

	//TODO - Add your implementation here

	if (year > 1000 && year < 10000) {

		year_ = year;

	}

}



std::string UUDate::GetDate() {

	//TODO - Add your implementation here

	char buffer[40] = { 0 };
	
	sprintf(buffer, "%02d/%02d/%02d", day_, month_, year_);

	std::string Date = buffer;

	return Date;



}