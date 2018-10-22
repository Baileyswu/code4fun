import java.io.BufferedInputStream;
import java.util.Scanner;
import java.math.BigDecimal;
import java.text.*;

public class V{
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
            System.out.println(ans.toPlainString().replaceAll("^0", ""));

        }

    }
}