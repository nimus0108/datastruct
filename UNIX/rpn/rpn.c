#include <stdio.h>
#include <math.h>
#include "stack.h"

int main(){
	char c;
	int p, pushed=0, k=-2, error=1, charNum=1;
	double pop1, pop2, fo, num;
	c = getchar();

	while ((c!='\n') && (c!=-1)){
		//If number
		if(isdigit(c)){
			c = c - '0';
			// k=-1 if the previous input was an int
			if(k!=-1){
				num = c;
			} else {
				pop();
				num *= 10;
				num+=c;
			}

			pushed = push(num);
			if (pushed==-1){
				printf("Stack full error\n");
				error = -1;
				break;
			}
			k=-1;
		} 
		//If operator
		else if(c=='+' || c=='-' || c=='*' || c=='/'){

			if(getStackSize() < 2){
				printf("Input error at character %d (%c); too few arguments on stack.\n", charNum, c);
				error=-1;
				break;
			}
			else{
				pop1 = pop();
				pop2 = pop();
				
				if(c=='+'){
					fo = pop1 + pop2;
				} else if (c=='-'){
					fo = pop2 - pop1;
				} else if (c=='*'){
					fo = pop1*pop2;
				} else if (c=='/'){
					fo = pop2/pop1;
				}
				push(fo);
			}
			k=-2;
		}
		else {
			k=-2;
		}

		c = getchar();
		charNum++;
	}

	if(getStackSize()!=1){
		error = -1;
		printf("There are too few operators in the expression.\n");
	}
	if(error!=-1){
		printf("Result %.2f\n", fo);
	}
}