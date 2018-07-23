//===- Z80InstPrinter.h - Convert Z80 MCInst to assembly --------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class prints a Z80 MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_Z80_INSTPRINTER_Z80INSTPRINTER_H
#define LLVM_LIB_TARGET_Z80_INSTPRINTER_Z80INSTPRINTER_H

#include "Z80InstPrinterBase.h"

namespace llvm {
class Z80InstPrinter final : public Z80InstPrinterBase {
public:
  Z80InstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                 const MCRegisterInfo &MRI)
    : Z80InstPrinterBase(MAI, MII, MRI) {}

  // Autogenerated by tblgen.
  void printInstruction(const MCInst *MI, raw_ostream &OS) override;
  StringRef getRegName(unsigned RegNo) const override {
    return getRegisterName(RegNo);
  }
  static const char *getRegisterName(unsigned RegNo);
};
}

#endif
