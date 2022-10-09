package Lab8.Ex2

case class DiWord(elems: String*) {
  override def toString: String = "DiWord(" + elems.mkString(", ") + ")"
}

case class Person(name: String, surname: String, age: Int)

object Person {
  def unapply(m: Map[String, String]): Option[Person] = {
    val keyDiff = Set("name", "surname", "age") -- m.keySet

    if (keyDiff.toList.isEmpty) {
      m("age").toIntOption match {
        case Some(x) => return Some(Person(m("name"), m("surname"), x))
      }
    }

    None
  }
}

case class Company(name: String, origin: String)

object Company {
  def unapply(m: Map[String, String]): Option[Company] = {
    val keyDiff = Set("company", "origin") -- m.keySet

    if (keyDiff.toList.isEmpty) {
      return Some(Company(m("company"), m("origin")))
    }

    None
  }
}


object Ex2 extends App {
  def extr(data: List[AnyRef]): List[AnyRef] = {
    data.map {
      case t: Map[String, String] => t match {
        case Person(x) => x
        case Company(x) => x
        case _ => None
      }
      case t: List[String] => DiWord(t: _*)
      case _ => None
    }
  }

  def onlyPeople(p: List[AnyRef]): List[Person] = {
    p.collect { case v: Person => v }
  }

  def onlyComp(p: List[AnyRef]): List[Company] = {
    p.collect { case v: Company => v }
  }

  def onlyPeopleOrComp(p: List[AnyRef]): List[AnyRef] = {
    p.collect { case v@(_: Company | _: Person) => v }
  }

  val data = List(Map("name" -> "John", "surname" -> "Smith", "age" -> "45"),
    Map("company" -> "ABB", "origin" -> "Sweden"),
    Map("name" -> "Kate", "surname" -> "Newsmith", "age" -> "45"),
    Map("company" -> "F4", "origin" -> "Poland"),
    List("Something", "else"),
    Map("company" -> "Saline Genoveva", "origin" -> "Italy"),
    Map("company" -> "AGH", "origin" -> "Poland"),
    Map("name" -> "Christopher", "surname" -> "Blacksmith", "age" -> "14")
  )

  val p = extr(data)
  println(p)

  println(onlyPeople(p))
  println(onlyComp(p))
  println(onlyPeopleOrComp(p))
}