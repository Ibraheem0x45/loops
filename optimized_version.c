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
  int factor = 100000 / u;
  int remaining = 100000 % u;

  for (int i = 0; i < 10000; i++) {    // 10k outer loop iterations
    for (int j = 0; j < factor; j++) { // 100k inner loop iterations, per outer loop iteration
      for (int k = 0; k < u; k++) {
        a[i] = a[i] + k;               // Simple sum
      }
    }

    for (int k = 0; k < remaining; k++) {
      a[i] = a[i] + k;
    }

    a[i] += r;                         // Add a random value to each element in array
  }
  printf("%d\n", a[r]);                // Print out a single element from the array
}