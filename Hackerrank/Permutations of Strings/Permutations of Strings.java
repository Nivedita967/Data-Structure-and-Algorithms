/*
Problem:
Permutations of Strings


*/

import java.util.*;
import java.io.*;
import java.lang.*;
/* 
	Algorithm
	----------
	
	1.) Find the largest contiguous increasing subarray from the right.
		-> If largest subarray ends at ith index then (i - 1)th index is
		   our inverse point.
		-> For example:
		   -----------
				arr -> [9, 5, 2,  4,  3,  1,   0]
						      ^   ^
						      |   |
						     i_p  i	
							(i-1)
	
	2.) Find the frist element from the right, which is greater than the element at
		index inverse_point.
			-> Let say, at index j
			
		-> For example:
		  -------------       end_point
								 ^
				arr -> [9, 5, 2, 4, 3, 1, 0]
				              ^     ^
							  |		|
							 i_p    j
		
	3.) Swap(nums[inverse_point], nums[j])
				arr -> [9, 5, 3, 4, 2, 1, 0]
	
	4.) Reverse all the elements from [inverse_point + 1, len(arr) - 1] (both are inclusive)
	    --> For example:
			------------
				reverse(arr, end_point, length - 1)
				
		    arr -> [9,5,3,0,1,2,4] (This is our next permutation of given input)
*/
class Solution {
	private void swap(int[] nums, int i, int j) {
		if(i == j) return;
		nums[i] = nums[i] ^ nums[j];
		nums[j] = nums[i] ^ nums[j];
		nums[i] = nums[i] ^ nums[j];
	}
	
	private void reverse(int[] nums, int i, int j) {
		while(i < j) {
			swap(nums, i, j);
			i += 1;
			j -= 1;
		}
	}
	
	/** 
		* return false when there is no next permutation and true otherwise
		* Modify array nums to its next permutation
	*/
    public boolean nextPermuatation(int[] nums) {
		int length = nums.length;
		int end_point = length - 1;
		
		while(end_point > 0 && nums[end_point - 1] >= nums[end_point])
			end_point -= 1;
		
		/*
			If end_point is becomes zero, it means this(nums) the our
			final largest permutation.
			
			There is no further permutation is possiable, to indicate
			it return false;
			
			For example:
			------------
				If the given input list is -> [3,2,1]
				                               ^
											   |
											end_point
				No next permutation is possiable, return false.
		*/
		if(end_point <= 0) return false;
		
		int inverse_point = end_point - 1;
		int j = length - 1;
		
		/*
			J never comes at index 0 at all ->
			{always able to find j b/w [end_point, length - 1] }
			why?? you already know.
		*/
		while(j >= 0 && nums[j] <= nums[inverse_point]) j-= 1;
		
		swap(nums, inverse_point, j);
		
		reverse(nums, end_point, length - 1);
		
		return true;
    }
}
 
class MainClass {
	private static int[] toIntegerArray(String[] arr) {
		int length = arr.length;
		int[] list = new int[length];
		for(int i = 0; i < length; i += 1) {
			list[i] = Integer.parseInt(arr[i]);
		}
		return list;
	}
	
	private static void print(int[] nums) {
		int cnt = 0;
		System.out.print("[");
		for(int num : nums) {
			System.out.print(num);
			if(cnt != nums.length - 1) System.out.print(",");
			cnt += 1;
		}
		System.out.println("]");
	}
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter elements in sorted order -> comma(,) separated");
		System.out.println("For Example -> [1,2,3]");
        String line = br.readLine().trim();
		line = line.substring(1, line.length() - 1);
		int[] list = toIntegerArray(line.split(","));
		Solution obj = new Solution();
		do {
			print(list);
		}while(obj.nextPermuatation(list));
    }
}
