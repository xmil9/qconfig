//
// qconfig tests
// Main entry point.
//
// Jun-2019, Michael Lindner
// MIT license
//
#include "config_tests.h"
#include "file_storage_tests.h"
#include "registry_storage_tests.h"
#include <cstdlib>
#include <iostream>


int main()
{
   testConfig();
   testFileStorage();
   testRegistryStorage();

   std::cout << "qconfig tests finished.\n";
   return EXIT_SUCCESS;
}
