package Lab10.Ex1

case class Person(name: String, surname: String, age: Int, sex: String)

object Ex1 extends App {
  val people = List(
    Person("John", "Doe", 23, "male"),
    Person("Joan", "Doe", 23, "female"),
    Person("Steve", "Jenkins", 24, "male"),
    Person("Eva", "Robinson", 25, "female"),
    Person("Ben", "Who", 22, "male"),
    Person("Janet", "Reed", 21, "female"),
    Person("Rob", "Jenkins", 26, "male"),
    Person("Ella", "Dawson", 27, "female")
  )

  // 1. Print all people name + family name, with M/F before each
  people.foreach(p => println((if (p.sex == "male") "M" else "F") + " " + p.name + " " + p.surname))

  println()

  // 2. Count, simultaneously all males & females
  people.groupBy(_.sex).map(g => (g._1, g._2.size)).foreach(println)

  println()

  // 3. Obtain average age
  println(people.foldLeft((0.0, 0))((m, p) => ((m._1 * m._2 + p.age) / (m._2 + 1), m._2 + 1))._1)

  println()

  // 4. Obtain average age for males and females
  people
    .groupBy(_.sex)
    .map(g => (g._1, g._2.foldLeft(0.0, 0)((m, p) => ((m._1 * m._2 + p.age) / (m._2 + 1), m._2 + 1))))
    .foreach(g => println(g._1 + ": " + g._2._1))
}
