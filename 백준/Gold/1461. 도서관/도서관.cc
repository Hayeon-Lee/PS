#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std; 
priority_queue<int> p_q; 
priority_queue<int, vector<int>, greater<int>>n_q; 
int n, m,result, max_n, max_number; 

void check_nq(int a){
	result += a * n_q.top();
	for (int i = 0; i < m; i++) {
		if (n_q.size()) n_q.pop();
		else return;
	}
}

void check_pq(int a) {
	result += a*p_q.top();
	for (int i = 0; i < m; i++) {
		if (p_q.size()) p_q.pop();		
		else return;
	}
}


int main() {
	cin >> n >> m; 
	vector<int> v(n); 
	for (int i = 0; i < n; i++) { 
		cin >> v[i];
		if (max_n < abs(v[i])) {
			max_number = v[i]; 
			max_n = abs(v[i]); 
		}	
		if (v[i] < 0) n_q.push(v[i]); 		
		else if(v[i]>0) p_q.push(v[i]);		
	}

	sort(v.begin(), v.end()); 

	if (max_number < 0) check_nq(-1); 
	else check_pq(1); 	
	
	while (n_q.size()) 	check_nq(-2); 
	while (p_q.size()) 	check_pq(2);
	
	cout << result; 
	return 0; 

}