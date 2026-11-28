#include "common.h"
/* localdecomp:start func_L03_0034AB00 */
/* from the NTSC-U draft of func_L03_0034AB00 (nonmatching/levels/func_L03_0034AB00.c), PAL names */
typedef int Q_0034B6C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0034B6C0;
extern s32 func_L01_00448E90(void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L01_004367A0(void *, u16 *, s32 *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_0044FC98(void *, s32, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_L03_0034AFE0(void *arg0);
extern void func_003BD360(void *);
long func_L03_0034B0C0(f32 *a, f32 *b);
extern f32 func_0037E250(f32, f32);
extern u8 D_L03_001FC450[];
typedef struct { u8 pad[0x18]; u8 *f18; } G9200_0034B6C0;
typedef struct { u8 pad[0x20]; f32 f20; s32 f24; s32 f28; s32 f2C; } G24C0_0034B6C0;
extern G9200_0034B6C0 D_L03_001E9280;
extern G24C0_0034B6C0 D_L03_001E2540;

void func_L03_0034AB00(u8 *m) {
    V_0034B6C0 bottom, top;
    u16 result;
    s32 result2;
    u8 *v;
    s32 i;
    s32 j;
    s32 *ids;
    V_0034B6C0 *pb;
    u16 old;
    f32 height;

    if (!func_L01_00448E90(m + 0x10)) {
        return;
    }
    v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        *(u16 *)(m + 0x34) |= 0x100;
        *(u16 *)(v + 0x152) = 0;
        for (i = 0; i < 2; i++) {
            if (((s32 *)(v + 0x154))[i] != -1) (*(u16 *)(v + 0x152))++;
        }
        ids = (s32 *)(v + 0x154);
        for (j = 0; j < 2; j++) {
            if (D_L03_001FC450[ids[j]] == 255) {
                *(u16 *)(v + 0x152) = 0;
            }
        }
        *(f32 *)(m + 0x18) = func_003BE7F0(m + 0x10, 0, 0, 0.5f);
        func_L01_004367A0(m, &result, &result2);
        *(Q_0034B6C0 *)&bottom = *(Q_0034B6C0 *)(m + 0x10);
        *(Q_0034B6C0 *)&top = *(Q_0034B6C0 *)(m + 0x10);
        top.z += 0.5f;
        bottom.z -= 1.0f;
        *(u16 *)(m + 0x7C) = result;
        pb = &bottom;
        if (func_003CE740(&top, pb, 0, m, 0)) {
            if (D_L03_001E9280.f18) {
                u8 *other;
                *(u16 *)(v + 0x152) = 0;
                other = D_L03_001E9280.f18;
                *(u8 **)(v + 0x15C) = other;
                *(Q_0034B6C0 *)(m + 0xF0) = *(Q_0034B6C0 *)(other + 0x10);
            }
        }
        *(u16 *)(v + 0x152) |= 0x80;
        if (*(f32 *)(v + 0x30) <= 0.0f) {
            *(f32 *)(v + 0x30) = 30.0f;
        }
        if (*(s16 *)(v + 0x34) <= 0) {
            *(f32 *)(v + 0x30) = 30.0f;
        }
        func_L01_00441FB8(m, 1, -1);
    case 1:
        old = *(u16 *)(m + 0x7C);
        if (func_L01_0044FC98(m, 0, 0, 0)) {
            *(u16 *)(v + 0x36) = *(u16 *)(v + 0x150);
        }
        if (old != *(u16 *)(m + 0x7C) && !m[0xBC]) {
            func_0039FE80(0, 0, m);
            m[0xBC] = 20;
        }
        if (m[0xBC]) {
            m[0xBC]--;
        }
        if (*(f32 *)(v + 0x30) <= 0.0f) {
            V_0034B6C0 *p = &bottom;
            *(Q_0034B6C0 *)p = *(Q_0034B6C0 *)(m + 0xE0);
            func_00388830(p, p, 0.0333333351f);
            func_L01_0044ED60(m, 65535, p, 255, 180, 0, 0, 35, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
            func_0039FE80(0, 0, m);
            func_L03_0034AFE0(m);
            func_003BD360(m);
            return;
        }
        if (*(u8 **)(v + 0x15C)) {
            u8 *other = *(u8 **)(v + 0x15C);
            if (other[0x20] == 254 || (*(u8 **)(v + 0x15C))[0x20] == 253) {
                *(u8 **)(v + 0x15C) = 0;
                *(u16 *)(v + 0x152) &= 0xFF7F;
            }
        }
        if ((*(u8 **)(v + 0x15C) == 0 || func_L03_0034B0C0((f32 *)(*(u8 **)(v + 0x15C) + 0x10), (f32 *)(m + 0xF0))) && (*(u16 *)(v + 0x152) & 0x80)) return;
        *(u16 *)(v + 0x152) &= 0xFF7F;
        height = func_003BE7F0(m + 0x10, 0, 0, 0.5f);
        if (height < *(f32 *)(m + 0x18)) {
            *(f32 *)(m + 0x18) -= 0.0816666707f;
            if (*(f32 *)(m + 0x18) < height) {
                D_L03_001E2540.f20 = func_0037E250(0.0f, 0.25f);
                D_L03_001E2540.f28 = 20;
                D_L03_001E2540.f2C = 0;
                *(f32 *)(m + 0x18) = height;
                *(u16 *)(v + 0x152) |= 0x80;
            }
        }
        break;
    case 2:
        break;
    }
}
/* localdecomp:end func_L03_0034AB00 */
