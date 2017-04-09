//Gregory Brewster and Xiaoliang He

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dynamicArray.h"
//#include "dynamicArray.c"
/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	//printf("passed valuse are: %c and %f\n",*s,*num);
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		//printf("Setting pointer *num to %f\n", *num);
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			//printf("Setting pointer *num to %f\n", *num);
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}
void checkArrSize(struct DynArr *stack)
{
         if(stack->size < 2) {
                 printf("\nFatal error, please check your input!\n");
                 exit(0);
         }
}


/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add(struct DynArr *stack)
{
	double sum;
	checkArrSize(stack);
	sum = stack->data[stack->size-2] +  stack->data[stack->size-1];
	popDynArr(stack);
	popDynArr(stack);	
	addDynArr(stack, sum);
	//printf("size of stack is %d and temp sum is %f and stack value at size is %f\n",stack->size, sum, stack->data[stack->size-1]);
	printf(" +\n");
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double minus;
	minus =  stack->data[stack->size-2] - stack->data[stack->size-1];
	popDynArr(stack);
	popDynArr(stack);
	addDynArr(stack, minus);
	//printf("size of stack is %d and temp minus is %f and stack value at size is %f\n",stack->size, minus, stack->data[stack->size-1]);
	printf(" -\n");
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	double divide;
        checkArrSize(stack);
        divide = stack->data[stack->size-2] / stack->data[stack->size-1];
        popDynArr(stack);
        popDynArr(stack);
        addDynArr(stack, divide);
        printf(" /\n");
}
void multiply (struct DynArr *stack)
{
        double multiply;
        checkArrSize(stack);
        multiply = stack->data[stack->size-2] * stack->data[stack->size-1];
        popDynArr(stack);
        popDynArr(stack);
        addDynArr(stack, multiply);
        printf(" \n*\n");
}
void power (struct DynArr *stack)
{	
        double power;
	checkArrSize(stack);
        power = pow( stack->data[stack->size-2],  stack->data[stack->size-1]);
        popDynArr(stack);
	popDynArr(stack);
        addDynArr(stack, power);
        printf(" \n^\n");
}

void square (struct DynArr *stack)
{
        double square;
        square = pow(stack->data[stack->size-1], 2);
        popDynArr(stack);
        addDynArr(stack, square);
        printf(" \nsquare\n");
}

void cube (struct DynArr *stack)
{
        double cube;
        cube = pow(stack->data[stack->size-1], 3);
        popDynArr(stack);
        addDynArr(stack, cube);
        printf(" \ncube\n");
}

void abso (struct  DynArr *stack)
{
        double abso;
        abso = fabs(stack->data[stack->size-1]);
        popDynArr(stack);
        addDynArr(stack, abso);
        printf(" \nabs\n");
}

void sqf (struct DynArr *stack)
{
        double sqVar;
        sqVar = sqrt(stack->data[stack->size-1]);
        popDynArr(stack);
        addDynArr(stack, sqVar);
        printf(" \nsqrt\n");
}

void expo (struct DynArr *stack)
{
        double ex;
        ex = exp(stack->data[stack->size-1]);
        popDynArr(stack);
        addDynArr(stack, ex);
        printf(" \nexp\n");
}

void logg (struct DynArr *stack)
{
        double logger;
        logger = log(stack->data[stack->size-1]);
        popDynArr(stack);
        addDynArr(stack, logger);
        printf(" \nln\n");
}

void logg10(struct DynArr *stack)
{
        double log;
        log = log10(stack->data[stack->size-1]);
        popDynArr(stack);
        addDynArr(stack, log);
        printf(" \nlog10\n");
}


double calculate(int numInputTokens, char **inputString)
{
	int i, limit=0;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);
	
	printf("testing info! numInputTOkesn: %d\n", numInputTokens);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0){
			add(stack);
			limit = 0; }
		else if(strcmp(s,"-") == 0){
			subtract(stack);
			limit = 0; }
		else if(strcmp(s, "/") == 0){
			divide(stack);
			limit = 0; }
		else if(strcmp(s, "x") == 0){
			multiply(stack);
			limit = 0; }
		else if(strcmp(s, "^") == 0){
			power(stack);
			limit = 0;
			}
		else if(strcmp(s, "^2") == 0){
			square(stack);
			limit = 0;
			}
		else if(strcmp(s, "^3") == 0 ){
			cube(stack);
			limit = 0;
			}
		else if(strcmp(s, "abs") == 0){
			abso(stack);
			limit = 0;
			}
		else if(strcmp(s, "sqrt") == 0){
			sqf(stack);
			limit = 0;
			}
		else if(strcmp(s, "exp") == 0){
			expo(stack);
			limit = 0;
			}
		else if(strcmp(s, "ln") == 0){
			logg(stack);
			limit = 0;
			}
		else if(strcmp(s, "log") == 0){
			logg10(stack);
			limit = 0;
			}
		else 
		{
			if(limit >=2){
				printf("\nLimit has been reached! You did something wrong!\n");
				break;
			}
			//printf("%c is not an operator! converting to a a number!\n",*s);
			int isNum;
			double num = 0;
			isNum = isNumber(s, &num);
			if(isNum == 1){
				//Is infact a number, push to stack
				pushDynArr(stack, num);
				limit++;
				//printf("value %f is now pushed to the statck\n", num);
				printf("\n%f", num);
				
			}else{
				if(strcmp(s, "pi") == 0){
					pushDynArr(stack, 3.144159265);
					printf("\n3.144159265");
					limit++;
				}else if(strcmp(s, "e") == 0){
					pushDynArr(stack, 2.7182818);
					limit++;
					printf("\n2.7182818");
				}else{
					//ignore because it is not a number
					printf("\nPosition %d is not a number, ignoring...\n", i+1);
				}
			}
				//limit is more than 2, this should not happen!
			// Remember to deal with special values ("pi" and "e")
			
		}
	}	//end for 
	
	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	if( stack->size > 1){
		//something went wrong
		printf("\nError computing value, check your entry!\n");
	}else{
	result = topDynArr(stack);
	}
	
	return result;
}

int main(int argc , char** argv)
{
	double result;
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;
	result = calculate(argc,argv);

	printf("--------------\n%f\n",result);
	return 0;
}
