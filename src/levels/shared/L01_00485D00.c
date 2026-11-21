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
extern u8 D_001425C0[];
extern s32 D_L01_001D8560;
extern s32 D_L01_001D855C;

/* localdecomp:start func_L01_00485D00 */
typedef struct {
    u8 x0;
    u8 level;
    u8 pad2[2];
    s32 name;
    u8 pad8[0x60];
    s32 x68;
    u8 pad6C[0x1E];
    u16 x8A;
    u8 pad8C[0x64];
} E_00485D00;
typedef struct {
    s32 x0;
    s32 text[16];
} T_00485D00;

__asm__(".extern D_L01_001D855C, 4");
__asm__(".extern D_L01_001D8560, 4");
extern E_00485D00 D_L01_002C5600_00485D00[];
extern T_00485D00 D_L01_002EA2D8_00485D00[];
extern s32 D_L01_001D855C;
extern s32 D_L01_001D8560;
extern u8 D_001425C0[];
extern u8 D_00142CA0[];
extern s32 D_00142DE0[];
extern s32 D_001427F0[];
extern char D_L01_00233C58[];
extern char D_L01_00233CD8[];
extern char D_L01_001E07D0[] __attribute__((section(".sdata")));
extern char D_L01_001E07E8[] __attribute__((section(".sdata")));
extern char D_L01_001E07F0[] __attribute__((section(".sdata")));
extern char D_L01_001E0810[] __attribute__((section(".sdata")));
extern char D_L01_001D8648[];
extern char D_L01_001D8650[];
extern char D_L01_001D8660[];
extern char D_L01_001D8668[];
extern char D_L01_001D8670[];
extern char D_L01_001D8680[];
extern char D_L01_001D8688[];
extern char D_L01_001D8698[];
extern char D_L01_001D86A8[];
extern char D_L01_001D86B0[];
extern char D_L01_001D86B8[];

extern int func_L01_00485A38(int, int);
extern s32 func_L01_00485A60(s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_L01_00418DE0(s32, s32);
extern s32 func_L01_00485B68(s32);
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_L01_00517538(s32, f32, f32);

void func_L01_00485D00(void) {
    s32 idx;
    s32 n;
    s32 m;
    s32 have;
    E_00485D00 *e;

    n = 0;
    idx = func_L01_00485A38(D_L01_001D855C, D_L01_001D8560);
    func_L01_00516D60(0xE0058, 0);
    func_L01_00516D60(0xE0059, 0);
    func_L01_00516D60(0xE005A, 0);
    if (D_00142CA0[idx] != 0) {
        if ((&D_L01_002C5600_00485D00[D_001425C0[idx]])->x68 > 0) {
            m = (&D_L01_002C5600_00485D00[D_001425C0[idx]])->level;
            if (m > 0) {
                func_L01_00418DE0(idx, m - 1);
                n = (&D_L01_002C5600_00485D00[D_001425C0[idx]])->x68;
                func_L01_00418DE0(idx, m);
                if (n < 0) {
                    n = 0;
                }
            }
        }
        switch ((&D_L01_002C5600_00485D00[D_001425C0[idx]])->level) {
        case 6:
            func_L01_00516D60(0xE0059, 1);
            break;
        case 5:
            func_L01_00516D60(0xE0058, 1);
            break;
        case 7:
            func_L01_00516D60(0xE005A, 1);
            break;
        }
        have = (D_00142DE0[idx] >> 5) - n;
        n = (&D_L01_002C5600_00485D00[D_001425C0[idx]])->x68 - n;
        func_0011B2E8(D_L01_00233C58, D_L01_001D8648, func_00381FF0((&D_L01_002C5600_00485D00[D_001425C0[idx]])->name));
        func_0011B2E8(D_L01_001E07D0, D_L01_001D8650, func_00381FF0(0x178), D_001427F0[idx], (&D_L01_002C5600_00485D00[D_001425C0[idx]])->x8A);
        func_0011B2E8(D_L01_001E07E8, D_L01_001D8660, func_00381FF0(0xBF5), (&D_L01_002C5600_00485D00[D_001425C0[idx]])->level + 1);
        func_0011B2E8(D_L01_001E07F0, D_L01_001D8668, func_00381FF0(0x1604), func_L01_00485B68(idx));
        if (n > 0) {
            if (n >= 10000) {
                func_L01_00517538(0xE0007, 0.9f, 1.0f);
            } else {
                func_L01_00517538(0xE0007, 1.0f, 1.0f);
            }
            func_0011B2E8(D_L01_001E0810, D_L01_001D8670, func_00381FF0(0x1605), have, n);
        } else {
            func_0011B2E8(D_L01_001E0810, D_L01_001D8680, func_00381FF0(0x1605), func_00381FF0(0x1606));
        }
        e = &D_L01_002C5600_00485D00[D_001425C0[idx]];
        func_0011B2E8(D_L01_00233CD8, D_L01_001D8648, func_00381FF0(D_L01_002EA2D8_00485D00[func_L01_00485A60(D_L01_001D855C, D_L01_001D8560)].text[e->level]));
    } else {
        func_0011B2E8(D_L01_00233C58, D_L01_001D8688);
        func_0011B2E8(D_L01_001E07D0, D_L01_001D8698, func_00381FF0(0x178));
        func_0011B2E8(D_L01_001E07E8, D_L01_001D86A8, func_00381FF0(0xBF5));
        func_0011B2E8(D_L01_001E07F0, D_L01_001D86B0, func_00381FF0(0x1604));
        func_0011B2E8(D_L01_001E0810, D_L01_001D86B8, func_00381FF0(0x1605));
        D_L01_00233CD8[0] = 0;
    }
}
/* localdecomp:end func_L01_00485D00 */
