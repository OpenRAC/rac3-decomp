/* PAL near miss (Codex wave 8: 296 words; round 30 W4: 53 aligned diff lines with --no-context at level 01, the file's own flags; 352 words vs retail's 356; frame 0x140 right).
 * Rewritten from the matched func_L39_0055A880 (same skeleton: the hit table E (selectors, colours, rate, vertices, indices, uvs, count, scroll), `time += dt * rate`,
 * packet with 4 vertices/colours/uvs, per-quad func_003D2DA0): an index-based `for (i...) for (j < 4)` loop with the packet struct `s` (the pointer-walking do-while of the
 * old draft gave 168 aligned and frame 0x150) and the texture-select chain with gotos of the old draft (kind == 1 / 2 / 3 / 4 / 5 / 6 / 7 as separate compares: the
 * `||` and range forms became `sltiu`), `D_001A4BE0.moby` re-read at every use (no hero local: 109 -> 63), goto chain (63 -> 53).
 * Left (53): the registers of the early locals (retail: texture $a2, group $a3, the two address his in $t0/$a3; mine a3/t0/a2) and the spill-slot order: retail keeps the four
 * selectors at sp+0x90..0x9c and the tint at 0xa0, next/color/u/v bases at 0xa4..0xb0; mine the tint at 0x90 and the selectors after. Putting `sel[4]` and `tint` into the
 * packet struct fixes the slots (tint 0xa0) but moves registers (86). Retail loads the selectors with `lh/sw` after the p70 == 1.0f test; mine before it.
 */
#include "common.h"
typedef int s128 __attribute__((mode(TI)));
/* localdecomp:start func_L01_00337880 */
typedef struct {
    u8 pad0[0x234]; s32 flag234; u8 pad238[0x25C0 - 0x238]; u8 *moby;
} Hero_00337880;
typedef struct {
    s16 selectors[4];
    u32 colors[4][4];
    f32 rate;
    s128 *vertices;
    s16 (*indices)[8];
    f32 (*uv)[2];
    s16 count;
    u8 pad5A[2];
    f32 uv_rate;
} Row_00337880;
typedef struct { u8 bytes[0xF0]; } Equip_00337880;
extern Hero_00337880 D_001A4BE0_00337880;
extern u8 D_001425C0[];
extern Equip_00337880 D_L01_002C5600[];
extern Row_00337880 D_L01_002B13E8[];
__asm__(".extern D_001DCF94_sda, 4");
extern s32 D_001DCF94_sda;
__asm__(".extern D_001DCF98_sda, 4");
extern s32 D_001DCF98_sda;
__asm__(".extern D_001DCF9C_sda, 4");
extern s32 D_001DCF9C_sda;
__asm__(".extern D_001DCF90_sda, 4");
extern f32 D_001DCF90_sda;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E1890;
typedef struct {
    s128 pos[4];
    u32 colors[4];
    f32 uv[4][2];
    unsigned long w70, w78, w80, w88;
} Packet_00337880;
void func_L01_00337880(u8 *m) {
    extern unsigned long func_00389598(s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003D2DA0(void *, void *, s32);
    Packet_00337880 s;
    u8 *p;
    Row_00337880 *r;
    s32 texture, blend, tint, state, kind, group;
    s32 s0, s1, s2, s3;
    s32 now, dt, i, j, vi, k2;
    f32 alpha_scale, scale, time;
    f32 *uv;
    f32 k, off;

    p = *(u8 **)(m + 0x68);
    if (p == 0) return;
    if (*(f32 *)(p + 0x70) == 0.0f) return;
    if (*(f32 *)(p + 0x70) == 1.0f) {
        if (D_001A4BE0_00337880.moby[0x42] != D_001A4BE0_00337880.moby[0x43] || D_001A4BE0_00337880.moby[0x42] == 0xFF) {
            *(f32 *)(p + 0x70) = 0.0f;
            return;
        }
    }
    texture = D_001DCF94_sda;
    tint = D_001DCF9C_sda;
    kind = D_L01_002C5600[D_001425C0[9]].bytes[1];
    if (kind == 1) texture = 0x31;
    else if (kind == 2) goto texture39;
    else if (kind == 3) { texture39: texture = 0x39; }
    else if (kind == 4) goto texture41;
    else if (kind == 5) goto texture41;
    else if (kind == 6) { texture41: texture = 0x41; }
    else if (kind == 7 || D_001A4BE0_00337880.flag234 != 0) texture = 0x38;
    blend = D_001DCF98_sda;
    scale = 1.0f;
    alpha_scale = 1.0f;
    state = D_001A4BE0_00337880.moby[0x42];
    if ((u32)(state - 0x17) >= 3 && state != 0x28) {
        state = *(s16 *)(p + 0x78);
    }
    if (state == 0x17) {
        *(s16 *)(p + 0x78) = state;
        group = 0;
    } else if (state == 0x18) {
        *(s16 *)(p + 0x78) = state;
        group = 1;
    } else if (state == 0x19) {
        *(s16 *)(p + 0x78) = state;
        group = 2;
    } else {
        *(s16 *)(p + 0x78) = 0x28;
        group = 3;
        if (D_L01_002C5600[D_001425C0[9]].bytes[1] < 7 && D_001A4BE0_00337880.flag234 == 0) {
            texture = 0xC;
        } else {
            texture = 0xA;
        }
        alpha_scale = 0.7f;
        scale = 1.25f;
        tint = 0x408080;
        blend = 2;
    }
    r = &D_L01_002B13E8[group];
    s0 = r->selectors[0];
    s1 = r->selectors[1];
    s2 = r->selectors[2];
    s3 = r->selectors[3];
    if (*(f32 *)(p + 0x70) == 1.0f) {
        *(s128 *)(p + 0x00) = *(s128 *)(D_001A4BE0_00337880.moby + 0xC0);
        *(s128 *)(p + 0x10) = *(s128 *)(D_001A4BE0_00337880.moby + 0xD0);
        *(s128 *)(p + 0x20) = *(s128 *)(D_001A4BE0_00337880.moby + 0xE0);
        D_L01_001E1890 = D_L01_001DFB40;
    }
    now = D_L01_001DFB40;
    dt = now - D_L01_001E1890;
    if (dt <= 0) dt = 1;
    time = *(f32 *)(p + 0x70) + (f32)dt * r->rate;
    *(f32 *)(p + 0x70) = time;
    D_L01_001E1890 = now;
    if ((f32)(r->count * 2) <= time) {
        state = D_001A4BE0_00337880.moby[0x42];
        if ((u32)(state - 0x17) >= 3 && state != 0x28) {
            *(f32 *)(p + 0x70) = 0.0f;
        }
        return;
    }
    s.w78 = func_00389598(texture);
    s.w80 = 0xFF9000000260L;
    s.w70 = 5;
    s.w88 = ((long)blend << 2) | 0x8000000040L;
    *(s128 *)(p + 0x30) = *(s128 *)(D_001A4BE0_00337880.moby + 0x10);
    for (i = 0; i < r->count; i++) {
        for (j = 0; j < 4; j++) {
            vi = (*r->indices)[0];
            vi = ((s16 (*)[4][2])r->indices)[i][j][0];
            if (i == s0) {
                s.colors[j] = r->colors[0][j];
            } else if (i == s1) {
                s.colors[j] = r->colors[1][j];
            } else if (i == s2) {
                s.colors[j] = r->colors[2][j];
            } else if (i == s3) {
                s.colors[j] = r->colors[3][j];
            } else {
                s.colors[j] = 0x50808080;
            }
            k2 = (s8)(s.colors[j] >> 24);
            k2 = k2 * alpha_scale;
            s.colors[j] = (k2 << 24) | tint;
            func_0038CE20(&s.pos[j], &r->vertices[vi], scale);
            uv = (f32 *)(((s16 (*)[4][2])r->indices)[i][j][1] * 8 + (s32)r->uv);
            k = D_001DCF90_sda;
            off = 1.0f - *(f32 *)(p + 0x70) * r->uv_rate;
            s.uv[j][0] = (uv[0] - 0.5f) * k + 0.5f;
            s.uv[j][1] = (uv[1] - 0.5f) * k + 0.5f + off;
        }
        func_003D2DA0(&s, p, 0);
    }
}
/* localdecomp:end func_L01_00337880 */
