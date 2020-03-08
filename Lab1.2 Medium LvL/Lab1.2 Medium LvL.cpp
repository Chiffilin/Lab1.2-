#include <iostream>
#include <clocale>
#include <string>
#include<istream>
using namespace std;

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

struct Engineer
{
    char F[56];
    char I[32];
    char O[32];
    int Gender;				// Girl=0,Man=1;
    char Post[32];
    Date birthday;

};

int main()
{
	const int N = 2;
	Engineer group[N];

	for (int i = 0; i < N; i++)
	{
		cout << "\n............Profile..[" << i + 1 << "]........" << endl;
		cout << "\nInput Surname: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].F, 56);

		cout << "\nInput Name: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].I, 32);

		cout << "\nInput Middle name: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].O, 32);

		cout << "\nGender:MAN[1],Girl[0].";
		cout << "\nInput Gender: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].Gender;						// Girl=0, Man=1;

		cout << "\nInput Post: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Post, 32);

		do
		{
			cout << "\nInput Birthday: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].birthday.day >> group[i].birthday.month >> group[i].birthday.year;
		} while (!group[i].birthday.isCorrect());
		cin.clear();
	}
	
	for (int i = 0; i < N; i++)
	{
		cout << "\n...............DATA......................" << endl;
		cout << "\nFIO: " << group[i].F << " " << group[i].I << " " << group[i].O;
		cout << "\nBirthday: " << group[i].birthday.day << "." << group[i].birthday.month << "." << group[i].birthday.year;
		cout << "\nGender: " << group[i].Gender;
		cout << "\nPost: " << group[i].Post << endl;
	}
	
	int best = 0;
	int d = 1955;
	int d1 = 1960;
	
								
	for (int i = 0; i < N; i++)
	{
		
		if(group[i].Gender == 1)
		{

			if (group[i].birthday.year <= d)
			{
				best = i;
				cout << "\n...............ANSWER......................" << endl;
				cout << "\nFIO: " << group[best].F << " " << group[best].I << " " << group[best].O;
				cout << "\nBirthday: " << group[best].birthday.day << "." << group[best].birthday.month << "." << group[best].birthday.year;
				cout << "\nGender: " << group[best].Gender;
				cout << "\nPost: " << group[best].Post << endl;
			}
			else
			{
				cout << "\n...............ANSWER......................" << endl;
				cout << "\nNo results! :(" << endl;
			}
		}
		else if (group[i].Gender == 0)
		{

			if (group[i].birthday.year <= d1)
			{
				best = i;
				cout << "\n...............ANSWER......................" << endl;
				cout << "\nFIO: " << group[best].F << " " << group[best].I << " " << group[best].O;
				cout << "\nBirthday: " << group[best].birthday.day << "." << group[best].birthday.month << "." << group[best].birthday.year;
				cout << "\nGender: " << group[best].Gender;
				cout << "\nPost: " << group[best].Post << endl;
			}
			else
			{
				cout << "\n...............ANSWER......................" << endl;
				cout << "\nNo results! :(" << endl;
			}
		}
	}
}