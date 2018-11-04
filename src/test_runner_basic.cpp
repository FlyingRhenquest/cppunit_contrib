/**
 * Copyright 2018 Bruce Ide
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * This is a basic generic test runner that runs all registered test suites.
 * In a cmake/ctest scenario, it's probably best to compile this to an object
 * file, then link each individual test class you create to its own executable.
 * That way if one crashes, ctest can report it and continue testing the
 * other tests. The other option is to link all your test classes into one
 * monolithic test excutable. If you do that, the listener I'm using will
 * generate a single test report at the end of the entire test run, but
 * if any test actually crashes, all testing will stop at that point.
 * You also won't have the option to run one single individual test
 * with a monolithic test.
 */

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestRunner.h>
#include <fr/cppunit_contrib/listener>
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[])
{
  bool tests_failed = false;
  CppUnit::TestResult controller;  
  fr::cppunit_contrib::listener progress;
  
  controller.addListener(&progress);
  CppUnit::TestRunner runner;
  runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
  try {
    runner.run(controller);
    tests_failed = !progress.all_tests_passed;
    std::cout << progress.get_report();
  } catch (std::exception &e) {
    std::cerr << "ERROR: Uncaught exception while running tests: " << e.what();
    tests_failed = true;
  }
  
  return (int) tests_failed;
}
