package Lab3.Ex2

object Ex2 extends App {
  def <[T](c: Int = 1)(str: T): Unit = 1 to c foreach (_ => println(str))

  def <[T](str: T): Unit = <()(str)

  def invokeAndAccumulate(init: Int, f: Int => Int, repeat: Int = 1): Int = {
    @scala.annotation.tailrec
    def loop(curr: Int, rep: Int): Int = rep match {
      case 0 => curr
      case rep => loop(f(curr), rep - 1)
    }

    loop(init, repeat)
  }

  def max(a: Int)(b: Int): Int = if (a > b) a else b;

  <("Hello world")
  <(3)("Hello world")

  println(invokeAndAccumulate(3, (x: Int) => 2 + x, 4))
  println(invokeAndAccumulate(2, (x: Int) => x * x))

  println(max(4)(5))
}