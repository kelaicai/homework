#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int date_array_of_noleap[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int date_array_ofleap[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
typedef struct date
{
	int year;
	int mounth;
	int day;
}date;

void input(date *tmp_date)
{
	int pf = 1;
	printf("input year,mounth,day\n");
	while (pf)
	{
		scanf("%d%d%d", &tmp_date->year, &tmp_date->mounth, &tmp_date->day);
		if (tmp_date->year>0 &&
			tmp_date->mounth>0 && tmp_date->mounth<12
			&& tmp_date->day>0 && tmp_date->day <= date_array_of_noleap[tmp_date->mounth])
		{
			pf = 0;
		}
		else
		{
			printf("you input is illgal and now try again");
		}
	}
}

int Count_nonleap_day(date *tmp_date)
{
	int count = 0;
	int i = 1;
	for (i; i<tmp_date->mounth; i++)
	{
		count += date_array_of_noleap[i];
	}
	count += tmp_date->day;
	return count;
}

int Count_leap_day(date *tmp_date)
{
	int count = 0;
	int i = 1;
	for (i; i<tmp_date->mounth; i++)
	{
		count += date_array_ofleap[i];
	}
	count += tmp_date->day;
	return count;
}
void func(date *tmp_date, char *str)
{
	int now;
	while (!(strncmp(str, "no", 2) == 0))
	{
		input(tmp_date);
		if ((tmp_date->year % 4 == 0 && tmp_date->year % 100 != 0) || tmp_date->year % 400 == 0)
		{
			printf("now you input a leap year\n");
			now = Count_leap_day(tmp_date);
		}
		else
		{
			printf("now you input a nonleap year\n");
			now = Count_nonleap_day(tmp_date);
		}
		printf("you day is the No.%d  day\n", now);

		fflush(stdin);
		printf("do you want to conitue?\n");
		gets(str);
	}
}
int main()
{
	date tmp_date;
	char str[10] = { '\0' };
	func(&tmp_date, str);
	system("pause");
	return 0;
}


