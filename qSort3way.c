#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000000

typedef int el_T;

void swap(el_T* a, el_T* b){
	el_T tmp = *a;
	*a = *b;
	*b = tmp;
}

void qSort3way(el_T a[], int left, int right) {
	int i = left - 1, j = right;
	int p = left - 1, q = right;
	el_T pivot = a[right];
	while(1) {
	/* From left, find the first element greater than or equal to pivot*/
		while(a[++i] < pivot);
	/* From right, find the first element smaller than or equal to pivot*/
		while(a[--j] > pivot) {
			if(j == left) break;
		}
		
		if(i >= j) break;
		swap(&a[i], &a[j]);
		
		if(a[i] == pivot) swap(&a[++p], &a[i]);
		if(a[j] == pivot) swap(&a[--q], &a[j]);
	}
	swap(&a[i], &a[right]);
	int k; 
	j = i - 1;
	for(k = left; k <= p; k++, j--) swap(&a[k], &a[j]);
        i = i + 1;
	for(k = right-1; k >= q; k--, i++) swap(&a[k], &a[i]);
	if(left < j) qSort3way(a, left, j);
	if(i < right) qSort3way(a, i, right);	
}

int main(){
int n, a[MAX];
scanf("%d", &n);
for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
qSort3way(a, 0, n-1);
for(int i = 0; i < n; ++i) printf("%d ", a[i]);
printf("\n");
return 0;
}
