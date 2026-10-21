/* US draft of func_0038E150 (rac3-uya-decomp func_00389920, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_0038E150 */
extern s32 D_001D55D0[];
extern s32 D_001D55D8[];
extern s32 D_001D55E0[];
extern s32 D_001D55C0;
extern s32 D_001D55C4_0038E150;
extern s32 D_001D55C8;
extern u8 D_0031CF50[];
extern u8 D_0031CFD0[];
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D55E8;
__asm__(".extern D_001D55D0, 16");
__asm__(".extern D_001D55D8, 16");
__asm__(".extern D_001D55E0, 16");
__asm__(".extern D_001D55C0, 16");
__asm__(".extern D_001D55C4_0038E150, 16");
__asm__(".extern D_001D55C8, 16");
__asm__(".extern D_0031CF50, 16");
__asm__(".extern D_0031CFD0, 16");
void func_0038E150(s32 index) {
    register s32 offset __asm__("$2") = index << 2;
    register s32 *table0 __asm__("$7");
    register s32 *table2 __asm__("$8");
    register s32 *table1 __asm__("$3");
    register s32 *ptr1 __asm__("$2");
    register s32 offset64 __asm__("$5");
    register u8 *out1 __asm__("$3");
    register u8 *out0 __asm__("$6");
    register s32 value1 __asm__("$10");
    register s32 value0 __asm__("$9");
    register s32 value2 __asm__("$2");
    __asm__ volatile("" : "+r"(offset));
    table0 = D_001D55D0;
    __asm__ volatile("" : "+r"(table0));
    table2 = D_001D55E0;
    __asm__ volatile("" : "+r"(table2));
    table1 = D_001D55D8;
    __asm__ volatile("" : "+r"(table1));
    table0 = (s32 *)(offset + (s32)table0);
    __asm__ volatile("" : "+r"(table0));
    table2 = (s32 *)(offset + (s32)table2);
    __asm__ volatile("" : "+r"(table2));
    ptr1 = (s32 *)(offset + (s32)table1);
    __asm__ volatile("" : "+r"(ptr1));
    offset64 = index << 6;
    __asm__ volatile("" : "+r"(offset64));
    out1 = (u8 *)0x320000;
    __asm__ volatile("" : "+r"(out1));
    value1 = *ptr1;
    __asm__ volatile("" : "+r"(value1));
    out0 = (u8 *)0x320000;
    __asm__ volatile("" : "+r"(out0));
    out1 -= 0x6FF0;
    value0 = *table0;
    out1 = (u8 *)(offset64 + (s32)out1);
    __asm__ volatile("" : "+r"(out1));
    value2 = *table2;
    __asm__ volatile("" : "+r"(value2));
    out0 -= 0x7070;
    offset64 += (s32)out0;
    __asm__ volatile("" : "+r"(offset64));
    D_001D55C0 = value0;
    D_001D55C4_0038E150 = value1;
    D_001D55C8 = value2;
    D_001D5B38 = (u8 *)offset64;
    D_001D5B3C = out1;
    D_001D55E8 = index;
}
/* localdecomp:end func_0038E150 */
