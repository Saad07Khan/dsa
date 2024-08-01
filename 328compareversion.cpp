class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        int n=version1.length();
        int m=version2.length();
        // int ver1;
        // int ver2;

        while(i<n || j<m)
        {
            int ver1=0;
            int ver2=0;
            while(i<n && version1[i]!='.')
            {
                ver1=ver1*10+(version1[i]-'0');
                i++;
            }

            while(j<m && version2[j]!='.')
            {
                ver2=ver2*10+(version2[j]-'0');
                j++;

            }

            if(ver1>ver2)
            {
                return 1;
            }

            if(ver1<ver2)
            {
                return -1;
            }

            i++;
            j++;
        }

        return 0;
        

    }
};