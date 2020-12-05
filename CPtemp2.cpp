/*
  compiler404
*/
#include <bits/stdc++.h>
using namespace std;

#define mp                       make_pair
#define pb                       push_back
#define eb                       emplace_back
#define all(x)                   (x).begin(),(x).end()
#define fi                       first
#define se                       second


typedef long long int            ll;
typedef vector<int> 	         vi;
typedef pair<int,int> 	         pii;
typedef tuple<int, int, int>     tiii;

int nxt() {
    int x;
    cin >> x;
    return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);


	int T; cin >> T;

	while(T--){
		// vector input trick
		vi v(nxt());
		generate(all(v), nxt);
	}

	return 0;
}