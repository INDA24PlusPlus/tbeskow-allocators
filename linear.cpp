#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define INF ((ll)(1e9+7))
#define fo(i, n) for(ll i=0;i<((ll)n);i++)
#define deb(x) cout << #x << " = " << (x) << endl;
#define deb2(x, y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define LSOne(S) ((S) & (-S))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;
typedef vector<vpl> vvpl;

struct Linear{
    char* buffer;
    size_t offset = 0;
    size_t size;
    Linear(size_t size) : size(size){
        buffer = new char[size];
    }
} linear(1000);

void* alloc(size_t size, size_t alignment) {
    while(linear.offset % alignment != 0) linear.offset++;
    void* pointer = linear.buffer+linear.offset;
    linear.offset += size;
    if(linear.offset > linear.size){
        throw "Out of memory";
    }
    return pointer;
}

void reset() {
    linear.offset = 0;
}



int main() {
    cin.tie(0)->sync_with_stdio(0);

    int* numbers = (int*)alloc(5 * sizeof(int), alignof(int));
    for(int i = 0; i < 5; i++) {
        numbers[i] = i + 1;
    }
    
    for(int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    reset();
    
    double* doubles = (double*)alloc(3 * sizeof(double), alignof(double));
    for(int i = 0; i < 3; i++) {
        doubles[i] = i + 0.5;
    }
    
    for(int i = 0; i < 3; i++) {
        cout << doubles[i] << " ";
    }
    cout << endl;

    return 0;
}