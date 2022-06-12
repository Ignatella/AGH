namespace SingleResponsibility
{
    static class Primes
    {
        // But we're still left in a situation where our code has two responsibilities (Mainly looping over numbers).
        public static long CountPrimes(int upTo)
        {
            long count = 0;
            for (int i = 2; i < upTo; i++)
            {
                if (PrimesFS.IsPrime(i)) count++;
            }

            return count;
        }

        private static bool IsPrime(int number)
        {
            for (int i = 2; i < number; i++)
            {
                if (number % i == 0) return false;
            }

            return true;
        }
    }
}
