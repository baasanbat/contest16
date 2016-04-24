#include <iostream>
#include <string>

using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		string s;
		cin >> s;
		int x = 0, y = 0;
		for (int i = 0; i < s.size(); i++) {
			x *= 2;
			y *= 2;
			int n = s[i]-'0';
			if (n&1) x++;
			if (n&2) y++;
		}
		cout << s.size() << " " << x << " " << y << endl;  
	}
	return 0;
}
