#include <iostream>
#include <vector>

using namespace std;

long long fibonacci_sum_squares(long long n) {
    vector<long long> fibList;

    long long a = 0;
    long long b = 1;

    int sum = 1;

    for (int i = 2; i <= n; i++)
    {
        long long temp = b;
        b = (a + b) % 10;
        a = temp;

        long long sq_digit = (b * b) % 10;
        
        sum = (sum + sq_digit) % 10;
    }

    return sum;
}

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n) << endl;
}
