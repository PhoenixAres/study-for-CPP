#include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
int t=(m >> i) & 1;
    if (t) return n | (t << i);
    else return n & (~(1 << i));
}

int main() {
	int n, m, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}