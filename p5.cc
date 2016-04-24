#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector <pair <string, int> > dictionary;

int answer_query(string &prefix, int idx) {
	int pos = lower_bound(dictionary.begin(), dictionary.end(), make_pair(prefix, 0))-dictionary.begin();
	pos += idx-1;
	if (pos<dictionary.size() && dictionary[pos].first.size()>=prefix.size() && dictionary[pos].first.substr(0,
		prefix.size())==prefix)
		return dictionary[pos].second+1;
	return -1;
}

int main() {
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) {
		string a; cin >> a;
		dictionary.push_back(make_pair(a, i));
	}
	sort(dictionary.begin(), dictionary.end());
	while (q--) {
		int k; string prefix; cin >> k >> prefix;
		cout << answer_query(prefix, k) << endl;
	}
	return 0;
}
