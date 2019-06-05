#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsGreaterOrEqual(string a, string b)
{
	int p = a.size();
	int q = b.size();

	if (p == q)
	{
		return stoi(a) > stoi(b);
	}
	else 
	{
		return stoi(a + b) > stoi(b + a);
	}
}

string largest_number(vector<string> a) {
	std::stringstream ret;
	
	while (a.size() > 0)
	{
		string max = a[0];
		int index = 0;
		for (int i = 1; i < a.size(); i++)
		{
			if (IsGreaterOrEqual(a[i], max))
			{
				max = a[i];
				index = i;
			}
		}

		ret << max;
		a.erase(a.begin() + index);
	}

	for (size_t i = 0; i < a.size(); i++)
	{
		ret << a[i];
	}
	

	string result;
	ret >> result;
	return result;
}

int main() {
	int n;
	std::cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) {
	std::cin >> a[i];
	}
	std::cout << largest_number(a) << "\n";
}
