#include<stdio.h> // include stdio.h header file
#include<windows.h> // include windows header file
#include"sound.h"  // include sound.h custom header file
int main(){  // main function
    int s, m, h, as, am, ah, alarm_validaty=1, d = 1000;  // integer variables declareration zone
    char av; // charecter varible declaration zone
    /*
    get current time from user
    */
    printf("Set Current Time (use space to separate): ");
    scanf("%d%d%d",&h,&m,&s);
    if((h>12) || (m>60) || (s>60)){  // check input time's validaty
        printf("invalid Time");
        exit(0);
    }
    fflush(stdin);  // clear input buffer for taking input  a charecter in line 18
    printf("Are You Want To set any Alarm(Y/N) : ");
    scanf("%c",&av);
    if(av=='y'||av=='Y'){  // alarm set and check validaty block
        while(alarm_validaty){
            printf("Enter Alarm time(hh mm ss)use space to separate : ");  // set alarm
            scanf("%d%d%d",&ah,&am,&as);
            if((ah>12) || (am>60) || (as>60)){
                printf("invalid Time\n");
            }
            else if(ah<=0||am<0||as<0){
                printf("Invalid time\n");
            }
            else{
                alarm_validaty = 0;
            }
        }
    }
    while(1){  // runing clock from here
        s++;
        if(s>59){  // check second and set minute
            m++;
            s=0;
        }
        if(m>59){  // check minute and set hour
            h++;
            m=0;
        }
        if(h>12){ // set hour
            h=1;
        }
        printf("\n Clock : %02d:%02d:%02d",h,m,s);  // printing clock
        if(ah==h&&am==m&&as==s){  // alarm activation block
            printf("*******COME ON WAKE UP*******\n*******TIME TO GO*******");
            sound();  // alarm sound function built in sound.h
            s+=35;  // fix second alarm duration time with second
            if(s>59){
                m++;  
                s = (s-59);
            }
        }
        Sleep(d);  // delay program execution
        system("cls");  // clear screen 
    }

    return 0;
}