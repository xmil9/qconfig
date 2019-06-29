//
// qconfig tests
// Tests for file storage.
//
// Jun-2019, Michael Lindner
// MIT license
//
#include "file_storage_tests.h"
#include "config.h"
#include "file_storage.h"
#include "test_util.h"
#include "win32_util/win32_windows.h"
#include <array>
#include <filesystem>
#include <optional>
#include <string>

using namespace qcfg;
using namespace std;
namespace fs = std::filesystem;


namespace
{
///////////////////

// Returns the directory that the app's executable is located in.
fs::path appDirectory()
{
#ifdef _WIN32
   array<char, MAX_PATH> buffer;
   const DWORD res =
      GetModuleFileNameA(NULL, buffer.data(), static_cast<DWORD>(buffer.size()));
   if (res == 0 || GetLastError() == ERROR_INSUFFICIENT_BUFFER)
      return {};

   fs::path appPath{buffer.data()};
   appPath.remove_filename();

   return appPath;
#else
   assert("todo");
#endif
}


// Returns the directory that tests can use to load/save data from/to.
fs::path testDataDirectory()
{
   fs::path dataDir = appDirectory();

#ifdef _WIN32 // windows
#ifdef _WIN64 // x64
   // x64 targets have an additional '/x64' subfolder.
   constexpr size_t numSubdirs = 5;
#else
   constexpr size_t numSubdirs = 4;
#endif
#else
   assert("todo");
#endif

   for (size_t i = 0; i < numSubdirs; ++i)
      dataDir = dataDir.parent_path();
   return dataDir / "tests" / "data";
}


///////////////////

void testFileStorageSave(const fs::path& dataDir)
{
   {
      const string caseLabel = "FileStorage::save";
      const fs::path caseDir = dataDir / "file_storage_save";
      fs::create_directories(caseDir);
      const fs::path filePath = caseDir / "config.txt";
      fs::remove(filePath);

      Config config;
      config.setString("test", "hello");

      FileStorage storage{filePath};
      const bool saved = config.save(storage);

      error_code errCode;
      const bool fileExists = fs::exists(filePath, errCode);

      VERIFY(saved, caseLabel);
      VERIFY(fileExists, caseLabel);

      fs::remove_all(caseDir);
   }
   {
      const string caseLabel = "FileStorage::save empty config";
      const fs::path caseDir = dataDir / "file_storage_save_empty";
      fs::create_directories(caseDir);
      const fs::path filePath = caseDir / "config.txt";
      fs::remove(filePath);

      Config config;
      FileStorage storage{filePath};
      const bool saved = config.save(storage);

      error_code errCode;
      const bool fileExists = fs::exists(filePath, errCode);

      VERIFY(saved, caseLabel);
      VERIFY(fileExists, caseLabel);

      fs::remove_all(caseDir);
   }
}


void testFileStorageLoad(const fs::path& dataDir)
{
   {
      const string caseLabel = "FileStorage::load existing config file";
      const fs::path caseDir = dataDir / "file_storage_load";
      const fs::path filePath = caseDir / "config.txt ";

      Config config;
      FileStorage storage{filePath};
      const bool loaded = config.load(storage);

      VERIFY(loaded, caseLabel);
      VERIFY(config.getInt32("a") == 1, caseLabel);
      VERIFY(config.getString("b") == "two", caseLabel);
   }
   {
      const string caseLabel = "FileStorage::load config file with comments";
      const fs::path caseDir = dataDir / "file_storage_load";
      const fs::path filePath = caseDir / "config_comments.txt ";

      Config config;
      FileStorage storage{filePath};
      const bool loaded = config.load(storage);

      VERIFY(loaded, caseLabel);
      VERIFY(config.getInt32("a") == 1, caseLabel);
      VERIFY(config.getString("b") == "two", caseLabel);
   }
   {
      const string caseLabel = "FileStorage::load empty config file";
      const fs::path caseDir = dataDir / "file_storage_load";
      const fs::path filePath = caseDir / "config_empty.txt ";

      Config config;
      config.setString("previous", "value");
      FileStorage storage{filePath};
      const bool loaded = config.load(storage);

      VERIFY(loaded, caseLabel);
      VERIFY(config.getString("previous") == nullopt, caseLabel);
   }
}


void testFileStorageRoundtrip(const fs::path& dataDir)
{
   {
      const string caseLabel = "FileStorage save/load roundtrip";
      const fs::path caseDir = dataDir / "file_storage_roundtrip";
      fs::create_directories(caseDir);
      const fs::path filePath = caseDir / "config.txt";
      fs::remove(filePath);

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

      FileStorage storage{filePath};
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

      fs::remove_all(caseDir);
   }
}

} // namespace


void testFileStorage()
{
   const fs::path dataDir = testDataDirectory();
   testFileStorageSave(dataDir);
   testFileStorageLoad(dataDir);
   testFileStorageRoundtrip(dataDir);
}
