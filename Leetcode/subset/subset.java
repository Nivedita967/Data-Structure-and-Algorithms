import java.util.*;
class subset {
    public static void main(String[] args) throws Exception {
        int[] array = new int[]{1, 2, 3};
        ArrayList<ArrayList<Integer>> results = generatePowerSets(array);
        
        ArrayList<Integer> set;
        System.out.print("[");
        for (int i = 0; i < results.size(); i++) {
            
            set = results.get(i);
            
            System.out.print("[");
            for (int j = 0; j < set.size(); j++) {
                
                System.out.printf("%d%s", 
                    set.get(j),
                    j < set.size() - 1 ? "," : "");
            }
            System.out.printf("]%s", i < results.size() - 1 ? "," : "");
        }
        System.out.println("]");
    }
    
    public static ArrayList<ArrayList<Integer>> generatePowerSets(int[] array) {
        ArrayList<ArrayList<Integer>> results = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < Math.pow(2, array.length); i++) {
            results.add(powerSets(array, i));
        }
        return results;
    }
    
    public static ArrayList<Integer> powerSets(int[] array, int n) {
        
        ArrayList<Integer> result = new ArrayList<Integer>();
        ArrayList<Integer> bin = convertToBin(n, array.length);
        for (int i = 0; i < bin.size(); i++) {
            if (bin.get(i) == 1) {
                result.add(array[i]);
            }
        }
        return result;
    
    }
    
    public static ArrayList<Integer> convertToBin(int n, int pad) {
        // convert n (decimal) to binary
        ArrayList<Integer> results = new ArrayList<Integer>();
        while (n > 0) {
            results.add(0, n % 2);
            n = n / 2;
        }
        
        // zero padding
        if (results.size() < pad) {
            for (int i = 0; i < pad - results.size() + 1; i++) {
                results.add(0, 0);
            }
        }
        
        return results;
    }
}

