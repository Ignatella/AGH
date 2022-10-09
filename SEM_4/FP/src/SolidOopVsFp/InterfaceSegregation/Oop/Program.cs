namespace InterfaceSegregation
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var workers = new List<IWorkable> { new Manager(), new Robot() };
            workers.ForEach(w => w.Work());
        }
    }
}