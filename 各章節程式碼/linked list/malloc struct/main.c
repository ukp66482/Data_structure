#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char* id;
    char* name;
    int score;
}Student;


int main() {

    int numStudent = 2;

    Student *A = (Student *) malloc(sizeof(*A) * numStudent); //open a A class ptr
    for (int i = 0; i < numStudent; i++) {

        A[i].id = (char *) malloc(sizeof(char*));
        printf("Please enter the student id: ");
        scanf("%s",A[i].id);                                //cant use & cuz it is address

        A[i].name = (char *)malloc(sizeof(char*));
        printf("Please enter the student name: ");
        scanf("%s",A[i].name);

        A[i].score = (int )malloc(sizeof(int));
        printf("Please enter the student's score: ");
        scanf("%d",&A[i].score);
    }

    printf("\n");

    for(int i=0;i<2;i++){
        printf("ID : %s\n",A[i].id);
        printf("Name: %s\n",A[i].name);
        printf("Score %d\n",A[i].score);
}




    return 0;
}
