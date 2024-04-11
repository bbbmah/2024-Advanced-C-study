#include "sort.h"

int compareByName(Student a, Student b){ // a와 b를 이름 기준으로 비교, a가 작으면 -1, 같으면 0, b가 작으면 1 반환
   return strcmp(a.name, b.name);
}

int compareById(Student a, Student b){ // a와 b를 학번 기준으로 비교, a가 작으면 -1, 같으면 0, b가 작으면 1 반환
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

void quickSort(Student *students, int length, int (*compare)(Student, Student)){ //막매개변수에 비교할것의 비교함수를 넣음(함수포인터)
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
