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
 * This test kills itself with a segv
 */

#include <fr/cppunit>
#include <signal.h>

class segv_test : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(segv_test);
  CPPUNIT_TEST(kill_self);
  CPPUNIT_TEST_SUITE_END();

public:

  void kill_self()
  {
    raise(11);
    // Oh I better not still be alive!
    CPPUNIT_ASSERT(true);
  }

};

CPPUNIT_TEST_SUITE_REGISTRATION(segv_test);
