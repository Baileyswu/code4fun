import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static long long extend_Euclid(long long a, long long b, long long &x, long long &y)
    {
        if(b==0)
        {
            x = 1;
            y = 0;
            return a;
        }
        long long r = extend_Euclid(b, a%b, y, x);
        y -= a/b*x;
        return r;
    }
    public static long long anti(long long b, long long mod, long long x, long long y)
    {
         long long r = extend_Euclid(b, mod, x, y);
         return (x%mod+mod)%mod;
    }
    public static BigInteger p = new BigInteger("33232930569601");
    public static BigInteger two = new BigInteger("2");
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));   
        while(cin.hasNext())
        {
            BigInteger n = cin.nextBigInteger();
            BigInteger m = cin.nextBigInteger();
            long long s = m.longValue();
            long long q = p.longValue();
            BigInteger ans = new BigInteger("1");
            if(n.divide(two).compareTo(m) < 0)
                m = m.subtract(n.divide(two));
            for(int i = 0;i < m;i++)
            {
                BigInteger t = BigInteger.valueOf(i);
                ans = ans.multiply(n.subtract(t)).mod(p);
                long long a = anti(s-i, q, x, y);
                t = BigInteger.valueOf(a);
                ans = ans.multiply(t).mod(p);
            }
            System.println(ans);
        }
    }
}
