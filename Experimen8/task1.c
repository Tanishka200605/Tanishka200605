#include<stdio.h>
int main(){
char str[100];
int length = 0;
printf("\t\t *** String Length Finder *** \n\n");
printf("Enter Your String:");
gets(str);
while(str[length] != '\0'){
length++;
}
printf("String Length: %d Charachters", length);
return 0;
}
