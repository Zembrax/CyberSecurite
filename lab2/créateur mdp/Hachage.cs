
using System.Security.Cryptography;
using System.Text;

namespace HachageMDP
{
    internal class Hachage
    {
        public static string HacherMotDePasse(string motDePasse)
        {
            using (SHA256 sha256Hash = SHA256.Create())
            {
                byte[] bytes = sha256Hash.ComputeHash(Encoding.UTF8.GetBytes(motDePasse));

                string hash = BitConverter.ToString(bytes).Replace("-", "").ToLower();

                return hash;
            }
        }
    }
}