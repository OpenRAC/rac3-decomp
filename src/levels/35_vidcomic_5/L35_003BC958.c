#include "common.h"

typedef struct {
    u8 pad0[0x84];
    s32 f84;
} S_Sub_003BC958;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x47];
    S_Sub_003BC958 *f68;
} S_Obj_003BC958;
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad1[0x44];
    s32 f6C;
    s16 f70;
    u8 pad2[4];
    s16 f76;
    u8 pad3[0x1C];
    s32 f94;
    s16 f98;
    u8 pad4[4];
    s16 f9E;
} S_1CCFD0_003BC958;

/* localdecomp:start func_L35_003BC958 */
extern S_1CCFD0_003BC958 D_001CCFD0;
extern void func_L35_003BC9F0(void *);
extern void func_L35_003BCA28(S_Obj_003BC958 *);
extern void func_L35_003BCAB8(void *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L35_003BC958(S_Obj_003BC958 *arg) {
    S_Sub_003BC958 *s = arg->f68;

    if (arg->f20 == 0) {
        func_L35_003BC9F0(arg);
        func_L01_004450F0((u8 *)arg, 1, -1);
    }
    if (D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0 && s->f84 == 0) {
        func_L35_003BCAB8(arg);
    }
    func_L35_003BCA28(arg);
}
/* localdecomp:end func_L35_003BC958 */

/* localdecomp:start func_L35_003BC9F0 */
typedef struct {
    u8 pad0[0x60];
    s32 f60; s32 f64; s32 f68; s32 f6C; s32 f70; s32 f74; s32 f78; s32 f7C; s32 f80; s32 f84;
} S_L35_9F0;

void func_L35_003BC9F0(void *arg) {
    S_L35_9F0 *s = (S_L35_9F0 *)((S_Obj_003BC958 *)arg)->f68;

    *((u8 *)arg + 0x30) = 0xFF;
    s->f60 = 0;
    s->f64 = 0;
    s->f68 = 0;
    s->f6C = 0;
    s->f70 = 0;
    s->f74 = 0;
    s->f78 = 0;
    s->f7C = 0;
    s->f80 = 0;
    s->f84 = 0;
}
/* localdecomp:end func_L35_003BC9F0 */

/* localdecomp:start func_L35_003BCA28 */
extern S_1CCFD0_003BC958 D_001CCFD0;
extern s32 func_003A1798(void);

void func_L35_003BCA28(S_Obj_003BC958 *a)
{
    S_Sub_003BC958 *p = a->f68;

    if (D_001CCFD0.f70 >= 0x1B58) {
        if (p->f84 != 0) {
            p->f84 = 0;
            D_001CCFD0.f24 = -1;
        }
    }
    if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 0x1B58) {
        func_003A1798();
        p->f84 = 0;
    }
}
/* localdecomp:end func_L35_003BCA28 */

/* localdecomp:start func_L35_003BCAB8 */
typedef struct {
    u8 pad0[0x48];
    f32 f48;
} S_Inner_003BCAB8;
typedef struct {
    u8 pad0[0x68];
    S_Inner_003BCAB8 *f68;
    u8 pad1[0x100 - 0x6C];
} S_Moby_003BCAB8;
typedef struct {
    s32 snd[16];
    s32 key40;
    s32 key44;
    s32 key48;
    s32 key4C;
    s32 key50;
    s32 key54;
    s32 key58;
    s32 key5C;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
    s32 f80;
    s32 f84;
} S_Sub_003BCAB8;
typedef struct {
    u8 pad0[0x80];
    f32 pos[4];
    u8 pad1[0x1B04 - 0x90];
    s32 f1B04;
    u8 pad2[0x1B38 - 0x1B08];
    u32 f1B38;
    u8 pad3[0x25C4 - 0x1B3C];
    s32 f25C4;
} S_Hero_003BCAB8;

extern S_Hero_003BCAB8 D_001A4BE0;
extern S_Moby_003BCAB8 *D_L35_001DF89C; __asm__(".extern D_L35_001DF89C, 4");
extern f32 D_L35_001DEAA4; __asm__(".extern D_L35_001DEAA4, 16");
extern s32 func_00382380(void *, s32, s32);
extern void func_003A2B68(int, int);

void func_L35_003BCAB8(void *arg) {
    S_Sub_003BCAB8 *s = (S_Sub_003BCAB8 *)((S_Obj_003BC958 *)arg)->f68;
    S_Inner_003BCAB8 *m;

    if (((u8)D_001A4BE0.f1B38 ^ 1) & 1) {
        switch (s->f60) {
        case 0:
            func_003A2B68((s->snd[0] & 0x3FFF) + 0x7D0, 0);
            break;
        case 1:
            func_003A2B68((s->snd[1] & 0x3FFF) + 0x7D0, 0);
            break;
        case 2:
            func_003A2B68((s->snd[2] & 0x3FFF) + 0x7D0, 0);
            break;
        case 3:
            func_003A2B68((s->snd[3] & 0x3FFF) + 0x7D0, 0);
            break;
        case 4:
            func_003A2B68((s->snd[4] & 0x3FFF) + 0x7D0, 0);
            D_001A4BE0.f1B38 |= 1;
            break;
        }
        s->f84 = 1;
        s->f60++;
    } else if (s->f64 == 0 && s->key50 != -1 && func_00382380(D_001A4BE0.pos, s->key50, 0) != 0) {
        s->f64 = 1;
        func_003A2B68((s->snd[7] & 0x3FFF) + 0x7D0, 0);
        s->f84 = 1;
    } else if (s->f68 == 0 && s->key54 != -1 && func_00382380(D_001A4BE0.pos, s->key54, 0) != 0) {
        s->f68 = 1;
        func_003A2B68((s->snd[8] & 0x3FFF) + 0x7D0, 0);
        s->f84 = 1;
    } else if (s->f6C == 0 && s->key58 != -1 && func_00382380(D_001A4BE0.pos, s->key58, 0) != 0) {
        s->f6C = 1;
        func_003A2B68((s->snd[9] & 0x3FFF) + 0x7D0, 0);
        s->f84 = 1;
    } else if (s->f7C == 0 && s->key48 != -1 && func_00382380(D_001A4BE0.pos, s->key48, 0) != 0) {
        s->f7C = 1;
        func_003A2B68((s->snd[5] & 0x3FFF) + 0x7D0, 0);
        s->f84 = 1;
    } else if (s->f80 == 0 && s->key4C != -1 && func_00382380(D_001A4BE0.pos, s->key4C, 0) != 0) {
        s->f80 = 1;
        func_003A2B68((s->snd[6] & 0x3FFF) + 0x7D0, 0);
        s->f84 = 1;
    } else if (!(D_001A4BE0.f1B38 & 4) && s->key44 != -1 && func_00382380(D_001A4BE0.pos, s->key44, 0) != 0) {
        D_001A4BE0.f1B38 |= 4;
        func_003A2B68((s->snd[10] & 0x3FFF) + 0x7D0, 0);
        s->f84 = 1;
    } else if (s->f70 == 0 && D_001A4BE0.f25C4 == 0xA0) {
        s->f70 = 1;
        func_003A2B68((s->snd[11] & 0x3FFF) + 0x7D0, 0);
        s->f84 = 1;
    } else if (s->f74 == 0 && s->key40 != -1 && func_00382380(D_001A4BE0.pos, s->key40, 0) != 0) {
        s->f74 = 1;
        func_003A2B68((s->snd[12] & 0x3FFF) + 0x7D0, 0);
        s->f84 = 1;
    } else if (s->f78 == 0 && s->key5C != -1 && (m = D_L35_001DF89C[s->key5C].f68) != 0
               && D_001A4BE0.pos[2] + D_L35_001DEAA4 < m->f48) {
        s->f78 = 1;
        func_003A2B68((s->snd[13] & 0x3FFF) + 0x7D0, 0);
        s->f84 = 1;
    } else if (!(D_001A4BE0.f1B38 & 2) && D_001A4BE0.f1B04 == 2) {
        D_001A4BE0.f1B38 |= 2;
        func_003A2B68((s->snd[14] & 0x3FFF) + 0x7D0, 0);
        s->f84 = 1;
    }
}
/* localdecomp:end func_L35_003BCAB8 */
