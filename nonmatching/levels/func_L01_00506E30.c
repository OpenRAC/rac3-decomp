/*
 * NEAR MISS: hero_crouch_jump (func_L01_00506E30), 133 differing lines by check.py.
 * Every instruction matches retail by opcode and register (checked by normalising branch
 * offsets). What differs is the layout of the one shared jump tail
 * (`jal func_L01_005003D0(state, 1); return 1;`). Retail keeps two copies: the flip and the
 * other jump kinds jump to a copy placed after the R1 check, and the standing jump (state 7)
 * has its own copy at the end. gcc cross-jumps the two into one copy at the end, and the R1
 * test comes out inverted (`bnez` to the tail, not `beqz` past it). No flag or source wording
 * tried (about ten, see the report) kept both copies.
 *
 * Also: `extern u8 *D_001D52FC;` conflicts with the file's later `extern Pad_5075D8 *D_001D52FC;`
 * (L01_005063E8.c, the hero_quick_switch_button block). That is a whole-file build error, so this
 * block cannot be inserted until one declaration changes.
 */
typedef struct {
    u8 pad0[0x178];
    f32 ground_speed;              /* 0x178: the speed the crouch jumps test (not named in hero.h) */
    u8 pad17C[0x1B8 - 0x17C];
    s32 state_timer;               /* 0x1B8: frames since the state began */
    u8 pad1BC[0x1E4 - 0x1BC];
    s16 thruster_wait;             /* 0x1E4: non-zero keeps the thruster dash from starting */
    u8 pad1E6[0x298 - 0x1E6];
    f32 f298;                      /* 0x298 */
    u8 pad29C[0x2A0 - 0x29C];
    f32 f2A0;                      /* 0x2A0 */
    u8 f2A4;                       /* 0x2A4: flag for the thruster dash */
    u8 pad2A5[0x25C4 - 0x2A5];
    s32 state;                     /* 0x25C4 */
    u8 pad25C8[0x2838 - 0x25C8];
    f32 stick_mag;                 /* 0x2838 */
    u8 pad283C[0x2884 - 0x283C];
    s16 unk_2884;                  /* 0x2884: must be 0 for the back-item jumps */
} H_506E30;
typedef struct {
    u8 pad0[0x1A0];
    u32 held;                      /* 0x1A0 */
} P_506E30;
extern u8 D_001A4BE0[];
extern u8 *D_001D52FC;
extern u8 D_00142CA2[];
extern s32 func_L01_004FF5D8(void);
extern s32 func_003A3BB8(s32, s32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L01_00460778(s32, s32, s32, s32, s32);
extern s32 func_L01_004E9238(s32);
extern void func_L01_005003D0(s32, s32);

/* hero_crouch_jump: X from a crouch (or a jump's first frames) starts a jump; the back item says which */
s32 func_L01_00506E30(void) {
    s32 state;
    s32 window;
    u32 r1;
    s32 item;

    if (((H_506E30 *)D_001A4BE0)->state == 14) {
        return 0;
    }
    window = func_L01_004FF5D8();
    r1 = func_003A3BB8(8, 0);
    if (!((((P_506E30 *)D_001D52FC)->held & r1) != 0 && window > 0
          && func_L01_00460778(func_003A3BB8(64, 0), 0x1F000, window + 4, window, 0) != 0)) {
        goto rest;
    }
    state = 11;
change:
    func_L01_005003D0(state, 1);
    return 1;
rest:
    if (((H_506E30 *)D_001A4BE0)->state_timer < 6) {
        return 0;
    }
    if (func_L01_004606E8(func_003A3BB8(64, 0), 7, 0, 0) == 0) {
        return 0;
    }
    item = func_L01_004E9238(3);
    if (item == 2 && D_00142CA2[0] != 0 && ((H_506E30 *)D_001A4BE0)->unk_2884 == 0) {
        if ((2.5f < ((H_506E30 *)D_001A4BE0)->f298 || ((H_506E30 *)D_001A4BE0)->f2A0 < 0.78539819f)
            && 0.7f < ((H_506E30 *)D_001A4BE0)->stick_mag
            && 0.018000001f < ((H_506E30 *)D_001A4BE0)->ground_speed) {
            state = 10;
            goto change;
        }
    }
    item = func_L01_004E9238(3);
    if (item == 3 && ((H_506E30 *)D_001A4BE0)->unk_2884 == 0) {
        if (0.7f < ((H_506E30 *)D_001A4BE0)->stick_mag
            && (2.5f < ((H_506E30 *)D_001A4BE0)->f298 || ((H_506E30 *)D_001A4BE0)->f2A4 != 0)
            && 0.018000001f < ((H_506E30 *)D_001A4BE0)->ground_speed) {
            if (((H_506E30 *)D_001A4BE0)->thruster_wait != 0) {
                return 1;
            }
            state = 16;
            goto change;
        }
    }
    item = func_L01_004E9238(3);
    if (item == 3 && ((H_506E30 *)D_001A4BE0)->unk_2884 == 0) {
        state = 13;
        goto change;
    }
    item = func_L01_004E9238(3);
    if (item == 2 && ((H_506E30 *)D_001A4BE0)->unk_2884 == 0 && D_00142CA2[0] != 0) {
        state = 15;
        goto change;
    }
    func_L01_005003D0(7, 1);
    return 1;
}
