
void minHeapify(int arr[],int n, int i)
{
    int li= left(i);
    int ri= right(i);
    int smallest=i;
    if(li<size && arr[li]<arr[smallest])
    {
        smallest=li;
    }
    if(ri<size && arr[ri]<arr[smallest])
    {
        smallest=ri;
    }

    if(smallest!=i)
    {
        swap(arr[i],arr[smallest]);
        minHeapify(smallest);
    }
}



void maxHeapify(int arr[], int n, int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<size && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<size && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }


}

void buildHeap(int arr[], int size) //O(n) TC
{
    for(int i=(size-2)/2;i>=0;i++)
    {
        minHeapify(i);
    }

}


void heapSort()
{
    buildmaxHeap(int arr[], int size);
    for(int i=size-1;i>=1;i++)
    {
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0) //i acts as new size now as last element is not considered
    }
}