#include<iostream>
#include<string>
using namespace std;

#define DAY 0
#define MONTH 1
#define YEAR 2

enum {january=1,february,march,april,may,june,july,august,september,october,november,december};

class Date
{
	int day,month,year;
public:
	Date() : day(0),month(0),year(0){}

	Date(int d,int m,int y) : day(d),month(m),year(y){}

	bool operator ==(const Date &d)
	{
		return (day == d.day && month == d.month && year == d.year );
	}

	bool operator !=(const Date &d)
	{
		return !(*this==d);
	}

	bool operator >(const Date &d)
	{
		if( year > d.year)
			return true;
		
		else if ( year == d.year )
		{
			if ( month > d.month )
				return true;
			else if ( month == d.month )
			{
				if ( day > d.day )
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else 
			return false;

	}

	bool operator <(const Date &d)
	{
		if( year < d.year)
			return true;
		
		else if ( year == d.year )
		{
			if ( month < d.month )
				return true;
			else if ( month == d.month )
			{
				if ( day < d.day )
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else 
			return false;
	}

	bool operator >=(const Date &d)
	{
		return !(*this<d);
	}

	bool operator <=(const Date &d)
	{
		return !(*this>d);
	}

	Date& operator ++()
	{
		if ( month == december && day==31)
			day=1,month=january,year++;
		else
		{
			if ( day == daysOfMonth(month) )
				day = 1,month++;
			else
				day++;
		}
		
		return *this;
	}

	Date operator ++(int postfix)
	{
		Date tmp = *this;

		if ( month == december && day==31)
			day=1,month=january,year++;
		else
		{
			if ( day == daysOfMonth(month) )
				day = 1,month++;
			else
				day++;
		}		
		return tmp;
	}

	Date& operator --()
	{
		if ( month == january && day==1)
			day=31,month=december,year--;
		else
		{
			if ( day == 1)
				month--,day=daysOfMonth(month);
			else
				day--;
		}
		
		return *this;
	}

	Date operator --(int postfix)
	{
		Date tmp = *this; 
		if ( month == january && day==1)
			day=31,month=december,year--;
		else
		{
			if ( day == 1)
				month--,day = daysOfMonth(month);
			else
				day--;
		}
		return tmp;
	}

	Date operator +(int days)
	{
		Date tmp= *this;
		for(int i=0;i<=days;i++)
			tmp++;
		return tmp;
	}

	Date operator -(int days)
	{
		Date tmp= *this;
		for(int i=0;i<days;i++)
			tmp--;
		return tmp;
	}

	friend ostream& operator <<(ostream &out,Date &d)
	{
		out<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
		return out;
	}

	friend istream& operator >>(istream &in,Date &d)
	{
		cout<<"Enter day : ";
		in>>d.day;
		cout<<"Enter month : ";
		in>>d.month;
		cout<<"Enter year : ";
		in>>d.year;
		
		return in;
	}

	operator string()
	{
		char *str = new char[11];
		char *dC = new char[3];
		char *mC = new char[3];
		char *yC = new char[5];

		itoa(day,dC,10);
		itoa(month,mC,10);
		itoa(year,yC,10);

		
		strcpy(str,dC);
		strcat(str,"/");
		strcat(str,mC);
		strcat(str,"/");
		strcat(str,yC);
		
		string s = string(str);
		return s;
	}

	Date& operator +=(int days)
	{
		*this = *this + days;
		return *this;
	}

	Date& operator -=(int days)
	{
		*this = *this - days;
		return *this;
	}

	int operator [](int index)
	{
		switch(index)
		{
		case 0:
			return day;
		case 1:
			return month;
		case 2:
			return year;
		default:
			return -1;
		}
	}
	
	inline bool isLeapYear()
	{
		if(( year % 4 == 0 && year % 100 !=0 ) || year % 400 == 0)
			return true;
		return false;
	}

	int daysOfMonth(int mnth)
	{
		if ( mnth == february )
		{
			if ( isLeapYear() )
				return 29;
			else
				return 28;
		}
		if ( mnth >= january && mnth <= 7)
		{
			if( (mnth % 2) != 0 )
				return 31;
			else
				return 30;
		}
		else
		{
			if( (mnth % 2) == 0 )
				return 31;
			else
				return 30;
		}
	}	

	inline int daysInYear()
	{
		if(isLeapYear())
			return 366;
		else
			return 365;
	}

	inline int remainingDaysOfYear()
	{
		int yrday=daysInYear();

		int elapsed= day;
	
		if(month != january )
			for(int i=month -1 ;i >= january ;i--)
				elapsed+=daysOfMonth(i);

		return (yrday - elapsed);		
	}
};