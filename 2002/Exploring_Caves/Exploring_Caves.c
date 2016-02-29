#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	int i;
	int N;
	int x_pos, y_pos, dx, dy, treasure_x, treasure_y;
	double dist;
	FILE* fp;

	if (argc != 2) {
		fprintf(stderr, "Argument Error\n");
		return 1;
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "File Open Error\n");
		return 1;
	}

	fscanf(fp, "%d ", &N);

	for (i = 0; i < N; i++) {
		x_pos = 0; y_pos = 0;
		treasure_x = 0; treasure_y = 0;
		dist = 0.0;
		while (1) {
			fscanf(fp, "%d %d ", &dx, &dy);
			if (dx == 0 && dy == 0) {
				printf("%d %d\n", treasure_x, treasure_y);
				break;
			} else {
				x_pos += dx; 
				y_pos += dy;
				double tmp;
				tmp = sqrt(x_pos*x_pos + y_pos*y_pos);
				if (tmp > dist || (tmp == dist && x_pos > treasure_x)) {
					treasure_x = x_pos;
					treasure_y = y_pos;
					dist = tmp;
				} 
			}
		}
	}

	fclose(fp);
	return 0;
}
