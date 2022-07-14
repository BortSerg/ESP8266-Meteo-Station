void HTTP_handleReboot (){
 
  
  String out = "";
  String ipadr = "";

  if (WiFi.status() != WL_CONNECTED) ipadr = WiFi.softAPIP().toString();
  if (WiFi.status() == WL_CONNECTED) ipadr = WiFi.localIP().toString();

out += "<!DOCTYPE html>";
out += "<html>";
out +=  "<head>";
out +=    "<meta http-equiv=\"Content-Type\" name=\"viewport\" content=\"text/html; charset=utf-8; width=device-width, initial-scale=1, user-scalable=no\" >";
out +=    "<title>Reboot</title>";

out +=       "<script type=\"text/javascript\"> ";
out +=                      "setTimeout('location.replace(\"http://" + ipadr + "\")', 10000);";        
out +=       "</script>";
out += "</head>";
out += "<body>";  
out +=     "<div>";
out +=            "Rebooting... Expect redirection!";
out += "</div></body></head></html>";
server.send ( 200, "text/html", out ); 
delay (3000);
  ESP.restart();
  
}
