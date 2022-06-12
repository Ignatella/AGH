namespace SingleResponsibility
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Modern mathematicians define a number as prime if it is divided by exactly two numbers.

            // Typical implementation
            Console.WriteLine(Primes.CountPrimes(1));
            Console.WriteLine(Primes.CountPrimes(12));

            // Functional style
            Console.WriteLine(PrimesFS.CountPrimes(1));
            Console.WriteLine(PrimesFS.CountPrimes(12));
        }
    }
}
