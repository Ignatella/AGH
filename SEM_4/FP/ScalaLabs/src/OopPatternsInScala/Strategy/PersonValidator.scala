package OopPatternsInScala.Strategy

trait Validator {
  def Validate(person: Person): Boolean
}

case class FirstNameValidator() extends Validator {
  override def Validate(person: Person): Boolean = person match {
    case Person(firstName, middleName, lastName) =>
      firstName.isDefined && middleName.isDefined && lastName.isDefined
  }
}


case class FullNameValidator() extends Validator {
  override def Validate(person: Person): Boolean = person.firstName.isDefined
}


case class PersonCollector(validator: Validator) {
  var validPeople: Vector[Person] = Vector[Person]()

  def collect(person: Person): Vector[Person] = {
    if (validator.Validate(person)) validPeople = validPeople :+ person
    validPeople
  }
}


object PersonValidator extends App {
  val singleNameValidCollector = PersonCollector(FirstNameValidator())
  val fullNameValidCollector = PersonCollector(FullNameValidator())

  val p1 = Person(Some("John"), Some("Quincy"), Some("Adams"))
  val p2 = Person(Some("Mike"), None, Some("Linn"))
  val p3 = Person(None, None, None)


  singleNameValidCollector.collect(p1)
  singleNameValidCollector.collect(p2)
  singleNameValidCollector.collect(p3)

  println(singleNameValidCollector.validPeople)

  fullNameValidCollector.collect(p1)
  fullNameValidCollector.collect(p2)
  fullNameValidCollector.collect(p3)

  println(fullNameValidCollector.validPeople)
}
