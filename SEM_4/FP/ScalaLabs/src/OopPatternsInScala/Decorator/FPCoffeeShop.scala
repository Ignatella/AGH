package OopPatternsInScala.Decorator


object FPCoffeeShop extends App {
  case class Coffee(val name: String = "Coffee", val price: Double = 15) {
    override def toString: String = "Name: " + name + ", Price: " + price
  }

  def addSugar(coffee: Coffee): Coffee = {
    Coffee(coffee.name + " + sugar", coffee.price + 5)
  }

  def addMilk(coffee: Coffee): Coffee = {
    Coffee(coffee.name + " + milk", coffee.price + 7)
  }

  val coffee = Coffee()

  println(coffee)
  println(addSugar(coffee))
  println(addMilk(addSugar(coffee)))
}