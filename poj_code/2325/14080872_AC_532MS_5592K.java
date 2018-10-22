import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));   
        BigInteger one = BigInteger.valueOf(1);
        BigInteger zero = BigInteger.valueOf(0);
        BigInteger two = BigInteger.valueOf(2);
        while(cin.hasNext())
        {
            BigInteger n = cin.nextBigInteger();
            if(n.compareTo(zero) < 0)
                break;
            else if(n.compareTo(zero) == 0)
            {
                System.out.println("10");
                continue;
            }
            else if(n.compareTo(one) == 0)
            {
                System.out.println("11");
                continue;
            }
            int ans[] = new int[10], p = 0;
            for(int i = 9;i > 1;i--)
            {
                while(n.mod(BigInteger.valueOf(i)).compareTo(zero) == 0)
                {
                    n = n.divide(BigInteger.valueOf(i));
                    ans[i]++;
                    p++;
                }
            }
            if(n.compareTo(BigInteger.valueOf(9)) > 0)
            {
                System.out.println("There is no such number.");
                continue;
            }
            if(p == 1)
                System.out.print("1");
            for(int i = 1;i < 10;i++)
                if(ans[i] > 0)
                    for(int j = 0;j < ans[i];j++)
                        System.out.print(i);
            System.out.println();
        }
    }
}
