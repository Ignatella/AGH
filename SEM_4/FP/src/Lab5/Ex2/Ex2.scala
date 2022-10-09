package Lab5.Ex2

case class ExpensesList() {
  var l: List[Expense] = List[Expense]()

  def +=(e: Expense): Unit = l = l :+ e

  def printList(): Unit = l.foreach(e => println(e))

  def sum: Double = l.map(e => e.amount).sum

  def max: Double = l.map(e => e.amount).max
}

case class Expense(amount: Double, name: String, category: String)


object Ex2 extends App {
  val el = ExpensesList()

  el += Expense(5, "Bread", "food") // amount, item name, category
  el += Expense(7, "Butter", "food")
  el += Expense(3.2, "Tomatoes", "food")
  el += Expense(18, "Star Wars ticket", "entertainment")

  el.printList()

  println(el.sum)
  println(el.max)
}