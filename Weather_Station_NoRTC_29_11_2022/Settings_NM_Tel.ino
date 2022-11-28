void HTTP_Settings_NM_Tel (void) {
  String out = "";
  
 out += "<!DOCTYPE html>";
 out += "<html>";
 out += "<head>";
 out += "<meta http-equiv=\"Content-Type\" name=\"viewport\" content=\"text/html; charset=utf-8; width=device-width, initial-scale=1, user-scalable=no\" >";
 out += "<title>Settings</title>";
 out += "<style type=\"text/css\">";
 out +=        "html {padding:0; margin:0;"; 
 out +=        "height: 100%;";
 out +=        "ckground: #2c3e50; /* fallback for old browsers */";
 out +=        "background: -webkit-linear-gradient(to left, #2c3e50, #4ca1af); /* Chrome 10-25, Safari 5.1-6 */";
 out +=        "background: linear-gradient(to left, #2c3e50, #4ca1af); /* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ */}";
  
  out +=      "h1{font-style:italic; font-weight:bold; text-align:center; color:white;}";
  out +=      "h2{color:white;}";
      
  out +=       "fieldset{text-align: left;}";
  out +=       "legend{text-align: center;}"; 
  out +=       ".knopki {font-size:16px;}";
  out +=       ".tab_token {height: 20px; width: 350px; margin-left:20px; }";
  out +=       ".tab_yesno {margin-left:20px;}";
  out +=       ".time_interval {margin-left:10px; height: 20px; width: 30px;}";
  out +=       ".tab_chat {height: 20px; width: 70px; margin-left:50px;}";
  out +=       "body {padding:0; margin:0;}";
  
   out +=     "@media screen and (max-width:550px){div {text-align: center; margin-left: 0px; margin-right: 0px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:550px){div {text-align: center; margin-left: 0px; margin-right: 0px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:650px){div {text-align: center; margin-left: 50px; margin-right: 50px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:800px){div {text-align: center; margin-left: 100px; margin-right: 100px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:1024px){div {text-align: center; margin-left: 200px; margin-right: 200px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:1280px){div {text-align: center; margin-left: 280px; margin-right: 280px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:1440px){div {text-align: center; margin-left: 320px; margin-right: 320px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:1600px){div {text-align: center; margin-left: 400px; margin-right: 400px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:1920px){div {text-align: center; margin-left: 600px; margin-right: 600px; margin-top:20px; margin-bottom:20px;}}";
 out += "</style>";
 
 out += "<script type=\"text/javascript\"> function check() {";
 out += "var inp1 = document.getElementById('input1');";
 out += "    inp2 = document.getElementById('input2');";
 out += "    inp3 = document.getElementById('input3');";
 out += "    inp4 = document.getElementById('input4');";
 out += "    inp5 = document.getElementById('input5');";
 out += "    inp6 = document.getElementById('input6');";
 out += "document.getElementById('save').disabled = inp1.value || inp2.value || inp3.value || inp4.value || inp5.value || inp6.value ? false : \"disabled\";}";
 out +="</script>";
 
 out += "</head>";
  
out += "<body>";
out +=    "<div>";
  out += "<form id=\"dataNMTEL\" action=\"/save\">";
  //Narodmon
  out += "<fieldset>";
  out += "<legend><h1>Отправка данных на Narodmon.ru</h1></legend><h2>";
        if (WiFi.status() == WL_CONNECTED){
        if (Config.SEND_NM == true) {
              out += "Отправлять данные? <input id=\"input1\" onclick=\"check();\" class=\"tab_yesno\" type=\"radio\" name=\"send_NM\" value=\"1\" checked>Да<input id=\"input1\" onclick=\"check();\" class=\"tab_yesno\" type=\"radio\" name=\"send_NM\" value=\"0\">Нет<p>" ;}
              
        if (Config.SEND_NM == false){
              out += "Отправлять данные? <input id=\"input1\" onclick=\"check();\" class=\"tab_yesno\" type=\"radio\" name=\"send_NM\" value=\"1\">Да<input id=\"input1\" onclick=\"check();\" class=\"tab_yesno\" type=\"radio\" name=\"send_NM\" value=\"0\" checked>Нет<p>" ;}
              
              out += "<label>Интервал отправки данных</label>";
              out += "<input id=\"input2\" onkeyup=\"check();\" class=\"time_interval\" min=\"5\" max=\"60\" title=\"Индервал отправки данных 5-60 минут\" type=\"text\" min = \"5\" max = \"60\" name=\"interval_NM\" value='" + String(Config.INTERVAL_NM) + "'> мин.";  }
        if (WiFi.status() != WL_CONNECTED){
              out += "Нет подключения к сети <br> Отправка данных на Narodmon.ru невозможна <p>";}
  
  out += "</h2></fieldset><br>";

  //Отправка данных на Telegram
  /*
  out += "<fieldset>";
  out += "<legend><h1>Отправка данных в Telegram</h1></legend><h2>";
        if (WiFi.status() == WL_CONNECTED){
        if (Config.SEND_TL == true) {
              out += "<p>Отправлять данные?<input id=\"input3\" onclick=\"check();\" class=\"tab_yesno\" name=\"send_TL\" type=\"radio\" value=\"1\" checked>Да<input id=\"input3\" onclick=\"check();\" class=\"tab_yesno\"  name=\"send_TL\" type=\"radio\" value=\"0\">Нет</p>" ;}
        if (Config.SEND_TL == false){
              out += "<p>Отправлять данные?<input id=\"input3\" onclick=\"check();\" class=\"tab_yesno\" name=\"send_TL\" type=\"radio\" value=\"1\">Да<input id=\"input3\" onclick=\"check();\" class=\"tab_yesno\"  name=\"send_TL\" type=\"radio\" value=\"0\" checked>Нет</p>" ;}
  
  out += "<label>Интервал отправки данных</label>";
  out += "<input id=\"input4\" onkeyup=\"check();\" class=\"time_interval\" title=\"Индервал отправки данных 5-60 минут\" type=\"text\" min = \"5\" max = \"60\" name=\"interval_TL\" value='" + String(Config.INTERVAL_TL) + "'> мин.";        
  out += "<p><label>Chat ID</label>";
  
  out += "<input id=\"input5\" onkeyup=\"check();\" class=\"tab_chat\"  maxlength=\"10\"title=\"Уникальный ID чата с вашим ботом\" name=\"chat_id\" value='" + String(Config.CHAT_ID) + "' >";
  out += "<p><label>API Token</label>";
  out += "<input id=\"input6\" onkeyup=\"check();\" class=\"tab_token\" maxlength=\"50\"  title=\"API Token имеет вид: 123456789:AABcddfhgSdffgcvLJJnbkjjhJGTYTFETdS\" name=\"token\" value='" + String(Config.TOKEN) + "'>";}

  if (WiFi.status() != WL_CONNECTED){
            out += "Нет подключения к сети <br> Отправка данных в Telegram невозможна <p>";}
  
  out += "</h2></fieldset><br>"; */
  out += "</form>";
 
  if (WiFi.status() == WL_CONNECTED){
            out += "<p><a href='/'><input class=\"knopki\" value=\"Главная\" type=\"submit\"></a>  <input id=\"save\" form=\"dataNMTEL\" class=\"knopki\" type=\"submit\" value=\"Сохранить\" title=\"Сначала необходимо что-то изменить :)\" disabled=\"disabled\">";}
  if (WiFi.status() != WL_CONNECTED){
            out += "<p><a href='/'><input class=\"knopki\" value=\"Главная\" type=\"submit\"></a>";}
  
  out += "</div></body></html>";
  server.send ( 200, "text/html", out );
  }
