package Lab8.Ex1

case class Memo[K, V](func: K => V) {
  private var args = Map.empty[K, V]

  def apply(arg: K): V = {
    if (!args.contains(arg)) {
      args += (arg -> func(arg))
    }

    args(arg)
  }
}

object Ex1 extends App {
  def len(s: String) = {
    println("Calculating len of:" + s);
    s.length
  }

  len("Hello")
  len("There")

  val mlen = Memo(len)

  mlen("a") // call
  mlen("a") // no call
  mlen("xyz") // do call
  mlen("some") // do the call
  mlen("some") // no call
  mlen("some") // no call

  def repr(x: Int) = {
    println("string repr of " + x.toString);
    x.toString
  }

  val mrepr = Memo(repr)

  mrepr(6)
  mrepr(56)
  mrepr(6) // should not happen
}
