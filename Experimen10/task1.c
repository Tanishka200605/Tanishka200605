#include <stdio.h>
int main() {
int num1, num2, sum;
int *ptr1, *ptr2;
printf("\t\t *** Addition using Pointers *** \n\n");
// Input two numbers
printf("Enter first number: ");
scanf("%d", &num1);
printf("Enter second number: ");
scanf("%d", &num2);
// Assign the addresses of num1 and num2 to the pointers
ptr1 = &num1;
ptr2 = &num2;
// Add the values pointed to by ptr1 and ptr2
sum = *ptr1 + *ptr2;
// Display the result
printf("Sum of %d and %d is: %d\n", num1, num2, sum);
return 0;
}
