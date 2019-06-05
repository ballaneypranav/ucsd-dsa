#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define mp make_pair
#define pb push_back

using namespace std;

// returns number of steps for n,
// and builds the cache
long long build_cache(long long numStepsCache[], long long prevStepCache[], long long n)
{
	if (numStepsCache[n] != 0)
		return numStepsCache[n];

	long long a = n;
	long long b = n;
	long long c = n;

	if (n % 3 == 0)
		a = build_cache(numStepsCache, prevStepCache, n/3);

	if (n % 2 == 0)
		b = build_cache(numStepsCache, prevStepCache, n/2);

	if (n > 1)
		c = build_cache(numStepsCache, prevStepCache, n - 1);

	long long m = min(a, min(b, c));

	if (m == a && n % 3 == 0)
		prevStepCache[n] = n/3;
	else if (m == b && n % 2 == 0)
		prevStepCache[n] = n/2;
	else
		prevStepCache[n] = n-1;	

	numStepsCache[n] = m;
		
	return m;
}

vector<long long> optimal_sequence_fast(long long prevStepCache[], long long numStepsCache[], long long n)
{
	vector<long long> sequence;

	sequence.push_back(n);

	while (n > 0)
	{
		long long a = (n % 3 == 0) ? numStepsCache[n/3] : n;
		long long b = (n % 2 == 0) ? numStepsCache[n/2] : n;
		long long c = (n > 1)      ? numStepsCache[n-1] : n;

		long long m = min(a, min(b, c));

		if (m == a && n % 3 == 0)
			n /= 3;
		else if (m == b && n % 2 == 0)
			n /= 2;
		else
			n--;

		sequence.push_back(n);
	}

	if (sequence.back() == 0)
		sequence.pop_back();

	reverse(sequence.begin(), sequence.end());
	return sequence;
}

/*
vector<int> optimal_sequence_fast(map<int, int> &cache, int n)
{
	cout << cache.size() << endl;
	if (n == 1)
	{
		vector<int> result = {1};
		return result;
	}

	map<int, int>::iterator it = cache.find(n);
	if (it != cache.end())
	{
		int last = it->second;
		vector<int> rest = optimal_sequence_fast(cache, last);
		rest.push_back(n);
		return rest;
	}

	int a = n;
	int b = n;
	int c = n;
	vector<int> seq1, seq2, seq3;
	if (n % 3 == 0)
	{
		seq1 = optimal_sequence_fast(cache, n/3);
		a = seq1.size();
	}
	if (n % 2 == 0)
	{
		seq2 = optimal_sequence_fast(cache, n/2);
		b = seq2.size();
	}
	if (n > 1)
	{
		seq3 = optimal_sequence_fast(cache, n-1);
		c = seq3.size();
	}

	int m = min(a, min(b, c));
	if (m == a)
	{
		cache.insert(pair<int, int>(n, seq1.back()));
		seq1.push_back(n);
		return seq1;
	}
	else if (m == b)
	{
		cache.insert(pair<int, int>(n, seq2.back()));
		seq2.push_back(n);
		return seq2;
	}
	else 
	{
		cache.insert(pair<int, int>(n, seq3.back()));
		seq3.push_back(n);
		return seq3;
	}
}

vector<int> optimal_sequence_not_so_fast(map<int, vector<int>> &cache, int n)
{
	cout << cache.size() << endl;

	map<int, vector<int>>::iterator it = cache.find(n);
	if (it != cache.end())
		return it->second;

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
		cache.insert(pair<int, vector<int>>(n, seq1));
		return seq1;
	}
	else if (m == b)
	{
		cache.insert(pair<int, vector<int>>(n, seq2));
		return seq2;
	}
	else 
	{
		cache.insert(pair<int, vector<int>>(n, seq3));
		return seq3;
	}

}
*/

vector<long long> optimal_sequence(long long n) {
	std::vector<long long> sequence;
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
	long long n;
	std::cin >> n;

	long long numStepsCache[n+1] = {};
	numStepsCache[0] = n;		// quick and dirty fix for optimal_sequence_fast 
	numStepsCache[1] = 1;
	numStepsCache[2] = 2;
	
	long long prevStepCache[n+1] = {};
	prevStepCache[1] = 1;
	prevStepCache[2] = 1;

	// cout << "FAST\n";
	build_cache(numStepsCache, prevStepCache, n);
	vector<long long> sequence_fast = optimal_sequence_fast(numStepsCache, prevStepCache, n);
	std::cout << sequence_fast.size() - 1 << endl;
	for (size_t i = 0; i < sequence_fast.size(); ++i)
		std::cout << sequence_fast[i] << " ";
	std::cout << std::endl;

	// cout << "SLOW\n";
	// vector<int> sequence = optimal_sequence(n);
	// std::cout << sequence.size() - 1 << " ";
	// for (size_t i = 0; i < sequence.size(); ++i)
	// 	std::cout << sequence[i] << " ";
	// std::cout << std::endl;
}