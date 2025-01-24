#include <stdio.h>

int add(int *a, int *b, int *c) {
 return *a + *b + *c;
}

void error(const char *prompt, int *num){
 int validInput;
 do{
 printf("%s", prompt);
validInput = scanf("%d", num); 
while (getchar()!= '\n');
 if (!validInput) {
    printf("Invalid input. Please enter a valid integer.\n");
        }
}while (!validInput);
}


int main() {
  int num1, num2, num3, result;
error("Enter first integer: ", &num1);
error("Enter second integer: ", &num2);
error("Enter third integer: ", &num3);
 result = add(&num1, &num2, &num3);

printf("The sum of %d, %d, and %d is: %d\n", num1, num2, num3, result);

    return 0;
}
