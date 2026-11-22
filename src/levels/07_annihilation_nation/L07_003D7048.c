#include "common.h"

/* localdecomp:start func_L07_003D7048 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern s32 D_001D545C;
extern u8 D_0014275B[];
extern f32 D_L07_001DA978;
extern f32 D_L07_002F3630[];
extern s32 D_L07_001D66B0;
__asm__(".extern D_L07_001D66B0, 16");
__asm__(".extern D_001D545C, 4");
__asm__(".extern D_0014275B, 16");
__asm__(".extern D_L07_001DA978, 4");
void func_L07_003D7048(u8 *obj) {
    extern void func_L07_003D7350(u8 *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern s32 func_L01_004561B8(void *);
    extern void func_003A52A0(s32, s32, void *);
    extern void func_L01_00404808(void (*)(void *), void *);
    extern void func_L07_003D7628(void *);
    extern s32 func_00382468(s32);
    extern void func_L07_003D7520(void *, void *, s32);
    extern void func_L03_003A1EB0(void *);
    extern f32 func_L01_0040E570(void *, void *);
    extern s32 func_L01_0041A4F0(void);
    extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
    extern void func_L01_004AA760(s32, void *);
    extern f32 func_003C3BE8(f32, f32, f32);
    extern void func_003C7C38(void *);
    vu0_v4 position;
    u8 *p;
    struct Hero *hero;
    func_L07_003D7350(obj);
    p = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0: break;
    case 1:
        if (p[8] == 2) func_L01_004450F0(obj, 4, -1);
        break;
    case 2:
        if (func_L01_004561B8(obj)) func_003A52A0(1, 4, obj);
        if (obj[0x31]) {
            func_L01_00404808(func_L07_003D7628, obj);
            if (func_00382468(10) == 0) {
                func_L07_003D7520(obj, &position, func_00382468(12));
                func_L03_003A1EB0(&position);
            }
        }
        if (func_L01_0040E570(obj + 0x10, &D_001A4BE0.pos) < 9.0f) {
            hero = &D_001A4BE0;
            if (fabs_asm(*(f32 *)(obj + 0x18) - hero->pos.z) < 0.75f) {
            f32 damage;
            s32 level;
            if (func_L01_0041A4F0()) {
                level = D_001D545C;
                if (level == 7 && D_0014275B[0]) damage = D_L07_001DA978;
                else damage = D_L07_002F3630[level];
            } else damage = 1.0f;
            func_L01_00446A70(hero->hero_moby, obj, 1,
                              &D_L07_001D66B0, &D_L07_001D66B0, damage);
        }
        }
        if (p[8] == 1) {
            func_L01_004AA760(1, obj);
            func_L01_004450F0(obj, 5, -1);
        }
        break;
    case 3: break;
    case 4:
        if (func_L01_004561B8(obj)) func_003A52A0(0, 4, obj);
        *(f32 *)(p + 0x14) += 0.012f;
        if (*(f32 *)(p + 0x14) >= 1.0f) {
            *(f32 *)(p + 0x14) = 1.0f;
            func_L01_004AA760(0, obj);
            func_L01_004450F0(obj, 2, -1);
        }
        *(f32 *)(obj + 0xF0) = func_003C3BE8(3.1415927f, 0.0f, *(f32 *)(p + 0x14));
        *(f32 *)(*(u8 **)(p + 0x10) + 0xF0) = *(f32 *)(obj + 0xF0);
        func_003C7C38(*(void **)(p + 0x10));
        break;
    case 5:
        if (func_L01_004561B8(obj)) func_003A52A0(0, 4, obj);
        *(f32 *)(p + 0x14) -= 0.012f;
        if (*(f32 *)(p + 0x14) <= 0.0f) {
            *(f32 *)(p + 0x14) = 0.0f;
            func_L01_004AA760(0, obj);
            func_L01_004450F0(obj, 1, -1);
        }
        *(f32 *)(obj + 0xF0) = func_003C3BE8(3.1415927f, 0.0f, *(f32 *)(p + 0x14));
        *(f32 *)(*(u8 **)(p + 0x10) + 0xF0) = *(f32 *)(obj + 0xF0);
        func_003C7C38(*(void **)(p + 0x10));
        break;
    }
}
/* localdecomp:end func_L07_003D7048 */

/* localdecomp:start func_L07_003D7350 */
typedef int Quad_003D7350 __attribute__((mode(TI)));
extern u8 D_L07_001DE890;
__asm__(".extern D_L07_001DE890, 1");
extern s32 D_L07_002A3740[];
extern s32 D_L07_002A38C0[];
extern f32 D_L07_002A3A40[][2];
void func_L07_003D7350(u8 *obj)
{
    extern u8 *func_003C24B0(s32, s32);
    extern void func_003C7C38(void *);
    extern void func_L07_003D74A0(u8 *);
    u8 *state;
    u8 *p;
    s32 i;
    if (obj[0x20] == 0) {
        state = *(u8 **)(obj + 0x68);
        if (!D_L07_001DE890) {
            for (i = 0; i < 96; i++) {
                D_L07_002A3740[i] = -1;
                D_L07_002A38C0[i] = 0x20FF8000;
                D_L07_002A3A40[i][0] = (i & 2) >> 1;
                D_L07_002A3A40[i][1] = i & 1;
            }
            D_L07_001DE890 = 1;
        }
        p = func_003C24B0(0x1D2D, 0x80);
        if (p) {
            u8 *model = *(u8 **)(p + 0x24);
            p[0x31] = 1;
            *(u16 *)(p+0x32) = *(u16 *)(obj+0x32);
            p[0x30] = obj[0x30];
            *(unsigned long *)(p+0x38) = *(unsigned long *)(obj+0x38);
            *(f32 *)(p+0x2C) = *(f32 *)(model+0x24) * 1.6f;
            *(Quad_003D7350 *)(p+0x10) = *(Quad_003D7350 *)(obj+0x10);
            *(Quad_003D7350 *)(p+0xF0) = *(Quad_003D7350 *)(obj+0xF0);
            func_003C7C38(p);
        }
        *(u8 **)(state+0x10) = p;
        *(void (**)(u8 *))(state+4) = func_L07_003D74A0;
        func_L07_003D74A0(obj);
    }
}
/* localdecomp:end func_L07_003D7350 */

/* localdecomp:start func_L07_003D74A0 */
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C7C38(void *);
extern void func_L01_004AA760(s32, void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003D74A0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 r;

    *(s32 *)(s + 0x14) = 0;
    r = func_003C3BE8(3.1415927f, *(f32 *)(s + 0x14), *(f32 *)(s + 0x14));
    *(f32 *)(a0 + 0xF0) = r;
    *(f32 *)(*(u8 **)(s + 0x10) + 0xF0) = r;
    func_003C7C38(*(void **)(s + 0x10));
    func_L01_004AA760(1, a0);
    s[8] = 1;
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L07_003D74A0 */

/* localdecomp:start func_L07_003D7520 */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003D7520;
void func_L07_003D7520(void *obj_,void *out_,s32 index) {
    u8 *obj = obj_;
    V_003D7520 *out = out_;
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    V_003D7520 delta;
    s32 ring;
    u8 segment;
    f32 angle, radius, base, step;
    step=0.5235988f;
    if(index>=6) { segment=index-6;ring=1; }
    else { segment=index;ring=0; }
    base=(f32)segment;
    base+=base;
    base+=(f32)ring;
    angle=func_0038DB48(*(f32 *)(obj+0xf8)+step*base);
    radius=1.2f;
    if(ring) radius=2.5f;
    delta.x=func_0038D098(angle)*radius;
    delta.y=func_0038D0B0(angle)*radius;
    delta.z=0;
    vec_add_ab(out, obj + 16, &delta);
    out->z+=0.45f;
}
/* localdecomp:end func_L07_003D7520 */

/* localdecomp:start func_L07_003D7628 */
extern void func_L07_003D7680(void *, f32, f32, s32);

void func_L07_003D7628(void *arg0) {
    func_L07_003D7680(arg0, 2.5f, 0.0f, 8);
    func_L07_003D7680(arg0, 1.2f, 0.5235988f, 6);
}
/* localdecomp:end func_L07_003D7628 */

INCLUDE_ASM("asm/levels", func_L07_003D7680);
