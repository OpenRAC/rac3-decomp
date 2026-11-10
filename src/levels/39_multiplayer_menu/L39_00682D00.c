#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* declared by functions of L39_00681758.c, which this file was cut from */
extern s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L39_00682D00 */
typedef struct S_00682D00 S_00682D00;
typedef struct {
    u8 pad0[0x30];
    void (*f30)(S_00682D00 *, f32 *, f32 *);
} Vt_00682D00;
struct S_00682D00 {
    u8 pad0[0x4];
    s32 f4;
    u8 pad8[0xC];
    u8 f14[0x44];
    f32 f58;
    u8 pad5C[0x4];
    Vt_00682D00 *f60;
    s32 f64;
    s32 f68;
    u8 pad6C[0xC];
    char f78[0x28];
    s32 fA0;
    s32 fA4;
    s32 fA8;
    s32 fAC;
    s32 fB0;
    s32 fB4;
};
extern char D_002475D8[];
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L39_00611628(s32);
extern char *func_00381FF0(s32);
extern void func_120048(char *, char *, s32);

void func_L39_00682D00(S_00682D00 *p) {
    f32 v[4];
    f32 x;
    f32 y;
    s32 color;

    if (p->fA0 == -1) {
        return;
    }
    if (p->f4 == 0) {
        func_L01_00516AA0(p->fA0, 1, 0);
        func_L01_00516AA0(p->fA4, 1, 0);
        func_L01_00516AA0(p->fA8, 1, 0);
        return;
    }
    func_L01_00516AA0(p->fA0, 1, 1);
    func_L01_00516AA0(p->fA4, 1, 1);
    func_L01_00516AA0(p->fA8, 1, 1);
    if (p->f4 == 2) {
        color = 0x80808080;
    } else if (p->f4 == 3) {
        color = 0x8066CCFF;
    } else if (p->f4 == 4) {
        color = 0x66D6EEFA;
    } else if (p->f4 == 5) {
        color = 0x66D6EEFA;
    } else {
        color = 0x8066CCFF;
    }
    p->f60->f30(p, &x, &y);
    if (p->f14[0] != 0) {
        func_L01_00516FD8(p->fA0, (s32)p->f14);
        func_L01_00516470(p->fA0, x, y);
        func_L01_005170B8(p->fA0, color);
        ((s32 (*)(s32, f32 *))func_L39_00611628)(p->fA0, v);
        x = v[2] + 0.005f;
        func_L01_00516470(p->fA4, x, y);
        func_L01_005170B8(p->fA4, color);
    }
    p->f60->f30(p, &x, &y);
    if (p->f64 != p->f68) {
        if (p->f64 == 0 && p->fAC >= 0) {
            func_120048(p->f78, func_00381FF0(p->fAC), p->f64);
        } else if (p->f64 == 1 && p->fB0 >= 0) {
            func_120048(p->f78, func_00381FF0(p->fB0), p->f64);
        } else if (p->f64 >= 2 && p->fB4 >= 0) {
            func_120048(p->f78, func_00381FF0(p->fB4), p->f64);
        } else {
            func_120048(p->f78, D_002475D8, p->f64);
        }
        func_L01_00516FD8(p->fA8, (s32)p->f78);
        p->f68 = p->f64;
    }
    func_L01_00516470(p->fA8, x + p->f58, y);
    func_L01_005170B8(p->fA8, color);
}
/* localdecomp:end func_L39_00682D00 */
