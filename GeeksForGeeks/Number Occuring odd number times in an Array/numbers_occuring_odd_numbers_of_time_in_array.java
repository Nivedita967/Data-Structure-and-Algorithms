class Main
{
    // Find odd occurring elements in a given array
    public static void findRepeating(int[] A)
    {
        int xor = 0;
        for (int i: A) {
            xor ^= (1 << i);
        }
 
        System.out.printf("The odd occurring elements are ");
        for (int i: A)
        {
            if ((xor & (1 << i)) != 0)
            {
                System.out.print(i + " ");
                xor ^= (1 << i); // to avoid printing duplicates
            }
        }
    }
    