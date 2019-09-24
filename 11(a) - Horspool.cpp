#include<stdio.h>
#include<string.h>
int n,m;
char p[50],t[50],table[100];

void shiftTable() {
	int i;
	
	for(i=0;i<100;i++) {
		table[i]=m;
	}
	for(i=0;i<=m-2;i++) {
		table[p[i]] = m-i-1;
	}
}

int horspool() {
	int i,k;
	shiftTable();
	i=m-1;
	
	while(i<=n-1) {
		k=0;
		while(k<=m-1 && (p[m-k-1] == t[i-k])) {
			k++;
		}
		if(k==m)
			return i-m+1;
	
		i=i+table[t[i]];
	}
	return -1;
}
int main() {
	int i;
	printf("Enter Text : ");
	gets(t);
	printf("Enter Pattern to be searched : ");
	gets(p);
	
	n=strlen(t);
	m=strlen(p);
	
	i = horspool();
	if(i>0)
		printf("Pattern found at index : %d\n",i);
	else
		printf("Pattern not found!");
	return 0;
}
