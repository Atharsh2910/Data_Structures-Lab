//Program to find the difference in strength between two players.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class findStrength{
    public:
    void strength();
};

int main() {
    findStrength s;

    int t;
    scanf("%d", &t);

    while(t--){
        s.strength();
    }

    return 0;
}

//Function to find the difference of strength.
void findStrength::strength() {
    int n;
    scanf("%d", &n);

    vector<int> s(n);
    for(int i=0; i<n; ++i){
        scanf("%d", &s[i]);
    }
    
    int max1=0;
    int max2=0;
    for(int i=0; i<n; ++i){
    if( s[i] > max1){
        max2 = max1;
        max1 = s[i];
    }
    else if(s[i]>max2){
        max2 = s[i];
    }
    }

    for(int i=0; i<n; ++i){
     if( s[i] == max1 ){
         printf(" %d", max1 - max2);
     }
     else {
         printf(" %d", s[i] - max1);
     }
    }

    printf("\n");
}
