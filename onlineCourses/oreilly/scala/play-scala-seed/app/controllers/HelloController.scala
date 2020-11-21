package controllers

import play.api.mvc._
import javax.inject._

class HelloController @Inject()(val controllerComponents: ControllerComponents) extends BaseController{
  def index() = Action { implicit request: Request[AnyContent] =>
    Ok(views.html.hello(null))
  }

  def wishByName(name: String) = Action { implicit request: Request[AnyContent] =>
    Ok(views.html.hello(name))
  }

  def addUser() = Action { implicit request: Request[AnyContent] =>
    val body = request.body;

    body.asFormUrlEncoded match{
      case Some(map) =>
        //persist user information
        Ok(s"The user of name `${map("name").head}` and age `${map("age").head}` has been created\n")
      case None => BadRequest("Unknow body format")
    }

    //    Content-type                                     Method Name
    //
    //    application/x-www-form-urlencoded                request.body.asFormUrlEncoded
    //
    //    text/plain                                       request.body.asText
    //
    //    application/xml                                  request.body.asXML
    //
    //    application/json                                 request.body.asJson

  }
}
