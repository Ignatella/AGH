namespace OpenClose
{
    class Check
    {
        public Guid Id { get; set; }

        public ICheckProcessor? CheckProcessor { get; set; }

        public double Amount { get; set; }
    }

    interface ICheckProcessor
    {
        public void ProcessCheck(Check check);
    }

    abstract class Bank
    {
        public string Name { get; set; }

        public Bank(string name)
        {
            Name = name;
        }
    }

    class BoABank : Bank, ICheckProcessor
    {
        public BoABank() : base("BoABank") { }

        public void ProcessCheck(Check check) { }
    }


    class CityBank : Bank, ICheckProcessor
    {
        public CityBank() : base("CityBank") { }

        public void ProcessCheck(Check check) { }
    }
}
