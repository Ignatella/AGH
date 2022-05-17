package Lab6.Ex2

import scala.math._

abstract class Len {
  def len: Double
}

case class Point(x: Double, y: Double, z: Double) extends Len {
  override def len: Double = hypot(hypot(x, y), z)
}

trait Dist extends Len with Ordered[Dist] {
  override def compare(that: Dist): Int = if (len == that.len) 0 else if (len > that.len) 1 else -1
}

class OrderedPoint(x: Double, y: Double, z: Double) extends Point(x, y, z) with Dist with Ordered[Dist]


object Ex2 extends App {
  val oPointA = new OrderedPoint(9, 0, 2)
  val oPointB = new OrderedPoint(3, 2, 4)

  print("A > B", oPointA > oPointB)
  print("A < B", oPointA < oPointB)
  print("A < A", oPointA < oPointA)
  print("A == A", oPointA == oPointA)
  print("A != A", oPointA != oPointA)
  print("A == B", oPointA < oPointB)

  println()

  // region should not be possible
  //     val pointA = new Point(9, 0, 2)
  //     val pointB = new Point(3, 2, 4)
  //     print("A<B", pointA < pointB)

  // neither this, i.e. the comparison functionality should only come with Dist trait
  // class OrderedPointS (x: Double, y: Double, z: Double) extends Point(x,y,z) with Ordered[Dist] {
  //     override def d : Double = math.hypot(math.hypot(x,y), z) // IMPORTANT HINT HERE
  // }
  //endregion
}

