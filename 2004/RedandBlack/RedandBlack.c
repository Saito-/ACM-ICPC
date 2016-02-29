#include <stdio.h>
#include <stdlib.h>

int W, H, sx, sy, ans;
char map[20 + 1][20 + 1];

void search(int x, int y)
{
	if (x <= 0 || x > W || y <= 0 || y > H) return;
	if (map[y][x] == '#' || map[y][x] == 'o') return;
	
	ans++;
	map[y][x] = 'o';
	search(x+1, y);
	search(x, y-1);
	search(x-1, y);
	search(x, y+1);
	
}

int main(int argc, char* argv[])
{
	FILE* fp = fopen(argv[1], "r");
	int x, y;
	char line[256];
	while (1) {
		fscanf(fp, "%d %d ", &W, &H);
		if (W == 0 && H == 0) break;
		ans = 0;
		for (y = 1; y <= H; y++) {
			fgets(line, 256, fp);
			for (x = 1; x <= W; x++) {
				map[y][x] = line[x-1];
				if (map[y][x] == '@') {
					sx = x;
					sy = y;
				}
			}
		}
		search(sx, sy);
		printf("%d\n", ans);
	}

	fclose(fp);
	return 0;
}
