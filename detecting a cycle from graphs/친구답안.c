#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int M[50][50]; // 행렬의 최대 크기는 50

			   // Depth First Search for detecting cycles.
int DFS(int v, int size, int* visited, int* recStack) {
	int i;
	if (visited[v] == 0) { // if current vertex (v) has not been visited yet
		visited[v] = 1; // visit the vertex
		recStack[v] = 1; // push the vertex into a recursion stack
		for (i = 0; i < size; i++) { // for all vertices in the graph
			if (M[v][i] == 1) { // if current vertex (v) and next possible vertex (i) is connected
				if ((visited[i] == 0)) { // and the next possible vertex has not been visited
					if (DFS(i, size, visited, recStack) == 1) // visit the next vertex using Depth First Search
						return 1; // if the recursion function call returns 1
				}
				else if (recStack[i] == 1) { // if the next possible vertex has already been in recursion stack
					return 1; // There is a cycle
				}
			}
		}
	}
	recStack[v] = 0; // pop current vertex (v) from the recursion stack.
	return 0; // no cycles detected.
}


int detectCycle(int size) {
	int i, v;

	// Initialize visited memoization array, recursion logging stack
	int* visited = (int*)malloc(sizeof(int) * size);
	int* recStack = (int*)malloc(sizeof(int) * size);

	// Set initial state as 0s (not visited, not exist in recursion stack respectively)
	for (i = 0; i < size; i++) {
		visited[i] = 0;
		recStack[i] = 0;
	}

	// for all vertices in the graph
	for (v = 0; v < size; v++) {
		if (DFS(v, size, visited, recStack) == 1) // Do Depth First Search for the current vertex (v) = starting vertex (node)
			return 1; // if Depth First Search returns 1, there is a cycle.
	}

	// free dynamically allocated values
	free(visited);
	free(recStack);
	return 0;
}

int main() {
	FILE* inputFile;
	FILE* outputFile;

	int numCases;
	int size;

	int i, j, k;

	// 입력 파일 열기 
	inputFile = fopen("input.txt", "r");
	if (inputFile == NULL) {
		printf("File read error.\n");
		exit(100);
	}
	// 출력 파일 열기 
	outputFile = fopen("output.txt", "w");

	// 처리할 case의 수 읽기 
	fscanf(inputFile, "%d", &numCases);
	for (i = 0; i < numCases; i++) {
		fscanf(inputFile, "%d", &size);
		for (j = 0; j < size; j++) {
			for (k = 0; k < size; k++) {
				fscanf(inputFile, "%d", &M[j][k]);
			}
		}
		printf("%d\n", detectCycle(size));
		fprintf(outputFile, "%d\n", detectCycle(size));
	}
	fclose(inputFile);
	fclose(outputFile);

	return 0;
}