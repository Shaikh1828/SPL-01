// mergesort
#include<stdio.h>
#include<stdlib.h>

void m_sort(int arr[], int left, int right);
void merge(int arr[], int left, int rightfront, int right );

void m_sort(int arr[], int left, int right)
{
    int center ;
    if(left<right)
    {
        center =(left+right)/2 ;
        m_sort(arr, left, center);
        m_sort(arr, center+1, right);
        merge(arr, left, center, right);
    }
}

void merge(int arr[], int left, int rightfront, int right )
{
    int l, r, i, j ,k;
    l = rightfront - left+1;
    r = right - rightfront ;
    int le[l], re[r] ;
    
    for ( i = 0; i < l; i++)
    {
        le[i] = arr[i+left];
    }

    for ( j = 0; j < r; j++)
    {
        re[j] = arr[j+rightfront+1];
    }

    i=0, j=0, k=left;
    while(i<l && j<r)
    {
        if(le[i] < re[j])
        {
            arr[k] = le[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = re[j];
            k++;
            j++;
        }
    }
    while (i<l)
    {
        arr[k] = le[i];
        k++;
        i++;
    }

    while (j<r)
    {
        arr[k] = re[j];
        k++;
        j++;
    }
}

int main()
{
    int n;
    printf("Enter total number : ");
    scanf("%d",&n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i]=rand()%n;
        printf("%d\n",arr[i]);
    }
    printf("\n");

    m_sort(arr, 0, n-1);
    
    for(int i=0; i<n; i++)
    {
        printf("%d\n",arr[i]);
    }

    

}