class Solution {
    public int[] arrayRankTransform(int[] arr) {
        TreeSet<Integer> set = new TreeSet<Integer>();
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int a : arr) {
            set.add(a);
        }
        int rank = 1;
        for(int a : set) {
            map.put(a, rank++);
        }
        int[] result = new int[arr.length];
        for(int i = 0; i < arr.length; i++) {
            result[i] = map.get(arr[i]);
        }
        return result;
    }
}