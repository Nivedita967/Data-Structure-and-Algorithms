class FreqStack {
    //Crearing hashmaps in our Freqstack class
    HashMap<Integer, Integer> freq = new HashMap<>();
    HashMap<Integer, Stack<Integer>> m = new HashMap<>();
    //Initialising maxfreq as 0
    int maxfreq = 0;

    //Implementing push method
    public void push(int x) {
        //Finding frequency and incresing frequency
        int f = freq.getOrDefault(x, 0) + 1;
        freq.put(x, f);
        //Finding maxfreq
        maxfreq = Math.max(maxfreq, f);
        //If m doesnt contain f as key, we put it in
        if (!m.containsKey(f)){
            m.put(f, new Stack<Integer>());
        } 
        //Then we get freq and add x
        m.get(f).add(x);
    }

    //Implementing pop method
    public int pop() {
        //Finding frequency and decreasing frequency
        int x = m.get(maxfreq).pop();
        freq.put(x, maxfreq - 1);
        //If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
        if (m.get(maxfreq).size() == 0) maxfreq--;
        return x;
    }
}
