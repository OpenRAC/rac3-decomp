/* functional: medium. From asm; gp globals named by address (gp=0x1DC8B0), table D_L30_0021F098 and its two selector int pairs inferred from hi/lo loads; types of unnamed ints guessed s32; 150 diff = scheduling. The two angle blocks are duplicated like retail */
#include "vu0.h"
extern f32 D_L30_001DD0A4;
__asm__(".extern D_L30_001DD0A4, 4");
extern f32 D_L30_001DD0A8;
__asm__(".extern D_L30_001DD0A8, 4");
extern f32 D_L30_001DD08C;
__asm__(".extern D_L30_001DD08C, 4");
extern f32 D_L30_001DD088;
__asm__(".extern D_L30_001DD088, 4");
extern f32 D_L30_001DD0B0;
__asm__(".extern D_L30_001DD0B0, 4");
extern f32 D_L30_001DD0AC;
__asm__(".extern D_L30_001DD0AC, 4");
extern f32 D_L30_001DD0BC;
__asm__(".extern D_L30_001DD0BC, 4");
extern f32 D_L30_001DD0B8;
__asm__(".extern D_L30_001DD0B8, 4");
extern f32 D_L30_001DD0B4;
__asm__(".extern D_L30_001DD0B4, 4");
extern s32 D_L30_001DD0A0;
__asm__(".extern D_L30_001DD0A0, 4");
extern s32 D_L30_001DD12C;
__asm__(".extern D_L30_001DD12C, 4");
extern s32 D_L30_001DD120;
__asm__(".extern D_L30_001DD120, 4");
extern s32 D_L30_001DD098;
__asm__(".extern D_L30_001DD098, 4");
extern s32 D_L30_001DD094;
__asm__(".extern D_L30_001DD094, 4");
extern s32 D_L30_001DD09C;
__asm__(".extern D_L30_001DD09C, 4");
extern s32 D_L30_001DD080;
__asm__(".extern D_L30_001DD080, 4");
extern s32 D_L30_001DD084;
__asm__(".extern D_L30_001DD084, 4");
extern s32 D_L30_001DD07C;
__asm__(".extern D_L30_001DD07C, 4");
extern s32 D_L30_001DD190;
__asm__(".extern D_L30_001DD190, 4");
extern s32 D_L30_001DD188;
__asm__(".extern D_L30_001DD188, 4");
extern s32 D_L30_001DD184;
__asm__(".extern D_L30_001DD184, 4");
extern f32 D_L30_001DD150[3];
__asm__(".extern D_L30_001DD150, 12");
extern s32 D_L30_001DD18C;
extern s32 D_L30_001DD194;
extern s32 D_L30_001DF2C0;
extern u8 *D_L30_0021F098[];
extern u8 D_L30_001E11C8[];
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_0034C958(vu0_v4 *, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L30_0034C8A8(void *, u8 *);

void func_L30_003478F0(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    vu0_v4 pos;
    vu0_v4 vel;
    f32 radius;
    f32 life;
    f32 sizeA;
    f32 sizeB;
    f32 speed;
    f32 ang;
    s32 r1;
    s32 r2;
    s32 col;
    s32 i;
    s32 k;
    u8 *p;

    for (k = 0; k < 3; k++) {
        f32 x = *(f32 *)(v + 0x58 + k * 4) + D_L30_001DD150[k];
        *(f32 *)(v + 0x58 + k * 4) = x - (f32)(s32)x;
    }
    for (i = 0; i < D_L30_001DD0A0; i++) {
        qzero(&pos);
        radius = func_003C4088(D_L30_001DD0A8, D_L30_001DD0A4,
                               func_L03_0034B440(1, 0, 5,
                                                 (f32)(D_L30_001DF2C0 + D_L30_001DD12C + *(s32 *)(v + 0x54) - D_L30_001DD120),
                                                 (f32)D_L30_001DD12C, 1.0f));
        func_L30_0034C958(&pos, radius);
        pos.y -= sqrt_asm(radius * radius - pos.x * pos.x - pos.z * pos.z);
        pos.x += *(f32 *)(obj + 0x10);
        pos.y += *(f32 *)(obj + 0x14);
        pos.z += *(f32 *)(obj + 0x18);
        r1 = func_00382498(D_L30_001DD098, D_L30_001DD094);
        r2 = func_00382498(-D_L30_001DD09C, D_L30_001DD09C);
        sizeA = func_003824E0(D_L30_001DD0B0, D_L30_001DD0AC);
        sizeB = func_003824E0(D_L30_001DD08C, D_L30_001DD088);
        speed = func_003824E0(D_L30_001DD0BC, D_L30_001DD0B8) * *(f32 *)(v + 0x50);
        if (*(s32 *)(v + 0x4C) != 0) {
            ang = *(f32 *)(v + 0x48) + 1.5707964f;
        } else {
            ang = *(f32 *)(v + 0x48) - 1.5707964f;
        }
        vel.x = func_0038D098(func_0038DB48(ang)) * speed;
        if (*(s32 *)(v + 0x4C) != 0) {
            ang = *(f32 *)(v + 0x48) + 1.5707964f;
        } else {
            ang = *(f32 *)(v + 0x48) - 1.5707964f;
        }
        vel.y = 0.0f;
        vel.z = func_0038D0B0(func_0038DB48(ang)) * speed;
        col = func_0038DBD8(D_L30_001DD080, D_L30_001DD084, func_003824E0(vel.y, 1.0f));
        p = func_L01_00475C60(&pos, &vel, r1, r2, col, D_L30_001DD07C, sizeA, sizeA / D_L30_001DD0B4, sizeB, 0);
        if (p != 0) {
            s32 sel;
            s32 off;
            if (func_00382498(0, 2) != 0) {
                off = D_L30_001DD194;
                sel = D_L30_001DD190;
            } else {
                off = D_L30_001DD18C;
                sel = D_L30_001DD188;
            }
            p[2] = *(u8 *)(D_L30_0021F098[sel] + off);
            p[3] = (func_00382498(0, D_L30_001DD184) != 0) ? 0x48 : 0x44;
        }
    }
    func_L30_0034C8A8(D_L30_001E11C8, obj);
}
