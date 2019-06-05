#include <iostream>
#include <vector>

using namespace std;

long long fibonacci_partial_sum(long long from, long long to)
{

    int period = -1;
    vector<long long> fibListMod;
    fibListMod.push_back(0);
    fibListMod.push_back(1);

    int sum = from < 2  && to >= 1 ? 1 : 0;

    for (int i = 2; i <= to; i++)
    {
        fibListMod.push_back((fibListMod[i-1] + fibListMod[i-2]) % 10);
        
        if (fibListMod[i] == 1 && fibListMod[i-1] == 0)
        {
            period = i-1;
            break;
        }

        if (i >= from)
            sum = (sum + fibListMod[i]) % 10;
    }

    if (period == -1)
        return sum;

    int sum_all = 0;
    for (int i = 0; i < period; i++)
    {
        sum_all += fibListMod[i];
    }
    cout << sum_all << endl;

    long long quotient1 = from / period;
    long long remainder1 = from % period;

    long long quotient2 = to / period;
    long long remainder2 = to % period;

    if (quotient1 == quotient1)
    {
        for (int i = remainder1; i <= remainder2; i++)
        {
            sum = (sum + fibListMod[i]) % 10;
        }
    }
    else
    {
        for (int i = remainder1; i <= period; i++)
        {
            sum = (sum + fibListMod[i]) % 10;
        }

        if (quotient2 != quotient1 + 1)
        {
            sum = (sum + (sum_all * (quotient2 - quotient1 - 1))) % 10;
        }

        for (int i = 1; i <= remainder2; i++)
        {
            sum = (sum + fibListMod[i]) % 10;
        }
    }
    return sum;
}

// long long fibonacci_partial_sum(long long from, long long to) {
//     vector<long long> fibList;

//     fibList.push_back(0);
//     fibList.push_back(1);

//     int sum = from < 2  && to > 1 ? 1 : 0;

//     for (int i = 2; i <= to; i++)
//     {
//         long long current = (fibList[i - 1] + fibList[i - 2]) % 10;
//         fibList.push_back((current * current) % 10);
//         if (i >= from)
//             sum = (sum + fibList[i]) % 10;
//     }

//     return sum;
// }

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //     {
    //         long long a = get_fibonacci_partial_sum_naive(i, j);
    //         long long b = fibonacci_partial_sum(i, j);
    //         if (a != b)
    //         {
    //             cout << i << " " << j << " " << a << " " << b << endl;
    //         }
    //     }

    cout << fibonacci_partial_sum(from, to) << "\n";
}
