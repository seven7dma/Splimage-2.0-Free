/* Copyright (c) 2007 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef _GDATAFRAMEWORK_H_
#define _GDATAFRAMEWORK_H_

#import <Foundation/Foundation.h>

#import "GDataDefines.h"


// The project's static library target defines these by default:
//
//   -DGDATA_REQUIRE_SERVICE_INCLUDES=1
//   -DGDATA_INCLUDE_nameServiceHere_SERVICE=1
//
// in the additional C flags.  Those should be replaced with specification of
// the actual needed service code, such as:
//
//   -DGDATA_REQUIRE_SERVICE_INCLUDES=1
//   -DGDATA_INCLUDE_CALENDAR_SERVICE=1
//   -DGDATA_INCLUDE_CONTACTS_SERVICE=1
//
// This error will catch projects being built against the nameServiceHere
// placeholder in release builds.
//
#if !DEBUG
  #if GDATA_INCLUDE_nameServiceHere_SERVICE && !GDATA_SUPPRESS_INCLUDE_WARNING
   // #error The service placeholder compiler flag should be replaced by actual service specifications
  #endif
#endif


// Returns the version of the framework.  Major and minor should
// match the bundle version in the Info.plist file.
//
// Pass NULL to ignore any of the parameters.

void GDataFrameworkVersion(NSUInteger* major, NSUInteger* minor, NSUInteger* release);

// Returns the version in @"a.b" or @"a.b.c" format
NSString *GDataFrameworkVersionString(void);

#endif
