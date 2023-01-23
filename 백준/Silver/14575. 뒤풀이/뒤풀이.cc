#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,t,lsum,dl[1001],dr[1001];

int main () {
  cin >> n >> t;

	for(int i=0;i<n;i++){
    cin >> dl[i] >> dr[i];
    lsum += dl[i];
	}

  sort(dl,dl+n);
	sort(dr,dr+n);

	int mid,ret=-1,left=1,right=1000000,idxl,idxr,tsum;

	while(left<=right){
		mid = (left+right)/2;

		idxl = upper_bound(dl,dl+n,mid)-dl; 
		idxr = lower_bound(dr,dr+n,mid)-dr;
		tsum = mid * n;

		for(int i=0;i<idxr;i++) tsum -= mid-dr[i];

		if(idxl<n || tsum<t) left = mid+1;
		else if(lsum>t) right = mid-1;
		else{
			right = mid-1;
			ret = mid;
		}
	}

	printf("%d\n",ret);

	return 0;

}

