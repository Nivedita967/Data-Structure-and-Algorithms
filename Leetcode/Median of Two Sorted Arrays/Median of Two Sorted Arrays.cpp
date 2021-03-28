 double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    if (nums2.size() < nums1.size())
      return findMedianSortedArrays(nums2, nums1);
    int mid = (nums1.size() + nums2.size())/2;
    int odd = (nums1.size() + nums2.size())%2;
    // Start binary search for about right position in smaller array
    int smallStart = 0;
    int smallEnd = nums1.size()-1;
    while (smallEnd - smallStart > 0) {
      int smallMid = (smallStart + smallEnd)/2;
      if (nums1[smallMid] < nums2[mid-smallMid-1])
        smallStart = smallMid+1;
      else
        smallEnd = smallMid;
    }
    // Found the spot in small array, step back one in both small and big array
    // and start searching one step at a time for final answer
    smallStart = std::max(smallStart-1, 0);
    int bigStart = std::max(mid-smallStart-3, 0);
    double ret = 0;
    while (nums1.size() + nums2.size()) {
      int val;
      if (bigStart == nums2.size())
        val = nums1[smallStart++];
      else if (smallStart == nums1.size())
        val = nums2[bigStart++];
      else if (nums1[smallStart] < nums2[bigStart])
        val = nums1[smallStart++];
      else
        val = nums2[bigStart++];
      if (smallStart+bigStart-odd == mid) {
        if (odd)
          return val;
        else
          ret = val;
      }
      else if (smallStart+bigStart-1 == mid)
        return (ret+val)/2.0;
    }
    return 0;
  }