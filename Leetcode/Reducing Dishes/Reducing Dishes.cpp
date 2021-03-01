// Approach:-

// From the observation we can see that the dish with the biggest satisfaction level will be prepared in last to maximize the Like-Time cofficient.

// But when to stop taking the dish with less satisfaction level?
// To do that we can obereve that, if the positive satisfaction is greater or equal to negztive satisfaction of dishes, we include that neagtive dish

// eg if satisfaction=[-9,-8,-1,0,5]

// positive satisfaction=5+0
// and for negative satisfaction if we take -1, then 5>-1 so -1 is included
// now if we do -1+-8=-9 here positive satisfaction is not greater to negative satisfaction so we ignore -8, and everything before that.

// Logic:
//     sort the vector
//     take sum of the values of vector from last
//     if sum<0:
//         stop the addition and store the index i

//     for i:len(vector)
//         time*vector[i]
//         time++

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
    	sort(satisfaction.begin(),satisfaction.end()); // Sorting the vector
     	int n=satisfaction.size();
     	int totalSum=0;
     	int start=n-1; // to store index that lead to the less than 0
     	
     	for (int i = n-1 ; i>=0 ; i--)
     	 {
     	 	totalSum+=satisfaction[i];
     	 	if(totalSum<0) // breaking the loop when totalSum become less than zero
     	 	{
     	 		break;
     	 	}
     	 	start--;
     	 } 
     	 start+=1; // since the start will also include the index of the number which make the sum less than 0 and we don't want that in answer, we increment it
        
        
     	 int time=1;
     	 int finalResult=0;
     	 for (int i = start; i < n;i++)
     	 {
     	 	finalResult+=satisfaction[i]*time; // time*satisfaction
     	 	time++;

     	 }
     	 return finalResult;
        
    }
};
