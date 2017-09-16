import java.io.BufferedInputStream;
import java.io.IOError;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main
{

    public static void main(String [] args) throws Exception
    {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int n;
        String a;
        List<Double> list = new ArrayList<>();
        n = in.nextInt();
        for(int i = 0; i < n; i++)
        {
            a = in.next();
            double d = 0;
            try
            {
                d = Double.parseDouble(a);
            }
            catch (Exception e)
            {
                System.out.printf("ERROR: %s is not a legal number\n", a);
                continue;
            }
            if(Math.abs(d) > 1000 || (a.contains(".") && a.length() - a.indexOf('.') > 3))
               System.out.printf("ERROR: %s is not a legal number\n", a);
            else
                list.add(d);
        }

        double sum = 0;
        for(double i : list)
            sum += i;
        if(list.size() == 0)
            System.out.printf("The average of 0 numbers is Undefined\n");
        else if(list.size() == 1)
            System.out.printf("The average of 1 number is %.2f\n", list.get(0));
        else
            System.out.printf("The average of %d numbers is %.2f\n",list.size(), sum / list.size());
    }
}