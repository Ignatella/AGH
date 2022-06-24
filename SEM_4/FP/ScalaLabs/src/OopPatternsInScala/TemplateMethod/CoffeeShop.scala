package OopPatternsInScala.TemplateMethod

import OopPatternsInScala.TemplateMethod.CoffeeShop._

object CoffeeShop {
  case class Drink(name: String)

  abstract class DrinkOrder() {
    val price: Double

    final def processDrinkOrder(): Boolean = {
      val paid = processPayment(price)
      if (!paid) false else {
        deliverDrink(prepareDrink())
      }
    }

    protected def processPayment(price: Double): Boolean

    protected def prepareDrink(): Drink

    protected def deliverDrink(drink: Drink): Boolean
  }

  case class CoffeeToTable(override val price: Double) extends DrinkOrder {
    protected override def processPayment(price: Double): Boolean = true

    protected override def prepareDrink(): Drink = Drink("Coffee")

    protected override def deliverDrink(drink: Drink): Boolean = true
  }

  case class TeaWithCourier(override val price: Double) extends DrinkOrder {
    protected override def processPayment(price: Double): Boolean = true

    protected override def prepareDrink(): Drink = Drink("Tea")

    protected override def deliverDrink(drink: Drink): Boolean = true
  }
}

object WorkDay1 extends App {
  CoffeeToTable(16.9).processDrinkOrder()
  TeaWithCourier(10.0).processDrinkOrder()
}
