#include<stdio.h>
#include<string.h>
int main(){
char str[100];
int i;
printf("\t\t *** Palindrome Finder *** \n\n");
printf("Enter Your String:");
gets(str);
// 012345678
// malayalam
for(i = 0; i < strlen(str) - 1; i++){
if(str[i] != str[strlen(str) - 1 - i]){
printf("The String is NOT a Palindrome");
return 0;
}
}
printf("The String is a Palindrome");
return 0;
}
