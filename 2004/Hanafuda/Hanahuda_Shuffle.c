#include <stdio.h>
#include <stdlib.h>

int *p_arr, *c_arr;

void cut(int* hanafuda, int n, int p, int c)
{
	int i;
	p_arr = (int*)malloc((p-2) * sizeof(int));
	c_arr = (int*)malloc(c * sizeof(int));

	for (i = 0; i < p-1; i++) {
		p_arr[i] = hanafuda[i];
	}

	for (i = 0; i < c; i++) {
		c_arr[i] = hanafuda[i+p-1];
	}
	
	for (i = 0; i < c; i++) {
		hanafuda[i] = c_arr[i];
	}

	for (i = 0; i < p-1; i++) {
		hanafuda[c+i] = p_arr[i];
	}
	/*
	for (i = 0; i < p-1; i++) {
		printf("p_arr[%d]: %d\n", i, p_arr[i]);
	}

	for (i = 0; i < c; i++) {
		printf("c_arr[%d]: %d\n", i, c_arr[i]);
	}
	*/
	
}

int main(int argc, char* argv[])
{
	int n, r, p, c;
	int* hanafuda;
	int i;
	FILE* fp;

	if (argc != 2) {
		fprintf(stderr, "Argument Error\n");
		return 1;
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "File Open Error\n");
		return 1;
	}

	while (1) {
		fscanf(fp, "%d %d ", &n, &r);
		if (n == 0 && r == 0) break;
		hanafuda = (int*)malloc(n * sizeof(int));
		for (i = 0; i < n; i++) {
			hanafuda[i] = n-i;
		}
		for (i = 0; i < r; i++) {
			fscanf(fp, "%d %d ", &p, &c);
			cut(hanafuda, n, p, c);
		}
		printf("%d\n", hanafuda[0]);
	}

	free(hanafuda);
	free(p_arr); free(c_arr);
	fclose(fp);
	return 0;
}
