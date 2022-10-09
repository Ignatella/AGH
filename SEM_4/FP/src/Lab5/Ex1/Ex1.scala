package Lab5.Ex1

import scala.annotation.tailrec

object Ex1 extends App {
  val lA = List(1, 2, 3, 4)
  val lB = List(10, 9, 8, 7)
  val lC = List(-1, -2, 1) // has only 3 elements
  val lD = List(100, 90, 80, 70, 60, 50) // has more elements

  val output = merge(List(lA, lB, lC, lD))

  println(output.mkString(", "))

  def merge(value: List[List[Int]]): List[Int] = {
    @tailrec
    def loop(v: List[List[Int]], i: Int = 0, result: List[Int] = List[Int]()): List[Int] = {
      var a = List[Int]()
      v.foreach(l => if (i < l.length) a = a :+ l(i))

      println(i)

      if (a.length != v.length)
        return result

      loop(v, i + 1, result ::: a)
    }

    loop(value)
  }
}
