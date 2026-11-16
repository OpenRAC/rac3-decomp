#include "common.h"

/* NTSC-U counterpart of func_L08_0039E8C8 (src/levels/08_aquatos/L08_0039E8C8.c) */
extern s32 func_L08_0039CB58(u8 *);
extern void func_L08_0039CDC8(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L08_0039CDC8 */
#include "vu0.h"
typedef int q_0039E8C8 __attribute__((mode(TI)));
extern s32 func_0039FE80(s32, s32, void *);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(u8 *, u8 *);
extern void func_L01_004475D0(u8 *);
extern s32 func_L01_00417EA0(void);
extern s32 func_L08_0039CB58(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE418(void *, s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_004412D0(void *, s32, s32);
extern s32 D_001D545C_sda_0039CDC8;
__asm__(".extern D_001D545C_sda_0039CDC8, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern f32 D_001DA8F8_sda;
__asm__(".extern D_001DA8F8_sda, 4");
extern u8 D_001426E0[];
extern f32 D_L08_002F0EF0[];

static __inline__ u8 scale_0039E8C8(u8 v) {
    f32 f = v;
    f32 r;
    if (func_L01_00417EA0() != 0) {
        if (D_001D545C_sda_0039CDC8 != 7 || D_001426E0[0x7B] == 0) {
            r = f * D_L08_002F0EF0[D_001D545C_sda_0039CDC8];
        } else {
            r = f * D_001DA8F8_sda;
        }
    } else {
        r = f;
    }
    return r;
}

void func_L08_0039CDC8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *o;
    u8 *ost;
    s32 i;
    vu0_v4 v;

    func_0039FE80(0, 0, a0);
    func_0039FE80(1, 0, a0);
    for (i = 0; i < 2; i++) {
        o = func_003BCFB0(0x1969, 0x260);
        if (o == 0) continue;
        *(q_0039E8C8 *)(o + 0xF0) = *(q_0039E8C8 *)(a0 + 0xF0);
        func_L01_00452E70(o, a0);
        *(u16 *)(o + 0x34) |= 0x20;
        func_L01_004475D0(o);
        o[0xB0] = a0[0xB0];
        ost = *(u8 **)(o + 0x68);
        *(s32 *)(ost + 0x180) = *(s32 *)(st + 0x180);
        *(s32 *)(ost + 0x188) = *(s32 *)(st + 0x188);
        *(f32 *)(ost + 0x18C) = *(f32 *)(st + 0x18C);
        *(f32 *)(ost + 0x184) = *(f32 *)(st + 0x184);
        *(void **)(ost + 0x1C) = ost + 0x70;
        *(void **)(ost + 0xC) = ost + 0x160;
        *(void **)(ost + 0x0) = ost + 0x30;
        *(s16 *)(ost + 0x36) = 0x1E;
        ost[0x44] = scale_0039E8C8(ost[0x44]);
        ost[0x45] = scale_0039E8C8(ost[0x45]);
        func_L08_0039CB58(o);
        *(f32 *)(o + 0x18) += 0.3f;
        func_L01_00441FB8(o, 2, 1);
        func_003BE418(o, 6, 0);
        *(q_0039E8C8 *)(ost + 0x1E0) = *(q_0039E8C8 *)(st + 0x1E0);
        ost[0x3F] = 1;
        *(s32 *)(ost + 0x190) = 600;
        *(s32 *)(ost + 0x1DC) = i;
        if (i == 0) {
            if (D_001D545C == 0x1C) func_00388830(&v, a0 + 0xD0, 1.0f);
            else func_00388830(&v, a0 + 0xD0, 0.4f);
        } else {
            if (D_001D545C == 0x1C) func_00388830(&v, a0 + 0xD0, -1.0f);
            else func_00388830(&v, a0 + 0xD0, -0.4f);
        }
        vec_add_ab(o + 0x10, &v, a0 + 0x10);
        *(s16 *)(o + 0xB6) = 10;
    }
    func_L01_004412D0(a0, 0, 3);
    *(u16 *)(a0 + 0x34) &= ~0x20;
}
/* localdecomp:end func_L08_0039CDC8 */
