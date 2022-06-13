namespace InterfaceSegregation
{
    interface IWorkable
    {
        void Work() { }
    }

    interface ISleepable
    {
        void Sleep() { }
    }

    class Manager : IWorkable, ISleepable { }

    class Robot : IWorkable { }
}

