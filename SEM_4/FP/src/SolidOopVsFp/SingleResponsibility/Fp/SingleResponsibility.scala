package SolidOopVsFp.SingleResponsibility.Fp

object SingleResponsibility extends App {

  def countPrimes(upTo: Int): Int = Seq.range(2, upTo).count(isPrime)

  def isPrime(number: Int): Boolean = !Seq.range(2, number).exists(v => number % v == 0)


  println(countPrimes(1))
  println(countPrimes(12))
}
