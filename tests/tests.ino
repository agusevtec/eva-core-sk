#include <AUnit.h>

using namespace aunit;
#include <evaRepeatTimer.h>

void setup()
{
  Serial.begin(115200);
  while (!Serial);
  aunit::TestRunner::setVerbosity(aunit::Verbosity::kAssertionFailed | aunit::Verbosity::kTestRunSummary);
}

void loop()
{
  aunit::TestRunner::run();
}
