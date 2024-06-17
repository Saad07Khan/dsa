import java.util.*;

public class Main {
    public static void maxHeapify(int arr[], int n, int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
            maxHeapify(arr, n, largest);
        }
    }

    public static void buildHeap(int arr[], int size) {
        for (int i = (size - 2) / 2; i >= 0; i--) {
            maxHeapify(arr, size, i);
        }
    }

    public static void heapSort(int arr[]) {
        int size = arr.length;
        buildHeap(arr, size);
        for (int i = size - 1; i >= 1; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            maxHeapify(arr, i, 0);
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int size = sc.nextInt();
        int arr[] = new int[size];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }

        heapSort(arr);

        System.out.println("Sorted array:");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}

class Main{
    public void buildHeap(int arr[], int n)
    {
        for(int i=(n-2)/2;i>=0;i--)
    }

    public void maxHeapify(int arr[], int n, int i)
    {
        int left= 2*i+1;
        int right= 2*i+2;
        int largest=i;
        if(left<n && arr[left]>arr[largest])
        {
            largest=left;
        }



        if(arr[i]!=largest)
        {
            int temp= arr[largest];
            arr[i]=arr[largest];
            
        }
    }
}

{
buildHeap()
for(int i=n-1;i>=0;i--)
{

    swap(arr[0],arr[i]);
    maxHeapify(n,i,0);//call max heapify for root
}

for(int i=(n-2)/2;i>=0;i--)
{
    maxHeapify()
}



void heapsort(int arr[], int n)
{
    buildHeap(arr,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        maxHeapify(0,i,n)
    }
}

void buildHeap(int arr[], int n)
{
    for(int i=(n-2)/2;i>=0;i--)
    {
        maxHeapify(i,n,arr);
    }
}

void maxHeapify(int arr[], int index, int n)
{
    int largest = i;

}