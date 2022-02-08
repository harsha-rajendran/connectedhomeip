/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      This file implements a unit test suite for GenericOTARequestorStorage.
 *
 */

#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib/support/CodeUtils.h>
#include <lib/support/UnitTestRegistration.h>
#include <lib/support/UnitTestUtils.h>
#include <nlunit-test.h>

#include <platform/internal/CHIPDeviceLayerInternal.h>
#include <platform/GenericOTARequestorStorage.h>

using namespace chip;
using namespace chip::Logging;
using namespace chip::System;

// =================================
//      Unit tests
// =================================

static void Test_Basic(nlTestSuite * inSuite, void * inContext)
{
    int numOfTestsRan                      = 0;
    GenericOTARequestorStorage storage;
    storage.LoadDefaultOTAProvidersList();
    NL_TEST_ASSERT(inSuite, numOfTestsRan > 0);
}

/**
 *   Test Suite. It lists all the test functions.
 */
static const nlTest sTests[] = {

    NL_TEST_DEF("Test OTARequestorStorage", Test_Basic),

    NL_TEST_SENTINEL()
};

int TestPlatformOTARequestorStorage()
{
    nlTestSuite theSuite = { "PlatformOTARequestorStorage tests", &sTests[0], nullptr, nullptr };

    // Run test suit againt one context.
    nlTestRunner(&theSuite, nullptr);
    return nlTestRunnerStats(&theSuite);
}

CHIP_REGISTER_TEST_SUITE(TestPlatformOTARequestorStorage)
