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
using namespace std;


namespace
{
///////////////////

void testConfigSetInt64()
{
   {
      const string caseLabel = "Config::setInt64 for positive value";
      Config cfg;
      cfg.setInt64("test", 42);
      const optional<int64_t> val = cfg.getInt64("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const string caseLabel = "Config::setInt64 for negative value";
      Config cfg;
      cfg.setInt64("test", -100);
      const optional<int64_t> val = cfg.getInt64("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100, caseLabel);
   }
}


void testConfigSetInt32()
{
   {
      const string caseLabel = "Config::setInt32 for positive value";
      Config cfg;
      cfg.setInt32("test", 42);
      const optional<int32_t> val = cfg.getInt32("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const string caseLabel = "Config::setInt32 for negative value";
      Config cfg;
      cfg.setInt32("test", -100);
      const optional<int32_t> val = cfg.getInt32("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100, caseLabel);
   }
}


void testConfigSetInt16()
{
   {
      const string caseLabel = "Config::setInt16 for positive value";
      Config cfg;
      cfg.setInt16("test", 42);
      const optional<int16_t> val = cfg.getInt16("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const string caseLabel = "Config::setInt16 for negative value";
      Config cfg;
      cfg.setInt16("test", -100);
      const optional<int16_t> val = cfg.getInt16("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100, caseLabel);
   }
}


void testConfigSetInt8()
{
   {
      const string caseLabel = "Config::setInt8 for positive value";
      Config cfg;
      cfg.setInt8("test", 42);
      const optional<int8_t> val = cfg.getInt8("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const string caseLabel = "Config::setInt8 for negative value";
      Config cfg;
      cfg.setInt8("test", -100);
      const optional<int8_t> val = cfg.getInt8("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100, caseLabel);
   }
}


void testConfigSetFloat()
{
   {
      const string caseLabel = "Config::setFloat for positive value";
      Config cfg;
      cfg.setFloat("test", 42.123f);
      const optional<float> val = cfg.getFloat("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42.123f, caseLabel);
   }
   {
      const string caseLabel = "Config::setFloat for negative value";
      Config cfg;
      cfg.setFloat("test", -100.0001f);
      const optional<float> val = cfg.getFloat("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100.0001f, caseLabel);
   }
}


void testConfigSetDouble()
{
   {
      const string caseLabel = "Config::setDouble for positive value";
      Config cfg;
      cfg.setDouble("test", 42.123);
      const optional<double> val = cfg.getDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42.123, caseLabel);
   }
   {
      const string caseLabel = "Config::setDouble for negative value";
      Config cfg;
      cfg.setDouble("test", -100.0001);
      const optional<double> val = cfg.getDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100.0001, caseLabel);
   }
}


void testConfigSetLongDouble()
{
   {
      const string caseLabel = "Config::setLongDouble for positive value";
      Config cfg;
      cfg.setLongDouble("test", 42.123L);
      const optional<long double> val = cfg.getLongDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42.123L, caseLabel);
   }
   {
      const string caseLabel = "Config::setLongDouble for negative value";
      Config cfg;
      cfg.setLongDouble("test", -100.0001L);
      const optional<long double> val = cfg.getLongDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == -100.0001L, caseLabel);
   }
}


void testConfigSetBool()
{
   {
      const string caseLabel = "Config::setBool for true value";
      Config cfg;
      cfg.setBool("test", true);
      const optional<bool> val = cfg.getBool("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == true, caseLabel);
   }
   {
      const string caseLabel = "Config::setBool for false value";
      Config cfg;
      cfg.setBool("test", false);
      const optional<bool> val = cfg.getBool("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == false, caseLabel);
   }
}


void testConfigSetString()
{
   {
      const string caseLabel = "Config::setString";
      Config cfg;
      cfg.setString("test", "value");
      const optional<string> val = cfg.getString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == "value", caseLabel);
   }
   {
      const string caseLabel = "Config::setString for empty string";
      Config cfg;
      cfg.setString("test", "");
      const optional<string> val = cfg.getString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == "", caseLabel);
   }
   {
      const string caseLabel = "Config::setString for long string";
      const string value =
         "0abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvwx"
         "yz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrstuv"
         "wxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopqrst"
         "uvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz";
      Config cfg;
      cfg.setString("test", value);
      const optional<string> val = cfg.getString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == value, caseLabel);
   }
}


void testConfigSetWString()
{
   {
      const string caseLabel = "Config::setWString";
      Config cfg;
      cfg.setWString("test", L"value");
      const optional<wstring> val = cfg.getWString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == L"value", caseLabel);
   }
   {
      const string caseLabel = "Config::setWString for empty string";
      Config cfg;
      cfg.setWString("test", L"");
      const optional<wstring> val = cfg.getWString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == L"", caseLabel);
   }
   {
      const string caseLabel = "Config::setWString for long string";
      const wstring value =
         L"0abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz2abcdefghijklmnopqrstuvw"
         L"xyz3abcdefghijklmnopqrstuvwxyz4abcdefghijklmnopqrstuvwxyz5abcdefghijklmnopqrst"
         L"uvwxyz6abcdefghijklmnopqrstuvwxyz7abcdefghijklmnopqrstuvwxyz8abcdefghijklmnopq"
         L"rstuvwxyz9abcdefghijklmnopqrstuvwxyz10abcdefghijklmnopqrstuvwxyz";
      Config cfg;
      cfg.setWString("test", value);
      const optional<wstring> val = cfg.getWString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == value, caseLabel);
   }
}


void testConfigGetInt64()
{
   {
      const string caseLabel = "Config::getInt64 for existing value";
      Config cfg;
      cfg.setInt64("test", 42);
      const optional<int64_t> val = cfg.getInt64("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const string caseLabel = "Config::getInt64 for not existing value";
      Config cfg;
      cfg.setInt64("test", 42);
      const optional<int64_t> val = cfg.getInt64("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetInt32()
{
   {
      const string caseLabel = "Config::getInt32 for existing value";
      Config cfg;
      cfg.setInt32("test", 42);
      const optional<int32_t> val = cfg.getInt32("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const string caseLabel = "Config::getInt32 for not existing value";
      Config cfg;
      cfg.setInt32("test", 42);
      const optional<int32_t> val = cfg.getInt32("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetInt16()
{
   {
      const string caseLabel = "Config::getInt16 for existing value";
      Config cfg;
      cfg.setInt16("test", 42);
      const optional<int16_t> val = cfg.getInt16("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const string caseLabel = "Config::getInt16 for not existing value";
      Config cfg;
      cfg.setInt16("test", 42);
      const optional<int16_t> val = cfg.getInt16("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetInt8()
{
   {
      const string caseLabel = "Config::getInt8 for existing value";
      Config cfg;
      cfg.setInt8("test", 42);
      const optional<int8_t> val = cfg.getInt8("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 42, caseLabel);
   }
   {
      const string caseLabel = "Config::getInt8 for not existing value";
      Config cfg;
      cfg.setInt8("test", 42);
      const optional<int8_t> val = cfg.getInt8("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetFloat()
{
   {
      const string caseLabel = "Config::getFloat for existing value";
      Config cfg;
      cfg.setFloat("test", 100.0001f);
      const optional<float> val = cfg.getFloat("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 100.0001f, caseLabel);
   }
   {
      const string caseLabel = "Config::getFloat for not existing value";
      Config cfg;
      cfg.setFloat("test", 100.0001f);
      const optional<float> val = cfg.getFloat("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetDouble()
{
   {
      const string caseLabel = "Config::getDouble for existing value";
      Config cfg;
      cfg.setDouble("test", 100.0001);
      const optional<double> val = cfg.getDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 100.0001, caseLabel);
   }
   {
      const string caseLabel = "Config::getDouble for not existing value";
      Config cfg;
      cfg.setDouble("test", 100.0001);
      const optional<double> val = cfg.getDouble("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetLongDouble()
{
   {
      const string caseLabel = "Config::getLongDouble for existing value";
      Config cfg;
      cfg.setLongDouble("test", 100.0001L);
      const optional<long double> val = cfg.getLongDouble("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == 100.0001L, caseLabel);
   }
   {
      const string caseLabel = "Config::getLongDouble for not existing value";
      Config cfg;
      cfg.setLongDouble("test", 100.0001L);
      const optional<long double> val = cfg.getLongDouble("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetBool()
{
   {
      const string caseLabel = "Config::getBool for existing value";
      Config cfg;
      cfg.setBool("test", true);
      const optional<bool> val = cfg.getBool("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == true, caseLabel);
   }
   {
      const string caseLabel = "Config::getBool for not existing value";
      Config cfg;
      cfg.setBool("test", true);
      const optional<bool> val = cfg.getBool("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetString()
{
   {
      const string caseLabel = "Config::getString for existing value";
      Config cfg;
      cfg.setString("test", "hello");
      const optional<string> val = cfg.getString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == "hello", caseLabel);
   }
   {
      const string caseLabel = "Config::getString for not existing value";
      Config cfg;
      cfg.setString("test", "hello");
      const optional<string> val = cfg.getString("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigGetWString()
{
   {
      const string caseLabel = "Config::getWString for existing value";
      Config cfg;
      cfg.setWString("test", L"hello");
      const optional<wstring> val = cfg.getWString("test");
      VERIFY(val.has_value(), caseLabel);
      VERIFY(val.value() == L"hello", caseLabel);
   }
   {
      const string caseLabel = "Config::getWString for not existing value";
      Config cfg;
      cfg.setWString("test", L"hello");
      const optional<wstring> val = cfg.getWString("missing");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigRemove()
{
   {
      const string caseLabel = "Config::remove for existing value";
      Config cfg;
      cfg.setString("test", "hello");
      
      cfg.remove("test");
      
      const optional<string> val = cfg.getString("test");
      VERIFY(!val.has_value(), caseLabel);
   }
}


void testConfigClear()
{
   {
      const string caseLabel = "Config::clear";
      Config cfg;
      cfg.setString("test", "hello");
      
      cfg.clear();
      
      const optional<string> val = cfg.getString("test");
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
