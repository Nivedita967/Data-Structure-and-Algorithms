# You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the i-th job, you have to finish all the jobs j where
#  0 <= j < i).
# You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. 
# The difficulty of a day is the maximum difficulty of a job done in that day.
# Given an array of integers jobDifficulty and an integer d. The difficulty of the i-th job is jobDifficulty[i].
# Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.



class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        if d > len(jobDifficulty):
            return -1
        
        # index starts from zero.
        # d[i][j]: the minimum job difficulty after i-th cut,
        # range within the first j+1 jobs (job at index j)
        # totally need to make d-1 cuts, and range within all
        # of the len(jobDifficulty) jobs.
        
        dp = {}
        
        # initialization
        running_max = 0
        for k in range(len(jobDifficulty)):
            running_max = max(running_max, jobDifficulty[k])
            dp[(0, k)] = running_max

        # obtain dp[i][j]
        for i in range(1, d):
            # the i-th cut is at least after the i-th element,
            # since each day at least one job has to be scheduled.
            # all days can be included in the last day of the current
            # schedule, so j is in range(i+1, length_of_jobs)
            for j in range(i, len(jobDifficulty)):
                # to obtain dp[i][j], we need to find out all possibilities
                # to schedule i+1 jobs within the first j+1 jobs.
                # since we already know dp[i-1][k] for all k, it suffices
                # to take the minimum of all 
                # (dp[i-1][k] + max(jobDifficulty[k:j+1])) for i <= k <= j
                running_max = 0
                # running_min
                dp[(i,j)] = 2**16
                for k in range(j, i-1, -1):
                    running_max = max(running_max, jobDifficulty[k])
                    dp[(i, j)] = min(dp[(i, j)], dp[(i-1, k-1)] + running_max)
            
            
        return dp[(d-1, len(jobDifficulty)-1)]