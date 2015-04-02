#include <iostream>
#include <vector>

int count = 0;
using namespace std;

void merge(vector<int> & num, int left, int mid, int right, vector<int> & tmp)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    while(i <= mid && j <= right)
    {
        if(num[i] >= num[j])
        {
            tmp[k++] = num[i++];
        }else
        {
            tmp[k++] = num[j++];
            count += mid - i + 1;
        }    
    }
    while(i <= mid)
        tmp[k++] = num[i++];
    while(j <= right)
        tmp[k++] = num[j++];
    while(left <= right)
    {
        num[left] = tmp[left++];
    }
}

void mergeSort(vector<int> & num, int left, int right, vector<int> & tmp)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        mergeSort(num, left, mid, tmp);
        mergeSort(num, mid + 1, right, tmp);
        merge(num, left, mid, right, tmp);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> num(N, 0);
    vector<int> tmp(N, 0);
    for(int i = 0; i < N; ++i)
    {
        cin >> num[i];
    }
    mergeSort(num, 0, N-1, tmp);
    cout << count << endl;

    return 0;
}