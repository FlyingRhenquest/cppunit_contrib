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
 * Verifies test listener works correctly when a test throws an unexpected
 * excepetion.
 */

#include <fr/cppunit>
#include <stdexcept>

class exception_test : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(exception_test);
  CPPUNIT_TEST(diae); // Die in an exception
  CPPUNIT_TEST_SUITE_END();
  
public:

  void diae()
  {
    throw std::logic_error("Doh! I'm dead! My one regret is that I have bonitis!");
    CPPUNIT_ASSERT(true);
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(exception_test);
