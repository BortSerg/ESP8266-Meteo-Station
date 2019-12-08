void HTTP_SettingsLight(void){
String out = "";

out += "<!DOCTYPE html>";
out += "<html>";
out +=  "<head>";
out +=    "<meta http-equiv=\"Content-Type\" name=\"viewport\" content=\"text/html; charset=utf-8; width=device-width, initial-scale=1, user-scalable=no\" >";
out +=    "<title>Settings</title>";
out +=    "<style type=\"text/css\">";
out +=          "html {padding:0; margin:0;"; 
out +=                   "height: 100%;";
out +=                   "ckground: #2c3e50; /* fallback for old browsers */";
out +=                   "background: -webkit-linear-gradient(to left, #2c3e50, #4ca1af); /* Chrome 10-25, Safari 5.1-6 */";
out +=                   "background: linear-gradient(to left, #2c3e50, #4ca1af); /* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ */}";

out +=         "h1{font-style:italic; font-weight:bold; text-align:center; color:white;}";
out +=         "h2{color:white;}";
out +=         "fieldset{text-align: left;}";
out +=         "legend { text-align: center; }";
out +=         "body {padding:0; margin:0;}";
out +=         ".tab { margin-left: 10px; height: 20px; width: 30px;}";
out +=         ".tab_gmt { margin-left: 10px; height: 20px; width: 35px;}";
out +=         ".tab_sync{margin-left: 10px; height: 20px; width: 40px;}";
out +=         ".tab_yesno {margin-left:20px;}";
out +=         ".knopki {font-size:16px;} ";
out +=         ".clock_script {margin-left: 15px; color: white; font-size: 120%; font-weight: bold; font-style:italic;} ";

out +=          "@media screen and (max-width:550px){div {text-align: center; margin-left: 0px; margin-right: 0px; margin-top:20px; margin-bottom:20px;}}";
out +=          "@media screen and (min-width:550px){div {text-align: center; margin-left: 0px; margin-right: 0px; margin-top:20px; margin-bottom:20px;}}";
out +=          "@media screen and (min-width:650px){div {text-align: center; margin-left: 50px; margin-right: 50px; margin-top:20px; margin-bottom:20px;}}";
out +=          "@media screen and (min-width:800px){div {text-align: center; margin-left: 100px; margin-right: 100px; margin-top:20px; margin-bottom:20px;}}";
out +=          "@media screen and (min-width:1024px){div {text-align: center; margin-left: 200px; margin-right: 200px; margin-top:20px; margin-bottom:20px;}}";
out +=          "@media screen and (min-width:1280px){div {text-align: center; margin-left: 280px; margin-right: 280px; margin-top:20px; margin-bottom:20px;}}";
out +=          "@media screen and (min-width:1440px){div {text-align: center; margin-left: 320px; margin-right: 320px; margin-top:20px; margin-bottom:20px;}}";
out +=          "@media screen and (min-width:1600px){div {text-align: center; margin-left: 400px; margin-right: 400px; margin-top:20px; margin-bottom:20px;}}";
out +=          "@media screen and (min-width:1920px){div {text-align: center; margin-left: 480px; margin-right: 480px; margin-top:20px; margin-bottom:20px;}}";
out +=    "</style>";   

out +=      "<script type=\"text/javascript\">";
out +=                                                                   "function check() { var inp1 = document.getElementById('input1');";
out +=                                                                   "document.getElementById('save').disabled = inp1.value ? false : \"disabled\";}";
out +=       "</script>";
out += "</head>";


out += "<body>";
    
out +=     "<div>";
out +=         "<form id=\"dataLight\" action=\"/save\">";
out +=             "<fieldset>";
out +=                 "<legend><h1>Настройки яркости свечения индикатора</h1></legend>";
out +=                          "<h2><p>Яркость<select id=\"input1\" onclick=\"check();\" class=\"tab_yesno\" name=\"light\" >";
                      if (Config.LIGHT == 0)
                              {
out +=                          "<option selected value=\"0\">Тусклый</option>";
out +=                          "<option value=\"2\">Средний</option>";
out +=                          "<option value=\"7\">Яркий</option>";
                              }
                      
                      if (Config.LIGHT == 2)
                              {
out +=                          "<option value=\"0\">Тусклый</option>";
out +=                          "<option selected value=\"2\">Средний</option>";
out +=                          "<option value=\"7\">Яркий</option>";
                              }
                      if (Config.LIGHT == 7)
                              {
out +=                          "<option value=\"0\">Тусклый</option>";
out +=                          "<option value=\"2\">Средний</option>";
out +=                          "<option selected value=\"7\">Яркий</option>";
                              }
out +=                          "</select></p>";
out +=            "</fieldset><br>";
out +=        "</form>";
out += "<p><a href='/'><input class=\"knopki\" value=\"Главная\" type=\"submit\"></a>  <input id=\"save\" form=\"dataLight\" class=\"knopki\" type=\"submit\" value=\"Сохранить\" title=\"Сначала необходимо что-то изменить :)\" disabled=\"disabled\">";
out += "</div></html>";
   server.send ( 200, "text/html", out );

}
