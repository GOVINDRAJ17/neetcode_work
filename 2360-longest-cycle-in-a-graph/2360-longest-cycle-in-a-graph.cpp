class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> visited(n,-1);
        int time=0;
        int ans=-1;

        for(int i=0;i<n;i++){
            if(visited[i]!=-1)
                continue;
            int curr=i;
            int starttime=time;
            while(curr!=-1 && visited[curr]==-1){
                visited[curr]=time;
                time++;
                curr=edges[curr];
            }
            if(curr!=-1 && visited[curr]>=starttime){
                ans=max(ans,time-visited[curr]);
            }
        }return ans;
    }
};