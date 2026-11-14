#include "common.h"

/* NTSC-U counterpart of func_L03_0032CBD8 (src/levels/03_starship_phoenix/L03_0032C3A8.c) */
/* localdecomp:start func_L03_0032C530 */
typedef struct {
    u8 pad0[0xEC];
    s32 wEC;
    u8 padF0;
    u8 bF1;
    u8 padF2[3];
    u8 bF5;
    u8 padF6[0x104 - 0xF6];
    s32 w104;
} Vars_32C530;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x47];
    Vars_32C530 *p68;
} Obj_32C530;
typedef struct {
    u8 pad0[0x18];
    s32 w18;
    u8 pad1C[0xC];
} Rec_32C530;
typedef struct {
    u8 pad0[0x1200];
    s32 w1200;
    u8 pad1204[0x24];
    s32 w1228;
    u8 pad122C[0x25CC - 0x122C];
    s32 w25CC;
    u8 pad25D0[0x2824 - 0x25D0];
    f32 f2824;
    u8 pad2828[0x28C9 - 0x2828];
    u8 b28C9;
} Hero_32C530;
extern Hero_32C530 D_001A4BE0;
extern Rec_32C530 D_L03_002AE550[];
extern u8 D_L03_00330100[];
extern s32 D_L03_001D7C20;
extern s32 D_L03_001DFB18;
__asm__(".extern D_L03_001D7C20, 16");
__asm__(".extern D_L03_001DFB18, 16");
extern s32 D_001D4C38_sda_0032C530;
__asm__(".extern D_001D4C38_sda_0032C530, 4");
extern void func_L03_0032C790(void *);
extern void func_L03_0032FCB0(void *);
extern void func_L03_0032CB68(void *);
extern s32 func_L03_0032DA18(void *, s32);
extern s32 func_L03_0032EF90(void *);
extern u8 *func_L01_004A72A8(s32, s32, void *, s32);
extern s32 func_00388398(s32 *);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00449AE8(s32);
extern void func_L01_00402498(void *, void *);
extern void func_L01_003EF820(void);

void func_L03_0032C530(Obj_32C530 *o) {
    Vars_32C530 *v = o->p68;
    s32 t;
    s32 q;
    Rec_32C530 *r;

    func_L03_0032C790(o);
    if ((u8)(o->b20 - 5) < 4) {
        t = v->wEC;
        if (t != -1) {
            q = t / 60;
            if (t % 60 == 0) {
                if (q == 5) {
                    func_L01_004A72A8(2, 0, o, 0x1936);
                } else if (q == 4) {
                    func_L01_004A72A8(3, 0, o, 0x1936);
                } else if (q == 3) {
                    func_L01_004A72A8(4, 0, o, 0x1936);
                } else if (q == 2) {
                    func_L01_004A72A8(5, 0, o, 0x1936);
                } else if (q == 1) {
                    func_L01_004A72A8(6, 0, o, 0x1936);
                }
                func_L03_0032FCB0(o);
            }
            if (func_00388398(&v->wEC) != 0) {
                v->w104 = (s32)func_L01_004A72A8(6, 0, o, 0x1936);
                v->wEC = 0x14;
                func_L03_0032CB68(o);
            }
        }
    }
    if ((u8)(o->b20 - 4) < 5) {
        r = &D_L03_002AE550[v->bF1];
        if (r->w18 != -1) {
            func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
            if (D_001A4BE0.w1200 == 0 || D_001A4BE0.w1228 != r->w18) {
                func_L01_00449AE8(r->w18);
                D_001A4BE0.b28C9 = 0;
            } else {
                D_001A4BE0.b28C9 = 1;
            }
            if (func_L03_0032DA18(o, r->w18) != 0) {
                func_L03_0032CB68(o);
            }
        }
        D_001A4BE0.f2824 = 25.0f;
    }
    if (o->b20 >= 2) {
        func_L01_00402498(D_L03_00330100, o);
    }
    if (func_L03_0032EF90(o) != 0) {
        s32 g = D_001D4C38_sda_0032C530;
        if (v->bF1 < 9) {
            D_L03_001D7C20 = v->bF1;
        } else {
            D_L03_001D7C20 = 9;
        }
        D_L03_001DFB18 = g;
    }
    if (D_001A4BE0.w25CC == 0x14 && v->bF5 == 0) {
        v->bF5 = 1;
        func_L01_003EF820();
    }
}
/* localdecomp:end func_L03_0032C530 */
