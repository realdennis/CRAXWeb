//===-- Timer.cpp ---------------------------------------------------------===//
//
//                     The KLEE Symbolic Virtual Machine
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "klee/Internal/Support/Timer.h"

#include "llvm/System/Process.h"

using namespace klee;
using namespace llvm;

WallTimer::WallTimer() {
  sys::TimeValue now(0,0),user(0,0),sys(0,0);
  sys::Process::GetTimeUsage(now,user,sys);
  startMicroseconds = now.usec();
}

uint64_t WallTimer::check() {
  sys::TimeValue now(0,0),user(0,0),sys(0,0);
  sys::Process::GetTimeUsage(now,user,sys);
  return now.usec() - startMicroseconds;
}
