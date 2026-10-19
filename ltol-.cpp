#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100000
#define pb push_back
#define fr front
#define pop pop_front
ll a[N];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	deque<int> q1;
	for (int i = 0; i < n; i++){
		q1.push_back(a[i]);
	}
	
	
	deque<int> q2; 
	
	int cnt = 0;
	while(!q1.empty()){
			if(q2.empty()){
				q2.pb(q1.fr());
				q1.pop();
			
			}
			
			//2
			else if((q1.fr() > q1.back()) && (q2.fr() > q1.back())){
				if(q1.fr() > q2.fr()){
					q1.pb(q2.fr());
					q2.pop();
				}
				else{
					q1.pb(q1.fr());
					q1.pop();
				}
			
			}
			//3
			else if ((q1.fr() > q1.back()) && (q1.fr() > q2.back())){
				if(q1.back() > q2.back()){
					q1.pb(q1.fr());
					q1.pop();
				}
			
			}
			//4
			else if((q1.fr() > q1.back()) || (q2.fr() > q1.back())){
				if(q1.fr() > q2.fr()){
					q1.pb(q1.fr());
					q1.pop();
				}
				else {
					q1.pb(q2.fr());
					q2.pop();
				}
			}
			
			//5
			else if((q1.fr() > q1.back()) || (q1.fr() > q2.back())){
				if(q1.back() > q2.back()){
					q2.pb(q1.fr());
					q1.pop();
				}
				else {
					q1.pb(q1.fr());
					q1.pop();
				}
			}
			//6
			else {
				if(q1.fr() > q2.fr()){
					q1.pb(q2.fr());
					q2.pop();
				}
				else {
					q1.pb(q1.fr());
					q1.pop();
				}
			}
			
			cnt++;
			cout << "B" <<cnt << endl;
			for (int i = 0; i < q1.size(); i++){
				cout << q1[i] << " ";
			}
			cout << endl;
			for (int i = 0; i < q2.size(); i++){
				cout << q2[i] << " ";
			}
			cout << endl;
			if(cnt == 7){
				return 0;
			}
		
		}

	cout << cnt << endl;
	
	
}
	
	
	


