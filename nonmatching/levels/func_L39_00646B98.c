/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_00644368, the NTSC-U twin of func_L39_00646B98, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 8 words differ with its file's flags.
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_00646B98 (src/levels/shared/L39_00646980.c) */
/* localdecomp:start func_L39_00644368 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 D_L39_004998A0[];
extern void func_L39_0062FD10(void *, void *, void *, f32);
extern f32 func_L39_0062FE30(void *, void *);
extern f32 func_003887C8(void *, void *);
extern void func_003BEC60(void *, f32, void *, f32, f32, f32);
extern void func_00388830(void *, void *, f32);

void func_L39_00644368(u8 *o) {
    u32 buf[2];
    s32 xa;
    s32 xb;
    s32 xc;
    s32 xd;
    s32 xe;
    s32 xf;
    s32 xg;
    f32 target;

    if (*(f32 *)(o + 0x132C) == 0.0f) {
        *(f32 *)(o + 0x132C) = 1.15f;
    }
    if (*(s32 *)(o + 0x1310) == 1) {
        target = 2.0f;
    } else {
        {
            u8 *p = o + 0x19E4;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                xa = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                xa = buf[1];
            }
        }
        if ((xa ^ 4) == 0) {
            goto test_mode;
        }
        {
            u8 *p = o + 0x19E4;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                xb = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                xb = buf[1];
            }
        }
        if ((xb ^ 0x15) != 0) {
            goto test_flag;
        }
      test_mode:
        if (*(s32 *)(o + 0x1310) == 2) {
            goto set_slow;
        }
      test_flag:
        if (o[0x24FD] == 0) {
            goto set_normal;
        }
      set_slow:
        target = 0.6f;
        goto have_target;
      set_normal:
        target = 1.15f;
      have_target:
        {
            u8 *p = o + 0x19E6;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                xc = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                xc = buf[1];
            }
        }
        if ((xc ^ 3) == 0) {
            target = 1.75f;
        }
    }
    *(u128_t *)(o + 0x1170) = *(u128_t *)(o + 0x140);
    if (*(s32 *)(o + 0x1310) == 1) {
        {
            u8 *p = o + 0x19E6;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                xd = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                xd = buf[1];
            }
        }
        if ((xd ^ 4) != 0) {
            *(s32 *)(o + 0x1334) = 0;
        } else {
            {
                u8 *p = o + 0x19E4;
                u8 *b;
                s32 m;
                s32 k;
                s32 n;
                s32 i;

                if (*p == 0) {
                    xe = 0;
                } else {
                    n = *p;
                    m = n + 1;
                    k = ((s32)p - n) & 7;
                    b = (u8 *)buf;
                    for (i = 0; i < 40; i += 5) {
                        *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                    }
                    buf[0] ^= (u32)p;
                    buf[1] ^= buf[0];
                    xe = buf[1];
                }
            }
            if ((xe ^ 0x83) != 0) {
                if (*(f32 *)(o + 0x2AC) < 3.0f && *(s32 *)(o + 0x1334) == 0) {
                    func_L39_0062FD10(o, o + 0x1170, o + 0x140, 0.0f);
                    *(f32 *)(o + 0x132C) = *(f32 *)(o + 0x132C) - func_L39_0062FE30(o, o + 0x140);
                    target = func_003887C8(o + 0x260, o + 0xA0);
                    if (1.0f < target) {
                        target = *(f32 *)(o + 0x2AC);
                    }
                    target = 2.0f - target;
                } else {
                    *(s32 *)(o + 0x1334) = 1;
                }
            } else {
                *(s32 *)(o + 0x1334) = 0;
            }
        }
    }
    func_003BEC60(o + 0x132C, target, (f32 *)(o + 0x132C) + 1, 0.0088888891f, 0.0088888891f, 1.06666672f);
    func_00388830(o + 0x1180, *(u8 **)(o + 0x1288) + 0x20, *(f32 *)(o + 0x132C));
    vec_add_ab(o + 0x1180, o + 0x1180, o + 0xA0);
    {
        u8 *p = o + 0x19E6;
        u8 *b;
        s32 m;
        s32 k;
        s32 n;
        s32 i;

        if (*p == 0) {
            xf = 0;
        } else {
            n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            xf = buf[1];
        }
    }
    if ((xf ^ 0x19) != 0) {
        {
            u8 *p = o + 0x19E4;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                xg = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                xg = buf[1];
            }
        }
        if ((xg ^ 0x68) != 0) {
            return;
        }
    }
    {
        f32 v = *(f32 *)(o + 0x2C4) + 0.75f;

        if (*(f32 *)(o + 0x1188) < v) {
            *(f32 *)(o + 0x1188) = v;
        }
    }
}
/* localdecomp:end func_L39_00644368 */
