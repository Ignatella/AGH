package Lab3.Ex1

import math._

object Ex1 extends App {
  def f(x: Double): Double = 1 + x * x

  val N = 1000000;
  var in = (0 to N).map(_ => (random, random * 10)).count(xy => xy._2 <= f(xy._1));

  println(in.toDouble / N.toDouble * 10)

  in = (0 to N).map(_ => (random, random)).count(f => f._1 * f._1 + f._2 * f._2 <= 1)
  println(in.toDouble / N.toDouble * 4)
}
