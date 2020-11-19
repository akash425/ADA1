#include <stdio.h>

int n=0;
void min_max(int arr[], int n){
    int min=arr[0],max=arr[0]; 
    for ( int i = 1; i < n; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
        if (arr[i]<min)
        {
            min=arr[i];
        }
    }
    printf("Max number:%d\nMin number:%d",max,min);

}

int main(){
    //int arr[n];
    printf("Enter number of elements:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    min_max(arr, n);
}