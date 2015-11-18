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
    if((sp) == (STACK_SIZE)-1) return -1;
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
    char ch, temp, pushed, expected;
    int error = 0;
    int pushedError = 0;
    int line = 1;
    int nc = 1;
    int pulled = 0;
    ch = getchar();

    while((ch != EOF) && (error==0)){
        nc++;
        if(pushed!=-1) pushed = ch;

        if (ch=='\n'){
            line++;
            nc = 1;
        }

        else if ((ch=='(') || (ch=='{') || (ch=='[')){
            error = push(ch);
            if(error==-1) 
                printf("Error: Stack Full!\n");
        }

        else if (ch==')' || ch=='}' || ch==']'){
            pulled = pop();
            if (pulled == -1) {
                printf("Line: %d, Char: %d, Found %c, No matching character.\n", line, (--nc), pushed);
                error = -1;
            }
            if((pulled=='('))
                expected=')';
            else if((pulled=='{'))
                expected='}';
            else if((pulled=='['))
                expected=']';
            if(pushed!=expected){
                printf("%c, %c\n", pushed, expected);
                printf("Line: %d, Char: %d, Found %c, expected %c\n", line, (--nc), pushed, expected); 
                error = -1;               
            }
        }
        ch = getchar();
    } 

    if (error == 0){
        printf("Well formatted input.\n");
    }
}
