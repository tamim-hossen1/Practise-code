#include<stdio.h> // include stdio.h header file
#include<windows.h> // include windows header file
#include"sound.h"  // include sound.h custom header file
void printf_clock(int h, int m, int s){
    system("cls");  // clear screen
    printf("\t\t\t\t\t================================\n");
    printf("\t\t\t\t\t|");
    printf(" Clock : | %02d | %02d | %02d |", h, m, s);  // printing clock
    printf("     |\n");
    printf("\t\t\t\t\t================================\n");
}
void alarm_system(int *m, int *s){
    printf("\n\t\t\t\t\t================================\n");
    printf("\t\t\t\t\t|");
    printf("********ALARM RINGING********");
    printf(" |\n");
    printf("\t\t\t\t\t|");
    printf("***********WAKE UP***********");  // printing clock
    printf(" |\n");
    printf("\t\t\t\t\t================================\n");
    sound();  // alarm sound function built in sound.h
    *s+=35;  // fix second alarm duration time with second
    if(*s>59){
        *m++;  
        *s = (*s-59);
    }
}
void set_current_time(int *h, int *m, int *s){
    printf("Set Current Time (use space to separate): ");
    scanf("%d%d%d",h,m,s);
    if((*h>12) || (*m>60) || (*s>60)){  // check input time's validaty
        printf("invalid Time");
        exit(0);
    }
}

void set_alarm(int *ah, int *am, int *as){
    int alarm_validity = 1;
    char av;
    printf("Are You Want To set any Alarm(Y/N) : ");
    scanf("%c",&av);
    if(av=='y'||av=='Y'){  // alarm set and check validaty block
        while(alarm_validity){
            printf("Enter Alarm time(hh mm ss)use space to separate : ");  // set alarm
            scanf("%d%d%d",ah,am,as);
            if((*ah>12) || (*am>60) || (*as>60)){
                printf("invalid Time\n");
            }
            else if(*ah<=0||*am<0||*as<0){
                printf("Invalid time\n");
            }
            else{
                alarm_validity = 0;
            }
        }
    }
}

void run_clock_from_here(int h, int m, int s, int ah, int am, int as, int d){
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
        printf_clock(h, m, s);
        if(ah==h&&am==m&&as==s){  // alarm activation block
            alarm_system(&m, &s);
        }
        Sleep(d);  // delay program execution 
    }
}

int main(){
    int s, m, h, as, am, ah, d = 1000;  // integer variables declareration zone
    char av; // charecter varible declaration zone
    set_current_time(&h, &m, &s);
    fflush(stdin);  // clear input buffer for taking input  a charecter
    set_alarm(&ah, &am, &as);
    run_clock_from_here(h, m, s, ah, am, as, d);
    return 0;
}