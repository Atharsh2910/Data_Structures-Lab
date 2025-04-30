//Program to find the number of winners in a game.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class findWinner{
    public:
    void winner();
};



int main(){
    findWinner w;

    int t;
    scanf("%d", &t);

    while(t--){
        w.winner();
    }

    return 0;
}

//Function to find the winner.
void findWinner::winner() {
    int k, q;
    scanf("%d", &k);
    scanf("%d", &q);

    vector<long long> a(k);
    for(int i=0; i<k; ++i){
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());

    vector<long long> n(q);
    for(int i=0; i<q; ++i){
        scanf("%lld", &n[i]);
    }

    for(int i=0; i<q; ++i){
        if(a[0]>n[i]){
            printf(" %lld", n[i]);
        }
        else{
            printf(" %lld", a[0]-1);
        }
    }
    printf("\n");
}
