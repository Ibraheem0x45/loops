package jvm;

import java.util.Random;

public class optimized_version {

    public static void main(String[] args) {
        var u = Integer.parseInt(args[0]); // Get an input number from the command line
        var r = new Random().nextInt(10000); // Get a random number 0 <= r < 10k
        var a = new int[10000]; // Array of 10k elements initialized to 0
        var factor = 100000 / u;
        var remaining = 100000 % u;
        
        for (var i = 0; i < 10000; i++) { // 10k outer loop iterations
            for (var j = 0; j < factor; j++) { // 100k inner loop iterations, per outer loop iteration
                for (var k = 0; k < u; k++) {
                    a[i] = a[i] + k; // Simple sum
                }
            }

            for (var k = 0; k < remaining; k++) {
                a[i] = a[i] + k; // Simple sum
            }

            a[i] += r; // Add a random value to each element in array
        }
        System.out.println(a[r]); // Print out a single element from the array
    }
}
