#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    int num[10005] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    while (m--) {
        next_permutation(num, num + n);
    }
    for (int i = 0; i < n; ++i) {
        cout << num[i] << ' ';
    }
    cout << endl;

    return 0;
}