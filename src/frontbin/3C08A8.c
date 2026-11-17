#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003BDD38();
extern void func_003BE308();
extern void func_003BDF60();
extern s32 func_003BDD38(void);
extern void func_003BE308(void *);
extern s32 D_001D8E30;
extern void func_003BF860();


/* US draft of func_003C08A8 (rac3-uya-decomp func_003BB398, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C08A8 */
/* The flag pair at 0x1DA344: retail reaches both bytes with `lui` (the assembler's
   expansion), so the pair is declared sized (gcc leaves the accesses to the assembler as
   macros) with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md). The first byte's store stays a literal address: as a plain symbol gcc counts
   it as one instruction and moves it into the following branch's delay slot, where retail
   (and gcc, for a constant address) keeps the two-instruction `lui $at` store before it. */
extern u8 D_001DA344_003C08A8[2];
__asm__(".extern D_001DA344_003C08A8, 16");
__asm__(".extern D_001DA338_003C08A8, 16");
extern s32 D_001DA338_003C08A8;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 f40; } T_3BB398;
extern T_3BB398 D_00225700[];
extern void func_003BC768();
extern void func_003BE168();
extern void func_003BB968();
extern void func_003BDE60();
extern void func_003BDF40();
extern void func_003BFE58();
extern s32 func_003BDF10();
extern s32 func_003BDF18();
u8 func_003BDBF8(void);
s32 func_003C08A8(s32 a) {
    s32 r = 0;
    s32 arg;
    u8 t;
    s32 v;
    v = func_003BDBF8();
    *(u8 *)0x1DA344 = v;
    if ((v & 0xFF) != 0) {
        func_003BC768();
        if (func_003BDF10() == 1) func_003BE168();
        if (func_003BDF10() > 0 && func_003BDF18() != 0) func_003BB968();
        t = D_001DA344_003C08A8[1];
        if (a) { if (t != 0) r = 1; }
        if (t == 0) {
            if (func_003BDF10() > 0 && a) {
                arg = D_001D8E30;
                D_001DA344_003C08A8[1] = 1;
            } else {
                arg = func_003BDD38();
            }
            func_003BDE60(arg);
            func_003BDF40();
            func_003BF8C0();
            func_003BFE58();
            func_003BE308(func_003BF860);
        }
    }
    func_003BDF60(D_00225700[0].f34, D_00225700[0].f40, 12, 12);
    D_001DA338_003C08A8 = D_001DA338_003C08A8 + 1;
    return r;
}
/* localdecomp:end func_003C08A8 */

/* localdecomp:start func_003C09E8 */
extern void func_003A8450();
extern s32 func_003BF848(void);
extern void func_003BFEB0(void *);
extern void func_003C03A8(void *);
void func_003C09E8(void *p) {
    func_003A8450(p);
    if (func_003BF848()) func_003BFEB0(p);
    func_003C03A8(p);
}
/* localdecomp:end func_003C09E8 */

/* localdecomp:start func_003C0A30 */
extern void func_003BDF40();
extern void func_003BC768();
extern void func_003BFE58();
 
void func_003C0A30(void) {
    func_003BDF40();
    func_003BC768();
    func_003BFE58();
    func_003BF8C0();
}
/* localdecomp:end func_003C0A30 */

/* US draft of func_003C0A68 (rac3-uya-decomp func_003BB558, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C0A68 */
typedef struct { u8 pad[0x40]; s32 w40; s32 w44; } S_3BB558;
extern S_3BB558 D_002D1FC0[];
extern void func_003BBA08(s32, s32);
extern s32 func_00381FF0(s32); extern s32 func_11BB58(void *, s32, s32);
extern void func_003BE008(f32);
s32 func_003C0A68(void) {
    func_003BBA08(0, 0);
    func_11BB58(D_002D1FC0, func_00381FF0(0x14D7), 0x40);
    D_002D1FC0[0].w40 = 0x96;
    D_002D1FC0[0].w44 = 0;
    func_003BE008(1.0f);
    return 1;
}
/* localdecomp:end func_003C0A68 */
