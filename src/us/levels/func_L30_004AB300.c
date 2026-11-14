#include "common.h"

/* NTSC-U counterpart of func_L30_004AEF20 (src/levels/shared/L30_004AEF20.c) */
/* localdecomp:start func_L30_004AB300 */
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

extern Hero_004AEF20 D_001A4BE0;
extern Elem_004AEF20 D_L30_002F2C10[6];
extern f32 D_L30_002F407C __attribute__((section(".data")));
extern f32 D_L30_001DBBFC;
__asm__(".extern D_L30_001DBBFC, 4");
extern f32 D_L30_001E22D8_004AB300 __attribute__((section(".data")));
extern s32 D_L30_001DF2C0_004AB300;

extern void func_L01_0050BF58(void);
extern void func_L30_004B8A80(void);
extern void func_L01_004E3EF0(void);
extern s32 func_L01_004E4550(s32, s32, s32);
extern void func_L01_004EFDD8(void);
extern void func_L01_004DCF08(void);
extern void func_L01_004DCFA0(void);
extern void func_L01_004E5E40(void *, s32);
extern void func_L30_004E19F8(void);
extern void func_L30_004E2E08(void);
extern void func_L30_004E2FD8(void);
extern s32 func_L30_004E2300(s8 *, s8 *, s8 *);
extern s32 func_L30_004E1888(void);
extern s32 func_L30_004E2168(void);
extern void func_L30_004CB6E0(s32, s32);
extern void func_L30_004E2058(void);
extern s32 func_00388398(void *);
extern void func_L30_004D34B0(void);
extern void func_L01_004C8A20_004AB300(void);
extern void func_L01_004F1208(void);
extern void func_L01_004DC790(void);
extern void func_L01_004E09A8(void);
extern void func_L01_004DF380(void);
extern void func_L01_0050EE90(void);
extern void func_L01_004DF108(void);
extern void func_L01_004DCC10(void);
extern void func_L01_004DCFC8(void);
extern void func_L01_004DD310(void);
extern void func_0039FE80(s32, s32, void *);
extern s32 func_003883C8(void *);
extern f32 func_00389380(f32, f32);
extern void func_L01_0042D288(void *);
extern void func_L01_004E0B00(void);
extern void func_L01_004405F4(void *);

void func_L30_004AB300(void)
{
    u8 kind;
    s32 side;
    s32 t;
    s32 i;

    func_L01_0050BF58();
    func_L30_004B8A80();
    func_L01_004E3EF0();
    kind = D_001A4BE0.body_kind;
    if (kind == 1) {
        func_L01_004E4550((s32)D_001A4BE0.pos, (s32)D_001A4BE0.rot, (s32)D_001A4BE0.ledge);
        func_L01_004EFDD8();
        if (D_001A4BE0.body_kind == kind) {
            func_L01_004DCF08();
            func_L01_004DCFA0();
        }
    }
    D_001A4BE0.w238 = 4;
    kind = D_001A4BE0.body_kind;
    if (kind == 5) {
        D_001A4BE0.pos[1] = D_001A4BE0.f1B0C;
        func_L01_004E5E40(D_001A4BE0.x1AB0, 3);
        func_L30_004E19F8();
        if (D_001A4BE0.body_kind == kind) {
            D_001A4BE0.h226 = 4;
        }
        func_L30_004E2E08();
        func_L30_004E2FD8();
        func_L30_004E2300((s8 *)D_001A4BE0.pos, (s8 *)D_001A4BE0.rot, (s8 *)D_001A4BE0.ledge);
        if (func_L30_004E1888() != 0) {
            return;
        }
        t = func_L30_004E2168();
        if (t != 0 && D_001A4BE0.state_type != 0x24) {
            D_001A4BE0.w1B30 = t;
            func_L30_004CB6E0(0xAB, 1);
        }
        if (D_001A4BE0.state != 0x74 && D_001A4BE0.state_type != 0x14) {
            if (D_001A4BE0.h1DC != 0) {
                if (D_L30_001DF2C0_004AB300 % 10 < 5) {
                    D_001A4BE0.moby->alpha = 0x10;
                } else {
                    D_001A4BE0.moby->alpha = 0x40;
                }
                D_001A4BE0.moby->flags |= 8;
            } else {
                D_001A4BE0.moby->alpha = 0x80;
                D_001A4BE0.moby->flags &= ~8;
            }
        }
        if (D_001A4BE0.state_type == 0x14) {
            D_001A4BE0.moby->alpha = 0x80;
            D_001A4BE0.moby->flags &= ~8;
        }
        func_L30_004E2058();
        for (i = 0; i < 6; i++) {
            func_00388398(&D_L30_002F2C10[i]);
        }
    }
    func_L30_004D34B0();
    func_L01_004C8A20_004AB300();
    if (D_001A4BE0.body_kind == 0) {
        return;
    }
    func_L01_004F1208();
    func_L01_004DC790();
    if (D_001A4BE0.body_kind == 0) {
        return;
    }
    func_L01_004E09A8();
    func_L01_004DF380();
    func_L01_0050EE90();
    func_L01_004DF108();
    if (D_001A4BE0.body_kind == 1) {
        D_L30_002F407C = D_L30_001DBBFC;
        func_L01_004DCC10();
        func_L01_004DCFC8();
        func_L01_004DD310();
        if (D_001A4BE0.w286C != 0) {
            func_0039FE80(D_001A4BE0.w286C + 0x10, 0, D_001A4BE0.moby);
            D_001A4BE0.h28A8 = 0x39;
            D_001A4BE0.h28AA = D_001A4BE0.w286C;
        }
        D_001A4BE0.w286C = 0;
    }
    if (D_001A4BE0.body_kind == 5) {
        func_003883C8(&D_001A4BE0.h1B2A);
        side = 2;
        if (D_001A4BE0.state == 0x9D && D_001A4BE0.state_timer >= 7) {
        } else {
            if (D_001A4BE0.state_type != 0x14 && D_001A4BE0.state_type != 0x1A && D_001A4BE0.state_type != 7
                && D_001A4BE0.state_type != 9 && D_001A4BE0.state != 0xAB
                && D_001A4BE0.moby->b43 != 0x3A && D_001A4BE0.state != 0xA6) {
                if (D_001A4BE0.f2838 > 0.2f) {
                    if (D_001A4BE0.stick_x > 0.01f) {
                        side = 1;
                    } else if (D_001A4BE0.stick_x < -0.01f) {
                        side = 0;
                    }
                }
                if (D_001A4BE0.h1B2A != 0) {
                    side = D_001A4BE0.w1B2C;
                }
                if (side == 1) {
                    D_001A4BE0.rot[2] = func_00389380(D_L30_001E22D8_004AB300, -1.5707964f);
                    D_001A4BE0.moby->flags &= 0x7FFF;
                } else if (side == 0) {
                    D_001A4BE0.rot[2] = func_00389380(D_L30_001E22D8_004AB300, 1.5707964f);
                    D_001A4BE0.moby->flags |= 0x8000;
                }
                if (side != 2) {
                    D_001A4BE0.side = side;
                }
            }
        }
    }
    func_L01_0042D288(D_001A4BE0.pos);
    if (D_001A4BE0.body_kind == 3) {
        if (D_001A4BE0.w25F8 != 0 && D_001A4BE0.w25F8 != 0x1E) {
            if (D_001A4BE0.h288C == 0) {
                D_001A4BE0.h2888 = 1;
                D_001A4BE0.h288C = 0x12;
                D_001A4BE0.h288A = 1;
            }
        } else {
            D_001A4BE0.w25F8 = 0;
        }
    }
    func_L01_004E0B00();
    func_L01_004405F4(D_001A4BE0.moby);
}
/* localdecomp:end func_L30_004AB300 */
