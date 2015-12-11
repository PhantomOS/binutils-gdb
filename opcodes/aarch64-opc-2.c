/* This file is automatically generated by aarch64-gen.  Do not edit!  */
/* Copyright (C) 2012-2014 Free Software Foundation, Inc.
   Contributed by ARM Ltd.

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING3. If not,
   see <http://www.gnu.org/licenses/>.  */

#include "sysdep.h"
#include "aarch64-opc.h"


const struct aarch64_operand aarch64_operands[] =
{
  {AARCH64_OPND_CLASS_NIL, "", 0, {0}, "<none>"},
  {AARCH64_OPND_CLASS_INT_REG, "Rd", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rd}, "an integer register"},
  {AARCH64_OPND_CLASS_INT_REG, "Rn", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rn}, "an integer register"},
  {AARCH64_OPND_CLASS_INT_REG, "Rm", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rm}, "an integer register"},
  {AARCH64_OPND_CLASS_INT_REG, "Rt", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rt}, "an integer register"},
  {AARCH64_OPND_CLASS_INT_REG, "Rt2", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rt2}, "an integer register"},
  {AARCH64_OPND_CLASS_INT_REG, "Rs", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rs}, "an integer register"},
  {AARCH64_OPND_CLASS_INT_REG, "Ra", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Ra}, "an integer register"},
  {AARCH64_OPND_CLASS_INT_REG, "Rt_SYS", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rt}, "an integer register"},
  {AARCH64_OPND_CLASS_INT_REG, "Rd_SP", OPD_F_MAYBE_SP | OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rd}, "an integer or stack pointer register"},
  {AARCH64_OPND_CLASS_INT_REG, "Rn_SP", OPD_F_MAYBE_SP | OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rn}, "an integer or stack pointer register"},
  {AARCH64_OPND_CLASS_INT_REG, "PAIRREG", OPD_F_HAS_EXTRACTOR, {}, "the second reg of a pair"},
  {AARCH64_OPND_CLASS_MODIFIED_REG, "Rm_EXT", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "an integer register with optional extension"},
  {AARCH64_OPND_CLASS_MODIFIED_REG, "Rm_SFT", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "an integer register with optional shift"},
  {AARCH64_OPND_CLASS_FP_REG, "Fd", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rd}, "a floating-point register"},
  {AARCH64_OPND_CLASS_FP_REG, "Fn", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rn}, "a floating-point register"},
  {AARCH64_OPND_CLASS_FP_REG, "Fm", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rm}, "a floating-point register"},
  {AARCH64_OPND_CLASS_FP_REG, "Fa", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Ra}, "a floating-point register"},
  {AARCH64_OPND_CLASS_FP_REG, "Ft", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rt}, "a floating-point register"},
  {AARCH64_OPND_CLASS_FP_REG, "Ft2", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rt2}, "a floating-point register"},
  {AARCH64_OPND_CLASS_SISD_REG, "Sd", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rd}, "a SIMD scalar register"},
  {AARCH64_OPND_CLASS_SISD_REG, "Sn", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rn}, "a SIMD scalar register"},
  {AARCH64_OPND_CLASS_SISD_REG, "Sm", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rm}, "a SIMD scalar register"},
  {AARCH64_OPND_CLASS_SIMD_REG, "Vd", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rd}, "a SIMD vector register"},
  {AARCH64_OPND_CLASS_SIMD_REG, "Vn", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rn}, "a SIMD vector register"},
  {AARCH64_OPND_CLASS_SIMD_REG, "Vm", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rm}, "a SIMD vector register"},
  {AARCH64_OPND_CLASS_FP_REG, "VdD1", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rd}, "the top half of a 128-bit FP/SIMD register"},
  {AARCH64_OPND_CLASS_FP_REG, "VnD1", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rn}, "the top half of a 128-bit FP/SIMD register"},
  {AARCH64_OPND_CLASS_SIMD_ELEMENT, "Ed", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rd}, "a SIMD vector element"},
  {AARCH64_OPND_CLASS_SIMD_ELEMENT, "En", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rn}, "a SIMD vector element"},
  {AARCH64_OPND_CLASS_SIMD_ELEMENT, "Em", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rm}, "a SIMD vector element"},
  {AARCH64_OPND_CLASS_SIMD_REGLIST, "LVn", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rn}, "a SIMD vector register list"},
  {AARCH64_OPND_CLASS_SIMD_REGLIST, "LVt", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a SIMD vector register list"},
  {AARCH64_OPND_CLASS_SIMD_REGLIST, "LVt_AL", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a SIMD vector register list"},
  {AARCH64_OPND_CLASS_SIMD_REGLIST, "LEt", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a SIMD vector element list"},
  {AARCH64_OPND_CLASS_CP_REG, "Cn", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_CRn}, "a 4-bit opcode field named for historical reasons C0 - C15"},
  {AARCH64_OPND_CLASS_CP_REG, "Cm", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_CRm}, "a 4-bit opcode field named for historical reasons C0 - C15"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "IDX", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm4}, "an immediate as the index of the least significant byte"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "IMM_VLSL", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a left shift amount for an AdvSIMD register"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "IMM_VLSR", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a right shift amount for an AdvSIMD register"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "SIMD_IMM", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "an immediate"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "SIMD_IMM_SFT", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "an 8-bit unsigned immediate with optional shift"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "SIMD_FPIMM", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "an 8-bit floating-point constant"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "SHLL_IMM", OPD_F_HAS_EXTRACTOR, {}, "an immediate shift amount of 8, 16 or 32"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "IMM0", 0, {}, "0"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "FPIMM0", 0, {}, "0.0"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "FPIMM", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm8}, "an 8-bit floating-point constant"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "IMMR", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_immr}, "the right rotate amount"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "IMMS", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm6}, "the leftmost bit number to be moved from the source"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "WIDTH", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm6}, "the width of the bit-field"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "IMM", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm6}, "an immediate"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "UIMM3_OP1", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_op1}, "a 3-bit unsigned immediate"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "UIMM3_OP2", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_op2}, "a 3-bit unsigned immediate"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "UIMM4", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_CRm}, "a 4-bit unsigned immediate"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "UIMM7", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_CRm, FLD_op2}, "a 7-bit unsigned immediate"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "BIT_NUM", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_b5, FLD_b40}, "the bit number to be tested"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "EXCEPTION", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm16}, "a 16-bit unsigned immediate"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "CCMP_IMM", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm5}, "a 5-bit unsigned immediate"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "NZCV", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_nzcv}, "a flag bit specifier giving an alternative value for each flag"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "LIMM", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_N,FLD_immr,FLD_imms}, "Logical immediate"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "AIMM", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_shift,FLD_imm12}, "a 12-bit unsigned immediate with optional left shift of 12 bits"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "HALF", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm16}, "a 16-bit immediate with optional left shift"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "FBITS", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_scale}, "the number of bits after the binary point in the fixed-point value"},
  {AARCH64_OPND_CLASS_IMMEDIATE, "IMM_MOV", 0, {}, "an immediate"},
  {AARCH64_OPND_CLASS_COND, "COND", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a condition"},
  {AARCH64_OPND_CLASS_COND, "COND1", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "one of the standard conditions, excluding AL and NV."},
  {AARCH64_OPND_CLASS_ADDRESS, "ADDR_ADRP", OPD_F_SEXT | OPD_F_HAS_EXTRACTOR, {FLD_immhi, FLD_immlo}, "21-bit PC-relative address of a 4KB page"},
  {AARCH64_OPND_CLASS_ADDRESS, "ADDR_PCREL14", OPD_F_SEXT | OPD_F_SHIFT_BY_2 | OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm14}, "14-bit PC-relative address"},
  {AARCH64_OPND_CLASS_ADDRESS, "ADDR_PCREL19", OPD_F_SEXT | OPD_F_SHIFT_BY_2 | OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm19}, "19-bit PC-relative address"},
  {AARCH64_OPND_CLASS_ADDRESS, "ADDR_PCREL21", OPD_F_SEXT | OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_immhi,FLD_immlo}, "21-bit PC-relative address"},
  {AARCH64_OPND_CLASS_ADDRESS, "ADDR_PCREL26", OPD_F_SEXT | OPD_F_SHIFT_BY_2 | OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm26}, "26-bit PC-relative address"},
  {AARCH64_OPND_CLASS_ADDRESS, "ADDR_SIMPLE", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "an address with base register (no offset)"},
  {AARCH64_OPND_CLASS_ADDRESS, "ADDR_REGOFF", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "an address with register offset"},
  {AARCH64_OPND_CLASS_ADDRESS, "ADDR_SIMM7", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm7,FLD_index2}, "an address with 7-bit signed immediate offset"},
  {AARCH64_OPND_CLASS_ADDRESS, "ADDR_SIMM9", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm9,FLD_index}, "an address with 9-bit signed immediate offset"},
  {AARCH64_OPND_CLASS_ADDRESS, "ADDR_SIMM9_2", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_imm9,FLD_index}, "an address with 9-bit negative or unaligned immediate offset"},
  {AARCH64_OPND_CLASS_ADDRESS, "ADDR_UIMM12", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {FLD_Rn,FLD_imm12}, "an address with scaled, unsigned immediate offset"},
  {AARCH64_OPND_CLASS_ADDRESS, "SIMD_ADDR_SIMPLE", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "an address with base register (no offset)"},
  {AARCH64_OPND_CLASS_ADDRESS, "SIMD_ADDR_POST", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a post-indexed address with immediate or register increment"},
  {AARCH64_OPND_CLASS_SYSTEM, "SYSREG", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a system register"},
  {AARCH64_OPND_CLASS_SYSTEM, "PSTATEFIELD", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a PSTATE field name"},
  {AARCH64_OPND_CLASS_SYSTEM, "SYSREG_AT", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "an address translation operation specifier"},
  {AARCH64_OPND_CLASS_SYSTEM, "SYSREG_DC", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a data cache maintenance operation specifier"},
  {AARCH64_OPND_CLASS_SYSTEM, "SYSREG_IC", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "an instruction cache maintenance operation specifier"},
  {AARCH64_OPND_CLASS_SYSTEM, "SYSREG_TLBI", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a TBL invalidation operation specifier"},
  {AARCH64_OPND_CLASS_SYSTEM, "BARRIER", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a barrier option name"},
  {AARCH64_OPND_CLASS_SYSTEM, "BARRIER_ISB", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "the ISB option name SY or an optional 4-bit unsigned immediate"},
  {AARCH64_OPND_CLASS_SYSTEM, "PRFOP", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "a prefetch operation specifier"},
  {AARCH64_OPND_CLASS_SYSTEM, "BARRIER_PSB", OPD_F_HAS_INSERTER | OPD_F_HAS_EXTRACTOR, {}, "the PSB option name CSYNC"},
  {AARCH64_OPND_CLASS_NIL, "", 0, {0}, "DUMMY"},
};

/* Indexed by an enum aarch64_op enumerator, the value is the offset of
   the corresponding aarch64_opcode entry in the aarch64_opcode_table.  */

static const unsigned op_enum_table [] =
{
  0,
  720,
  721,
  722,
  725,
  726,
  727,
  728,
  729,
  723,
  724,
  730,
  731,
  753,
  754,
  755,
  758,
  759,
  760,
  761,
  762,
  756,
  757,
  763,
  764,
  807,
  808,
  809,
  810,
  12,
  519,
  520,
  1002,
  1004,
  1006,
  814,
  1005,
  1003,
  261,
  507,
  518,
  517,
  812,
  514,
  511,
  503,
  502,
  509,
  510,
  513,
  515,
  516,
  822,
  535,
  538,
  541,
  536,
  539,
  664,
  162,
  163,
  164,
  165,
  426,
  605,
  318,
  320,
  340,
  342,
};

/* Given the opcode enumerator OP, return the pointer to the corresponding
   opcode entry.  */

const aarch64_opcode *
aarch64_get_opcode (enum aarch64_op op)
{
  return aarch64_opcode_table + op_enum_table[op];
}
