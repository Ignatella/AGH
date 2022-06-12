package Lab11.Ex2

import scala.io.Source

case class Recipe(title: String, body: String)

object Ex2 extends App {
  val fileContents = Source.fromFile("_")

  val content = fileContents.getLines.mkString("\n")

  fileContents.close()

  val reg = "[ ]{5,}(.+)\n\n".r

  val titles = reg.findAllIn(content).map(_.trim)
  val bodies = content.split(reg.toString()).map(_.trim).drop(1)


  var recipes: List[Recipe] = List()

  for ((t, i) <- titles.zipWithIndex) {
    recipes = recipes :+ Recipe(t, bodies(i))
  }
}
