using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ch12Ex01
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            int bai = n / 100;
            int shi = (n - bai * 100) / 10;
            int ge = n % 10;
            for(int i=0;i< bai;i++)
            {
                Console.Write("B");
            }
            for(int i=0;i< shi;i++)
            {
                Console.Write("S");
            }
            for (int i = 0; i < ge; i++)
            {
                Console.Write(i+1);
            }
            Console.WriteLine();
            Console.ReadKey();
        }
    }
}