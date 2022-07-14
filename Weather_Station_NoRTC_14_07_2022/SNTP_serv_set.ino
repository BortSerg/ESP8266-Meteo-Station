void SNTP_server_set(){
  sntp_stop();
  sntp_setservername(0,"ntp.time.in.ua");
  sntp_setservername(1,"pool.ntp.org");
  sntp_setservername(2,"ntp2.time.in.ua");
  sntp_set_timezone(Config.GMT);
  sntp_init();
  delay (1000);
}
