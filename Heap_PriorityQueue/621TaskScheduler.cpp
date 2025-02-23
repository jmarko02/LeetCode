#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freqs(26,0);
        for(char task : tasks) 
            freqs[task - 'A']++;

        priority_queue<int> maxHeap;
        for(int freq : freqs)
            if(freq > 0)
                maxHeap.push(freq);

        queue<pair<int,int>> q;
        int time = 0;

        while(!q.empty() || !maxHeap.empty()){
            time++;
            if(maxHeap.empty()){
                time = q.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if(cnt > 0){
                    q.push({cnt, time + n});
                }
            }
            if(!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};