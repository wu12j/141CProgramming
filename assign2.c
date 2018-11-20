/*
   Assignment 2
   
   Objective: Write a complete, well documented C program to walk through the maze, 
              starting from the maze entrance location, 
              and attempts to locate the exit from the maze.
   
   
   Name: Jingchao Wu
   
*/

#include<stdio.h>
#include <stdlib.h>

#define D  0 // move Down
#define R  1 // move Right
#define U  2 // move Up  
#define L  3 // move Left



int X=0, Y=0;//coordinate for the maze array


/* function prototype */
void findStart(char maze[][12]);//find the start point from the first column of the input maze (maze[][1]).

void mazeTraversal(char maze[][12], int x, int y, int direction );	//is a recursive function that gives maze, current x and y coordinate 
                        //and direction as an input. There are four valid directions of Up, Down, 
						//Left and Right. Also, the first (X,Y) coordinate to call mazeTraversal 
						//function is the found start point (maze entrance).	
						
void printMaze(char maze[][12] );//will print the current state of the maze after each movement.

int validMove(char maze[][ 12 ], int x,int y );//will determine the validity of the next movement (input coordinates).

int coordsAreEdge( int x, int y );//that check the input coordinate are edge or not.
					  
/* main program function */ 
int main(void)
{
	char maze[12][12] =  {  { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
						    { '1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1'},
							{ '0', '0', '1', '0', '1', '0', '1', '1', '1', '1', '0', '1'},
							{ '1', '1', '1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
							{ '1', '0', '0', '0', '0', '1', '1', '1', '0', '1', '0', '0'},
							{ '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
							{ '1', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
							{ '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
							{ '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
							{ '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
							{ '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
							{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' } };	

   findStart(maze);
   mazeTraversal( maze, X, Y, R );
   
  
 return 0;
}

//Find the maze entrance coordinate of the maze array
//Input: the maze array
//Output: None.
void findStart(char maze[][12]){
int i;
for (i=0;i<12;i++)	
	if (maze[i][Y]=='0') {
		X=i;
	return; 
	}
	
}


//a recursive function the first (X,Y) coordinate to call 
//mazeTraversal function is the found start point (maze entrance).
//Input:maze, current x and y coordinate and direction 
//Output:None.
void mazeTraversal( char maze[ 12 ][ 12 ], int x, int y, int  direction )
{ 
   static int position = 0; // starting position 

   maze[x][y] = 'X'; //   current step marked as X
   printMaze( maze );

  
   if ( coordsAreEdge( x, y ) && x != X  && y != Y  ) { 
       
      printf( "\nMaze ended.\n\n" );
      return;   
   } 
   else if ( x == X && y == Y  && position == 1 ) { 
      printf( "\nstarting location arrived.\n\n" );
      return;
   } 
   else { // make next move
      int move; // next move
      int count; // counter

      position = 1;

      // loop 4 times and find first valid move
      for ( move = direction, count = 0; count < 4; count++, move++, move %= 4 ) {
         
         // choose valid move
         switch( move ) { 

            case D: // move Down

               
               if ( validMove(maze, x + 1, y ) ) {  
                  mazeTraversal( maze, x + 1, y, L);
                  return;
               } break;
         
            case R: // move Right

                
               if ( validMove( maze, x, y + 1 ) ) {  
                  mazeTraversal( maze, x, y + 1, D );
                  return;
               }   break;

            case U: // move Up

               if ( validMove( maze, x - 1, y ) ) { 
                  mazeTraversal( maze, x - 1, y, R );
                  return;
               } break; 

              
            case L: // move Left

               
               if ( validMove( maze, x, y - 1 ) ) { // go L
                  mazeTraversal( maze, x, y - 1, U );
                  return;
               } break;

                 
         }  

      }  

   }  

}  















//will determine the validity of the next movement 
//Input:coordinates,maze array
//Output:
int validMove( char maze[][ 12 ], int x, int y )
{ 
   if ( x >= 0 && x <= 11 && y >= 0 && y <= 11 && maze[ x ][ y ] != '1' )
	   return 1;
  
	else return 0;

}  






//check the input coordinate are edge or not
//Input:coordinates
//Output:return if coordinates are valid 
int coordsAreEdge( int x, int y ){
	

   // coordinate invalid condition
   if ( ( x == 0 || x == 11 ) && ( y >= 0 && y <= 11 ) ) {
      return 1;
   }  
   else if ( ( y == 0 || y == 11 ) && ( x >= 0 && x <= 11 ) ) {
      return  1;
   }  
   else { // coordinate valid condition
      return  0;
   }  

   
}  
	
	
	
	
	
//print the current state of the maze after each movement.
//Input:maze array
//Output:None.	
void printMaze(char maze[][12] ){
int i,j,k;	
	for (i=0;i<12;i++){	
		for (j=0;j<12;j++){
			if(maze[i][j]=='1')
				printf("%c ",'#');
			else if(maze[i][j]=='0')
				printf("%c ",'.');
			else if(maze[i][j]=='X')
				printf("%c ",'@');
			
		}	
	    printf("\t");
		for (k=0;k<12;k++)
			printf("%c ",maze[i][k]);
	printf("\n");
	}
	
	printf( "\nHit return to see next move\n");
	getchar();
}
