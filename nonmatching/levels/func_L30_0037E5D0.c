/* Level 30 near miss: 4 of 437 words differ with @ps2as and
   -mvu0-use-vf0-vf2. The remaining sites are the high address temporary for
   D_L30_001E9020 at 0x0037EB6C/70 and the out3 reload/store register at
   0x0037EBC4/0x0037EBE8. Three formulations left the same residual bytes.
   The existing divs_nops row 2 1 2 is required and is not the residual.
   Started from the level 27 family's draft and corrected against L30 retail;
   block-local variables, a scalar global and variable reuse improved 48 -> 4.
   This draft is not linked; the owning file's flags are unchanged. */
#include "common.h"
#include "vu0.h"

typedef int Q_0037E5D0 __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; Q_0037E5D0 q[0x2A0]; } Hero_0037E5D0;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0037E5D0;

extern Hero_0037E5D0 D_001A4BE0;
extern V4_0037E5D0 D_L30_001E9020;
extern u8 *D_L30_001E9018[];
extern s32 D_L30_001D673C;
extern u8 *D_L30_0021C860[];
extern f32 D_001DE144_sda;
__asm__(".extern D_001DE144_sda, 4");
extern f32 D_001DE140_sda;
__asm__(".extern D_001DE140_sda, 4");
extern s32 D_001D6740_sda;
__asm__(".extern D_001D6740_sda, 4");

extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern u8 *func_00382348(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);

u8 *func_L30_0037E5D0(u8 *m, void *p, f32 *out2, f32 *out3)
{
    V4_0037E5D0 pos;
    V4_0037E5D0 *pp = &pos;
    V4_0037E5D0 v10;
    V4_0037E5D0 v20;
    void *arr[0x80];
    V4_0037E5D0 v230;
    V4_0037E5D0 v240;
    V4_0037E5D0 v250;
    V4_0037E5D0 v260;
    u8 *cur;
    u8 *rec;
    void *pvar;
    u8 *saved;
    f32 lim;
    f32 dist;
    f32 head;
    f32 elev;
    f32 diff;
    f32 dot;
    f32 d0;
    f32 len;
    f32 ang;
    s32 count;
    s32 idx;
    s32 i;
    s32 j;
    s32 hit;

    pos = *(V4_0037E5D0 *)p;
    pvar = *(void **)(m + 0x68);
    lim = D_001DE144_sda;
    saved = 0;

    func_0038CE20(&v10, D_001A4BE0.ptr[0x970] + 0xE0, 0.5f);
    vec_add_ba(&v20, D_001A4BE0.ptr[0x970] + 0x10, &v10);

    if (func_003D3CB0(&v20, pp, 6, D_001A4BE0.ptr[0x970], 0) != 0) {
        pos = D_L30_001E9020;
        return 0;
    }

    count = 0;
    for (idx = 0, cur = D_L30_0021C860[0]; cur != 0; cur = D_L30_0021C860[++idx]) {
        if (*(u8 *)(cur + 0x20) == 0xFE) continue;
        if (*(u8 *)(cur + 0x20) == 0xFD) continue;
        if (*(s16 *)(cur + 0xAA) == 0x1BC3 || *(s16 *)(cur + 0xAA) == 0x189B ||
            *(s16 *)(cur + 0xAA) == 0x1D3E || *(s16 *)(cur + 0xAA) == 0x1A90) continue;
        v230 = *(V4_0037E5D0 *)(cur + 0x10);
        rec = func_00382348(cur);
        if (rec == 0 || *(u8 *)(rec + 0xE) == 3) continue;
        func_0038CE20(&v240, cur + 0xE0, *(f32 *)(rec + 0x10));
        vec_add_ab(&v230, &v230, &v240);
        if (cur == 0 || *(void **)(cur + 0x24) == 0 ||
            *(u8 *)(*(u8 **)(cur + 0x24) + 0x46) != 5) continue;

        head = func_0038D160(v230.x - pp->x, v230.y - pp->y);
        elev = func_0038D160(func_0038CF38(pp, &v230), v230.z - pp->z);
        diff = func_0038DBA0(*out2, head);
        dist = func_0038CF00(pp, &v230);

        hit = 0;
        if (D_L30_001D673C != 0 || D_001A4BE0.h[0x1B4] != 0 || D_001D6740_sda != 0) {
            if (dist < 2.5f) {
                vec_sub_ab(&v250, cur + 0x10, D_001A4BE0.ptr[0x970] + 0x10);
                d0 = func_0038CE68(&v250, D_001A4BE0.ptr[0x970] + 0xE0);
                if (fabs_asm(d0) < 2.0f) {
                    func_0038CE20(&v260, D_001A4BE0.ptr[0x970] + 0xE0, d0);
                    vec_sub_ab(&v250, &v250, &v260);
                    dot = func_0038CE68(&v250, D_001A4BE0.ptr[0x970] + 0xC0);
                    len = func_0038CEA8(&v250);
                    if (len != 0.0f && 1.5707964f - func_0038D0C8(dot / len) < 1.0471976f) hit = 1;
                }
            }
        } else {
            if (dist < 2.5f) {
                u8 *pl = D_001A4BE0.ptr[0x970];
                ang = func_0038D160(*(f32 *)(cur + 0x10) - D_001A4BE0.f[0x20],
                                    *(f32 *)(cur + 0x14) - D_001A4BE0.f[0x21]);
                if (func_0038DBA0(*(f32 *)(pl + 0xF8), ang) < 1.0471976f &&
                    fabs_asm(pp->z - v230.z) < 2.0f) hit = 1;
            }
        }
        if (hit) {
            if (func_003D3CB0(pp, &v230, 6, D_001A4BE0.ptr[0x970], 0) == 0) {
                *out3 = -elev;
                *out2 = head;
                saved = cur;
                goto done;
            }
        }
        if (dist > lim && cur != *(u8 **)(pvar + 0x10)) continue;
        if (dist > D_001DE144_sda) continue;

        func_00382760(&v240, dist, *out2, *out3 + D_001A4BE0.f[0xD1] * 0.5f);
        vec_add_ab(&v240, &v240, pp);
        ang = func_0038D0C8(func_0038CF00(&v240, &v230) / (dist + dist));
        ang = ang + ang;
        if (ang > D_001DE140_sda * 0.017453292f) {
            rec = func_00382348(cur);
            if (rec != 0) {
                f32 d2;
                dot = *(u8 *)(rec + 0xA);
                dot = dot * 0.125f;
                d2 = func_0038D0C8(dot / dist);
                if (dot < dist) {
                    ang = ang - d2;
                    if (ang < 0.0f) ang = 0.0f;
                }
            }
        }
        if (ang < D_001DE140_sda * 0.017453292f) {
            v250 = *pp;
            hit = 1;
            i = 0;
            for (;;) {
                u8 *obj;
                if (func_003D3CB0(&v250, &v230, 6, m, 0) == 0) break;
                if (++i >= 7) break;
                obj = D_L30_001E9018[0];
                if (obj == 0) goto fail;
                if (*(s16 *)(obj + 0xAA) == 0x1BC3 || *(s16 *)(obj + 0xAA) == 0x189B ||
                    *(s16 *)(obj + 0xAA) == 0x1D3E) {
                    arr[count++] = obj;
                    *(void **)(obj + 0x98) = 0;
                    if (count >= 0x80) break;
                    obj = (u8 *)&D_L30_001E9020;
                    v250 = *(V4_0037E5D0 *)obj;
                    continue;
                }
                if (obj == cur) break;
fail:
                hit = 0;
                break;
            }
            if (hit) {
                *out3 = -elev;
                lim = dist;
                if (diff < 0.17453292f) *out2 = head;
                saved = cur;
                if (cur == *(u8 **)(pvar + 0x10)) return saved;
            }
        }
    }
done:
    for (j = 0; j < count; j++) {
        u8 *o = arr[j];
        *(void **)(o + 0x98) = *(void **)(*(u8 **)(o + 0x24) + 0x10);
    }
    return saved;
}
