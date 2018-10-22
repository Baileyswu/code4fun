import java.util.*;
import java.io.*;
import java.math.*;

public class Main
{
    public static BigInteger ans[] = new BigInteger[105];
    public static void solve(int x)
    {
        if(ans[x-1] == null)
            solve(x-1);
        ans[x] = ans[x-1].multiply(BigInteger.valueOf(3)).subtract(ans[x-2]);
    }
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int x;
        ans[1] = BigInteger.valueOf(1);
        ans[2] = BigInteger.valueOf(3);
        solve(100);
        while(cin.hasNext())
        {
            x = cin.nextInt();
            System.out.println(ans[x]);
        }
    }
}