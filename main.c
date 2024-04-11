#include "student.h"
#include "sort.h"
#include "utils.h"

int main(int argc, char* argv[]) { // [TODO] Fill in the parameters
    FILE *input, *output;
    char *filename;

    if (strcmp(argv[1],"try/id_sort.in") != 0 || strcmp(argv[1],"try/name_sort.in") != 0) { // [TODO] Fill in the condition //argv�� ���ϸ�(����)�� ������ ��Ȯ�� �Ͱ� �ٸ��ٸ�
        fprintf(stderr, "Command should be format like below\n");
        fprintf(stderr, "%s try/*_sort.in\n", argv[0]); // [TODO] Fill in the arguments ��Ȯ�� ���� �Է�
        exit(EXIT_FAILURE);
    }

    filename = strdup(argv[1]); // [TODO] Fill in the arguments //�ԷµǴ� ���ϸ� �Է�
    input = fopen(filename, "r"); //�Էµ� ���ϸ����� ������ ����.
    if (input == NULL) {
        fprintf(stderr, "Input file error\n");
        exit(EXIT_FAILURE);
    }

    strcpy(strstr(filename, "in"), "out");//filename�� in�� out���� ��ȯ
    output = fopen(filename, "w");//[filename].out�� ����
    if (output == NULL) {//[filename].out�� ������ ������
        fprintf(stderr, "Output file error\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_BUFFER_SIZE];
    int length = countLines(input); //�л���
    int index = 0;
    Student *students = createStudents(length); // [TODO] Fill in the arguments //�л� ������ �� Student�迭 �����

    while (fgets(line, MAX_BUFFER_SIZE, input) != NULL) { //������ �� �پ� �д´�.
        char name[MAX_BUFFER_SIZE];
        int id;

        sscanf(line, "name: %s major: %*s id: %d", name, &id); // [TODO] Fill in the arguments
        appendStudent(students, index, newStudent(name, id)); // [TODO] Fill in the arguments //creatStudent���� ���� �迭�� �Է¹��� �л� ���� �ֱ�
    }

    SortBy sortBy = setSortBy(filename); // [TODO] Fill in the arguments //������ ���� �ޱ� ()
    switch (sortBy) {
    case NAME:
        quickSort(students, length, compareByName); // [TODO] Fill in the arguments // students �迭 �ӿ��� sort�ϱ�
        printStudents(output, students, length); // [TODO] Fill in the arguments //sort�� ���� ���Ͽ� �Է��ϱ�
        break;
    
    case ID:
        quickSort(students, length, compareById); // [TODO] Fill in the arguments
        printStudents(output, students, length); // [TODO] Fill in the arguments
        break;

    default:
        exit(EXIT_FAILURE);
    }
    
    freeStudents(students, length); // [TODO] Fill in the arguments
    free(filename);
    fclose(input);
    fclose(output);

    return 0;
}
