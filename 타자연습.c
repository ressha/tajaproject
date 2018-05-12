#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

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
	srand(time(NULL));
	int rancap = rand() % 2;
	int randomchar=rand() % (((25 - 0) + 1) + 0);
	int answerchar=(rancap ? 97:65)+randomchar;
	int userinput=0,testcase=20,cnt=1,wrong=0;
	while(testcase>0){
		//system("clear");
		system("cls"); //cygwin에서 clear()로 수정 
		printf("---------\n");
		printf("|   %c   |\n",answerchar);
		printf("---------\n");
		printf("%d번째 입력\n",cnt);
		printf("진행율 : %d%%\n오타수 : %d\n정확도 : %d%%\n",(int)((double)(20-testcase)/(double)20*(double)100),wrong,100-(int)((double)wrong/(double)cnt*(double)100));
		printf("입력:");
		userinput=getch();
		if (userinput==answerchar){
			testcase--;
			cnt++;
			rancap = rand() % 2;
			randomchar=rand() % (((25 - 0) + 1) + 0);
			answerchar=0;
			userinput=0;
			answerchar = (rancap ? 97:65)+randomchar;
		}
		else if(userinput==27){
		main();
		}
		else{
			wrong++;
			cnt++;
		}
	}
	//system("clear");
	system("cls");
	printf("오타수 : %d\n정확도 : %d%%\n",wrong,100-(int)((double)wrong/(double)cnt*(double)100));
	printf("Enter를 누르면 돌아갑니다");
	while(1){
		userinput=getch();
		if(userinput==13){
			//system("clear");
			system("cls");
			main();
		}
	}
}

void wordT(){
	
}

void SparagraphT(){
	
}

void LparagraphT(){
	
}

int main(){
	int selection=-1;
	printf("무엇을 연습하시겠습니까?\n1) 자리 연습\n2) 낱말 연습\n3) 짧은 글 연습\n4) 긴 글 연습\n5) 종료\n:");
	scanf("%d",&selection);
	switch(selection){
		case 1:
			printf("자리 연습을 시작합니다\n");
			//countdown(5);
			system("cls");//cygwin 에서 clear 
			positionT();
			break;
		case 2:
			printf("낱말 연습을 시작합니다\n");
			countdown(5);
			wordT();
			break;
		case 3:
			printf("짧은 글 연습을 시작합니다\n");
			countdown(5);
			SparagraphT();
			break;
		case 4:
			printf("긴 글 연습을 시작합니다\n");
			countdown(5);
			LparagraphT();
			break;
		case 5:
			printf("프로그램을 종료합니다");
			sleep(1);
			break;
	}
}
