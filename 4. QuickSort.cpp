#include<stdio.h>
#define max 10

void quickSort(int ar[], int low, int high);
int partition(int ar[], int low, int high);

void quickSort(int ar[], int l, int r) {
	int s;
	if(l<r) {
		
		s = partition(ar,l,r);
		quickSort(ar, l, s-1);
		quickSort(ar, s+1, r);
	}
}

int partition(int ar[], int l,int r) {
	int pivot = ar[l], i=l+1, j=r,temp;
	
	while(i<=j) {
		while(pivot > ar[i] && i<=r) {
			i++;
		}
		
		while(pivot<ar[j] && j>=l) {
			j--;
		}
			
		if(i<j) {
			temp=ar[i];
			ar[i] = ar[j];
			ar[j] = temp;
		}
	}
	
	temp = ar[l];
	ar[l] = ar[j];
	ar[j] = temp;
	
	return j;
}

int main() {
	int n,ar[20],i;
	
	printf("Enter number of elements\n");
	scanf("%d",&n);
	
	printf("Enter array elements\n");
	
	for(i=0;i<n;i++) {
		scanf("%d",&ar[i]);
	}
	
	quickSort(ar,0,n-1);
	
	printf("After Sorting : \n");
	for(i=0;i<n;i++) {
		printf("%d\t",ar[i]);
	}
}

