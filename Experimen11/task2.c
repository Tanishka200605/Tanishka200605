#include <stdio.h>
#include <stdlib.h>
/* Define a structure to hold employee details */
struct candidate {
int id;
char name[50];
};
/* Function to add candidate details to the file */
void add_candidate() {
struct candidate cnd;
FILE *file = fopen("output/candidate_database.txt", "a");
if (file == NULL) {
printf("Error opening file!\n");
return;
}
/* Input employee details */
printf("Enter Candidate ID: ");
scanf("%d", &cnd.id);
printf("Enter Candidate Name: ");
getchar();
gets(cnd.name);
/* Write employee data to the file */
fprintf(file, "%d,%s\n", cnd.id, cnd.name);
fclose(file);
printf("Candidate record added successfully!\n");
}
/* Function to display all candidates records from the file */
void display_candidates() {
struct candidate cnd;
FILE *file = fopen("output/candidate_database.txt", "r");
if (file == NULL) {
printf("No candidate records found!\n");
return;
}
printf("\nCandidate Records:\n");
printf("ID\tName\n");
printf("---------------------------------\n");
/* Read and display each employee record from the file */
while (fscanf(file, "%d,%[^\n]", &cnd.id, cnd.name) != EOF) {
printf("%d\t%-15s\n", cnd.id, cnd.name);
}
fclose(file);
}
void start_voting() {
int id;
FILE *file = fopen("output/votes_database.txt", "a");
system("cls");
printf("!!! Vote for your Candidate !!!\n\n");
display_candidates();
printf("\n\nPlease enter candidate ID to Vote:");
scanf("%d", &id);
fprintf(file, "%d\n", id);
fclose(file);
printf("Your vote casted.");
}
void show_result() {
struct candidate candidates[30];
FILE *file = fopen("output/votes_database.txt", "a");
system("cls");
printf("!!! Voting Result !!!\n\n");
}
int main() {
int choice;
printf("\t\t *** Voting System *** \n\n");
while (1) {
/* Menu for user */
printf("\nVoting Menu:\n");
printf("1. Add Candidate\n");
printf("2. Display Candidates\n");
printf("3. Exit\n");
printf("4. Clear Screen\n");
printf("5. Start Voting\n");
printf("6. Show Result\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
add_candidate();
break;
case 2:
display_candidates();
break;
case 3:
printf("Exiting the program.\n");
return 0;
case 4:
system("cls");
break;
case 5:
start_voting();
break;
case 6:
show_result();
break;
default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;

}
