/**
 * @file main.cpp
 * @copyright 2012 Jolla Ltd.
 * @author Martin Kampas <martin.kampas@tieto.com>
 * @date 2012
 */

#include <QtTest/QtTest>

#include "libssu/sandbox_p.h"
#include "deviceinfotest.h"

int main(int argc, char **argv){
  Sandbox sandbox(QString("%1/configroot").arg(LOCATE_DATA_PATH),
      Sandbox::UseAsSkeleton, Sandbox::ThisProcess);
  if (!sandbox.activate()){
    qFatal("Failed to activate sandbox");
  }

  DeviceInfoTest deviceinfoTest;

  if (QTest::qExec(&deviceinfoTest, argc, argv))
    return 1;

  return 0;
}
