#include "stdio.h"
#include "string.h"


int main(int argc,char **argv)
{
	static const char NONLEAP_YEAR_MON[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	//平年 
	static const char LEAP_YEAR_MON[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	//闰年 
	static const short FOUR_YEARS = (366 + 365 +365 +365); //每个四年的总天数 
	static const int DAY_SECOND = 24*3600;	//每天的秒数	 
	const char *pucMonth;
	int i_dwSeconds=atoi(argv[1]);
	int iTime = i_dwSeconds;//得到当前系统时间 
	int iDays = iTime/DAY_SECOND+1;//获取的是从1970年以来的秒数，因此需要先得到天数 
	int iRemainSeconds= iTime%DAY_SECOND;
	char ucYear4 = iDays/FOUR_YEARS;//得到从1970年以来的周期（4年）的次数 
	int iRemainDays = iDays%FOUR_YEARS;//得到不足一个周期的天数 
	int iRemainDaysTemp=0;
	char ucDesYear = ucYear4*4; 
	char ucDesMonth = 0,ucDesDay = 0;
	char ucDesHour=0,ucDesMinute=0,ucDesSecond=0;
	char  ucLeapYearFlag= 0; 
	int i;
	if ( iRemainDays<365 )//一个周期内，第一年 
	{//平年 
	} 
	else if ( iRemainDays<(365+365) )//一个周期内，第二年 
	{//平年 
		ucDesYear += 1; 
		iRemainDays -= 365; 
	} 
	else if ( iRemainDays<(365+365+365) )//一个周期内，第三年 
	{//平年 
		ucDesYear += 2; 
		iRemainDays -= (365+365); 
	} 
	else//一个周期内，第四年，这一年是闰年 
	{//润年 
		ucDesYear += 3; 
		iRemainDays -= (365+365+365); 
		ucLeapYearFlag = 1; 
	} 
	if(0==ucLeapYearFlag)
	{
		pucMonth=NONLEAP_YEAR_MON;
	}
	else
	{
		pucMonth=LEAP_YEAR_MON;
	}
	//循环减去12个月中每个月的天数，直到剩余天数小于等于0，就找到了对应的月份  
	for ( i=0; i<12; i++ )   
	{        
		iRemainDaysTemp = iRemainDays - pucMonth[i];         
		if ( iRemainDaysTemp<=0 )         
		{             
			ucDesMonth = i+1;           
			if ( iRemainDaysTemp == 0 )//表示刚好是这个月的最后一天，那么天数就是这个月的总天数了                
			ucDesDay = pucMonth[i];            
			else                
			ucDesDay = iRemainDays;             
			break;         
		}        
		iRemainDays = iRemainDaysTemp;     
	} 
	ucDesHour=iRemainSeconds/3600;
	iRemainSeconds-=ucDesHour*3600;
	ucDesMinute=iRemainSeconds/60;
	iRemainSeconds-=ucDesMinute*60;
	ucDesSecond=iRemainSeconds;
	printf("year:%d,mon:%d,day:%d,hour:%d,min:%d,sec:%d\r\n",ucDesYear,ucDesMonth,ucDesDay,ucDesHour,ucDesMinute,ucDesSecond);
	return 0;
}
