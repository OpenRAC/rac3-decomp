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

/* localdecomp:start func_L04_00512970 */
extern Game_00512970 D_1A4BE0;
extern u8 D_1A4D40[];
extern s32 D_L04_001DBCB4;
extern u8 *D_001D52FC;

extern void func_L01_004EE850(s32, f32);
extern s32 func_003A3BB8(s32, s32);
extern s32 func_L04_0050CB28(s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L01_0050FE88(s32, s32);
extern s32 func_L04_004EFEC0(s32);
extern void func_003C4BB0(void *, f32);

void func_L04_00512970(void) {
    D_1A4BE0.reset = 0;
    func_L01_004EE850(0, 1.0f);
    if (*(s32 *)(D_001D52FC + 0x1A0) & func_003A3BB8(8, 0)) {
        func_L04_0050CB28(4, 0);
        func_L01_0050FB40(0xD, 2, -2.0f);
        func_L01_0050FE88(3, 0x12);
        return;
    }
    if (0.3f < D_1A4BE0.timer && D_1A4BE0.flag_1e0 == 0) {
        if (D_1A4BE0.flag_1474 != 0 || D_1A4BE0.flag_25ea != 0) {
            func_L04_0050CB28(2, 1);
        } else {
            s32 amount;
            if (!func_L04_0050CB28(2, 0)) return;
            D_1A4BE0.frame = 1;
            amount = 7;
            if (D_1A4BE0.level_46c > 4) amount = 12;
            func_L01_0050FB40(4, D_L04_001DBCB4, (f32)amount);
            D_1A4BE0.flag_3ee = 1;
        }
        return;
    }
    if ((0.060000002f < D_1A4BE0.speed_178 && D_1A4BE0.level_46c > 2) || D_1A4BE0.mode == 0x10) {
        if (func_L04_0050CB28(3, 0)) {
            func_L01_0050FB40(5, 0, -1.0f);
            func_003C4BB0(D_1A4D40, 0.10000001f);
        }
        return;
    }
    if (D_1A4BE0.level_46c < 11 && (D_1A4BE0.flags_c08 & 2) == 0) return;
    if (!func_L04_0050CB28(0, 0)) return;
    if (func_L04_004EFEC0(0) == 0x4A) {
        func_L01_0050FB40(func_L04_004EFEC0(0), 0, 12.0f);
    } else if (D_1A4BE0.flags_c08 & 2) {
        func_L01_0050FB40(func_L04_004EFEC0(0), 0, -2.0f);
    }
}
/* localdecomp:end func_L04_00512970 */
