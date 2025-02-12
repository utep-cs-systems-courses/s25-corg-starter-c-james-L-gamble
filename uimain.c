#include <stdio.h>
#include "draw.h" // project-related declarations

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = t, Square = s, Right Facing Arrow = r, Arrow = a, Chars = c, Larger Chars = l) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      puts("You selected chars:");
      for (char c = 'a'; c < 'd'; c++)
	print_char_5x7(c);
      break;
    case 'r':
      puts("You selected right-facing arrow:");

      print_right_facing_arrow(25,6);
      
      break;

    case 'a':
      puts("You selected arrow:");

      print_arrow(5,8,5,5);

      break;

    case 'l':
      puts("You selected larger chars:");
      for(char c = 'a'; c < 'd';c++)
	print_char_8x12(c);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
