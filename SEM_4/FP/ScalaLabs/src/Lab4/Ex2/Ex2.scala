package Lab4.Ex2

object Ex2 extends App {
  def minmax[T](x: List[T], s: (T, T) => Boolean, g: (T, T) => Boolean): (Option[T], Option[T]) = {
    @scala.annotation.tailrec
    def loop(l: List[T], maxI: Int, i: Int, min: Option[T], max: Option[T]): (Option[T], Option[T]) = {
      if (i == maxI)
        (min, max)
      else
        loop(l, maxI, i + 1,
          if (min.isEmpty || s(l(i), min.get)) Option(l(i)) else min,
          if (max.isEmpty || g(l(i), max.get)) Option(l(i)) else max
        )
    }

    loop(x, x.length, 0, None, None)
  }

  val x = List(-3, 10, 90, 89, 12, 5, -5, 12, -16, 9908)
  val mm = minmax[Int](x, (a, b) => a < b, (a, b) => a > b)
  println("Min: " + mm._1.get + " Max: " + mm._2.get)
}