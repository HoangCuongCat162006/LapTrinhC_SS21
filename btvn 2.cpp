#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char firstChar;

    file = fopen("bt01.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt.\n");
        return 1;
    }

    firstChar = fgetc(file);
    if (firstChar == EOF) {
        printf("File rong, khong co ky tu de hien thi.\n");
    } else {
        printf("Ky tu dau tien trong file la: '%c'\n", firstChar);
    }

    fclose(file);

    return 0;
}

