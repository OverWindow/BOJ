#include <stdio.h>

void func(int num,int cnt){
	
	cnt += 1;
	
	for(int k = 0; k < 4; k++)
	{
		if(cnt > 1)
			for (int i = 0; i < 4*cnt - 4; i++)
				printf("_");
		switch(k){
			case 0: 
				printf("\"재귀함수가 뭔가요?\"\n");
				break;
			case 1:
				printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
				break;
			case 2:
				printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
				break;
			case 3:
				printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
				break;		
		}
	}
	
	if(cnt == num)
	{
		for(int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 4*cnt; i++)
				printf("_");	
			switch(k){
				case 0:
					printf("\"재귀함수가 뭔가요?\"\n");
					break;
				case 1:
					printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
					break;
				case 2:
					printf("라고 답변하였지.\n");
					break;
			}
		}
	}
	else
		func(num,cnt);
		
	if(cnt > 1)
			for (int i = 0; i < 4*cnt - 4; i++)
				printf("_");
	printf("라고 답변하였지.\n");
}


int main(void){
	int num,cnt = 0;
	scanf("%d",&num);
	
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	func(num,cnt);
}