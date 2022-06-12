package SolidOopVsFp.OpenClose.Fp

object OpenClose extends App {
  case class Check(id: Int, checkProcessor: CheckProcessor, Amount: Double)

  trait CheckProcessor {
    def ProcessCheck(check: Check): Unit
  }

  abstract class Bank(val name: String)

  case class BoABank() extends Bank("BoABank") with CheckProcessor {
    override def ProcessCheck(check: Check): Unit = {}
  }

  case class CityBank() extends Bank("CityBank") with CheckProcessor {
    override def ProcessCheck(check: Check): Unit = {}
  }

  val checks: List[Check] = List[Check](
    Check(1, BoABank(), 10),
    Check(2, CityBank(), 50)
  )

  checks.foreach(check => check.checkProcessor.ProcessCheck(check))
}
