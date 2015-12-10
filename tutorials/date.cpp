# include <iostream>
using namespace std;
# include "date.h"

ostream& operator <<(ostream &os,const Date &d)
{
	os<<endl<<"Day   = "<<d.day;
	os<<endl<<"Month = "<<d.month;
	os<<endl<<"Year  = "<<d.year;
	os<<endl;
	return os;
}

istream& operator>>(istream& is, Date& d)
{
	cout<<"Enter Day:   "; 
	is>>d.day;
	cout<<"Enter Month: ";
	is>>d.month;
	cout<<"Enter Year:  ";
	 is>>d.year;
	return is;
}

bool Date::isLeap() const
{
	if((year%4) == 0 && !(year%400 == 0))
		return true;
	else
		return false;
}

Date& Date::operator +=(int number)
{
	for(int i = 0;i<number;i++)
		(*this)++;
	return *this;
}

Date& Date::operator -=(int number)
{
	for(int i = 0;i<number;i++)
		(*this)--;
	return *this;
}

bool Date::operator ==(const Date &d)
{
	if(day == d.day && month == d.month && year == d.year)
		return true;
	else
		return false;
}

bool Date::operator !=(const Date &d)
{
	return !(*this == d);
}

bool Date::operator >(const Date &d)
{
	if(year > d.year)
		return true;
	else if((month > d.month) && (year == d.year))
		return true;
	else if((day > d.day) && (month == d.month) && (year > d.year))
		return true;
	else
		return false;
}

Date& Date::operator --()
{
	if(day == 1)
	{
		if(month == 1)
		{
			day = 31;
			month = 12;
			year--;
		}
		else if(month == 3 && isLeap())
		{
			day = 29;
			month = 2;
		}
		else
		{
			month--;
			day = Months[month-1];
		}
	}
	else
	{
		day--;
	}
	return *this;
}	

Date Date::operator --(int)
{
	Date d = *this;
	if(day == 1)
	{
		if(month == 1)
		{
			day = 31;
			month = 12;
			year--;
		}
		else if(month == 3 && isLeap())
		{
			day = 29;
			month = 2;
		}
		else
		{
			month--;
			day = Months[month-1];
		}
	}
	else
	{
		day--;
	}
	return d;
}
	
Date& Date::operator ++()
{
	if(day == Months[month-1])
	{
		day = 1;
		if(month == 12)
		{
			month = 1;
			year++;
		}
		else if(month == 2 && isLeap())
			day = 29;
		else
			month++;
	}	
	else if(day == 29 && month == 2)
	{
		month++;
		day = 1;
	}
	else
		day++;
	return *this;
}


Date Date::operator ++(int)
{
	Date d = *this;
	if(day == Months[month-1])
	{
		day = 1;
		if(month == 12)
		{
			month = 1;
			year++;
		}
		else if(month == 2 && isLeap())
			day = 29;
		else
			month++;
	}	
	else if(day == 29 && month == 2)
	{
		month++;
		day = 1;
	}
	else
		day++;
	return d;
}

Date& Date::Sub(int num)
{
	int sub = 0;
	while(num >= 30)
	{
		sub = day;
		if(month == 1)
		{
			year--;
			month = 12;
		}
		else if(isLeap() && month == 2)
		{
			sub++;
			month--;
		}
		else
			month--;
		day = Months[month - 1];
		num -= sub;
	}
	if(num == 29 && !isLeap() && month == 2)
	{
		day = 30;
		month--;
	}
	else if(num == 28 && !isLeap() && month == 2)
	{
		day = 31;
		month--;
	}
	else
		day -= num;
	return *this;
}

Date& Date::Add(int num)
{
	while(num >= 31)
	{
		num -= (Months[month-1] - day + 1);
		day = 1;
		if(month == 12)
		{
			month = 1;
			year++;
		}
		else if(isLeap() && month == 2)
		{
			month = 3;
			num--;
		}
		else
			month++;
	}
	if(num >=29)
	{
		if(month == 2 && isLeap())
		{
			day = Months[month]-(num-1);
			month = 3;
		}
		else if(month == 2)
		{
			day = Months[month]-num;
			month = 3;
		}
		else if(Months[month] < 31)	
		{
			day = 31;
		}
		else
			day = day + num;
	}
	else
		day = day + num;
	return *this;
}

int Date::Sub(Date& d)
{
	int num = 0;
	while(year > d.year + 1)
		num += sub_year();
	while(month_greater(d))
		num += sub_month();
	while(*this != d)
	{
		num++;
		(*this)--;
	}
	return num;
}
		
int main()
{
	Date d1(1,1,1950),d2(1,1,2000);
	int num;
	cout<<"******************DATE***************"<<endl;
 

/*	cout<<"Enter the Date ";
	cin>>d1;

	cout<<"Enter the Second Date ";
	cin>>d2;*/
	Date d3 = d2;
	if(d1 > d2)
		num = d1.Sub(d2);
	else
		num = d2.Sub(d1);
	cout<<endl<<"The number of days are = "<<num<<endl;

	num=0;
	while(d1 != d3)
	{
		num++;
		d3--;
	}
	cout<<endl<<"The number of days are = "<<num<<endl;
		
}	
