#include<stdio.h>
int main() {
	int ar[50],n,sv,l,h,m,flag=0;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	
	printf("Ente %d elemenents\n",n);
	for(int i=0;i<n;i++)
	scanf("%d",&ar[i]);
	
	printf("Enter element to be searched : ");
	scanf("%d",&sv);
	
	l=0;
	h=n-1;
	while(l<=h) {
		m = (l+h)/2;
		
		if(sv>ar[m])
			l = m+1;
		else if(sv<ar[m])
			h = m-1;
		else {
			printf("%d found!",sv);
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("%d not found!",sv);
	
	return 0;
}
