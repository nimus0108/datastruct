#define STACK_SIZE 100
#include <stdio.h>
char stack[STACK_SIZE];
int sp=0;
/*
* Pushes character c onto the stack.
* Returns 0 if successful.
* Returns -1 if an error occurs. (Stack full).
*/
int push (char c)
{
    if((sp) == (STACK_SIZE)) return -1;
    stack[sp++] = c;
    return 0;
}
/*
* Pops next character off the stack.
* Returns the char if successful.
* Returns -1 if an error occurs. (Stack empty).
*/
int pop ()
{
    if((sp) == 0) return -1;
    return stack[--sp];
}
/*
* Reads one character at a time from stdin, checking that all (),
* {}, and [] in the file properly match.
*
* If an error in the input is found, an error specifying the line and
* character position in the file is printed for the user.
*/
int main ()
{
    char ch, temp, pushed, pulled;
    int error = 0;

    while((ch != EOF) && (error==0)){
        ch = getchar();
        printf("%c\n", ch);
        if ((ch=="(") || (ch=="{") || (ch=="[")){
            printf("yes");
            pushed = push(ch);
            if(pushed!=-1);
        }
        else if (ch==")" || ch=="}" || ch=="]"){
            pulled = pop();
            if(pushed!=pulled){
                printf("Errirrr");
            }
        }else {
            printf("%c\n", ch);
        }
    }

    if (error == 0){
        printf("test");
    }
}
