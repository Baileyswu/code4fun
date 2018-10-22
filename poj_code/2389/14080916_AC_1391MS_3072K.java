import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));   
        BigInteger one = BigInteger.valueOf(1);
        BigInteger zero = BigInteger.valueOf(0);
        BigInteger two = BigInteger.valueOf(2);
        while(cin.hasNext())
        {
            one = cin.nextBigInteger();
            two = cin.nextBigInteger();
            one = one.multiply(two);
            System.out.println(one);
        }
    }
}
