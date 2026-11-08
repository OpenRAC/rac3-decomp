#include "common.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x178];
    /* 0x178 */ f32 speed_178;
    /* 0x17C */ u8 pad1[0x1E0 - 0x17C];
    /* 0x1E0 */ s16 flag_1e0;
    /* 0x1E2 */ u8 pad2[0x3EE - 0x1E2];
    /* 0x3EE */ u8 flag_3ee;
    /* 0x3EF */ u8 pad3[0x46C - 0x3EF];
    /* 0x46C */ u8 level_46c;
    /* 0x46D */ u8 pad4[0xC08 - 0x46D];
    /* 0xC08 */ s32 flags_c08;
    /* 0xC0C */ u8 pad5[0x1474 - 0xC0C];
    /* 0x1474 */ u8 flag_1474;
    /* 0x1475 */ u8 pad6[0x25C4 - 0x1475];
    /* 0x25C4 */ s32 mode;
    /* 0x25C8 */ s32 frame;
    /* 0x25CC */ u8 pad7[0x25EA - 0x25CC];
    /* 0x25EA */ u8 flag_25ea;
    /* 0x25EB */ u8 pad8[0x280C - 0x25EB];
    /* 0x280C */ s32 reset;
    /* 0x2810 */ u8 pad9[0x2838 - 0x2810];
    /* 0x2838 */ f32 timer;
} Game_00512970;

/* localdecomp:start func_L04_0050E6F0 */
extern Game_00512970 D_1A4BE0;
extern u8 D_1A4D40[];
extern s32 D_L04_001DBCF4;
extern u8 *D_001D52FC;

extern void func_L01_004EAA78(s32, f32);
extern s32 func_0039E928(s32, s32);
extern s32 func_L04_00508950(s32, s32);
extern void func_L01_0050BB98(s32, s32, f32);
extern void func_L01_0050BEE0(s32, s32);
extern s32 func_L04_004EBEA0(s32);
extern void func_003BF640(void *, f32);

void func_L04_0050E6F0(void) {
    D_1A4BE0.reset = 0;
    func_L01_004EAA78(0, 1.0f);
    if (*(s32 *)(D_001D52FC + 0x1A0) & func_0039E928(8, 0)) {
        func_L04_00508950(4, 0);
        func_L01_0050BB98(0xD, 2, -2.0f);
        func_L01_0050BEE0(3, 0x12);
        return;
    }
    if (0.3f < D_1A4BE0.timer && D_1A4BE0.flag_1e0 == 0) {
        if (D_1A4BE0.flag_1474 != 0 || D_1A4BE0.flag_25ea != 0) {
            func_L04_00508950(2, 1);
        } else {
            s32 amount;
            if (!func_L04_00508950(2, 0)) return;
            D_1A4BE0.frame = 1;
            amount = 8;
            if (D_1A4BE0.level_46c > 5) amount = 14;
            func_L01_0050BB98(4, D_L04_001DBCF4, (f32)amount);
            D_1A4BE0.flag_3ee = 1;
        }
        return;
    }
    if ((0.050000004f < D_1A4BE0.speed_178 && D_1A4BE0.level_46c > 3) || D_1A4BE0.mode == 0x10) {
        if (func_L04_00508950(3, 0)) {
            func_L01_0050BB98(5, 0, -1.0f);
            func_003BF640(D_1A4D40, 0.0833333358f);
        }
        return;
    }
    if (D_1A4BE0.level_46c < 13 && (D_1A4BE0.flags_c08 & 2) == 0) return;
    if (!func_L04_00508950(0, 0)) return;
    if (func_L04_004EBEA0(0) == 0x4A) {
        func_L01_0050BB98(func_L04_004EBEA0(0), 0, 15.0f);
    } else if (D_1A4BE0.flags_c08 & 2) {
        func_L01_0050BB98(func_L04_004EBEA0(0), 0, -2.0f);
    }
}
/* localdecomp:end func_L04_0050E6F0 */
