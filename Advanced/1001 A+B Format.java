import java.text.NumberFormat;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		long a, b;
		Scanner in = new Scanner(System.in);
		
		a = in.nextLong();
		b = in.nextLong();
		
		String numberFormat = NumberFormat.getInstance().format(a+b);		
		System.out.println(numberFormat);
	}
}
