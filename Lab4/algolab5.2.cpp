#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1; 
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i]; i++;
		}
		else
		{
			arr[k] = R[j]; j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i]; i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j]; 
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2; 
		mergeSort(arr, l, m); 
		mergeSort(arr, m + 1, r); 
		merge(arr, l, m, r);
	}
}
int main()
{
	int i,n;
	clock_t start,end; 
	double total_cuptime; 
	printf("Enter size:"); 
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements: "); 
	start=clock();
	for(i=0; i<n; i++) a[i]=(rand()%50000);
	for(i=0; i<n; i++) printf("\t%d",a[i]);
	mergeSort(a,0,n-1); 
	printf("\nSorted Array: \n"); 
	for(i=0; i<n; i++)
	printf("%d ",a[i]);

	printf("\n\nCpu Time Calculation:"); 
	end=clock();
	double total_cputime=((double)(end-start)); 
	printf("\nTotal cpu time=%f",total_cputime); 
	total_cputime=((double)(end-start)/CLOCKS_PER_SEC); 
	printf("\nTotal cpu time in second=%f",total_cputime); 
	return 0;
}
