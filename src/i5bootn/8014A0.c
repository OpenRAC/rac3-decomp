#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 8010A8.c's earlier functions (tools/port_from_us.py) */
extern int func_00801080(void);
extern void func_00801090(void);
extern void func_00801138(void);

/* localdecomp:start func_008014A0 */
/* Sony 2.9-ee library code: SIO putc, waits for room in the transmit FIFO and writes one byte.
   Retail has the byte store in the jr delay slot. The original store was most likely volatile
   and moved there by the assembler (binutils 2.10 swaps it; none of this project's assemblers
   do). A plain store that gcc's own delay-slot pass can move matches instead; the empty asm
   keeps the address in a register (lui/ori + sb 0(reg)) instead of folding it into the store. */
int func_008014A0(int c) {
    unsigned char *p;
    while (*(volatile unsigned int *)0x1000F130 & 0x8000)
        ;
    p = (unsigned char *)0x1000F180;
    __asm__("" : "+r"(p));
    *p = c;
    return c;
}
/* localdecomp:end func_008014A0 */

/* localdecomp:start func_008014D8 */
/* Sony 2.9-ee library code: SIO putc that turns '\n' into "\r\n" (func_008014A0 writes one byte). */
extern int func_008014A0(int);
void func_008014D8(int c) {
    if (c == '\n') {
        func_008014A0('\r');
        func_008014A0('\n');
    } else {
        func_008014A0(c);
    }
}
/* localdecomp:end func_008014D8 */
