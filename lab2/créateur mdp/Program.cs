using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace HachageMDP
{
    internal class Program
    {
        static void Main(string[] args)
        {

            string inputFile = "Liste_MDP.txt";
            string outputFile = "SortiEncripter.txt";


            string[] mDP = File.ReadAllLines(inputFile);


            using (StreamWriter writer = new StreamWriter(outputFile))
            {
                foreach (string password in mDP)
                {

                    string hash = Hachage.HacherMotDePasse(password);


                    writer.WriteLine(hash);
                }
            }
        }
    }
}