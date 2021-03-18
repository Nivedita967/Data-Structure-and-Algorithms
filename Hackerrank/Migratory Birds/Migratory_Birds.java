//Time Complexity: O(n)    

static int migratoryBirds(List<Integer> arr) {
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();   //hashmap to store the bird id's and their occurences
        hm.put(1,0);
        hm.put(2,0);
        hm.put(3,0);
        hm.put(4,0);
        hm.put(5,0);
        
        for(int i=0; i<arr.size(); i++){
            if(hm.containsKey(arr.get(i)))
                hm.put(arr.get(i), hm.get(arr.get(i))+1);   //update the occurences of each bird 
        }
        
        int max = 0, ans = 0;
        for(Map.Entry element : hm.entrySet()){
            int key = (int)element.getKey();  //retrieve the key
            int value = (int)element.getValue();  //retrieve the value
            
            if(value > max){   //calculate the max value
                ans = key;
                max = value;
            }    
        }
        return ans;  //return id of the bird that is more frequently sighted
     }
