/*
   Assignment 5
   
   Objective: to be maintaining a file of all students and their registered 
   courses to learn the concepts of structures, pointers to structures, 
   dynamic memory allocation and file manipulation
   
   
   Name: Jingchao Wu
   Date: March 2017
   
*/

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



// Structure definition 
typedef struct CourseInfo
{   
    char studentID[9];
	int courseNum;
	char courseID [5];
    char firstName[20];
    char lastName [25];
    char courseName [10];
   
   
} info;

info conList[MAX];   // Array decalaration of the type contact

int countNum = 0; // Initializing the record numbers at 0

// Function prototype
void addStudent();
void displayStudentInfo();
void searchStudentlName();
int searchStudentID(int i);
void saveStudentInfo();
void loadStudentinfo();
void Exit();
void upperCase(char name[], int n);
void delete() ;

/* main program function */ 
int main()
{    
    loadStudentinfo();//load info from file
	
    int ch;   //choice
    
     
    
    for(;;)
    {
        printf("\t1. Add new student\n");
		printf("\t2. Display student information\n");
		printf("\t3. Delete a student\n");
		printf("\t4. Display current students\n");
		printf("\t5. Save student information to file\n");
		printf("\t6. Exit\n\t> ");
        scanf("%d", &ch);   // Reading the ch the user is going to make from the keyboard
        
        switch(ch)  // Switch case to make the program react depending on the ch of the user in the pervious step
        {
            case 1 :
                addStudent();
                break;
            case 2 :
                displayStudentInfo();
                break;
            case 3 :
                 delete();
                break;
            case 4 :
                displayStudentInfo();
                break;
            case 5 :
                saveStudentInfo();
                break;
            case 6 :
                Exit();
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
    
    return 0;
}

 
 


// This function takes the data entered from the user and then stores it in the "contact" structure format
// Input: NONE
// Output: NONE
void addStudent()
{
    char ans = 'y';
    char *buffer;

    
    while(ans == 'y' || ans == 'Y')
    {
       
        printf("\nAdding new student:\n");  
		printf("Student ID : "); // Asking the user to enter the id
        scanf(" %[^\n]s", buffer);
        strcpy(conList[countNum].studentID, buffer);
		if(!searchStudentID(countNum))
			 printf("error.");
			 exit(0);
			
		}
         
		
        printf("First name : ");// Asking user to enter the first name  
		
        scanf(" %s", buffer);
        upperCase(buffer, 1);
        strcpy(conList[countNum].firstName, buffer);
        
        printf("Last name : "); // Asking the user to enter the last name  
        scanf(" %s", buffer);
        upperCase(buffer, 1);
        strcpy(conList[countNum].lastName, buffer);
		
		
        printf("Number of courses: "); // Asking the user to enter  
        scanf(" %d", &conList[countNum].courseNum);
         
        int i = 0; 
        while(i<conList[countNum].courseNum){
			
		printf("course id : "); // Asking the user to enter  
        scanf(" %s", buffer);
        strcpy(conList[countNum].courseID, buffer);
		
		printf("course name : "); // Asking the user to enter  
        scanf(" %s", buffer);
        strcpy(conList[countNum].courseName, buffer);
      
		   
		  i++; 
	   }
        
        
         
        countNum++;
        
        printf("\nAdd another student?(y/n): ");    // Asking the user if they will like to add another contact
        scanf(" %c", &ans);
    
}



// This function capitalize the first letter of a word  
// Input: a string array and an integer
// Output: void
void upperCase(char string[], int n)
{
    int i = 0;
    
    while(string[i])
    {
        string[i] = toupper(string[i]); // Capitalizing the character 
        i++;
        
        if(n == 1)
        {
            while(string[i] != ' ')
            {
                string[i] = tolower(string[i]);
                i++;
            }
            
            if(string[i])
                i++;
        }
    }
}
//DISPLAY INFO
//INPUT:NONE
//OUTPUT:NONE
void displayStudentInfo()
{
    int i = 0;
    while(i < countNum) 
{
    i++;
	printf("Student id : %s\n", conList[i].studentID);
    printf("First name : %s\n", conList[i].firstName);
    printf("Last name  : %s\n", conList[i].lastName);
    printf("Number of courses: %d\n", conList[i].courseNum);
	int j=0;
    while(j<conList[i].courseNum){
			
		printf("course id : %s",conList[i].courseID);  
  
		printf("course name : %s ",conList[i].courseName);  
         
		  j++; 
	   }
        
   
}
}
//SEARCH STUDENT NAME
//INPUT:NONE
//OUTPUT:NONE
void searchStudentlName()
{
    int index = 0, count = 0;
    int iArray[MAX] = {0};
    char lName[30];
    
    printf("What is the student's last name? ");
    scanf("%s", lName);
    upperCase(lName, 1);
    while(index < countNum)
    {
        if(strcmp(lName, conList[index].lastName) == 0)
        {
            iArray[index] = 1;
            count++;
        }
        
        index++;
    }
    
    printf("Found %d record(s):\n", count);
    
    index = 0;
    while(index < countNum)
    {
        if(iArray[index] == 1)
            displayStudentInfo(index);
        
        index++;
    }
}

//SEARCH STUDENT ID
//INPUT:COUNTNUM
//OUTPUT:TRUE OR FALSE
int searchStudentID(int i)
{
    
    int j = 0;
    while(j < countNum-1)
    {
       if(strcmp(conList[j].studentID, conList[i].studentID)==0) {
		   return 0;
	   }
        
        j++;
    }
	return 1;
} 
//DELETE STUDENT INFO
//INPUT:NONE
//OUTPUT:NONE
void delete() 
 {      char *buffer;
		printf("Enter Student ID to delete: "); // Asking the user to enter the id
        scanf(" %s", buffer);
         
        int j = 0;
    while(j < countNum-1)
    {
       if(strcmp(conList[j].studentID, buffer)==0) {
		   for(;j<countNum-1;j++)
			   conList[j]=conList[j+1];
		   countNum--;
	   }
	 
	 
	 
	 
 }

}

//SAVE STUDENT INFO
//INPUT:NONE
//OUTPUT:NONE
void saveStudentInfo()
{
    FILE *out;
    int i;
    
    if((out = fopen("inputStudents.txt", "w")) == NULL)
    {
        printf("Cannot open inputStudents.txt for writing\n");
        exit(0);
    }
    
    fprintf(out, "%d\n", countNum);
    
    for(i = 0; i < countNum; i++)
    {
		fprintf(out,"%s\n", conList[i].studentID);
        fprintf(out, "%s\n", conList[i].firstName);
        fprintf(out, "%s\n", conList[i].lastName);	
		fprintf(out," %s\n", conList[i].firstName);
		fprintf(out,"%s\n", conList[i].lastName);
		fprintf(out,"%d\n", conList[i].courseNum);
		int j=0;
		while(j<conList[i].courseNum){
			
		fprintf(out,"%s",conList[i].courseID);  
  
		fprintf(out,"%s ",conList[i].courseName);  
         
		  j++; 
	   }
        
		
		
		
		
		
    }
    
    fclose(out);
    
    printf("Student List saved successfully.\n");
    
}

//load Student info from file
//INPUT:NONE
//OUTPUT:NONE
void loadStudentinfo()
{
    FILE *in;
    int i;
    char temp[100];
    
    if((in = fopen("studentList.txt", "r")) == NULL)
    {
        printf("Cannot open studentList.txt for reading\n");
        return;
    }
    
    fscanf(in, "%d", &countNum);
    
    for(i = 0; i < countNum; i++)
    {

		
		
		fscanf(in,"%s\n", conList[i].studentID);
        fscanf(in, "%s\n", conList[i].firstName);
        fscanf(in, "%s\n", conList[i].lastName);	
		fscanf(in,"%s\n", conList[i].firstName);
		fscanf(in,"%s\n", conList[i].lastName);
		fscanf(in,"%d\n", conList[i].courseNum);
		int j=0;
		while(j<conList[i].courseNum){
			
		fscanf(in,"%s",conList[i].courseID);  
  
		fscanf(in,"%s ",conList[i].courseName);  
         
		  j++; 
	   }
        
        
    }
    
    fclose(in);
    
    printf("Contact List loaded successfully.\n");
}
//EXIT PROGRAM
//INPUT:NONE
//OUTPUT:NONE
void Exit()
{
    char ans;
    
    printf("Save your students to file before leaving? (y/n): ");
    fflush(stdin);
    scanf("%c", &ans);
    if(ans == 'y' || ans == 'Y')
        saveStudentInfo();
    
    printf("Bye!\n");
    exit(0);
}
 
