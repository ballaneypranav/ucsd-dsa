#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define mp make_pair
#define pb push_back

using namespace std;

vector<int> optimal_sequence_fast(map<int, vector<int>> &cache, int n)
{
	for (auto pair: cache)
		if (pair.first == n)
			return pair.second;

	int a = n;
	int b = n;
	int c = n;
	vector<int> seq1, seq2, seq3;
	if (n % 3 == 0)
	{
		seq1 = optimal_sequence_fast(cache, n/3);
		seq1.pb(n);
		a = seq1.size();
	}
	if (n % 2 == 0)
	{
		seq2 = optimal_sequence_fast(cache, n/2);
		seq2.pb(n);
		b = seq2.size();
	}
	if (n > 1)
	{
		seq3 = optimal_sequence_fast(cache, n-1);
		seq3.pb(n);
		c = seq3.size();
	}

	int m = min(a, min(b, c));
	if (m == a)
	{
		cache.insert(pair<int, vector<int>>(a, seq1));
		return seq1;
	}
	if (m == b)
	{
		cache.insert(pair<int, vector<int>>(b, seq2));
		return seq2;
	}
	if (m == c)
	{
		cache.insert(pair<int, vector<int>>(c, seq3));
		return seq3;
	}

	return seq1;
}

vector<int> optimal_sequence(int n) {
	std::vector<int> sequence;
	while (n >= 1) {
		sequence.push_back(n);
		if (n % 3 == 0) {
			n /= 3;
		} else if (n % 2 == 0) {
			n /= 2;
		} else {
			n = n - 1;
		}
	}
	reverse(sequence.begin(), sequence.end());
	return sequence;
}

int main() {
	int n;
	std::cin >> n;

	map<int, vector<int>> cache;
	cache.insert(pair<int, vector<int>>(1, {1}));
	cache.insert(pair<int, vector<int>>(2, {1, 2}));

	cout << "FAST\n";
	vector<int> sequence_fast = optimal_sequence_fast(cache, n);
	std::cout << sequence_fast.size() - 1 << " ";
	for (size_t i = 0; i < sequence_fast.size(); ++i)
		std::cout << sequence_fast[i] << " ";
	std::cout << std::endl;

	cout << "SLOW\n";
	vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << " ";
	for (size_t i = 0; i < sequence.size(); ++i)
		std::cout << sequence[i] << " ";
	std::cout << std::endl;
}