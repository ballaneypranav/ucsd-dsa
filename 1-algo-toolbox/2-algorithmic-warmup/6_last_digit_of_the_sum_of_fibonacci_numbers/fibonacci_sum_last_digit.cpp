#include <iostream>
#include <vector>

using namespace std;

long long fibonacci_sum(long long n)
{
    if (n < 2)
        return n;

    int p = -1;
    vector<long long> fibListMod;
    fibListMod.push_back(0);
    fibListMod.push_back(1);
    long long sum = 1;

    for (int i = 2; i <= n; i++)
    {
        fibListMod.push_back((fibListMod[i-1] + fibListMod[i-2]) % 10);
        
        if (fibListMod[i] == 1 && fibListMod[i-1] == 0)
        {
            p = i-1;
            break;
        }

        sum = (sum + fibListMod[i]) % 10;
    }

    if (p == -1)
        return sum;

    long long quotient = n / p;
    long long remainder = n % p;

    // cout << "p = " << p << "; q = " << quotient << "; r = " << remainder << endl;
    // cout << "sum = " << sum << endl;

    sum = (sum * quotient) % 10;
    // cout << "sum = " << sum << endl;

    for (int i = 1; i <= remainder; i++)
    {
        // cout << "Adding " << fibListMod[i] << endl;
        sum = (sum + fibListMod[i]) % 10;
    }
    return sum;
}

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // for (n = 50; n < 100; n++)
    // {
    //     long long a = fibonacci_sum_naive(n);
    //     long long b = fibonacci_sum(n);
    //     if (a != b)
    //     std::cout << n << " " << a << " " << b << endl;
    // }

    // cout << "Correct: "  << fibonacci_sum_naive(n) << endl;
    cout << fibonacci_sum(n) << endl;
}
