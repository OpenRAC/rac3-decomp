/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Ordinary wrapper COMPILE ERROR: injected func_0038DFB8 declarations void(s32,s32,f32), s32(s32,s32,f32), s32(f32,s32,s32) conflict; requires context correction by Claude. Contract-only diagnostic 50 diff, NOT ordinary proof: .lit4 loads vs inline constants ...
 */
#include "common.h"
/* localdecomp:start func_003BFD40 */
typedef struct {
    u128_t start, end;
    f32 f20, f24, f28;
    s32 color0, color1;
    s32 min, max;
    s32 flag;
    s32 time0, time1, unused, kind;
} Particle_003BFD40;
void func_003BFD40(s32 owner, u128_t *start, u128_t *end) {
    extern void func_003A8708(s32, s32);
    extern s32 func_0038DFB8(s32, s32, f32);
    extern f32 func_00382918(void);
    extern void func_003BFC98(s32 a0, u8 *src);
    Particle_003BFD40 p;
    s32 time;
    f32 scale;
    func_003A8708(owner, 0x502020);
    p.color1 = p.color0 = func_0038DFB8(0x7F2F00, 0x800000, func_003828C0(0.0f, 1.0f));
    p.max = p.min = func_00382878(31, 63);
    scale = func_003828C0(0.1f, 0.8f);
    p.end = *end;
    p.f28 = scale;
    p.start = *start;
    p.f24 = func_00382918();
    p.f20 = func_003828C0(90.0f, 180.0f) * 0.017453292f * 0.0200000014f;
    time = (func_00382878(150, 180) * 5 + 2) / 6;
    p.kind = 5;
    p.flag = 1;
    p.time0 = p.time1 = time;
    func_003BFC98(owner, (u8 *)&p);
}
/* localdecomp:end func_003BFD40 */
