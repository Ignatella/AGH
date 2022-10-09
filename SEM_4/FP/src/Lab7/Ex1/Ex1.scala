package Lab7.Ex1

import java.util.Calendar

abstract class Printable {
  def pprint(text: String): Unit
}

trait TimeStamp extends Printable {
  override abstract def pprint(text: String): Unit = {
    print(Calendar.getInstance().getTime + " ")
    super.pprint(text)
  }
}

trait Quote extends Printable {
  override abstract def pprint(text: String): Unit = super.pprint("\"" + text + "\"")
}

class Logger() extends Printable {
  override def pprint(text: String): Unit = println(text)
}

object Ex1 extends App {
  val logger = new Logger with Quote with TimeStamp
  logger.pprint("Hello there")
}