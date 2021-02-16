public class Solution {

  public int reverse(int x) {
    int reversed = 0;
    while (x != 0) {
      int temp = reversed * 10 + x % 10;
      x = x / 10;
      if (temp / 10 != reversed) {
        return 0;
      }
      reversed = temp;
    }

    return reversed;
  }
}
