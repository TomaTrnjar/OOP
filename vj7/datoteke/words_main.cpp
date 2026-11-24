#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct WordCount {
	string word;
	int count;
};

string clean(const string& word) {
	string result;
	for (char c : word) {
		if (isalpha(c))
			result += tolower(c);
	}
	return result;
}

int main()
{
	ifstream in("tekst.txt");
	if (!in) {
		cout << "Datoteka tekst.txt ne postoji\n";
		return 1;
	}

	map<string, int> freq;
	string word;
	while (in >> word) {
		string w = clean(word);
		if (w.empty())
			continue;
		++freq[w];
	}

	cout << "razlicitih rijeci: " << freq.size() << '\n';
	cout << "alice: " << freq["alice"] << '\n';

	vector<WordCount> v;
	for (const auto& p : freq)
		v.push_back({p.first, p.second});

	sort(v.begin(), v.end(), [](const WordCount& a, const WordCount& b) {
		if (a.count != b.count)
			return a.count > b.count;
		return a.word < b.word;
	});

	for (size_t i = 0; i < 5 && i < v.size(); ++i)
		cout << v[i].word << ": " << v[i].count << '\n';
	return 0;
}
