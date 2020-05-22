#include<iostream>
#include<algorithm>
using namespace std;

int a, b;

int main() {
	for(int i = 0; i < 3; i++) {
		b = 0;
		
		for(int j = 0; j < 4; j++) {
			cin >> a;
			b += a;
		}
		
		switch(b) {
			case 0: puts("D");
			break;
			
			case 1: puts("C");
			break;
			
			case 2: puts("B");
			break;
			
			case 3: puts("A");
			break;
			
			case 4: puts("E");
		}
	}
}
