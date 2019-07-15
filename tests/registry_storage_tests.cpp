//
// qconfig tests
// Tests for registry storage.
//
// Jun-2019, Michael Lindner
// MIT license
//
#include "registry_storage_tests.h"
#include "config.h"
#include "registry_storage.h"
#include "test_util.h"
#include "win32_util/registry.h"
#include "win32_util/win32_windows.h"
#include <array>
#include <optional>
#include <string>

using namespace qcfg;


namespace
{
///////////////////

const HKEY TestsRegHive = HKEY_CURRENT_USER;
const std::wstring TestsKeyPath = L"Software\\Projects\\qconfig\\tests";


///////////////////

void testRegistryStorageSave()
{
   {
      const std::string caseLabel = "RegistryStorage::save";
      const std::wstring keyPath = TestsKeyPath + L"\\save";

      Config config;
      config.setString("test", "hello");

      RegistryStorage storage{TestsRegHive, keyPath};
      const bool saved = config.save(storage);

      VERIFY(saved, caseLabel);
      VERIFY(win32::RegKey::keyExists(TestsRegHive, keyPath), caseLabel);

      win32::RegKey::removeKey(TestsRegHive, keyPath);
   }
   {
      const std::string caseLabel = "RegistryStorage::save empty config";
      const std::wstring keyPath = TestsKeyPath + L"\\save_empty";

      Config config;
      RegistryStorage storage{TestsRegHive, keyPath};
      const bool saved = config.save(storage);

      VERIFY(saved, caseLabel);
      VERIFY(win32::RegKey::keyExists(TestsRegHive, keyPath), caseLabel);

      win32::RegKey::removeKey(TestsRegHive, keyPath);
   }
}


void testRegistryStorageLoad()
{
   {
      const std::string caseLabel = "RegistryStorage::load existing config file";
      const std::wstring keyPath = TestsKeyPath + L"\\load";

      {
         win32::RegKey setup{TestsRegHive, keyPath};
         setup.writeString(L"a", "1");
         setup.writeString(L"b", "two");
      }

      Config config;
      RegistryStorage storage{TestsRegHive, keyPath};
      const bool loaded = config.load(storage);

      VERIFY(loaded, caseLabel);
      VERIFY(config.getInt32("a") == 1, caseLabel);
      VERIFY(config.getString("b") == "two", caseLabel);

      win32::RegKey::removeKey(TestsRegHive, keyPath);
   }
   {
      const std::string caseLabel = "RegistryStorage::load empty config file";
      const std::wstring keyPath = TestsKeyPath + L"\\load_empty";

      {
         win32::RegKey setup{TestsRegHive, keyPath};
      }

      Config config;
      config.setString("previous", "value");
      RegistryStorage storage{TestsRegHive, keyPath};
      const bool loaded = config.load(storage);

      VERIFY(loaded, caseLabel);
      VERIFY(config.getString("previous") == std::nullopt, caseLabel);

      win32::RegKey::removeKey(TestsRegHive, keyPath);
   }
}


void testRegistryStorageRoundtrip()
{
   {
      const std::string caseLabel = "RegistryStorage save/load roundtrip";
      const std::wstring keyPath = TestsKeyPath + L"\\roundtrip";

      Config config;
      config.setInt64("int64", 64);
      config.setInt32("int32", 32);
      config.setInt32("int16", 16);
      config.setInt32("int8", 8);
      config.setFloat("float", 1.23456f);
      config.setDouble("double", 12345.678);
      config.setLongDouble("long double", 0.123456L);
      config.setBool("bool", true);
      config.setString("string", "my string");
      config.setWString("wstring", L"my wstring");

      RegistryStorage storage{TestsRegHive, keyPath};
      const bool saved = config.save(storage);
      VERIFY(saved, caseLabel);

      if (saved)
      {
         Config loadedConfig;
         loadedConfig.load(storage);

         VERIFY(loadedConfig.getInt64("int64") == 64, caseLabel);
         VERIFY(loadedConfig.getInt32("int32") == 32, caseLabel);
         VERIFY(loadedConfig.getInt16("int16") == 16, caseLabel);
         VERIFY(loadedConfig.getInt8("int8") == 8, caseLabel);
         VERIFY(loadedConfig.getFloat("float") == 1.23456f, caseLabel);
         VERIFY(loadedConfig.getDouble("double") == 12345.678, caseLabel);
         VERIFY(loadedConfig.getLongDouble("long double") == 0.123456L, caseLabel);
         VERIFY(loadedConfig.getBool("bool") == true, caseLabel);
         VERIFY(loadedConfig.getString("string") == "my string", caseLabel);
         VERIFY(loadedConfig.getWString("wstring") == L"my wstring", caseLabel);
      }

      win32::RegKey::removeKey(TestsRegHive, keyPath);
   }
}

} // namespace


void testRegistryStorage()
{
   testRegistryStorageSave();
   testRegistryStorageLoad();
   testRegistryStorageRoundtrip();
}
