/**
 * This codes are taken from slides and HW2.pdf. This main class is about experimenting time complexity.
 * @sarperardabakır
 * @21902781
 * @04.07.22
 */
#include <iostream>
using namespace std;
/**
 * A recursive algorithm which works in O(2n) time.
 * @param n
 * @return
 */
int recursiveFib( int n ) {
    if ( n <= 2 )
        return 1;
    return recursiveFib( n - 1) + recursiveFib( n - 2 );
}
/**
 * An iterative algorithm which works in O(n) time.
 * @param n
 * @return
 */
int iterativeFib( int n ) {
    int previous = 1;
    int current = 1;
    int next = 1;         // result when n is 1 or 2
    // compute next Fibonacci values when n >= 3
    for ( int i = 3; i <= n; i++ ) {
        next = current + previous;
        previous = current;
        current = next;
    }
    return next;
}

int main() {

    //Store the starting time
    double duration;
    clock_t startTime = clock();
    //Code block
    //recursiveFib() and iterativeFib() methods are calling many times by different values so as to calculating time complexity.
    //recursiveFib(20);
    iterativeFib(10);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;

    return 0;
}

