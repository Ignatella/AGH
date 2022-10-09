namespace SingleResponsibility
{
    internal class PrimesFS
    {
        public static long CountPrimes(int upTo)
        {
            return upTo > 1 ? Enumerable.Range(2, upTo - 2).Where(x => IsPrime(x)).Count() : 0;
        }

        public static bool IsPrime(int number)
        {
            return !Enumerable.Range(2, number - 2).Any(x => number % x == 0);
        }
    }
}
