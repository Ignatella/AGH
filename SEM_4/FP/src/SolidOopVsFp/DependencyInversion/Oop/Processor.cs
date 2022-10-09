namespace DependencyInversion
{
    interface IProcessor
    {
        void Process();
    }

    abstract class Processor : IProcessor
    {
        public string Name { get; set; }

        public Processor(string name)
        {
            Name = name;
        }

        public void Process()
        {
            Console.WriteLine($"Processor - {Name}");
        }
    }

    class TestProcessor : Processor
    {
        public TestProcessor() : base("TestProcessor") { }
    }

    class ActualProcessor : Processor
    {
        public ActualProcessor() : base("ActualProcessor") { }
    }
}
