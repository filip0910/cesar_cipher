#include <stdio.h>
#include <stdlib.h>

int get_shift(int n, char *argv[]) {
  if (n == 1) {
    return 1;
  }
  if (n > 2) {
    fprintf(stderr, "One argument expected at most.\n Setting shift to 1.\n");
    return 1;
  }
  return atoi(argv[1]) ? atoi(argv[1]) : 1; // set to 1 if 1st arg is not number
}

int main(int argc, char *argv[]) {

  int shift = get_shift(argc, argv);

  int c;
  // reading
  while ((c = getchar()) != EOF) {
    // small letter
    if (c >= 'a' && c <= 'z') {
      if (c + shift > 'z') { // overflow
        putchar((c + shift) % 'z' + 'a' - 1);
      } else if (c + shift < 'a') { // underflow
        putchar(c + shift - 'a' + 'z' + 1);
      } else {
        putchar(c + shift);
      } // big letter
    } else if (c >= 'A' && c <= 'Z') {
      if (c + shift > 'Z') { // overflow
        putchar((c + shift) % 'Z' + 'A' - 1);
      } else if (c + shift < 'A') { // underflow
        putchar(c + shift - 'A' + 'Z' + 1);
      } else {
        putchar(c + shift);
      }
    } else if (c == '\n') {
      putchar('\n');
    }
  }

  return 0;
}
