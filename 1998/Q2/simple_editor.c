#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cursor_pos;
char txt[1000] = { '\0' };

char* cmds[] = {
	"forward",
	"backward",
	"delete",
	"insert"
};

char ops[][5] = { "char", "word" };

void forward(char *op)
{
	if (strcmp(op, ops[0]) == 0) {
		if (cursor_pos <= strlen(txt)) 
			cursor_pos++;
	}
	if (strcmp(op, ops[1]) == 0) {
		int i;
		for (i = cursor_pos; txt[i] != ' ' && txt[i] != '\0'; i++) {
			cursor_pos++;
		}
	}
}

void backward(char *op)
{
	if (strcmp(op, ops[0]) == 0) {
		if (cursor_pos > 0) 
			cursor_pos--;
	}
	if (strcmp(op, ops[1]) == 0) {
		int i;
		for (i = cursor_pos; txt[i] != ' ' && i > 0; i--) {
			cursor_pos--;
		}
	}
}

void delete(char *op)
{
	if (strcmp(op, ops[0]) == 0) {
		int i;
		for (i = cursor_pos; i < strlen(txt); i++) {
			txt[i] = txt[i+1];
		}
	}
	if (strcmp(op, ops[1]) == 0) {
		int i;
		int rshift;
		if (txt[cursor_pos] == ' ') {
			for (i = cursor_pos; txt[i] == ' ' && txt[i] != '\0'; i++) ;
			rshift = i - cursor_pos;
			for (i = cursor_pos; i < strlen(txt) - rshift; i++) {
				txt[i] = txt[i+rshift];
			}
			putchar('\n');
			txt[i] = '\0';
		} else {
			for (i = cursor_pos; txt[i] != ' ' && txt[i] != '\0'; i++) ;
			rshift = i - cursor_pos;
			for (i = cursor_pos; i < strlen(txt) - rshift; i++) {
				txt[i] = txt[i+rshift];
			}
			putchar('\n');
			txt[i] = '\0';
		}
	}
}

void insert(char *op)
{
	int i;
	
	for (i = 0; i < strlen(op); i++) {
		op[i] = op[i+1];
	}
	op[strlen(op)-1] = '\0';
	
	int len = strlen(op);
	for (i = strlen(txt); i >= cursor_pos; i--) {
		txt[i+len] = txt[i];
	}
	
	for (i = 0; i < len; i++) {
		txt[i+cursor_pos] = op[i];
	}
	cursor_pos += len + 1;
}

void exec_cmd(char* buf) 
{
	void (*p[])() = { forward, backward, delete, insert };
	int i;
	char cmd[100];
	char op[100];

	sscanf(buf, "%s", cmd);
	if (strcmp(cmd, cmds[3]) == 0) {
		for (i = strlen(cmd)+1; i < strlen(buf); i++) {
			op[i - strlen(cmd)-1] = buf[i];
		}
		op[strlen(op)-1] = '\0';
		(*p[3])(op);
	} else {
		sscanf(buf, "%s %s", cmd, op);
		for (i = 0; i < 3; i++) {
			if (strcmp(cmd, cmds[i]) == 0) {
				(*p[i])(op);
			}
		}
	}
}

void print_txt()
{
	int i;
	int len = strlen(txt);

	if (cursor_pos == len) {
		txt[cursor_pos] = '^';
		txt[cursor_pos+1] = '\0';

	} else {
		for (i = len; i >= cursor_pos-1; i--) {
			txt[i+1] = txt[i];
		}
		txt[cursor_pos-1] = '^';
	}

	printf("%s", txt);
}

int main(int argc, char* argv[])
{
	char buf[100];
	int num_of_txt;
	int num_of_cmd;
	int i, j;
	FILE* fp;

	if (argc != 2) {
		fprintf(stderr, "Argument Error\n");
		return 1;
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "File Open Error\n");
		return 1;
	}

	fgets(buf, sizeof(buf), fp);
	num_of_txt = atoi(buf);

	for (i = 0; i < num_of_txt; i++) {
		cursor_pos = 0;
		fgets(txt, sizeof(txt), fp);
		txt[strlen(txt)-1] = '\0';
		fgets(buf, sizeof(buf), fp);
		num_of_cmd = atoi(buf);
		for (j = 0; j < num_of_cmd; j++) {
			fgets(buf, sizeof(buf), fp);			
			exec_cmd(buf);
		}
		print_txt();
	}

	putchar('\n');
	return 0;
}
