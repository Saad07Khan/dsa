//fibonacci using multiple recursion calls
class Solution {
public:
    int fib(int n) {

        if(n<=1)
        {
            return n;
        }

        int last = fib(n-1);
        int slast = fib(n-2);// wont execute until above recursive call executes

        return f+s;

        
        
    }
};