class Solution {
    public String decodeString(String s) {
        Stack<String> result = new Stack();  //create a stack to store the strings
        Stack<Integer> num = new Stack();    //create a stack to store the numbers
        
        String str = "";  //to store the decoded string
        int index = 0;    //to iterate through the string
        char ch;          //to retrieve each character in the string
        
        while(index<s.length()){
            ch = s.charAt(index);  
            if(Character.isDigit(ch)){   //if the character is a digit
                int count = 0;
                while(Character.isDigit(s.charAt(index))){    //fetch all digits
                    count = count*10 + Character.getNumericValue(s.charAt(index));   //constraints says the max number in the string can be 30
                    index++;
                }
                num.push(count);   //push into the stack
            }
            else if(ch == '['){     //if the character is an opening bracket
                result.push(str);   //push string into the stack
                str = "";           //reinitialize 
                index++;
            }
            else if(ch == ']'){
                String temp = result.pop();   //obtain the topmost element in the stack
                int count = num.pop();
                for(int i=0; i<count; i++)
                    temp += str;              //append according to the given number of occurences
                str = temp;
                index++;
            }
            else{
                str += ch;        //store characters 
                index++;
            }
        }
        return str;     //return the decoded string
    }
}
