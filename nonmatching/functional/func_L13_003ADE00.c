/* functional: high. Hand-written from PAL assembly (no draft existed). Enemy/NPC update: proximity check, state-dependent attack/death transitions, particle bursts from the attached object at +0x3E0, then per-state animation setup and pose callbacks; returns 1 (alive) or 0 (after calling func_L13_003AE508). Loops over gp data count D_L13_001DE790 spawn debris along the object's matrix axes. */
#include "common.h"

/* localdecomp:start func_L13_003ADE00 */
typedef int u128_003ADE00 __attribute__((mode(TI)));
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_003ADE00;

extern V_003ADE00 D_L13_001E2140;
extern f32 D_L13_001DEBB0;
extern s32 D_L13_001D67C4;
extern s32 D_001D545C;
extern s32 D_L13_001DE790;
extern f32 D_L13_001DE794;
extern f32 D_L13_001DE7A0;
extern f32 D_L13_001DE7A4;
extern u8 D_L13_001DE760[];
extern u8 D_L13_001DE778[];
__asm__(".extern D_L13_001DEBB0, 4");
__asm__(".extern D_L13_001D67C4, 4");
__asm__(".extern D_001D545C, 4");
__asm__(".extern D_L13_001DE790, 4");
__asm__(".extern D_L13_001DE794, 4");
__asm__(".extern D_L13_001DE7A0, 4");
__asm__(".extern D_L13_001DE7A4, 4");
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L13_003AF9F0(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L13_003C62A8(void *, void *, void *);
extern void func_003C2880(void *);
extern void func_003C56E0(void *, void *, void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L13_003AEB48(void *);
extern void func_L13_003AE508(void *);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_L05_00468EA8(void *, void *, void *, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00459C50(s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);

s32 func_L13_003ADE00(u8 *self) {
    u8 *v;
    u8 *vm;
    u8 *obj;
    u8 *p90;
    u8 *p84;
    u8 *p88;
    u8 *p94;
    u8 *p8c;
    u8 *p80;
    u8 *fp;
    s32 s;
    s32 flag;
    s32 a5;
    s32 i;
    s32 lvl;
    s32 cnt;
    f32 r;
    f32 f2;
    f32 f12;
    V_003ADE00 t10;
    V_003ADE00 t20;
    V_003ADE00 m[4];
    V_003ADE00 t70;

    v = *(u8 **)(self + 0x68);
    if (self[0x31] != 0) {
        r = func_L01_0040E548(&D_L13_001E2140, self + 0x10);
        if (r < 1024.0f) {
            func_L01_004472C0(self);
            self[0x6F] = 0x1E;
        }
    }
    s = self[0x95];
    if (s == 1) {
        *(f32 *)(v + 0xCC) = 0.2f;
        *(f32 *)(v + 0xC8) = 0.75f;
        if (func_L01_00452FB0(self, v + 0x70, 0, 0, 0) != 0) {
            *(s32 *)(v + 0x3E4) = 1;
            func_L13_003AF9F0(self);
        }
    } else {
        *(f32 *)(v + 0xC8) = 2.0f;
        *(f32 *)(v + 0xCC) = 2.0f;
        flag = func_L01_00452FB0(self, v + 0x70, 0, 0, 1) != 0;
        if (self[0x95] == 0 && 0.0f < *(f32 *)(v + 0x30)) {
            f2 = *(f32 *)(v + 0x30);
            r = (f32)*(s16 *)(v + 0x34) * *(f32 *)(v + 0x3C4);
            if (f2 <= r) {
                if (*(s32 *)(v + 0x3E0) != 0) {
                    func_0038CF68(&t10, self + 0xE0, 0.40000004f);
                    t20 = *(V_003ADE00 *)(*(u8 **)(v + 0x3E0) + 0x10);
                    func_L13_003C62A8(self, &t20, &t10);
                    func_003C2880(*(void **)(v + 0x3E0));
                    *(s32 *)(v + 0x3E0) = 0;
                }
                func_0038CF68(&t10, self + 0xC0, -1.0f);
                func_003C56E0(self, v + 0x70, &t10, 3, -1);
                func_L01_004450F0(self, 0x10, 1);
            }
        } else if (self[0x95] == 2) {
            if (0.0f < *(f32 *)(v + 0x30) && flag != 0) {
                func_L13_003AEB48(self);
                func_L01_004450F0(self, 0x16, -1);
            }
        }
    }
    if (v[0x5E] != 0 || *(f32 *)(self + 0x18) < D_L13_001DEBB0 - 5.0f || v[0x3E] == 2) {
        func_L13_003AE508(self);
        return 0;
    }
    obj = *(u8 **)(v + 0x3E0);
    p90 = v + 0x270;
    fp = v + 0x30;
    p84 = v + 0x2F0;
    p88 = v + 0x3F0;
    p94 = v + 0x470;
    p8c = v + 0x4F0;
    p80 = v + 0x570;
    if (obj != 0) {
        func_L01_0044FD88(self, obj, 4, 0);
        func_003C2EC0(*(void **)(v + 0x3E0), 0, &m[0]);
        t10 = m[3];
        cnt = D_L13_001DE790;
        if (cnt > 0) {
            f12 = D_L13_001DE794;
            i = 0;
            do {
                i++;
                func_003C4C18(&t10, f12);
                r = func_003824E0(D_L13_001DE7A0, D_L13_001DE7A4);
                func_0038CF68(&t20, &m[2], r * 0.020000001f);
                func_L05_00468EA8(&t10, &t20, D_L13_001DE760, func_00382468(2), func_00382468(3) - 1);
                f12 = D_L13_001DE794;
            } while (i < D_L13_001DE790);
        }
        func_0038CF68(&t70, &m[0], 0.5f);
        t10 = t70;
        t10.v[0] = t70.v[0] + m[3].v[0];
        t10.v[1] = t70.v[1] + m[3].v[1];
        t10.v[2] = t70.v[2] + m[3].v[2];
        if (D_L13_001DE790 > 0) {
            i = 0;
            do {
                i++;
                func_003C4C18(&t10, D_L13_001DE794);
                r = func_003824E0(D_L13_001DE7A0, D_L13_001DE7A4);
                func_0038CF68(&t20, &m[2], r * 0.020000001f);
                func_L05_00468EA8(&t10, &t20, D_L13_001DE778, func_00382468(2), func_00382468(3) - 1);
            } while (i < D_L13_001DE790);
        }
        func_0038CF68(&t70, &m[0], -0.5f);
        t10.v[0] = t70.v[0] + m[3].v[0];
        t10.v[1] = t70.v[1] + m[3].v[1];
        t10.v[2] = t70.v[2] + m[3].v[2];
        if (D_L13_001DE790 > 0) {
            i = 0;
            do {
                i++;
                func_003C4C18(&t10, D_L13_001DE794);
                r = func_003824E0(D_L13_001DE7A0, D_L13_001DE7A4);
                func_0038CF68(&t20, &m[2], r * 0.020000001f);
                func_L05_00468EA8(&t10, &t20, D_L13_001DE778, func_00382468(2), func_00382468(3) - 1);
            } while (i < D_L13_001DE790);
        }
    }
    func_L01_00452860(self, fp, 0);
    if (v[0x5F] != 0) {
        lvl = D_001D545C;
        if (lvl == 0x16 && *(s32 *)(v + 0x3E8) == 0) {
            *(s32 *)(v + 0x3E8) = 1;
            D_L13_001D67C4 = D_L13_001D67C4 + 1;
            if (D_L13_001D67C4 >= 0xF) {
                func_L01_00459C50(0x17);
            }
        }
        func_L01_00456BD0(self, 5);
        a5 = (self[0x20] < 8) ? *(s32 *)(v + 0x370) : *(s32 *)(v + 0x378);
        f12 = (self[0x20] < 8) ? *(f32 *)(v + 0x374) : *(f32 *)(v + 0x37C);
        func_L01_00456C98(self, a5, 0, 0, 0, 0, 3, 0, 0, 0, f12, 10.0f, 1.0f);
    } else {
        func_L01_00456BD0(self, 3);
        a5 = (self[0x20] < 8) ? *(s32 *)(v + 0x370) : *(s32 *)(v + 0x378);
        f12 = (self[0x20] < 8) ? *(f32 *)(v + 0x374) : *(f32 *)(v + 0x37C);
        func_L01_00456C98(self, a5, 0, 0, 0, 0, 1, (*(u32 *)(v + 0x3D0) != 0), 0, 0, f12, 10.0f, 1.0f);
    }
    *(u16 *)(self + 0x7C) = *(u16 *)(self + 0x7C) | 0xE0;
    func_L01_0044E850(self, p90, 0, 0.0432f, 0.43200004f);
    func_L01_0044E850(self, p84, 1, 0.0432f, 0.43200004f);
    func_L01_00451DF8(self, p88, 5, 1, 2.5f);
    func_L01_00451DF8(self, p94, 6, 1, 2.5f);
    func_L01_00451DF8(self, p8c, 7, 1, 2.5f);
    func_L01_00451DF8(self, p80, 8, 1, 2.5f);
    return 1;
}
/* localdecomp:end func_L13_003ADE00 */
