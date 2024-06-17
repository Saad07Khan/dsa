import java.util.*;
class lecs
{

    public static void buildp(int [][]dp, int value)
    {
        int n= dp.length;
        for(int i=0;i<n;i++)
        {
            Arrays.fill(dp[i],value);
        }
    }
    public static int lcs(int i, int j, String s1, String s2,int [][]dp)
    {

        if(i<0 || j<0)
        {
            return 0;
        }

        if(dp[i][j]!=-1)return dp[i][j];
        if(s1.charAt(i)==s2.charAt(j))
        {
            return dp[i][j] = 1 +lcs(i-1,j-1,s1,s2,dp);
        }
        else
        return dp[i][j] = 0 + Math.max(lcs(i-1,j,s1,s2,dp),lcs(i,j-1,s1,s2,dp));


    }


    public static int buildlcs(String s1, String s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();

        int [][]dp = new int[n1][n2];

        buildp(dp,-1);

        int ans= lcs(n1-1,n2-1,s1,s2,dp);

        return ans;

    }
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        String s1;
        String s2;

        s1 = sc.next();
        s2 = sc.next();
        int ans = buildlcs(s1,s2);

        System.out.println(ans);

    }
}




void heapsort(int i, int[] arr)
{
    int largest =i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left]>arr[i])
    {
        largest = left;
    }

    if()
    {
        largest = right;
    }

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }
}