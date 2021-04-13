#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "converter.h"

int main() {

  char source[] = "This is the source. Nishant is in BPHC."; // placeholder text
  char passphrase[] = "HelloWord"; // placeholder passphrase

  struct convert res = convert(source);
  int n = res.n, m = res.m;
  int (*arr)[m] = (void*)res.arr;

  for (int i = 0; i < n; i++, puts("")) {
    for (int k = 0; k < m; k++) {
      printf("%d ", arr[i][k]);
    }
  }

  if (strlen(passphrase) <= 9) {
    struct convert respass = convert(passphrase);
    int n2 = respass.n, m2 = respass.m;
    int (*arrp)[m2] = (void*)respass.arr;

    for (int i = 0; i < n2; i++, puts("")) {
      for (int k = 0; k < m2; k++) {
        printf("%d ", arrp[i][k]);
      }
    }
    free(arrp);
  } else {
    printf("%s\n", "Please enter a passphrase shorter or equal to 9 characters.");
  }

  free(arr);

  return 0;
}
