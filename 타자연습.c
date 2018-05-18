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
}

void wordT(){
	//낱말 연습 코드
}

void SparagraphT(){
	//짧은 문장 연습 코드
}

void LparagraphT(){
	//긴 문장 연습 코드
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
			countdown(5);
			LparagraphT();
			break;
		default: //5 혹은 이외의 수 입력시
			printf("프로그램을 종료합니다");
			sleep(1);
			break;
	}
}
