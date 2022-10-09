namespace OpenClose
{
    internal class Program
    {
        static void Main(string[] args)
        {
            IEnumerable<Check> checks = new List<Check>
            {
                new Check { Id = Guid.NewGuid(), CheckProcessor = new BoABank(), Amount = 10 },
                new Check { Id = Guid.NewGuid(), CheckProcessor = new CityBank(), Amount = 50 }
            };

            foreach (var check in checks)
            {
                check.CheckProcessor?.ProcessCheck(check);
            }
        }
    }
}