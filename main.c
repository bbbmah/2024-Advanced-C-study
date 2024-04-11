#include "student.h"
#include "sort.h"
#include "utils.h"

int main(int argc, char* argv[]) { // [TODO] Fill in the parameters
    FILE *input, *output;
    char *filename;

    if (strcmp(argv[1],"try/id_sort.in") != 0 && strcmp(argv[1],"try/name_sort.in") != 0) { // [TODO] Fill in the condition //argv속 파일명(추정)의 포멧이 정확한 것과 다르다면
        fprintf(stderr, "Command should be format like below\n");
        fprintf(stderr, "%s try/*_sort.in\n", argv[0]); // [TODO] Fill in the arguments 정확한 포멧 입력
        exit(EXIT_FAILURE);
    }

    filename = strdup(argv[1]); // [TODO] Fill in the arguments //입력되는 파일명 입력
    input = fopen(filename, "r"); //입력된 파일명으로 파일을 연다.
    if (input == NULL) {
        fprintf(stderr, "Input file error\n");
        exit(EXIT_FAILURE);
    }

    strcpy(strstr(filename, "in"), "out");//filename의 in을 out으로 변환
    output = fopen(filename, "w");//[filename].out을 열기
    if (output == NULL) {//[filename].out이 열리지 않으면
        fprintf(stderr, "Output file error\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_BUFFER_SIZE];
    int length = countLines(input); //학생수
    int index = 0;
    Student *students = createStudents(length); // [TODO] Fill in the arguments //학생 정보가 들어갈 Student배열 만들기

    while (fgets(line, MAX_BUFFER_SIZE, input) != NULL) { //파일을 한 줄씩 읽는다.
        char name[MAX_BUFFER_SIZE];
        int id;

        sscanf(line, "name: %s major: %*s id: %d", name, &id); // [TODO] Fill in the arguments
        appendStudent(students, index++, newStudent(name, id)); // [TODO] Fill in the arguments //creatStudent에서 만든 배열에 입력받은 학생 정보 넣기
    }

    SortBy sortBy = setSortBy(filename); // [TODO] Fill in the arguments //정렬할 기준 받기 ()
    switch (sortBy) {
    case NAME:
        quickSort(students, length, compareByName); // [TODO] Fill in the arguments // students 배열 속에서 sort하기
        printStudents(output, students, length); // [TODO] Fill in the arguments //sort한 것을 파일에 입력하기
        break;
    
    case ID:
        quickSort(students, length, compareById); // [TODO] Fill in the arguments
        printStudents(output, students, length); // [TODO] Fill in the arguments
        break;

    default:
        exit(EXIT_FAILURE);
    }
    
    //freeStudents(students, length); // [TODO] Fill in the arguments
    free(students); //수정요함
    free(filename);
    fclose(input);
    fclose(output);

    return 0;
}
