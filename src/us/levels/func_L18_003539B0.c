#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L18_003545D0 (src/levels/shared/L18_003537D8.c): 60 Hz rate 0.05f and timers 420/360 */
/* localdecomp:start func_L18_003539B0 */
typedef int Quad_3543C8 __attribute__((mode(TI)));
typedef struct Obj_3543C8 {
    u8 pad0[0x10];
    Quad_3543C8 pos;
    u8 pad20[4];
    u8 *def;
    u8 pad28[0xC];
    u16 flags;
    u8 pad36[0x32];
    u8 *vars;
    u8 pad6C[0x2A];
    u16 timer;
    s32 w98;
    u8 pad9C[0xC];
    u8 alpha;
    u8 padA9[0x13];
    u8 state;
    u8 padBD[0x33];
    Quad_3543C8 pos2;
} Obj_3543C8;

typedef struct {
    char pad0[0x30];
    f32 unk30;
    char pad34[0x80 - 0x34];
    s32 unk80;
} Vars;

typedef struct {
    char pad0[0x68];
    Vars *vars;
    char pad6C[0x96 - 0x6C];
    s16 unk96;
} Moby;

extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L18_00350468(Moby *);
extern void func_L01_004EA040(void);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004FC518(s32, s32);
extern void func_L18_003537C0(Obj_3543C8 *);
typedef struct M_003545D0 {
    u8 pad0[0x34];
    u16 flags;
    u8 pad36[0x62];
    s32 w98;
    u8 pad9C[0x64];
} M_003545D0;

typedef struct G_003545D0 {
    u8 pad0[0x360];
    s32 x360;
    u8 pad364[0x19E0 - 0x364];
    void *x19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    u8 *x25C0;
    s32 x25C4;
    u8 pad25C8[4];
    s32 x25CC;
    u8 pad25D0[0x14];
    u8 x25E4;
    u8 pad25E5[0x280C - 0x25E5];
    s32 x280C;
    u8 pad2810[0x288C - 0x2810];
    s16 x288C;
} G_003545D0;

typedef struct V_003545D0 {
    u8 pad0[0x30];
    f32 x30;
    u8 pad34[0x2E];
    u8 x62;
    u8 pad63[0x1D];
    s32 x80;
    u8 pad84[0x284];
    s32 list[18];
    u8 pad350[0x20];
    s32 x370;
    u8 pad374[0xE];
    u8 x382;
    u8 pad383;
    s32 x384;
    u8 pad388[0x78];
    vu0_q x400;
    vu0_q x410;
    u8 pad420[0x10];
    s8 x430;
    s8 x431;
    s8 x432;
    s8 x433;
    s32 x434;
    s32 x438;
    u8 pad43C[4];
    u8 x440;
    u8 pad441[3];
    f32 x444;
    s32 x448;
} V_003545D0;

extern M_003545D0 *D_L18_001E011C;
extern s32 D_L18_001D678C;
extern u8 D_001BBC40[];
extern s32 D_001A71A0[];
extern s32 D_001A71A4[];
extern u8 D_00142703[];
extern u8 *D_001D52FC;
extern u16 D_001A8B50[];
extern s32 D_L18_001DFCC0;
extern s32 D_L18_001DFCC8;
extern s32 D_L18_001DFD10;
extern u8 D_L18_001E2B40[];
extern G_003545D0 D_001A4BE0;

extern void func_003BD360(void *);
extern void func_00388B40(void *);
extern void func_003BFC18(void *, void *, s32);
extern void func_L01_0044E358(void *, void *, void *);
extern f32 func_L18_0044AA78(void *, void *);
extern s32 func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0050BB98(s32, s32, f32);
extern void func_L01_00419718(s32, s32);
extern s32 func_L01_00442998(s32, s32, s32);
extern s32 func_00388398(void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L18_00350948(void *);
extern void func_L18_00350698(void *);
extern void func_L18_003503B0(void *);
extern void func_L18_00351750(void *);
extern void func_L18_00352A50(void *);
extern void func_L18_00352530(void *);
extern void func_L18_00352128(void *);
extern void func_L18_00352C68(void *);
extern void func_L18_00351688(void *);

void func_L18_003539B0(u8 *obj) {
    V_003545D0 *v = *(V_003545D0 **)(obj + 0x68);
    vu0_v4 a;
    vu0_v4 b[3];
    s32 i;
    s32 r;

    if (v->x62 == 1) {
        func_003BD360(obj);
        return;
    }
    switch (obj[0x95]) {
    case 0:
        for (i = 0; i < 18; i++) {
            s32 k = v->list[i];
            if (k != -1) {
                M_003545D0 *m = &D_L18_001E011C[k];
                m->w98 = 0;
                m->flags |= 0x41;
            }
        }
        obj[0x30] = 0xFF;
        *(s16 *)(obj + 0x32) = 0x1FF;
        if (D_L18_001D678C != 0) {
            *(u16 *)(obj + 0x34) |= 0x100;
            func_00388B40(obj + 0xC0);
        }
        if (D_001BBC40[obj[0xB0] + D_001D545C * 16] & 0x80) {
            if (D_001D545C == 11) {
                *(f32 *)(obj + 0x10) = 502.78f;
                *(f32 *)(obj + 0x14) = 201.07f;
                *(f32 *)(obj + 0x18) = 802.0f;
                func_003BFC18(obj + 0x10, &a, 0);
                func_L01_0044E358(obj + 0xC0, &a, b);
            }
        }
        v->x384 = 0;
        func_L18_00350948(obj);
        v->x400 = *(vu0_q *)(obj + 0x10);
        v->x410 = *(vu0_q *)(obj + 0xF0);
        v->x448 = 0;
        v->x432 = -1;
        v->x430 = -1;
        v->x431 = -1;
        v->x433 = -1;
        v->x434 = 2;
        v->x438 = 0;
        v->x382 = 0;
        break;
    case 1:
        if (v->x440 == 0) {
            s32 done = ((s32 (*)(void *))func_L18_00351688)(obj);
            *(f32 *)(obj + 0x2C) += (*(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.8f - *(f32 *)(obj + 0x2C)) * 0.05f;
            if (*(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.8f * 0.98f < *(f32 *)(obj + 0x2C) && done != 0) {
                *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.8f;
                func_L01_00441FB8(obj, 0, 3);
            }
            break;
        }
        *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.8f;
        func_L01_00441FB8(obj, 0, 3);
        /* fallthrough */
    case 3:
        if (v->x440 == 0) {
            ((s32 (*)(void *))func_L18_00351688)(obj);
        }
        if ((v->x440 != 0 && v->x444 == 3.0f) ||
            func_L18_0044AA78(obj, (void *)D_001A71A0[0]) < v->x444) {
            if (D_L18_001DFCC0 >= 4 && D_L18_001DFCC8 >= 4 && D_001A4BE0.x25E4 == 0 &&
                D_001A4BE0.x25C4 != 0x31 && v->x30 > 0.0f &&
                D_001A4BE0.x288C == 0) {
                if (v->x440 == 0) {
                    r = func_L01_0044F2E8(0, 8, 0x855, 1, 0, 0, 0) != 0;
                }
                if (v->x440 != 0 || ((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) && r)) {
                    func_L01_004FC518(0x31, 0);
                    func_L01_0050BB98(0xD, 0, 15.0f);
                    func_L18_003503B0(obj);
                    D_001A4BE0.x19E0 = obj;
                    *(s32 *)(D_001A4BE0.x25C0 + 0x9C) = -1;
                    D_001A4BE0.x280C = 0x1D;
                    func_L01_00441FB8(obj, 0, 4);
                    if (D_001A8B50[0] == 0) {
                        if (D_001D545C == 0x12 || D_001D545C == 0x1A) {
                            v->x448 = 420;
                        } else if (D_001D545C == 0x1D) {
                            v->x448 = 360;
                        } else {
                            func_L01_00419718(0x14D0, 0x11A);
                        }
                    }
                    D_L18_001DFD10 = 2;
                }
            }
        }
        break;
    case 4:
        ((s32 (*)(void *))func_L18_00351688)(obj);
        func_L18_003503B0(obj);
        func_L01_00441FB8(obj, 0, 5);
        break;
    case 5:
        func_L18_00351750(obj);
        func_L18_003503B0(obj);
        if ((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) && D_001D545C != 11 && D_001D545C != 20 &&
            v->x80 == 0) {
            func_L01_00441FB8(obj, 0, 6);
        } else if (v->x370 != -1) {
            func_L01_00442998(v->x370, -1, 0);
            D_00142703[0] = 1;
            func_L01_00441FB8(obj, 0, 7);
        } else {
            func_L18_00352A50(obj);
        }
        D_L18_001DFD10 = 2;
        break;
    case 6:
        func_L18_00350468((Moby *)obj);
        ((s32 (*)(void *))func_L18_00351688)(obj);
        func_L01_00441FB8(obj, 0, 3);
        break;
    case 7:
        func_L18_00350698(obj);
        ((s32 (*)(void *))func_L18_00351688)(obj);
        func_L01_00441FB8(obj, 0, 3);
        break;
    case 8:
        if (v->x80 != 0) {
            D_L18_001DFD10 = 2;
        }
        if (obj[0xBC] == 0) {
            if (D_001A71A4[0] == 0x31) {
                func_L18_00350468((Moby *)obj);
                func_L01_004EA040();
            }
            func_L01_00441FB8(obj, 0, 3);
        }
        break;
    }
    func_L18_003537C0((Obj_3543C8 *)obj);
    if (obj[0xBC] != 10) {
        func_L18_00352530(obj);
        func_L18_00352128(obj);
    }
    (*(u16 *)(obj + 0x96))++;
    if (v->x448 != 0 && func_00388398(&v->x448) != 0) {
        func_L01_00419718(0x14D0, 0x11A);
    }
    func_L18_00352C68(obj);
    if (obj[0xBC] != 10 && obj[0x31] != 0) {
        if (func_L01_0040C018(D_L18_001E2B40, obj + 0x10) < 484.0f) {
            func_L01_00444188(obj);
            obj[0x6F] = 20;
        }
    }
    if (v->x382 != 0) {
        if (D_001A4BE0.x360 != 0 && D_001A4BE0.x25CC != 20) {
            v->x382 = 0;
            D_L18_001DFD10 = 0;
        } else {
            D_L18_001DFD10 = 2;
        }
    }
}
/* localdecomp:end func_L18_003539B0 */
