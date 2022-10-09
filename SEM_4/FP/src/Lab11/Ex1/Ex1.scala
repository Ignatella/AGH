package Lab11.Ex1

object MaybeMonad {
  class Maybe[T](v: T, ok: Boolean) {

    def flatMap(f: T => Maybe[T]): Maybe[T] = if (ok) f(v) else Maybe(v, ok)

    override def toString: String = if (ok) v.toString else "FAILED"
  }

  object Maybe {
    def apply[T](v: T, ok: Boolean = true): Maybe[T] = new Maybe(v, ok)
  }
}

object Ex1 extends App {

  import MaybeMonad._

  val FAILED = false

  def fail(arg: Double): Maybe[Double] = Maybe(arg, FAILED)

  val a = Maybe(9.0)

  val unsuccessful = a
    .flatMap { v =>
      println("multiplying")
      Maybe(v * 2)
    }
    .flatMap(fail)
    .flatMap { v =>
      println("multiplying again")
      Maybe(v * 2)
    }

  val successful = a.flatMap { x => Maybe(x * 2) }.flatMap { x => Maybe(x * 2) }

  println(unsuccessful)
  println()
  println(successful)
}
