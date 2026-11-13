#include "common.h"

/* localdecomp:start func_L30_004AEF20 */
typedef struct {
    u8 pad_0[0x23];
    u8 alpha;               /* 0x23 */
    u8 pad_24[0x34 - 0x24];
    u16 flags;              /* 0x34 */
    u8 pad_36[0x43 - 0x36];
    u8 b43;                 /* 0x43 */
} Moby_004AEF20;

typedef struct {
    u8 pad_0[0x80];
    f32 pos[4];             /* 0x80 */
    f32 rot[4];             /* 0x90 */
    u8 pad_A0[0x1B8 - 0xA0];
    s32 state_timer;        /* 0x1B8 */
    u8 pad_1BC[0x1DC - 0x1BC];
    s16 h1DC;               /* 0x1DC */
    u8 pad_1DE[0x226 - 0x1DE];
    s16 h226;               /* 0x226 */
    u8 pad_228[0x238 - 0x228];
    s32 w238;               /* 0x238 */
    u8 pad_23C[0x500 - 0x23C];
    f32 ledge[4];           /* 0x500 */
    u8 pad_510[0x1AB0 - 0x510];
    u8 x1AB0[0x1B0C - 0x1AB0]; /* 0x1AB0 */
    f32 f1B0C;              /* 0x1B0C */
    u8 pad_1B10[0x1B28 - 0x1B10];
    s16 side;               /* 0x1B28 */
    s16 h1B2A;              /* 0x1B2A */
    s32 w1B2C;              /* 0x1B2C */
    s32 w1B30;              /* 0x1B30 */
    u8 pad_1B34[0x2260 - 0x1B34];
    f32 stick_x;            /* 0x2260 */
    u8 pad_2264[0x25C0 - 0x2264];
    Moby_004AEF20 *moby;    /* 0x25C0 */
    s32 state;              /* 0x25C4 */
    s32 substate;           /* 0x25C8 */
    s32 state_type;         /* 0x25CC */
    u8 pad_25D0[0x25E4 - 0x25D0];
    u8 body_kind;           /* 0x25E4 */
    u8 pad_25E5[0x25F8 - 0x25E5];
    s32 w25F8;              /* 0x25F8 */
    u8 pad_25FC[0x2838 - 0x25FC];
    f32 f2838;              /* 0x2838 */
    u8 pad_283C[0x286C - 0x283C];
    s32 w286C;              /* 0x286C */
    u8 pad_2870[0x2888 - 0x2870];
    s16 h2888;              /* 0x2888 */
    s16 h288A;              /* 0x288A */
    s16 h288C;              /* 0x288C */
    u8 pad_288E[0x28A8 - 0x288E];
    s16 h28A8;              /* 0x28A8 */
    s16 h28AA;              /* 0x28AA */
} Hero_004AEF20;

typedef struct {
    u8 pad[0x70];
} Elem_004AEF20;

extern Hero_004AEF20 D_1A4BE0;
extern Elem_004AEF20 D_L30_002F2C50[6];
extern f32 D_L30_002F40BC __attribute__((section(".data")));
extern f32 D_L30_001DBBBC;
__asm__(".extern D_L30_001DBBBC, 4");
extern f32 D_L30_001E22D8 __attribute__((section(".data")));
extern s32 D_L30_001DF2C0;

extern void func_L01_0050FF00(void);
extern void func_L30_004BC770(void);
extern void func_L01_004E7CB8(void);
extern s32 func_L01_004E8318(s32, s32, s32);
extern void func_L01_004F3BE0(void);
extern void func_L01_004E0C18(void);
extern void func_L01_004E0CB0(void);
extern void func_L01_004E9C08(void *, s32);
extern void func_L30_004E58F8(void);
extern void func_L30_004E6D08(void);
extern void func_L30_004E6ED8(void);
extern s32 func_L30_004E6200(s8 *, s8 *, s8 *);
extern s32 func_L30_004E5788(void);
extern s32 func_L30_004E6068(void);
extern void func_L30_004CF4B0(s32, s32);
extern void func_L30_004E5F58(void);
extern s32 func_0038CAD0(void *);
extern void func_L30_004D7368(void);
extern void func_L01_004CC698_004AEF20(void);
extern void func_L01_004F5010(void);
extern void func_L01_004E04A0(void);
extern void func_L01_004E4770(void);
extern void func_L01_004E3148(void);
extern void func_L01_00512E68(void);
extern void func_L01_004E2ED0(void);
extern void func_L01_004E0920(void);
extern void func_L01_004E0CD8(void);
extern void func_L01_004E1020(void);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_00430118(void *);
extern void func_L01_004E48C8(void);
extern void func_L01_004436F4(void *);

void func_L30_004AEF20(void)
{
    u8 kind;
    s32 side;
    s32 t;
    s32 i;

    func_L01_0050FF00();
    func_L30_004BC770();
    func_L01_004E7CB8();
    kind = D_1A4BE0.body_kind;
    if (kind == 1) {
        func_L01_004E8318((s32)D_1A4BE0.pos, (s32)D_1A4BE0.rot, (s32)D_1A4BE0.ledge);
        func_L01_004F3BE0();
        if (D_1A4BE0.body_kind == kind) {
            func_L01_004E0C18();
            func_L01_004E0CB0();
        }
    }
    D_1A4BE0.w238 = 3;
    kind = D_1A4BE0.body_kind;
    if (kind == 5) {
        D_1A4BE0.pos[1] = D_1A4BE0.f1B0C;
        func_L01_004E9C08(D_1A4BE0.x1AB0, 3);
        func_L30_004E58F8();
        if (D_1A4BE0.body_kind == kind) {
            D_1A4BE0.h226 = 4;
        }
        func_L30_004E6D08();
        func_L30_004E6ED8();
        func_L30_004E6200((s8 *)D_1A4BE0.pos, (s8 *)D_1A4BE0.rot, (s8 *)D_1A4BE0.ledge);
        if (func_L30_004E5788() != 0) {
            return;
        }
        t = func_L30_004E6068();
        if (t != 0 && D_1A4BE0.state_type != 0x24) {
            D_1A4BE0.w1B30 = t;
            func_L30_004CF4B0(0xAB, 1);
        }
        if (D_1A4BE0.state != 0x74 && D_1A4BE0.state_type != 0x14) {
            if (D_1A4BE0.h1DC != 0) {
                if (D_L30_001DF2C0 % 8 < 4) {
                    D_1A4BE0.moby->alpha = 0x10;
                } else {
                    D_1A4BE0.moby->alpha = 0x40;
                }
                D_1A4BE0.moby->flags |= 8;
            } else {
                D_1A4BE0.moby->alpha = 0x80;
                D_1A4BE0.moby->flags &= ~8;
            }
        }
        if (D_1A4BE0.state_type == 0x14) {
            D_1A4BE0.moby->alpha = 0x80;
            D_1A4BE0.moby->flags &= ~8;
        }
        func_L30_004E5F58();
        for (i = 0; i < 6; i++) {
            func_0038CAD0(&D_L30_002F2C50[i]);
        }
    }
    func_L30_004D7368();
    func_L01_004CC698_004AEF20();
    if (D_1A4BE0.body_kind == 0) {
        return;
    }
    func_L01_004F5010();
    func_L01_004E04A0();
    if (D_1A4BE0.body_kind == 0) {
        return;
    }
    func_L01_004E4770();
    func_L01_004E3148();
    func_L01_00512E68();
    func_L01_004E2ED0();
    if (D_1A4BE0.body_kind == 1) {
        D_L30_002F40BC = D_L30_001DBBBC;
        func_L01_004E0920();
        func_L01_004E0CD8();
        func_L01_004E1020();
        if (D_1A4BE0.w286C != 0) {
            func_003A52A0(D_1A4BE0.w286C + 0x10, 0, D_1A4BE0.moby);
            D_1A4BE0.h28A8 = 0x2F;
            D_1A4BE0.h28AA = D_1A4BE0.w286C;
        }
        D_1A4BE0.w286C = 0;
    }
    if (D_1A4BE0.body_kind == 5) {
        func_0038CB00(&D_1A4BE0.h1B2A);
        side = 2;
        if (D_1A4BE0.state == 0x9D && D_1A4BE0.state_timer >= 6) {
        } else {
            if (D_1A4BE0.state_type != 0x14 && D_1A4BE0.state_type != 0x1A && D_1A4BE0.state_type != 7
                && D_1A4BE0.state_type != 9 && D_1A4BE0.state != 0xAB
                && D_1A4BE0.moby->b43 != 0x3A && D_1A4BE0.state != 0xA6) {
                if (D_1A4BE0.f2838 > 0.2f) {
                    if (D_1A4BE0.stick_x > 0.01f) {
                        side = 1;
                    } else if (D_1A4BE0.stick_x < -0.01f) {
                        side = 0;
                    }
                }
                if (D_1A4BE0.h1B2A != 0) {
                    side = D_1A4BE0.w1B2C;
                }
                if (side == 1) {
                    D_1A4BE0.rot[2] = func_0038DAB8(D_L30_001E22D8, -1.5707964f);
                    D_1A4BE0.moby->flags &= 0x7FFF;
                } else if (side == 0) {
                    D_1A4BE0.rot[2] = func_0038DAB8(D_L30_001E22D8, 1.5707964f);
                    D_1A4BE0.moby->flags |= 0x8000;
                }
                if (side != 2) {
                    D_1A4BE0.side = side;
                }
            }
        }
    }
    func_L01_00430118(D_1A4BE0.pos);
    if (D_1A4BE0.body_kind == 3) {
        if (D_1A4BE0.w25F8 != 0 && D_1A4BE0.w25F8 != 0x1E) {
            if (D_1A4BE0.h288C == 0) {
                D_1A4BE0.h2888 = 1;
                D_1A4BE0.h288C = 0x12;
                D_1A4BE0.h288A = 1;
            }
        } else {
            D_1A4BE0.w25F8 = 0;
        }
    }
    func_L01_004E48C8();
    func_L01_004436F4(D_1A4BE0.moby);
}
/* localdecomp:end func_L30_004AEF20 */
