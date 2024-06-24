#include <stdio.h>
#include <string.h>

void cyclic_move(char *string, int x) {
  if (string == NULL || x == 0) {
    return;
  }

  int length = strlen(string);
  x = x % length;

  if (x < 0) {
    x = length + x;
  }

  // Reverse the entire string
  for (int i = 0; i < length / 2; i++) {
    char temp = string[i];
    string[i] = string[length - i - 1];
    string[length - i - 1] = temp;
  }

  // Reverse the first part up to x
  for (int i = 0; i < x / 2; i++) {
    char temp = string[i];
    string[i] = string[x - i - 1];
    string[x - i - 1] = temp;
  }

  // Reverse the second part from x to end
  for (int i = x; i < (length - x) / 2 + x; i++) {
    char temp = string[i];
    string[i] = string[length - i - 1 + x];
    string[length - i - 1 + x] = temp;
  }
}

int main(void) {
  char string[] = "abcd";
  int x = 3;

  printf("Original string: %s\n", string);

  cyclic_move(string, x);

  printf("String after cyclic move by %d positions: %s\n", x, string);

  return 0;
}
