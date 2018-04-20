#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
#include<string.h>

pthread_mutex_t l;
int fd, n;

char ch[] = "\nTEACHER PROVIDED :>\n";
char ch1[]= "\nPEN & PAPER\n";
char ch2[]= "\nPAPER & QUESTION PAPER\n";
char ch3[]= "\nPEN & QUESTION PAPER\n";
char c1[] = "\nTeacher Provides PEN and PAPER\n";
char c2[] = "\nTeacher Provides PAPER and QUESTION PAPER\n";
char c3[] = "\nTeacher Provides PEN and QUESTION PAPER\n";
char lap1[] = ":::::::::::::::::Lap 1:::::::::::::::::\n";
char lap2[] = ":::::::::::::::::Lap 2:::::::::::::::::\n";
char lap3[] = ":::::::::::::::::Lap 3:::::::::::::::::\n";
char ch_Dash[]= "----------------   \n";
void career(void * args)
{
    pthread_mutex_lock(&l);
    int count = 0;
    while(1)
    {
        printf("\n\x1b[34mEnter Any Two Choices From Below List To Analyze Which Student Completes His/Her Tasks First\x1b[0m\n");
        printf("\n1. Pen and Paper\n2. Paper and Question Paper\n3. Pen and Question Paper\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                write(fd, lap1, strlen(lap1));
                write(fd, ch, strlen(ch));
                write(fd, c1, strlen(ch1));
                write(fd, ch, strlen(ch));
                write(fd, ch_Dash, strlen(ch_Dash));
                write(fd, ch1, strlen(ch1));
                system("clear");
                //system("\e[41m\e[2J");
                printf("\nYOUR CHOICE:\t\tPen, Paper(As The Teacher Has Given These)\nTASK COMPLETED BY:\tSTUDENT 3\nHIS REQUIREMENT:\tQUESTION PAPER\n");
                if(count == 0)
                printf("\n\x1b[34mNOTE : Please Check \"Counter.txt\" For Information About \nTask Allocations And Many More\x1b[0\n");
                else if(count == 1)
                printf("\x1b[34mNOTE : You Have Attemted 2nd Time\nPlease Check \"Counter.txt\" For More Information\x1b[0m\n");
                else
                printf("\x1b[34mNOTE : You Can Still Check \"Counter.txt\" For More Information\x1b[0m\n");
               
                break;
            case 2:
                write(fd, lap2, strlen(lap2));
                write(fd, ch, strlen(ch));
                write(fd, ch_Dash, strlen(ch_Dash));
                write(fd, ch2, strlen(ch2));
                system("clear");
                //system("\e[44m\e[2J");
                printf("\nYOUR CHOICE:\t\tPaper, Question Paper(As The Teacher Has Given These)\nTASK COMPLETED BY:\tSTUDENT 1\nHIS REQUIREMENT:\tPEN\n");
                if(count == 0)
                printf("\n\x1b[35mNOTE : Please Check \"Counter.txt\" For Information About Task Allocations And Many More\x1b[0m\n");
                else if(count == 1)
                printf("\x1b[35mNOTE : You Have Attemted 2nd Time\nPlease Check \"Counter.txt\" For More Information\x1b[0m\n");
                else
                printf("\x1b[35mNOTE : You Can Still Check \"Counter.txt\" For More Information\x1b[0m\n");
               
                break;
            case 3:
                write(fd, lap3, strlen(lap3));
                write(fd, ch, strlen(ch));
                write(fd, ch_Dash, strlen(ch_Dash));
                write(fd, ch3, strlen(ch3));
                system("clear");
                //system("\e[43m\e[2J");
                printf("\nYOUR CHOICE:\t\tPen, Question Paper(As The Teacher Has Given These)\nTASK COMPLETED BY:\tSTUDENT 2\nHIS REQUIREMENT:\tPAPER\n");
                if(count == 0)
                printf("\n\x1b[33mNOTE : Please Check \"Counter.txt\" For Information About Task Allocations And Many More\x1b[0m\n");
                else if(count == 1)
                printf("\x1b[33mNOTE : You Have Attemted 2nd Time\nPlease Check \"Counter.txt\" For More Information\x1b[0m\n");
                else
                printf("\x1b[33mNOTE : You Can Still Check \"Counter.txt\" For More Information\x1b[0m\n");
                break;
            case 4:
                printf("Wait A While...");
                sleep(3);               
                exit(0);   
        }
        count++;
    }
    pthread_mutex_unlock(&l);
   
}




//Driver function

main()
{
    fd = open("Store.txt", O_CREAT|O_RDWR, 0777);
    pthread_mutex_init(&l, 0);   
    pthread_t T1;
   
    pthread_create(&T1, NULL, career, NULL);
    pthread_join(T1, NULL);
    close(fd);
}

