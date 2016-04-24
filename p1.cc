#include <iostream>
#include <string>
using namespace std;

int convert_in_n(const string s, int n) {
	int ret = 0, pwr = 1;
	int sz = s.length()-1;
	while (sz >= 0) {
		ret += pwr*(s[sz--]-'0');
		pwr *= n;
	}
	return ret;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string two, three; cin >> two >> three;
	int ret;
	char ttwo[] = {'0', '1'};
	char tthree[] = {'0', '1', '2'};
	for (size_t i = 0; i < two.size(); i++) {
		string ct = two;
		for (int ii = 0; ii < 2; ii++) {
			if (ttwo[ii] == two[i]) continue;
			ct[i] = ttwo[ii];
			for (size_t j = 0; j < three.size(); j++) {
				string c3 = three;
				for (int jj = 0; jj < 3; jj++) {
					if (tthree[jj] == three[j]) continue;
					c3[j] = tthree[jj];
					int candid = convert_in_n(ct, 2);
					if (candid == convert_in_n(c3, 3)) {
						ret = candid;
						ii = jj = 4;
						i = two.size();
						j = three.size();
					}
				}
			}
		}
	}
	cout << ret << endl;
	return 0;
}
