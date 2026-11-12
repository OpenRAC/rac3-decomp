/* near miss (level 3, Starship Phoenix): 183 differences, a first draft (needs a config/levels/divs_nops.txt row `func_L03_003998E8 2`): the three-slot list walk of func_L03_0032DF60 with a spawn body; retail spills five values (s+0x7C, s+0x64 twice, i+1, i*4) into a 0xA0 frame, this C spills four into 0x90, which shifts every register by one */
#include "common.h"

/* localdecomp:start func_L03_003998E8 */
#include "vu0.h"
typedef struct { u8 pad0[4]; s32 i4; u8 pad8[0x18 - 8]; s16 h18; u8 pad1A[3]; u8 b1D; } T_003998E8;
typedef struct { u8 pad0[0x64]; s32 idx[3]; f32 f70; u8 pad74[0x7C - 0x74]; u8 cnt[3]; } S_003998E8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_003998E8 *p68; u8 pad6C[0xF8 - 0x6C]; f32 fF8; } A_003998E8;
extern u16 *D_L03_0021C620[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s32 D_L03_001DF9D8;
extern T_003998E8 *func_L03_0032F6A8(void *);
extern void func_L03_0032F6F8(s32, void *);

void func_L03_003998E8(void *arg) {
    A_003998E8 *a = arg;
    S_003998E8 *s = a->p68;
    int i;
    int n = 0;
    int k = 1;
    f32 r = 0.0f;
    f32 step = 1.0f;
    f32 ang = r;
    for (i = 0; i < 3; i++) {
        u8 *c = &s->cnt[i];
        s16 *cur;
        if (*c == 0) continue;
        cur = (s16 *)D_L03_0021C620[s->idx[i]];
        while ((s->idx[i] & 0xFF) != 0xFF && D_L03_001DF9D8 >= s->idx[i] && cur != 0 &&
               (cur[-1] >= 0 || cur == (s16 *)D_L03_0021C620[s->idx[i]])) {
            u8 *e = D_L03_001DF99C + ((*(u16 *)cur & 0x7FFF) << 8);
            if (e == 0) break;
            if (e[0x20] == 1) {
                T_003998E8 *t = func_L03_0032F6A8(e);
                f32 off[4];
                t->h18 = func_00382498(-25, 25) + 100;
                t->b1D = i;
                e[0x23] = 0;
                qzero(off);
                if (r != 0.0f) {
                    off[0] = r * func_0038D0B0(ang);
                    off[1] = r * func_0038D098(ang);
                }
                vec_add_ab(e + 0x10, &a->pos, off);
                n++;
                func_L03_0032F6F8(t->i4, e);
                *(f32 *)(e + 0xF8) = a->fF8;
                if (n >= k) {
                    k += 3;
                    step = 1.0f / (f32)k;
                    n = 0;
                    r = r + 1.05f;
                } else {
                    ang = func_0038DAB8(ang, step * 6.2831855f);
                }
                (*c)--;
            }
            if (*c == 0) break;
            cur++;
        }
    }
    s->f70 = r + 0.6f;
    if (n == 0) s->f70 = s->f70 - 1.05f;
}
/* localdecomp:end func_L03_003998E8 */
