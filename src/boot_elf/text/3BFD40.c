#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef int u128_t __attribute__((mode(TI)));
/* --- end of declarations from other files --- */

/* declarations of 3BF968.c's earlier functions */
extern f32 func_003828C0(f32, f32);
extern s32 func_00382878(s32, s32);
extern void func_003BFC98(s32 a0, u8 *src);

/* localdecomp:start func_003BFD40 */
typedef struct {
    u128_t start, end;
    f32 f20, f24, f28;
    s32 color0, color1;
    s32 min, max;
    s32 flag;
    s32 time0, time1, owner, kind;
} Particle_003BFD40;
extern void func_003A8708(s32, s32);
extern s32 func_0038DFB8_003BFD40(s32, s32, f32);
extern f32 func_00382918(void);
extern void func_003BFC98(s32, u8 *);

void func_003BFD40(s32 owner, u128_t *start, u128_t *end) {
    Particle_003BFD40 p;
    s32 time;

    func_003A8708(owner, 0x502020);
    p.color1 = p.color0 = func_0038DFB8_003BFD40(0x7F2F00, 0x800000, func_003828C0(0.0f, 1.0f));
    p.max = p.min = func_00382878(31, 63);
    p.f28 = func_003828C0(0.1f, 0.8f);
    p.start = *start;
    p.end = *end;
    p.f24 = func_00382918();
    p.f20 = func_003828C0(90.0f, 180.0f) * 0.017453292f * 0.0200000014f;
    time = (func_00382878(150, 180) * 5 + 2) / 6;
    p.kind = 5;
    p.flag = 1;
    p.time0 = p.time1 = time;
    func_003BFC98(owner, (u8 *)&p);
}
/* localdecomp:end func_003BFD40 */
