#define MAXSIZE 10

#include <stdio.h>
int array[MAXSIZE];
int pos = 0;
int total = 0;

void printNumbers (){
    int i;
    printf("The numbers are: ");
    for (int i=0; i<pos; i++){
        printf("%d", array[i]);
    }
    printf("\n");
}

int addNumber (int num){
    if (pos == MAXSIZE)
        return -1;
    array[pos++] = num;

    total +=num;
    return 0;
}

int main () {
    int ch;
    int error = 0;
    int currentNum = 0;

    ch = getChar();
    while((ch != EOF) && (error==0)){
        if (isdigit(ch)){
            currentNum = (currentNum * 10) + (ch - '0');
        } else if (currentNum > 0){
            addNumber(currentNum);
            currentNum = 0;
        }
        ch = getChar;
    }

    if (error == 0){
        printNumbers();
        printf("The sum is: %d", total);
    } else {
        printf("Too many numbers.");
    }


}
