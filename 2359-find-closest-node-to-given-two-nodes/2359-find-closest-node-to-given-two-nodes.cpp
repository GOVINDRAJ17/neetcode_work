class Solution {
public:
    vector<int> getdist(vector<int> & edges,int start){
        int n=edges.size();
        vector<int> dist(n,-1);
        int curr=start;
        int d=0;

        while(curr!=-1 && dist[curr]==-1){
            dist[curr]=d;
            d++;
            curr=edges[curr];
            
        }return dist;
    }


    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1=getdist(edges,node1);
        vector<int> dist2=getdist(edges,node2);

        int ans=-1;
        int best=INT_MAX;

        for(int i=0;i<n;i++){
            if(dist1[i] !=-1 &&dist2[i]!=-1){
                int worstdist=max(dist1[i],dist2[i]);
                if(worstdist<best){
                    best=worstdist;
                    ans=i;
                }
            }
        }return ans;
    }
};