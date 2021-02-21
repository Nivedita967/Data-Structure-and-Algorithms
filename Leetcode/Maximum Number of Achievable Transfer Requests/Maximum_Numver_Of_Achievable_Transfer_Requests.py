class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        indegree=defaultdict(int)
        ans=0
        r=len(requests)
        
        def backtrack(i,count):
            nonlocal ans
            
            #Base Case
            if i==r:
                for key in indegree:
                    if indegree[key]!=0:
                        return
                    
                # Else it is Balanced State
                #Update the ans
                ans=max(ans,count)
                return
            
            #Access first element of request
            f=requests[i][0]
            t=requests[i][1]
            
            #Take ith request
            indegree[f]-=1
            indegree[t]+=1
            backtrack(i+1,count+1)
            indegree[f]+=1
            indegree[t]-=1
            
            #Do not take ith request
            backtrack(i+1,count)
            
            
        backtrack(0,0)
        
        return ans
            
        