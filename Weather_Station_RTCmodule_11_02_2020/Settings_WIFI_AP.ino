  void HTTP_Settings_WIFI_AP(void) {
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
  out +=      "input[type=checkbox] {transform: scale(1.5);}";
    
  out +=      "fieldset{text-align: left;}";
  out +=      "legend{text-align: center;}"; 
  out +=      ".knopki {font-size:16px;}";
  out +=      ".tab_ssid { margin-left:65px; height: 20px; width: 200px; }";
  out +=      ".tab_ssidpass {margin-left:20px; height: 20px; width: 200px; }";
  out +=      ".tab_ap {margin-left:27px; height: 20px; width: 200px; }";
  out +=      ".tab_appass {margin-left:20px; height: 20px; width: 200px;}";
  out +=      "body {padding:0; margin:0;}";
  
   out +=     "@media screen and (max-width:550px){div {text-align: center; margin-left: 0px; margin-right: 0px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:550px){div {text-align: center; margin-left: 0px; margin-right: 0px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:650px){div {text-align: center; margin-left: 100px; margin-right: 100px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:800px){div {text-align: center; margin-left: 200px; margin-right: 200px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:1024px){div {text-align: center; margin-left: 300px; margin-right: 300px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:1280px){div {text-align: center; margin-left: 400px; margin-right: 400px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:1440px){div {text-align: center; margin-left: 500px; margin-right: 500px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:1600px){div {text-align: center; margin-left: 600px; margin-right: 600px; margin-top:20px; margin-bottom:20px;}}";
   out +=     "@media screen and (min-width:1920px){div {text-align: center; margin-left: 700px; margin-right: 700px; margin-top:20px; margin-bottom:20px;}}";
 out += "</style>";

 out += "<script type=\"text/javascript\"> function check() {";
 out += "var inp1 = document.getElementById('input1');";
 out += "    inp2 = document.getElementById('input2');";
 out += "    inp3 = document.getElementById('input3');";
 out += "    inp4 = document.getElementById('input4');";
 out += "document.getElementById('save').disabled = inp1.value || inp2.value || inp3.value || inp4.value  ? false : \"disabled\";}";
 out +="</script>";

 out += "</head>";
  
out += "<body>";
out +=    "<div>";
  
  out += "<form id=\"data\" action=\"/save\" autocomplete=\"on\">";
  
  //подключение к wi-fi
  out += "<fieldset>";
  out += "<legend><h1> Настройки домашней сети Wi-Fi</h1></legend><h2>";
  out += "<label>SSID</label>";
  out += "<input id=\"input1\" onkeyup=\"check();\" class=\"tab_ssid\" type=\"text\" title='Имя домашней сети Wi-Fi' name='wifi_ssid' value='" + String(Config.WIFI_SSID) + "' >";
  out += "<p><label>Password</label>";
  out += "<input id=\"input2\" onkeyup=\"check();\" type=\"password\" class=\"tab_ssidpass\" title='Пароль от сети. Для открытого подключения оставить пустым' name='wifi_password' value='" + String(Config.WIFI_PASSWORD) + "'>";
  out += "</h2></fieldset><br>";
  
  //Настройка точки доступа
  out += "<fieldset>";
  out += "<legend><h1>Настройки точки доступа</h1></legend><h2>";
  out += "<p><label>SSID AP</label>";
  out += "<input id=\"input3\" onkeyup=\"check();\" required class=\"tab_ap\" type=\"text\" title='Имя точки доступа которую создаст метеостанция если нет подключения к роутеру' name='ap_ssid' value='" + String(Config.AP_SSID) + "' >";
  out += "<p><label>Password</label>";
  out += "<input id=\"input4\" onkeyup=\"check();\" class=\"tab_appass\" type=\"password\" title='Пароль от точки доступа. Для открытого подключения оставить пустым' name='ap_password' value='" + String(Config.AP_PASSWORD) + "'>";
  out += "</h2></fieldset><br>";

out += "</form>";

  
   out += "<p><a href='/'><input class=\"knopki\" value=\"Главная\" type=\"submit\"></a>  <input id=\"save\" form=\"data\" class=\"knopki\" type=\"submit\" value=\"Сохранить\" title=\"Сначала необходимо что-то изменить :)\" disabled=\"disabled\">";
  out += "</div></body></html>";
  server.send ( 200, "text/html", out );
  }
