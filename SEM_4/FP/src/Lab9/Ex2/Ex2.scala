package Lab9.Ex2

trait Receptacle {
  val drinkName: String
  val volume: Double
  val unknown: Int
  val isAlcoholic: Boolean
}

case class Cup(drinkName: String, volume: Double, unknown: Int, isAlcoholic: Boolean) extends Receptacle

case class Glass(drinkName: String, volume: Double, unknown: Int, isAlcoholic: Boolean) extends Receptacle

case class Jug(drinkName: String, volume: Double, unknown: Int, isAlcoholic: Boolean) extends Receptacle

object Ex2 extends App {
  val drinks = List(
    Cup("Tea", 0.3, 5, isAlcoholic = false),
    Glass("Juice", 0.5, 10, isAlcoholic = false),
    Jug("Budweiser", 2.6, 19, isAlcoholic = true),
    Glass("Burgundy", 0.2, 12, isAlcoholic = true)
  )

  val volume = drinks.map(_.volume).sum
  val cocktails = drinks.filter(_.isAlcoholic).map(_.drinkName)
  val distinctDrinks = drinks.map(_.drinkName).distinct
  val partitionedDrinks = drinks.partition(_.isAlcoholic)

  println("Total volume: " + "%.3f".format(volume))
  println("Cocktails: " + cocktails)
  println("Distinct drinks: " + distinctDrinks)
  println("Partitioned drinks: " + partitionedDrinks)
}
