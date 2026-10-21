#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3A56A8.c's earlier functions (tools/port_from_us.py) */
extern u8 D_001A30B0[];
#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
extern s32 D_001D6E1C;
extern u8 D_1A3100[];
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_13C170(void);
extern s32 func_12C908(s32);
extern void func_003A5A20(void);
typedef struct { u8 x0; s8 x1; s8 x2; s8 x3; u16 x4; u16 x6; s32 x8; s32 xC; u32 x10; s32 x14; s32 x18; u8 pad[0x60-0x1C]; } S_3A0200;
extern S_3A0200 D_0022D430[];
extern s32 D_0022D8B0[];
extern void func_003C2C38(s32 p);
typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
typedef struct { O_3A02D8 *f0; u8 pad[0x40]; } S_16C580_3A02D8;
extern S_16C580_3A02D8 D_0016C580_003A5AF8;
extern u32 D_001D54D0;
extern s16 D_001D5BB0[4];
extern s16 D_001D5BB6;
extern s16 D_001D5BB8;
extern s16 D_001D5BBA;
extern s16 D_001D5BBC;
extern O_3A02D8 *func_003C2868_003A5AF8(s32, s32);
extern void func_003A5AA0(void);
typedef struct { u8 p0[0x20]; s16 f20; } S_16C580_3A0D58;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0D58;
extern S_16C580_3A0D58 D_16C580_003A6578;
extern f32 func_00382918(void);
extern void func_003C4FD0(f32 *v, f32 r);

typedef struct { f32 x, y, z, w; } V_3A0EB0;
typedef struct { f32 x, y, z, w; } E_3A0EB0;
typedef struct {
    V_3A0EB0 v;
    u128_t q10;
    f32 f20; f32 f24; f32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; s32 f44; s32 f48; s32 f4C;
} T_3A0EB0;
extern s32 D_001D6FA0[2];
extern s32 D_001DA010[2];
extern s32 D_00225734[];
extern void func_003C3278();
extern void func_0038D408();
extern s32 func_0038DFB8(s32, s32, f32);
extern void func_003A6578(void *, void *, s32, f32, f32, f32, s32);
extern void func_003A8708_003A6590(void *, s32);
extern f32 func_003828C0(f32, f32);
extern f32 func_00382918(void);
extern s32 func_00382878(s32, s32);
extern void func_003A8668(s32, u8 *);

/* PAL version of func_003A6B90 (US rac3-uya-decomp func_003A6A20).
   The US draft called func_003A6590; that address has no PAL counterpart.
   In PAL the helper lives at 0x003A66D0 (func_003A66D0, declared by
   src/boot_elf/text/3A6578.c), which is what the retail code calls. */

/* localdecomp:start func_003A6B90 */
extern void func_003A66D0(void *, s32, s32);
void func_003A6B90(void *p) {
    func_003A66D0(p, 1, 0);
    func_003A66D0(p, 2, 0);
}
/* localdecomp:end func_003A6B90 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A6BD0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A6C00);

/* localdecomp:start func_003A6C08 */
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x38]; s32 f6C; } S_225780;
typedef struct { s32 v[0x53]; } E_160C40;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad2[0xB0]; E_160C40 e[1]; } S_160C40;
extern S_225780 D_00225700_003A6C08;
extern S_160C40 D_160C40;
extern s32 func_003A2998(s32, s32, s32);
extern s32 func_003A2B50(s32);
s32 func_003A6C08(s32 a) {
    s32 idx = D_00225700_003A6C08.f30;
    s32 h = D_00225700_003A6C08.f6C;
    s32 lo = D_160C40.e[idx].v[a];
    s32 d = D_160C40.e[idx].v[a + 1] - lo;
    if (d > 0) {
        func_003A2998(h, lo + D_160C40.f1284, d);
        func_003A2B50(0);
    }
    return 1;
}
/* localdecomp:end func_003A6C08 */
