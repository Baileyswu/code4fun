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
		BigInteger tep = po(a, k/2);
		tep = tep.multiply(tep);
		BigInteger t;
		if(k % 2 != 0)
			tep = tep.multiply(BigInteger.valueOf(a));
		return tep;
	}
	public static BigInteger head(int n)
	{
		//System.out.print("n "+n);
		BigInteger r = zero;
		BigInteger p = zero;
		for(int i = 0;i < all;i++)
		{
			if(n < prim[i])
				break;
			if(n%prim[i] == 0)
				r = r.add(one);
			while(n%prim[i]==0)
			{
				p = p.add(one);
				n /= prim[i];
			}
		}
		if(n != 1)
		{
			r = r.add(one);
			p = p.add(one);
		}
		//System.out.println(" r "+r+" p "+ p);
		if(r.compareTo(p) != 0)
			return de;
		return r;
	}
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));   
        set();
        while(cin.hasNext())
        {
           	int n = cin.nextInt();
           	int m = cin.nextInt();
     		BigInteger ans = po(m, n);
           	//System.out.println("ans"+ans);

     		for(int i = 2;i <= m;i++)
     		{
     			if(m % i != 0)
     				continue;
     			int k = m/i;
     			BigInteger r = head(i);
           		//System.out.print("r "+r+" ");

     			if(r.compareTo(de) == 0)
     				continue;
     			r = r.mod(two);
     			if(r.compareTo(zero) == 0)
     				r = one;
     			else
     				r = de;
     			ans = ans.add(po(k, n).multiply(r));
           		//System.out.println(po(k, n).multiply(r));
     		}
            System.out.println(ans);
        }
    }
}
