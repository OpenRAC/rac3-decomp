/* near miss (open-rac-engine names it hud_bolts_draw): 22 words differ, all before the loop: retail
 * re-materialises &D_L01_001E0370 (lui/addiu) for strlen and sets the tally buffer pointer and i = 0
 * before the first sprintf; ours keeps the buffer address in $s0 across the call. The loop, the
 * doubler (x%d) and the hiding paths match. */
#include "common.h"

typedef struct {
    s32 amount;      /* 0x0: the +N/-N tally */
    u8 pad4[0xE - 0x4];
    s16 shown;       /* 0xE */
} Tally_00479390;
extern s32 D_L01_001D8050;
extern s32 D_L01_001D805C;
extern char D_L01_001E0370[];
extern char D_L01_001E0388[][24];
extern char D_L01_001E03B8[];
extern Tally_00479390 D_L01_001E03C0[];
extern char D_L01_001D8078[];
extern char D_L01_001D8080[];
extern char D_L01_001D8088[];
extern u8 D_00142660[];
extern u8 D_001A4BE0[];
extern void func_L01_00479738(void);
extern void func_L01_00479AB0(void);
extern void func_L01_004792F8(void);
extern s32 func_L01_004792E0(s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_0011B868(char *);

/* hud_bolts_draw: draws the bolt HUD with the doubler's x2: (challenge multiplier + 1)
   << bolt_multiplier_exp, shown while 2 or more. */
void func_L01_00479390(void) {
    s32 i;
    s32 multiplier;
    u8 *game;
    u8 *hero;

    func_L01_00479738();
    if (D_L01_001D8050 != 0) {
        D_L01_001D8050--;
        func_0011B2E8(D_L01_001E0370, D_L01_001D8078, *(s32 *)D_L01_001D8054);
        D_L01_001D805C = func_0011B868(D_L01_001E0370);
        /* the two tallies */
        for (i = 0; i < 2; i++) {
            if (D_L01_001E03C0[i].shown != 0) {
                func_L01_00516AA0(func_L01_004792E0(i), 1, 1);
                if (D_L01_001E03C0[i].amount > 0) {
                    func_0011B2E8(D_L01_001E0388[i], D_L01_001D8080, D_L01_001E03C0[i].amount);
                } else {
                    func_0011B2E8(D_L01_001E0388[i], D_L01_001D8078, D_L01_001E03C0[i].amount);
                }
            } else {
                func_L01_00516AA0(func_L01_004792E0(i), 1, 0);
            }
        }
        game = D_00142660;
        hero = D_001A4BE0;
        multiplier = (game[0x5A] + 1) << hero[0x28C8]; /* bolt_mult_exp */
        if (multiplier < 2) {
            func_L01_00516AA0(0x10007, 1, 0);
        } else {
            func_L01_00479AB0();
            func_L01_00516AA0(0x10007, 1, 1);
        }
        func_0011B2E8(D_L01_001E03B8, D_L01_001D8088, multiplier);
    } else {
        func_L01_00516AA0(0x10000, 1, 0);
    }
    func_L01_004792F8();
}
