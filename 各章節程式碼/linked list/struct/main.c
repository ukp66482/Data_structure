#include <stdio.h>
#include <string.h>

struct students{

    char id[20];
    char name[20];
    int chinese;
    int english;
    int math;
    int social;
    int science;
};
typedef struct students Student; //typedef (struct students) as Student


int main() {
    Student Willy;
    strcpy(Willy.id,"E34106010"); //char array cant assign but can use scanf %s to input the string
    strcpy(Willy.name,"黃偉峰");   //so we use the strcpy to copy the string into the array
    //Willy.id = "E34106010";
    //Willy.name = "黃偉峰";
    Willy.chinese = 100;
    Willy.english = 100;
    Willy.math = 100;
    Willy.social = 100;
    Willy.science = 100;

    printf("學生編號: %s\n", Willy.id);
    printf("姓名: %s\n", Willy.name);
    printf("國文成績: %d\n", Willy.chinese);
    printf("英文成績: %d\n", Willy.english);
    printf("數學成績: %d\n", Willy.math);
    printf("社會成績: %d\n", Willy.social);
    printf("自然成績: %d\n", Willy.science);



    return 0;
}
