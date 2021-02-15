
static String isBalanced(String s) {
    //create a Stack for storing characters
        Stack <Character> st=new Stack<>();
        boolean isbal=true;
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            switch(ch){
                //if any of these case is true than push in stack
                case '(':
                case'{':
                case '[':{
                    st.push(ch);
                    continue;
                }
                //if this case is true than break
                case ')':{
                if(st.isEmpty()||st.peek()!='(')
                {
                    isbal=false;
                    break;
                }
                else st.pop();
break;
                }
                  case '}':{
                if(st.isEmpty()||st.peek()!='{')
                {
                    isbal=false;
                    break;
                }
                else st.pop();
                break;
                }
                  case ']':{
                if(st.isEmpty()||st.peek()!='[')
                {
                    isbal=false;
                    break;
                }
                else st.pop();
                break;
                }
            }
        }
        // if stack is not empty that means it is not balance;
         if(!st.isEmpty()){
                    isbal=false;
                }
return (isbal)?"YES":"NO";

    }
