#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool debug = true;

char error_message[30] = "An error has occurred\n";
enum command {finish, error} cmd;
enum runMode {batch, interactive} mode;

enum command parseCmd(char *);

int main(int argc, char *argv[]) {
	bool stop = false;

	FILE *fp;
	fp = fopen(argv[1],"r");
	if(fp >= 0) mode = batch;
	else mode = interactive;

	while (!stop)
	{
		char *line = NULL;
		size_t len = 0;
		ssize_t read;
		printf("%s ", "grsh> ");
		read = getline (&line, &len, stdin);
		printf("You entered %s, which has %zu chars.\n", line, len - 1);
        
		char* rawrest;
		if(debug) puts("31before tok");
		char* rawcmd = strtok_r(line, " ", &rawrest);
		printf("toked cmd is %s", rawcmd);
		if(debug) puts("33before parse");
		cmd = parseCmd(rawcmd);
		if (cmd == finish)
		{
			puts("exiting...");
			goto OUTDONE;
		}
		else{
			goto OUTERR;
		}
		free(line);
		
	}
	// return 0;

	OUTERR:
	{
		puts(error_message);
		return 1;
	}

	OUTDONE: 
	{
		puts("have a good day.");
		return 0;
	}
}

enum command parseCmd(char *arg)
{
	enum command toReturn;
	char finishStr[] = "exit";
	//char* arg2;
	//strcpy(arg2, arg);
	puts("parsing");
	//puts(finishStr);
	puts(arg);
	if (0 == strcmp(finishStr, arg))
	{
		toReturn = finish;
	}
	else
		toReturn = error;
	return toReturn;
}
