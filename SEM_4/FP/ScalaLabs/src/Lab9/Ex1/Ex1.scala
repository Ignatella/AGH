package Lab9.Ex1

case class Value(v: Double) {
  override def toString: String = "%.4f".format(v)
}

object Sum {
  def apply(v1: Value, v2: Value): Value = Value(v1.v + v2.v)
}

object Subtract {
  def apply(v1: Value, v2: Value): Value = Value(v1.v - v2.v)
}

object Multiply {
  def apply(v1: Value, v2: Value): Value = Value(v1.v * v2.v)
}

object Divide {
  def apply(v1: Value, v2: Value): Value = Value(v1.v / v2.v)
}

object Ex1 extends App {
  val result = Divide(Subtract(Multiply(Sum(Value(1), Value(2)), Value(3)), Value(7)), Value(3))
  println(result)
}
