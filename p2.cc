#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector <int> big, sub, ret;
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		big.push_back(k);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		sub.push_back(k);
	}
	sort(sub.begin(), sub.end());
	for (int i = 0; i+sub.size() <= big.size(); i++) {
		vector <int> temp;
		for (int j = 0; j < sub.size(); j++)
			temp.push_back(big[i+j]);
		sort(temp.begin(), temp.end());
		bool ok = 1;
		for (int j = 0; j < sub.size()-1; j++) {
			if (temp[j]-sub[j] != temp[j+1]-sub[j+1]) {
				ok = 0;
				break;
			}
		}
		if (ok) 
			ret.push_back(i);
	}
	printf("%lu\n", ret.size());
	for (int i = 0; i < ret.size(); i++)
		printf("%d\n", ret[i]+1);
	return 0;
}
