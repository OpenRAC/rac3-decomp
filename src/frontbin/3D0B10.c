#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D0B20(void);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003D0B10);

typedef int u128_3CB5B0 __attribute__((mode(TI)));
typedef struct { u8 p0[0x350]; f32 f350, f354, f358; s32 x35C; } L_3CB5B0;
typedef struct { u8 p0[0x10]; u128_3CB5B0 q10; } B_3CB5B0;
typedef struct { u8 p0[0x10]; s32 state; u8 p1[0xC]; u128_3CB5B0 q20; } E_3CB5B0;
extern s32 D_001D9310[2];
extern f32 D_00222418[];
extern u8 D_002FF200[];
extern B_3CB5B0 D_002FF600[];
extern E_3CB5B0 D_002FF700[];
extern void func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF00(void *, void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003D0B20);

/* localdecomp:start func_003D0CB8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3CB748;
typedef struct { s16 h0, h2, h4, h6, h8, hA; u32 w; u8 pad[0x20]; } S_3CB748;
extern u32 func_003DE880(u32, u32, s32, void *);
extern u32 func_003E10C0(u32, u32, s32, void *);
extern u32 func_003D0880(u32, u32, s32, void *);
void func_003D0CB8(void *arg) {
    s32 idx = (s32)arg;
    S_3CB748 *s = (S_3CB748 *)&D_002FF700[idx];
    u8 *b = (u8 *)&D_002FF600[idx];
    u8 *q = b + 0x10;
    u32 cur = s->w;
    u32 end = cur + 0x400;
    s32 x;
    V_3CB748 v = *(V_3CB748 *)(b + 0x10);
    if (cur < end) {
        s->h0 = 0;
        cur = func_003DE880(cur, end, idx, q);
        x = (s32)(cur - s->w) >> 1;
        s->h2 = x;
        if (cur < end) {
            s->h4 = x;
            cur = func_003E10C0(cur, end, idx, q);
            x = (s32)(cur - s->w) >> 1;
            s->h6 = x - (u16)s->h4;
            if (cur < end) {
                s->h8 = x;
                s->hA = ((s32)(func_003D0880(cur, end, idx, q) - s->w) >> 1) - (u16)s->h8;
            }
        }
    }
}
/* localdecomp:end func_003D0CB8 */

/* localdecomp:start func_003D0DD0 */
extern void func_003D0E00();
extern void func_003D0CB8(void *);
void func_003D0DD0(void *p) {
    func_003D0E00(p);
    func_003D0CB8(p);
}
/* localdecomp:end func_003D0DD0 */
