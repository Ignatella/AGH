package SolidOopVsFp.LiskovSubstitution.Fp

object LiskovSubstitution extends App {
  abstract class Organization()

  case class Bank() extends Organization

  case class School() extends Organization

  val organizations: List[Organization] = List[Organization](Bank(), School()) // List is covariant
}
