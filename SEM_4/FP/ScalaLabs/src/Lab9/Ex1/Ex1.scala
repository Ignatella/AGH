package Lab9.Ex1

abstract class Action

case class Value(v: Double) extends Action {
  override def toString: String = "%.4f".format(v)
}

case class Sum(v1: Action, v2: Action) extends Action

case class Subtract(v1: Action, v2: Action) extends Action

case class Multiply(v1: Action, v2: Action) extends Action

case class Divide(v1: Action, v2: Action) extends Action

object Evaluate {
  def apply(act: Action): Value = act match {
    case Value(v) => Value(v)
    case Sum(v1, v2) => Value(Evaluate(v1).v + Evaluate(v2).v)
    case Subtract(v1, v2) => Value(Evaluate(v1).v - Evaluate(v2).v)
    case Multiply(v1, v2) => Value(Evaluate(v1).v * Evaluate(v2).v)
    case Divide(v1, v2) => Value(Evaluate(v1).v / Evaluate(v2).v)
  }
}


object Ex1 extends App {
  val result = Divide(Subtract(Multiply(Sum(Value(1), Value(2)), Value(3)), Value(7)), Value(3))
  println(Evaluate(result))
}
