/****Difference of the Days, hours, minutes, seconds between two time and date******/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void days(int,int,int,int,int,int,int,int,int,int,int,int);
int month(int,int);
int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};

  int main() {
  int day1,month1,year1,day2,month2,year2,hour1, min1, sec1, hour2, min2, sec2;

  printf("Enter the first time and date:  (DD.MM.YYYY HH:MM:SS) : ");
  scanf("%d.%d.%d %d:%d:%d",&day1,&month1,&year1, &hour1, &min1, &sec1);
  printf("Enter the second time and date: (DD.MM.YYYY HH:MM:SS) : ");
  scanf("%d.%d.%d %d:%d:%d",&day2,&month2,&year2, &hour2, &min2, &sec2);
  if(year2>=year1)
  days(year1,year2,month1,month2,day1,day2,hour1,hour2,min1,min2,sec1,sec2);
  else
  days(year2,year1,month2,month1,day2,day1,hour2,hour1,min2,min1,sec2,sec1);
  getch();
  }

 void days(int dateY1,int dateY2,int dateM1,int dateM2,int dateD1,int dateD2, int timeH1,int timeH2,int timeM1,int timeM2,int timeS1,int timeS2) {
  int count=0,i, diffSec, diffMin, diffHour;
  for(i=dateY1; i<dateY2; i++) {
    if( (i%4 == 0 && i%100 != 0) || (i%400 == 0) )
    count+=366;
    else
    count+=365;
    }
  count-=month(dateM1,dateY1);
  count-=dateD1;
  count+=month(dateM2,dateY2);
  count+=dateD2;
  if(count<0)
  count=count*-1;

   if(timeS1 > timeS2) {
        timeS2 += 60;
        --timeM2;
    }

    if(timeM1 > timeM2) {
        timeM2 += 60;
        --timeH2;
    }

    if(timeH1 > timeH2) {
        timeH2 += 24;
        --count;
    }

    diffSec = timeS2 - timeS1;
    diffMin = timeM2 - timeM1;
    diffHour = timeH2 - timeH1;

    printf("Difference is %d days, %d hours, %d minutes, %d seconds.", count, diffHour, diffMin, diffSec);
  }

 int month(int limit,int yearForCount) {
  int fourWeeks=0,length;
  for(length=0;length<limit-1;length++) {
      if(length==1) {
            if(yearForCount%4==0)
            fourWeeks+=29;
            else
            fourWeeks+=28;
          }

        else
        fourWeeks+=mon[length];
      }
  return(fourWeeks);
  }
