import java.math.BigInteger;
import java.util.Scanner;
import java.io.BufferedInputStream;

public class Main {

    //private static BigInteger two = new BigInteger("2");

    public static void main(String[] args)
    {
	    String s;
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        s = in.next();
        BigInteger num = new BigInteger(s);
        if(check(num))
            System.out.println("Yes");
        else
            System.out.println("No");
        System.out.println(num.add(num));
    }

    private static boolean check(BigInteger num)
    {
        BigInteger doubledNum = num.add(num);
        int[] check = new int[10];
        while(num.compareTo(BigInteger.ZERO) > 0)
        {
            check[num.mod(BigInteger.TEN).intValue()]++;
            num = num.divide(BigInteger.TEN);
        }

        while(doubledNum.compareTo(BigInteger.ZERO) > 0)
        {
            int digit = doubledNum.mod(BigInteger.TEN).intValue();
            if(check[digit] == 0)
                return false;
            check[digit]--;
            doubledNum = doubledNum.divide(BigInteger.TEN);
        }
        return true;
    }
}