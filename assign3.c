/*
   Assignment 3
   
   Objective: Write a complete, well documented C program that reads several lines of text and prints three tables indicating:
			  1) the number of occurrences of each letter of the alphabet in the complete text
			  2) the number of one-letter words, two-letter words, three-letter words, and so on, appearing in the complete text
	          3) the number of occurrences of each different word in the complete text
   
   
   Name: Jingchao Wu
   Date: March 2017
   
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LineNum 10
#define LineLength 80
#define WordLength 20

/* function prototype */
void letterAnalysis(char [][LineLength], int lines);
int wordLengthAnalysis(char [][LineLength], int lines, int wordLength);
void wordAnalysis(char [][LineLength], int lines);

/* main program function */ 
int main() {
	char text[LineNum][LineLength];
	
	int lines;
    printf( "Enter number of lines will be input:\n" );
	scanf("%d",&lines);
	if(lines>LineNum) {
		printf("Lines number error.");
		return 0;
	}
	
	printf( "Enter the text:\n" );
	
	int i;
	for(i = 0; i < lines; i++){
		
		scanf(" %[^\n]s ", text[i]);//get input
		
	}
	


	printf("\nLetter count analysis: \n");
	letterAnalysis(text, lines);

	printf("\nWord length analysis: \n");

	for (i = 0; i < WordLength; i++)
		printf("%d word of length: \t%d\n",i, wordLengthAnalysis(text, lines, i));

	printf("\nWord count analysis: \n");
	wordAnalysis(text, lines);
	
	
	return 0;
}


// Objective: gets the number of lines of text as input parameters and prints a table indicating the number of 
//            occurrences of each letter of the alphabet in the complete text.
// Input: 2D char array , number of lines
// Output: None
void letterAnalysis(char text[][LineLength], int lines) {

	int letter[26] = {0};
	int i, j;
	for (i = 0; i < lines; i++) {
		for (j = 0; j < strlen(text[i]); j++) {
			text[i][j] = tolower(text[i][j]);
			if (isalpha(text[i][j]))                       // increments on characters 
				letter[text[i][j] % 'a']++;                    //get the position of that character in the alphabet,  stored in the corrosponding position in the array
		}
	}

	for (i = 0; i < 26; i++)
		printf("%c: \t%d\n",'a' + i, letter[i]);
}

// Objective: get the number of occurrences of words with that length appearing in the text.
// Input: 2D char array , number of lines
// Output: return the number of occurrences of words with that length appearing in the text.
int wordLengthAnalysis(char input[][LineLength], int lines, int wordLength) {
	int i, count = 0;
	char text[lines][LineLength];

	for (i = 0; i < lines; i++) {
		strcpy(text[i], input[i]); 				//copy input array to a new array
		char *token = strtok(text[i], " "); 	//get the current token
		while (token != NULL) {
			if (strlen(token) == wordLength) 
				count++;                
												//countwords of the inputted length were found
			token = strtok(NULL, " "); 			//get the next token
		}
	}
	return count;
}


// Objective: prints a table indicating the number of occurrences of each different word in the text.
// Input: 2D char array , number of lines
// Output: None
void wordAnalysis(char text[][LineLength], int lines) {
	
	int i, j ;
	char *temp;
	char words[ LineLength ][ WordLength ] = { "" };
	int count[ LineLength ] = { 0 };
	
	
	for (i = 0; i < lines; i++) {
		  

         temp = strtok( &text[ i ][ 0 ], ". \n" );   //get first token
  		 while ( temp != NULL ) {
  		 	//get words for match
		for ( j = 0; words[ j ][ 0 ] && strcmp( temp, &words[ j ][ 0 ] ) != 0; j++ ) {
		}
		
          count[ j ]++ ;
		  
		  if ( !words[ j ][ 0 ] ) 
				strcpy( &words[ j ][ 0 ], temp );
		  
  
          temp = strtok( NULL, ". \n" );
      }
      
  }
  putchar( '\n' );

   for ( j = 0; words[ j ][ 0 ] != '\0' && j <= LineLength; j++ ) 
   		printf( "\"%s\" appeared %d time\n",&words[ j ][ 0 ], count[ j ]);
   		
   }
   		

































