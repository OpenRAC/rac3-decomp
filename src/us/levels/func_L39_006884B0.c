#include "common.h"

/* NTSC-U counterpart of func_L39_0068B058 (src/levels/39_multiplayer_menu/L39_0068B058.c): 0.0779221 -> 0.0666667 */
/* localdecomp:start func_L39_006884B0 */
typedef struct S_0068B058_C S_0068B058_C;
typedef struct {
    char _p0[0x18];
    void (*f18)(S_0068B058_C *);
} S_0068B058_V;
struct S_0068B058_C {
    char _p0[0x60];
    S_0068B058_V *f60;
};
typedef struct {
    char _p0[0x10C];
    s32 f10C;
    S_0068B058_C *f110[1];
} S_0068B058_A;

__asm__(".extern D_001DC300_sda, 4");
__asm__(".extern D_001DC304_sda, 1");
__asm__(".extern D_001DC308_sda, 4");
extern s32 D_L39_002412A8;
extern s32 D_L39_00242A90;
extern s32 D_L39_003D2980[];
extern f32 D_001DC300_sda;
extern u8 D_001DC304_sda;
extern s32 D_001DC308_sda;
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_005130C8(s32, s32);

void func_L39_006884B0(S_0068B058_A *arg0) {
    s32 c;
    s32 *p;
    s32 i;

    if (D_L39_002412A8 == 12 && D_L39_00242A90 == -2) {
        if (D_001DC304_sda) {
            func_003C4138(&D_001DC300_sda, 0.0f, 0.0666666701f);
        } else {
            func_003C4138(&D_001DC300_sda, 1.0f, 0.0666666701f);
        }
        c = func_0038DBD8(D_001DC308_sda & 0xFFFFFF, D_001DC308_sda, D_001DC300_sda);
        p = D_L39_003D2980;
        func_L01_005130C8(p[4], c);
        func_L01_005130C8(p[5], c);
    }
    for (i = 0; i < arg0->f10C; i++) {
        arg0->f110[i]->f60->f18(arg0->f110[i]);
    }
}
/* localdecomp:end func_L39_006884B0 */
