#include <cstdio>
#include <iostream>

using namespace std;

long long INF = 1e18;

//Funktion som returnerar komplexiteten av ett heltal
long long getComplexity(int n) {
	if(n == 1) return 1;
	else {
		long long minPlus = INF;
		long long minMult = INF;
		for(int i = 1; i < n; i++) {
			minPlus = min(minPlus, getComplexity(i)+getComplexity(n-i));
		}
		for(int i = 2; i < n-1; i++) {
			if(n%i == 0) minMult = min(minMult, getComplexity(i)+getComplexity(n/i));
		}
		return min(minPlus, minMult);
	}

}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cout << getComplexity(i) << endl;
	return 0;
}

//Optimize loops
//Memoization
//Print 



