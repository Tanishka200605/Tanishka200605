#include<stdio.h>
int main(){
int num;
printf("\t\t\t *** Even Odd Finder *** \n\n\n");
printf("Enter Number: ");
scanf("%d", &num);
if(num%2==0){
printf("%d is Even", num);
}else{
printf("%d is Odd", num);
}
return 0;
}
