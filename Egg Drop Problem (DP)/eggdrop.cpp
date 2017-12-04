#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <cstring>


// #define fr(n) for(i=0; i<n; i++)
// #define INF (1<<30)
// #define VI vector<int>
// #define ll long long
// #define ld long double
// #define LL unsigned long long
//#define u64 uint64_t	// 9,223,372,036,854,775,807

using namespace std;


int main(int argc, const char * argv[]) {
	
	int n,m,l,i,j,p,q,k,x;

	ifstream infile("input.txt");
    ofstream outfile("output.txt");

	string s;
	getline(infile,s);

    l = s.size();
    cout<<"L is "<<l<<endl;

    k=0;
    i=0;
    while(s[i]!=','){
        k = k*10 + stoi(s.substr(i,1));
        i++; 
    }
    i++;
    n=k;
    k = 0;
    for(;i<l;i++){
        k = k*10 + stoi(s.substr(i,1));
    }

    int a[k+1][n+1];

    for(i=1;i<n+1;i++){
        a[1][i] = i-1;
    }
    for(i=1;i<k+1;i++){
        a[i][1] = 0;
    }

    for(i=2;i<k+1;i++){
        for(j=2;j<n+1;j++){
            m = 1000000;
            for(x=1;x<j;x++){
                p = 1 + max(a[i-1][x], a[i][j-x]);
                m = min(m,p);
            }
            a[i][j] = m;
        }
    }


    cout<<n<<" "<<k<<endl;
    cout<<a[k][n]<<endl;

    // for(i=1;i<k+1;i++){
    //     for(j=1;j<n+1;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    outfile<< a[k][n] <<endl;






	return 0;

}
