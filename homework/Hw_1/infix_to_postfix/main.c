#include <stdio.h>
#include <stdlib.h>

char stack[40];
int top = -1;
int k=0;

char pop(){
    return stack[top--];
}

void push(char ch){
    stack[++top]=ch;
}

int Is_num_letter(char ch){
    return ((ch >= 'A' && ch <= 'Z')||(ch >= 'a' && ch <= 'z')||(ch >= '0' && ch <= '9'));
}

int priority(char op){
    switch (op) {

        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '(':
            return 0;
        default:
            return -1;
    }
}

char* infix_to_postfix(char* infix){

    char *post = (char*)malloc(sizeof (char)*50);
    int i;
    for( i=0; infix[i] != '\0'; i++){

        if(Is_num_letter(infix[i])){

            post[k++] = infix[i];

        }else if(infix[i] == '('){

            push(infix[i]);

        }else if (infix[i] == ')'){

            char op;
            while((op = pop())!='('){

                post[k++] = op;

            }
        }else{
            while(priority(stack[top]) >= priority(infix[i])){
                post[k++] = pop();
            }
            push(infix[i]);

        }
    }
    while(top!=-1){
        post[k++] = pop();
}
    post[k] = '\0';
    return  post;
}

int main() {

    char* infix = (char*)malloc(sizeof (char)*50);

    scanf("%s",infix);
    printf("%s", infix_to_postfix(infix));
    free(infix);

    return 0;
}
