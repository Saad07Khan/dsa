import java.util.*;
class leis{


    public static int lis(int prevInd, int ind, int[] arr,int n)
    {
        if(ind>=n)
        {
            return 0;
        }

        int len = 0 + lis(prevInd,ind+1,arr,n);
        if(prevInd==-1||arr[ind]>arr[prevInd])
        {
            len = Math.max(len,1+ lis(ind,ind+1,arr,n));
        }

        return len;
    }
    public static void main(String[] args)
    {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int [] arr = new int[n];

        for(int i=0;i<n;i++)
        {
            int m= sc.nextInt();
            arr[i]=m;
        }

        int len = lis(-1,0,arr,n);
        System.out.println(len);

    }
}