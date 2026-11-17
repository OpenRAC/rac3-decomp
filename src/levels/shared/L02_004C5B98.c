#include "common.h"

/* localdecomp:start func_L02_004C5B98 */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern vu0_q D_L02_001E8070[];
__asm__(".extern D_L02_001D673C, 4");
extern s32 D_L02_001D673C;
extern void func_L01_00512490(void);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_00511280(void *, void *, f32);
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern s32 func_L01_003FB640(f32, void *, s32, void *);
extern s32 func_L01_003FC480(f32, f32, void *, s32, void *);
extern s32 func_L01_003FDCA0(void *, s32, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);

s32 func_L02_004C5B98(s32 arg)
{
    vu0_v4 saved;
    vu0_v4 d;
    vu0_v4 diff;
    u8 *h = D_001A4BE0;
    u8 *h2;
    u8 *h3;
    u8 *pos;
    u8 *c;
    s32 up;
    s32 i;
    s32 r;
    f32 m;
    f32 len;
    u8 *hp;
    u8 *hc;

    if (*(s16 *)(h + 0x1F0) != 0) {
        return 1;
    }
    saved = *(vu0_v4 *)(h + 0x80);
    qzero(&d);
    if (*(s16 *)(h + 0x2886) != 0) {
        func_L01_00512490();
        *(s16 *)(h + 0x2886) = 0;
    }
    up = 0;
    if (-0.92f < func_0038CE68(h + 0x20, h + 0x2E0)) {
        up = 1;
    }
    switch (*(s32 *)(h + 0x25CC)) {
    case 0x11:
        break;
    default:
        if (h[0x25F4] != 0 || *(s16 *)(h + 0x218) != 0 || up != 0) {
            hc = D_001A4BE0;
            if (hc[0x25E4] == 2) {
                func_L01_00511280(&d, &d, 5.0f);
            } else if (hc[0x25F4] == 1 || *(s16 *)(hc + 0x218) != 0) {
                func_L01_005110E8(&d, 0, 0.0f, 0.0f, 0.6f);
            } else if (D_L02_001D673C != 0) {
                func_L01_00511280(&d, &d, 0.77f);
            } else {
                func_L01_005110E8(&d, 0, 0.0f, 0.0f, *(f32 *)(hc + 0x274));
            }
        } else {
            d.z = *(f32 *)(h + 0x274);
        }
        break;
    }
    vec_add_ab(D_001A4BE0 + 0x80, D_001A4BE0 + 0x80, &d);
    for (i = 0; i < 8; i++) {
        h2 = D_001A4BE0;
        if (*(s32 *)(h2 + 0x25CC) == 0x11) {
            if (func_L01_003FB640(0.6f, h2 + 0x80, 0x24, *(void **)(h2 + 0x25C0)) == 0) {
                break;
            }
        } else {
            if (h2[0x25F4] != 0 || up != 0) {
                pos = h2 + 0x80;
                r = func_L01_003FB640(*(f32 *)(h2 + 0x284), pos, 0x24, *(void **)(h2 + 0x25C0));
                if (*(s16 *)(h2 + 0x1E6) == 0) {
                    r |= func_L01_003FDCA0(pos, 0, *(f32 *)(h2 + 0x284));
                }
            } else {
                m = *(f32 *)(h2 + 0x270) - *(f32 *)(h2 + 0x274);
                if (m < 0.05f) {
                    m = 0.05f;
                }
                pos = h2 + 0x80;
                r = func_L01_003FC480(*(f32 *)(h2 + 0x284), m, pos, 0x24, *(void **)(h2 + 0x25C0));
                if (*(s16 *)(h2 + 0x1E6) == 0) {
                    r |= func_L01_003FDCA0(pos, 0, *(f32 *)(h2 + 0x284));
                }
            }
            if (r == 0) {
                break;
            }
        }
        c = (u8 *)D_L02_001E8070;
        *(vu0_q *)(D_001A4BE0 + 0x80) = *(vu0_q *)c;
        *(vu0_q *)(D_001A4BE0 + 0x250) = *(vu0_q *)(c + 0x10);
        *(vu0_q *)(D_001A4BE0 + 0x260) = *(vu0_q *)(c - 0x10);
        hp = D_001A4BE0;
        hp[0x2A7] = 1;
        *(s32 *)(hp + 0x28C) = *(s32 *)(c - 0x18);
    }
    vec_sub_ab(D_001A4BE0 + 0x80, D_001A4BE0 + 0x80, &d);
    vec_sub_ab(&diff, D_001A4BE0 + 0x80, &saved);
    len = func_0038CEA8(&diff);
    if (*(f32 *)(D_001A4BE0 + 0x284) * 3.0f < len) {
    if (arg == 0xF) {
    if (diff.x > 512.0f) {
        diff.x = 512.0f;
    } else if (diff.x < -512.0f) {
        diff.x = -512.0f;
    }
    if (diff.y > 512.0f) {
        diff.y = 512.0f;
    } else if (diff.y < -512.0f) {
        diff.y = -512.0f;
    }
    if (diff.z > 512.0f) {
        diff.z = 512.0f;
    } else if (diff.z < -512.0f) {
        diff.z = -512.0f;
    }
    h3 = D_001A4BE0;
    func_0038CF68(&diff, &diff, *(f32 *)(h3 + 0x284));
    vec_add_ab(h3 + 0x80, &saved, &diff);
    }
    return -1;
    }
    return 1;
}
/* localdecomp:end func_L02_004C5B98 */
