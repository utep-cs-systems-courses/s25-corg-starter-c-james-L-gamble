#include <stdio.h>
#include "draw.h"

/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}

// Prints a triangle of specified height whose left edge is at col leftCol.
void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}

void print_arrow(int triangleEdge,int rectangleEdge, int triangleSize, int rectangleSize){
  /* Idea: The point of the arrow is a triangle, the body of the arrow is a rectangle.*/

  print_triangle(triangleEdge,triangleSize);
  print_square(rectangleEdge,rectangleSize);

}

void print_right_facing_arrow(int rectangleWidth, int halfRectangleHeight)
{
  //I misheard the instructions, believing the triangle had to point right.

  /*Idea: the triangle's base will be rectangleHeight * 3 asterisks long. The other two sides will each be rectangleHeight long. So, we print rectangleHeight newlines, each with n asterisks after them, where n is the current line number. We then print the rectangle, each line being appended with one asterisk more than the last, until the number of asterisks after the rectangle is n * 2. We then print 1 less astrisk after each line until there are 0 once more.*/


  /*Print the first part of the triangle, and the space above the rectangle.*/

  int blankHeight = halfRectangleHeight;
  int blankWidth = rectangleWidth;
  int triangleAsterisks = 1;

  /* Prints the first quarter of the triangle, and the blank space above the rectangle */
  for(int i = 0; i < blankHeight;i++){
    for(int j = 0; j < blankWidth;j++){
      printf(" ");
    }
    for(int j = 0; j < triangleAsterisks;j++){
      printf("*");
    }
    triangleAsterisks++;
    printf("\n");
  }

  /* Prints the second quarter of the triangle, and the first half of the rectangle that forms the body of the arrow. */
  for(int i = 0; i < halfRectangleHeight-1;i++){
    for(int j = 0; j < rectangleWidth;j++){
      printf("*");
    }
    for(int j = 0; j < triangleAsterisks;j++){
      if(triangleAsterisks < (halfRectangleHeight * 2)){
	printf("*");
      }
    }
    triangleAsterisks++;
    printf("\n");
  }

  /* Prints the middle line of the arrow, to make it symetrical */
  for(int i = 0; i < (triangleAsterisks + rectangleWidth); i++){
    printf("*");
  }
  printf("\n");
  triangleAsterisks--; /* Decrement to print proper triangle size at the start of the third quarter */

  
  /* Prints the third quarter of the triangle, and the second half of the rectangle that forms the body of the arrow. */
  for(int i = 0; i < halfRectangleHeight-1;i++){
    for(int j = 0; j < rectangleWidth;j++){
      printf("*");
    }
    for(int j = 0; j < triangleAsterisks;j++){
      if(triangleAsterisks > (halfRectangleHeight)){
	printf("*");
      }
    }
    triangleAsterisks--;
    printf("\n");
  }

  /* Prints the fourth quarter of the triangle, and the blank space below the rectangle. */
  for(int i = 0; i < blankHeight;i++){
    for(int j = 0; j < blankWidth;j++){
      printf(" ");
    }
    for(int j = 0; j < triangleAsterisks;j++){
      printf("*");
    }
    triangleAsterisks--;
    printf("\n");
  }  
}
