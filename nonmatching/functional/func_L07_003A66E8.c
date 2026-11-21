/* functional: medium. Scheduling and s3/s4 allocation differ; behaviour verified only through call/op multiset and line count. */
#include "common.h"
/* localdecomp:start func_L07_003A66E8 */
#include "vu0.h"
extern s32 D_001DEF40_sda;
extern u8 *D_L07_001ECC80[];
extern s32 D_00142660[];
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
void func_L07_003A66E8(u8 *self) {
    extern s32 func_L07_003BAC00(void *, s32);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern s32 func_L01_004561B8(void *);
    extern s32 func_0038CAD0(void *);
    extern void func_L07_003A6EF8(void *);
    extern void func_L01_004AAC98(s32, s32, void *, s32);
    extern void func_L01_004AA760(s32, void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
    extern s32 func_003D4D00(void *, s32, void *, s32, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_L01_00446A70(u8 *, u8 *, s32, void *, void *, f32);
    extern s32 func_00382468(s32);
    extern void func_L01_00466F50(void *, void *, s32, f32, f32);
    extern void func_L01_00470150(void *, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32, s32, f32);
    extern void func_L07_003A6FC8(u8 *, s32);
    extern void func_L01_00451DB8(void *, void *, u32, u32, f32);
    struct { vu0_q velocity; vu0_v4 v; } w;
    u8 *s = *(u8 **)(self + 0x68);

    if (self[0x20] != 0 && *(void **)(s + 0x74) != 0 && !func_L07_003BAC00(*(void **)(s + 0x74), *(s32 *)(s + 0x70))) return;
    if (self[0x20] == 3 && *(s16 *)(s + 0x7C) == 0) func_L01_004450F0(self, 2, -1);
    if (self[0x20] == 2 && *(s16 *)(s + 0x78) == 0) func_L01_004450F0(self, 4, -1);
    switch (self[0x20]) {
    case 0:
        self[0x30] = 0xFF;
        *(s16 *)(self + 0x32) = 0x40;
        self[0x31] = 0;
        *(s32 *)(s + 0x74) = 0;
        *(s32 *)(s + 0x70) = -1;
        func_L01_004450F0(self, 1, -1);
        break;
    case 1:
        if (*(s32 *)(s + 0x70) != -1) func_L01_004450F0(self, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(self)) *(s32 *)(s + 0x84) = *(s16 *)(s + 0x78);
        if (func_0038CAD0(s + 0x84)) func_L01_004450F0(self, 4, -1);
        else if (*(s32 *)(s + 0x84) < 33 && (D_001DEF40_sda & 3) == (((s32)self >> 8) & 3)) func_L07_003A6EF8(self);
        break;
    case 4: {
        s32 i, count;

        u8 *p;
        u8 **list;
        f32 size, step;
        if (func_L01_004561B8(self)) {
            *(s32 *)(s + 0x84) = *(s16 *)(s + 0x7A);
            func_L01_004AAC98(0, 4, self, 0x197E);
        }
        if (*(s32 *)(s + 0x84) < 3) func_L07_003A6EF8(self);
        if (func_0038CAD0(s + 0x84)) {
            func_L01_004AA760(0, self);
            func_L01_004450F0(self, 3, -1);
            break;
        }
        *(vu0_q *)&w.v = 0;
        w.v.x = func_L01_00443A18(0.0f, 0.02f);
        w.v.y = func_L01_00443A18(0.0f, 0.02f);
        w.v.z = func_003824E0(0.08000000566244125f, 0.12000000476837158f);
        w.velocity = *(vu0_q *)&w.v;
        size = func_003824E0(0.6f, 1.2f) * 210000.0f;
        step = size * 0.25f;
        p = s + 0xA0;
        for (i = 8; i >= 0; i--) {
            s32 six = 6;
            s32 n = (func_00382498(8, 16) * 5 + 2) / six;
            func_L01_0046FB40(p, &w.velocity, n, 0x7F7F7F, 1, 0x7F, 0, size, step, 0, -0.003000000026077032f);
            p += 16;
        }
        count = func_003D4D00(self + 0x10, 0, self, 0, 2.9000000953674316f);
        if (count > 0) {
        list = D_L07_001ECC80;
        do {
            u8 *other = *list;
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m" (w.v) : "m" (*(vu0_v4 *)(other + 0x10)), "m" (*(vu0_v4 *)(self + 0x10)) : "vf1", "vf2");
            if (w.v.z >= 0.0f && w.v.z < 1.0f && fabs_asm(func_0038CE68(&w.v, self + 0xC0)) < 2.0f && fabs_asm(func_0038CE68(&w.v, self + 0xD0)) < 2.0f) {
                func_L01_00446A70(*list, self, 0x10001, *list + 0x10, D_L07_001D66B0, (f32)D_00142660[2] * 0.25f);
            }
            count--;
            list++;
        } while (count != 0);
        }
        if (func_00382468(4) == 0) func_L01_00466F50(s + 0xA0 + func_00382468(9) * 16, &w.velocity, 0, -1.0f, 0.0f);
        { u8 *endParticle = *(u8 **)(self + 0x68) + 0xA0;
        for (i = 8; i >= 0; i--) {
            func_L01_00470150(endParticle, 0, 0x20204080, -1, 1, 315000.0f, 1.0f, 2, 0, -1, 0, 0, 1.0f);
            endParticle += 16;
        }
        }
        break;
    }
    case 3:
        if (func_L01_004561B8(self)) {
            *(s32 *)(s + 0x84) = *(s16 *)(s + 0x7C);
            if (*(s32 *)(s + 0x84) < 0) *(s32 *)(s + 0x84) = 0;
            func_L07_003A6FC8(self, 1);
        }
        if (func_0038CAD0(s + 0x84)) func_L01_004450F0(self, 2, -1);
        else if (*(s32 *)(s + 0x84) + *(s16 *)(s + 0x78) < 33 && (D_001DEF40_sda & 3) == (((s32)self >> 8) & 3)) func_L07_003A6EF8(self);
        break;
    case 5: break;
    }
    if (self[0x31]) func_L01_00451DB8(self, s + 0x154, 0x80A0A0A0, 0x80202020, 0.1466076672077179f);
    func_L07_003A6FC8(self, 0);
}
/* localdecomp:end func_L07_003A66E8 */
