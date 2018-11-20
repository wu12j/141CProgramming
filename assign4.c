/*
   Assignment 4
   
   Objective:  Write a C program that uses string processing functions to properly format a Comma Separated
   Values (csv) file of course Information and store them into an array of structures. 
   
   Name: Jingchao Wu
   Date: March 2017
   
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct CourseInfo{
int courseID;
char courseName[50];
char courseCode[12];
char Term [6];
};
typedef struct CourseInfo Info;  

Info courses[100];
int count = 0;
   

/* function prototype */
void loadCourseInfo();
void displayCourseInfo();
void addCourseInfo();
void searchCourseInfo(int);




/* main program function */ 
int main(void) {
loadCourseInfo();
 for(;;){
    int ch = -1;
	while (ch < 0 || ch > 4)
	{
	
	printf("*************************************");
	printf("\nSelect an option from the menu:\n");
	printf("1-Add a new course\n");
	printf("2-Search for a course by course ID\n");
	printf("3-Search for a course by course Name\n");
	printf("4-Display course data\n");
	printf("0-Quit\n");
	printf("*************************************\n-->");		
	scanf("%d",&ch)	;
	if (ch==0) return 0;	
		
	if (ch == 1)
			addCourseInfo();
		else if (ch == 2)
			searchCourseInfo(1);
		else if (ch == 3)
			searchCourseInfo(2);
		else if (ch == 4)
			displayCourseInfo();	
	}
	 
 }
	
	return 0;
}


// Objective: Reads all the data from input file and format and store them in an array of
//			structures.
// Input: None
// Output: None
void loadCourseInfo() {
FILE *fp;
char text[100];
char *token;
char text2[15];
char text3[1];
fp=fopen("input.csv","r"); 	// Open  file
while (fscanf (fp, "%s\n", text) != EOF)
{
count++;
token = strtok(text, ",");
   
	int i = 0, j = 0;
    while(token != NULL)
    {   
        switch(i){
		case 0:
				strcpy(text2, token);
				for (j = 0; j < strlen(text2); j++)
			    	text2[j] = toupper(text2[j]); 
				strcpy(courses[count].courseName, text2);
				break;
			case 1:
				strcpy(courses[count].courseCode,token);
				break;
			case 2:
				strcat(courses[count].courseCode, token);
				break;
			case 3:
				strcat(courses[count].courseCode, "-");
				strcat(courses[count].courseCode, token);
				break;
			case 4:
				strcat(courses[count].courseCode, "-");
				strcat(courses[count].courseCode, token);	
				break;
			case 5:
				strcpy(text3, token);	
				text3[0] = toupper(text3[0]);
				strcpy(courses[count].Term, text3);
				break;
			case 6:
				strcat(courses[count].Term, token); 
				break;
		 
		 
			
		}
		i++;
        token = strtok(NULL, ", ");
    }	
}
fclose(fp); 
  
}

// Objective: Prints  course information.
// Input: none
// Output: none
void displayCourseInfo() {
	
int i;

	printf("ID\tName\tCourseCode\tTerm\t\n");

	for (i = 0; i < count; i ++)
	{
			printf("%d\t ",  courses[i].courseID) ;
			printf("%s\t ", courses[i].courseName);
			printf("%s\t ", courses[i].courseCode);
			printf("%s\t ", courses[i].Term);
			printf("\n");
	}
	printf("\n");	
	
	
	
}


// Objective: To add a new course. CourseID and CourseCode   unique.
// Input: none
// Output: None
void addCourseInfo() {
	
	
	printf("Please enter the Course Information. \n");
	printf("The format is: CourseName,Faculty,Subject,Level,Section,Semester,Year\n");
	printf("Sample input: programming,03,60,141,01,W,2015 \n");
	printf("-->");
	
	char text[100];
    scanf(" %[^\n]s ", text);
 
    
	char *token;
    char text2[15];
	char text3[1];
    token = strtok(text, ",");
   
	int i = 0, j = 0, k;
	int flag = 0;
    while(token != NULL)
    {   
        switch(i){
			case 0:
				strcpy(text2, token);
				for (j = 0; j < strlen(text2); j++)
			    	text2[j] = toupper(text2[j]);    //upper case 
				strcpy(courses[count].courseName, text2);
				break;
			case 1:
				strcpy(courses[count].courseCode,token);
				break;
			case 2:
				strcat(courses[count].courseCode, token);
				break;
			case 3:
				strcat(courses[count].courseCode, "-");
				strcat(courses[count].courseCode, token);
				break;
			case 4:
				strcat(courses[count].courseCode, "-");
				strcat(courses[count].courseCode, token);
				
			    for (k = 0; k < count-1; k ++)      //check duplicate
				{ 
					if (strcmp(courses[k].courseCode, courses[count].courseCode) == 0)
					flag++;	
				}
				if (flag > 0)
				{
					printf("A duplicate Course Code was found.\n");		
					return;
				}	
				break;
			case 5:
				strcpy(text3, token);	
				text3[0] = toupper(text3[0]);  //upper case
				strcpy(courses[count].Term, text3);
				break;
			case 6:
				strcat(courses[count].Term, token); 
				break;
		 
				
		}
		i++;
        token = strtok(NULL, ", ");
    }	
	 courses[count].courseID=count;
   	count++;	
}
   		

// Objective: To search for a course information using courseID or course Name 
// Input: choice
// Output: None
void searchCourseInfo(int ch)
{
	int i, j, flag = 0;
	int id;
	char searchName[50];
	int flag2 = 0;

//  search by course ID
	if (ch == 1) {

		printf("\nPlease enter the course ID:\n  ");
		scanf("%d", &id);
		printf("\nThe result is:\n\n");

		
		for (i = 0; i < count; i++)
			{
				if (courses[i].courseID==id){
					flag=1;
			        break;}
			}
				printf("%d\t", courses[i].courseID);
				printf("%s\t", courses[i].courseName);
				printf("%s\t", courses[i].courseCode);
				printf("%s\t", courses[i].Term);
				printf("\n");
		
		if(flag == 0)
		{
			printf("Course ID %d was not found.\n", id);
		}
	}
	if (ch == 2) {//  search by course name
		printf("Enter course name:");
	    scanf("%s", searchName);

		for (j = 0; j < strlen(searchName); j++)
			searchName[j] = toupper(searchName[j]); //  uppercase

		printf("\nThe result is:\n\n");

		for (i = 0; i < count; i ++)
		{
			if (strcmp(courses[i].courseName, searchName) == 0)
			{

				 
				 
				printf("%d\t", courses[i].courseID);
				printf("%s\t", courses[i].courseName);
				printf("%s\t", courses[i].courseCode);
				printf("%s\t", courses[i].Term);
				printf("\n");

				flag2=1;
			}
		}

		if (flag2== 0)
		{
		printf("%s course was not found.\n", searchName);
		}	
		
		
		
	}
}




















