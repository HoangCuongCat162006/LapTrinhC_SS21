#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    int age;
} Student;

int main() {
    int numStudents;
    Student *students;
    FILE *file;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &numStudents);
    getchar(); // Xóa ký t? th?a sau khi nh?p s?

    students = (Student *)malloc(numStudents * sizeof(Student));
    if (students == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Nhap thong tin cho sinh vien thu %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);
        getchar();

        printf("Ten: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        size_t len = strlen(students[i].name);
        if (len > 0 && students[i].name[len - 1] == '\n') {
            students[i].name[len - 1] = '\0'; // Xóa ký t? xu?ng dòng
        }

        printf("Tuoi: ");
        scanf("%d", &students[i].age);
        getchar();
    }

    file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Khong the mo hoac tao file students.txt.\n");
        free(students);
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%d, %s, %d\n", students[i].id, students[i].name, students[i].age);
    }

    printf("Thong tin sinh vien da duoc luu vao file students.txt.\n");

    fclose(file);
    free(students);

    return 0;
}

