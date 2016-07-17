#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Our IP address
IPAddress ip(2,2,2,103);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup() 
  {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) { } // wait for serial port to connect.

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print(F("Server is at "));
  Serial.println(Ethernet.localIP());
  }  // end of setup

// how much serial data we expect before a newline
const unsigned int MAX_INPUT = 100;
// the maximum length of paramters we accept
const int MAX_PARAM = 10;

// Example GET line: GET /?foo=bar HTTP/1.1
void processGet (const char * data)
  {
  // find where the parameters start
  const char * paramsPos = strchr (data, '?');
  if (paramsPos == NULL)
    return;  // no parameters
  // find the trailing space
  const char * spacePos = strchr (paramsPos, ' ');
  if (spacePos == NULL)
    return;  // no space found
  // work out how long the parameters are
  int paramLength = spacePos - paramsPos - 1;
  // see if too long
  if (paramLength >= MAX_PARAM)
    return;  // too long for us
  // copy parameters into a buffer
  char param [MAX_PARAM];
  memcpy (param, paramsPos + 1, paramLength);  // skip the "?"
  param [paramLength] = 0;  // null terminator

  // do things depending on argument (GET parameters)

  if (strcmp (param, "foo") == 0){
  tempx();
    Serial.println (F("Activating foo"));
//
  }

  else if (strcmp (param, "bar") == 0){
    Serial.println (F("Activating bar"));
  }
  }  // end of processGet

// here to process incoming serial data after a terminator received
void processData (const char * data)
  {
  Serial.println (data);
  if (strlen (data) < 4)
    return;

  if (memcmp (data, "GET ", 4) == 0)
    processGet (&data [4]);
  }  // end of processData

bool processIncomingByte (const byte inByte)
  {
  static char input_line [MAX_INPUT];
  static unsigned int input_pos = 0;
  switch (inByte)
    {
    case '\n':   // end of text
      input_line [input_pos] = 0;  // terminating null byte
      if (input_pos == 0)
        return true;   // got blank line
      // terminator reached! process input_line here ...
      processData (input_line);
      // reset buffer for next time
      input_pos = 0;  
      break;

    case '\r':   // discard carriage return
      break;

    default:
      // keep adding if not full ... allow for terminating null byte
      if (input_pos < (MAX_INPUT - 1))
        input_line [input_pos++] = inByte;
      break;
    }  // end of switch
  return false;    // don't have a blank line yet
  } // end of processIncomingByte  


void loop() 
  {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) 
    {
    Serial.println(F("Client connected"));
    // an http request ends with a blank line
    boolean done = false;
    while (client.connected() && !done) 
      {
      while (client.available () > 0 && !done)
        done = processIncomingByte (client.read ());
      }  // end of while client connected

    // send a standard http response header
    client.println(F("HTTP/1.1 200 OK"));
    client.println(F("Content-Type: text/html"));
    client.println(F("Connection: close"));  // close after completion of the response
    client.println();   // end of HTTP header
    client.println(F("<!DOCTYPE HTML>"));
    client.println(F("<html>"));
    client.println(F("<head>"));
    client.println(F("<title>Test page</title>"));
    client.println(F("</head>"));
    client.println(F("<body>"));
    client.println(F("<h1>My web page</h1>"));
    client.println(F("<p>Requested actions performed"));
    client.println(F("</body>"));
    client.println(F("</html>"));

    // give the web browser time to receive the data
    delay(10);
    // close the connection:
    client.stop();
    Serial.println(F("Client disconnected"));
  }  // end of got a new client
} 



void tempx(){
    EthernetClient client = server.available();
    client.println(F("HTTP/1.1 200 OK"));
    client.println(F("Content-Type: text/html"));
    client.println(F("Connection: close"));  // close after completion of the response
    client.println();   // end of HTTP header
    client.println(F("<!DOCTYPE HTML>"));
    client.println(F("<html>"));
    client.println(F("<head>"));
    client.println(F("<title>Test page</title>"));
    client.println(F("</head>"));
    client.println(F("<body>"));
    client.println(F("<h1>TEMPERATURE IS: </h1>"));
    client.println(F("</body>"));
    client.println(F("</html>"));

    // give the web browser time to receive the data
    delay(10);
    // close the connection:
    client.stop();

}
