
#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Selection_Sorting(int arr[],int size)
{
    int i=0,j=0;
    for(i=0;i<=size-1;i++)
    {
        int min_idx = i;
        for(j=i+1;j<=size-1;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx = j;
            }
        }
            swap(&arr[i], &arr[min_idx]);
    }
}
   
void Insertion_Sorting(int arr[],int size)
{
    for(int i=1;i<=size-1;i++)
    {
        int key=arr[i];
        int j=i-1;

        while((arr[j]>key) && (j>=0))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void bubble_sorting(int arr[],int size)
{
    for(int i=0;i<=size-1;i++)
    {
        for(int j=0;j<(size-1-i);j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int temp_arr[high-low+1];
    int temp_i = 0;
    int left=low;
    int right=mid+1;

    while((left<=mid) && (right<=high))
    {
        if(arr[left]<=arr[right])
            temp_arr[temp_i++]=arr[left++];
        else
            temp_arr[temp_i++]=arr[right++];
    }
    while(left<=mid)
            temp_arr[temp_i++]=arr[left++];
    while(right<=high)
            temp_arr[temp_i++]=arr[right++];
    
    for(int i=low;i<=high;i++)
        arr[i]=temp_arr[i-low];     
}

void merge_sorting(int arr[], int low, int high)
{
    if(low==high)
        return;
        
    int mid=(low+high)/2;
    merge_sorting(arr,low,mid);
    merge_sorting(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void display(int arr[],int size)
{
    for(int i=0;i<=size-1;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[]={10,90,50,70,30,20,100,60,80,40};
    int size = sizeof(arr)/4;

    printf("Before Sorting Array.\n");
    display(arr,size);
    printf("\n");

    printf("Merge Sorting Array.\n");
    merge_sorting(arr,0,size-1);    
    display(arr,size);
    printf("\n");

    // printf("Bubble Sorting Array.\n");
    // bubble_sorting(arr,size);
    // display(arr,size);
    // printf("\n");

    // printf("Insertion Sorting Array.\n");
    // Insertion_Sorting(arr,size);    
    // display(arr,size);
    // printf("\n");

    // printf("Selection Sorting Array.\n");
    // Selection_Sorting(arr,size);
    // display(arr,size);
    // printf("\n");

}

