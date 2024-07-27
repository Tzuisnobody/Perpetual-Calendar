#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TRUE    1
#define FALSE   0

int menu;
int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};

int inputyear(void)
{
	int year;
	
	printf("Enter a year: ");
	scanf("%d", &year);
	return year;
}

int determinedaycode(int year) 
{
	int daycode;
	int d1, d2, d3;
	
	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}


int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}

void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}

void monthe()
{
    int m,h,i=1,a=0,j=0,b=1;
    printf("\nEnter the month and year :");
    scanf("%d",&m);
    switch (m)
    {
    case 1:
        a=7;
        j=31;
        break;
    case 2:
        a=3;
        j=28;
        break;
    case 3:
        a=3;
        j=31;
        break;
    case 4:
        a=6;
        j=30;
        break;
    case 5:
        a=1;
        j=31;
        break;
    case 6:
        a=4;
        j=30;
        break;
    case 7:
        a=6;
        j=31;
        break;
    case 8:
        a=2;
        j=31;
        break;
    case 9:
        a=5;
        j=30;
        break;
    case 10:
        a=7;
        j=31;
        break;
    case 11:
        a=3;
        j=30;
        break;
    case 12:
        a=5;
        j=31;
        break;
    default:
    printf("\a\a Invalid month\n");
        break;

    }
    if(a==0&&j==0){
        printf(" ");
    }else{printf("\n\n\n");
    printf("\t\t\t Result \n\n", m);
    printf("       SUN       MON       TUE      THU      FRI        SAT \n\n",m);
    }
    switch(a)
    {
    case 1:
        printf("\t%d",i);
        break;
    case 2:
        printf("\t\t%d",i);
        break;
    case 3:
        printf("\t\t\t%d",i);
        break;
    case 4:
        printf("\t\t\t\t%d",i);
        break;
    case 5:
        printf("\t\t\t\t\t%d",i);
        break;
    case 6:
        printf("\t\t\t\t\t\t%d",i);
        break;
    case 7:
        printf("\t\t\t\t\t\t\t%d",i);
        break;

    }
    h=8-a;
    if(a==0){
        printf(" ");
    }else{
    for(i=2;i<=h;i++)
    {
        printf("\t%d",i);

    }
    printf("\n");
    for(i=h+1;i<=j;i++)
    {
        if(b==8)
        {
            printf("\n");
            b=1;
        }
        printf("\t%d",i);
        b++;
            
        }
        
    }
}
void weeke(){
    int date, month, year;
    int fmonth, leap;
    int dayOfWeek;
    int YY = year % 100;
    int century = year / 100;
    
   printf("\nEnter the year: ");
   scanf("%d", &year);

   printf("\nEnter the month: ");
   scanf("%d", &month);

   printf("\nEnter the day: ");
   scanf("%d", &date);

    if(month>=1 && month<=12){
    if(date>=1 && date<=31){
      if ((year % 100 == 0) && (year % 400 != 0))
    leap = 0;
       else if (year % 4 == 0)
      leap = 1;
    else
      leap = 0;

      fmonth = 3 + (2 - leap) * ((month + 2) / (2 * month))+ (5 * month + month / 9) / 2;

     fmonth = fmonth % 7;
    
printf("\nDate: %d/%d/%d \n", date, month, year);

   dayOfWeek = 1.25 * YY + (fmonth-1) + date - 2 * (century % 4);

   //remainder on division by 7
   dayOfWeek = dayOfWeek % 7;

   switch (dayOfWeek) {
      case 0:
         printf("weekend = Saturday");
         break;
      case 1:
         printf("weekend = Sunday");
         break;
      case 2:
         printf("weekday = Monday");
         break;
      case 3:
         printf("weekday = Tuesday");
         break;
      case 4:
         printf("weekday = Wednesday");
         break;
      case 5:
         printf("weekday = Thursday");
         break;
      case 6:
         printf("weekday = Friday");
         break;
      default:
         printf("Incorrect data");
         break;
   }
    }else{
        printf("Date does not exist!");
    }
}else{
        printf("Date does not exist!");
}
}
void menunu(){
    int num[5];
    int ye;
    int year, daycode, leapyear;
    printf("[1]Find Year\n[2]Find Month and Year\n[3]Find the day of the Week\n[4]Exit\nYou pick: ");
    scanf("%d", &ye);
    switch(ye){
        case 1:
	
	year = inputyear();
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
	printf("\n");
            back:
            printf("\nPress:\n[1]Menu\n[2]Exit\nYou press: ");
            scanf("%d",&menu);
            if(menu==1)
                menunu();
            else if(menu==2)
                exit(0);
            else 
                printf("ERROR!");
                goto back;
            break;
        case 2: monthe();
            printf("\nPress:\n[1]Menu\n[2]Exit\nYou press: ");
            scanf("%d",&menu);
            if(menu==1)
                menunu();
            else if(menu==2)
                exit(0);
            else 
                printf("ERROR!");
                goto back;
            break;
        case 3: weeke();
            printf("\nPress:\n[1]Menu\n[2]Exit\nYou press: ");
            scanf("%d",&menu);
            if(menu==1)
                menunu();
            else if(menu==2)
                exit(0);
            else 
                printf("ERROR!");
                goto back;
            break;
    }
}
int main(){
    printf("\t\t\t\tPERPETUAL CALENDAR\n\n");
    menunu();
    return 0;
}