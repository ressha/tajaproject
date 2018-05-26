#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int countdown(int t){
			printf("%d",t);sleep(1);
			int i;
			for(i=t-1;i>=1;i--){
				printf("\b%d",i);
				sleep(1);
			}
			printf("\b ");
}

void positionT(){
}

void wordT(){
	//낱말 연습 코드
}

void SparagraphT(){
	//짧은 문장 연습 코드
}

void LparagraphT(){
	//긴 문장 연습 코드
	srand(time(NULL)); //시드 초기화
	int T=2;
	char long_para[4][10][100]={"The Middle\n","Take a seat right over there, sat on the stairs\n","Stay or leave, the cabinets are bare and I'm unaware\n","Of just how we got into this mess, got so aggressive\n","I know we meant all good intentions\n", \ 
	"So pull me closer\n","Why don't you pull me close?\n","Why don't you come on over?\n","I can't just let you go\n","Oh baby, why don't you just meet me in the middle?\n", \
	
	"Faint\n","I am a little bit of loneliness, a little bit of disregard\n","Handful of complaints but I can't help the fact\n","That everyone can see these scars\n","I am what I want you to want, what I want you to feel\n", \
	"But it's like no matter what I do, I can't convince you\n","To just believe this is real\n","So I, let go watching you turn your back like you always do\n","Face away and pretend I'm not\n","But I'll be here 'cause you're all that I've got\n", \
	
	"Wolves\n","In your eyes, there's a heavy blue\n","One to love and one to lose\n","Sweet divide, a heavy truth\n","Water or wine, don't make me choose\n", \
	"I wanna feel the way that we did that summer night\n","Drunk on a feeling, alone with the stars in the sky\n","I've been running through the jungle\n","I've been running with the wolves\n","To get to you, to get to you\n", \
	
	"Butterflies And Hurricanes\n","Change everything you are and everything you were\n","Your number has been called. Fights and battles have begun\n", \
	"Revenge will surely come. Your hard times are ahead\n","Best, You've got to be the best. you've got to change the world\n","And use this chance to be heard\n"};
	system("cls");
	while(T--){
		int randint=rand()%4,c;
		
		//첫 페이지 출력부분
		int len[10]={0,};
		for(int i=0;i<5;i++)
			for(int j=0;j<100;j++){
				if(long_para[randint][i][j]=='\n'){
					len[i]=j-1;
					printf("\n");
					break;
				}
				printf("%c",long_para[randint][i][j]);
			}
		//입력부분
		int ln=0,cl=0;
		while(ln<5){
			c=getch();
			if(c=='\b'){
				if(cl>0){
					printf("\b \b");
					cl--;
				}
				else if(cl<=0 && ln>0){
					ln--;
					for(int i=0;i<100;i++){
						if(long_para[randint][ln][i]=='\n')
						cl=i-1;
					}
					printf("\b \b");
				}
				continue;
			}
			printf("%c",c);
			if(long_para[randint][ln][cl+1]=='\n'){
				cl=0;
				ln++;
				printf("\n");
			}else{
				cl++;
			}
		}
	}
}

int main(){
	int selection=-1; //선택 함수 초기화
	printf("무엇을 연습하시겠습니까?\n1) 자리 연습\n2) 낱말 연습\n3) 짧은 글 연습\n4) 긴 글 연습\n5) 종료\n입력 : ");
	scanf("%d",&selection); //입력 받음
	switch(selection){
		case 1: //1 입력시
			printf("자리 연습을 시작합니다\n");
			//countdown(5);
			system("cls");//cygwin 에서 clear 
			positionT(); //자리연습 함수 실행
			break;
		case 2: //2 입력시
			printf("낱말 연습을 시작합니다\n");
			countdown(5);
			wordT();
			break;
		case 3: //3 입력시
			printf("짧은 글 연습을 시작합니다\n");
			countdown(5);
			SparagraphT();
			break;
		case 4: //4 입력시
			printf("긴 글 연습을 시작합니다\n");
			//countdown(5);
			LparagraphT();
			break;
		default: //5 혹은 이외의 수 입력시
			system("cls");
			printf("프로그램을 종료합니다");
			sleep(1);
			exit(1);
	}
}
