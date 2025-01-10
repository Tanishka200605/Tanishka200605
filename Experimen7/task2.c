#include<stdio.h>
int main(){
int rows,cols,i,j;
printf("\t\t *** Add Arrays *** \n\n");
printf("Enter Array Size (row,column):");
scanf("%d,%d", &rows, &cols);
int arr_a[rows][cols], arr_b[rows][cols], sum[rows][cols];
printf("Enter First Array Elements:\n");
for(i = 0; i < rows; i++){
for(j = 0; j < cols; j++){
printf("%d,%d: ",i,j);
scanf("%d", &arr_a[i][j]);
}
}
printf("\n");
printf("Enter Second Array Elements:\n");
for(i = 0; i < rows; i++){
for(j = 0; j < cols; j++){
printf("%d,%d: ",i,j);
scanf("%d", &arr_b[i][j]);
}
}
printf("\n");
printf("Sum of both Arrays:\n");
for(i = 0; i < rows; i++){
for(j = 0; j < cols; j++){
sum[i][j] = arr_a[i][j] + arr_b[i][j];
printf("%d ", sum[i][j]);
}
printf("\n");
}
return 0;
}
