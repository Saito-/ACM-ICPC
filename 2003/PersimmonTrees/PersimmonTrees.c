#include <stdio.h>
#include <stdlib.h>

int N, W, H, S, T;
int field[100][100];

void init()
{
	int x, y;
	for (y = 1; y <= H; y++) {
		for (x = 1; x <= W; x++) {
			field[y][x] = 0;
		}
	}
}

void print()
{
	int x, y;
	for (y = 1; y <= H; y++) {
		for (x = 1; x <= W; x++) {
			printf("%d ", field[y][x]);
		}
		putchar('\n');
	}
}

int main(int argc, char* argv[])
{
	FILE* fp = fopen(argv[1], "r");
	int i, j, x, y;

	while (1) {
		fscanf(fp, "%d ", &N);
		if (N == 0) break;
		int ans = 0;
		fscanf(fp, "%d %d ", &W, &H);
		init();
		for (i = 0; i < N; i++) {
			fscanf(fp, "%d %d ", &x, &y);
			field[y][x] = 1;
		}
		fscanf(fp, "%d %d ", &S, &T);
		for (y = 1; y <= H-T+1; y++) {
			for (x = 1; x <= W-S+1; x++) {
				int count = 0;
				for (j = y; j <= y+T-1; j++) {
					for (i = x; i <= x+S-1; i++) {
						count += field[j][i];
					}
				}
				if (count > ans) ans = count;
			}
		}
		printf("%d\n", ans);
	}
	
	fclose(fp);
	return 0;
}
