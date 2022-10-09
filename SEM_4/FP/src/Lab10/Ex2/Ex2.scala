package Lab10.Ex2


object Ex2 extends App {
  def pow(x: Int) = {
    print("pow:" + x)
    x * x
  }

  def d2(x: Int) = {
    print("d2:" + x)
    x * 2
  }

  def powT(x: Int) = ("pow:" + x.toString, x * x)

  def d2T(x: Int) = ("d2:" + x.toString, x * 2)

  def composeII(f1: Int => Int, f2: Int => Int): Int => Int = {
    def f(arg: Int): Int = {
      var v = f2(arg)
      print(" -> ")
      v = f1(v)
      v
    }

    f
  }

  def composeTT(f1: Int => (String, Int), f2: Int => (String, Int)): Int => (String, Int) = {
    def f(arg: Int): (String, Int) = {
      var str = ""
      var v = f2(arg)
      str += v._1 + " -> "
      v = f1(v._2)
      str += v._1

      (str, v._2)
    }

    f
  }


  val cII = composeII(pow, d2)
  val rII = cII(3)
  println(", " + rII)

  println()

  val cTT = composeTT(powT, d2T)
  var rTT = cTT(3)
  println(rTT._1 + ", " + rTT._2)

  println()

  val d = composeTT(powT, cTT)
  rTT = d(5)
  println(rTT._1 + ", " + rTT._2)
}
