class Solution {
public:

void solve(string digits,string output,string mapping[],int index,vector<string>&ans)
{
    if(index>=digits.length())
    {
        ans.push_back(output);
        return;
    }

    int number = digits[index]-'0';
    string value= mapping[number];

    for(int i=0;i<value.length();i++)
    {
        output.push_back(value[i]);
        solve(digits,output,mapping,index+1,ans);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0)
            return ans;
        
        string output="";
        string mapping[10]= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,mapping,0,ans);

        return ans;

        
    }
};