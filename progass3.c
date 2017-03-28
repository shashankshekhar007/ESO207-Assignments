#include <stdio.h>
int n;

void op(int A[], int start, int end){
	int i;
	int k=0, k1=0, k2=0;
	int B[end-start+1];
	if(end<=start)
		return;
	else{
		for(i=start+2; i<=end; i+=3){
			B[k]=A[i];
			k++;
			k1++;
		}
		for(i=start+1; i<=end; i+=3){
			B[k]=A[i];
			k++;
			k2++;
		}
		for(i=start; i<=end; i+=3){
			B[k]=A[i];
			k++;
		}
	}
	for(i=start;i<=end;i++)
		A[i]=B[i-start];
	op(A, start, start+k1-1);
	op(A, start+k1, start+k1+k2-1);
	op(A, start+k1+k2, end);
}


int main(){
	scanf("%d", &n);
	int i;
	int ar[n];
	long long int sum=0;
	for (i=0;i<n;i++)
		scanf("%d", &ar[i]);
	int q;
	int j,l,r;
	op(ar, 0, n-1);
	scanf("%d", &q);
	long long int s[n];
	if(ar[0]>=-1000001 && ar[0]<=1000001)
			s[0]=ar[0];
		else
			s[0]=0;
	for(i=1;i<n;i++){
		if(ar[i]>=-1000001 && ar[i]<=1000001)
			s[i]=ar[i]+s[i-1];
		else
			s[i]=s[i-1];
	}
	while (q--){
		sum=0;
		scanf("%d%d%d%d", &i, &j, &l, &r);
		long long int sum;
		if(i==0)
			sum=s[j];
		else
			sum=s[j]-s[i-1];
		printf("%lld\n", sum);
	}
	return 0;
}