/* functional: medium. Re-read block by block against the level-01 assembly (offsets, constants, callee order, timer/filter/table logic). The two $gp-relative level globals are level names (D_L01_001DF268, D_L01_001E0058, read through $gp as the shared matched code reads D_L01_001E0058): the earlier D_001DF268_sda/D_001E0058_sda names are a fixed $gp offset, the right slot only in level 01; levels 09/12/20/26/29 keep them at other offsets (09: gp+0x2860, not 0x29B8). Vector ops are plain C with each w lane from retail's destination register. Retail's second timer branch passes sp+0x40 (current) to func_L01_0040E570 before anything in this call has written it (stale stack); the C passes its own uninitialised local there, so that branch's distance test can differ when no earlier object of the same call set it. */
#include "common.h"
/* localdecomp:start func_L01_003D1210 */
#include "vu0.h"
typedef struct { float x, y, z, w; } plain_v4;
static void plain_add(void *d, void *a, void *b) {
    plain_v4 *pd = d, *pa = a, *pb = b;
    pd->x = pa->x + pb->x; pd->y = pa->y + pb->y; pd->z = pa->z + pb->z; pd->w = pa->w;
}
static void plain_sub(void *d, void *a, void *b) {
    plain_v4 *pd = d, *pa = a, *pb = b;
    pd->x = pa->x - pb->x; pd->y = pa->y - pb->y; pd->z = pa->z - pb->z; pd->w = pa->w;
}
extern u8 D_001A4C60[];
extern f32 D_L01_001DF268;
__asm__(".extern D_L01_001DF268, 4");
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C __attribute__((section(".data")));
extern s32 D_L01_001DFB40 __attribute__((section(".data")));
typedef struct {
    u8 pad0[8];
    void (*set)(u8 *, void *);
    void (*get)(u8 *, void *);
} Table_003D1210;
typedef struct { u8 pad0[8]; s32 (*test)(u8 *); } Filter_003D1210;
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E0058;
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
    f32 distance;
    f32 strength;
    f32 angle;
    f32 step;
    Table_003D1210 *table;
    Filter_003D1210 *filter;
    u16 *p;
    u8 *m;
    s32 index;
    s32 *timer;
    u8 *timerbase;
    s32 timer_offset;
    s32 list_id;
    plain_sub(&delta, D_001A4C60, &state->position);
    delta.z = 0;
    {
        f32 dist = func_0038CEA8(&delta);
        f32 radius = state->radius;
        if (dist > radius) {
            dist -= radius;
            func_0038CF68(&correction, &delta, dist);
            plain_sub(D_001A4C60 + 0x80, D_001A4C60 + 0x80, &correction);
        } else if (dist > radius * D_L01_001DF268) {
            f32 falloff;
            dist -= radius * D_L01_001DF268;
            falloff = dist / (radius * (1.0f - D_L01_001DF268));
            dist = dist * falloff * falloff;
            func_0038CF68(&correction, &delta, dist);
            plain_sub(D_001A4C60 + 0x80, D_001A4C60 + 0x80, &correction);
        }
    }
    plain_sub(&delta, &state->position, &state->previous);
    delta.z = 0;
    plain_add(D_001A4C60 + 0x80, D_001A4C60 + 0x80, &delta);
    {
        f32 radius = state->radius;
        f32 ratio = radius / radius;
        state->old_radius = radius;
        *(u128_t *)&state->previous = *(u128_t *)&state->position;
        plain_sub(&delta, &state->position, D_001A4C60);
        func_0038CE20((f32 *)&delta, (f32 *)&delta, 1.0f - ratio);
    }
    plain_sub(D_001A4C60 + 0x80, D_001A4C60 + 0x80, &delta);
    if (state->group == -1) return;
    table = func_L01_0043B568(0x1B78, 0, 16);
    func_0038CE20((f32 *)&forward, (f32 *)(object + 0xC0), 4.0f);
    plain_add(&forward, &forward, D_001A4C60);
    { f32 blend = state->blend;
    if (blend < 0.45f) {
        *(u128_t *)&base = *(u128_t *)&forward;
    } else if (blend < 0.95f) {
        func_0038CDF8(&base, &forward, &state->position, (blend - 0.45f) * 2.0f);
    } else {
        *(u128_t *)&base = *(u128_t *)&state->position;
    }
    }
    list_id = state->group;
    p = D_L01_0021DE20[list_id];
    index = 0;
    goto condition;
repeat:
        m = (u8 *)(((*p & 0x7FFF) << 8) + (s32)D_L01_001E001C);
        if (m == 0) return;
        if (m[0x20] == 254) goto next;
        if (m[0x20] == 253) goto next;
        if (state->filter != -1) {
            filter = func_L01_0043B568(*(s16 *)(m + 0xAA), 1, 28);
            if (filter == 0 || filter->test(m) != 0) goto advance;
        }
        timerbase = (u8 *)state->timers;
        timer_offset = index << 2;
        timer = (s32 *)(timerbase + timer_offset);
        if (*timer == 0) {
            *(u128_t *)&output = *(u128_t *)&base;
            *timer = D_L01_001DFB40 + func_00382498(12, 25);
        } else if (state->blend > 0.99f) {
            *(u128_t *)&output = *(u128_t *)&base;
        } else if (*timer < D_L01_001DFB40) {
            table->get(m, &current);
            if (state->blend > 0.95f)
                strength = 1.0f - (state->blend - 0.95f) / 0.05f;
            else strength = 1.0f;
            plain_sub(&jitter, &base, &current);
            func_0038CE20((f32 *)&jitter, (f32 *)&jitter, 1.0f + func_003824E0(-0.2f, 0.3f) * strength);
            plain_add(&output, &current, &jitter);
            strength *= func_003824E0(0.25f, 2.0f);
            angle = func_00382538();
            jitter.x = func_0038D098(angle) * strength;
            jitter.y = func_0038D0B0(angle) * strength;
            jitter.z = 0.0f;
            plain_add(&output, &output, &jitter);
            output.z = base.z;
            *(s32 *)(timerbase + timer_offset) = D_L01_001DFB40 + func_00382498(37, 100);
        } else if (*timer - 80 < D_L01_001DFB40 && func_L01_0040E570(&current, &base) > 64.0f) {
            table->get(m, &current);
            if (state->blend > 0.95f)
                strength = 1.0f - (state->blend - 0.95f) / 0.05f;
            else strength = 1.0f;
            plain_sub(&jitter, &base, &current);
            func_0038CE20((f32 *)&jitter, (f32 *)&jitter, 1.0f + func_003824E0(0.1f, 0.4f) * strength);
            plain_add(&output, &current, &jitter);
            strength *= func_003824E0(0.5f, 2.5f);
            angle = func_00382538();
            jitter.x = func_0038D098(angle) * strength;
            jitter.y = func_0038D0B0(angle) * strength;
            jitter.z = 0.0f;
            plain_add(&output, &output, &jitter);
            output.z = base.z;
            *(s32 *)(timerbase + timer_offset) = D_L01_001DFB40 + func_00382498(67, 133);
        } else goto next;
        goto apply;
next:
        index++;
        goto advance;
apply:
        table->set(m, &output);
        index++;
advance:
        list_id = state->group;
        p++;
condition:
    if ((u8)list_id != 255 && list_id <= D_L01_001E0058 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L01_0021DE20[list_id])) goto repeat;
}
/* localdecomp:end func_L01_003D1210 */
