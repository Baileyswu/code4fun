
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        BigInteger[] a = new BigInteger[20];
        a[0] = BigInteger.valueOf(1);
        a[1] = BigInteger.valueOf(2);
        BigInteger sum = a[0];
        for(int i = 2;i < 19;i++)
        {
            sum = sum.multiply(a[i-1]);
            a[i] = sum.add(a[0]);
        }
        while(cin.hasNext())
        {
            int n = cin.nextInt();
            for(int i = 1;i <= n;i++)
                System.out.println(a[i]);
        }

    }
}
