/* near miss (level 3, Starship Phoenix): 69 differences with -mvu0-use-vf0-vf2 and @ps2as, all in the final four-iteration loop: retail does not hoist the 0xFF of 0xFF - c (it stays a li inside the conditional block) and evaluates the colour byte right after the fabs call, the C hoists 0xFF into a saved register ($s5, retail has 0xD4 there) and schedules the float argument first, so the loop's registers are one off. The 0.02f scale written at each use (not as a local) gave retail's $f0 plus mov.s $f20 copy (90 -> 69). Tried: a u8 callee parameter instead of c & 0xFF, u8 c, 255 - c, the colour computed before the r call (171). Same family as func_L03_003C1528 and the other 0x2CC functions of level 3. */
#include "common.h"
#include "vu0.h"
extern f32 D_001DEC24_sda;
__asm__(".extern D_001DEC24_sda, 4");
extern f32 D_001DEC28_sda;
__asm__(".extern D_001DEC28_sda, 4");
extern f32 D_001DEC2C_sda;
__asm__(".extern D_001DEC2C_sda, 4");
extern f32 D_001DEC30_sda;
__asm__(".extern D_001DEC30_sda, 4");
extern s32 D_001DEC34_sda;
__asm__(".extern D_001DEC34_sda, 4");
extern s32 D_001DEC38_sda;
__asm__(".extern D_001DEC38_sda, 4");
extern s32 D_001DEC3C_sda;
__asm__(".extern D_001DEC3C_sda, 4");
extern f32 D_001DEC40_sda;
__asm__(".extern D_001DEC40_sda, 4");
extern f32 D_001DEC44_sda;
__asm__(".extern D_001DEC44_sda, 4");
extern s32 D_001DEC48_sda;
__asm__(".extern D_001DEC48_sda, 4");
extern s32 D_001DEC4C_sda;
__asm__(".extern D_001DEC4C_sda, 4");
extern f32 D_001DEC50_sda;
__asm__(".extern D_001DEC50_sda, 4");
extern f32 D_001DEC54_sda;
__asm__(".extern D_001DEC54_sda, 4");
extern s32 D_001DEC58_sda;
__asm__(".extern D_001DEC58_sda, 4");
extern s32 D_001DEC5C_sda;
__asm__(".extern D_001DEC5C_sda, 4");
extern s32 D_001DEC60_sda;
__asm__(".extern D_001DEC60_sda, 4");
extern s32 D_001DF4C0;
extern u8 D_001E2440[];
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382468(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);
void func_L03_003C0608(u8 *a0) {
    f32 v[4];
    f32 pos[4];
    f32 t[4];
    f32 w[4];
    f32 x[4];
    s32 i;
    s32 n;
    s32 c;
    s32 r;
    func_0038D000(v, &D_001DEC60_sda, a0 + 0xC0);
    vec_add_ab(v, v, a0 + 0x10);
    if (func_00382468(4) == 0) {
        func_L01_00443B88(pos, D_001DEC24_sda * 0.020000001f, D_001DEC28_sda * 0.020000001f);
        func_L01_0046C470(v, pos, D_001DEC38_sda, D_001DEC40_sda, D_001DEC34_sda, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        for (n = 2; n >= 0; n--) {
            func_L01_00443B88(t, D_001DEC2C_sda * 0.020000001f, D_001DEC30_sda * 0.020000001f);
            vec_add_ab(pos, pos, t);
            func_L01_0046C470(v, pos, D_001DEC3C_sda, D_001DEC44_sda, D_001DEC34_sda, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
    vec_sub_ba(w, D_001E2440, v);
    func_0038CF68(w, w, -0.3f);
    func_0038CF68(x, w, 0.1f);
    vec_add_ab(w, w, v);
    for (i = 0; i < 4; i++) {
        r = (D_001DF4C0 + i * 20) & 0xFF;
        r = func_0038DBD8(D_001DEC48_sda, D_001DEC4C_sda, fabs_asm(0.5f - (f32)(212 - (r * 5 + 2) / 6) / 212.0f));
        c = (u8)D_001DF4C0;
        if (i & 2) c = c << 1;
        if (i & 1) c = 0xFF - c;
        func_L01_0046C2E8(w, r, c & 0xFF, D_001DEC5C_sda, D_001DEC58_sda, 2, 0, 0,
                          (D_001DEC50_sda + (f32)i * D_001DEC54_sda) * (*(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24)));
        vec_add_ba(w, w, x);
    }
}
