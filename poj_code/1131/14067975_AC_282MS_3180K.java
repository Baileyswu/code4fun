import java.util.*;
import java.io.*;
import java.math.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        String st;
        while(cin.hasNext())
        {
            st = cin.nextLine();
            int len = st.length();
            char ch[];
            ch = st.toCharArray();
            BigDecimal b = BigDecimal.valueOf(1);
            BigDecimal d = BigDecimal.valueOf(8);
            BigDecimal a = BigDecimal.valueOf(0);
            for(int i = 2;i < len;i++)
            {
                b = b.multiply(d);
                a = a.add(BigDecimal.valueOf(ch[i]-'0').divide(b));
            }
            System.out.println(st+" [8] = "+a+" [10]");

        }
    }
}