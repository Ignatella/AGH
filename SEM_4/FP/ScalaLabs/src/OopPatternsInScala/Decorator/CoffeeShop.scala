package OopPatternsInScala.Decorator

object Extras extends Enumeration {
  type Extra = Value

  val Sugar, Milk = Value
}

trait Extra {
  def name(): String

  def price(): Double

  def addExtra(): Extra
}

case class BaseCoffee() extends Extra {
  override def name(): String = "Coffee"

  override def price(): Double = 15

  override def addExtra(): Extra = this
}

case class CoffeeWithSugar(override val extra: Extra) extends ExtraDecorator(extra) {
  override def name(): String = super.name() + " + sugar"

  override def price(): Double = super.price() + 5
}

case class CoffeeWithMilk(override val extra: Extra) extends ExtraDecorator(extra) {
  override def name(): String = super.name() + " + milk"

  override def price(): Double = super.price() + 7
}

case class Coffee() {
  var extra: Extra = BaseCoffee()

  def name(): String = extra.name()

  def price(): Double = extra.price()

  def addExtra(e: Extras.Extra): Unit = e match {
    case Extras.Sugar => extra = CoffeeWithSugar(extra)
    case Extras.Milk => extra = CoffeeWithMilk(extra)
  }

  override def toString: String = "Name: " + name + ", Price: " + price()
}

class ExtraDecorator(val extra: Extra) extends Extra {
  override def name(): String = extra.name()

  override def price(): Double = extra.price()

  override def addExtra(): Extra = this
}

object CoffeeShop extends App {
  val coffee = Coffee()

  println(coffee)

  coffee.addExtra(Extras.Sugar)

  println(coffee)

  coffee.addExtra(Extras.Milk)

  println(coffee)
}
