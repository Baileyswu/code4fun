import java.util.*;
import java.math.*;

public class Main {
    public static int cnt;
    public static int fac[] = new int[110];

    public static void Factor(int n) {
        int i, tmp;
        cnt = 0;
        tmp = (int) (Math.sqrt((double) n) + 1e-8);
        for (i = 2; i <= tmp; i++) {
            if (n % i == 0) {
                fac[cnt++] = i;
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 1)
            fac[cnt++] = n;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger ans, tmp, tot;
        int n, m, i, j, k, t;
        while (in.hasNext()) {
            n = in.nextInt();
            m = in.nextInt();
            Factor(m);
            ans = BigInteger.ZERO;
            tot = BigInteger.valueOf(m).pow(n);
            for (i = 1; i < (1 << cnt); i++) {
                tmp = BigInteger.ONE;
                t = i;
                for (j = k = 0; t != 0; t >>= 1, j++) {
                    if (t % 2 == 1) {
                        k++;
                        tmp = tmp.multiply(BigInteger.valueOf(fac[j]));
                    }
                }
                tmp = BigInteger.valueOf(m).divide(tmp);
                tmp = tmp.pow(n);
                if (k % 2 == 1)
                    ans = ans.add(tmp);
                else
                    ans = ans.subtract(tmp);
            }
            System.out.println(tot.subtract(ans));
        }
    }
}