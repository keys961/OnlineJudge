using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n=0;
            n = Convert.ToInt32(Console.ReadLine());
            int times = 0;
            while(n!=1)
            {
                if(n%2==0)
                {
                    n /= 2;
                    times++;
                }
                else
                {
                    n = (3*n+1)/2;
                    times++;
                }
            }
            Console.WriteLine(times);
            Console.ReadKey();
        }
    }
}