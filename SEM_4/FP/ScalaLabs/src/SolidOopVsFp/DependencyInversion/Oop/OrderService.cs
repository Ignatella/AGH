namespace DependencyInversion
{
    class OrderService
    {
        private readonly IProcessor _processor;

        public OrderService(IProcessor processor)
        {
            _processor = processor;
        }

        public void ProcessOrder()
        {
            _processor.Process();
        }
    }
}
