#include <signal.h>
#include "v850_sim.h"
#include "simops.h"
#include "sys/syscall.h"

/* sld.b */
void
OP_300 ()
{
  unsigned int op2;
  int result, temp;

  temp = OP[1];
  temp = (temp << 25) >> 25;
  op2 = temp;
  result = get_byte (State.mem + State.regs[30] + op2);
  result = (result << 24) >> 24;
  State.regs[OP[0]] = result;
}

/* sld.h */
void
OP_400 ()
{
  unsigned int op2;
  int result, temp;

  temp = OP[1];
  temp = (temp << 25) >> 25;
  op2 = temp << 1;
  result = get_half (State.mem + State.regs[30] + op2);
  result = (result << 16) >> 16;
  State.regs[OP[0]] = result;
}

/* sld.w */
void
OP_500 ()
{
  unsigned int op2;
  int result, temp;

  temp = OP[1];
  temp = (temp << 25) >> 25;
  op2 = temp << 2;
  result = get_word (State.mem + State.regs[30] + op2);
  State.regs[OP[0]] = result;
}

/* sst.b */
void
OP_380 ()
{
  unsigned int op0, op1;
  int temp;

  op0 = State.regs[OP[0]];
  temp = OP[1];
  temp = (temp << 25) >> 25;
  op1 = temp;
  put_byte (State.mem + State.regs[30] + op1, op0);
}

/* sst.h */
void
OP_480 ()
{
  unsigned int op0, op1;
  int temp;

  op0 = State.regs[OP[0]];
  temp = OP[1];
  temp = (temp << 25) >> 25;
  op1 = temp << 1;
  put_half (State.mem + State.regs[30] + op1, op0);
}

/* sst.w */
void
OP_501 ()
{
  unsigned int op0, op1;
  int temp;

  op0 = State.regs[OP[0]];
  temp = OP[1];
  temp = (temp << 25) >> 25;
  op1 = temp << 2;
  put_word (State.mem + State.regs[30] + op1, op0);
}

/* ld.b */
void
OP_700 ()
{
  unsigned int op0, op2;
  int result, temp;

  op0 = State.regs[OP[0]];
  temp = OP[2];
  temp = (temp << 16) >> 16;
  op2 = temp;
  result = get_byte (State.mem + op0 + op2);
  result = (result << 24) >> 24;
  State.regs[OP[1]] = result;
}

/* ld.h */
void
OP_720 ()
{
  unsigned int op0, op2;
  int result, temp;

  op0 = State.regs[OP[0]];
  temp = OP[2];
  temp = (temp << 16) >> 16;
  temp &= ~0x1;
  op2 = temp;
  result = get_half (State.mem + op0 + op2);
  result = (result << 16) >> 16;
  State.regs[OP[1]] = result;
}

/* ld.w */
void
OP_10720 ()
{
  unsigned int op0,  op2;
  int result, temp;

  op0 = State.regs[OP[0]];
  temp = OP[2];
  temp = (temp << 16) >> 16;
  temp &= ~0x1;
  op2 = temp;
  result = get_word (State.mem + op0 + op2);
  State.regs[OP[1]] = result;
}

/* st.b */
void
OP_740 ()
{
  unsigned int op0, op1, op2;
  int temp;

  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  temp = OP[2];
  temp = (temp << 16) >> 16;
  op2 = temp;
  put_byte (State.mem + op0 + op2, op1);
}

/* st.h */
void
OP_760 ()
{
  unsigned int op0, op1, op2;
  int temp;

  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  temp = OP[2];
  temp &= ~0x1;
  temp = (temp << 16) >> 16;
  op2 = temp;
  put_half (State.mem + op0 + op2, op1);
}

/* st.w */
void
OP_10760 ()
{
  unsigned int op0, op1, op2;
  int temp;

  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  temp = OP[2];
  temp &= ~0x1;
  temp = (temp << 16) >> 16;
  op2 = temp;
  put_word (State.mem + op0 + op2, op1);
}

/* bv disp9 */
void
OP_580 ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((psw & PSW_OV) != 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* bl disp9 */
void
OP_581 ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((psw & PSW_CY) != 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* be disp9 */
void
OP_582 ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((psw & PSW_Z) != 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* bnh disp 9*/
void
OP_583 ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((((psw & PSW_CY) != 0) | ((psw & PSW_Z) != 0)) != 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* bn disp9 */
void
OP_584 ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((psw & PSW_S) != 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* br disp9 */
void
OP_585 ()
{
  unsigned int op0;

  op0 = ((signed)OP[0] << 23) >> 23;
  State.pc += op0;
}

/* blt disp9 */
void
OP_586 ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((((psw & PSW_S) != 0) ^ ((psw & PSW_OV) != 0)) != 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* ble disp9 */
void
OP_587 ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((((psw & PSW_Z) != 0)
       || (((psw & PSW_S) != 0) ^ ((psw & PSW_OV) != 0))) != 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* bnv disp9 */
void
OP_588 ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((psw & PSW_OV) == 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* bnl disp9 */
void
OP_589 ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((psw & PSW_CY) == 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* bne disp9 */
void
OP_58A ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((psw & PSW_Z) == 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* bh disp9 */
void
OP_58B ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((((psw & PSW_CY) != 0) | ((psw & PSW_Z) != 0)) == 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* bp disp9 */
void
OP_58C ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((psw & PSW_S) == 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* bsa disp9 */
void
OP_58D ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((psw & PSW_SAT) != 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* bge disp9 */
void
OP_58E ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((((psw & PSW_S) != 0) ^ ((psw & PSW_OV) != 0)) == 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* bgt disp9 */
void
OP_58F ()
{
  unsigned int op0, psw;

  op0 = ((signed)OP[0] << 23) >> 23;
  psw = State.sregs[5];
  
  if ((((psw & PSW_Z) != 0)
       || (((psw & PSW_S) != 0) ^ ((psw & PSW_OV) != 0))) == 0)
    State.pc += op0;
  else
    State.pc += 2;
}

/* jmp [reg1] */
void
OP_60 ()
{
  /* interp.c will bump this by +2, so correct for it here.  */
  State.pc = State.regs[OP[0]] - 2;
}

/* jarl disp22, reg */
void
OP_780 ()
{
  unsigned int op0, opc;
  int temp;

  temp = OP[0];
  temp = (temp << 10) >> 10;
  op0 = temp;
  opc = State.pc;

  State.pc += temp;

  /* Gross.  jarl X,r0 is really jr and doesn't save its result.  */
  if (OP[1] != 0)
    State.regs[OP[1]] = opc + 4;
}

/* add reg, reg */
void
OP_1C0 ()
{
  unsigned int op0, op1, result, z, s, cy, ov;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  result = op0 + op1;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (result < op0 || result < op1);
  ov = ((op0 & 0x80000000) == (op1 & 0x80000000)
	&& (op0 & 0x80000000) != (result & 0x80000000));

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		     | (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0));
}

/* add sign_extend(imm5), reg */
void
OP_240 ()
{
  unsigned int op0, op1, result, z, s, cy, ov;
  int temp;

  /* Compute the result.  */
  temp = (OP[0] & 0x1f);
  temp = (temp << 27) >> 27;
  op0 = temp;
  op1 = State.regs[OP[1]];
  result = op0 + op1;
  
  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (result < op0 || result < op1);
  ov = ((op0 & 0x80000000) == (op1 & 0x80000000)
	&& (op0 & 0x80000000) != (result & 0x80000000));

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0));
}

/* addi sign_extend(imm16), reg, reg */
void
OP_600 ()
{
  unsigned int op0, op1, result, z, s, cy, ov;
  int temp;

  /* Compute the result.  */
  temp = (OP[0] & 0xffff);
  temp = (temp << 16) >> 16;
  op0 = temp;
  op1 = State.regs[OP[1]];
  result = op0 + op1;
  
  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (result < op0 || result < op1);
  ov = ((op0 & 0x80000000) == (op1 & 0x80000000)
	&& (op0 & 0x80000000) != (result & 0x80000000));

  /* Store the result and condition codes.  */
  State.regs[OP[2]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0));
}

/* sub reg1, reg2 */
void
OP_1A0 ()
{
  unsigned int op0, op1, result, z, s, cy, ov;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  result = op1 - op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op1 < op0);
  ov = ((op1 & 0x80000000) != (op0 & 0x80000000)
	&& (op1 & 0x80000000) != (result & 0x80000000));

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0));
}

/* subr reg1, reg2 */
void
OP_180 ()
{
  unsigned int op0, op1, result, z, s, cy, ov;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  result = op0 - op1;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op0 < op1);
  ov = ((op0 & 0x80000000) != (op1 & 0x80000000)
	&& (op0 & 0x80000000) != (result & 0x80000000));

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0));
}

/* mulh reg1, reg2 */
void
OP_E0 ()
{
  State.regs[OP[1]] = ((State.regs[OP[1]] & 0xffff)
		       * (State.regs[OP[0]] & 0xffff));
}

/* mulh sign_extend(imm5), reg2

   Condition codes */
void
OP_2E0 ()
{
  int value = OP[0];
 
  value = (value << 27) >> 27;

  State.regs[OP[1]] = (State.regs[OP[1]] & 0xffff) * value;
}

/* mulhi imm16, reg1, reg2 */
void
OP_6E0 ()
{
  int value = OP[0];
 
  value = value & 0xffff;

  State.regs[OP[2]] = (State.regs[OP[1]] & 0xffff) * value;
}

/* divh reg1, reg2 */
void
OP_40 ()
{
  unsigned int op0, op1, result, ov, s, z;
  int temp;

  /* Compute the result.  */
  temp = State.regs[OP[0]] & 0xffff;
  temp = (temp << 16) >> 16;
  op0 = temp;
  op1 = State.regs[OP[1]];

  if (op0 == 0xffffffff && op1 == 0x80000000)
    {
      result = 0x80000000;
      ov = 1;
    }
  else if (op0 != 0)
    {
      result = op1 / op0;
      ov = 0;
    }
  else
    {
      result = 0x0;
      ov = 1;
    }

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (ov ? PSW_OV : 0));
}

/* cmp reg, reg */
void
OP_1E0 ()
{
  unsigned int op0, op1, result, z, s, cy, ov;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  result = op1 - op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op1 < op0);
  ov = ((op1 & 0x80000000) != (op0 & 0x80000000)
	&& (op1 & 0x80000000) != (result & 0x80000000));

  /* Set condition codes.  */
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0));
}

/* cmp sign_extend(imm5), reg */
void
OP_260 ()
{
  unsigned int op0, op1, result, z, s, cy, ov;
  int temp;

  /* Compute the result.  */
  temp = OP[0];
  temp = (temp << 27) >> 27;
  op0 = temp;
  op1 = State.regs[OP[1]];
  result = op1 - op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op1 < op0);
  ov = ((op1 & 0x80000000) != (op0 & 0x80000000)
	&& (op1 & 0x80000000) != (result & 0x80000000));

  /* Set condition codes.  */
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0));
}

/* setf cccc,reg2 */
void
OP_7E0 ()
{
  /* Hack alert.  We turn off a bit in op0 since we really only
     wanted 4 bits.  */
  unsigned int op0, psw, result = 0;

  op0 = OP[0] & 0xf;
  psw = State.sregs[5];

  switch (op0)
    {
      case 0x0:
	result = ((psw & PSW_OV) != 0);
	break;
      case 0x1:
	result = ((psw & PSW_CY) != 0);
	break;
      case 0x2:
	result = ((psw & PSW_Z) != 0);
	break;
      case 0x3:
	result = ((((psw & PSW_CY) != 0) | ((psw & PSW_Z) != 0)) != 0);
	break;
      case 0x4:
	result = ((psw & PSW_S) != 0);
	break;
      case 0x5:
	result = 1;
	break;
      case 0x6:
	result = ((((psw & PSW_S) != 0) ^ ((psw & PSW_OV) != 0)) != 0);
	break;
      case 0x7:
	result = (((((psw & PSW_S) != 0) ^ ((psw & PSW_OV) != 0))
		  || ((psw & PSW_Z) != 0)) != 0);
	break;
      case 0x8:
	result = ((psw & PSW_OV) == 0);
	break;
      case 0x9:
	result = ((psw & PSW_CY) == 0);
	break;
      case 0xa:
	result = ((psw & PSW_Z) == 0);
	break;
      case 0xb:
	result = ((((psw & PSW_CY) != 0) | ((psw & PSW_Z) != 0)) == 0);
	break;
      case 0xc:
	result = ((psw & PSW_S) == 0);
	break;
      case 0xd:
	result = ((psw & PSW_SAT) != 0);
	break;
      case 0xe:
	result = ((((psw & PSW_S) != 0) ^ ((psw & PSW_OV) != 0)) == 0);
	break;
      case 0xf:
	result = (((((psw & PSW_S) != 0) ^ ((psw & PSW_OV) != 0))
		  || ((psw & PSW_Z) != 0)) == 0);
	break;
    }
  
  State.regs[OP[1]] = result;
}

/* satadd reg,reg */
void
OP_C0 ()
{
  unsigned int op0, op1, result, z, s, cy, ov, sat;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  result = op0 + op1;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (result < op0 || result < op1);
  ov = ((op0 & 0x80000000) == (op1 & 0x80000000)
	&& (op0 & 0x80000000) != (result & 0x80000000));
  sat = ov;

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0)
		| (sat ? PSW_SAT : 0));

  /* Handle saturated results.  */
  if (sat && s)
    State.regs[OP[1]] = 0x80000000;
  else if (sat)
    State.regs[OP[1]] = 0x7fffffff;
}

/* satadd sign_extend(imm5), reg */
void
OP_220 ()
{
  unsigned int op0, op1, result, z, s, cy, ov, sat;

  int temp;

  /* Compute the result.  */
  temp = (OP[0] & 0x1f);
  temp = (temp << 27) >> 27;
  op0 = temp;
  op1 = State.regs[OP[1]];
  result = op0 + op1;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (result < op0 || result < op1);
  ov = ((op0 & 0x80000000) == (op1 & 0x80000000)
	&& (op0 & 0x80000000) != (result & 0x80000000));
  sat = ov;

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0)
		| (sat ? PSW_SAT : 0));

  /* Handle saturated results.  */
  if (sat && s)
    State.regs[OP[1]] = 0x80000000;
  else if (sat)
    State.regs[OP[1]] = 0x7fffffff;
}

/* satsub reg1, reg2 */
void
OP_A0 ()
{
  unsigned int op0, op1, result, z, s, cy, ov, sat;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  result = op1 - op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op1 < op0);
  ov = ((op1 & 0x80000000) != (op0 & 0x80000000)
	&& (op1 & 0x80000000) != (result & 0x80000000));
  sat = ov;

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0)
		| (sat ? PSW_SAT : 0));

  /* Handle saturated results.  */
  if (sat && s)
    State.regs[OP[1]] = 0x80000000;
  else if (sat)
    State.regs[OP[1]] = 0x7fffffff;
}

/* satsubi sign_extend(imm16), reg */
void
OP_660 ()
{
  unsigned int op0, op1, result, z, s, cy, ov, sat;
  int temp;

  /* Compute the result.  */
  temp = (OP[0] & 0xffff);
  temp = (temp << 16) >> 16;
  op0 = temp;
  op1 = State.regs[OP[1]];
  result = op1 - op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op1 < op0);
  ov = ((op1 & 0x80000000) != (op0 & 0x80000000)
	&& (op1 & 0x80000000) != (result & 0x80000000));
  sat = ov;

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0)
		| (sat ? PSW_SAT : 0));

  /* Handle saturated results.  */
  if (sat && s)
    State.regs[OP[1]] = 0x80000000;
  else if (sat)
    State.regs[OP[1]] = 0x7fffffff;
}

void
OP_80 ()
{
  unsigned int op0, op1, result, z, s, cy, ov, sat;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  result = op0 - op1;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (result < op0);
  ov = ((op1 & 0x80000000) != (op0 & 0x80000000)
	&& (op1 & 0x80000000) != (result & 0x80000000));
  sat = ov;

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_CY | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0) | (ov ? PSW_OV : 0)
		| (sat ? PSW_SAT : 0));

  /* Handle saturated results.  */
  if (sat && s)
    State.regs[OP[1]] = 0x80000000;
  else if (sat)
    State.regs[OP[1]] = 0x7fffffff;
}

/* tst reg,reg */
void
OP_160 ()
{
  unsigned int op0, op1, result, z, s;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  result = op0 & op1;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);

  /* Store the condition codes.  */
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0));
}

/* mov reg, reg */
void
OP_0 ()
{
  State.regs[OP[1]] = State.regs[OP[0]];
}

/* mov sign_extend(imm5), reg */
void
OP_200 ()
{
  int value = OP[0];
 
  value = (value << 27) >> 27;
  State.regs[OP[1]] = value;
}

/* movea sign_extend(imm16), reg, reg  */

void
OP_620 ()
{
  int value = OP[0];
 
  value = (value << 16) >> 16;

  State.regs[OP[2]] = State.regs[OP[1]] + value;
}

/* movhi imm16, reg, reg */
void
OP_640 ()
{
  int value = OP[0];
 
  value = (value & 0xffff) << 16; 

  State.regs[OP[2]] = State.regs[OP[1]] + value;
}

/* sar zero_extend(imm5),reg1 */
void
OP_2A0 ()
{
  unsigned int op0, op1, result, z, s, cy;

  op0 = OP[0] & 0x1f;
  op1 = State.regs[OP[1]];
  result = (signed)op1 >> op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op1 & (1 << (op0 - 1)));

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV | PSW_CY);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0));
}

/* sar reg1, reg2 */
void
OP_A007E0 ()
{
  unsigned int op0, op1, result, z, s, cy;

  op0 = State.regs[OP[0]] & 0x1f;
  op1 = State.regs[OP[1]];
  result = (signed)op1 >> op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op1 & (1 << (op0 - 1)));

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV | PSW_CY);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0));
}

/* shl zero_extend(imm5),reg1 */
void
OP_2C0 ()
{
  unsigned int op0, op1, result, z, s, cy;

  op0 = OP[0] & 0x1f;
  op1 = State.regs[OP[1]];
  result = op1 << op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op1 & (1 << (32 - op0)));

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV | PSW_CY);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0));
}

/* shl reg1, reg2 */
void
OP_C007E0 ()
{
  unsigned int op0, op1, result, z, s, cy;

  op0 = State.regs[OP[0]] & 0x1f;
  op1 = State.regs[OP[1]];
  result = op1 << op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op1 & (1 << (32 - op0)));

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV | PSW_CY);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0));
}

/* shr zero_extend(imm5),reg1 */
void
OP_280 ()
{
  unsigned int op0, op1, result, z, s, cy;

  op0 = OP[0] & 0x1f;
  op1 = State.regs[OP[1]];
  result = op1 >> op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op1 & (1 << (op0 - 1)));

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV | PSW_CY);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0));
}

/* shr reg1, reg2 */
void
OP_8007E0 ()
{
  unsigned int op0, op1, result, z, s, cy;

  op0 = State.regs[OP[0]] & 0x1f;
  op1 = State.regs[OP[1]];
  result = op1 >> op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);
  cy = (op1 & (1 << (op0 - 1)));

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV | PSW_CY);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0)
		| (cy ? PSW_CY : 0));
}

/* or reg, reg */
void
OP_100 ()
{
  unsigned int op0, op1, result, z, s;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  result = op0 | op1;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0));
}

/* ori zero_extend(imm16), reg, reg */
void
OP_680 ()
{
  unsigned int op0, op1, result, z, s;

  op0 = OP[0] & 0xffff;
  op1 = State.regs[OP[1]];
  result = op0 | op1;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);

  /* Store the result and condition codes.  */
  State.regs[OP[2]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0));
}

/* and reg, reg */
void
OP_140 ()
{
  unsigned int op0, op1, result, z, s;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  result = op0 & op1;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0));
}

/* andi zero_extend(imm16), reg, reg */
void
OP_6C0 ()
{
  unsigned int op0, op1, result, z;

  op0 = OP[0] & 0xffff;
  op1 = State.regs[OP[1]];
  result = op0 & op1;

  /* Compute the condition codes.  */
  z = (result == 0);

  /* Store the result and condition codes.  */
  State.regs[OP[2]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV);
  State.sregs[5] |= (z ? PSW_Z : 0);
}

/* xor reg, reg */
void
OP_120 ()
{
  unsigned int op0, op1, result, z, s;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  op1 = State.regs[OP[1]];
  result = op0 ^ op1;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0));
}

/* xori zero_extend(imm16), reg, reg */
void
OP_6A0 ()
{
  unsigned int op0, op1, result, z, s;

  op0 = OP[0] & 0xffff;
  op1 = State.regs[OP[1]];
  result = op0 ^ op1;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);

  /* Store the result and condition codes.  */
  State.regs[OP[2]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0));
}

/* not reg1, reg2 */
void
OP_20 ()
{
  unsigned int op0, result, z, s;

  /* Compute the result.  */
  op0 = State.regs[OP[0]];
  result = ~op0;

  /* Compute the condition codes.  */
  z = (result == 0);
  s = (result & 0x80000000);

  /* Store the result and condition codes.  */
  State.regs[OP[1]] = result;
  State.sregs[5] &= ~(PSW_Z | PSW_S | PSW_OV);
  State.sregs[5] |= ((z ? PSW_Z : 0) | (s ? PSW_S : 0));
}

/* set1 */
void
OP_7C0 ()
{
  unsigned int op0, op1, op2;
  int temp;

  op0 = State.regs[OP[0]];
  op1 = OP[1] & 0x7;
  temp = OP[2];
  temp = (temp << 16) >> 16;
  op2 = temp;
  temp = get_byte (State.mem + op0 + op2);
  State.sregs[5] &= ~PSW_Z;
  if ((temp & (1 << op1)) == 0)
    State.sregs[5] |= PSW_Z;
  temp |= (1 << op1);
  put_byte (State.mem + op0 + op2, temp);
}

/* not1 */
void
OP_47C0 ()
{
  unsigned int op0, op1, op2;
  int temp;

  op0 = State.regs[OP[0]];
  op1 = OP[1] & 0x7;
  temp = OP[2];
  temp = (temp << 16) >> 16;
  op2 = temp;
  temp = get_byte (State.mem + op0 + op2);
  State.sregs[5] &= ~PSW_Z;
  if ((temp & (1 << op1)) == 0)
    State.sregs[5] |= PSW_Z;
  temp ^= (1 << op1);
  put_byte (State.mem + op0 + op2, temp);
}

/* clr1 */
void
OP_87C0 ()
{
  unsigned int op0, op1, op2;
  int temp;

  op0 = State.regs[OP[0]];
  op1 = OP[1] & 0x7;
  temp = OP[2];
  temp = (temp << 16) >> 16;
  op2 = temp;
  temp = get_byte (State.mem + op0 + op2);
  State.sregs[5] &= ~PSW_Z;
  if ((temp & (1 << op1)) == 0)
    State.sregs[5] |= PSW_Z;
  temp &= ~(1 << op1);
  put_byte (State.mem + op0 + op2, temp);
}

/* tst1 */
void
OP_C7C0 ()
{
  unsigned int op0, op1, op2;
  int temp;

  op0 = State.regs[OP[0]];
  op1 = OP[1] & 0x7;
  temp = OP[2];
  temp = (temp << 16) >> 16;
  op2 = temp;
  temp = get_byte (State.mem + op0 + op2);
  State.sregs[5] &= ~PSW_Z;
  if ((temp & (1 << op1)) == 0)
    State.sregs[5] |= PSW_Z;
}

/* di */
void
OP_16007E0 ()
{
  State.sregs[5] |= PSW_ID;
}

/* ei */
void
OP_16087E0 ()
{
  State.sregs[5] &= ~PSW_ID;
}

/* halt, not supported */
void
OP_12007E0 ()
{
  State.exception = SIGQUIT;
}

/* reti, not supported */
void
OP_14007E0 ()
{
  abort ();
}

/* trap, not supportd */
void
OP_10007E0 ()
{
  extern int errno;

  /* Trap 0 is used for simulating low-level I/O */

  if (OP[0] == 0)
    {
      int save_errno = errno;	
      errno = 0;

/* Registers passed to trap 0 */

#define FUNC   State.regs[6]	/* function number, return value */
#define PARM1  State.regs[7]	/* optional parm 1 */
#define PARM2  State.regs[8]	/* optional parm 2 */
#define PARM3  State.regs[9]	/* optional parm 3 */

/* Registers set by trap 0 */

#define RETVAL State.regs[10]	/* return value */
#define RETERR State.regs[11]	/* return error code */

/* Turn a pointer in a register into a pointer into real memory. */

#define MEMPTR(x) ((char *)((x) + State.mem))


      switch (FUNC)
	{
#if !defined(__GO32__) && !defined(_WIN32)
	case SYS_fork:
	  RETVAL = fork ();
	  break;
	case SYS_execve:
	  RETVAL = execve (MEMPTR (PARM1), (char **) MEMPTR (PARM2),
			   (char **)MEMPTR (PARM3));
	  break;
	case SYS_execv:
	  RETVAL = execve (MEMPTR (PARM1), (char **) MEMPTR (PARM2), NULL);
	  break;
#if 0
	case SYS_pipe:
	  {
	    reg_t buf;
	    int host_fd[2];

	    buf = PARM1;
	    RETVAL = pipe (host_fd);
	    SW (buf, host_fd[0]);
	    buf += sizeof(uint16);
	    SW (buf, host_fd[1]);
	  }
	  break;

	case SYS_wait:
	  {
	    int status;

	    RETVAL = wait (&status);
	    SW (PARM1, status);
	  }
	  break;
#endif
#endif

	case SYS_read:
	  RETVAL = v850_callback->read (v850_callback, PARM1, MEMPTR (PARM2),
					PARM3);
	  break;
	case SYS_write:
	  if (PARM1 == 1)
	    RETVAL = (int)v850_callback->write_stdout (v850_callback,
				 		       MEMPTR (PARM2), PARM3);
	  else
	    RETVAL = (int)v850_callback->write (v850_callback, PARM1,
						MEMPTR (PARM2), PARM3);
	  break;
	case SYS_lseek:
	  RETVAL = v850_callback->lseek (v850_callback, PARM1, PARM2, PARM3);
	  break;
	case SYS_close:
	  RETVAL = v850_callback->close (v850_callback, PARM1);
	  break;
	case SYS_open:
	  RETVAL = v850_callback->open (v850_callback, MEMPTR (PARM1), PARM2);
	  break;
	case SYS_exit:
	  /* EXIT - caller can look in PARM1 to work out the 
	     reason */
	  if (PARM1 == 0xdead || PARM1 == 0x1)
	    State.exception = SIGABRT;
	  else
	    State.exception = SIGQUIT;
	  break;

#if 0
	case SYS_stat:	/* added at hmsi */
	  /* stat system call */
	  {
	    struct stat host_stat;
	    reg_t buf;

	    RETVAL = stat (MEMPTR (PARM1), &host_stat);

	    buf = PARM2;

	    /* The hard-coded offsets and sizes were determined by using
	     * the D10V compiler on a test program that used struct stat.
	     */
	    SW  (buf,    host_stat.st_dev);
	    SW  (buf+2,  host_stat.st_ino);
	    SW  (buf+4,  host_stat.st_mode);
	    SW  (buf+6,  host_stat.st_nlink);
	    SW  (buf+8,  host_stat.st_uid);
	    SW  (buf+10, host_stat.st_gid);
	    SW  (buf+12, host_stat.st_rdev);
	    SLW (buf+16, host_stat.st_size);
	    SLW (buf+20, host_stat.st_atime);
	    SLW (buf+28, host_stat.st_mtime);
	    SLW (buf+36, host_stat.st_ctime);
	  }
#endif
	  break;

	case SYS_chown:
	  RETVAL = chown (MEMPTR (PARM1), PARM2, PARM3);
	  break;
	case SYS_chmod:
	  RETVAL = chmod (MEMPTR (PARM1), PARM2);
	  break;
	case SYS_utime:
	  /* Cast the second argument to void *, to avoid type mismatch
	     if a prototype is present.  */
	  RETVAL = utime (MEMPTR (PARM1), (void *) MEMPTR (PARM2));
	  break;
	default:
	  abort ();
	}
      RETERR = errno;
      errno = save_errno;
    }
  else if (OP[0] == 1 )
    {
      char *fstr = State.regs[2] + State.mem;
      puts (fstr);
    }
}

/* ldsr, reg,reg */
void
OP_2007E0 ()
{
  unsigned int op0;

  op0 = State.regs[OP[0]];
  State.sregs[OP[1]] = op0;
}

/* stsr, not supported */
void
OP_4007E0 ()
{
  unsigned int op0;

  op0 = State.sregs[OP[1]];
  State.regs[OP[0]] = op0;
}

