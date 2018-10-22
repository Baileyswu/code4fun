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
            BigInteger base = cin.nextBigInteger();
            if(base.compareTo(zero) == 0)
                break;
            String a, b;
            a = cin.next();
            b = cin.next();
            BigInteger an = zero, bn = zero;
            for(int i = 0;i < a.length();i++)
            {
                an = an.multiply(base);
                an = an.add(BigInteger.valueOf(a.charAt(i)-'0'));
            }
            for(int i = 0;i < b.length();i++)
            {
                bn = bn.multiply(base);
                bn = bn.add(BigInteger.valueOf(b.charAt(i)-'0'));
            }
            an = an.mod(bn);

            int p = 0, ans[] = new int[1005];
            while(an.compareTo(zero) != 0)
            {
                ans[p] = an.mod(base).intValue();
                an = an.divide(base);
                p++;
            }
            for(int i = p-1;i > -1;i--)
                System.out.print(ans[i]);
            System.out.println();
        }
    }
}
