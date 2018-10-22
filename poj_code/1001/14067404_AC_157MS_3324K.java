import java.io.BufferedInputStream;
import java.util.Scanner;
import java.math.BigDecimal;
import java.text.*;

public class Main{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        BigDecimal a, ans;
        int x;
        while(cin.hasNext())
        {
            a = cin.nextBigDecimal();
            x = cin.nextInt();
            ans = a.pow(x);
            ans = ans.stripTrailingZeros();
            String res = ans.toPlainString();
            if(res.startsWith("0"))
                res = res.substring(1);
            System.out.println(res);

        }

    }
}