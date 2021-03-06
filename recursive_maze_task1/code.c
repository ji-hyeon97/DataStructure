#define _CRT_SECURE_NO_WARNINGS//Visual Studio환경에서 보안문제때문에 일단 보안문제로 일어나는 것들은 해결하겠습니다.
#include<stdio.h>
#include<stdlib.h>//동적할당 malloc, free를 사용하기 위해 작성하였습니다.
const int path = 1;//1은 지나갈수 있는 길임으로 path라는 변수 선언하였고 이는 작업시 값변화에 영향을 받아서는 안되므로 const로 고정시켜주었습니다 
const int wall = 0;//0은 지나갈수 없는 길임으로 wall라는 변수 선언하였고 이는 작업시 값변화에 영향을 받아서는 안되므로 const로 고정시켜주었습니다 
const int check = 3;//3은 임으로 제가 만든 값이고 지났던길을 check라는 표시를 해주었습니다.
int find(int ***map, int x, int y, int a, int b) {//map을 이중포인터로 동적할당을 받았기에 삼중포인터로 참조할수 있도록 하였고 a는 행 b는 렬값입니다.
	if (x<0 || y<0 || x >= a || y >= b) {//행렬값이 좌표가 map에 없거나 map을 벗어나면 
		return 0;//0을 리턴합니다
	}
	else if ((*map)[x][y] != path) {//지나갈수 있는길 즉 1이 아니라면
		return 0;//0을 리턴합니다
	}
	else if (x == a - 1 && y == b - 1) {//도착지점에서
		(*map)[x][y] = path;//마지막 도착지점의 값은 1입니다
		return 1;//리턴 1을 해줍니다
	}
	else {
		(*map)[x][y] = check;//탐색하며 지났던곳은 체크해줍니다
		if (find(map, x + 1, y, a, b) || find(map, x, y + 1, a, b) || find(map, x - 1, y, a, b)) {//본격적인 재귀함수입니다 or논리연산자를 통해 하나라도 참이면 참이 되게 만들어 주었고 아래, 오른쪽, 위의 방향순서대로 탐색을 할수있도록 재귀함수를 작성하였습니다
			return 1;//1을 반환해줍니다
		}
		return 0;//0을 반환해줍니다
	}
}void init(int ***map, int a, int b) {//맵을 초기화 해줍니다
	for (int i = 0; i<a; i++) {//행
		for (int j = 0; j<b; j++) {//렬
			(*map)[i][j] = 0;//모든값을 0으로 합니다.
		}
	}
}
int main() {
	int n;//100을 받는 변수로 만든것입니다
	int a, b;//행렬의 크기를 받기 의해 만든 변수입니다
	FILE *in = fopen("input.txt", "rt");//파일입출력 input.txt파일 읽기
	FILE *ot = fopen("output.txt", "wt");//파일입출력 output.txt파일 쓰기(출력)
	while (feof(in) == 0) {//input.txt파일이 끝날때까지
		fscanf(in, "%d ", &n);//100을 받습니다
		for (int i = 0; i<n; i++) {//반복문 100번합니다
			fscanf(in, "%d %d", &a, &b);//행렬의 크기를 받습니다
			int **map = (int**)malloc(sizeof(int*)*(a));//이차원배열 동적할당 받는거여서 이중포인터를 사용하였고 우선 행의 수만큼 동적할당을 받습니다
			for (int k = 0; k < a; k++) {//행의 수만큼 
				map[k] = (int*)malloc(sizeof(int)*b);//각 행마다 열의 개수만큼 동적할등을 받습니다
			}
			init(&map, a, b);//우선 이차원배열 map을 초기화 시켜줍니다 이유는 행렬이 100개가 있어서 1개끝날때 마다 초기화를 시켜주어야합니다.
			for (int k = 0; k<a; k++) {//행
				for (int j = 0; j<b; j++) {//렬
					fscanf(in, "%d ", &map[k][j]);//행렬을 입력받습니다
				}
			}
			if (find(&map, 0, 0, a, b)) {//find함수가 1을 반환한경우
				fprintf(ot, "%d\n", 1);//output.txt에 1을 출력하게 합니다
				printf("%d\n", 1);//즉석으로 보시기 편하게 콘솔창도 만들었습니다
			}
			else {//find함수가 0을 반환한 경우
				fprintf(ot, "%d\n", 0);//output.txt에 0을 출력하게 합니다
				printf("%d\n", 0);//즉석으로 보시기 편하게 콘솔창도 만들었습니다.
			}
			for (int i = 0; i < a; i++) {//행의 개수만큼 반복
				free(map[i]);//각 행에 열의 개수 만큼있는 동적할당 해제 
			}
			free(map);//이차원 배열 동적할당 해제완료

		}
	}
	fclose(in);//input.txt파일 닫기
	fclose(ot);//output.txt파일 닫기
	return 0;//0반환
}