#include <bits/stdc++.h>

using namespace std

;int main() {
	int n,w;
	scanf("%d%d",&n,&w);
	long long arr[n+w-1];
	for(int i=0;i<n+w-1;i++) {
		arr[i]=LLONG_MIN;
	}
	for(int i=0;i<n;i++) {
		scanf("%lld",&arr[i]);
	}
	for(int i=1;i<n;i++) {
		arr[i]+=arr[i-1];
	}
	deque<long long> q;
	long long mx=0,siz;
	for(int i=0;i<min(n,w);i++) {
		while(!q.empty()&&arr[i]>=arr[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
	}
	for(int i=w;i<n+w-1;i++) {
		long long k=i-w-1>=0?arr[i-w-1]:0;
		if(arr[q.front()]-k>mx) {
			mx=arr[q.front()]-k;
			siz=q.front()-i+w+1;
		} else if(arr[q.front()]-k==mx&&q.front()-i+w+1<siz) {
			siz=q.front()-i+w+1;
		}
		while(!q.empty()&&q.front()<=i-w) {
			q.pop_front();
		}
		while(!q.empty()&&arr[i]>=arr[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
	}
	if(arr[q.front()]-arr[n-2]>mx) {
		mx=arr[q.front()]-arr[n-2];
		siz=1;
	} else if(arr[q.front()]-arr[n-2]==mx&&1<siz) {
		siz=1;
	}
	if(mx>0) {
		printf("%lld\n%lld",mx,siz);
	} else {
		printf("0\n0");
	}

	return 0;
}
