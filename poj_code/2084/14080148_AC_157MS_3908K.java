import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));   
        BigInteger one = BigInteger.valueOf(1);
        BigInteger zero = BigInteger.valueOf(0);
        BigInteger two = BigInteger.valueOf(2);
        BigInteger[] ans = new BigInteger[105];
        ans[0] = ans[1] = one;
        ans[2] = two;
        for(int i = 2;i < 100;i++)
        {
            ans[i+1] = zero;
            for(int j = 0;j <= i/2;j++)
                ans[i+1] = ans[i+1].add(ans[j].multiply(ans[i-j]));
            ans[i+1] = ans[i+1].multiply(two);
            if(i%2==0)
                ans[i+1] = ans[i+1].subtract(ans[i/2].pow(2));
        }
        while(cin.hasNext())
        {
            int n = cin.nextInt();
            if(n == -1)
                break;
            System.out.println(ans[n]);
        }
    }
}
