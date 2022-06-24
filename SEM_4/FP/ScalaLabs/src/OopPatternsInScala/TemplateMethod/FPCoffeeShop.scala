package OopPatternsInScala.TemplateMethod

import OopPatternsInScala.TemplateMethod.FPCoffeeShop._

object FPCoffeeShop {
  case class Drink(name: String)

  def processDrinkOrder(
                         price: Double,
                         processPayment: Double => Boolean,
                         prepareDrink: () => Drink,
                         deliverDrink: Drink => Boolean): Boolean = {
    val paid = processPayment(price)
    if (!paid) false else {
      deliverDrink(prepareDrink())
    }
  }

  def processCashPayment(price: Double): Boolean = true

  def processCardPayment(price: Double): Boolean = true

  def prepareCoffee(): Drink = Drink("Coffee")

  def prepareTea(): Drink = Drink("Tea")

  def deliverToTable(drink: Drink): Boolean = true

  def deliverWithCourier(drink: Drink): Boolean = true
}

object WorkDay2 extends App {
  processDrinkOrder(16.9, processCardPayment, prepareCoffee, deliverToTable)
  processDrinkOrder(10.0, processCashPayment, prepareTea, deliverWithCourier)
}
