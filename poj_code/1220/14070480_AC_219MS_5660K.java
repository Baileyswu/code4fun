import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
    public static BigInteger ok(char x)
    {
        if(x >= '0' && x <= '9')
            return BigInteger.valueOf(x-'0');
        if(x >= 'A' && x <= 'Z')
            return BigInteger.valueOf(x-'A'+10);
        return BigInteger.valueOf(x-'a'+36);
    }
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int n;
        n = cin.nextInt();
        for(int y = 0;y < n;y++)
        {
            BigInteger a = cin.nextBigInteger();
            BigInteger b = cin.nextBigInteger();
            String st = cin.next();
            System.out.print(a+" "+st+"\n"+b+" ");
            BigInteger sum = BigInteger.valueOf(0);
            for(int i = 0;i < st.length();i++)
            {
                sum = sum.multiply(a);
                BigInteger temp = ok(st.charAt(i));
                sum = sum.add(temp);
            }
            int ans[] = new int[10000];
            int p = 0;
            while(sum.compareTo(BigInteger.valueOf(0)) != 0)
            {
                ans[p] = sum.mod(b).intValue();
                sum = sum.divide(b);
                p++;
            }
            for(int i = p-1;i >= 0;i--)
            {
                if(ans[i] < 10)
                    System.out.print(ans[i]);
                else if(ans[i] > 9 && ans[i] < 36)
                    System.out.printf("%c", 'A'+ans[i]-10);
                else
                    System.out.printf("%c", 'a'+ans[i]-36);
            }
            if(p == 0)
                System.out.print("0");
            System.out.println("\n");
        }
        
    }
}