#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L16_003CC0A8 */
typedef struct V_003CC0A8 {
    u8 pad00[0x1F0];
    s32 a1F0[3];
    s32 a1FC[4];
    u8 pad20C[0x214 - 0x20C];
    s16 h214;
    s16 h216;
    u8 pad218[0x228 - 0x218];
    s32 w228;
    u8 *w22C;
    u8 x230[0x10];
} V_003CC0A8;

extern void func_003C5060(void *, void *, void *, s32);
extern u8 *D_L16_001E015C;
__asm__(".extern D_L16_001E015C, 16");
extern s32 D_L16_001DFC40;
extern u8 D_001A4C60[];

void func_L16_003CC0A8(u8 *self) {
    V_003CC0A8 *s = *(V_003CC0A8 **)(self + 0x68);
    vu0_v4 tmp;
    u8 *obj;

    if (s->h214 != 0) {
        obj = D_L16_001E015C + (s->a1FC[s->h216] << 8);
    } else {
        obj = D_L16_001E015C + (s->a1F0[s->h216] << 8);
    }
    s->w22C = obj;
    vec_sub_ba(&tmp, D_001A4C60, obj + 0x10);
    tmp.z = 1.618f;
    func_003C5060(s->w22C, s->x230, &tmp, 0);
    s->w228 = D_L16_001DFC40;
}
/* localdecomp:end func_L16_003CC0A8 */

/* localdecomp:start func_L16_003CC150 */
extern void func_0038D000(float *, float *, float *);

void func_L16_003CC150(void *arg0, void *arg1) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_0038D000(arg1, (float *)((u8 *)temp_s0 + 0x230),
                  (float *)((u8 *)*(void **)((u8 *)temp_s0 + 0x22C) + 0xC0));
    vec_add_ab(arg1, arg1, (u8 *)*(void **)((u8 *)temp_s0 + 0x22C) + 0x10);
}
/* localdecomp:end func_L16_003CC150 */

INCLUDE_ASM("asm/levels", func_L16_003CC1A8);
