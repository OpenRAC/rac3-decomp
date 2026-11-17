#include "common.h"

typedef struct { u8 pad0[0x68]; struct { u8 pad[4]; s32 idx; } *p68; } O_B;

/* declared by functions of L07_003C0710.c, which this file was cut from */
extern s32 func_00381FF0(s32);

/* localdecomp:start func_L07_003C1EB8 */
/* following rac3-decomp's func_L03_00330530 */
typedef struct { u8 pad00[0x30]; s32 f30; u8 pad34[7]; u8 b3B; } S_003C1EB8;
extern void func_0011B2E8();
extern char *func_0011B4E4(char *, char *);
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_0038FA18(u16 *, long, char *, s32, unsigned long, f32, f32);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);
extern u8 D_L07_001DE598[];
extern u8 D_L07_001DE5A0[];
extern char D_L07_001DE5B0[];
extern u8 D_00143A07[];
extern f32 D_L07_001E05A4;
__asm__(".extern D_L07_001E05A4, 16");
extern s32 D_L07_001E05A0;
__asm__(".extern D_L07_001E05A0, 16");
extern s32 D_001D4BC8;
__asm__(".extern D_001D4BC8, 16");
extern s32 D_L07_001D64E8;
__asm__(".extern D_L07_001D64E8, 16");

static __inline__ s32 scale_003C1EB8(f32 v) {
    f32 z0 = 0.0f, z1 = 0.0f;
    return (s32)(v * D_L07_001E05A4 + 0.5f + (D_L07_001E05A0 == 1 ? z0 : z1));
}

void func_L07_003C1EB8(u8 *self) {
    char buf[0x400];
    u16 m[16];
    S_003C1EB8 *p = *(S_003C1EB8 **)(self + 0x68);
    u32 y;
    s32 h, w;

    switch (p->f30) {
    case 0:
        func_0011B2E8(buf, D_L07_001DE598, func_00381FF0(0x58B));
        break;
    case -1:
        func_0011B2E8(buf, D_L07_001DE598, func_00381FF0(0x269));
        break;
    case -2:
        func_0011B2E8(buf, D_L07_001DE598, func_00381FF0(0x185E));
        break;
    case -3:
        func_0011B2E8(buf, D_L07_001DE598, func_00381FF0(0x1660));
        break;
    default: {
        u8 *fmt = D_L07_001DE5A0;
        s32 a = func_00381FF0(0x269);
        s32 b = func_00381FF0(0x125C);
        s32 c = func_00381FF0(0x282);
        func_0011B2E8(buf, fmt, a, b, p->f30, c);
        break;
    }
    }
    if (p->b3B) {
        func_0011B4E4(buf, D_L07_001DE5B0);
        func_0011B4E4(buf, (char *)func_00381FF0(0x12B3));
    }
    w = 0x90;
    y = D_00143A07[0] == 2 ? w : 0x80;
    m[12] = 2;
    m[13] = 2;
    func_003910C0((s16 *)m, scale_003C1EB8(256.0f), scale_003C1EB8((f32)(s32)(y + 0x100)), D_001D4BC8 - 0x90, D_001D4BC8 + 0x90, D_001D4BC8, (y >> 1) | 0x100, 0x10, 0x27);
    func_0038FA18(m, 0x8066CCFFL, buf, -1, 0x80000000UL, 1.0f, 1.0f);
    w = ((s16)m[6] >> 1) + 8;
    h = ((s16)m[7] >> 1) + 8;
    func_0038C3B0(((s16)m[5]) - h, ((s16)m[5]) + h, ((s16)m[4]) - w, ((s16)m[4]) + w, 0x33, 0x331465B7);
    func_L01_00436020(0x33, 0x332299DE, (s16)m[5] - h, (s16)m[5] + h, (s16)m[4] - w, (s16)m[4] + w);
    m[9] &= 0xFFFB;
    func_0038FA18(m, 0x8066CCFFL, buf, -1, 0x80000000UL, 1.0f, 1.0f);
    D_L07_001D64E8 = 1;
}
/* localdecomp:end func_L07_003C1EB8 */
