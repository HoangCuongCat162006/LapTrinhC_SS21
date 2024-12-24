#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile;
    FILE *destFile;
    char ch;

    sourceFile = fopen("bt01.txt", "r");
    if (sourceFile == NULL) {
        printf("Khong the mo file bt01.txt.\n");
        return 1;
    }

    destFile = fopen("bt06.txt", "w");
    if (destFile == NULL) {
        printf("Khong the tao file bt06.txt.\n");
        fclose(sourceFile);
        return 1;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("Da sao chep noi dung tu bt01.txt sang bt06.txt.\n");

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}

