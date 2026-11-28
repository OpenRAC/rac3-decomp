/* func_L01_004DF428 (Claude wave 14 retry r81, 2026-11-28). Replaces the earlier draft of this function (Codex wave 8 near miss). */
/* PAL near miss (wave 14 retry r81, 2026-11-28): func_L01_004DF428, 29 diff under the file's line
 * (build/codex/wave10/p10/check.py, level 01); r54's near had 31 (the Codex draft 201). Changed against r54's
 * near: the reset loop stores a local `none = -1` (its li now precedes the counter's as in retail: the
 * permuter's lever), and the two flag objects are stored D_00142CA0 first, D_00142D40 second (retail
 * fills the func_0039EF28 delay slot with the D_00142CA0 store and materialises D_00142D40 first).
 * Still differs: (1) the D_001A4C90 copy (6 rows): retail schedules %hi(D_001A4C90) before %hi of
 * D_L01_001DFC50 (mode stored before pos in the source changes nothing); (2) the float/flag block after
 * func_00382498 (22 rows): retail keeps 1 in $a1 and D_00142CA0 in $a0 with its la before the stores,
 * constants 0.007/0.3/1.15/0.12 in f3/f1/f0/f2; here 1 takes $a0, D_00142CA0 $v0 after the sw of the
 * call result, constants f0..f3 in order. Storing D_00142CA0.enabled directly (no pointer) measures 27
 * but gives the assembler's lui $at + sb 0x2ca2($at) where retail has la + sb 2($a0), so it is not used;
 * pointers assigned right after the call (four orders) stay at 29. */
#include "common.h"

/* localdecomp:start func_L01_004DF428 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x10];
    u128_t pos;        /* 0x10 */
    u8 pad20[0x14];
    u16 flags;         /* 0x34 */
    u8 pad36[0x2C];
    u8 b62;            /* 0x62 */
    u8 pad63[0x47];
    s16 type;          /* 0xAA */
    u8 padAC[0x14];
    u128_t rot[4];     /* 0xC0 */
} Moby_004DF428;

typedef struct {
    s32 value;
    u8 pad4[0x4C];
} Saved_004DF428;

typedef struct {
    u8 pad0[0x80];
    u128_t f80;                 /* 0x80 */
    u128_t f90;                 /* 0x90 */
    u8 padA0[0xBF8 - 0xA0];
    Moby_004DF428 *fBF8;        /* 0xBF8 */
    u8 padBFC[0xE90 - 0xBFC];
    f32 fE90;                   /* 0xE90 */
    f32 fE94;                   /* 0xE94 */
    f32 fE98;                   /* 0xE98 */
    u8 padE9C[0x1180 - 0xE9C];
    s32 f1180;                  /* 0x1180 */
    f32 f1184;                  /* 0x1184 */
    f32 f1188;                  /* 0x1188 */
    u8 pad118C[0x1228 - 0x118C];
    Saved_004DF428 saved[7];    /* 0x1228 */
    u8 pad1458[0x25C0 - 0x1458];
    Moby_004DF428 *f25C0;       /* 0x25C0 */
    u8 pad25C4[0x278C - 0x25C4];
    s32 reset[9];               /* 0x278C */
    u8 pad27B0[0x280C - 0x27B0];
    s32 f280C;                  /* 0x280C */
    u8 pad2810[0x2824 - 0x2810];
    f32 f2824;                  /* 0x2824 */
    f32 f2828;                  /* 0x2828 */
    u8 pad282C[0x2850 - 0x282C];
    s32 f2850;                  /* 0x2850 */
    s32 f2854;                  /* 0x2854 */
    s16 f2858;                  /* 0x2858 */
    u8 pad285A[0x2884 - 0x285A];
    s16 f2884;                  /* 0x2884 */
} H_004DF428;

typedef struct {
    u8 pad0[8];
    s32 count;      /* 0x08 */
    u8 padC[0x40 - 0xC];
    s16 state;      /* 0x40 */
    u8 pad42[0x78 - 0x42];
    s32 next;       /* 0x78 */
} G_004DF428;

typedef struct {
    u128_t pos;
    u8 pad10[0x2544 - 0x10];
    u8 mode;        /* 0x2544 */
} C_004DF428;

typedef struct {
    u128_t pos;
    u128_t rot;
} T_004DF428;

typedef struct {
    u8 b0;
    u8 active;
    u8 pad2[0x3E];
    u128_t f40, f50, f60, f70, f80, f90;
    u8 padA0[0x10];
} E_004DF428;

typedef struct {
    u8 b0, b1, enabled;
} F_004DF428;

extern H_004DF428 D_001A4BE0_004DF428;
extern G_004DF428 D_00142660;
extern C_004DF428 D_001A4C90;
extern u128_t D_L01_001DFC50[];
extern s32 D_L01_001D673C;
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0020;
extern T_004DF428 D_0016C5F0;
extern u128_t D_L01_001EAA20;
extern s32 D_001D4C40;
extern S_4DC790 D_L01_002F4540[];
extern F_004DF428 D_00142D40, D_00142CA0;

void func_L01_004DF428(void) {
    extern void func_L01_00425978(s32);
    extern void func_0038CB78(void *, s32, s32);
    extern void func_0038D308(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_L01_004EF840(void);
    extern void func_L01_004E45C8(void);
    extern void func_L01_0050FDD8(s32, s32);
    extern void func_L01_005138F8(void);
    extern s32 func_00382498(s32, s32);
    extern void func_0039EF28(void);
    extern s32 func_L01_00513EF0(void);
    extern void func_L01_004E1F00(s32);
    extern void func_L01_003F5AC0(s32, s32);
    s32 saved[7];
    vu0_v4 a;
    vu0_v4 b;
    s32 i;
    Moby_004DF428 *p;
    Moby_004DF428 *list;

    if (D_00142660.state == 4 && D_00142660.next != 4) {
        D_00142660.state = D_00142660.next;
        func_L01_00425978(D_00142660.next);
    }
    for (i = 0; i < 7; i++) {
        saved[i] = D_001A4BE0_004DF428.saved[i].value;
    }
    func_0038CB78(&D_001A4BE0_004DF428, 0, 0x28E0);
    for (i = 0; i < 7; i++) {
        saved[i] = D_001A4BE0_004DF428.saved[i].value;
    }
    if (D_L01_001D673C) {
        D_001A4C90.pos = D_L01_001DFC50[0];
        D_001A4C90.mode = 2;
    }
    list = (Moby_004DF428 *)D_L01_001E001C;
    for (i = 0; &list[i] < (Moby_004DF428 *)D_L01_001E0020; i++) {
        p = &list[i];
        if (p->type == 0) {
            D_001A4BE0_004DF428.f25C0 = p;
            func_0038D308(&p->rot[0], &p->rot[3]);
            D_001A4BE0_004DF428.f90 = D_001A4BE0_004DF428.f25C0->rot[3];
            func_0038CF68(&b, &D_001A4BE0_004DF428.f25C0->rot[2], -3.0f);
            func_0038CF68(&a, &D_001A4BE0_004DF428.f25C0->rot[2], 1.0f);
            vec_add_ab(&a, &a, &D_001A4BE0_004DF428.f25C0->pos);
            vec_add_ab(&b, &b, &D_001A4BE0_004DF428.f25C0->pos);
            if (func_003D3CB0(&a, &b, 2, D_001A4BE0_004DF428.f25C0, 0)) {
                D_001A4BE0_004DF428.f25C0->pos = D_L01_001EAA20;
            }
            D_001A4BE0_004DF428.f25C0->flags |= 2;
            D_001A4BE0_004DF428.fBF8 = D_001A4BE0_004DF428.f25C0;
            D_001A4BE0_004DF428.f80 = D_001A4BE0_004DF428.f25C0->pos;
            func_L01_004EF840();
            func_L01_004E45C8();
            func_L01_0050FDD8(0, 0);
            D_0016C5F0.pos = D_001A4BE0_004DF428.f80;
            D_0016C5F0.rot = D_001A4BE0_004DF428.f90;
            break;
        }
    }
    D_001A4BE0_004DF428.f25C0->b62 = 0xFF;
    if (D_001D4C40 == 0) {
        D_001D4C40 = 9;
    }
    for (i = 42; i >= 0; i--) {
        ((E_004DF428 *)D_L01_002F4540)[42 - i].active = 0;
        qzero(&((E_004DF428 *)D_L01_002F4540)[42 - i].f60);
        qzero(&((E_004DF428 *)D_L01_002F4540)[42 - i].f40);
        qzero(&((E_004DF428 *)D_L01_002F4540)[42 - i].f50);
        qzero(&((E_004DF428 *)D_L01_002F4540)[42 - i].f90);
        qzero(&((E_004DF428 *)D_L01_002F4540)[42 - i].f70);
        qzero(&((E_004DF428 *)D_L01_002F4540)[42 - i].f80);
    }
    {
        s32 none = -1;
        for (i = 8; i >= 0; i--) {
            D_001A4BE0_004DF428.reset[i] = none;
        }
    }
    D_001A4BE0_004DF428.f2824 = 2.125f;
    D_001A4BE0_004DF428.f2828 = 1.25f;
    if (D_00142660.count < 10) {
        D_00142660.count = 10;
    }
    if (D_00142660.count == 0) {
        func_L01_005138F8();
    }
    D_001A4BE0_004DF428.f2850 = D_00142660.count;
    D_001A4BE0_004DF428.f2854 = 4;
    D_001A4BE0_004DF428.f2858 = D_001A4BE0_004DF428.f2850;
    D_001A4BE0_004DF428.f1180 = func_00382498(150, 250);
    D_001A4BE0_004DF428.f1184 = 0.007f;
    D_001A4BE0_004DF428.f1188 = 0.3f;
    D_001A4BE0_004DF428.fE90 = 1.15f;
    D_001A4BE0_004DF428.fE94 = *(f32 *)((u8 *)&D_001A4BE0_004DF428.f80 + 8);
    D_001A4BE0_004DF428.fE98 = 0.12f;
    {
        F_004DF428 *f = &D_00142D40;
        F_004DF428 *g = &D_00142CA0;
        g->enabled = 1;
        f->enabled = 1;
    }
    func_0039EF28();
    D_001A4BE0_004DF428.f2884 = 0;
    if (func_L01_00513EF0() && D_001A4BE0_004DF428.f280C != 4 && D_001A4BE0_004DF428.f280C != 81) {
        D_001A4BE0_004DF428.f280C = 32;
    } else if (D_001A4BE0_004DF428.f280C == 32) {
        D_001A4BE0_004DF428.f280C = 0;
    }
    func_L01_004E1F00(0);
    func_L01_003F5AC0(0, 1);
}
/* localdecomp:end func_L01_004DF428 */
