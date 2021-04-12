#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct convert {
    int n, m;
    int *arr;
} convert(char text[]){

    // refer SO question: https://stackoverflow.com/questions/67041897/

    // copy the input text into a local store.
    size_t textlen = strlen(text);
    char store[textlen + 3 + 1];
    strcpy(store, text);

    // make sure the length of the input string is a multiple of 3 or make it so.
    int excess = textlen % 3;
    char excess_spaces[3] = "   ";
    if (excess != 0) {
      strncat(store, excess_spaces, 3-excess);
    }
    size_t storelen = strlen(store);

    // allocate VLA with dynamic storage
    int (*arr)[storelen / 3] = malloc(3 * sizeof *arr);

    // covert the source into an array
    int steps = storelen / 3;
    for (int i = 0; i < steps; i++) {
      int t[3];
      for (int k = 0; k < 3; k++) {
        t[k] = (int) store[3*i+k];
        arr[k][i] = t[k];
      }
    }

    return (struct convert){ .n = 3, .m = steps, .arr = (int*)arr };
}

int main() {

  char source[] = "This is the source. "; // placeholder text
  struct convert res = convert(source);
  int n = res.n, m = res.m;
  int (*arr)[m] = (void*)res.arr;

  for (int i = 0; i < n; i++, puts("")) {
    for (int k = 0; k < m; k++) {
      printf("%d ", arr[i][k]);
    }
  }
  free(arr);

  return 0;
}
