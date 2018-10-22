import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		double sum=0;
		double a;
		for(int i=0;i<12;i++)
		{
			a=cin.nextDouble();
			sum+=a;
		}
		sum/=12;
		System.out.println('$'+String.format("%1$.2f", sum));

	}

}
