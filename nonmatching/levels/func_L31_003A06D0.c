/* NTSC-U draft (Claude wave C4): C of func_L31_0039EF10, the NTSC-U twin of func_L31_003A06D0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L31_0039EF10", whose code is not the PAL one).
 * Worker's note: flags: needs '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' - the PAL line's -mno-split-addresses must go (retail splits lui/addiu of D_L31_002BEC80 and D_001A30B0 across delay slots) and -mvu0-use-vf0-vf2 must be added; 17 normalized ...
 */
#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x10];
    f32 vx;
    f32 vy;
    f32 vz;
    s32 w1C;
    f32 f20;
    f32 f24;
    s32 w28;
    f32 f2C;
    s32 w30;
    s32 w34;
    f32 f38;
    s32 w3C;
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w4C;
    s32 w50;
    u8 pad54[0xC];
    f32 f60;
} Priv_0039EF10;

typedef struct {
    u8 pad00[0x18];
    u8 *p18;
    u8 pad1C[4];
    vu0_v4 v20;
} Glob_0039EF10;

typedef struct {
    u8 pad00[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    u8 *ownerDC;
} Slot_0039EF10;

/* localdecomp:start func_L31_0039EF10 */
__asm__(".extern D_001DE780_sda, 4");
__asm__(".extern D_001DE784_sda, 4");
__asm__(".extern D_001DE78C_sda, 4");
__asm__(".extern D_001DE794_sda, 4");
__asm__(".extern D_001DE798_sda, 4");
__asm__(".extern D_001DE720_sda, 4");
__asm__(".extern D_001DE724_sda, 4");
extern f32 D_001DE780_sda;
extern f32 D_001DE784_sda;
extern f32 D_001DE78C_sda;
extern f32 D_001DE794_sda;
extern f32 D_001DE798_sda;
extern s32 D_001DE720_sda;
extern s32 D_001DE724_sda;
extern Glob_0039EF10 D_L31_001E9200;
extern u8 D_001A30B0[];
extern void func_L31_0039FA20(void *);
extern s32 func_L01_00452F60(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L31_0039F570(void *);
extern f32 func_00389410(f32);
extern s32 func_L01_00452EC8(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_003F9498(void *, f32, s32, void *);
extern s32 func_00388398(void *);
extern void func_L01_00443648(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_L01_00438908(void *, s32, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern u8 *func_L31_0039FAF0(s32, void *, void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00452F40(void *, s32);
extern void func_L31_0039FAB0(void *);
extern void func_L31_0039F4C8(void *);

void func_L31_0039EF10(u8 *obj) {
    Priv_0039EF10 *p;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    u8 *carrier;
    u8 *slot;
    vu0_v4 *pv40;
    u8 *tgt;
    f32 a;
    f32 b;
    f32 t;
    f32 k;
    f32 q;
    s32 i;
    s32 h;

    p = *(Priv_0039EF10 **)(obj + 0x68);
    a = D_001DE780_sda;
    if (p->w3C == 0) {
        a = a * p->f60;
    }
    b = D_001DE784_sda;
    if (p->w3C == 0) {
        b = b * p->f60;
    }
    switch (obj[0x20]) {
    case 0:
        func_L31_0039FA20(obj);
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        if (func_L01_00452F60(obj) != 0) {
            func_L01_00441FB8(obj, 2, -1);
        }
        func_L31_0039F570(obj);
        *(f32 *)(obj + 0xF0) = func_00389410(0.0f);
        *(f32 *)(obj + 0xF8) = -1.5707964f;
        func_L01_00438908(obj, 0xFF, 0xFF, 0xFF);
        h = p->w34;
        if (h == -1 || *(u8 **)((slot = D_001A30B0 + h * 128) + 0xDC) != obj || slot[0xD0] == 0) {
            p->w34 = func_0039FE80(1, 4, obj);
        }
        break;
    case 2:
        if (func_L01_00452EC8(obj) != 0 && obj[0x43] != 1) {
            func_003BE4F0(obj, 1, 0, 5);
        }
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
        p->vx = p->vx + p->f20;
        p->vz = p->vz + p->f24;
        vec_add_ba(&v10, obj + 0x10, &p->vx);
        if (func_L01_003F9498(&v10, a, 0x12, obj) != 0 || func_00388398(&p->w28) != 0) {
            if (D_L31_001E9200.p18 != 0) {
                p->w40 = (s32)D_L31_001E9200.p18;
            }
            *(vu0_q *)(obj + 0x10) = *(vu0_q *)&D_L31_001E9200.v20;
            func_L01_00441FB8(obj, 3, -1);
        } else {
            *(vu0_q *)(obj + 0x10) = *(vu0_q *)&v10;
        }
        if (p->w3C != 0) {
            func_L01_00443648(obj, obj + 0x10, 1, 0, 1, 0, a, p->f2C, 1.0f);
        }
        func_L31_0039F570(obj);
        if (p->vz != 0.0f) {
            if (p->vx == 0.0f) {
                *(f32 *)(obj + 0xF0) = 0.0f;
            } else {
                *(f32 *)(obj + 0xF0) = func_00388A28(p->vx, p->vz);
                *(f32 *)(obj + 0xF0) = func_00389380(*(f32 *)(obj + 0xF0), (p->vx < 0.0f) ? D_001DE794_sda : D_001DE798_sda);
            }
            *(f32 *)(obj + 0xF8) = -1.5707964f;
            func_L01_00438908(obj, 0xFF, 0xFF, 0xFF);
            h = p->w34;
            if (h == -1 || *(u8 **)((slot = D_001A30B0 + h * 128) + 0xDC) != obj || slot[0xD0] == 0) {
                p->w34 = func_0039FE80(1, 4, obj);
            }
        }
        break;
    case 3:
        carrier = 0;
        tgt = (u8 *)p->w40;
        if (tgt != 0 && (*(u16 *)(tgt + 0x34) & 0x20) != 0) {
            carrier = *(u8 **)(*(u8 **)(tgt + 0x68) + 8);
        }
        if (func_L01_00452EC8(obj) != 0) {
            if (p->w3C != 0) {
                func_0039FE80(0, 0, obj);
            }
            *(s32 *)(obj + 0x98) = 0;
            *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(obj, 1);
            p->w28 = D_001DE724_sda;
            if (p->w3C != 0) {
                pv40 = &v40;
                for (i = 0; i < D_001DE720_sda; i++) {
                    *(vu0_q *)&v40 = 0;
                    v40.y = 1.0f;
                    v40.w = 1.0f;
                    func_00388830(&v20, &p->vx, p->f38);
                    t = func_003BEB48(2.042035f, 4.2411504f, (f32)i / (f32)D_001DE720_sda);
                    func_00389158(&v20, &v20, pv40, t);
                    if (carrier != 0) {
                        vec_add_ab(&v20, &v20, carrier + 0x10);
                    }
                    func_003886E8(&v10, &v20, D_001DE78C_sda);
                    vec_add_ba(&v10, obj + 0x10, &v10);
                    qzero(&v30);
                    v30.x = p->f20;
                    v30.z = p->f24;
                    func_L01_00452F40(func_L31_0039FAF0(p->w30, &v20, &v10, &v30, p->w44, p->w48, p->w4C, p->w50, 1.0f, p->f38, p->f60, 0), 1);
                }
            }
        }
        if (carrier != 0) {
            vec_add_ab(obj + 0x10, obj + 0x10, carrier + 0x10);
            q = *(f32 *)(carrier + 0x18);
            if (q < 0.0f) {
                *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) - q;
            }
        }
        k = (f32)(D_001DE724_sda - p->w28) / (f32)D_001DE724_sda;
        func_L31_0039F570(obj);
        if (p->w3C != 0) {
            func_L01_00443648(obj, obj + 0x10, 1, 0, 1, 0, func_003BEB48(a, b, 1.0f - k), 20.0f, 1.0f);
        }
        if (func_00388398(&p->w28) != 0) {
            func_L01_00441FB8(obj, 4, -1);
        }
        break;
    case 4:
        func_L31_0039FAB0(obj);
        return;
    }
    if (p->w3C > 0) {
        func_L31_0039F4C8(obj);
    }
}
/* localdecomp:end func_L31_0039EF10 */
