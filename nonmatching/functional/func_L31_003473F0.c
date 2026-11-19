/* functional: high. 186 words differ (scheduling/regalloc); the vu0 helper is not even needed with the file's plain flags (vec copy done as struct copy compiles as lq/sq). Constants, gp globals and both collision probes re-read against the asm. */
/* localdecomp:start func_L31_003473F0 */
#include "vu0.h"
__asm__(".extern D_L31_001DCFDC, 4");
__asm__(".extern D_L31_001DCFE0, 4");
__asm__(".extern D_L31_001DCFE4, 4");
__asm__(".extern D_L31_001DCFE8, 4");
__asm__(".extern D_L31_001DCFF0, 4");
extern f32 D_L31_001DCFDC;
extern f32 D_L31_001DCFE0;
extern f32 D_L31_001DCFE4;
extern s32 D_L31_001DCFE8;
extern f32 D_L31_001DCFF0;
extern s32 D_L31_001DF340;
extern u8 D_001A4BE0[];
extern vu0_v4 D_L31_001E91A0;
extern f32 func_L30_0034CE78(u8 *);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
void func_L31_003473F0(vu0_v4 *pos, f32 range, f32 depth) {
    vu0_v4 s, v;
    f32 hz, h, t, lerped, hx, w, lim, m;
    s32 hit;

    h = func_L30_0034CE78(*(u8 **)(D_001A4BE0 + 0x25C0));
    hz = *(f32 *)(D_001A4BE0 + 0x88);
    if (hz + h < pos->z) {
        return;
    }
    if (pos->z + range < hz) {
        return;
    }
    m = hz < pos->z ? pos->z : hz;
    t = (m - pos->z) / range;
    lerped = func_003C4088(depth, 0.0f, t);
    hx = *(f32 *)(D_001A4BE0 + 0x80);
    if (fabs_asm(pos->x - hx) > lerped + D_L31_001DCFDC) {
        return;
    }
    w = *(f32 *)(D_001A4BE0 + 0xF0);
    if ((0.0f < w && hx < pos->x) || (w < 0.0f && pos->x < hx)) {
        *(f32 *)(D_001A4BE0 + 0x100) = *(f32 *)(D_001A4BE0 + 0x100) - *(f32 *)(D_001A4BE0 + 0xF0);
    }
    s = *pos;
    s.z += D_L31_001DCFE0;
    v = s;
    if (hx < pos->x) {
        lim = pos->x - lerped - D_L31_001DCFDC - hx;
        lim = 0.0f < lim ? 0.0f : lim;
        v.x = v.x - (lerped + (D_L31_001DCFDC + D_L31_001DCFDC));
        if (func_003D3CB0(&s, &v, 2, *(u8 **)(D_001A4BE0 + 0x25C0), 0)) {
            m = D_L31_001E91A0.x - *(f32 *)(D_001A4BE0 + 0x80) + D_L31_001DCFDC;
            lim = m < lim ? lim : m;
        }
        v.z = s.z + (D_L31_001DCFE4 - D_L31_001DCFE0);
        s.z = v.z;
        if (func_003D3CB0(&s, &v, 2, *(u8 **)(D_001A4BE0 + 0x25C0), 0)) {
            m = D_L31_001E91A0.x - *(f32 *)(D_001A4BE0 + 0x80) + D_L31_001DCFDC;
            lim = m < lim ? lim : m;
        }
        m = lim < 0.0f ? lim : 0.0f;
    } else {
        lim = pos->x + lerped + D_L31_001DCFDC - hx;
        lim = lim < 0.0f ? 0.0f : lim;
        v.x = v.x + (lerped + (D_L31_001DCFDC + D_L31_001DCFDC));
        if (func_003D3CB0(&s, &v, 2, *(u8 **)(D_001A4BE0 + 0x25C0), 0)) {
            m = D_L31_001E91A0.x - *(f32 *)(D_001A4BE0 + 0x80) - D_L31_001DCFDC;
            lim = lim < m ? lim : m;
        }
        v.z = s.z + (D_L31_001DCFE4 - D_L31_001DCFE0);
        s.z = v.z;
        if (func_003D3CB0(&s, &v, 2, *(u8 **)(D_001A4BE0 + 0x25C0), 0)) {
            m = D_L31_001E91A0.x - *(f32 *)(D_001A4BE0 + 0x80) - D_L31_001DCFDC;
            lim = lim < m ? lim : m;
        }
        m = 0.0f < lim ? lim : 0.0f;
    }
    if (D_L31_001DF340 != D_L31_001DCFE8) {
        D_L31_001DCFE8 = D_L31_001DF340;
        *(f32 *)(D_001A4BE0 + 0x80) = *(f32 *)(D_001A4BE0 + 0x80) + m / (D_L31_001DCFF0 * 50.0f);
    }
}
/* localdecomp:end func_L31_003473F0 */
