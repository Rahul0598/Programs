//question -
//https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650

#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(vector<int> folders, int workers){
	int n = folders.size();
	int lo = *max_element(folders.begin(), folders.end());
	int hi = accumulate(folders.begin(), folders.end(), 0);
	while(lo < hi){
		int mi = lo + (hi-lo)/2;
		int required = 1, currentLoad = 0;
		for(int i=0; i<n; ++i) {
			if( currentLoad + folders[i] <= mi){
				currentLoad += folders[i];
			}
			else{
				++required;
				currentLoad = folders[i];
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
    cout << res << endl;
    return 0;
}

