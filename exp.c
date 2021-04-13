#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

  char source[] = "This is the source. Nishant is in BPHC."; // placeholder text
  char passphrase[] = "HelloWord"; // placeholder passphrase

  // copy the input text into a local store.
  size_t textlen = strlen(source);
  char store[textlen + 3 + 1];
  strcpy(store, source);

  // make sure the length of the input string is a multiple of 3 or make it so.
  int excess = textlen % 3;
  char excess_spaces[3] = "   ";
  if (excess != 0) {
    strncat(store, excess_spaces, 3-excess);
  }
  size_t storelen = strlen(store);

  // // allocate VLA with dynamic storage
  // int (*arr)[storelen / 3] = malloc(3 * sizeof *arr);

  int arr[3][storelen / 3];

  // covert the source into an array
  int steps = storelen / 3;
  for (int i = 0; i < steps; i++) {
    int t[3];
    for (int k = 0; k < 3; k++) {
      t[k] = (int) store[3*i+k];
      arr[k][i] = t[k];
    }
  }

  // for (int i = 0; i < 3; i++, puts("")) {
  //   for (int k = 0; k < (storelen / 3); k++) {
  //     printf("%d ", arr[i][k]);
  //   }
  // }

  // copy the passphrase text into a local store.
  size_t passlen = strlen(passphrase);
  char storePass[passlen + 3 + 1];
  strcpy(storePass, passphrase);

  // make sure the length of the input string is a multiple of 3 or make it so.
  int excessP = passlen % 3;
  if (excessP != 0) {
    strncat(storePass, excess_spaces, 3-excessP);
  }
  size_t storelenP = strlen(storePass);

  // // allocate VLA with dynamic storage
  // int (*arr)[storelen / 3] = malloc(3 * sizeof *arr);

  int arrPassphrase[3][storelenP / 3];

  // covert the source into an array
  int stepsP = storelenP / 3;
  for (int i = 0; i < stepsP; i++) {
    int t[3];
    for (int k = 0; k < 3; k++) {
      t[k] = (int) storePass[3*i+k];
      arrPassphrase[k][i] = t[k];
    }
  }

  int encrypt[3][storelen / 3];

  for (size_t i = 0; i < 3; i++) {
    for (size_t k = 0; k < (storelen / 3); k++) {
      encrypt[i][k] = 0;
    }
  }

  for (int i = 0; i < 3; i++, puts("")) {
    for (int k = 0; k < (storelen / 3); k++) {
      printf("%d ", encrypt[i][k]);
    }
  }

  for(int i=0;i<3;i++) {
      for(int j=0;j<storelen/3;j++) {
          encrypt[i][j]=0;
          for(int k=0;k<storelenP/3;k++) {
            printf("arrPassphrase[%d][%d] = %d\n", i, k, arrPassphrase[i][k]);
            printf("arr[%d][%d] = %d\n", k, j, arr[k][j]);
            encrypt[i][j]+=arrPassphrase[i][k]*arr[k][j];
          }
      }
  }

  for (int i = 0; i < 3; i++, puts("")) {
    for (int k = 0; k < (storelen / 3); k++) {
      printf("%d ", encrypt[i][k]);
    }
  }

  return 0;
}
