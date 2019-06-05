#include <iostream>

int get_change(int m) 
{
	int coins = m / 10;
	m = m % 10;

	coins += (m / 5);
	m %= 5;

	coins += m;
	m %= 1;

	return coins;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
