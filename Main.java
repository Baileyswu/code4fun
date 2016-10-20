	import java.util.*;
	import java.io.*;
	import java.math.*;
	
	public class Main{
		public static void main(String[] args) {
			Scanner cin = new Scanner(new BufferedInputStream(System.in)); 
			int T = cin.nextInt();
			BigDecimal two = new BigDecimal("2.00000");
			for(int o = 0;o < T;o++) {
				int n = cin.nextInt();
				BigDecimal A = new BigDecimal("1.00000");
				BigDecimal B = new BigDecimal("0.00000");
				BigDecimal t = new BigDecimal("1.00000");
				BigDecimal a = new BigDecimal("1.00000");
				for(int i = 0;i < n-1;i++) {
					a = cin.nextBigDecimal();
					t = a.divide(t, 8, BigDecimal.ROUND_HALF_UP);
					if(i%2 == 0) B = B.add(t);
					else A = A.add(t);
				}
				t = A.multiply(B);
				MathContext mc = new MathContext(8, RoundingMode.HALF_UP);
				BigDecimal ans = new BigDecimal(Math.sqrt(t.doubleValue()), mc);
				ans = ans.multiply(two);
				ans = ans.setScale(5, RoundingMode.HALF_UP);
				System.out.println("Case #"+(o+1)+": "+ans);
			}
		}
	}
