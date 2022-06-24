package OopPatternsInScala.Strategy

object FPPersonValidator extends App {
  def isFirstNameValid(person: Person): Boolean = person.firstName.isDefined

  def isFullNameValid(person: Person): Boolean = person match {
    case Person(firstName, middleName, lastName) =>
      firstName.isDefined && middleName.isDefined && lastName.isDefined
  }

  def personCollector(isValid: (Person) => Boolean): Person => Vector[Person] = {
    var validPeople = Vector[Person]()
    (person: Person) => {
      if (isValid(person)) validPeople = validPeople :+ person
      validPeople
    }
  }

  val singleNameValidCollector = personCollector(isFirstNameValid)
  val fullNameValidCollector = personCollector(isFullNameValid)

  val p1 = Person(Some("John"), Some("Quincy"), Some("Adams"))
  val p2 = Person(Some("Mike"), None, Some("Linn"))
  val p3 = Person(None, None, None)

  singleNameValidCollector(p1)
  singleNameValidCollector(p2)
  println(singleNameValidCollector(p3))

  fullNameValidCollector(p1)
  fullNameValidCollector(p2)
  println(fullNameValidCollector(p3))

  //  Output
  //  Vector(Person(Some(John),Some(Quincy),Some(Adams)), Person(Some(Mike),None,Some(Linn)))
  //  Vector(Person(Some(John),Some(Quincy),Some(Adams)))
}
