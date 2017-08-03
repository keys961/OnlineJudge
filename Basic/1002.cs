using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1002B
{
    class Program
    {
        static void Main(string[] args)

       {
            string number = Console.ReadLine();
            char[] _digit = number.ToCharArray();
            Console.ReadKey();
            int sum=0;
            for(int i=0;i<_digit.Length;i++)
            {
                int digits = _digit[i]-48;
                sum += digits;
            }
            int bai = sum / 100;
            int shi = sum / 10 % 10;
            int ge = sum % 10;
            digitss(bai);
            if (bai == 0)
            {
                digitss(shi);
            }
            else
            {
                switch (shi)
                {
                    case 1: Console.Write("yi "); break;
                    case 2: Console.Write("er "); break;
                    case 3: Console.Write("san "); break;
                    case 4: Console.Write("si "); break;
                    case 5: Console.Write("wu "); break;
                    case 6: Console.Write("liu "); break;
                    case 7: Console.Write("qi "); break;
                    case 8: Console.Write("ba "); break;
                    case 9: Console.Write("jiu "); break;
                    default: Console.Write("ling "); break;
                }
            }
            switch (ge)
            {
                case 1: Console.Write("yi"); break;
                case 2: Console.Write("er"); break;
                case 3: Console.Write("san"); break;
                case 4: Console.Write("si"); break;
                case 5: Console.Write("wu"); break;
                case 6: Console.Write("liu"); break;
                case 7: Console.Write("qi"); break;
                case 8: Console.Write("ba"); break;
                case 9: Console.Write("jiu"); break;
                default: Console.Write("ling"); break;
            }
            Console.ReadKey();
        }
        static void digitss(int a)
        {
            switch (a)
            {
                case 1: Console.Write("yi "); break;
                case 2: Console.Write("er "); break;
                case 3: Console.Write("san "); break;
                case 4: Console.Write("si "); break;
                case 5: Console.Write("wu "); break;
                case 6: Console.Write("liu "); break;
                case 7: Console.Write("qi "); break;
                case 8: Console.Write("ba "); break;
                case 9: Console.Write("jiu "); break;
                default: break;
            }
        }
    }
}