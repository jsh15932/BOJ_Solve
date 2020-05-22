#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

double r, s1, s2;

int main() {
	scanf("%lf", &r);
	
	s1 = M_PI * r * r;
	s2 = r * r* 2;
	
	printf("%.6f\n", s1);
	printf("%.6f", s2);
}
