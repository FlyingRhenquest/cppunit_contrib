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
 * This is a basic test for my test listener. Note that I'm failing
 * some tests here so I can verify my test report looks the way I want
 * it to. I really should wrap running these tests in the framework,
 * but I don't really want to get that deep into the cppunit
 * implementation.
 */

#include <fr/cppunit>

class basic_test : public CppUnit::TestFixture {
  
  CPPUNIT_TEST_SUITE(basic_test);
  CPPUNIT_TEST(test_pass);
  CPPUNIT_TEST(test_fail);
  CPPUNIT_TEST_SUITE_END();

public:

  void test_pass()
  {
    CPPUNIT_ASSERT(true);
  }

  void test_fail()
  {
    CPPUNIT_ASSERT(false);
  }

};

CPPUNIT_TEST_SUITE_REGISTRATION(basic_test);

