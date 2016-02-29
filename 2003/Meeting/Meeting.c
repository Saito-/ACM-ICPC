#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int N, Q, M;
	int i, j, idx, num, date, ninzu;
	int sanka[100];
	char str[1000];
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
		date = 0; ninzu = 0;
		for (i = 0; i < 100; i++) {
			sanka[i] = 0;
		}
		fscanf(fp, "%d %d ", &N, &Q);
		if (N == 0 && Q == 0) break;
		for (i = 0; i < N; i++) {
			fgets(str, sizeof(str), fp);
			char* ch = str;
			M = atoi(ch);
			if (M == 0) {
				for (j = 0; j < 100; j++) {
					sanka[j]++;
				}
			} else {
				for (j = 0; j < M; j++) {
					ch = strchr(ch, ' ');
					ch++;
					sanka[atoi(ch)-1]++;
				}
			}
		}
		for (j = 0; j < 100; j++) {
			num = sanka[j];
			if (num >= Q && num > ninzu) {
				ninzu = num;
				date = j+1;
			}
		}
		printf("%d\n", date);
	}

	fclose(fp);
	return 0;
}
