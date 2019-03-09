
/*

Is Friday the 13th a rare day?
In other words: Is 'Friday' the 13th rarer compared to 'Other weekdays' the 13th?
To answer that question, I coded this little program to calculate the frequency of each 'Weekday' the 13th from 1/1/1900 to 31/12/[Input], given 1/1/1900 is Monday.
Input: year
Output: Saturdays - Sundays - Mondays - Tuesdays - Wednesdays - Thursdays - Fridays
Result: Friday the 13th is not as rare as you may think, in fact it's the most frequent out of all weekdays.
Don't believe me? Test it for yourself with my source code.

*/

#include <iostream>

int LeapYear(int n){ // Check if n is a leap year or not
    // A year is considered a leap year if it's:
    //      A. Divisible by 4 and indivisible by 100
    //   or B. Divisible by 400
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) return 1;
	return 0;
}

int CountDays(int day, int month, int year){ // Count the days from 1/1/1900 to day/month/year
	int days = 0;
	for (int i = 1900; i < year; i++){
		if(LeapYear(i)) days += 366;    // Leap years have 366 days
	 	else days += 365;               // Normal years have 365 days
	}
	for (int i = 1; i < month; i++){
		switch (i){
			case 4:
			case 6:
			case 9:
			case 11:
			 	days += 30;                         // April, June, September and November has 30 days
			 	break;
	 		case 2:
	 			if (LeapYear(year)) days += 29;     // February has 29 days if it's a leap year
	 			else days += 28;                    // ____________ 28 ______________ normal year
	 			break;
			default:
				days += 31;                         // Other months have 31 days
				break;
		}
	}
	return days + day;	
}

void HowMany13ths (int N){
	int i, j, days;
	int mondays = 0, tuesdays = 0, wednesdays = 0, thursdays = 0, fridays = 0, saturdays = 0, sundays = 0;
	for (i = 1900; i <= N; i++){                // From year 1900 to year N (of course N > 1900)
		for (j = 1; j <= 12; j++){              // Each year have 12 months
			days = CountDays(13, j, i);         // Calculate how many days from 1/1/1900 to 13/j/i
			switch (days % 7){                  // Divide 'days' by 7 to figure out which weekday it is
				case 0: sundays++; 	break;      // If 'days' % 7 == 0 then it is a Sunday
				case 1: mondays++; 	break;      //_________________ 1 ____________ Monday
				case 2: tuesdays++;	break;      //_________________ 2 ____________ Tuesday
				case 3: wednesdays++;	break;  //_________________ 3 ____________ Wednesday
				case 4: thursdays++;	break;  //_________________ 4 ____________ Thursday
				case 5: fridays++;	break;      //_________________ 5 ____________ Friday
				case 6: saturdays++;	break;  //_________________ 6 ____________ Saturday
			}
		}
	}
	cout << saturdays << " - " << sundays << " - " << mondays << " - " << tuesdays << " - " << wednesdays << " - " << thursdays << " - " << fridays << endl;
	// Output
}

int main(){
	int year;
	cout << "Input a year: ";
	cin >> year;
	HowMany13ths(year);
}
