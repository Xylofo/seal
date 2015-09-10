#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long INF = 1e18;

vector<long long> save;

//Funktion som returnerar komplexiteten av ett heltal
long long getComplexity(int n) {
	if(save[n] != -1) return save[n];
	if(n == 1) return 1;
	else {
		long long minPlus = INF;
		long long minMult = INF;
		for(int i = 1; i <= n/2; i++) {
			minPlus = min(minPlus, getComplexity(i)+getComplexity(n-i));
		}
		int nsqrt = sqrt(n);
		for(int i = 2; i <= nsqrt; i++) {
			if(n%i == 0) minMult = min(minMult, getComplexity(i)+getComplexity(n/i));
		}
		save[n] = min(minPlus, minMult);
		return min(minPlus, minMult);
	}

}

int main(){
	int n;
	cin >> n;
	save.resize(n+1, -1);
	for(int i = 1; i <= n; i++) cout << i << " " << getComplexity(i)<< endl;
	return 0;
}

//Optimize loops
//Print 

