package Lab7.Ex2

class A {
  override def toString: String = "A"
}

class B(val x: Int) extends A {
  override def toString: String = "B:" + x.toString
}

class C(x: Int) extends B(x) {
  override def toString: String = "C:" + x.toString
}


case class TwistedMonoPair[+T](a: T, b: T) {
  def apply(i: Int): String = if (i == 0) a.toString else b.toString

  def replace[B >: T](i: Int)(v: B): TwistedMonoPair[B] = {
    if (i == 0) TwistedMonoPair(v, b) else TwistedMonoPair(a, v)
  }
}


object Ex2 extends App {
  val a: TwistedMonoPair[A] = TwistedMonoPair[A](new B(7), new A)

  println(a(0))
  println(a(1))
  println(a)

  val b: TwistedMonoPair[A] = TwistedMonoPair[B](new B(9), new C(77)) // covariantness
  println(b)

  //  val c: TwistedMonoPair[A] = new TwistedMonoPair[B](new B(9), new A) // should not compile (due to  covariantness)

  val d1 = b.replace(0)(new A) // converts to TwistedMonoPair[A]
  println(d1)

  val tA: TwistedMonoPair[A] = d1

  //val tB : TwistedMonoPair[B] = d1// should be an error due to covariantness

  val d2 = b.replace(1)(new A) // replacing 2nd element
  println(d2)
}