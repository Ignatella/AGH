package SolidOopVsFp.InterfaceSegregation.Fp

object InterfaceSegregation extends App {
  trait Workable {
    def work(): Unit
  }

  trait Sleepable {
    def eat(): Unit
  }

  case class Manager() extends Workable with Sleepable {
    override def work(): Unit = {}

    override def eat(): Unit = {}
  }

  case class Robot() extends Workable {
    override def work(): Unit = {}
  }

  val workers = List[Workable](Manager(), Robot())
  workers.foreach { w => w.work() }
}
