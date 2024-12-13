#include<vector>
#include<string>
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::vector<char> output;
        gen(n,0,0,output,result);
        return result;
    }   
private:
    void gen(int n, int left_cnt, int right_cnt, std::vector<char>& output, std::vector<std::string>& result){
        if(left_cnt >= n && right_cnt >= n){
            result.push_back(std::string(output.begin(),output.end()));
            return;
        }
        if(left_cnt < n){
            output.push_back('(');
            gen(n,left_cnt + 1, right_cnt,output,result);
            output.pop_back();
        }
        if(right_cnt < left_cnt){
            output.push_back(')');
            gen(n, left_cnt, right_cnt+1, output, result);
            output.pop_back();
        }
    }
};