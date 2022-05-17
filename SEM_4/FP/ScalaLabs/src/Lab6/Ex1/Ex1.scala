package Lab6.Ex1

import scala.math._

case class MapPoint(name: String, latitude: Double, longitude: Double) {
  def -(another: MapPoint): Double = sqrt(pow(another.latitude - latitude, 2) + pow(another.longitude - longitude, 2))

  def distanceTo(another: MapPoint): Double = this - another

  def move(deltaLatitude: Double, deltaLongitude: Double): MapPoint =
    this.copy(latitude = latitude + deltaLatitude, longitude = longitude + deltaLongitude)
}

class Route {
  private var stops = List[MapPoint]()

  def this(stops: MapPoint*) = {
    this()
    this.stops = stops.toList
  }

  def addStop(point: MapPoint): Unit = stops = stops :+ point

  override def toString: String = "Lab8.Ex1.Route(" + stops.map(p => p.toString).mkString(", ") + ")"
}

object Route {
  def apply(stops: MapPoint*): Route = new Route(stops: _*)
}

object Ex1 extends App {
  val krk = MapPoint("Krakow", 50.061389, 19.938333);
  println(krk);

  val nyc = MapPoint("NYC", 40.7127, -74.0059);
  println(nyc);

  val porto = MapPoint("Porto", 41.162142, -8.621953);
  val irkutsk = MapPoint("Irkutsk", 52.283333, 104.283333);
  println(irkutsk);

  println(porto - irkutsk)
  println(krk - irkutsk)
  println(krk.distanceTo(porto))

  val r = Route(krk, nyc, porto)
  println(r);

  r.addStop(porto.move(1, 1))
  r.addStop(irkutsk)

  println(r) // 5 stops trip should be printed here
}
