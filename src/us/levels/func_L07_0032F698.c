#include "common.h"

/* localdecomp:start func_L07_0032F698 */
typedef struct { u8 b0; u8 b1; u8 b2; u8 b3; s32 w4; s32 w8; } Ent_0032F698;
typedef struct { s32 w0; u8 b4; u8 pad5[3]; } Row_0032F698;
typedef struct {
    u8 pad0[0x9E];
    u8 b9E;
    u8 b9F;
    u8 padA0[4];
    s16 hA4;
    u8 padA6[2];
    u8 bA8;
    u8 padA9;
    u8 bAA;
    u8 bAB;
    f32 fAC;
    u8 bB0;
    u8 padB1;
    s16 hB2;
    s16 hB4;
    s16 hB6;
    f32 fB8;
    u16 hBC;
    u8 bBE;
    u8 padBF[0x1D];
    u8 bDC;
    u8 bDD;
    u8 bDE;
    u8 padDF;
    s32 wE0;
} St_0032F698;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x47];
    St_0032F698 *p68;
} Obj_0032F698;
typedef struct {
    u8 pad0[0x1200];
    s32 w1200;
    u8 pad1204[0x24];
    s32 w1228;
    u8 pad122C[0x25C4 - 0x122C];
    s32 w25C4;
    u8 pad25C8[0x25ED - 0x25C8];
    u8 b25ED;
    u8 pad25EE[0x2850 - 0x25EE];
    union {
        s32 w;
        u8 b;
    } u2850;
    u8 pad2854[0x28C9 - 0x2854];
    u8 b28C9;
    u8 b28CA;
} Hero_0032F698;

extern Hero_0032F698 D_001A4BE0;
extern u8 D_001DD144_sda;
__asm__(".extern D_001DD144_sda, 1");
extern s32 D_00142668[];
extern s32 D_001427F0[];
extern u8 D_L07_002B0EB0[];
extern s32 D_001D4C38;
extern s32 D_L07_001D7B20_0032F698;
extern s32 D_L07_001DF518;
extern void func_L07_0032FC80(void *);
extern Ent_0032F698 *func_L07_00332D20(s32, s32);
extern void func_L07_003307F0(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L07_00334D60(void *);
extern s32 func_003883C8(void *);
extern s32 func_L07_003A0BC0(s32, void *, s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_003DF7C0(s32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_005130C8(s32, s32);
extern s32 func_L01_0040BAF0(void *);
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_00334E18(void *);
extern s32 func_L01_00449AE8(s32);
extern s32 func_L07_00332218(void *);
extern void func_L07_00334B78(void *, s32);
extern s32 func_L07_00332D68(void *, s32);
extern void func_L07_0032FD90(void *);

void func_L07_0032F698(Obj_0032F698 *a) {
    St_0032F698 *s;
    Ent_0032F698 *e;
    Row_0032F698 *row;
    s32 *p;
    s32 id;
    s32 got;
    s32 lim;
    s32 h4;
    s32 color;
    s32 i;
    f32 t;

    s = a->p68;
    func_L07_0032FC80(a);
    if (a->b20 >= 4 && a->b20 <= 7) {
        e = func_L07_00332D20(s->b9E, s->b9F);
        if (D_001A4BE0.w25C4 == 0x39) {
            if (e->b3 != 0) {
                D_001DD144_sda = 1;
            }
            func_L07_003307F0(a);
        }
        if (D_001A4BE0.w25C4 != 0x74) {
            if (s->hA4 != -1) {
                if (s->hA4 % 60 == 0) {
                    if (s->hA4 < 0x259) {
                        func_0039FE80(3, 0, a);
                    }
                    func_L07_00334D60(a);
                }
                if (func_003883C8(&s->hA4) != 0) {
                    func_L07_003A0BC0(0x2C, a, 0, 0x78);
                    s->bA8 = 1;
                    func_L07_003307F0(a);
                }
            }
            if (e->b2 != 0) {
                t = s->fAC + 0.0050000004f;
                s->fAC = t;
                if (t >= 1.0f) {
                    if (D_001A4BE0.u2850.w > 0) {
                        got = 0;
                        if ((D_00142668[0] >> 2) >= D_001A4BE0.u2850.w && !(s->wE0 & 0x800)) {
                            func_L07_003A0BC0(0x39, a, 0, 0x78);
                            s->wE0 |= 0x800;
                            got = 1;
                        }
                        if (got == 0 && !(s->wE0 & 0x400) && func_0037E1D8(8) == 0) {
                            func_L07_003A0BC0(0x38, a, 0, 0x78);
                            s->wE0 |= 0x400;
                        }
                        D_001A4BE0.u2850.w = D_001A4BE0.u2850.w - 1;
                        s->fAC = s->fAC - 1.0f;
                        s->bAB = s->bAB + 1;
                    }
                }
                func_003DF7C0(3);
            }
            if (s->bBE != 0) {
                s->fB8 = func_00389380(s->fB8, 0.20943953f);
                color = func_003894A0(0x8066CCFF, 0x80FFFFFF, (1.0f - func_00388960(s->fB8)) * 0.5f);
                for (i = 0; i < 8; i++) {
                    if ((s->bBE >> i) & 1) {
                        func_L01_005130C8(i + 0x150008, color);
                    }
                }
                if (func_003883C8(&s->hBC) != 0) {
                    s->bBE = 0;
                }
            }
            if (s->bDC != 0) {
                if (func_L01_0040BAF0(&s->bDD) != 0) {
                    if (D_001A4BE0.u2850.w < D_00142668[0]) {
                        D_001A4BE0.u2850.w = D_001A4BE0.u2850.w + 1;
                    }
                    s->bDD = 4;
                    s->bDC = s->bDC - 1;
                    func_003DF7C0(0x1E);
                }
            }
        }
        if (e->b3 != 0) {
            func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
            func_L07_00334E18(a);
            row = (Row_0032F698 *)((s->bB0 << 3) + (s32)D_L07_002B0EB0);
            id = row->w0;
            p = &D_001427F0[id];
            if (s->hB2 < *p) {
                s->hB2 = *p;
            } else {
                s->hB4 = s->hB4 - (s->hB2 - *p);
                *p = s->hB2;
                lim = row->b4 >> 3;
                h4 = s->hB4;
                if (lim != 0 ? h4 == lim : h4 == 1) {
                    if (!(s->wE0 & 0x8000)) {
                        if (func_0037E1D8(4) == 0) {
                            func_L07_003A0BC0(0x31, a, 0, 0x78);
                            s->wE0 |= 0x10000;
                        }
                    }
                    s->wE0 |= 0x8000;
                }
                if (s->hB4 <= 0) {
                    s->hB6 = s->hB6 + 1;
                    D_001A4BE0.b25ED = 1;
                    if (s->hB6 >= 0x1F) {
                        id = func_L07_00332218(a);
                        D_001A4BE0.b25ED = 0;
                        func_L07_00334B78(a, id);
                    }
                } else {
                    s->hB6 = 0;
                }
            }
            if (D_001A4BE0.w1200 == 0 || D_001A4BE0.w1228 != id) {
                D_001A4BE0.b28C9 = 0;
                D_001A4BE0.b28CA = 1;
                func_L01_00449AE8(id);
            } else {
                D_001A4BE0.b28C9 = 1;
            }
        } else if (e->w8 != -1) {
            func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
            if (D_001A4BE0.w1200 == 0 || D_001A4BE0.w1228 != e->w8) {
                D_001A4BE0.b28C9 = 0;
                func_L01_00449AE8(e->w8);
            } else {
                D_001A4BE0.b28C9 = 1;
            }
            if (func_L07_00332D68(a, e->w8) != 0) {
                s->bA8 = 2;
                func_L07_003307F0(a);
            }
        } else {
            D_001A4BE0.b28C9 = 0;
        }
        if (e->b0 == 0) {
            if (s->bDE < D_001A4BE0.u2850.w) {
                s->bDE = D_001A4BE0.u2850.b;
            }
            if (D_001A4BE0.u2850.w < s->bDE) {
                s->bA8 = 3;
                func_L07_003307F0(a);
            }
        }
        func_L07_0032FD90(a);
        D_L07_001D7B20_0032F698 = s->b9E + 10;
        D_L07_001DF518 = D_001D4C38;
    }
}
/* localdecomp:end func_L07_0032F698 */
