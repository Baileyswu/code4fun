import java.util.*;

import java.io.*;

import java.math.*;



public class Main {

    public static BigInteger one = new BigInteger("1");

    public static void main(String[] args) {

        Scanner cin = new Scanner(new BufferedInputStream(System.in));   

        while(cin.hasNext())

        {

            int n = cin.nextInt();

            int k = cin.nextInt();

            BigInteger ans[] = new BigInteger[1100];
            for(int i = 0;i <= n;i++)
                ans[i] = one;
            for(int i = 2;i <= k;i++) {
    			for(int j = i;j <= n;j++)
    				ans[j] = ans[j].add(ans[j-i]);
    		}
            System.out.println(ans[n]);
        }

    }

}