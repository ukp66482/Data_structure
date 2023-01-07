#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[50][50];
int top = -1;

void push(char *str){
    strcpy(stack[++top],str);
}

char* pop(){
    return stack[top--];
}

int Is_operator_operand(char ch){   // operand return 1   operator return 0
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

char* postfix_to_prefix(const char *postfix){

    char* expr =(char*) malloc(sizeof (char)*50);
    char* top1 =(char*) malloc(sizeof (char)*50);
    char* top2 =(char*) malloc(sizeof (char)*50);

    char ch;
    char last[2];

    for(int i=0;postfix[i]!='\0';i++){

        ch = postfix[i];

        last[0] = ch;
        last[1] = '\0';

        if(Is_operator_operand(ch)) {

                strcpy(top1,pop());
                strcpy(top2,pop());
                strcpy(expr,last);
                strcat(expr,top2);
                strcat(expr,top1);
                push(expr);

        }else{
            push(last);
        }
    }

        free(expr);
        free(top1);
        free(top2);

    return stack[0];
}

int main() {

    char *postfix = malloc(sizeof (char)*50);

    scanf("%s",postfix);
    printf("%s",postfix_to_prefix(postfix));
    free(postfix);

    return 0;
}
