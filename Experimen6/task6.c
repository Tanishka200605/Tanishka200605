#include<stdio.h>
void counter(){
static int count = 0;
count++;
printf("Counter Function Called : %d\n", count);
}
int main(){
printf("\t\t\t *** Storage Class *** \n\n");
counter();
counter();
counter();
counter();
return 0;
}
