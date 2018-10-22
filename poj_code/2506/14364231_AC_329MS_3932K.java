
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static BigInteger[] data = new BigInteger[251];
    public static BigInteger f(int n)
    {
        if(data[n].compareTo(BigInteger.valueOf(-1))!=0)
            return data[n];
        data[n] =  f(n-1).add(f(n-2).multiply(BigInteger.valueOf(2)));
        return data[n];
    }
    public static void main(String[] args) {
       int n;
       data[0] = data[1] = BigInteger.valueOf(1);
       for(int i=2;i<251;i++){
               data[i] = BigInteger.valueOf(-1);
       }
       f(250);
       Scanner in = new Scanner(System.in);
       while(in.hasNextInt()){
           n = in.nextInt();
           System.out.println(data[n]);
       }
    }

}