import java.util.*;
import java.lang.*;
import java.io.*;
class Codechef
{
	public static void main (String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		while(t-- > 0) 
		{
			int n = Integer.parseInt(br.readLine());
			String words[] = br.readLine().split(" ");
			
			Set<String> set = new HashSet<>();
			HashMap<Character, Integer> map = new HashMap<>();
			
			for(String s: words) 
			{
				set.add(s);
				map.put(s.charAt(0), map.getOrDefault(s.charAt(0),0)+1);
			}
			int res = 0, i =0 ;
			Arrays.sort(words, (a,b) -> (int)a.charAt(0)-(int)b.charAt(0));
			StringBuilder one = new StringBuilder();
			StringBuilder two = new StringBuilder();
			while(i < n) 
			{
				int j = i+map.get(words[i].charAt(0));
				map.put(words[i].charAt(0), map.get(words[i].charAt(0))-1);
				while(j < n) 
				{
					one.append(words[j].charAt(0)).append(words[i].substring(1));
					two.append(words[i].charAt(0)).append(words[j].substring(1));
					
					if(set.contains(one.toString())) 
					{
						j += map.get(words[j].charAt(0));
					}
					else
					{
						if(!set.contains(two.toString())) res += 2;
						j++;
					}
					one.setLength(0);
					two.setLength(0);
				}
				i++;
			}

			System.out.println(res);
		}
	}
}
