#include <iostream>

using namespace std;

int main()
{
	int N; cin >> N;
	for (int k = 0; k < (1 << N); k++) {
		cout << k << endl;
	}
	return 0;
}
