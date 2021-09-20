#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "slicer/common.h"

static std::string customLoggerMsg;
static void testCustomLogger(const std::string& msg) {
  customLoggerMsg = msg;
}

TEST(Slicer, CustomLogger) {
  slicer::set_logger(testCustomLogger);
  slicer::_weakCheckFailed("expr1", 1, "file");
  std::string expected("\nSLICER_WEAK_CHECK failed [expr1] at file:1\n\n");
  ASSERT_EQ(customLoggerMsg, expected);
}