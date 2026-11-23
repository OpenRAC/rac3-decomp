#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

/* localdecomp:start func_L31_00349A18 */
/* log: flags. Under the file's own flags (L31_003480E0.c, -mno-split-addresses, default as) the best was
   21 diff: retail splits %hi/%lo of D_L31_00283F90, D_L31_00284010 and func_L31_00349E10 (lui early,
   addiu late) and builds -1.5707964f inline, which needs Ps2EeAs and gcc's split addresses: the flags
   of the next file, L31_00349D18.c (@ps2as, no -mno-split-addresses). Checked with
   --as ps2as --flags=-msplit-addresses: copy as if/else: 6; colour arrays indexed: 4; the list pointer
   set inside the loop (moved out by loop.c into the loop's preheader, as retail): MATCH.
   func_L03_0034B218 declared with its f32 fourth (same EABI registers as L03's (f32, u8 *, ...)): the
   argument setup order then matches; D_L31_001E1290 sized 8 so gcc emits one la, as retail. */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00349A18;

typedef struct {
    u8 p0[0x30];
    V_00349A18 f30;
    u8 p40[0x40];
} E_00349A18;

typedef int Q_00349A18 __attribute__((mode(TI)));

typedef struct {
    f32 a, b;
} P_00349A18;

extern E_00349A18 *D_L31_001DF880;
extern s32 D_L31_00283F90[];
extern P_00349A18 D_L31_00284010[];
extern s32 D_L31_001E1290[2];
extern s32 D_L31_001DD0A4;
__asm__(".extern D_L31_001DD0A4, 4");
extern s32 D_L31_001DD0AC;
__asm__(".extern D_L31_001DD0AC, 4");
extern s32 D_L31_001DD0B0;
__asm__(".extern D_L31_001DD0B0, 4");
extern s32 D_L31_001DD0C8;
__asm__(".extern D_L31_001DD0C8, 4");
extern s32 D_L31_001DD0CC;
__asm__(".extern D_L31_001DD0CC, 4");
extern s32 D_L31_001DD0D0;
__asm__(".extern D_L31_001DD0D0, 4");
extern s32 D_L31_001DD0D8;
__asm__(".extern D_L31_001DD0D8, 4");
extern s32 D_L31_001DD0DC;
__asm__(".extern D_L31_001DD0DC, 4");
extern f32 D_L31_001DD0E0;
__asm__(".extern D_L31_001DD0E0, 4");
extern s32 D_L31_001DD0E4;
__asm__(".extern D_L31_001DD0E4, 4");
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L31_003496E8(u8 *);
extern u8 *func_003C24B0(s32, s32);
extern void func_003C29B0(u8 *);
extern void func_003C6FE0(u8 *);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L31_00349E10();

void func_L31_00349A18(u8 *m) {
    u8 *v;
    s32 i;
    s32 n;
    f32 f;
    f32 c;
    Q_00349A18 t;

    *(f32 *)(m + 0xF8) = -1.5707964f;
    v = *(u8 **)(m + 0x68);
    *(s32 *)(m + 0x98) = 0;
    if (m[0x43] != 1) {
        func_003C3A10(m, 1, 0, 0);
    }
    *(s32 *)(v + 0x30) = 0;
    t = *(Q_00349A18 *)(m + 0x10);
    *(Q_00349A18 *)(v + 0x10) = t;
    if (*(s32 *)(v + 0x20) == -1) {
        *(Q_00349A18 *)v = t;
    } else {
        *(Q_00349A18 *)v = *(Q_00349A18 *)&D_L31_001DF880[*(s32 *)(v + 0x20)].f30;
    }
    *(s32 *)(v + 0x44) = 0;
    *(s32 *)(v + 0x40) = -1;
    func_L31_003496E8(m);
    n = D_L31_001DD0B0;
    for (i = 0; i < n; i++) {
        if (*(s32 *)(v + 0x28) != 0 && *(s32 *)(v + 0x2C) != 0) {
            ((f32 *)(v + 0x50))[i] = 1.0f - *(f32 *)(v + 0x30);
        } else {
            ((f32 *)(v + 0x50))[i] = *(f32 *)(v + 0x30);
        }
    }
    m[0x40] = D_L31_001DD0AC;
    m[0x41] = D_L31_001DD0AC + 1;
    for (i = 0; i < D_L31_001DD0AC; i++) {
        u8 **pp = (u8 **)(v + 0x90);

        pp[i] = func_003C24B0(0x1649, 0xA0);
        if (pp[i] != 0) {
            *(f32 *)(pp[i] + 0xF8) = -1.5707964f;
            *(u16 *)(pp[i] + 0x34) &= ~4;
            *(u16 *)(pp[i] + 0x34) &= ~2;
            *(u16 *)(pp[i] + 0x34) &= ~1;
            *(s16 *)(pp[i] + 0x32) = 0xFF;
            *(s32 *)(*(u8 **)(pp[i] + 0x68) + 0x44) = 1;
            *(f32 *)(pp[i] + 0x2C) =
                *(f32 *)(*(u8 **)(pp[i] + 0x24) + 0x24)
                * (*(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24));
            *(V_00349A18 *)(pp[i] + 0x10) = *(V_00349A18 *)(m + 0x10);
            pp[i][0x42] = m[0x43];
            pp[i][0x43] = m[0x43];
            pp[i][0x40] = D_L31_001DD0AC - 1 - i;
            pp[i][0x41] = D_L31_001DD0AC - i;
            func_003C29B0(pp[i]);
            func_003C6FE0(pp[i]);
        }
    }
    if (D_L31_001DD0A4 == 0) {
        D_L31_001DD0A4 = 0;
        c = D_L31_001DD0B0;
        for (i = 0; i < 32; i++) {
            f = (f32)(i / 2) / c;
            D_L31_00283F90[i] = ((s32)(f * 128.0f) << 24) | (D_L31_001DD0C8 << 16) | (D_L31_001DD0CC << 8)
                                | D_L31_001DD0D0;
            if (!(i & 1)) {
                D_L31_00284010[i].a = 0.0f;
            } else {
                D_L31_00284010[i].a = 1.0f;
            }
            D_L31_00284010[i].b = f;
        }
        func_L03_0034B218((u8 *)D_L31_001E1290, D_L31_001DD0D8, D_L31_001DD0DC, D_L31_001DD0E0, D_L31_001DD0E4, func_L31_00349E10);
    }
}
/* localdecomp:end func_L31_00349A18 */
