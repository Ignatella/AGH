using Microsoft.Extensions.DependencyInjection;

namespace DependencyInversion
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var serviceProvider = new ServiceCollection()
            //.AddSingleton<IProcessor, ActualProcessor>() We can register ActualProcessor or TestProcessor depending on our needs
            .AddSingleton<IProcessor, TestProcessor>()
            .AddScoped<OrderService>()
            .BuildServiceProvider();


            var orderService = serviceProvider.GetService<OrderService>();
            orderService?.ProcessOrder();
        }
    }
}