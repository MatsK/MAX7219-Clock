//
//  HTML PAGE
//

const char PAGE_AdminGeneralSettings[] PROGMEM =  R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Basic settings</strong>
<hr>

<form action="" method="post">
<table border="0"  cellspacing="0" cellpadding="3" >
<tr>
	<td align="right">API key</td>
	<td><input id="devicename" name="devicename" size="32" value=""></td>
</tr>

<tr>
  <td align="right">City ID</td>
  <td><input type="text" id="cityid" name="cityid" value=""></td>
</tr>

<tr><td colspan="2" align="center"><input type="submit" style="width:150px" class="btn btn--m btn--blue" value="Save"></td></tr>
</table>
</form>
<a href="http://openweathermap.org/api" align="center" target="_blank">Get the API key here</a><br><br>
<a href="http://bulk.openweathermap.org/sample/" align="center" target="_blank">Here we find the City ID of our city</a><br>
<br>
<td align="center">Developer: Marcel Akhkamov</td><br>
<td align="center">  danubanan@gmail.com</td><br>
<td align="center">  musa.pro@yandex.ru</td><br>
<a href="http://vk.com/danubanan" align="center" target="_blank">vk.com/danubanan</a><br>
<script>

window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{
				setValues("/admin/generalvalues");
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}

</script>
)=====";


// Functions for this Page
void send_devicename_value_html()
{
	String values ="";
	values += "devicename|" + (String) config.DeviceName + "|div\n";
	server.send ( 200, "text/plain", values);
	Serial.println(__FUNCTION__); 
}

void send_general_html()
{
	if (server.args() > 0 )  // Save Settings
	{	
		String temp = "";
		for ( uint8_t i = 0; i < server.args(); i++ ) {
			if (server.argName(i) == "devicename") config.DeviceName = urldecode(server.arg(i)); 
      if (server.argName(i) == "cityid") config.cityid = urldecode(server.arg(i));
		}

		WriteConfig();
		firstStart = true;
	}
	server.send_P ( 200, "text/html", PAGE_AdminGeneralSettings ); 
	Serial.println(__FUNCTION__); 
}

void send_general_configuration_values_html()
{
	String values ="";
	values += "devicename|" +  (String)  config.DeviceName +  "|input\n";
        values += "cityid|" +  (String)  config.cityid +  "|input\n";
 
	server.send ( 200, "text/plain", values);
	Serial.println(__FUNCTION__); 
  AdminTimeOutCounter=0;
}
