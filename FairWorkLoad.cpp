#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(vector<int> folders, int workers){
	int n = folders.size();
	int lo = *max_element(folders.begin(), folders.end());
	int hi = accumulate(folders.begin(), folders.end(), 0);
	cout << hi << " " << lo << endl;	
	while(lo < hi){
		int mi = lo + (hi-lo)/2;
		cout << "mi = " << mi << endl;
		int required = 1, currentLoad = 0;
		for(int i=0; i<n; ++i) {
			if( currentLoad + folders[i] <= mi){
				currentLoad += folders[i];
				cout << "cl = " << currentLoad << endl;
			}
			else{
			 cout << "else" << endl;
				++required;
				currentLoad = folders[i];
				cout << "cr = " << currentLoad << endl;
			}
		}
		if (required <= workers)
			hi = mi;
		else 
			lo = mi+1;
	}
	return lo;
}

int main() {
    vector<int> calorie(9);
    int x=10;
    for(int i = 0; i <= 8; i++,x+=10){
       calorie[i] = x;
    }
    int res = getMax(calorie, 3);
    //cout << res << endl;
    return 0;
}

