#include "stdio.h"
#include "converter.h"

int main() {

  char source[] = "This si the source. "; // placeholder text
  int arr = convert(source);
  for (int i = 0; i < 21; i++) {
    for (int k = 0; k < 3; k++) {
      printf("%d\n", *(*(arr + i) + k));
    }
  }

  return 0;
}
