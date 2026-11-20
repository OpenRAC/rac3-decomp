/* functional: medium. Hero ledge detection (hero_detect_ledge), written from the PAL assembly only. Written for gate-checking, not byte-matching: VU0 vector adds/subs/zero are plain C (the file's flags cannot take the vu0.h asm helpers), every offset, constant, callee and branch re-read against the PAL assembly; the callees' parameter meanings are inferred (func_0038CF68 = scale vector, func_003D3CB0 = line/collision test, func_L01_005114B0 = vector length). Quirk kept on purpose: when the lip-height test (len + height_above_ground < 1.8 / len < 0.5) returns early, retail leaves v0 = (out ? out->flags : 0), written as `ret`. a1 is unused by retail. */
/* localdecomp:start func_L02_004BDFD8 */
#include "vu0.h"
/* Plain C for the vector library's vadd.xyz / vsub.xyz: xyz are d = a op b, the w lane stays a's (the
 * destination register's w in retail). The file's flags cannot take the vu0.h asm helpers. */
static void vadd3(void *d, void *a, void *b) {
    vu0_v4 *dd = (vu0_v4 *)d, *aa = (vu0_v4 *)a, *bb = (vu0_v4 *)b;
    f32 x = aa->x + bb->x, y = aa->y + bb->y, z = aa->z + bb->z, w = aa->w;
    dd->x = x; dd->y = y; dd->z = z; dd->w = w;
}
static void vsub3(void *d, void *a, void *b) {
    vu0_v4 *dd = (vu0_v4 *)d, *aa = (vu0_v4 *)a, *bb = (vu0_v4 *)b;
    f32 x = aa->x - bb->x, y = aa->y - bb->y, z = aa->z - bb->z, w = aa->w;
    dd->x = x; dd->y = y; dd->z = z; dd->w = w;
}
extern u8 D_001A4BE0[];
extern u8 D_001A50E0[];
extern u8 D_001E8040[];
extern vu0_v4 D_001E8060;
extern vu0_v4 D_001E8080;
extern void func_0038CF68(void *dst, void *src, f32 scale);
extern void func_0038D000(void *dst, void *src, void *hero);
extern f32 func_0038CE68(void *hero);
extern f32 func_0038D098(f32 x);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_L01_005114B0(void *v);
extern void func_L01_00511508(void *dst, void *src, f32 scale);
extern f32 func_L01_00511848(void *v);
extern s32 func_003D3CB0(void *a, void *b, s32 mode, void *moby, s32 flags);
extern s32 func_L01_003FB640(void *p, s32 mode, void *moby, f32 radius);
extern s32 func_003D5630(void);
extern u8 *func_00382348(void *obj);
extern u8 *func_003C4D58(void *obj);
s32 func_L02_004BDFD8(vu0_v4 *pos, s32 unused, u8 *out) {
    u8 *hero = D_001A4BE0;
    vu0_v4 v0, v10, v20, v30, v40, v50, v60, v70, v80, v90, vA0, vB0, vC0, vD0, vE0, vF0, v100, v110, v120, v130;
    s32 flag, i, ok, hit, ret;
    u8 *m, *n, *slot;
    f32 len, len2, step, ang;
    if (out) *(s32 *)(out + 0x28) = 0;
    if (*(s16 *)(hero + 0x1D0) != 0) return 0;
    flag = 0;
    if (hero[0x25E4] == 0) {
        s32 stype = *(s32 *)(hero + 0x25CC);
        s32 skip = 0;
        if (stype == 4) {
            if (hero[0x46E] != 0) { flag = 1; skip = 1; }
            else if (func_L01_005114B0(hero + 0xF0) < 0.07f) { flag = 1; skip = 1; }
        }
        if (!skip) {
            s32 st;
            stype = *(s32 *)(hero + 0x25CC);
            st = *(s32 *)(hero + 0x25C4);
            if (stype == 2 || st == 8 || st == 0x19 || st == 0x1A) flag = 1;
        }
        if (*(s32 *)(hero + 0x25C4) == 0xE && *(f32 *)(hero + 0xC18) < 37.0f) flag = 0;
    }
    if (out != D_001A50E0) flag = 1;
    if (!flag) return 0;
    *(vu0_q *)&v0 = *(vu0_q *)pos;
    func_0038CF68(&v40, hero, *(f32 *)(hero + 0x284));
    vadd3(&v0, &v0, &v40);
    func_0038CF68(&v40, hero + 0x20, 1.65f);
    vadd3(&v10, &v0, &v40);
    func_0038CF68(&v40, hero + 0x20, -1.15f);
    vadd3(&v20, &v0, &v40);
    func_0038CF68(&v30, hero, 0.075f);
    flag = 0;
    for (i = 0; i < 4; i++) {
        vadd3(&v10, &v10, &v30);
        vadd3(&v20, &v20, &v30);
        hit = func_003D3CB0(&v10, &v20, 4, *(void **)(hero + 0x25C0), 0);
        if (hit) {
            s32 r = func_003D5630();
            if (r != 9 && r != 0xC && r != 0) {
                if (func_L01_00511848(&D_001E8080) < 0.349f) flag = 1;
            }
        }
        if (flag) break;
    }
    if (!flag) return 0;
    slot = 0;
    if (*(void **)(D_001E8040 + 0x18)) {
        void *obj = *(void **)(D_001E8040 + 0x18);
        ok = 0;
        m = func_00382348(obj);
        n = func_003C4D58(*(void **)(D_001E8040 + 0x18));
        if (m && (*(u16 *)(m + 0x1E) & 1)) ok = 1;
        else if (n) ok = *(u32 *)(n + 0x3C) & 1;
        if (!ok) return 0;
        slot = *(u8 **)(D_001E8040 + 0x18);
    }
    if (out) *(s32 *)(out + 0x38) = *(s32 *)(D_001E8040 + 0x18);
    *(vu0_q *)&v60 = *(vu0_q *)&D_001E8060;
    vsub3(&v50, &v60, pos);
    len = func_L01_005114B0(&v50);
    if (1.5f < len) return 0;
    func_0038CF68(&v70, hero + 0x20, 0.005f);
    vadd3(&v70, &v70, &v60);
    func_0038CF68(&v80, hero, -1.0f);
    vadd3(&v80, &v80, &v70);
    if (func_003D3CB0(&v80, &v70, 2, *(void **)(hero + 0x25C0), 0)) {
        u8 *hm = *(u8 **)((u8 *)&D_001E8060 - 8);
        if (hm == 0) return 0;
        if (hm != slot) return 0;
    }
    ret = 0;
    if (out) {
        func_0038CF68(&v90, hero + 0x20, 0.6f);
        vadd3(&v90, &v90, &v60);
        if (func_L01_003FB640(&v90, 4, *(void **)(hero + 0x25C0), 0.45f))
            *(u32 *)(out + 0x34) |= 1;
        else
            *(u32 *)(out + 0x34) &= ~1u;
        ret = *(u32 *)(out + 0x34);
    }
    len2 = func_L01_005114B0(&v50);
    if (len2 + *(f32 *)(hero + 0x33C) < 1.8f) return 0;
    if (len2 < 0.5f) return ret;
    vB0.x = 0.0f; vB0.y = 0.0f; vB0.z = 0.0f; vB0.w = 0.0f;
    vB0.x = 1.0f;
    vB0.z = -0.7f;
    func_0038D000(&vB0, &vB0, hero);
    flag = 0;
    vadd3(&vB0, &vB0, &v60);
    vsub3(&v90, pos, &vB0);
    func_L01_00511508(&v90, &v90, 0.0f);
    func_0038CF68(&vA0, hero + 0x20, 0.7f / 5.0f);
    vadd3(&v90, &v90, &vB0);
    for (i = 0; i < 5; i++) {
        if (func_003D3CB0(&v90, &vB0, 2, 0, 0)) {
            func_0038CF68(&vC0, &D_001E8080, 1.0f);
            flag = 1;
            func_L01_00511508(&vC0, &vC0, 0.0f);
            break;
        }
        vadd3(&v90, &v90, &vA0);
        vadd3(&vB0, &vB0, &vA0);
    }
    if (!flag) return 0;
    {
        f32 a = func_0038CE68(hero);
        if (!(a < func_0038D098(1.1347f))) return 0;
    }
    *(vu0_q *)&v120 = *(vu0_q *)&v60;
    func_0038CF68(&v110, hero + 0x2E0, -0.05f);
    func_0038CF68(&v100, &vC0, 0.03f);
    step = 0.0f;
    vadd3(&vF0, &v100, &v110);
    vsub3(&v100, &v100, &v110);
    vadd3(&vD0, &v120, &v100);
    vadd3(&vE0, &v120, &vF0);
    for (;;) {
        if (!func_003D3CB0(&vE0, &vD0, 4, *(void **)(hero + 0x25C0), 0)) {
            if (out) {
                *(vu0_q *)(out + 0x10) = *(vu0_q *)&v120;
                func_0038CF68(&v130, &vC0, 0.5f);
                func_0038CF68(out, hero + 0x2E0, 1.43f);
                vadd3(out, &v130, out);
                vadd3(out, out + 0x10, out);
                ang = func_0038D160(vC0.x, vC0.y);
                *(s32 *)(out + 0x28) = 1;
                *(f32 *)(out + 0x24) = ang;
            }
            return 1;
        }
        step += 0.03f;
        *(vu0_q *)&v120 = *(vu0_q *)&D_001E8060;
        vadd3(&vE0, &v120, &vF0);
        vadd3(&vD0, &v120, &v100);
        if (!(step < 2.4f)) break;
    }
    return 0;
}
/* localdecomp:end func_L02_004BDFD8 */
