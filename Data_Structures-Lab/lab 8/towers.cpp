//Program to find the maximum number of blocks in the 1st tower.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class findMax {
    public:
    maxHeight();
};

int main() {
    findMax f;

    int t;
    scanf("%d", &t);
    while (t--) {
        f.maxHeight();
    }
 return 0;
}

//Function to find the maximum number of blocks in tower 1.
void findMax :: maxHeight() {

    int n;
    scanf("%d", &n);

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    sort(a.begin() + 1, a.end());

    for (int i = 1; i < n; ++i) {
        if (a[i] > a[0]) {
            a[0] += (a[i] - a[0] + 1) / 2;
        }
    }

    printf("%lld\n", a[0]);
}