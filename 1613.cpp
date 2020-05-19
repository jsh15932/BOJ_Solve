#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int a, b;
int s;
int map[401][401];

void floyd() {
	for(int via = 1; via <= n; via++) {
		for(int from = 1; from <= n; from++) {
			for(int to = 1; to <= n; to++) {
				if(map[from][to] == 0) {
					if(map[from][via] == 1 && map[via][to] == 1) {
						map[from][to] = 1;
					}
					
					else if(map[from][via] == -1 && map[via][to] == -1) {
						map[from][to] = -1;
					}
				}
			}
		}
	}
}

int main() {
	cin >> n >> k;
	
	for(int i = 0; i < k; i++) {
		cin >> a >> b;
		
		map[a][b] = -1;
		map[b][a] = 1;
	}
	
	floyd();
	
	cin >> s;
	
	for(int i = 0; i < s; i++) {
		cin >> a >> b;
		
		cout << map[a][b] << endl;
	}
}
