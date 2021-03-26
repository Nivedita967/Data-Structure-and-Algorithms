//Java program for board cutting

import java.io.*;
import java.util.*;

public class CuttingBoard {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner (System.in);
        int q = sc.nextInt();
        int m, n;
        int x, y = x = 1;
        long c = 0;
        int sizeX, sizeY;
        ArrayList<Long> arrY, arrX;
        for (int i = 0; i < q; i++){
            //initializing the variables
            c = 0;
            x = y = 1;
            m = sc.nextInt();
            n = sc.nextInt();
            arrY = new ArrayList<>();
            arrX = new ArrayList<>();
            for (int j = 0; j < m - 1; j++){
                arrY.add(sc.nextLong());
            }
            for (int j = 0; j < n - 1; j++){
                arrX.add(sc.nextLong());
            }
            //sorting, reversing the two arraylists
            Collections.sort(arrX);
            Collections.reverse(arrX);
            Collections.sort(arrY);
            Collections.reverse(arrY);
            sizeX = arrX.size();
            sizeY = arrY.size();
           while (sizeX>0 || sizeY>0){
               //checking if size of two arraylists
               if ((sizeX>0 && sizeY==0) || ((sizeX>0) && (arrX.get(x - 1)>arrY.get(y - 1)))){
                   c += y*arrX.get(x - 1);
                   x++;
                   sizeX--;
               }
               else if (sizeY>0){
                   c += x*arrY.get(y - 1);
                   y++;
                   sizeY--;
               }
               c = c%((int)Math.pow(10,9)+7);
           }
           //printing the results
           System.out.println(c%((int)Math.pow(10,9)+7));
        }
        
    }

}

