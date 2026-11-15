#include "common.h"

/* declared by functions of L08_0039D188.c, which this file was cut from */
extern s32 func_L08_0039E658(u8 *);
extern void func_L08_0039E8C8(u8 *);
extern void func_L01_004450F0(void *, s32, s32);

/* localdecomp:start func_L08_0039E8C8 */
#include "vu0.h"
typedef int q_0039E8C8 __attribute__((mode(TI)));
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_0044A7D0(u8 *);
extern s32 func_L01_0041A4F0(void);
extern s32 func_L08_0039E658(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3938(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004443E8(void *, s32, s32);
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern f32 D_001DA8B8_sda;
__asm__(".extern D_001DA8B8_sda, 4");
extern u8 D_001426E0[];
extern f32 D_L08_002F0F30[];

static __inline__ u8 scale_0039E8C8(u8 v) {
    f32 f = v;
    f32 r;
    if (func_L01_0041A4F0() != 0) {
        if (D_001D545C_sda != 7 || D_001426E0[0x7B] == 0) {
            r = f * D_L08_002F0F30[D_001D545C_sda];
        } else {
            r = f * D_001DA8B8_sda;
        }
    } else {
        r = f;
    }
    return r;
}

void func_L08_0039E8C8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *o;
    u8 *ost;
    s32 i;
    vu0_v4 v;

    func_003A52A0(0, 0, a0);
    func_003A52A0(1, 0, a0);
    for (i = 0; i < 2; i++) {
        o = func_003C24B0(0x1969, 0x260);
        if (o == 0) continue;
        *(q_0039E8C8 *)(o + 0xF0) = *(q_0039E8C8 *)(a0 + 0xF0);
        func_L01_00456160(o, a0);
        *(u16 *)(o + 0x34) |= 0x20;
        func_L01_0044A7D0(o);
        o[0xB0] = a0[0xB0];
        ost = *(u8 **)(o + 0x68);
        *(s32 *)(ost + 0x180) = *(s32 *)(st + 0x180);
        *(s32 *)(ost + 0x188) = *(s32 *)(st + 0x188);
        *(f32 *)(ost + 0x18C) = *(f32 *)(st + 0x18C);
        *(f32 *)(ost + 0x184) = *(f32 *)(st + 0x184);
        *(void **)(ost + 0x1C) = ost + 0x70;
        *(void **)(ost + 0xC) = ost + 0x160;
        *(void **)(ost + 0x0) = ost + 0x30;
        *(s16 *)(ost + 0x36) = 0x19;
        ost[0x44] = scale_0039E8C8(ost[0x44]);
        ost[0x45] = scale_0039E8C8(ost[0x45]);
        func_L08_0039E658(o);
        *(f32 *)(o + 0x18) += 0.3f;
        func_L01_004450F0(o, 2, 1);
        func_003C3938(o, 6, 0);
        *(q_0039E8C8 *)(ost + 0x1E0) = *(q_0039E8C8 *)(st + 0x1E0);
        ost[0x3F] = 1;
        *(s32 *)(ost + 0x190) = 500;
        *(s32 *)(ost + 0x1DC) = i;
        if (i == 0) {
            if (D_001D545C == 0x1C) func_0038CF68(&v, a0 + 0xD0, 1.0f);
            else func_0038CF68(&v, a0 + 0xD0, 0.4f);
        } else {
            if (D_001D545C == 0x1C) func_0038CF68(&v, a0 + 0xD0, -1.0f);
            else func_0038CF68(&v, a0 + 0xD0, -0.4f);
        }
        vec_add_ab(o + 0x10, &v, a0 + 0x10);
        *(s16 *)(o + 0xB6) = 10;
    }
    func_L01_004443E8(a0, 0, 3);
    *(u16 *)(a0 + 0x34) &= ~0x20;
}
/* localdecomp:end func_L08_0039E8C8 */
