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

struct Node{
    ll l, r, val = 0;
    Node *lnode, *rnode;
    Node(ll l, ll r) : l(l), r(r){
        if(r-l > 1){
            ll mid = (l+r)/2;
            lnode = new Node(l, mid);
            rnode = new Node(mid, r);
        }
    }

    void update(ll lo, ll hi, ll val){
        if(hi <= l || r <= lo) return;
        if(lo <= l && r <= hi){
            this->val = val;
            return;
        }
        push();
        lnode->update(lo, hi, val);
        rnode->update(lo, hi, val);
        val = max(lnode->val, rnode->val);
    }

    ll query(ll lo, ll hi){
        if(hi <= l || r <= lo) return 0;
        if(lo <= l && r <= hi) return val;
        push();
        return max(lnode->query(lo, hi), rnode->query(lo, hi));
    }

    void push(){
        if(r-l > 1){
            lnode->val = val;
            rnode->val = val;
        }
    }
};

struct Random{
    char* buffer;
    size_t size;
    Node *st;
    Random(size_t size) : size(size){
        buffer = new char[size];
        srand(time(NULL));
        st = new Node(0, size);
    }
} random(1000);


void* alloc(size_t size, size_t alignment){
    for(int i = 0; i < 1000; i++){
        size_t pointer = (size_t)(random.buffer+((size_t)rand()%random.size)) - (size_t)random.buffer;
        while(pointer % alignment != 0) pointer++;
        if(pointer+size > random.size) continue;
        if(random.st->query(pointer, pointer+size)) continue;
        random.st->update(pointer, pointer+size, 1);
        return (void*)(random.buffer + pointer);
    }
    throw "Could not find memory";
}

void reset(){
    random.st->update(0, random.size, 0);
}

void free(void* pointer, size_t size){
    size_t ptr = (size_t)pointer - (size_t)random.buffer;
    random.st->update(ptr, ptr+size, 0);
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