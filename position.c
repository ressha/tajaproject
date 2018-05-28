#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<termios.h>
void position(void);
int getch(void);
void position(void)//메인함수는 적지 않았습니다. getch 함수는 맨 
{srand(time(NULL));
		int caps=rand()%2,alpha=rand()%26;
		int answer=(caps?65:95)+alpha,input;
		int prog=1,miss=0,hit=0;
		double acc=0;
	while(prog<=20){
		if (hit>0)
			acc=(hit-miss)/(double)hit;
	system("clear");
	printf("***********\n");
	printf("     %c     \n",answer);
	printf("***********\n");
	printf("%d번째 입력\n",hit+1);
	printf("진행도:%d/20\n 오타수:%d\n 정확도:%.2f%%\n",prog,miss,acc*100);
	input=getch();
	if(input==answer){
	prog++;
	hit++;
	caps=rand()%2;
	alpha=rand()%26;
	answer=(caps?65:95)+alpha,input;
	}
	else if(input==27){
		system("clear");
		main();
	}
	else{
		miss++;
		hit++;
	}
	}
	system("clear");
	printf("전체타수:%d  , 오타수:%d , 정확도:%.2f%%\n",hit,miss,acc*100);
	while(1){
		input=getch();
		if(input==13){
			system("clear");
			main();
		}
	}
}
int getch(void)
{
	char ch;
	struct termios t_old,t_new;
	tcgetattr(STDIN_FILENO,&t_old);
	t_new=t_old;
	t_new.c_lflag&=~(ECHO|ICANON);
	tcsetattr( STDIN_FILENO, TCSANOW, &t_new);
	read(0,&ch,1);
	tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
	return ch;
}
