#include <stdio.h>
#include <stdlib.h>

int max(int* results, int n)
{
	int i;
	int max = results[0];
	for (i = 1; i < n; i++) {
		if (results[i] > max) max = results[i];
	}
	return max;
}

int main(int argc, char* argv[])
{
	int m, n, money, year, tesu, type, rishi;
	double riritu;
	int* results;
	int i, j, k;
	FILE* fp;

	if (argc != 2) {
		fprintf(stderr, "Argument Error\n");
		return 1;
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "File Open Error\n");
		return 1;
	}

	fscanf(fp, "%d ", &m);

	for (i = 0; i < m; i++) {
		fscanf(fp, "%d ", &money);
		fscanf(fp, "%d ", &year);
		fscanf(fp, "%d ", &n);
		results = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++) {
			rishi = 0;
			fscanf(fp, "%d %lf %d ", &type, &riritu, &tesu);
			int A = money;
			if (type == 0) {
				for (k = 0; k < year; k++) {
					int B = (int)(A * riritu);
					rishi += B;
					A -= tesu;
				}
				results[j] = A + rishi;
			} else {
				for (k = 0; k < year; k++) {
					int B = (int)(A * riritu);
					A = A+B-tesu;
				}
				results[j] = A;
			}
		}
		printf("%d\n", max(results, n));
	}


	free(results);
	fclose(fp);
	return 0;
}
