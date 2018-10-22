/*--------------------------------------------
 * File Name: POJ 1091
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-17 18:39:51
--------------------------------------------*/

import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static BigInteger zero = new BigInteger("0");
	public static BigInteger one = new BigInteger("1");
	public static BigInteger de = new BigInteger("-1");
	public static BigInteger two = new BigInteger("2");
	public static int[] num = new int[10000];
	public static int[] prim = new int[10000];
	public static int[] fac = new int[50];
	public static int all;
	public static void set()
	{
		for(int i = 0;i < 10000;i++)
			num[i] = 1;
		all = 0;
		for(int i = 2;i < 10000;i++)
			if(num[i] != 0)
			{
				prim[all++] = i;
				//System.out.println(i+" "+prim[all-1]);
				for(int j = i*i;j < 10000;j += i)
					num[j] = 0;
			}
	}
	public static BigInteger po(int a, int k)
	{
		if(k == 0)
			return one;
		if(k == 1)
			return BigInteger.valueOf(a);
		BigInteger tep = po(a, k/2);
		tep = tep.multiply(tep);
		BigInteger t;
		if(k % 2 != 0)
			tep = tep.multiply(BigInteger.valueOf(a));
		return tep;
	}
	public static int head(int n)
	{
		int cnt = 0;
		for(int i = 0;i < all;i++)
		{
			if(n < prim[i])
				break;
			if(n%prim[i] == 0)
			{
				n /= prim[i];
				fac[cnt++] = prim[i];
     			//System.out.printf("%d %d\n", cnt-1, fac[cnt-1]);
			}
			while(n%prim[i] == 0)
				n /= prim[i];
		}
		return cnt;
	}
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));   
        set();
        while(cin.hasNext())
        {
           	int n = cin.nextInt();
           	int m = cin.nextInt();
           	/*if(n == 0)
           	{
           		if(m == 1)
           			System.out.println(1);
           		else
           			System.out.println(0);
           		continue;
           	}*/
     		BigInteger ans = zero;
     		int cnt = head(m);
     		//System.out.printf("cnt %d\n", cnt);
     		int r = 1 << cnt;
     		for(int i = 0;i < r;i++)
     		{
     			int s = i, tmp = 1, p = 0;
     			for(int j = 0;j < cnt;j++)
     			{
     				if(s % 2 == 1)
     				{
     					tmp *= fac[j];
     					p++;
     				}
     				s /= 2;
     			}
     			BigInteger t = po(m/tmp, n);
     			//System.out.printf("%d %d %d %d\n", i, tmp, p, t);
     			if(p % 2 == 1)
     				ans = ans.subtract(t);
     			else
     				ans = ans.add(t);
     		}
            System.out.println(ans);
        }
    }
}
