using System;
using System.Collections.Generic;
using System.Linq;
namespace Ex06
{
    public class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            Dictionary<char, int> dic = new Dictionary<char, int>();
            for(int i=0;i<str.Length;i++)
            {
                if(dic.ContainsKey(str[i]))
                {
                    dic[str[i]] ++;
                }
                else
                {
                    dic.Add(str[i], 1);
                }
            }
            var dicSort = from objDic in dic orderby objDic.Key select objDic;
            foreach (KeyValuePair<char, int> kvp in dicSort)
                Console.WriteLine(kvp.Key + ":" + kvp.Value);
            Console.ReadKey();
        }
    }
}