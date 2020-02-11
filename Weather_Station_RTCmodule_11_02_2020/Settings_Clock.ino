void HTTP_SettingsClock(void){
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
  
out +=        "<script type=\"text/javascript\"> function digitalWatch() {var hours   = parseInt('" + String(hours) +"',10);";
out +=                                                                   "var minutes = parseInt('" + String(minutes) +"',10);";
out +=                                                                   "var seconds = parseInt('" + String(seconds) +"',10);";
out +=                                                                   "var watch = setInterval(function(){seconds = parseInt(seconds, 10); minutes = parseInt(minutes, 10); hours = parseInt(hours, 10);";
out +=                                                                                           "seconds++;";
out +=                                                                                           "if (seconds>59) { seconds = 0; minutes++;";
out +=                                                                                                              "if (minutes > 59) { minutes = 0; hours++;";
out +=                                                                                                                                  "if(hours > 23) hours = 0;}}";
out +=                                                                    "if (seconds < 10) {seconds = \"0\" + seconds;} ";
out +=                                                                    "if (minutes < 10) {minutes = \"0\" + minutes;} ";
out +=                                                                    "if (hours < 10)   {hours = \"0\" + hours;} ";

out +=                                                                   "document.getElementById(\"digitalWatch\").innerHTML = hours + \":\" + minutes + \":\" + seconds;}, 1000);";
out +=                                                                   "}";

out +=                                                 "function check() { ";
                                                                         if (WiFi.status() == WL_CONNECTED){
out +=                                                                   "var inp1 = document.getElementById('input1');";
out +=                                                                   "inp2 = document.getElementById('input2');";
out +=                                                                   "inp3 = document.getElementById('input3');";
out +=                                                                   "inp4 = document.getElementById('input4');";
out +=                                                                   "inp5 = document.getElementById('input5');";
out +=                                                                   "inp6 = document.getElementById('input6');";
out +=                                                                   "document.getElementById('save').disabled = inp1.value || inp2.value || inp3.value || inp4.value || inp5.value || inp6.value? false : \"disabled\";}";}
                                                                         if (WiFi.status() != WL_CONNECTED){
out +=                                                                   "var inp7 = document.getElementById('input7');";
out +=                                                                   "inp8 = document.getElementById('input8');";
out +=                                                                   "inp9 = document.getElementById('input9');";
out +=                                                                   "document.getElementById('save').disabled = inp7.value || inp8.value || inp9.value ? false : \"disabled\";}";}
out +=       "</script>";
out += "</head>";
  
out += "<body onload=\"digitalWatch()\">";
    
out +=     "<div>";
out +=         "<form id=\"dataClock\" action=\"/save\">";
out +=             "<fieldset>";
out +=                 "<legend><h1>Настройки часов</h1></legend>";
if (WiFi.status() == WL_CONNECTED){
  if (Config.SYNC_CLOCK == true) {
out +=                          "<h2><p>Cинхронизировать время с NTP сервером?<input id=\"input1\" onclick=\"check();\" class=\"tab_yesno\" name=\"sync_clock\" type=\"radio\" value=\"1\" checked>Да";
out +=                                                                       "<input id=\"input1\" onclick=\"check();\" class=\"tab_yesno\" name=\"sync_clock\" type=\"radio\" value=\"0\">Нет";
out +=                          "<p>Время метеостанции<lable id=\"digitalWatch\" class= \"clock_script\"></lable>";

out +=                           "<p>Часовой пояс GMT<input id=\"input2\" onkeyup=\"check();\" class=\"tab_gmt\" title=\"Часовой пояс GMT: -11..0..12\" type=\"text\" min = '-11' max = '12' name=\"timezone\" value=\"" + String(Config.GMT) + "\" >";

out +=                           "<p>Интервал синхронизации<input id=\"input3\" onkeyup=\"check();\" class=\"tab_sync\" title='от 1 часа до 1 недели (168 часов)' type='text' name=\"interval_sync\" min = '1' max = '168' value='" + String(Config.INTERVAL_SYNC) + "'> ч.";}

  else {
out +=                           "<h2><p>Cинхронизировать время с NTP сервером?<input id=\"input1\" onclick=\"check();\" class=\"tab_yesno\" name=\"sync_clock\" type=\"radio\" value=\"1\">Да";
out +=                                                                        "<input id=\"input1\" onclick=\"check();\" class=\"tab_yesno\" name=\"sync_clock\" type=\"radio\" value=\"0\" checked>Нет";
out +=                           "<p>Синхронизация отключена. Установите время вручную";
out +=                           "<p>Время метеостанции<lable id=\"digitalWatch\" class= \"clock_script\"></lable>";
out +=                           "<p><label>Часы</label>";
out +=                           "<input id=\"input4\" onkeyup=\"check();\" class=\"tab\" maxlength=\"2\" min=\"0\" max=\"23\" type=\"text\" name='hh' value='" + String(hours)   + "' >";

out +=                           "<label style='margin-left: 15px;'>Минуты</label>";
out +=                           "<input id=\"input5\" onkeyup=\"check();\" class=\"tab\" maxlength=\"2\" min=\"0\" max=\"59\" type=\"text\" name='mm' value='" + String(minutes) + "' >";

out +=                           "<label style='margin-left: 15px;'>Секунды</label>";
out +=                           "<input id=\"input6\" onkeyup=\"check();\" class=\"tab\" maxlength=\"2\" min=\"0\" max=\"59\" type=\"text\" name='ss' value='" + String(seconds) + "' ></h2>";}}
                    
if (WiFi.status() != WL_CONNECTED){
out +=                           "<h2>Нет подключения к сети. Установите время вручную <p>";
out +=                           "<p>Время метеостанции<lable id=\"digitalWatch\" class= \"clock_script\"></lable>";
out +=                           "<p><label>Часы</label>";
out +=                           "<input id=\"input7\" onkeyup=\"check();\" class=\"tab\" maxlength=\"2\" min=\"0\" max=\"23\" type=\"text\" name='hh' value='" + String(hours)   + "' >";

out +=                           "<label style='margin-left: 15px;'>Минуты</label>";
out +=                           "<input id=\"input8\" onkeyup=\"check();\" class=\"tab\" maxlength=\"2\" min=\"0\" max=\"59\" type=\"text\" name='mm' value='" + String(minutes) + "' >";

out +=                           "<label style='margin-left: 15px;'>Секунды</label>";
out +=                           "<input id=\"input9\" onkeyup=\"check();\" class=\"tab\" maxlength=\"2\" min=\"0\" max=\"59\" type=\"text\" name='ss' value='" + String(seconds) + "' ></h2>";}

out +=            "</fieldset><br>";
out +=        "</form>";
out += "<p><a href='/'><input class=\"knopki\" value=\"Главная\" type=\"submit\"></a>  <input id=\"save\" form=\"dataClock\" class=\"knopki\" type=\"submit\" value=\"Сохранить\" title=\"Сначала необходимо что-то изменить :)\" disabled=\"disabled\">";
out += "</div></body></html>";
   server.send ( 200, "text/html", out );
}
