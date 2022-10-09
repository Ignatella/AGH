namespace LiskovSubstitution
{
    internal class Program
    {
        static void Main(string[] args)
        {
            IEnumerable<Organization> organizations = new List<Organization> // Covariant container
            {
                new Bank(),
                new School()
            };
        }
    }
}