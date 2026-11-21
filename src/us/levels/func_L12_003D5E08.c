#include "common.h"

/* NTSC-U counterpart of func_L12_003D7BE8 (src/levels/shared/L12_003D7BE8.c) */
typedef struct { u8 pad[0x60]; u8 x60; } V_3D6A28;
typedef struct { u8 pad[0x68]; V_3D6A28 *x68; } M_3D6A28;
typedef struct { u8 pad[0x70]; u8 x70[0x100]; s32 x170; u8 pad174[0x18C - 0x174]; M_3D6A28 *x18C; } B_3D6A28;
typedef struct { u8 pad[0xA8]; u8 xA8; } O_3D6A28;

/* localdecomp:start func_L12_003D5E08 */
#include "vu0.h"

typedef int u128_003D7BE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D7BE8;
typedef struct { V4_003D7BE8 r[4]; } M4_003D7BE8;
typedef struct {
    u8 pad0[0x130];
    V4_003D7BE8 x130;
    u8 pad140[0x14C - 0x140];
    s16 x14C;
    u8 pad14E[0x174 - 0x14E];
    s32 x174;
    u8 pad178[0x17C - 0x178];
    s32 x17C;
    u8 pad180[0x190 - 0x180];
    f32 x190;
    f32 x194;
    s32 x198;
    f32 x19C;
    u8 pad1A0[0x220 - 0x1A0];
    u8 x220[0x284 - 0x220];
    f32 x284;
} Vars_003D7BE8;
typedef struct {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[0x43 - 0x21];
    u8 x43;
    u8 pad44[0x60 - 0x44];
    u8 x60;
    u8 pad61[0x68 - 0x61];
    Vars_003D7BE8 *x68;
    u8 pad6C[0x96 - 0x6C];
    u16 x96;
} Moby_003D7BE8;
typedef struct {
    u8 pad0[0xD0];
    u8 xD0;
    u8 padD1[0xDC - 0xD1];
    void *xDC;
} Ent_003D7BE8;

extern u8 D_001A30B0[];
extern u8 D_L12_001D6700_003D5E08[] __attribute__((section(".sdata")));
extern f32 D_L12_001DF058;
extern f32 D_L12_001DF05C;
extern f32 D_L12_001DF060;
extern s32 D_L12_001DF0D4_003D5E08;
extern s32 D_L12_001DF0D8_003D5E08;
extern s32 D_L12_001DF0DC_003D5E08;
extern s32 D_L12_001DF0E0_003D5E08;
extern s32 D_L12_001DF0E4_003D5E08;
extern s32 D_L12_001DF0E8;
extern s32 D_L12_001DF0EC;
extern f32 D_L12_001DF0F0;
extern s32 D_L12_001DF0F4;
extern s32 D_L12_001DF0F8;
extern f32 D_L12_001DF0FC;
extern f32 D_L12_001DF100;
extern f32 D_L12_001DF104;
extern f32 D_L12_001DF108;
extern f32 D_L12_001DF10C;
extern f32 D_L12_001DF110;
extern f32 D_L12_001DF114;
extern f32 D_L12_001DF118;
extern s32 D_L12_001DF8C0;
__asm__(".extern D_L12_001DF058, 4");
__asm__(".extern D_L12_001DF05C, 4");
__asm__(".extern D_L12_001DF060, 4");
__asm__(".extern D_L12_001DF0D4_003D5E08, 4");
__asm__(".extern D_L12_001DF0D8_003D5E08, 4");
__asm__(".extern D_L12_001DF0DC_003D5E08, 4");
__asm__(".extern D_L12_001DF0E0_003D5E08, 4");
__asm__(".extern D_L12_001DF0E4_003D5E08, 4");
__asm__(".extern D_L12_001DF0E8, 4");
__asm__(".extern D_L12_001DF0EC, 4");
__asm__(".extern D_L12_001DF0F0, 4");
__asm__(".extern D_L12_001DF0F4, 4");
__asm__(".extern D_L12_001DF0F8, 4");
__asm__(".extern D_L12_001DF0FC, 4");
__asm__(".extern D_L12_001DF100, 4");
__asm__(".extern D_L12_001DF104, 4");
__asm__(".extern D_L12_001DF108, 4");
__asm__(".extern D_L12_001DF10C, 4");
__asm__(".extern D_L12_001DF110, 4");
__asm__(".extern D_L12_001DF114, 4");
__asm__(".extern D_L12_001DF118, 4");

extern s32 func_L12_003D66C0(void *, void *);
extern void func_L12_003D6C18(void *, s32);
extern void func_L12_003D6D40(void *, void *, s32);
extern void func_L12_003D6E50(void *);
extern void func_L12_003D6FD8(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00389380(f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_L01_004026A0(void *, void *);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003BD9A0(void *, s32, void *);
extern void func_L07_003C9438(void *, void *, void *, s32, void *, s32, u32, f32, f32);
extern void func_L01_00467DA8(void *, f32, s32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_0046D570(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00443648(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00452F40(void *, s32);

void func_L12_003D5E08(Moby_003D7BE8 *o) {
    Vars_003D7BE8 *v = o->x68;
    Ent_003D7BE8 *e;
    s32 h;
    f32 f;
    s32 i;
    V4_003D7BE8 pos;
    V4_003D7BE8 dir;
    V4_003D7BE8 rnd;
    M4_003D7BE8 m;
    V4_003D7BE8 end;
    V4_003D7BE8 start;
    V4_003D7BE8 at;

    if (o->x20 == 0 && func_L12_003D66C0(o, v) == 0) {
        return;
    }
    if (func_L12_003D6A28((O_3D6A28 *)o, (B_3D6A28 *)v) == 0) {
        func_L12_003D6C18(o, 1);
        return;
    }
    switch (o->x20) {
    case 1:
        if (func_L01_00452EC8(o)) {
            func_003BE4F0(o, 1, 0, 15);
        }
        h = v->x17C;
        if (h != -1) {
            e = (Ent_003D7BE8 *)(D_001A30B0 + h * 0x80);
            if (e->xDC == o && e->xD0 != 0) {
                func_0039FB08(h);
            }
        }
        v->x17C = -1;
        func_L12_003D6D40(o, v, 0);
        func_L12_003D6E50(o);
        if (v->x14C != 0) {
            func_L01_00441FB8(o, 2, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(o)) {
            func_003BE4F0(o, 2, 0, 5);
        }
        func_L12_003D6D40(o, v, 1);
        if (o->x60 & 2) {
            func_003BE4F0(o, 3, 0, 5);
            func_L01_00441FB8(o, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(o)) {
            if (v->x17C == -1 || ((Ent_003D7BE8 *)(D_001A30B0 + v->x17C * 0x80))->xDC != o
                || ((Ent_003D7BE8 *)(D_001A30B0 + v->x17C * 0x80))->xD0 == 0) {
                v->x17C = func_0039FE80(0, 4, o);
            }
        }
        if (o->x43 != 3) {
            func_003BE4F0(o, 3, 0, 10);
        }
        func_L12_003D6D40(o, v, 1);
        func_L12_003D6E50(o);
        v->x190 += D_L12_001DF05C;
        if (D_L12_001DF058 <= v->x190) {
            v->x190 = D_L12_001DF058;
            func_L01_00441FB8(o, 5, -1);
        }
        v->x284 = v->x194 = func_00389380(v->x194, v->x190);
        func_L01_0044B5C8(o, v->x220, 2, 0.0299999993f, 0.300000012f);
        if (v->x14C == 0) {
            func_L01_00441FB8(o, 4, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(o)) {
            func_003BE4F0(o, 1, 0, 15);
        }
        func_L12_003D6D40(o, v, 1);
        func_L12_003D6E50(o);
        v->x190 -= D_L12_001DF060;
        if (v->x190 <= 0.0f) {
            v->x190 = 0.0f;
            func_L01_00441FB8(o, 1, -1);
        }
        v->x284 = v->x194 = func_00389380(v->x194, v->x190);
        func_L01_0044B5C8(o, v->x220, 2, 0.0299999993f, 0.300000012f);
        h = v->x17C;
        if (h != -1) {
            e = (Ent_003D7BE8 *)(D_001A30B0 + h * 0x80);
            if (e->xDC == o && e->xD0 != 0) {
                func_0039FB08(h);
            }
        }
        v->x17C = -1;
        if (v->x14C != 0) {
            func_L01_00441FB8(o, 3, -1);
        }
        break;
    case 5:
        o->x96++;
        if (o->x43 != 3) {
            func_003BE4F0(o, 3, 0, 10);
        }
        func_L12_003D6D40(o, v, 1);
        func_L12_003D6E50(o);
        v->x284 = v->x194 = func_00389380(v->x194, v->x190);
        func_L01_0044B5C8(o, v->x220, 2, 0.0299999993f, 0.300000012f);
        if (v->x198 != 0) {
            func_L01_004026A0(func_L12_003D6FD8, o);
        }
        if (v->x14C == 0) {
            func_L01_00441FB8(o, 4, -1);
        } else {
            func_003BDA38(o, 3, &pos);
            for (i = 0; i < D_L12_001DF0F4; i++) {
                *(u128_003D7BE8 *)&rnd = 0;
                rnd.x = func_0037E250(D_L12_001DF0FC, D_L12_001DF100);
                rnd.y = func_0037E250(D_L12_001DF0FC, D_L12_001DF100);
                rnd.z = func_0037E250(D_L12_001DF104, D_L12_001DF108);
                dir = rnd;
                func_00388830(&dir, &dir, D_L12_001DF0F0 * 0.0166666675f);
                func_L01_00460318(&pos, &dir,
                                  (D_L12_001DF0E0_003D5E08 << 24) | (D_L12_001DF0DC_003D5E08 << 16) | (D_L12_001DF0D8_003D5E08 << 8) | D_L12_001DF0D4_003D5E08,
                                  (D_L12_001DF0DC_003D5E08 << 16) | (D_L12_001DF0D8_003D5E08 << 8) | D_L12_001DF0D4_003D5E08,
                                  D_L12_001DF0E4_003D5E08, D_L12_001DF0E8, D_L12_001DF0EC, D_L12_001DF0F8);
            }
            if (o->x96 >= 11) {
                v->x198 = 5;
                o->x96 = 0;
                func_003BD9A0(o, 3, &m);
                dir = m.r[1];
                rnd = m.r[3];
                func_00388830(&dir, &dir, D_L12_001DF10C * 0.0166666675f);
                start = m.r[3];
                at = m.r[3];
                vec_add_ab(&end, &start, &dir);
                func_L07_003C9438(&start, &dir, o, 0, 0, -1, 0xFFFFFFFF, D_L12_001DF110, v->x19C);
                func_L01_00467DA8(&at, D_L12_001DF114 * 7.0f, 9, 0.1f, 0xBF204080, 2, 1, D_L12_001D6700_003D5E08, 0.0f, 1);
                func_L01_00467DA8(&at, D_L12_001DF114 * 5.0f, 9, 0.1f, 0xBF2040A0, 2, -1, D_L12_001D6700_003D5E08, 0.0f, 1);
                func_L01_00467DA8(&at, D_L12_001DF114 * 3.5f, 9, 0.1f, 0xC0FFFFFF, 2, 1, D_L12_001D6700_003D5E08, 0.0f, 1);
                func_L01_00467DA8(&at, D_L12_001DF114 * 2.5f, 9, 0.1f, 0xB0FFFFFF, 2, -1, D_L12_001D6700_003D5E08, 0.0f, 1);
                func_L01_0046D570(&at, 7, 1.08f, 0.84000003f, 0x46787878, 2, 2, D_L12_001D6700_003D5E08, 0, 2, 6, 1);
                func_L01_0046D570(&at, 10, 2.0400002f, 0.84000003f, 0x46787878, 2, -1, D_L12_001D6700_003D5E08, 1, 2, 6, 1);
                func_L01_0046D570(&at, 10, 2.4f, 1.8000001f, 0x2D787878, 2, 1, D_L12_001D6700_003D5E08, 1, 2, 6, 1);
            }
            if ((D_L12_001DF8C0 & 0xF) == (((s32)o >> 8) & 0xF)) {
                f = D_L12_001DF118 * D_L12_001DF118;
                if (func_L01_0040C018(&pos, &v->x130) < f) {
                    func_L01_00443648((u8 *)o, (u8 *)&v->x130, 0x10001, 1, 1, 0, 0.5f, v->x19C * 3.0f, 1.0f);
                }
            }
        }
        break;
    }
    if (v->x14C == 0 || v->x174 != 0) {
        func_L01_00452F40(o, 1);
    } else {
        func_L01_00452F40(o, 0);
    }
}
/* localdecomp:end func_L12_003D5E08 */
