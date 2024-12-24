#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int numLines;
    char line[256];

    file = fopen("bt05.txt", "w");
    if (file == NULL) {
        printf("Khong the mo hoac tao file bt05.txt.\n");
        return 1;
    }

    printf("Nhap so dong can ghi vao file: ");
    scanf("%d", &numLines);
    getchar();

    for (int i = 0; i < numLines; i++) {
        printf("Nhap noi dung dong %d: ", i + 1);
        fgets(line, sizeof(line), stdin);
        fprintf(file, "%s", line);
    }

    fclose(file);

    file = fopen("bt05.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt05.txt de doc.\n");
        return 1;
    }

    printf("\nNoi dung trong file bt05.txt la:\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}

