#include "student.h"

Student* createStudents(int n){ //n줄 만큼의 학생 정보가 들어갈 Student 배열 만들기
   Student* student = (Student*)malloc(sizeof(Student)*(n+1));
   return student;
}

Student newStudent(char *name, int id){
   Student temp;
   temp.name = malloc(strlen(name) + 1);
   strcpy(temp.name, name);
   temp.id = id;
   return temp;
}

void appendStudent(Student *students, int index, Student student){
   students[index] = student;
}

void printStudents(FILE *output, Student *students, int length) { //length의 수만큼 반복. 파일에 학생 이름과 학번을 쓴다.
  for (int i = 0; i < length; i++) {
    fprintf(output, "name: %s id: %d\n", students[i].name, students[i].id);
  }
}

void freeStudents(Student *students, int length){
   free(students); //여기 length가 왜 필요한지 모르겠ㅅ브니다;;
}
