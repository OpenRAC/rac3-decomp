#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3E15B0.c's earlier functions (tools/port_from_us.py) */
extern void func_003A96A8(s32);
extern void func_00391708(void);
extern s32 D_001D5520[];
extern void func_00391A58(s32, s32, s32, s32, s32, s32);
extern void func_003D96F0(void);
extern s32 D_00306D40[];

typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3DBEC8;
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    s32 f44;
    u8 pad48[0x58 - 0x48];
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 pad64[0x7C - 0x64];
    s16 f7C, f7E;
    s32 f80;
    u8 pad84[0x98 - 0x84];
} S_3DBEC8;
extern S_3DBEC8 D_00306D00_003E17D0;
extern T_3DBEC8 D_001D94D0;
extern T_3DBEC8 D_001D9510;
extern char D_001D94F0[];
extern char D_001D94F8[];
extern char D_001D9500[];
extern char D_001D9530[];
extern s32 D_001D9BC8;
extern u16 D_001D4BC4;
extern s32 D_001D5B90;
extern s32 D_001D4CE8;
extern u8 D_001D9FA0;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern f32 D_001DA074;
extern s32 D_001DA070;
extern char *D_001D949C;
extern char *D_001D94A0;
extern char *D_001D94A4;
extern u8 D_001D94A8;
extern s32 D_001D94BC;
extern s32 D_001D94C0;
extern u8 D_003357E0[];
extern void func_0038B200(s32, s32, s32, s32);
extern void func_00389620(s32);
extern void func_003A97F8(s32, unsigned long);
extern char *func_00382468(s32);
extern s32 func_11BB58(void *, void *, s32);
extern s32 func_11B868(void *);
extern void func_003AF7C0(T_3DBEC8 *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_00396D48(s32, s32);
extern void func_00397040(s32, s32, s32, s32, s32, s32);
extern s32 func_00396E18(s32);
extern void func_00397A18(f32, f32, f32, f32, f32, s32, s32, s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_0038E530(s32);
extern void func_00382490(void);
extern void func_11B2E8();
extern void func_0038C790(s32, s32, s32, s32, s32, s32);
extern s32 func_0038DFB8(s32, s32, f32);
extern s32 func_00391198(s32, s32, s32, void *, s32);
extern long func_00389978(s32);
extern void func_003914C0(T_3DBEC8 *, s32, void *, s32, long, void *);
extern void func_003914A0(T_3DBEC8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00389750(void);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E17D0);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031CAB0);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031CAE0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E2610);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031CB60);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031CB90);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031CC20);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031CC40);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E3B68);

typedef int Q_3DCD08 __attribute__((mode(TI)));
typedef struct { Q_3DCD08 a, b; } V2_3DCD08;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DCD08;
typedef struct {
    V4_3DCD08 v0;
    V4_3DCD08 v10;
    V4_3DCD08 v20;
    V4_3DCD08 v30;
    s32 f40;
    s32 f44;
    s32 f48, f4C, f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    f32 f6C;
    s32 f70;
    s32 f74, f78;
    s16 f7C, f7E;
    s32 f80;
    s16 f84, f86;
    s32 f88, f8C, f90, f94;
} S_3DCD08;
typedef struct {
    u8 pad0[0x100];
    s32 f100;
    u8 pad104[0x148 - 0x104];
    f32 f148;
    f32 f14C;
    u8 pad150[0x1A4 - 0x150];
    s32 f1A4;
    u8 pad1A8[0x1C0 - 0x1A8];
    s32 f1C0;
    s32 f1C4;
} P_3DCD08;
/* US draft of func_003E3CB0 (rac3-uya-decomp func_003E3B68, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003E3CB0 */
extern void func_003E3CB0(f32 *);
__asm__(".extern D_001D94CC, 4");
extern f32 D_001D94CC;
extern f32 D_00222420[];
extern void func_003C50A0();
extern void func_0038DBF0();
extern void func_0038D9D0();
void func_003E3CB0(f32 *arg0) {
    f32 a[4];
    f32 b[12];
    ((void (*)(f32 *, f32 *, f32))func_003C50A0)(a, D_00222420, *arg0 * (D_001D94CC * 0.017453292f * 0.020000001f));
    func_0038DBF0(a, b);
    func_0038D9D0(D_00222420, b, D_00222420);
}
/* localdecomp:end func_003E3CB0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E3D38);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E3DA8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E3E60);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E3E68);
