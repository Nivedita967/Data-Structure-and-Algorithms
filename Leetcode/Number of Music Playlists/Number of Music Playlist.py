#Problem:https://leetcode.com/problems/number-of-music-playlists/description/
from collections import defaultdict

#Approach:
# Create a mapping from the number of different songs used to the count of playlists.
# Initially there is one playlist with no songs.
# For each additional song, add playlists with every new song, If we have used more than K songs, add playlists with
# all songs not in the most recent K.

class Solution:
    def numMusicPlaylists(self, N, L, K):
        
        used_count = {0: 1}     # used_count[i] is the number of playlists that have used i different songs

        for song in range(L):

            new_used_count = defaultdict(int)
            for used, count in used_count.items():

                new_used_count[used + 1] += count * (N - used)  # add any of the (N - used) unused songs
                if used > K:
                    new_used_count[used] += count * (used - K)  # add any used song not in the most recent K songs

            used_count = new_used_count

        
        return used_count[N] % (10 ** 9 + 7)
