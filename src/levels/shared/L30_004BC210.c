#include "common.h"

/* localdecomp:start func_L30_004BC210 */
typedef struct {
    u8 pad0[0x80];
    f32 pos[4];                 /* 0x80 */
    u8 pad90[0x1B8 - 0x90];
    s32 state_timer;            /* 0x1B8 */
    u8 pad1BC[0x260 - 0x1BC];
    f32 v260[4];                /* 0x260 */
    f32 cur_x;                  /* 0x270 */
    f32 cur_y;                  /* 0x274 */
    f32 tgt_x;                  /* 0x278 */
    f32 tgt_y;                  /* 0x27C */
    f32 tgt_z;                  /* 0x280 */
    f32 cur_z;                  /* 0x284 */
    f32 vel_z;                  /* 0x288 */
    u8 pad28C[0x2A7 - 0x28C];
    u8 b2A7;                    /* 0x2A7 */
    u8 pad2A8[0x360 - 0x2A8];
    s32 ground_frames;          /* 0x360 */
    u8 pad364[0x46E - 0x364];
    u8 jump_past_apex;          /* 0x46E */
    u8 pad46F[0x47C - 0x46F];
    s16 jump_push_frames;       /* 0x47C */
    u8 pad47E[0x488 - 0x47E];
    f32 f488;                   /* 0x488 */
    u8 pad48C[0x1474 - 0x48C];
    u8 b1474;                   /* 0x1474 */
    u8 pad1475;
    u8 in_puddle;               /* 0x1476 */
    u8 pad1477[0x25C4 - 0x1477];
    s32 state;                  /* 0x25C4 */
    u8 pad25C8[0x25CC - 0x25C8];
    s32 state_type;             /* 0x25CC */
    u8 pad25D0[0x25D4 - 0x25D0];
    s32 prev_state;             /* 0x25D4 */
    u8 pad25D8[0x25E0 - 0x25D8];
    s32 s25E0;                  /* 0x25E0 */
    u8 body_kind;               /* 0x25E4 */
} H_004BC210;

extern H_004BC210 D_001A4BE0;
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);

void func_L30_004BC210(s32 snap) {
    switch (D_001A4BE0.body_kind) {
    case 0:
        D_001A4BE0.tgt_x = 0.8f;
        D_001A4BE0.tgt_y = 0.7f;
        D_001A4BE0.tgt_z = 0.45f;
        break;
    case 1:
        D_001A4BE0.tgt_x = 0.55f;
        D_001A4BE0.tgt_y = 0.45f;
        D_001A4BE0.tgt_z = 0.25f;
        break;
    case 5:
        D_001A4BE0.tgt_x = 1.71999991f;
        D_001A4BE0.tgt_y = 1.2f;
        D_001A4BE0.tgt_z = 0.85f;
        break;
    case 3:
        D_001A4BE0.tgt_x = 0.8f;
        D_001A4BE0.tgt_y = 0.6f;
        D_001A4BE0.tgt_z = 0.45f;
        break;
    }

    if (D_001A4BE0.state_type == 4) {
        if (D_001A4BE0.jump_push_frames < D_001A4BE0.state_timer && D_001A4BE0.jump_past_apex == 0) {
            D_001A4BE0.tgt_y = D_001A4BE0.f488;
        }
    } else if (D_001A4BE0.state == 6) {
        D_001A4BE0.tgt_y = 0.5f;
    } else if (D_001A4BE0.state == 4) {
        D_001A4BE0.tgt_x = 0.350000024f;
    } else if (D_001A4BE0.state_type == 0x11 || D_001A4BE0.state_type == 0x12) {
        D_001A4BE0.tgt_x = 0.0f;
        D_001A4BE0.tgt_y = 0.0f;
    } else if (D_001A4BE0.b1474 != 0 && D_001A4BE0.ground_frames != 0) {
        D_001A4BE0.tgt_x = 0.8f;
        D_001A4BE0.tgt_y = 0.9f;
    } else if (D_001A4BE0.state == 0x81) {
        D_001A4BE0.tgt_z = 0.8f;
    } else if (D_001A4BE0.state == 0x50) {
        D_001A4BE0.tgt_z = 0.5f;
    } else if (D_001A4BE0.state == 0xA3) {
        D_001A4BE0.tgt_x = 1.4f - D_001A4BE0.cur_z;
        D_001A4BE0.tgt_z = 0.57f;
    } else if (D_001A4BE0.state == 0xA6) {
        D_001A4BE0.tgt_x = 1.3f - D_001A4BE0.cur_z;
        D_001A4BE0.tgt_z = 0.9f;
    }

    if (D_001A4BE0.body_kind == 5) {
        func_003C4138(&D_001A4BE0.cur_x, D_001A4BE0.tgt_x, 0.24000001f);
        func_003C4138(&D_001A4BE0.cur_y, D_001A4BE0.tgt_y, 0.24000001f);
        func_003C4138(&D_001A4BE0.cur_z, D_001A4BE0.tgt_z, 0.140000015f);
        return;
    }
    if (snap) {
        D_001A4BE0.cur_x = D_001A4BE0.tgt_x;
        D_001A4BE0.cur_y = D_001A4BE0.tgt_y;
        D_001A4BE0.cur_z = D_001A4BE0.tgt_z;
    }
    if (D_001A4BE0.b2A7 == 0 || D_001A4BE0.prev_state == 0x12 || D_001A4BE0.s25E0 == 0x12
        || (D_001A4BE0.body_kind == 0 && D_001A4BE0.cur_y < 0.53f) || D_001A4BE0.state_type == 0x11 || D_001A4BE0.in_puddle != 0
        || func_0038CF38(D_001A4BE0.v260, D_001A4BE0.pos) > D_001A4BE0.cur_z * 0.5f) {
        func_003C4138(&D_001A4BE0.cur_x, D_001A4BE0.tgt_x, 0.024f);
        func_003C4138(&D_001A4BE0.cur_y, D_001A4BE0.tgt_y, 0.024f);
        func_L01_004482A0(&D_001A4BE0.cur_z, &D_001A4BE0.vel_z, D_001A4BE0.tgt_z, 0.0288000014f, 0.432000041f, 0.0800000057f);
    }
}
/* localdecomp:end func_L30_004BC210 */
