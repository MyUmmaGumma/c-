
	int Months[12] =  {
			 31,
			 28,
			 31,
			 30,
			 31,
			 30,
			 31,	
			 31,
			 30,
			 31,
			 30,
			 31
		};
class Date
{
	int day;
	int month;
	int year;
	
public:
		Date() : day(1),month(1),year(1900)
		{
		}

		Date(int _day,int _month,int _year) : day(_day),month(_month),year(_year)
		{
		}
		~Date() 
		{
		}
		
		int GetDay() const
		{
			return day;
		}
	
		int GetMonth() const
		{
			return month;
		}	
		int GetYear() const
		{
			return year;
		}	
		Date& operator ++();  //prefix operators;
		Date  operator ++(int);
		Date& operator --();
		Date  operator --(int);
		Date& operator +=(int number);
		Date& operator -=(int number);
		bool  operator ==(const Date &d);
		bool  operator !=(const Date &d);
		bool  operator >(const Date &d);
		bool isLeap() const;

		//helper functions
		int sub_year() //must un-complicate this function
		{
			int ret = 0;
			Date d = *this;
			d.year--;
			if(month > 2 && !isLeap())
				ret = 365;
			else if(month > 2 && isLeap())
				ret = 366;
			else if(month <= 2 && !isLeap() && d.isLeap())
				ret = 366;
			else if(month <=2 && !isLeap() && !d.isLeap())
				ret = 365;
			else if(month <=2 && isLeap() && !d.isLeap())
				ret = 365;
			year--;
			return ret;
		}
	
		int sub_month() 
		{
			month--;
			if(month == 0)
			{
				month = 12;
				year--;
				return Months[0];
			}
			else if(isLeap() && month == 1)
				return Months[month]+1;
			else if(isLeap() && month == 2 && day >28)
				day = day - 2;
			else if(month==2 && day >28)
				day = day - 3;
			else   
				return Months[month];
		}
		
		bool month_greater(Date &d)
		{
			if(year > d.year)
				return true;
			else if(month > d.month && year == d.year)
				return true;
			else
				return false;
		}

		Date(Date &d)
		{
			day = d.day;
			month = d.month;
			year = d.year;
		}
	
		Date& Add(int num);
		Date& Sub(int num);
		int Sub(Date &d); // chk how to make this const
		friend ostream&
			 operator<<(ostream &os,const Date& d);
		friend istream&
			operator>>(istream &is, Date &d);
};
