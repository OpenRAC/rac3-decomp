#include "common.h"

/* types of func_L08_0039C480, from upstream's L08_0039B088.c */
typedef int s128_0039AA50 __attribute__((mode(TI)));

/* declared by functions of L08_0039B088.c, which this file was cut from */
extern void func_L08_0039C480(u8 *self);
extern s32 D_001D545C;
extern void func_L01_004450F0(void *, s32, s32);

/* declarations func_L08_0039C480's C had before it in L08_0039B088.c */
extern void func_0038CF68(f32, void *, void *);
/* localdecomp:start func_L08_0039C480 */
/* PAL port of the NTSC-U match src/us/levels/func_L08_0039AA50.c */
#include "vu0.h"

extern s32 D_001D545C;
extern f32 D_L08_001DA8B8;
extern u8 D_1426E0[];
extern f32 D_L08_002F0F30[];
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_L01_0044A7D0(void *);
extern s32 func_L01_0041A4F0(void);
extern void func_L08_0039E658(void *);
extern void func_003C3938(void *, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);

void func_L08_0039C480(u8 *self) {
    vu0_v4 vec;
    u8 *s3;
    u8 *s0;
    u8 *obj;
    f32 f;
    f32 g;
    s32 i;

    s3 = *(u8 **)(self + 0x68);
    func_003A52A0(0, 0, self);
    func_003A52A0(1, 0, self);
    for (i = 0; i < 2; i++) {
        obj = func_003C24B0(0x1968, 0x260);
        if (obj != 0) {
            *(s128_0039AA50 *)(obj + 0xF0) = *(s128_0039AA50 *)(self + 0xF0);
            func_L01_00456160(obj, self);
            *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x20;
            func_L01_0044A7D0(obj);
            obj[0xB0] = self[0xB0];
            s0 = *(u8 **)(obj + 0x68);
            *(s32 *)(s0 + 0x180) = *(s32 *)(s3 + 0x2C0);
            *(s32 *)(s0 + 0x188) = *(s32 *)(s3 + 0x2C8);
            *(f32 *)(s0 + 0x18C) = *(f32 *)(s3 + 0x2CC);
            *(f32 *)(s0 + 0x184) = *(f32 *)(s3 + 0x2C4);
            *(u8 **)(s0 + 0x1C) = s0 + 0x70;
            *(u8 **)(s0 + 0xC) = s0 + 0x160;
            *(u8 **)(s0 + 0x0) = s0 + 0x30;
            *(s16 *)(s0 + 0x36) = 25;
            f = (f32)s0[0x44];
            if (func_L01_0041A4F0() != 0) {
                if (D_001D545C != 7 || D_1426E0[0x7B] == 0) {
                    g = f * D_L08_002F0F30[D_001D545C];
                } else {
                    g = f * D_L08_001DA8B8;
                }
            } else {
                g = f;
            }
            s0[0x44] = (s32)g;
            f = (f32)s0[0x45];
            if (func_L01_0041A4F0() != 0) {
                if (D_001D545C != 7 || D_1426E0[0x7B] == 0) {
                    g = f * D_L08_002F0F30[D_001D545C];
                } else {
                    g = f * D_L08_001DA8B8;
                }
            } else {
                g = f;
            }
            s0[0x45] = (s32)g;
            func_L08_0039E658(obj);
            *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + 0.5f;
            func_L01_004450F0(obj, 2, 1);
            *(s128_0039AA50 *)(s0 + 0x1E0) = *(s128_0039AA50 *)(s3 + 0x330);
            func_003C3938(obj, 6, 0);
            *(s32 *)(s0 + 0x1DC) = i;
            *(s32 *)(s0 + 0x190) = 500;
            if (i == 0) {
                if (D_001D545C == 0x1C) {
                    func_0038CF68(1.0f, &vec, self + 0xD0);
                } else {
                    func_0038CF68(0.57f, &vec, self + 0xD0);
                }
            } else {
                if (D_001D545C == 0x1C) {
                    func_0038CF68(-1.0f, &vec, self + 0xD0);
                } else {
                    func_0038CF68(-0.57f, &vec, self + 0xD0);
                }
            }
            vec_add_ab(obj + 0x10, &vec, self + 0x10);
            *(s16 *)(obj + 0xB6) = 0x14;
        }
    }
    func_L01_004443E8(self, 0, 3);
}
/* localdecomp:end func_L08_0039C480 */
