#include <SoftwareSerial.h>

SoftwareSerial esp(10, 11);
void setup()
{
	esp.begin(9600);
	Serial.begin(115200);
	Serial.println("start");
	_delay_ms(1000);
	esp.println("AT+CWMODE=1");//режим 1 Ч STA, 2 Ч AP, 3 Ч BOTH
	esp.find("OK");
	esp.println("AT+CWJAP=\"WiFiName\",\"WiFiPassword\"");
	_delay_ms(3000);
	if (esp.find("OK"))
	{
		Serial.println("Connected to WiFi: OK");
		esp.println("AT+CIPMODE=0");
		esp.find("OK");
		esp.println("AT+CIPMUX=1");
		esp.find("OK");
		esp.println("AT+CIPSERVER=1,8888");
		esp.find("OK");
		Serial.println("Init server: OK");
	}
	else
	{
		Serial.println("Connected to WiFi: Error");
	}
}

void loop()
{
	if (esp.available())
	{
		Serial.write(esp.read());
	}
}
