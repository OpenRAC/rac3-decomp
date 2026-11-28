/* func_L01_003D1210 (Claude wave 14 r61, 2026-11-28). Replaces the earlier draft of this function (Codex wave 10 near miss). */
/* func_L01_003D1210 (PAL, levels), near miss (wave 14 r61): 227 differences with divs 0,2,1,1 injected (retail's nops
   before its four div.s; the Codex wave 10 draft gives 289 under the same check, 334 without the divs row).
   Changed against that draft: the duplicate declarations and unused locals dropped, the jitter as
   vec_sub_ba(&jitter, &base, &current) (retail loads current first), the two class tests as separate ifs (an ||
   is folded into a range test), the timers as state->timers[index], the loop written as one goto-built loop
   (retail's loop is entered at its bottom test and gets no invariant motion or strength reduction; a for loop
   gets both and a duplicated top test: 379).
   Left: the saved-register choice is a permutation of retail's (state in $s1 instead of $s2, object and index in
   $s5 instead of $s4, table in $s4 instead of $s7, and retail keeps the high half of D_L01_0021DE20 in $fp where
   ours keeps D_L01_001DFB40's); retail's loop top is 8-aligned (a real loop note), which this goto loop does not
   give; block 1's vsub gets vf1/vf2 swapped. NEEDS divs row 'func_L01_003D1210 0 2 1 1'. */
#include "common.h"

/* localdecomp:start func_L01_003D1210 */
#include "vu0.h"
extern u8 D_001A4C60[];
__asm__(".extern D_001DF268_sda, 4");
__asm__(".extern D_001E0058_sda, 4");
extern f32 D_001DF268_sda;
extern s32 D_001E0058_sda;
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C __attribute__((section(".data")));
extern s32 D_L01_001DFB40 __attribute__((section(".data")));
typedef struct {
    u8 pad0[8];
    void (*set)(u8 *, void *);
    void (*get)(u8 *, void *);
} Table_003D1210;
typedef struct { u8 pad0[8]; s32 (*test)(u8 *); } Filter_003D1210;
typedef struct { u8 pad0[0x2C]; s32 group; f32 blend; u8 pad34[12]; s32 filter; u8 pad44[16]; f32 radius; u8 pad58[0x64]; s32 timers[30]; f32 old_radius; u8 pad138[8]; vu0_v4 position, previous; } State_003D1210;
void func_L01_003D1210(u8 *object, State_003D1210 *state) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(vu0_v4 *, vu0_v4 *, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern void *func_L01_0043B568(s32, s32, s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_L01_0040E570(void *, void *);
    vu0_v4 delta, correction, forward, base, current, output, jitter;
    f32 strength;
    f32 angle;
    Table_003D1210 *table;
    Filter_003D1210 *filter;
    u16 *p;
    u8 *m;
    s32 index;
    s32 group;
    vec_sub_ab(&delta, D_001A4C60, &state->position);
    delta.z = 0;
    {
        f32 dist = func_0038CEA8(&delta);
        f32 radius = state->radius;
        if (dist > radius) {
            dist -= radius;
            func_0038CF68(&correction, &delta, dist);
            vec_sub_ab(D_001A4C60 + 0x80, D_001A4C60 + 0x80, &correction);
        } else if (dist > radius * D_001DF268_sda) {
            f32 falloff;
            dist -= radius * D_001DF268_sda;
            falloff = dist / (radius * (1.0f - D_001DF268_sda));
            dist = dist * falloff * falloff;
            func_0038CF68(&correction, &delta, dist);
            vec_sub_ab(D_001A4C60 + 0x80, D_001A4C60 + 0x80, &correction);
        }
    }
    vec_sub_ba(&delta, &state->position, &state->previous);
    delta.z = 0;
    vec_add_ab(D_001A4C60 + 0x80, D_001A4C60 + 0x80, &delta);
    {
        f32 radius = state->radius;
        f32 ratio = radius / radius;
        state->old_radius = radius;
        *(u128_t *)&state->previous = *(u128_t *)&state->position;
        vec_sub_ba(&delta, &state->position, D_001A4C60);
        func_0038CE20((f32 *)&delta, (f32 *)&delta, 1.0f - ratio);
    }
    vec_sub_ab(D_001A4C60 + 0x80, D_001A4C60 + 0x80, &delta);
    if (state->group == -1) return;
    table = func_L01_0043B568(0x1B78, 0, 16);
    func_0038CE20((f32 *)&forward, (f32 *)(object + 0xC0), 4.0f);
    vec_add_ba(&forward, &forward, D_001A4C60);
    {
        f32 blend = state->blend;
        if (blend < 0.45f) {
            *(u128_t *)&base = *(u128_t *)&forward;
        } else if (blend < 0.95f) {
            func_0038CDF8(&base, &forward, &state->position, (blend - 0.45f) * 2.0f);
        } else {
            *(u128_t *)&base = *(u128_t *)&state->position;
        }
    }
    group = state->group;
    p = D_L01_0021DE20[group];
    index = 0;
    goto test;
top:
    m = (u8 *)(((*p & 0x7FFF) << 8) + (s32)D_L01_001E001C);
    if (m == 0) return;
    if (m[0x20] == 0xFE) goto skip;
    if (m[0x20] == 0xFD) goto skip;
    if (state->filter != -1) {
        filter = func_L01_0043B568(*(s16 *)(m + 0xAA), 1, 0x1C);
        if (filter == 0 || filter->test(m) != 0) goto next;
    }
    if (state->timers[index] == 0) {
        *(u128_t *)&output = *(u128_t *)&base;
        state->timers[index] = D_L01_001DFB40 + func_00382498(12, 25);
    } else if (state->blend > 0.99f) {
        *(u128_t *)&output = *(u128_t *)&base;
    } else if (state->timers[index] < D_L01_001DFB40) {
        table->get(m, &current);
        if (state->blend > 0.95f)
            strength = 1.0f - (state->blend - 0.95f) / 0.05f;
        else
            strength = 1.0f;
        vec_sub_ba(&jitter, &base, &current);
        func_0038CE20((f32 *)&jitter, (f32 *)&jitter, 1.0f + func_003824E0(-0.2f, 0.3f) * strength);
        vec_add_ba(&output, &current, &jitter);
        strength *= func_003824E0(0.25f, 2.0f);
        angle = func_00382538();
        jitter.x = func_0038D098(angle) * strength;
        jitter.y = func_0038D0B0(angle) * strength;
        jitter.z = 0.0f;
        vec_add_ab(&output, &output, &jitter);
        output.z = base.z;
        state->timers[index] = D_L01_001DFB40 + func_00382498(37, 100);
    } else if (state->timers[index] - 80 < D_L01_001DFB40 && func_L01_0040E570(&current, &base) > 64.0f) {
        table->get(m, &current);
        if (state->blend > 0.95f)
            strength = 1.0f - (state->blend - 0.95f) / 0.05f;
        else
            strength = 1.0f;
        vec_sub_ba(&jitter, &base, &current);
        func_0038CE20((f32 *)&jitter, (f32 *)&jitter, 1.0f + func_003824E0(0.1f, 0.4f) * strength);
        vec_add_ba(&output, &current, &jitter);
        strength *= func_003824E0(0.5f, 2.5f);
        angle = func_00382538();
        jitter.x = func_0038D098(angle) * strength;
        jitter.y = func_0038D0B0(angle) * strength;
        jitter.z = 0.0f;
        vec_add_ab(&output, &output, &jitter);
        output.z = base.z;
        state->timers[index] = D_L01_001DFB40 + func_00382498(67, 133);
    } else
        goto skip;
    table->set(m, &output);
    index++;
    goto next;
skip:
    index++;
next:
    group = state->group;
    p++;
test:
    if ((u8)group != 0xFF && group <= D_001E0058_sda && p != 0 && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[group]))
        goto top;
}
/* localdecomp:end func_L01_003D1210 */
