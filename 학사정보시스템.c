#include <stdio.h>
#include <string.h>

// 학생 정보를 저장할 구조체 정의
typedef struct {
    char name[31];
    char id[9];
    int numSubjects;
    char subjectNames[10][31];
    double subjectGrades[10];
} Student;

// 전체 학생 정보를 저장할 배열 선언
Student students[100];
int numStudents = 0;

// 학생 정보 입력 함수
void addStudent() {
    scanf("%s %s %d", students[numStudents].name, students[numStudents].id, &students[numStudents].numSubjects);
    for (int i = 0; i < students[numStudents].numSubjects; i++) {
        scanf("%s %lf", students[numStudents].subjectNames[i], &students[numStudents].subjectGrades[i]);
    }
    numStudents++;
}

// 학생 정보 출력 함수 (이름 순으로 정렬 후 출력)
void printStudents() {
    // 이름 순으로 정렬 (버블 정렬 사용)
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                // 이름이 더 큰 경우, 두 학생 정보를 교환
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // 정렬된 학생 정보 출력
    for (int i = 0; i < numStudents; i++) {
        double totalGrade = 0.0;
        for (int j = 0; j < students[i].numSubjects; j++) {
            totalGrade += students[i].subjectGrades[j];
        }
        double avgGrade = totalGrade / students[i].numSubjects;

        printf("%s %s %d %.2lf\n", students[i].name, students[i].id, students[i].numSubjects, avgGrade);
    }
}

// 학생 정보 삭제 함수
void deleteStudent(char *nameToDelete) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, nameToDelete) == 0) {
            // 학생 이름이 일치하는 경우, 해당 학생 정보를 삭제
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            break; // 삭제가 완료되었으므로 반복문 종료
        }
    }
}

int main() {
    char command;

    while (1) {
        scanf(" %c", &command); // 명령을 입력받음

        if (command == 'I') {
            addStudent();
        } else if (command == 'S') {
            printStudents();
        } else if (command == 'D') {
            char nameToDelete[31];
            scanf("%s", nameToDelete);
            deleteStudent(nameToDelete);
        } else if (command == 'P') {
            printStudents();
        } else if (command == 'Q') {
            break; // 종료
        }
    }

    return 0;
}
