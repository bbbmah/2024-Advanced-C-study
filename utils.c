#include "utils.h"

SortBy setSortBy(const char *filename) { //파일의 이름에 name / id 가 들어가있는지를 통해 무엇을 기준으로 정렬할 것인지 반환
    if (strstr(filename, "name")) {
        return NAME;
    }

    if (strstr(filename, "id")) {
        return ID;
    }

    exit(EXIT_FAILURE);
}

int countLines(FILE *input) { //줄 수(학생 수 반환)
    int count = 0;
    
    char line[MAX_BUFFER_SIZE];
    while (fgets(line, MAX_BUFFER_SIZE, input) != NULL) {
        count++;
    }

    rewind(input);
    
    return count;
}

void swap(Student *a, Student *b){ 
    //이건 어디 쓰는건지 진짜 모르겠습니다;;
}