import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));   
        BigInteger zero = BigInteger.valueOf(0);
        while(cin.hasNext())
        {
            BigInteger base = cin.nextBigInteger();
            BigInteger ori = cin.nextBigInteger();
            int ans[] = new int[1000];
            int p = 0;
            if(ori.compareTo(zero) == 0)
            {
                continue;
            }
            while(ori.compareTo(zero) > 0)
            {
                ans[p] = ori.mod(base).intValue();
                ori = ori.divide(base);
                p++;
            }
            int q = 1;
            while(q > 0)
            {
                for(int i = p-1;i > -1;i--)
                {
                    if(ans[i] == 0)
                    {
                        ans[i+1] -= 1;
                        ans[i] = base.intValue();
                    }
                }
                q = 0;
                for(int i = 0;i < p;i++)
                    if(ans[i] == 0)
                        q++;
                if(ans[p-1] == 0)
                    p--;
            }
            for(int i = p-1;i > -1;i--)
                System.out.print(ans[i]);
            System.out.println();
        }
    }
}
