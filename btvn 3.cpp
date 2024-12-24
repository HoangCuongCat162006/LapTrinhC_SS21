#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char str[256];

    file = fopen("bt01.txt", "a");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt.\n");
        return 1;
    }

    printf("Nhap vao mot chuoi bat ky de ghi them: ");
    fgets(str, sizeof(str), stdin);

    fprintf(file, "%s", str);
    printf("Chuoi da duoc ghi them vao file bt01.txt.\n");

    fclose(file);

    return 0;
}

