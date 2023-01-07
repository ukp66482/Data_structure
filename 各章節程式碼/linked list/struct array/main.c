#include<stdio.h>
#include<string.h>

struct Student
{
    int rollNumber;
    char studentName[10];
    float percentage;
};

int main(void)
{
    int counter;
    struct Student studentRecord[5];

    printf("Enter Records of 5 students");

    for(counter=0; counter<5; counter++)
    {
        printf("\nEnter Roll Number:");
        scanf("%d",&studentRecord[counter].rollNumber);
        printf("\nEnter Name:");
        scanf("%s",&studentRecord[counter].studentName);
        printf("\nEnter percentage:");
        scanf("%f",&studentRecord[counter].percentage);

    }

    printf("\nStudent Information List:");

    for(counter=0; counter<5; counter++)
    {
        printf("\nRoll Number:%d\t Name:%s\t Percentage :%f\n",
               studentRecord[counter].rollNumber,studentRecord[counter].studentName, studentRecord[counter].percentage);
    }
    return 0;
}