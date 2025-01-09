#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

int main (int argc, char** argv) {
  int u = atoi(argv[1]);               // Get an input number from the command line
  srand(time(NULL));                   // FIX random seed
  int r = rand() % 10000;              // Get a random integer 0 <= r < 10k
  int32_t a[10000] = {0};              // Array of 10k elements initialized to 0
  for (int i = 0; i < 10000; i++) {    // 10k outer loop iterations
    for (int j = 0; j < 100000; j++) { // 100k inner loop iterations, per outer loop iteration
      a[i] = a[i] + j%u;               // Simple sum
    }
    a[i] += r;                         // Add a random value to each element in array
  }
  printf("a[r] = %d\n", a[r]);                // Print out a single element from the array

  int32_t b[10000] = {0};

  int factor = 100000 / u;
  int remaining = 100000 % u;

  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < factor; j++) {
      for (int k = 0; k < u; k++) {
        b[i] = b[i] + k;
      }
      
    }

    for (int k = 0; k < remaining; k++) {
        b[i] = b[i] + k;
    }

    b[i] += r;                  
  }

  printf("b[r] = %d\n", b[r]);       

  for (int i = 0; i < 10000; i++) {
    if (a[i] != b[i]) {
      printf("Im very sad ;( u: %d\n", u);
      printf("diff %d\n", a[i] - b[i]);
      return 420;
    }
  }

  printf("All values matched for u: %d\n", u);
  return 0;
}