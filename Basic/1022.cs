using System;

namespace Ex07
{
    public class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] newInput = input.Split(new char[] { ' ' },StringSplitOptions.RemoveEmptyEntries);
            int A = Convert.ToInt32(newInput[0]);
            int B = Convert.ToInt32(newInput[1]);
            int D = Convert.ToInt32(newInput[2]);
            int sum = A + B;
            string result = "";
            if (sum == 0)
                Console.WriteLine("0");
            else
            {
                while (sum != 0)
                {
                    result += (sum % D).ToString();
                    sum /= D;
                }
                char[] results = result.ToCharArray();
                Array.Reverse(results);
                foreach (var item in results)
                {
                    Console.Write(item);
                }
                Console.WriteLine();
            }
            Console.ReadKey();
        }
    }
}