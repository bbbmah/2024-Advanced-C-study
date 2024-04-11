#include "sort.h"

int compareByName(Student a, Student b){ // a�� b�� �̸� �������� ��, a�� ������ -1, ������ 0, b�� ������ 1 ��ȯ
   return strcmp(a.name, b.name);
}

int compareById(Student a, Student b){ // a�� b�� �й� �������� ��, a�� ������ -1, ������ 0, b�� ������ 1 ��ȯ
   if(a.id<b.id){
      return -1;
   }
   else if(a.id == b.id){
      return 0;
   }
   else{
      return 1;
   }
}

void quickSort(Student *students, int length, int (*compare)(Student, Student)){ //���Ű������� ���Ұ��� ���Լ��� ����(�Լ�������)
   Student temp;
   for(int i = 0; i < length - 1 ; i++){
      for(int j = 0; j < length - i; j++){
         if(compare(students[j], students[j+1]) > 0){
            temp = students[j+1];
            students[j+1] = students[j];
            students[j] = temp;
         }
      }
   }
}
