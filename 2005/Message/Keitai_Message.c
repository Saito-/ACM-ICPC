#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *btns[] = { 
	".,!? ", 
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz",
};


int main(int argc, char* argv[])
{
	int i, j, n, count, flg;
	char input[1024];
	FILE* fp;

	if (argc != 2) {
		fprintf(stderr, "Argument Error\n");
		return 1;
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "File Open Error\n");
		return 1;
	}

	fscanf(fp, "%d ", &n);

	for (i = 0; i < n; i++) {
		flg = 0;
		fgets(input, sizeof(input), fp);
		int len = strlen(input) - 1;
		for (j = 0; j < len; j++) {
			count = 0;
			int num = (input[j] - '0');
			if (num != 0) {
				flg = 1;
				do {
					count++;
					j++;
				} while ((input[j] - '0') == num);
				int idx = (count-1) % strlen(btns[num-1]);
				printf("%c", btns[num-1][idx]);
			}
		}
		if (flg == 1) 
			putchar('\n');
		else 
			i--;
	}

	fclose(fp);
	return 0;
}
