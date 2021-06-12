#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int path = 1;
const int wall = 0;
const int check = 3;
int count = 0;
int map[101][101];
void clear(int a, int b) {
	for (int i = 0; i<a; i++) {
		for (int j = 0; j<b; j++) {
			map[i][j] = 0;
		}
	}
}
void find(int x, int y, int a, int b) {
	if (x < 0 || y < 0 || x >= a || y >= b) {
		return;
	}
	if (x == a - 1 && y == b - 1) {
		count++;
		if (count >= 1000000) {
			clear(a, b);
		}
		return;
	}
	map[x][y] = check;
	if (x >= 1 && x < a) {
		if (map[x - 1][y] == 1) {
			find(x - 1, y, a, b);
		}
	}
	if (x >= 0 && x < a - 1) {
		if (map[x + 1][y] == 1) {
			find(x + 1, y, a, b);
		}
	}
	if (y >= 0 && y < b - 1) {
		if (map[x][y + 1] == 1) {
			find(x, y + 1, a, b);
		}
	}
	map[x][y] = 1;
}
void init(int a, int b) {
	for (int i = 0; i<a; i++) {
		for (int j = 0; j<b; j++) {
			map[i][j] = 0;
		}
	}
	count = 0;
}
int main() {
	int n;
	int a, b;
	FILE *in = fopen("input.txt", "r");
	FILE *ot = fopen("output.txt", "w");
	while (feof(in) == 0) {
		fscanf(in, "%d ", &n);
		for (int i = 0; i<n; i++) {
			fscanf(in, "%d %d", &a, &b);
			init(a, b);
			for (int k = 0; k<a; k++) {
				for (int j = 0; j<b; j++) {
					fscanf(in, "%d ", &map[k][j]);
				}
			}
			find(0, 0, a, b);
			if (count >= 1) {
				fprintf(ot, "%d\n", count);
			}
			else {
				fprintf(ot, "%d\n", count);
			}
			printf("%d\n", count);
		}
	}
	fclose(in);
	fclose(ot);
	return 0;
}