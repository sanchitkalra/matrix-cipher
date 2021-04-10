// Converts an input string to it's respective ASCII matrix.

#include <string.h>

// Converts the entire string into an multi-dimensional array.
int convert(char text[]){

    // copy the input text into a local store.
    char store[strlen(text)];
    strcpy(store, text);

    // make sure the length of the input string is a multiple of 3 or make it so.
    int excess = strlen(store)%3;
    char excess_spaces[3] = "   ";
    if (excess != 0) {
      strncat(store, excess_spaces, 3-excess);
    }

    // covert the source into an array
    int arr[3][strlen(store)/3];
    int steps = strlen(store)/3;
    for (int i = 0; i < steps; i++) {
      int t[3];
      for (int k = 0; k < 3; k++) {
        t[k] = (int) store[3*i+k];
        arr[k][i] = t[k];
      }
      // for (int k = 0; k < 3; k++) {
      //   printf("%c ", store[3*i+k]);
      //   printf("%d ", t[k]);
      //   printf("%c\n", arr[k][i]);
      // }
    }

    return arr;

}
