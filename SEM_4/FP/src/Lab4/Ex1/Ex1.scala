package Lab4.Ex1

object Ex1 extends App {
  def gen_seq(from: Int, to: Int): () => Int = {
    var curr = from

    def gen(): Int = {
      curr = curr + 1
      if (curr > to) to else curr - 1
    }

    gen
  }

  val g_1_4 = gen_seq(1, 4) // function g_1_4 generates integrates from 1 to 4  and then keeps returning 4 i.e. 1 2 3 4 4 4 4 4 4 ....
  val g_0_inf = gen_seq(0, Int.MaxValue)
  val g_7_10 = gen_seq(7, 10)

  for (_ <- 0 until 10) {
    println(g_1_4() + " " + g_0_inf() + " " + g_7_10())
  }
}
