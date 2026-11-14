#include "common.h"

typedef struct {
    s16 h70;
    u8 pad72[2];
    u8 r;
    u8 g;
    u8 b;
    u8 b77;
    u8 pad78[8];
} Col_003B4518;

typedef struct {
    u8 pad00[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x47 - 0x36];
    u8 b47;
    u8 pad48[0x5E - 0x48];
    u8 b5E;
    u8 pad5F;
    u8 b60;
    u8 pad61[0x70 - 0x61];
    Col_003B4518 col;
    u8 pad80[0x190 - 0x80];
    s32 w190;
    u8 pad194[0x300 - 0x194];
    s32 w300;
    u8 pad304[4];
    u8 *w308;
    u8 pad30C[0x321 - 0x30C];
    u8 b321;
    u8 pad322[2];
    u8 b324;
    u8 pad325;
    u8 b326;
    u8 pad327[0x330 - 0x327];
    s16 h330;
    u8 pad332[0x33C - 0x332];
    s32 w33C;
} Priv_003B4518;

typedef struct {
    u8 pad000[0x144];
    u8 *f144;
    s32 f148;
} Glob_003B4518;

/* localdecomp:start func_L07_003B4518 */
extern s32 D_L07_001DF41C_sda;
__asm__(".extern D_L07_001DF41C_sda, 4");
extern u8 *D_L07_001DF41C_003B4518;
extern u8 D_L07_001D66B0[8];
__asm__(".extern D_L07_001D66B0, 16");
extern Glob_003B4518 D_L07_001E1EC0_003B4518;
extern s32 func_L01_00444358(void *, s32, s32);
extern f32 func_L01_004443B0(void *, s32);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
extern void func_L01_004568F8(void *, s32, f32);
extern void func_003BF4F8(void *, void *);
extern void func_L01_004479A8(void *, void *);
extern void func_L01_0044B598(void *, s32);
extern s32 func_003883C8(void *);
extern void func_L07_003A0BC0(s32, void *, s32, s32);
extern void func_L07_003B4BE0(u8 *, s32);
extern void func_L01_00438908(u8 *, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, f32, u8 *, f32, f32, f32, s32, s32, f32, f32, s32, f32, s32, s32, s32, s32, f32);
extern void func_L07_00330E70(void *);
extern void func_L01_00479140(s32, s32, u8, f32);
extern void func_L01_004538E0(void *, s32);
extern s32 func_L07_003335E0(s32);
extern void func_L01_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L07_003B4F80(u8 *);
extern void func_L07_0044F0E8(u8 *, s32, void *, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);

void func_L07_003B4518(u8 *obj) {
    Priv_003B4518 *p;
    Col_003B4518 *pc;
    s32 v;
    u8 ff;
    f32 d;
    f32 k;
    Col_003B4518 c;
    u8 *g;
    u8 *q;

    p = *(Priv_003B4518 **)(obj + 0x68);
    if (obj[0x20] == 1) {
        return;
    }
    ff = 0xFF;
    v = func_L01_00444358(obj, -1, 0);
    pc = &p->col;
    d = func_L01_004443B0(obj, v);
    obj[0xA8] = ff;
    if (*(u16 *)(obj + 0x34) & 0x4000) {
        if (d > 0.0f) {
            if (p->h330 == 0) {
                func_L01_004A72A8(0, 0, obj, 0x1A1C);
                p->h330 = 0x3C;
            }
            p->f30 = p->f30 - d;
            func_L01_004568F8(obj, p->b47, d);
            p->col.b77 = ff;
            func_003BF4F8(obj, pc);
            if ((f32)p->h34 * 0.1f <= d) {
                u8 *e = (u8 *)D_L07_001DF41C_sda + (p->w300 << 8);
                if (e[0xBC] == 0) {
                    e[0xBC] = 2;
                }
            }
        }
    }
    func_L01_004479A8(obj, pc);
    if (p->col.h70 == 0) {
        func_L01_0044B598(obj, p->w33C);
    }
    func_003883C8(&p->h330);
    if (p->b321 == 0) {
        k = 0.66f;
        if (p->f30 < (f32)p->h34 * k) {
            func_L07_003A0BC0(6, obj, 0, 0x78);
            func_L07_003B4BE0(obj, 0x12);
            p->b321 = 1;
            p->b326 = 3;
            p->f30 = (f32)p->h34 * k;
        }
    } else if (p->b321 == 1) {
        k = 0.33f;
        if (p->f30 < (f32)p->h34 * k) {
            func_L07_003B4BE0(obj, 0x12);
            p->b321 = 2;
            p->b326 = 3;
            p->f30 = (f32)p->h34 * k;
        }
    }
    if (p->b326 != 0) {
        q = p->w308;
        if (q != 0) {
            if (*(s16 *)(q + 0xAA) != 0x1C81) {
                p->w308 = 0;
            } else if (q[0x20] == 0xFE) {
                p->w308 = 0;
            } else if (q[0x20] == 0xFD) {
                p->w308 = 0;
            }
        } else {
            D_L07_001DF41C_003B4518[(p->w300 << 8) + 0xBC] = p->b326;
            p->b326 = 0;
        }
    }
    if (p->f30 <= 0.0f) {
        c = p->col;
        func_L01_00438908(obj, c.r, c.g, c.b);
        func_L01_0044ED60(obj, 0x3FFF, 8.0f, D_L07_001D66B0, 12.0f, 8.0f, 12.0f, 0xFF, 0xB4, -1.0f, -1.0f, 0, 1.0f, 0, 0x23, 0, 3, 1.0f);
        func_L07_00330E70(obj);
        return;
    }
    if (p->b5E != 0) {
        func_L07_00330E70(obj);
        p->b5E = 0;
        return;
    }
    if (p->b60 != 0) {
        func_L07_00330E70(obj);
        p->b60 = 0;
        return;
    }
    if (p->b324 != 0) {
        if (D_L07_001E1EC0_003B4518.f144 != obj) {
            if (D_L07_001E1EC0_003B4518.f144 == 0) {
                D_L07_001E1EC0_003B4518.f144 = obj;
                D_L07_001E1EC0_003B4518.f148 = 0;
            }
        }
    } else {
        if (D_L07_001E1EC0_003B4518.f144 == obj) {
            D_L07_001E1EC0_003B4518.f144 = 0;
        }
    }
    func_L01_00479140(2, 0, D_L07_001E1EC0_003B4518.f144 != obj, p->f30 / (f32)p->h34);
    func_L01_004538E0(obj, 3);
    func_L01_004539A8(obj, func_L07_003335E0(p->w190), 0, 0, 0, 0, 1, 0, 0, 0, 0.0f, 0.0f, 1.0f);
    func_L07_003B4F80(obj);
    func_003883C8((u8 *)p + 0x328);
    func_L07_0044F0E8(obj, 0x11, (u8 *)p + 0x2B0, 2.5f);
    if (func_L01_0040C018(&D_L07_001E1EC0_003B4518, obj + 0x10) < 5625.0f) {
        func_L01_00444188(obj);
        obj[0x6F] = 0x46;
    }
}
/* localdecomp:end func_L07_003B4518 */
