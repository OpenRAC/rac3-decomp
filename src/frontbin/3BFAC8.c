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
extern void func_003BFC58();
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
extern void func_003BFD60(S_3BA368 *p);


typedef int u128_3BA490 __attribute__((mode(TI)));
typedef struct {
    u128_3BA490 a;
    u128_3BA490 b;
    f32 f20, f24, f28;
    s32 x2C, x30, x34, x38, x3C, x40, x44, x48, x4C;
} P_3BA490;
extern void func_003A8308(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern s32 func_0038DBD8(s32, s32, f32);
typedef int Q_3BA5B8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x10]; Q_3BA5B8 q10; u8 pad20[0x12]; s16 h32; } B_3BA5B8;
typedef struct {
    B_3BA5B8 *b;
    s32 w4;
    f32 f8;
    u8 bC, bD, bE, bF;
    union { Q_3BA5B8 q; f32 f[4]; } q10;
} Sub_3BA5B8;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3BA5B8 q10;
    Sub_3BA5B8 s20;
} S_3BA5B8;
extern void *func_003CD108(s32);
extern s32 func_00382468();
extern u8 *D_002FCFFC[];
extern void func_0038D000(void *, void *, void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003BFAC8);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BA748;
typedef int Q_3BA748 __attribute__((mode(TI)));
typedef struct { s8 p0[0x20]; s8 b20; } O_3BA748;
typedef struct { O_3BA748 *obj; s32 f4; u8 p8[5]; u8 b0D; u8 pE[2]; V_3BA748 v10; } B_3BA748;
typedef struct { u8 p0[4]; s32 f4; u8 b8; u8 p9; s16 h0A; f32 fC; V_3BA748 v10; B_3BA748 b; } P_3BA748;
extern s32 func_0038CB00();
extern void func_003CD250(s32);
extern void func_0038D000(void *, void *, void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003BFC58);

extern u8 *D_001DA31C_003BFD60[2];
extern u8 D_00380060[];
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850;
extern u8 D_001DA318[8];
extern f32 D_001D8E64;
extern s32 D_001D8E68;
extern f32 D_001D8E6C;
extern f32 D_001D8E70;
extern u8 *func_003BFAC8(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
/* localdecomp:start func_003BFD60 */
/* US draft of func_003BFD60 (rac3-uya-decomp func_003C0010, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


__asm__(".extern D_001D8E64_003BFD60, 4");
__asm__(".extern D_001D8E68_003BFD60, 4");
__asm__(".extern D_001D8E6C_003BFD60, 4");
__asm__(".extern D_001D8E70_003BFD60, 4");
extern u8 *D_001DA31C_003BFD60_003BFD60[2];
extern u8 D_00380060_003BFD60[];
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850_003BFD60;
extern u8 D_001DA318_003BFD60[8];
extern f32 D_001D8E64_003BFD60;
extern s32 D_001D8E68_003BFD60;
extern f32 D_001D8E6C_003BFD60;
extern f32 D_001D8E70_003BFD60;
extern u8 *func_003BFAC8_003BFD60(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_003BFD60(S_3BA368 *a) {
    s32 i;
    u8 **p = D_001DA31C_003BFD60_003BFD60;
    u8 *e = D_00380060_003BFD60;
    u8 *r;
    for (i = 5; i >= 0; i--) {
        if (*p == 0) {
            r = func_003BFAC8_003BFD60(e, (s32)a, D_001D8E68_003BFD60, 0, 0, -1, 0, -1, 0, 0, D_001D8E6C_003BFD60 * 210000.0f, D_001D8E70_003BFD60, 1.0f);
            *p = r;
            if (r != 0) r[3] = 0x44;
        }
        e += 0x10;
        p++;
    }
    { S_3BA850_003BFD60 *q = (S_3BA850_003BFD60 *)D_001DA318_003BFD60; q->f1C = D_001D8E64_003BFD60 * 0.020000002f; }
}
/* localdecomp:end func_003BFD60 */
