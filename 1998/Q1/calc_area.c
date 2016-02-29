#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char str[128];
int count = 0;

void calc_area(int n, FILE* fp)
{
	int i;
	int *x, *y;
	double area = 0.0;
	x = (int*)calloc(n, sizeof(int));
	y = (int*)calloc(n, sizeof(int));

	for (i = 0; i < n; i++) {
		fgets(str, sizeof(str), fp);
		sscanf(str, "%d %d", x+i, y+i);
	}

	for (i = 0; i < n-1; i++) {
		area += (x[i] - x[i+1]) * (y[i] + y[i+1]);
	}
	area += (x[n-1] - x[0]) * (y[n-1] + y[0]);

	printf("%d\t%.1f\n", count, fabs(area) * 0.5);

	free(x); free(y);
}

int main(int argc, char* argv[])
{
	FILE* fp;
	int n = -1;
	int idx = 0;


	if (argc != 2) {
		fprintf(stderr, "Argument Error\n");
		return 1;
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "File Open Error\n");
		return 1;
	}

	while (fgets(str, sizeof(str), fp) != NULL) {
		n = atoi(str);
		if (n == 0) break;
		count++;
		calc_area(n, fp);
		fgets(str, sizeof(str), fp);
	}

	return 0;
}
