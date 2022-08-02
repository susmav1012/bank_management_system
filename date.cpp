class date{
	int day;
	int month;
	int year;
	public:
		void getdate();
		int validate(int);
		void display();
		friend char* get_date(int);
};

void date::getdate()
{
	scanf("%d/%d/%d",&day,&month,&year);
}

int date::validate(int age)
{
	int y;
	y=2021-year;
	if(month>12||month<=0)
		return 0;
	
		switch(month)
		{
			case 1:
				case 3:
					case 5:
						case 7:
							case 8:
								case 10:
									case 12:
										if(day>31||day<=0)			
											return 0;
			case 4:
				case 6:
					case 9:
						case 11:
							if(day>30||day<=0)
								return 0;
			case 2:
				if(year%4==0)
				{
					if(year%100==0)
					{
						if(year%400==0)
						{
							if(day>29||day<=0)
								return 0;
						}
						else
						{
							if(day>28||day<=0)
								return 0;
						}
					}
					else
					{
						if(day>29||day<=0)
							return 0;
					}
				}
				else
				{
					if(day>28||day<=0)
						return 0;
				}	
		}
	if(07<month)
	{
		y--;
	}
	if(y>=age)return 1; else return 0;
}

void date::display()
{
	cout<<day<<endl<<month<<endl<<year;
}

char dob[11];
char* get_date(int n)
{
	date d;
	d.getdate();
	while(!d.validate(n))
	{
		cout <<"\n\t\t\t\t\t\t\t\t\t=================================================================================" << endl;
		red();
		cout<<"\t\t\t\t\t\t\t\t\tINVALID DATE!!";
		reset();
		cout<<"\n\t\t\t\t\t\t\t\t\tPlease Enter Again:";
		d.getdate();
		
	}
	sprintf((char*)dob,"%d/%d/%d",d.day,d.month,d.year);
	return dob;
}

