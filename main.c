#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"

int main(
        int argc,
        char **argv) {
    assert(argc > 1);
    // argv[1] contains the configuration file name
    // e.g. ./main config.json
    FILE * fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("The file %s could not be opened\n", argv[1]);
        exit(2);
    }
    char *line = malloc(sizeof(char)*256);
    size_t lineLength;
    getline(&line, &lineLength, fp);
    line[strlen(line)-1] = 0x00;
    double myBase, myExp;
    if (strcmp(line, "[PARAMS]") == 0) {
        getline(&line, &lineLength, fp);
        char *token = strtok(line, " =");
        myBase = atof(strtok(NULL, " ="));
        getline(&line, &lineLength, fp);
        token = strtok(line, " =");
        myExp = atof(strtok(NULL, " ="));
    }
    double result = numberToThe(myBase, myExp);
    printf("%lf to the %lf is equal to %lf\n", myBase, myExp, result);
    fclose(fp);
    return 0;
}
