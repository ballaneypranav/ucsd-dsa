#include <iostream>

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else if (a == 0)
        return b;

    return gcd(b, a % b);
}

long long lcm_fast(long long a, long long b)
{
	return (a * b) / gcd(a, b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
