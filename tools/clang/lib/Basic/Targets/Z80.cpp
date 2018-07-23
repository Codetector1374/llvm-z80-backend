//===--- Z80.cpp - Implement Z80 target feature support -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements Z80 TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#include "Z80.h"
#include "llvm/ADT/StringSwitch.h"

using namespace clang;
using namespace clang::targets;

bool Z80TargetInfo::setCPU(const std::string &Name) {
  return llvm::StringSwitch<bool>(Name)
    .Case("generic", true)
    .Case("z80",     true)
    .Default(false);
}

bool Z80TargetInfo::
initFeatureMap(llvm::StringMap<bool> &Features,
               DiagnosticsEngine &Diags, StringRef CPU,
               const std::vector<std::string> &FeaturesVec) const {
  if (CPU == "z80")
    Features["undoc"] = true;
  return TargetInfo::initFeatureMap(Features, Diags, CPU, FeaturesVec);
}

ArrayRef<const char *> Z80TargetInfo::getGCCRegNames() const {
  static const char *const GCCRegNames[] = {
    "a", "f", "b", "c", "d", "e", "h", "l",
    "a'", "f'", "b'", "c'", "d'", "e'", "h'", "l'",
    "ixh", "ixl", "iyh", "iyl", "i", "r",
    "af", "bc", "de", "hl", "af'", "bc'", "de'", "hl'",
    "ix", "iy", "sp", "pc"
  };
  return GCCRegNames;
}

void Z80TargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Z80TargetInfoBase::getTargetDefines(Opts, Builder);
  defineCPUMacros(Builder, "Z80", /*Tuning=*/false);
  if (getTargetOpts().CPU == "undoc")
    defineCPUMacros(Builder, "Z80_UNDOC", /*Tuning=*/false);
}
