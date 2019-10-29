#include <stdio.h>
#include <conio.h>
#define size 100
void merge(int a[], int, int, int);
void merge_sort(int a[],int, int);
int partition(int a[], int beg, int end);
void quick_sort(int a[], int beg, int end);
int smallest(int arr[], int k, int n);
void selection_sort(int arr[], int n);
void main()
{
int arr[size], i, n, choice;
clrscr();
printf("\n Enter the number of elements in the array : ");
scanf("%d", &n);
printf("\n Enter the elements of the array: ");
for(i=0;i<n;i++)
{
 scanf("%d", &arr[i]);
}
printf("\n***MENU***");
printf("\n1.MERGE");
printf("\n2.QUICK");
printf("\n3.SELECTION");
printf("\nEnter 4 to exit");
do
{
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
merge_sort(arr, 0, n-1);
printf("\n The sorted array using merge sort is: \n");
for(i=0;i<n;i++)
printf(" %d\t", arr[i]);
break;
case 2:
quick_sort(arr, 0, n-1);
printf("\n The sorted array using quick sort is: \n");
for(i=0;i<n;i++)
printf(" %d\t", arr[i]);
break;
case 3:
selection_sort(arr, n);
printf("\n The sorted array using selection sort is: \n");
for(i=0;i<n;i++)
printf(" %d\t", arr[i]);
break;
}
}while(choice!=4);
getch();
}
void merge(int arr[], int beg, int mid, int end)
{
int i=beg, j=mid+1, index=beg, temp[size], k;
while((i<=mid) && (j<=end))
{
 if(arr[i] < arr[j])
 {
temp[index] = arr[i];
i++;
 }
 else
 {
temp[index] = arr[j];
j++;
 }
index++;
}
if(i>mid)
{
 while(j<=end)
 {
temp[index] = arr[j];
j++;
index++;
 }
}
else
{
 while(i<=mid)
 {
temp[index] = arr[i];
i++;
index++;
 }
}
for(k=beg;k<index;k++)
arr[k] = temp[k];
}
void merge_sort(int arr[], int beg, int end)
{
int mid;
if(beg<end)
{
mid = (beg+end)/2;
 merge_sort(arr, beg, mid);
merge_sort(arr, mid+1, end);
 merge(arr, beg, mid, end);
}
}


int partition(int a[], int beg, int end)
{
int left, right, temp, loc, flag;
loc = left = beg;
right = end;
flag = 0;
while(flag != 1)
{
while((a[loc] <= a[right]) && (loc!=right))
right--;
if(loc==right)
 flag =1;
 else if(a[loc]>a[right])
 {
 temp = a[loc];
 a[loc] = a[right];
 a[right] = temp;
 loc = right;
 }
if(flag!=1)
 {
while((a[loc] >= a[left]) && (loc!=left))
left++;
 if(loc==left)
flag =1;
 else if(a[loc] <a[left])
 {
 temp = a[loc];
a[loc] = a[left];
a[left] = temp;
loc = left;
 }
 }
}
return loc;
}
void quick_sort(int a[],  int beg, int end)
{
int loc;
if(beg<end)
{
 loc = partition(a, beg, end);
quick_sort(a, beg, loc-1);
quick_sort(a, loc+1, end);
}
}

int smallest(int arr[], int k, int n)
{
int pos = k, small=arr[k], i;
for(i=k+1;i<n;i++)
{
 if(arr[i]< small)
 {
 small = arr[i];
 pos = i;
 }
}
return pos;
}
void selection_sort(int arr[],int n)
{
int k, pos, temp;
for(k=0;k<n;k++)
{
 pos = smallest(arr, k, n);
 temp = arr[k];
arr[k] = arr[pos];
 arr[pos] = temp;
}
}
/* ***********OUTPUT***********
 Enter the number of elements in the array : 3

 Enter the elements of the array: 100
125
75

***MENU***
1.MERGE
2.QUICK
3.SELECTION
Enter 4 to exit
Enter your choice:1

 The sorted array using merge sort is:
 75      100     125
Enter your choice:2

 The sorted array using quick sort is:
 75      100     125
Enter your choice:3

 The sorted array using selection sort is:
 75      100     125
Enter your choice:4
*/
