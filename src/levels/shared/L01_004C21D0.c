#include "common.h"

typedef struct VObj_4BEB00 VObj_4BEB00;
typedef struct { u8 p0[12]; void (*f)(VObj_4BEB00 *); } VT_4BEB00;
struct VObj_4BEB00 { s32 p0; VT_4BEB00 *vt; };
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[15];
} E_004BF8A0;
typedef struct {
    u8 pad0[92];
    s32 w92;
    u8 pad96[32];
    s32 w128;
    s32 w132;
    u8 pad136[184];
    E_004BF8A0 e[1];
} G_004BF8A0;
typedef struct {
    u8 pad0[132];
    u16 h132;
    u16 h134;
    u8 pad136[104];
} M_004BF8A0;
typedef struct {
    u8 p0[4];
    s32 val;
    s32 idx;
    u8 pC[4];
} E_4BFEA0;
typedef struct {
    u8 p0[4];
    s32 w4;
    u8 p8[0x78];
    s32 sel;
    u8 p84[0xBC];
    E_4BFEA0 ent[1];
} G_4BFEA0;
typedef struct {
    s32 w0;
    u8 p4[0x74];
    s32 w78;
} H_4BFEA0;
typedef struct {
    s32 a[5];
} T_4BFEA0;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } E_4C01C8;
typedef struct { u8 p0[0x80]; s32 f80; s32 f84; u8 p88[0xBC]; E_4C01C8 e[1]; } S_4C01C8;
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6A38 - 0x4958];
    u8 fX[1];
} S_func_004C07D8;
typedef struct {
    u8 p0[0x20];
    s32 w32;
} E_4C0BF8;
typedef struct {
    u8 p0[0x80];
    s32 idx;
    s32 active;
    u8 p88[0x9C];
    E_4C0BF8 e[1];
} B_4C0BF8;
typedef struct {
    s32 w0;
    s32 w4;
    u8 p8[8];
} T_4C1638;
typedef struct {
    u8 p0[4];
    s32 val;
    u8 p8[4];
    s32 idx;
} E_4C1638;
typedef struct {
    u8 p0[4];
    s32 w4;
    u8 p8[0x78];
    s32 sel;
    u8 p84[0xBC];
    E_4C1638 ent[1];
} G_4C1638;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } E_4C1988;
typedef struct { u8 p0[0x80]; s32 f80; s32 f84; u8 p88[0xBC]; E_4C1988 e[1]; } S_4C1988;

INCLUDE_ASM("asm/levels", func_L01_004C21D0);

INCLUDE_ASM("asm/levels", func_L01_004C2548);

/* localdecomp:start func_L01_004C26A8 */
extern s32 func_003B9BD0(s32);
extern void func_003B9E90(s32);
extern void func_L01_00517918(s32);
extern VObj_4BEB00 *func_003B42F8(s32);
extern void func_003A2750(s32);
void func_L01_004C26A8(void) {
    VObj_4BEB00 *o;
    func_003B9E90(func_003B9BD0(0));
    func_L01_00517918(27);
    o = func_003B42F8(0);
    o->vt->f(o);
    o = func_003B42F8(1);
    o->vt->f(o);
    func_003A2750(1);
}
/* localdecomp:end func_L01_004C26A8 */

INCLUDE_ASM("asm/levels", func_L01_004C2718);

INCLUDE_ASM("asm/levels", func_L01_004C2A80);

/* localdecomp:start func_L01_004C3448 */



extern G_004BF8A0 D_L01_002446C0;
extern char D_L01_0024DED0[];
extern char D_L01_001DAE18[];
extern s32 D_L01_001E0F94;
extern char D_L01_001E1008[8];
extern char D_L01_001E1009;
extern u8 D_001425C0[];
extern M_004BF8A0 D_L01_002C5600[];
extern s32 D_00142660[];
extern char *func_00381FF0(s32);
extern void func_L01_00516FD8(s32, char *);
extern void func_L01_00516818(s32, f32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00518670(s32, s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_0011B2E8(char *, char *, char *, s32);
extern void func_L01_004BEC88(char *, s32);
extern s32 func_0011B868(char *);
extern void func_L01_00516EC8(s32, f32 *, f32 *, f32 *, f32 *);
extern s32 func_L01_004BA830(void);

void func_L01_004C3448(void)
{
    f32 v[2];
    s32 i;

    if (D_L01_002446C0.w132 == 0) {
        func_L01_00516FD8(0x480029, func_00381FF0(2252));
        func_L01_00516FD8(0x48002A, func_00381FF0(256));
        func_L01_00516818(0x480026, 1.0f);
        func_L01_00516470(0x480026, 0.3025f, 0.325f);
        func_L01_00518670(0x480026, 0, 0);
        func_L01_00516AA0(0x48002D, 1, 0);
        func_L01_00516AA0(0x480022, 1, 0);
        return;
    }
    if (D_L01_002446C0.e[D_L01_002446C0.w128].b4 == 1) {
        func_0011B2E8(D_L01_0024DED0, D_L01_001DAE18, func_00381FF0(2254), D_L01_001E0F94);
        func_L01_00516FD8(0x480026, D_L01_0024DED0);
        func_L01_00516818(0x480026, 1.0f);
        func_L01_00518670(0x480026, 1, 1);
        func_L01_00516470(0x480026, 0.3f, 0.27f);
        func_L01_00516FD8(0x48002A, func_00381FF0(2251));
        func_L01_00516AA0(0x48002D, 1, 1);
        func_L01_00516AA0(0x480022, 1, 1);
        if (D_L01_002446C0.w92 == 0) {
            func_L01_004BEC88(D_L01_001E1008, D_L01_001E0F94 * ((M_004BF8A0 *)((u8 *)D_L01_002C5600 + D_001425C0[D_L01_002446C0.e[D_L01_002446C0.w128].w0] * 240))->h132);
        } else {
            func_L01_004BEC88(D_L01_001E1008, D_L01_001E0F94 * ((M_004BF8A0 *)((u8 *)D_L01_002C5600 + D_001425C0[D_L01_002446C0.e[D_L01_002446C0.w128].w0] * 240))->h134);
        }
        for (i = func_0011B868(D_L01_001E1008); i >= 0; i--) {
            D_L01_001E1008[i + 2] = D_L01_001E1008[i];
        }
        D_L01_001E1009 = ' ';
        D_L01_001E1008[0] = ' ';
        func_L01_00516EC8(0x48002D, &v[0], &v[1], &v[1], &v[1]);
        func_L01_00516470(0x480022, v[0], 0.33f);
    } else if (func_L01_004BA830() <= D_00142660[0]) {
        func_L01_00516FD8(0x480026, func_00381FF0(2256));
        func_L01_00516818(0x480026, 1.0f);
        func_L01_00518670(0x480026, 1, 1);
        func_L01_00516470(0x480026, 0.3f, 0.25f);
        func_L01_00516FD8(0x480029, func_00381FF0(2274));
        func_L01_00516FD8(0x48002A, func_00381FF0(2271));
        func_L01_00516AA0(0x48002D, 1, 0);
        func_L01_00516AA0(0x480022, 1, 0);
    }
}
/* localdecomp:end func_L01_004C3448 */

/* localdecomp:start func_L01_004C3840 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 D_L01_001E0F80;
extern s32 D_L01_001E0F7C;
extern u8 D_L01_002F2798[];

extern f32 func_L01_004451A8(f32 f12);
extern void func_L01_004C13B0(s32 a0, u8 *a1);

void func_L01_004C3840(s32 arg0) {
    f32 f;

    D_L01_001E0F80 = 1;
    ((void (*)(s32 a0, s32 a1, s32 a2))func_L01_00516AA0)(0x48000C, 1, 0);
    f = (f32)D_L01_001E0F7C / 15.0f;
    if (arg0 != 0) {
        f = 1.0f - f;
    }
    if (1.0f < f) {
        f = 1.0f;
    } else if (f < 0.0f) {
        f = 0.0f;
    }
    func_L01_004C13B0((s32)(func_L01_004451A8(f) * 128.0f), D_L01_002F2798);
}
/* localdecomp:end func_L01_004C3840 */

INCLUDE_ASM("asm/levels", func_L01_004C3910);

/* localdecomp:start func_L01_004C3A48 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern G_004BF8A0 D_L01_002446C0;
extern char *func_00381FF0(s32);
extern s32 D_00142660[];
extern void func_L01_00516FD8(s32, char *);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_004BEC88(char *, s32);




extern T_4BFEA0 D_L01_001DAE28;
extern u8 D_L01_001E1038[8];
extern u8 D_L01_001E0FF0[8];
extern u8 D_L01_002F2798[];
extern s32 D_L01_001E0F7C;
extern s32 D_L01_001E0F80;

extern s32 func_L01_00419D00(s32);
extern void func_L01_00516EC8(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_L01_004C0FD8(u8 *, s32, u32);
extern void func_L01_004C3840(s32);
extern void func_L01_00516D60(s32, s32);

void func_L01_004C3A48(void) {
    G_4BFEA0 *g;
    T_4BFEA0 t;
    s32 idx;
    s32 val;
    s32 lt;
    s32 on;
    s32 n;
    u32 col;
    f32 sc;
    f32 x;
    f32 y;

    g = &(*(G_4BFEA0 *)&D_L01_002446C0);
    idx = g->ent[g->sel].idx;
    if (idx == 0) {
        idx = (*(H_4BFEA0 *)&D_00142660).w78;
    }
    t = D_L01_001DAE28;
    col = 0x80707070;
    sc = 0.563f;
    ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000B, ((s32 (*)(s32))func_00381FF0)(func_L01_00419D00(idx)));
    ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000C, ((s32 (*)(s32))func_00381FF0)(t.a[idx]));
    ((void (*)(u8 *, s32))func_L01_004BEC88)(D_L01_001E1038, (*(H_4BFEA0 *)&D_00142660).w0);
    func_L01_00516EC8(0x480011, &x, &y, &y, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48001B, x - 0.015f, 0.64f);
    val = g->ent[g->sel].val;
    lt = val < (*(H_4BFEA0 *)&D_00142660).w0;
    ((void (*)(u8 *, s32))func_L01_004BEC88)(D_L01_001E0FF0, val);
    func_L01_00516EC8(0x48000E, &y, &y, &x, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48001A, x + 0.012f, sc);
    func_L01_00516EC8(0x48001A, &y, &y, &x, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48000F, x + 0.01f, sc);
    if (lt) {
        col = 0x8066CCFF;
    }
    func_L01_004C0FD8(D_L01_002F2798, 0x48001A, col);
    func_L01_004C0FD8(D_L01_002F2798, 0x48000F, col);
    n = g->w4;
    if (n < 15) {
        D_L01_001E0F7C = n;
        func_L01_004C3840(0);
        ((void (*)(s32, s32, s32))func_L01_00516AA0)(0x48000C, 1, 0);
    } else {
        D_L01_001E0F80 = 0;
        ((void (*)(s32, s32, s32))func_L01_00516AA0)(0x48000C, 1, 1);
    }
    if (val == 0) {
        ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000B, ((s32 (*)(s32))func_00381FF0)(1196));
    }
    on = val != 0;
    func_L01_00516D60(0x480011, on);
    func_L01_00516D60(0x48001B, on);
    func_L01_00516D60(0x48000E, on);
    func_L01_00516D60(0x48001A, on);
    func_L01_00516D60(0x48000F, on);
    func_L01_00516D60(0x480012, on);
    if (val != 0) {
        func_L01_00516D60(0x480012, lt);
    }
}
/* localdecomp:end func_L01_004C3A48 */

/* localdecomp:start func_L01_004C3D70 */
extern char *func_00381FF0(s32);
extern G_004BF8A0 D_L01_002446C0;
extern s32 D_00142660[];
extern void func_L01_00516FD8(s32, char *);
extern s32 D_L01_001E0F80;
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L01_004C3D70(void) {
    S_4C01C8 *b = ((S_4C01C8 *)&(*(G_4BFEA0 *)&D_L01_002446C0));

    if (b->f84 == 0) {
        ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480012, ((s32 (*)(s32))func_00381FF0)(2252));
        ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480013, ((s32 (*)(s32))func_00381FF0)(256));
        func_L01_00516AA0(0x48000D, 1, 0);
        if (D_L01_001E0F80 == 0) {
            func_L01_00516AA0(0x48000C, 1, 1);
        }
    } else {
        if (((s32 *)&(*(H_4BFEA0 *)&D_00142660))[0] >= b->e[b->f80].f0) {
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480012, ((s32 (*)(s32))func_00381FF0)(2274));
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480013, ((s32 (*)(s32))func_00381FF0)(2271));
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000D, ((s32 (*)(s32))func_00381FF0)(2256));
        } else {
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000D, ((s32 (*)(s32))func_00381FF0)(2255));
        }
        func_L01_00516AA0(0x48000D, 1, 1);
        func_L01_00516AA0(0x48000C, 1, 0);
    }
}
/* localdecomp:end func_L01_004C3D70 */

INCLUDE_ASM("asm/levels", func_L01_004C3EB8);

INCLUDE_ASM("asm/levels", func_L01_004C42D0);

/* localdecomp:start func_L01_004C4380 */
extern VObj_4BEB00 *func_003B42F8(s32);
extern void func_L01_004C13B0(s32 a0, u8 *a1);
extern S_func_004C07D8 D_00160C40[];
extern u8 D_L01_002F2CD8[];
extern s16 D_001CCFD4[];
extern u8 D_L01_00244E50[];
extern u8 D_L01_00249650[];
extern void func_L01_00516468_004C4380(s32);
extern s32 func_L01_0047B3D8(void);
extern s32 func_L01_00479248(void);
extern s32 func_L01_0047B948(void);
extern void func_L01_004C1028(void *);
extern s32 func_003E8348(s32, s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_004C44D8(void);
extern void func_L01_004C47A0(void);
void func_L01_004C4380(void) {
    func_L01_00516468_004C4380(1);
    func_L01_0047B3D8();
    func_L01_00479248();
    func_L01_0047B948();
    func_L01_004C1028(D_L01_002F2CD8);
    func_003E8348(27, 0x480000);
    ((void (*)(s32, void *))func_L01_004C13B0)(0, D_L01_002F2CD8);
    if (D_001CCFD4[0] == 0) {
        func_003B4528(((void * (*)(s32))func_003B42F8)(0), (s32)D_L01_00244E50, 0, D_00160C40->f4954, (s32)D_00160C40->fX);
        func_003E8710(0x480019, (s32)((void * (*)(s32))func_003B42F8)(0));
        func_003B4528(((void * (*)(s32))func_003B42F8)(1), (s32)D_L01_00249650, 0, D_00160C40->f4954, (s32)D_00160C40->fX);
        func_003E8710(0x48001A, (s32)((void * (*)(s32))func_003B42F8)(1));
        func_L01_00517190(0x480019, 43);
        func_L01_00517190(0x48001A, 44);
        func_L01_00516AA0(0x480019, 0x8000, 1);
        func_L01_00516AA0(0x48001A, 0x8000, 1);
    }
    func_L01_00516468_004C4380(0);
    func_L01_004C44D8();
    func_L01_004C47A0();
}
/* localdecomp:end func_L01_004C4380 */

INCLUDE_ASM("asm/levels", func_L01_004C44D8);

/* localdecomp:start func_L01_004C47A0 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern G_004BF8A0 D_L01_002446C0;


extern s32 D_00142660[];
extern char *func_00381FF0(s32 id);
extern void func_L01_00516FD8(s32 id, char *s);

void func_L01_004C47A0(void) {
    B_4C0BF8 *b = &(*(B_4C0BF8 *)&D_L01_002446C0);
    s32 idx = b->idx;

    if (b->active == 0) {
        func_L01_00516FD8(0x480014, func_00381FF0(2252));
        func_L01_00516FD8(0x480015, func_00381FF0(256));
        ((void (*)(s32 id, s32 a, s32 b))func_L01_00516AA0)(0x480016, 1, 0);
        return;
    }
    if (b->e[idx].w32 <= D_00142660[0]) {
        func_L01_00516FD8(0x480014, func_00381FF0(2274));
        func_L01_00516FD8(0x480015, func_00381FF0(2271));
        func_L01_00516FD8(0x480016, func_00381FF0(2256));
    } else {
        func_L01_00516FD8(0x480016, func_00381FF0(2255));
        func_L01_00516FD8(0x480015, func_00381FF0(2251));
    }
    ((void (*)(s32 id, s32 a, s32 b))func_L01_00516AA0)(0x480016, 1, 1);
}
/* localdecomp:end func_L01_004C47A0 */

INCLUDE_ASM("asm/levels", func_L01_004C48D0);

/* localdecomp:start func_L01_004C4D90 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 D_L01_001E0F80;
extern s32 D_L01_001E0F7C;
extern u8 D_L01_002F3218[];

extern f32 func_L01_004451A8(f32 f12);
extern void func_L01_004C13B0(s32 a0, u8 *a1);

void func_L01_004C4D90(s32 arg0) {
    f32 f;

    D_L01_001E0F80 = 1;
    ((void (*)(s32 a0, s32 a1, s32 a2))func_L01_00516AA0)(0x48000C, 1, 0);
    f = (f32)D_L01_001E0F7C / 15.0f;
    if (arg0 != 0) {
        f = 1.0f - f;
    }
    if (1.0f < f) {
        f = 1.0f;
    } else if (f < 0.0f) {
        f = 0.0f;
    }
    func_L01_004C13B0((s32)(func_L01_004451A8(f) * 128.0f), D_L01_002F3218);
}
/* localdecomp:end func_L01_004C4D90 */

INCLUDE_ASM("asm/levels", func_L01_004C4E60);

INCLUDE_ASM("asm/levels", func_L01_004C4FE8);

/* localdecomp:start func_L01_004C51E0 */
extern void func_L01_00516D60(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_004BEC88(char *, s32);
extern void func_L01_00516FD8(s32 id, char *s);
extern char *func_00381FF0(s32 id);
extern G_004BF8A0 D_L01_002446C0;



extern T_4C1638 D_L01_002F1C20[];
extern u8 D_L01_001E1038[8];
extern u8 D_L01_001E0FF0[8];
extern s32 D_L01_001E0F7C;
extern s32 D_L01_001E0F80;

extern void func_L01_004C1838(void);
extern s32 func_L01_004526F8(void);
extern void func_L01_00516EC8(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_L01_005170B8_004C51E0(s32, u32);
extern void func_L01_004C4D90(s32);

void func_L01_004C51E0(void) {
    G_4C1638 *g;
    s32 idx;
    s32 val;
    s32 en;
    s32 on;
    s32 n;
    u32 col;
    f32 sc;
    f32 x;
    f32 y;

    g = &(*(G_4C1638 *)&D_L01_002446C0);
    col = 0x80707070;
    sc = 0.563f;
    idx = g->ent[g->sel].idx;
    ((void (*)(s32, s32))func_L01_00516FD8)(0x48000B, ((s32 (*)(s32))func_00381FF0)(D_L01_002F1C20[idx].w0));
    ((void (*)(s32, s32))func_L01_00516FD8)(0x48000C, ((s32 (*)(s32))func_00381FF0)(D_L01_002F1C20[idx].w4));
    func_L01_004C1838();
    n = func_L01_004526F8();
    ((void (*)(u8 *, s32))func_L01_004BEC88)(D_L01_001E1038, n);
    func_L01_00516EC8(0x480011, &x, &y, &y, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48001B, x - 0.015f, 0.64f);
    val = g->ent[g->sel].val;
    en = func_L01_004526F8() >= val;
    if (val == 255) {
        en = 0;
    }
    ((void (*)(u8 *, s32))func_L01_004BEC88)(D_L01_001E0FF0, val);
    func_L01_00516EC8(0x48000E, &y, &y, &x, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48001A, x + 0.012f, sc);
    func_L01_00516EC8(0x48001A, &y, &y, &x, &y);
    ((s32 (*)(s32, f32, f32))func_L01_00516470)(0x48000F, x + 0.01f, sc);
    if (en) {
        col = 0x8066CCFF;
    }
    func_L01_005170B8_004C51E0(0x48001A, col);
    func_L01_005170B8_004C51E0(0x48000F, col);
    n = g->w4;
    if (n < 15) {
        D_L01_001E0F7C = n;
        func_L01_004C4D90(0);
        ((void (*)(s32, s32, s32))func_L01_00516AA0)(0x48000C, 1, 0);
    } else {
        D_L01_001E0F80 = 0;
        ((void (*)(s32, s32, s32))func_L01_00516AA0)(0x48000C, 1, 1);
    }
    if (val == 0) {
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x480012, 1);
        ((void (*)(s32, s32))func_L01_00516FD8)(0x480012, ((s32 (*)(s32))func_00381FF0)(268));
    } else {
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x480012, 0);
    }
    on = val != 0;
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x480011, on);
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x48001B, on);
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x48000E, on);
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x48001A, on);
    ((s32 (*)(s32, s32))func_L01_00516D60)(0x48000F, on);
    if (val == 255) {
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x480011, 0);
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x48001B, 0);
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x48000E, 0);
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x48001A, 0);
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x48000F, 0);
    }
    if (val != 0) {
        ((s32 (*)(s32, s32))func_L01_00516D60)(0x480012, en);
    }
}
/* localdecomp:end func_L01_004C51E0 */

/* localdecomp:start func_L01_004C5530 */
extern void func_L01_00516FD8(s32 id, char *s);
extern char *func_00381FF0(s32 id);
extern G_004BF8A0 D_L01_002446C0;
extern s32 D_L01_001E0F80;
extern s32 func_L01_004526F8(void);
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L01_004C5530(void) {
    S_4C1988 *b = ((S_4C1988 *)&D_L01_002446C0);
    s32 n = b->e[b->f80].f0;

    if (b->f84 == 0) {
        if (n != 0) {
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480012, ((s32 (*)(s32))func_00381FF0)(2252));
        }
        ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480013, ((s32 (*)(s32))func_00381FF0)(256));
        func_L01_00516AA0(0x48000D, 1, 0);
        if (D_L01_001E0F80 == 0) {
            func_L01_00516AA0(0x48000C, 1, 1);
        }
    } else {
        if (func_L01_004526F8() >= n) {
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480012, ((s32 (*)(s32))func_00381FF0)(2274));
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x480013, ((s32 (*)(s32))func_00381FF0)(2271));
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000D, ((s32 (*)(s32))func_00381FF0)(2256));
        } else {
            ((s32 (*)(s32, s32))func_L01_00516FD8)(0x48000D, ((s32 (*)(s32))func_00381FF0)(2255));
        }
        func_L01_00516AA0(0x48000D, 1, 1);
        func_L01_00516AA0(0x48000C, 1, 0);
    }
}
/* localdecomp:end func_L01_004C5530 */

LINKER_REMNANT("asm/levels", func_L01_004C5688);
