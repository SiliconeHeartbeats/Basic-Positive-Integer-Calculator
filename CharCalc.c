#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int sort(void);

float compute(long num1, char op, long num2);

char input[25];

int main(){
	char cont[2];
	do{
	sort();
	printf("\nPress enter to evaluate another expression\n");
	fgets(cont,3,stdin);
	}
	while(*cont == '\n');
	return 0;

}	
int sort(){	
	
	int oppos = 0;
	int inputlength;
	
	
	char num1[10]={'0'};
	char num2[10]={'0'};
	char *end1,*end2;
	int i,j;
	printf("\nEnter integer expression to evaluate:");	
	fgets(input,20, stdin);
	inputlength = strcspn(input, "\n");    //marks input length while ignoring irrelevant characters
	input[strcspn(input,"\n")] = 0;       //removes newline character from input
  	oppos = strcspn(input, "/+*-");	      //finds position of operator in array
	
	int num2length = (inputlength-1) - (oppos+1); //find length of num2 array for use second for loop
	char opper = input[oppos];

	for(i=0; i <=(oppos-1); i++){	      //copies elements of input associated with first operand to dedicated array for first operand	
	num1[i] = *(input+i);		      
	}			
	num1[(oppos)] = '\0';		      //attaches \0 to end of array
	for(j=0;j <=num2length;j++){	      //copies elemts of input associated with second operand to dedicated array for second operand	
	num2[j] = *(input+(oppos+1)+j);
	}         		
	num2[num2length+1] = '\0';            
	
	long num01 = strtol(num1,&end1,10);   //converts string of char associated with first operand into an int long
	long num02 = strtol(num2,&end2,10);   //converts string of char associated with second operand into an int long
	
	compute(num01, opper, num02);


	return 0;
}

float compute(long num1, char op, long num2){
		float quotient;
		long  sum;
		long diff;
		long prod;		
	
		switch(op){
			case '+':		
			sum = num1 + num2;
			printf("\n%ld\n",sum);
			break;
			
			case '-':
			diff = num1 - num2;
			printf("\n%ld\n",diff);
			break;
			
			case '*':
			prod = num1 * num2;
			printf("\n%ld\n",prod);
			break;

			case '/':
			quotient = (float) num1 / num2;
			printf("\n%f\n",quotient);
			break;

		return 0;
		}
}
			











