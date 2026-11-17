#include "common.h"

/* localdecomp:start func_L10_003BA538 */
typedef struct {
    s32 f0;
    f32 f4;
    s32 f8;
    s32 pad0C;
    s32 f10;
    f32 f14;
    f32 f18;
    s32 f1C;
    s32 pad20;
    s32 sound;
} V_3BA538;
extern u8 D_001426E0[];
extern u8 D_001A30B0[];
typedef struct {
    u8 pad0[0x228];
    f32 f228;
    f32 f22C;
    u8 pad230[8];
    f32 f238;
    f32 f23C;
    u8 pad240[0x10];
    s32 f250;
    s32 f254;
    s32 f258;
} G_3BA538;
typedef struct {
    u8 pad0[0x20];
    f32 f20;
    s32 pad24;
    s32 f28;
    s32 f2C;
    f32 f30;
    s32 pad34;
    s32 f38;
    s32 pad3C;
    f32 f40;
    s32 pad44;
    s32 f48;
} B_3BA538;
extern G_3BA538 D_L10_001E6700;
extern B_3BA538 D_L10_001E1BC0;
__asm__(".extern D_L10_001E6700, 16");
__asm__(".extern D_L10_001E1BC0, 16");
extern u8 D_L10_001DECE4;
extern u8 D_L10_001DECE5;
extern u8 D_L10_001DECE6;
extern f32 D_L10_001DECE8;
extern f32 D_L10_001DECEC;
extern f32 D_L10_001DECF0;
extern f32 D_L10_001DECF4;
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L10_003BA8E0(void *, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003873C0(void);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);

void func_L10_003BA538(u8 *m) {
    V_3BA538 *v = *(V_3BA538 **)(m + 0x68);
    u8 *e;
    s32 h;
    f32 f;
    f32 r;
    s32 n;

    if (func_L01_00456250(m) != 0 || D_001426E0[2] == 0 || D_001426E0[0x7A] != 0) {
        h = v->sound;
        if (h != -1) {
            e = D_001A30B0 + (h << 7);
            if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_003A4F28(h);
            }
        }
        v->sound = -1;
        func_L10_003BA8E0(m, 0);
        return;
    }
    func_L10_003BA8E0(m, 1);
    switch (m[0x20]) {
    case 0:
        v->sound = -1;
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            m[0x95] = 1;
        }
        {
            s32 k = v->sound;
            if (k == -1 || *(u8 **)((e = D_001A30B0 + (k << 7)) + 0xDC) != m || e[0xD0] == 0) {
                v->sound = func_003A52A0(0, 4, m);
            }
        }
        D_L10_001E6700.f250 = 0xF0;
        D_L10_001E6700.f254 = 0x1E;
        D_L10_001E6700.f258 = 0x14;
        D_L10_001E6700.f22C = 20480.0f;
        D_L10_001E6700.f228 = 0.0f;
        if (func_0038CAD0(&v->f1C) != 0) {
            v->f1C = v->f10;
        }
        f = func_0038D0B0((f32)v->f1C * 6.2831855f / (f32)v->f10) * 0.5f + 0.5f;
        f = func_003C4088(1.0f - v->f14, 1.0f - v->f18, f * f) * 255.0f;
        D_L10_001E6700.f238 = f;
        D_L10_001E6700.f23C = f - 1.0f;
        func_003873C0();
        if (func_00382468(v->f0 - 1) == 0) {
            r = func_003824E0(v->f4 * 0.25f, v->f4);
            n = (func_00382498(v->f8 >> 2, v->f8) * 5 + 2) / 6;
            func_003A52A0(1, 0x110, m);
            switch (func_00382468(3)) {
            case 0:
                D_L10_001E1BC0.f20 = r;
                D_L10_001E1BC0.f28 = n;
                D_L10_001E1BC0.f2C = 0;
                break;
            case 1:
                D_L10_001E1BC0.f30 = r;
                D_L10_001E1BC0.f38 = n;
                D_L10_001E1BC0.f2C = 0;
                break;
            case 2:
                D_L10_001E1BC0.f40 = r * 0.3f;
                D_L10_001E1BC0.f48 = n;
                D_L10_001E1BC0.f2C = 0;
                break;
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
    //P{
            D_L10_001E6700.f250 = D_L10_001DECE4;
            D_L10_001E6700.f254 = D_L10_001DECE5;
            D_L10_001E6700.f258 = D_L10_001DECE6;
            D_L10_001E6700.f22C = D_L10_001DECEC;
            D_L10_001E6700.f228 = D_L10_001DECE8;
            D_L10_001E6700.f23C = D_L10_001DECF4;
            D_L10_001E6700.f238 = D_L10_001DECF0;
            func_003873C0();
        }
        break;
    }
}
/* localdecomp:end func_L10_003BA538 */

/* localdecomp:start func_L10_003BA8E0 */
void func_L10_003BA8E0(void *arg0, s32 arg1) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_v1 + 0x20)) > 0) {
        *(s32 *)((u8 *)temp_v1 + 0x80) = (s32) (arg1 ^ 1);
    }
}
/* localdecomp:end func_L10_003BA8E0 */
