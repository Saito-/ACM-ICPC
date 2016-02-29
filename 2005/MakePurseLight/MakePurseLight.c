#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int pay, back;
	int i;
	int tags[4] = { 10, 50, 100, 500 };
	int coins[4] = { 0 };
	int use[4];
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
		for (i = 0; i < 4; i++) {
			use[i] = 0;
		}
		fscanf(fp, "%d ", &pay);
		if (pay == 0) break;
		fscanf(fp, "%d %d %d %d ", coins, coins+1, coins+2, coins+3);
		for (i = 0; i < 4; i++) {
			pay -= tags[i] * coins[i];
			use[i] += coins[i];
		}
		back = -pay;
		for (i = 3; i >= 0; i--) {
			while (back >= tags[i]) {
				back -= tags[i];
				use[i]--;
			}
		}
		for (i = 0; i < 4; i++) {
			if (use[i] > 0) {
				printf("%d %d\n", tags[i], use[i]);		
			}
		}
		putchar('\n');
	}
	
	fclose(fp);
	return 0;
}
