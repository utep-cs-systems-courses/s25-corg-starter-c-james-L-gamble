#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_5x7(char c)
{
  c -= 0x20;
  for (char col = 0; col < 5; col++) {
    for (char row = 0; row < 7; row++) {
      unsigned short rowBits = font_5x7[c][col];
      unsigned short colMask = 1 << (6-row); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
  putchar('\n');
}

void print_char_8x12(char c)
{
  /* I don't fully understand why, but the final rows of the characters are not displaying. 

     Maybe I'm iterating over the row incorrectly? */
  c -= 0x20;
  for(char col = 0; col < 8; col++){
    unsigned short rowBits = font_8x12[c][col];
    for(char row = 0; row < 12; row++) {
      unsigned short colMask = 1 << (11-row);
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
   putchar('\n');
}

