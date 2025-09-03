#include<iostream>
using namespace std;
int main()
{
  int n1[100],n2[100],arr[100],len1,len2;
  cout<<"\nEnter size of n1 array:";
  cin>>len1;
  cout<<"\nEnter n1 array elements:";
  for(int i=0;i<len1;i++)
  {
    cin>>n1[i];
  }
   
  cout<<"\nEnter size of n2 array:";
  cin>>len2;
  cout<<"\nEnter n2 array elements:";
  for(int i=0;i<len2;i++)
  {
    cin>>n2[i];
  } 
  int k;
  cout<<"\nEnter k value:";
  cin>>k;

  int n=len1+len2;
  //merge both arrays
  int l=0;
  for(int i=0;i<n;i++)
  {
     if(len1>i)
     {
        arr[i]=n1[i];
     }
     else{
        arr[i]=n2[l];
        l++;
     }
  }  

//merge sort
for (int size = 1; size < n; size *= 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * size) {
            int mid = min(left_start + size - 1, n - 1);
            int right_end = min(left_start + 2 * size - 1, n - 1);

            // Merge left_start to mid and mid+1 to right_end
            int n1 = mid - left_start + 1;
            int n2 = right_end - mid;

            int L[100], R[100];
            for (int i = 0; i < n1; i++)
                L[i] = arr[left_start + i];
            for (int j = 0; j < n2; j++)
                R[j] = arr[mid + 1 + j];

            int i = 0, j = 0, k = left_start;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j])
                    arr[k++] = L[i++];
                else
                    arr[k++] = R[j++];
            }
            while (i < n1)
                arr[k++] = L[i++];
            while (j < n2)
                arr[k++] = R[j++];
        }
    }
cout<<"\n"<<k<<"th smallest element is "<<arr[k-1];
}
