#include "common.h"

typedef struct {
    void (*f0)(u8 *);
    void (*f4)(u8 *);
} Vt003D1AA8;
typedef struct {
    s32 a;
    f32 b;
    s32 c;
    f32 d;
} Src_3D1EB8;

typedef struct {
    u8 pad0[0x19E0];
    u8 *f19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    s32 f25C0;
} G_003D1BE8;
typedef struct {
    u8 pad0[0x140];
    s32 f140;
    u8 pad144[0x160 - 0x144];
    u8 f160[0x1C8 - 0x160];
    f32 f1C8;
    u8 pad1CC[0x1E0 - 0x1CC];
    u8 f1E0[0x240 - 0x1E0];
    f32 f240;
    u8 pad244[0x274 - 0x244];
    f32 f274;
    f32 f278;
} P_003D1BE8;

/* declared by functions of L12_003D2E60.c, which this file was cut from */
extern f32 D_L12_001DEF10;
extern void func_L12_003D3978(u8 *, u8 *);
extern void func_L12_003D3A80(u8 *, u8 *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L01_0040E570(void *, void *);

/* localdecomp:start func_L12_003D3978 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D3978;
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 D_L01_001DEEE4;
extern f32 D_L01_001DEF0C;
extern f32 D_L01_001DEF10;
__asm__(".extern D_L01_001DEEE4, 4");
__asm__(".extern D_L01_001DEF0C, 4");
__asm__(".extern D_L01_001DEF10, 4");

void func_L12_003D3978(u8 *obj, u8 *p) {
    V4_003D3978 t;
    V4_003D3978 q;
    V4_003D3978 d;
    f32 k;
    f32 r;
    f32 dist;

    if (*(s16 *)(p + 0x14C) != 0) {
        k = 0.017453292f;
        func_003C2F58(obj, 1, &t);
        q = *(V4_003D3978 *)(p + 0x130);
        vec_sub_ab(&d, &q, &t);
        r = func_0038D160(d.x, d.y);
        r = func_0038DAB8(r, D_L01_001DEEE4 * k);
        *(f32 *)(p + 0x274) = r;
        *(f32 *)(p + 0x274) = func_0038DAB8(r, *(f32 *)(p + 0x27C));
        dist = func_L01_0040E570(obj + 0x10, &q);
        if (dist < D_L01_001DEF10 * D_L01_001DEF10) {
            r = -func_0038D160(func_0038CED8(&d), d.z);
        } else {
            r = -func_0038D160(func_0038CED8(&d), d.z);
            r = func_0038DAB8(r, D_L01_001DEF0C * k);
        }
        *(f32 *)(p + 0x278) = r;
    }
}
/* localdecomp:end func_L12_003D3978 */

/* localdecomp:start func_L12_003D3A80 */
#include "vu0.h"
typedef struct { vu0_v4 a; vu0_v4 b; vu0_v4 c; } T_003D3A80;
extern f32 D_L12_001DEF18;
__asm__(".extern D_L12_001DEF18, 4");
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L12_003D50C8(u8 *, u8 *, u8 *, u8 *, f32);

void func_L12_003D3A80(u8 *obj, u8 *other) {
    vu0_v4 v0;
    T_003D3A80 t;
    vu0_v4 w;

    func_003C2EC0(obj, 1, &t);
    vec_neg(&t.b, &t.b);
    func_0038CE20(&v0, &t.b, D_L12_001DEF18);
    func_L12_003D50C8(obj, *(u8 **)(other + 0x140), (u8 *)&w, (u8 *)&v0, (f32)other[0x44]);
}
/* localdecomp:end func_L12_003D3A80 */
