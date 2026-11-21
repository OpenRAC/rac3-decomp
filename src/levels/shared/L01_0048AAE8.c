#include "common.h"

typedef struct {
    int f0;
    char pad[64];
} S_002EA318;
typedef struct {
    s32 idx;
    u8 pad[0x40];
} S_482AE0;
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
typedef struct {
    u8 pad0[56];
    u16 x38;
    u8 pad3A[182];
} Entry_00483CD8;
typedef struct Obj_484598 Obj_484598;
typedef struct {
    u8 pad[12];
    void (*fn)(Obj_484598 *);
} Vt_484598;
struct Obj_484598 {
    u8 pad[4];
    Vt_484598 *vt;
};
typedef struct { u8 pad[0x38]; u16 h38; u8 pad3A[0xF0 - 0x3A]; } E_4848A8;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[0x82];
    u16 x8A;
    u8 pad8C[0x64];
} E_4858E8;
typedef struct {
    u8 pad[56];
    u16 unk38;
    u8 pad2[182];
} S_002C5640;
typedef struct {
    u8 pad0[56];
    u16 f56;
    u8 pad58[182];
} Entry_00485FF8;
typedef struct {
    s32 id;
    u8 flag;
    u8 pad[0xAB];
} Ent4876B0;
typedef struct {
    s32 obj;
    u8 pad[81];
    char name[91];
} Slot_00487740;
typedef struct VObj_487AC0 VObj_487AC0;
typedef struct {
    u8 pad[12];
    void (*fn)(VObj_487AC0 *self);
} VTbl_487AC0;
struct VObj_487AC0 {
    s32 pad;
    VTbl_487AC0 *vtbl;
};

/* declared by functions of L01_004838A0.c, which this file was cut from */
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern int func_0011B2E8(char *, char *, ...);
extern s32 func_003B9BD0(s32);

/* localdecomp:start func_L01_0048AAE8 */
typedef struct {
    s32 id;
    u8 flag;
    char text[0xA3];
    s32 name;
    void *fn;
} E_0048AAE8;
typedef struct { s32 w0; s32 w4; } T_0048AAE8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 a24[4];
    f32 a34[4];
    f32 a44[4];
} M_0048AAE8;
extern void *func_0011A264(void *, s32, s32);
extern s32 D_L01_001D8A3C;
extern s32 D_00143050[];
extern s32 D_L01_002EAEC0[];
extern E_0048AAE8 D_L01_00233DD8_0048AAE8[];
extern T_0048AAE8 D_L01_002E9DC0_0048AAE8[];
extern char D_L01_001D8BA8[];
extern f32 D_L01_001D8B2C;
extern f32 D_L01_001D8B30;
extern f32 D_L01_001D8B34;
extern f32 D_L01_001D8B38;
extern f32 D_L01_001D8B3C;
__asm__(".extern D_L01_001D8A3C, 4");
__asm__(".extern D_L01_001D8B2C, 4");
__asm__(".extern D_L01_001D8B30, 4");
__asm__(".extern D_L01_001D8B34, 4");
__asm__(".extern D_L01_001D8B38, 4");
__asm__(".extern D_L01_001D8B3C, 4");
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 func_003B9BD0(s32);
extern void func_L01_0048AA70(s32, s32);
extern void func_003B9C68(s32, void *);
extern void func_003BABB0(s32, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(s32, f32, f32, f32, f32);
extern void func_003BA4E0(s32, s32, f32, f32, f32);
extern void func_L01_00498F18(s32, s32, s32);
extern void func_L01_00498948(s32, s32, s32);
extern char *func_003B9E30(s32, s32, s32);
extern s32 func_00381FF0(s32);
extern int func_0011B2E8(char *, char *, ...);

static __inline__ s32 name_0048AAE8(s32 t) {
    if (t == 1 || t == 2 || t == 4 || t == 8 || t == 27 || t == 28 || t == 9 || t == 29 ||
        t == 5 || t == 13 || t == 23 || t == 10 || t == 18 || t == 14) {
        return t > 0 ? D_L01_002E9DC0_0048AAE8[t % 60].w4 : D_L01_002E9DC0_0048AAE8[1].w4;
    }
    return t > 0 ? D_L01_002E9DC0_0048AAE8[t % 60].w0 : D_L01_002E9DC0_0048AAE8[1].w0;
}

void func_L01_0048AAE8(void) {
    M_0048AAE8 m;
    s32 i = 0;
    s32 available = 1;
    s32 c;
    s32 t;

    D_L01_001D8A3C = 0;
    func_0011A264(D_L01_00233DD8_0048AAE8, 0x14A0, 0); /* size and fill value swapped, as in retail */
    for (; i < 60; i++) {
        t = D_00143050[i];
        if (t == 0) {
            continue;
        }
        if (t == 1 || t == 28 || t == 27 || t == 6 || t == 29 || t == 23 || t == 26) {
            continue;
        }
        if (t == 20) {
            continue;
        }
        if (D_L01_001D8A3C < 0 && t >= 2) {
            D_L01_001D8A3C = 0;
        }
        c = D_L01_001D8A3C;
        D_L01_001D8A3C = c + 1;
        D_L01_00233DD8_0048AAE8[c].id = D_00143050[i];
        D_L01_00233DD8_0048AAE8[c].name = D_L01_002EAEC0[D_00143050[i] - 1];
        D_L01_00233DD8_0048AAE8[c].fn = (void *)func_L01_0048AA70;
        D_L01_00233DD8_0048AAE8[c].flag = available != 0;
    }
    m.f0 = func_L01_0047DAE0() - 0x800;
    m.f4 = func_003BB118(1);
    m.f8 = 20;
    m.fC = D_L01_001D8A3C;
    m.f10 = D_L01_001D8A3C < 8 ? D_L01_001D8A3C : 7;
    m.f14 = 1;
    m.f18 = 1.0f;
    m.f1C = 0.385096014f;
    m.f20 = 0.0553999990f;
    m.a24[0] = D_L01_001D8B2C;
    m.a24[1] = 1.0f;
    m.a24[2] = 1.0f;
    m.a24[3] = 1.0f;
    m.a34[0] = D_L01_001D8B34 - (D_L01_001D8B3C + D_L01_001D8B3C);
    m.a34[1] = 0;
    m.a34[2] = 0;
    m.a34[3] = 0;
    m.a44[0] = 0;
    m.a44[1] = 0;
    m.a44[2] = 0;
    m.a44[3] = 0;
    func_003B9C68(func_003B9BD0(0), &m);
    func_003BABB0(func_003B9BD0(0), D_L01_001D8B2C, m.a34[0], 0.0450000018f, 0.0425000004f, 0.349999994f, 0);
    func_003BABD0(func_003B9BD0(0), D_L01_001D8B2C, D_L01_001D8B30, D_L01_001D8B34 - 0.008f, D_L01_001D8B38 - 0.01f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.0265f, 0.00666f, 0.03f);
    func_L01_00498F18(func_003B9BD0(0), 0, 1);
    for (i = 0; i < D_L01_001D8A3C; i++) {
        func_L01_00498948(func_003B9BD0(0), i, 0);
        func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8BA8,
                      func_00381FF0(name_0048AAE8(D_L01_00233DD8_0048AAE8[i].id)));
    }
}
/* localdecomp:end func_L01_0048AAE8 */
