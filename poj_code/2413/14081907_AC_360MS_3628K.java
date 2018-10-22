import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static BigInteger zero = new BigInteger("0");
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));   
        BigInteger f[] = new BigInteger[501];
        f[0] = f[1] = new BigInteger("1");
        for(int i = 2;i < 501;i++)
            f[i] = f[i-1].add(f[i-2]);
        while(cin.hasNext())
        {
            BigInteger a = cin.nextBigInteger();
            BigInteger b = cin.nextBigInteger();
            if(a.compareTo(zero)==0 && b.compareTo(zero)==0)
                break;
            int ans = 0;
            for(int i = 1;i < 501;i++)
            {
                if(a.compareTo(f[i]) <= 0 && b.compareTo(f[i]) >= 0)
                    ans++;
            }
            System.out.println(ans);
        }
    }
}
