import java.math.BigInteger;
import java.util.Scanner;
import java.io.BufferedInputStream;

public class Main {

    public static void main(String[] args) {
	    String a, b, c;
	    int  n;
	    BigInteger num1, num2, num3;
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        n = in.nextInt();

	    for(int i = 0; i < n; i++) {
            a = in.next();
            b = in.next();
            c = in.next();
            num1 = new BigInteger(a);
            num2 = new BigInteger(b);
            num3 = new BigInteger(c);
            if(num1.add(num2).compareTo(num3) > 0)
                System.out.println("Case #" + (i+1)
                    + ": " + "true");
            else
                System.out.println("Case #" + (i+1)
                        + ": " + "false");
        }
    }
}