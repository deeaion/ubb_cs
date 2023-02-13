/* Write a program that reads 2 arrays and merges the two arrays into third array.
 Before merging, sort the 2 arrays in ascending order.*/
/*I will use merge sort since after sorting the arrays ,
I will need to use a merge function after sorting out
both arrays. Well actually I still need to create another function to merge since it is not created
to input two arrays and merge them */
#include <stdio.h>
#include<stdlib.h>
//reading the arrays and printing//
int read_array(int *arr)
{
    int i,n;
    n=0;
    while(n<=0)
    {printf("Insert the length of the array:");
    scanf("%d",&n);
    printf("\n");
    if(n<=0)
        printf("Invalid number . Please enter a valid one.\n");
    }
    for(i=0; i<n; i++)
    {
        printf("Give number:");
        printf("\n");
        scanf("%d",arr+i);

    }
    return n;
}
void print_array(int *arr,int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%d ",*(arr+i));

    }
    printf("\n");
}
//merge sort
void merge_sort(int *arr, int l,int r)
{int m;
    if(l<r)
    {
        //mid element
        m=l+(r-l)/2;


    //we sort both halves
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    //and then we merge the sorted halves
    merges(arr,l,m,r);}
}
void merges(int *arr,int l,int m,int r)
{
    int i,j,k;
    int m1,m2;
    m1=m-l+1;//toate elementele pana la mijlocul curent
    m2=r-m;//toate elementele dupa mij curent
    int left[m1],right[m2];
    //we copy all the data from the array in the second one
    for(i=0;i<m1;i++)
        *(left+i)=*(arr+l+i);
    for(i=0;i<m2;i++)
        *(right+i)=*(arr+m+1+i);
    i=0;
    j=0;
    k=l;//de la ce index se pun elementele

    //cat timp nu trecem de cate elemente au cei doi vectori obtinuti efectuam interclasarea
    while(i<m1 && j<m2)
    {
        if(left[i]<=right[j])
        {
            *(arr+k)=*(left+i);
            i++;
        }
        else
        {
            *(arr+k)=*(right+j);
            j++;
        }
        k++;
    }
    //punem elementele reziduale
    while(i<m1)
    {
        *(arr+k)=*(left+i);
        i++;
        k++;
    }
     while(j<m2)
    {
        *(arr+k)=*(right+j);
        j++;
        k++;
    }

}

void interclasare(int *arr,int *arr_f,int *arr_s,int m1,int m2)
{
    int i,j,k;
    i=0;
    j=0;
    k=0;//de la ce index se pun elementele

    //cat timp nu trecem de cate elemente au cei doi vectori obtinuti efectuam interclasarea
    while(i<m1 && j<m2)
    {
        if(arr_f[i]<=arr_s[j])
        {
            *(arr+k)=*(arr_f+i);
            i++;
        }
        else
        {
            *(arr+k)=*(arr_s+j);
            j++;
        }
        k++;
    }
    //punem elementele reziduale
    while(i<m1)
    {
        *(arr+k)=*(arr_f+i);
        i++;
        k++;
    }
     while(j<m2)
    {
        *(arr+k)=*(arr_s+j);
        j++;
        k++;
    }
}
int main()
{
    int el_first,el_second,arr_first[100],arr_second[100],merged_arr[200],merged_length;
    el_first=read_array(arr_first);
    el_second=read_array(arr_second);
    merged_length=el_first+el_second;
    //sorting the vectors
    merge_sort(arr_first,0,el_first-1);
    merge_sort(arr_second,0,el_second-1);
    interclasare(merged_arr,arr_first,arr_second,el_first,el_second);
    print_array(merged_arr,merged_length);

    return 0;

}




