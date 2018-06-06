#include <CycleDelayCounter.h>

CycleDelayCounter cnt(2000UL);
//CycleDelayCounter cnt(2000UL, false);


void setup() {
    Serial.begin(115200);
    Serial.println("Setup finished");
}
int counter = 2000;

void loop() {
    if (cnt.finished()) {
        Serial.print(millis());
        Serial.println(" Counter finished");
        delay(500);
        cnt.startCounter();
    }
}
