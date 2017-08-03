using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1009B
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] words = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            Array.Reverse(words);
            for(int i=0;i<words.Length-1;i++)
            {
                Console.Write(words[i] + " ");
            }
            Console.Write(words[words.Length - 1]);
            Console.ReadKey();
        }

    }
}