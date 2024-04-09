#include <stdio.h>
#include <string.h>

extern char **environ;

int main()
{
    FILE *fp = fopen("./data", "r");
    int i = 0;

    for (i = 0; environ[i] != NULL; i++) {
        printf("environ[%d]: %s\n", i, environ[i]);
    }

    if (NULL != fp) {
        printf("open file success\n");
        fclose(fp);
    } else {
        if (strcmp(environ[19], "USER=phula") == 0) {
            printf("can not open file because program is run without privilege\n");
            return 0;
        }
        printf("can not open file\n");
    }

    return 0;
}