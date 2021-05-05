#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //char input[100];
    //char prompt[] = "prompt/> ";

    while (1) {
        printf("Please enter a line:\n");
        char *line = NULL;
        size_t len = 0;
        ssize_t lineSize = 0;
        lineSize = getline(&line, &len, stdin);
        printf("You entered %s, which has %zu chars.\n", line, lineSize - 1);
        free(line);
    }
}