#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char str[256];

    file = fopen("bt01.txt", "w");
    if (file == NULL) {
        printf("Khong the mo hoac tao file.\n");
        return 1;
    }

    printf("Nhap vào mot chuoi bat ki: ");
    fgets(str, sizeof(str), stdin);

    fprintf(file, "%s", str);
    printf("Chuoi da duoc ghi vao file bt01.txt.\n");

    fclose(file);

    return 0;
}

