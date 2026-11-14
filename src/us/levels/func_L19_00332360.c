#include "common.h"

/* localdecomp:start func_L19_00332360 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00332360;
typedef struct {
    u8 pad0[0x350];
    s32 w350;
    u8 pad354[4];
    u8 *p358;
    u8 pad35C[4];
    s32 w360;
} St_00332360;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0xF];
    unsigned long d30;
    u8 pad38[0x30];
    St_00332360 *p68;
    u8 pad6C[0x29];
    u8 b95;
    u8 pad96[2];
    s32 w98;
    u8 pad9C[0xE];
    s16 hAA;
} Obj_00332360;
typedef struct {
    u8 pad0[0x25C0];
    s32 w25C0;
    u8 pad25C4[0x286C - 0x25C4];
    s32 w286C;
} Hero_00332360;

extern Hero_00332360 D_001A4BE0;
extern s32 D_L19_001E8E58_00332360[];
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00452F40(void *, s32);
extern u8 *func_L19_00333BF8(void *);
extern u8 *func_L19_00333DD8(void *);
extern u8 *func_L19_00333F80(void *);
extern u8 *func_L19_00334138(void *);
extern s32 func_L19_00334758(void *);
extern void func_L19_00334958_00332360(void *);

void func_L19_00332360(Obj_00332360 *a) {
    St_00332360 *s;
    s32 mode;
    f32 d;
    u8 *r;
    V4_00332360 va;
    V4_00332360 vb;

    mode = D_001A4BE0.w286C;
    s = a->p68;
    if (mode == 0) {
        return;
    }
    if (a->b20 == 0xC) {
        return;
    }
    if (a->b95 == 7) {
        return;
    }
    if ((a->d30 & 0x104100000000ul) == 0x4100000000ul) {
        if (a->w98 == 0) {
            return;
        }
    }
    if (s->w360 != 0) {
        return;
    }
    if (a->b95 == 4 && mode != 6) {
        return;
    }
    if (a->b95 == 5 && mode != 5) {
        return;
    }
    if (a->b20 == 1) {
        if (s->w350 == 0) {
            return;
        }
        if (mode != 1) {
            return;
        }
        d = func_L01_0040C040((u8 *)&D_001A4BE0 + 0x80, (u8 *)a + 0x10);
        if (d < 144.0f) {
            va = *(V4_00332360 *)((u8 *)a + 0x10);
            vb = *(V4_00332360 *)((u8 *)&D_001A4BE0 + 0x80);
            va.z = va.z + 1.0f;
            vb.z = vb.z + 1.0f;
            if (func_003CE740(&va, &vb, 0, a, 0) == 0 || D_L19_001E8E58_00332360[0] == D_001A4BE0.w25C0) {
                func_L01_00441FB8(a, 4, 1);
            }
        }
        return;
    }
    switch (mode) {
    case 1:
        if (a->b95 != 1) {
            func_L01_00441FB8(a, 3, 1);
        } else if (a->b20 != 3) {
            func_L01_00441FB8(a, 3, -1);
        }
        break;
    case 3:
        if (a->b95 != 2 && a->hAA == 0x964) {
            func_L01_00441FB8(a, 10, 2);
        }
        break;
    case 2:
        if (a->b95 != 0) {
            func_L01_00441FB8(a, 2, 0);
        }
        break;
    case 4:
        if (a->hAA == 0x964) {
            s->w360 = 30;
            if (a->b95 != 3) {
                r = func_L19_00333BF8(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_00441FB8(a, 11, 3);
                }
            }
        }
        break;
    case 6:
        if (a->hAA == 0x940) {
            s->w360 = 30;
            if (a->b95 != 4) {
                r = func_L19_00333DD8(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_00441FB8(a, 13, 4);
                }
            } else if (a->b20 == 0xD) {
                func_L01_00441FB8(a, 4, 1);
            } else if (a->b20 == 0xF) {
                if (func_L19_00334758(a) == 0) {
                    func_L19_00334958_00332360(a);
                }
            }
        }
        break;
    case 5:
        if (a->hAA == 0x93C) {
            s->w360 = 30;
            if (a->b95 != 5) {
                r = func_L19_00333F80(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_00441FB8(a, 17, 5);
                }
            } else if (a->b20 != 0x12) {
                func_L01_00452F40(s->p358, 0);
                s->p358 = 0;
                func_L01_00441FB8(a, 4, 1);
            }
        }
        break;
    case 7:
        if (a->hAA == 0xA59) {
            s->w360 = 30;
            if (a->b95 != 6) {
                r = func_L19_00334138(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_00441FB8(a, 19, 6);
                }
            } else if (a->b20 != 0x14) {
                func_L01_00452F40(s->p358, 0);
                s->p358 = 0;
                func_L01_00441FB8(a, 4, 1);
            }
        }
        break;
    case 8:
        if (a->hAA == 0x964) {
            if (a->b95 != 1) {
                func_L01_00441FB8(a, 4, 1);
            }
        } else {
            func_L01_00441FB8(a, 6, 1);
        }
        break;
    }
}
/* localdecomp:end func_L19_00332360 */
