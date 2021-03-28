// Xenia the mathematician has a sequence consisting of n (n is divisible by 3) positive integers, each of them is at most 7.
//  She wants to split the sequence into groups of three so that for each group of three a, b, c the following conditions held:
// a < b < c;
// a divides b, b divides c.
// Naturally, Xenia wants each element of the sequence to belong to exactly one group of three. Thus, if the required partition exists, then it has  groups of three.
// Help Xenia, find the required partition or else say that it doesn't exist.

import java.util.*;
import java.math.*;
public class XeniaDivisors
{
	public static void main(String[] args)
		{
			Scanner sc = new Scanner(System.in);
			int size = sc.nextInt();
			ArrayList<Integer> out = new ArrayList<>();
			int[] arr = new int[8];
            // initliaze the arr elements to 0
			Arrays.fill(arr,0);
            // works is a flag variable
			boolean works = true;
			for(int i = 0;i<size;i++)
			{
                // take the sequence from user
				int temp = sc.nextInt();
                // track the count of ocurrance of temp in arr
				arr[temp]++;
                // set works to false: required partition does not exist
				if(temp==5||temp==7)
					works = false;
			}
			while(true)
			{
				if(arr[1]==0)
					break;
				out.add(1);
                // 1 is added to out to decrement its ocurance in arr
				arr[1]--;
				if(arr[3]==0)
				{
					if(arr[2]==0)
						break;
					else
					{
						out.add(2);
                        // 2 is added to out to decrement its ocurance in arr
						arr[2]--;
						if(arr[6]==0)
						{
							if(arr[4]==0)
								break;
							else
							{
								out.add(4);
                                // 4 is added to out to decrement its ocurance in arr
								arr[4]--;
							}
						}
						else
						{
							arr[6]--;
							out.add(6);
						}
					}

				}
				else
				{
					arr[3]--;
					out.add(3);
					if(arr[6]==0)
						break;
					else
					{
						out.add(6);
						arr[6]--;
					}
				}
			}
            // size is not divisible by 3 or size = 0
			if(out.size()%3!=0||out.size()==0)
                // does not exist
				works = false;
			if(!works)
                // print -1 as rrequired partition does not exist
				System.out.println("-1");
			else
                // If required partion exists
				for(int i = 0;i<out.size();i++)
				{
					System.out.print(out.get(i)+" ");
                    // divisility by 3
					if((i+1)%3==0)
						System.out.println();
				}
		}
}