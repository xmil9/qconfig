//
// qconfig tests
// Tests for config class.
//
// Jun-2019, Michael Lindner
// MIT license
//
#include "config_tests.h"
#include "config.h"
#include "test_util.h"
#include <optional>
#include <string>

using namespace qcfg;


namespace
{
///////////////////

void testConfigSetInt64()
{
   {
      const std::string caseLabel = "Config::setInt64 for positive value";
      Config cfg;
      cfg.setInt64("test", 42);
      const std::optional<int64_t> val = cfg.getInt64("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const std::string caseLabel = "Config::setInt64 for negative value";
      Config cfg;
      cfg.setInt64("test", -100);
      const std::optional<int64_t> val = cfg.getInt64("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100, caseLabel);
   }
}


void testConfigSetInt32()
{
   {
      const std::string caseLabel = "Config::setInt32 for positive value";
      Config cfg;
      cfg.setInt32("test", 42);
      const std::optional<int32_t> val = cfg.getInt32("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const std::string caseLabel = "Config::setInt32 for negative value";
      Config cfg;
      cfg.setInt32("test", -100);
      const std::optional<int32_t> val = cfg.getInt32("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100, caseLabel);
   }
}


void testConfigSetInt16()
{
   {
      const std::string caseLabel = "Config::setInt16 for positive value";
      Config cfg;
      cfg.setInt16("test", 42);
      const std::optional<int16_t> val = cfg.getInt16("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const std::string caseLabel = "Config::setInt16 for negative value";
      Config cfg;
      cfg.setInt16("test", -100);
      const std::optional<int16_t> val = cfg.getInt16("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100, caseLabel);
   }
}


void testConfigSetInt8()
{
   {
      const std::string caseLabel = "Config::setInt8 for positive value";
      Config cfg;
      cfg.setInt8("test", 42);
      const std::optional<int8_t> val = cfg.getInt8("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const std::string caseLabel = "Config::setInt8 for negative value";
      Config cfg;
      cfg.setInt8("test", -100);
      const std::optional<int8_t> val = cfg.getInt8("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100, caseLabel);
   }
}


void testConfigSetFloat()
{
   {
      const std::string caseLabel = "Config::setFloat for positive value";
      Config cfg;
      cfg.setFloat("test", 42.123f);
      const std::optional<float> val = cfg.getFloat("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42.123f, caseLabel);
   }
   {
      const std::string caseLabel = "Config::setFloat for negative value";
      Config cfg;
      cfg.setFloat("test", -100.0001f);
      const std::optional<float> val = cfg.getFloat("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100.0001f, caseLabel);
   }
}


void testConfigSetDouble()
{
   {
      const std::string caseLabel = "Config::setDouble for positive value";
      Config cfg;
      cfg.setDouble("test", 42.123);
      const std::optional<double> val = cfg.getDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42.123, caseLabel);
   }
   {
      const std::string caseLabel = "Config::setDouble for negative value";
      Config cfg;
      cfg.setDouble("test", -100.0001);
      const std::optional<double> val = cfg.getDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100.0001, caseLabel);
   }
}


void testConfigSetLongDouble()
{
   {
      const std::string caseLabel = "Config::setLongDouble for positive value";
      Config cfg;
      cfg.setLongDouble("test", 42.123L);
      const std::optional<long double> val = cfg.getLongDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42.123L, caseLabel);
   }
   {
      const std::string caseLabel = "Config::setLongDouble for negative value";
      Config cfg;
      cfg.setLongDouble("test", -100.0001L);
      const std::optional<long double> val = cfg.getLongDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100.0001L, caseLabel);
   }
}


void testConfigSetBool()
{
   {
      const std::string caseLabel = "Config::setBool for true value";
      Config cfg;
      cfg.setBool("test", true);
      const std::optional<bool> val = cfg.getBool("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == true, caseLabel);
   }
   {
      const std::string caseLabel = "Config::setBool for false value";
      Config cfg;
      cfg.setBool("test", false);
      const std::optional<bool> val = cfg.getBool("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == false, caseLabel);
   }
}


void testConfigSetString()
{
   {
      const std::string caseLabel = "Config::setString";
      Config cfg;
      cfg.setString("test", "value");
      const std::optional<std::string> val = cfg.getString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == "value", caseLabel);
   }
   {
      const std::string caseLabel = "Config::setString for empty string";
      Config cfg;
      cfg.setString("test", "");
      const std::optional<std::string> val = cfg.getString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == "", caseLabel);
   }
   {
      const std::string caseLabel = "Config::setString for long string";
      const std::string value =
         "0abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwx"
         "yz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuv"
         "wxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrst"
         "uvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz";
      Config cfg;
      cfg.setString("test", value);
      const std::optional<std::string> val = cfg.getString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == value, caseLabel);
   }
}


void testConfigSetWString()
{
   {
      const std::string caseLabel = "Config::setWString";
      Config cfg;
      cfg.setWString("test", L"value");
      const std::optional<std::wstring> val = cfg.getWString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == L"value", caseLabel);
   }
   {
      const std::string caseLabel = "Config::setWString for empty string";
      Config cfg;
      cfg.setWString("test", L"");
      const std::optional<std::wstring> val = cfg.getWString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == L"", caseLabel);
   }
   {
      const std::string caseLabel = "Config::setWString for long string";
      const std::wstring value =
         L"0abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvw"
         L"xyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrst"
         L"uvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopq"
         L"rstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz";
      Config cfg;
      cfg.setWString("test", value);
      const std::optional<std::wstring> val = cfg.getWString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == value, caseLabel);
   }
}


void testConfigGetInt64()
{
   {
      const std::string caseLabel = "Config::getInt64 for existing value";
      Config cfg;
      cfg.setInt64("test", 42);
      const std::optional<int64_t> val = cfg.getInt64("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const std::string caseLabel = "Config::getInt64 for not existing value";
      Config cfg;
      cfg.setInt64("test", 42);
      const std::optional<int64_t> val = cfg.getInt64("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetInt32()
{
   {
      const std::string caseLabel = "Config::getInt32 for existing value";
      Config cfg;
      cfg.setInt32("test", 42);
      const std::optional<int32_t> val = cfg.getInt32("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const std::string caseLabel = "Config::getInt32 for not existing value";
      Config cfg;
      cfg.setInt32("test", 42);
      const std::optional<int32_t> val = cfg.getInt32("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetInt16()
{
   {
      const std::string caseLabel = "Config::getInt16 for existing value";
      Config cfg;
      cfg.setInt16("test", 42);
      const std::optional<int16_t> val = cfg.getInt16("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const std::string caseLabel = "Config::getInt16 for not existing value";
      Config cfg;
      cfg.setInt16("test", 42);
      const std::optional<int16_t> val = cfg.getInt16("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetInt8()
{
   {
      const std::string caseLabel = "Config::getInt8 for existing value";
      Config cfg;
      cfg.setInt8("test", 42);
      const std::optional<int8_t> val = cfg.getInt8("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const std::string caseLabel = "Config::getInt8 for not existing value";
      Config cfg;
      cfg.setInt8("test", 42);
      const std::optional<int8_t> val = cfg.getInt8("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetFloat()
{
   {
      const std::string caseLabel = "Config::getFloat for existing value";
      Config cfg;
      cfg.setFloat("test", 100.0001f);
      const std::optional<float> val = cfg.getFloat("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 100.0001f, caseLabel);
   }
   {
      const std::string caseLabel = "Config::getFloat for not existing value";
      Config cfg;
      cfg.setFloat("test", 100.0001f);
      const std::optional<float> val = cfg.getFloat("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetDouble()
{
   {
      const std::string caseLabel = "Config::getDouble for existing value";
      Config cfg;
      cfg.setDouble("test", 100.0001);
      const std::optional<double> val = cfg.getDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 100.0001, caseLabel);
   }
   {
      const std::string caseLabel = "Config::getDouble for not existing value";
      Config cfg;
      cfg.setDouble("test", 100.0001);
      const std::optional<double> val = cfg.getDouble("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetLongDouble()
{
   {
      const std::string caseLabel = "Config::getLongDouble for existing value";
      Config cfg;
      cfg.setLongDouble("test", 100.0001L);
      const std::optional<long double> val = cfg.getLongDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 100.0001L, caseLabel);
   }
   {
      const std::string caseLabel = "Config::getLongDouble for not existing value";
      Config cfg;
      cfg.setLongDouble("test", 100.0001L);
      const std::optional<long double> val = cfg.getLongDouble("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetBool()
{
   {
      const std::string caseLabel = "Config::getBool for existing value";
      Config cfg;
      cfg.setBool("test", true);
      const std::optional<bool> val = cfg.getBool("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == true, caseLabel);
   }
   {
      const std::string caseLabel = "Config::getBool for not existing value";
      Config cfg;
      cfg.setBool("test", true);
      const std::optional<bool> val = cfg.getBool("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetString()
{
   {
      const std::string caseLabel = "Config::getString for existing value";
      Config cfg;
      cfg.setString("test", "hello");
      const std::optional<std::string> val = cfg.getString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == "hello", caseLabel);
   }
   {
      const std::string caseLabel = "Config::getString for not existing value";
      Config cfg;
      cfg.setString("test", "hello");
      const std::optional<std::string> val = cfg.getString("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetWString()
{
   {
      const std::string caseLabel = "Config::getWString for existing value";
      Config cfg;
      cfg.setWString("test", L"hello");
      const std::optional<std::wstring> val = cfg.getWString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == L"hello", caseLabel);
   }
   {
      const std::string caseLabel = "Config::getWString for not existing value";
      Config cfg;
      cfg.setWString("test", L"hello");
      const std::optional<std::wstring> val = cfg.getWString("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigRemove()
{
   {
      const std::string caseLabel = "Config::remove for existing value";
      Config cfg;
      cfg.setString("test", "hello");

      cfg.remove("test");

      const std::optional<std::string> val = cfg.getString("test");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigClear()
{
   {
      const std::string caseLabel = "Config::clear";
      Config cfg;
      cfg.setString("test", "hello");

      cfg.clear();

      const std::optional<std::string> val = cfg.getString("test");
      VERIFY(!val.has_value(), caseLabel);
   }
}

} // namespace


void testConfig()
{
   testConfigSetInt64();
   testConfigSetInt32();
   testConfigSetInt16();
   testConfigSetInt8();
   testConfigSetFloat();
   testConfigSetDouble();
   testConfigSetLongDouble();
   testConfigSetBool();
   testConfigSetString();
   testConfigSetWString();
   testConfigGetInt64();
   testConfigGetInt32();
   testConfigGetInt16();
   testConfigGetInt8();
   testConfigGetFloat();
   testConfigGetDouble();
   testConfigGetLongDouble();
   testConfigGetBool();
   testConfigGetString();
   testConfigGetWString();
   testConfigRemove();
   testConfigClear();
}
