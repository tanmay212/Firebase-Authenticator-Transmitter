#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "rererererter.firebaseio.com"
#define FIREBASE_AUTH "gneyHcUWnzowsCRWuaHiWw7uXZoaT25ITSVtAfD8"
#define WIFI_SSID "Nightwing"
#define WIFI_PASSWORD "nopassword"

void setup()
{
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  //  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  //  Serial.println();
  //  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

String directio;
void loop()
{
  do
  {
   directio = Firebase.getString("this");
    delay(50);
   Serial.println(directio);
  }
  while (!Firebase.failed());

}
