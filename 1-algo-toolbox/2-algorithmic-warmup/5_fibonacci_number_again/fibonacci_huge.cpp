#include <iostream>
#include <vector>

using namespace std;

long long fibonacci_huge(long long n, long long m)
{
    int p;
    vector <long long> fibListMod;
    fibListMod.push_back(0);
    fibListMod.push_back(1);
    fibListMod.push_back(1);

    for (int i = 3; ; i++)
    {
        fibListMod.push_back((fibListMod[i-1] + fibListMod[i-2]) % m);

        if (fibListMod[i] == 1 && fibListMod[i-1] == 0)
        {
            p = i-1;
            break;
        }
    }

    int mod = n % p;

    //cout << " p=" << p << " mod=" << mod << "\n";

    // vector <long long> fibList;

    // fibList.push_back(0);
    // fibList.push_back(1);
    // fibList.push_back(1);

    // for (int i = 3; i <= mod; i++)
    // {
    //     fibList.push_back((fibList[i - 1] + fibList[i - 2]));
    // }

    //cout << fibList[mod] << " ";
    return fibListMod[mod];
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // for (int i = 2; i < 40; i++)
    // {
    //     n = 100;
    //     m = i;
    //     cout << n << " " << m << " " << get_fibonacci_huge_naive(n, m) << " " << fibonacci_huge(n, m) << endl;
    // }

    // cout << "Correct: " << get_fibonacci_huge_naive(n, m) << endl;
    cout << fibonacci_huge(n, m) << endl;
    
}
