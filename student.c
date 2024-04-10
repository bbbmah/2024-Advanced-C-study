#include "student.h"

Student* createStudents(int n){ //n�� ��ŭ�� �л� ������ �� Student �迭 �����
   Student* student = malloc(sizeof(Student)*n);
   return student;
}

Student newStudent(char *name, int id){
   Student temp;
   temp.name = name;
   temp.id = id;
   return temp;
}

void appendStudent(Student *students, int index, Student student){
   students[index] = student;
}

void printStudents(FILE *output, Student *students, int length) { //length�� ����ŭ �ݺ�. ���Ͽ� �л� �̸��� �й��� ����.
  for (int i = 0; i < length; i++) {
    fprintf(output, "name: %s id: %d\n", students[i].name, students[i].id);
  }
}

void freeStudents(Student *students, int length){
   for(int i=0; i<length; i++){
      free(&students[i]);
   }
}
