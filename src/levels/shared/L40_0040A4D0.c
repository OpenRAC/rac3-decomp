#include "common.h"
#include "vu0.h"

/* The Siege Ranger (Galactic Ranger), legs class 0x109F with its torso 0x109E: moby update,
   network create / think / update callbacks and its walking and fighting. A moby's pVar is at
   +0x68. */

/* The front end's vector helpers */
extern f32 func_0038CEA8(void *v);                 /* length of a vector */
extern f32 func_0038CF38(void *a, void *b);        /* distance between two points */
extern f32 func_0038D160(f32 x, f32 y);            /* the angle of (x, y) */
extern f32 func_0038DBA0(f32 a, f32 b);            /* the difference of two angles */

typedef struct {
    u8 pad0[0x18D];
    s8 f18D;
} S_0040A4D0;
typedef struct {
    u8 pad0[0x88];
    s32 f88[1];
} S_0040A4D0t;

typedef struct {
    u8 pad[0x88];
    s32 f88[1];
} Team_0040BCF0;

/* localdecomp:start func_L40_0040A4D0 */
__asm__(".extern D_L40_00247244, 4");
extern s32 D_L40_00247244;
extern S_0040A4D0 *D_00241640;
extern u8 *D_L40_0024845C;
extern u8 *D_L40_0035746C[];
extern s32 D_001A5DF8[];

extern void func_003C2880(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_003C2F58(u8*m, s32 a1, void*pos);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L39_0061C1E0(void *, s32);
extern s32 func_L39_0066C280(s32 type, s32 uid, s32 time, s32 kind, u8*msg);
extern u8*func_L39_0066C2B8(void);
extern s32 func_00197498(s32);
extern s32 func_L40_0053D8C8(s32, void *, void *, void *);
extern s32 func_L40_0053F7F0(s32);
extern void func_L40_0040BCF0(u8 *m);
extern void func_L40_0040ABB8(u8*m);
extern u8*func_L40_0040AA08(s32 a0, s32 a1, u8*msg);

void func_L40_0040A4D0(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 c;
    u8 *t;
    if (*(s32 *)(v + 0x2B8) == -1 && m[0x20] == 0) {
        if (D_00241640->f18D == 0) {
            func_003C2880(m);
            return;
        }
        func_L39_0061C1E0(m, -1);
        func_L40_0053D8C8(0x109F, func_L40_0040BCF0, func_L40_0040ABB8, func_L40_0040AA08);
        m[0x20] = 0x26;
        *(s32 *)(v + 0x348) = 2;
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F2FF8(m, 1);
        if (*(u8 **)(v + 0x270) != 0) {
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = 0;
            func_L39_005F2FF8(*(u8 **)(v + 0x270), 1);
        }
        return;
    }
    if (*(s32 *)(v + 0x348) == 0) {
        if (D_00241640->f18D == 0) {
            func_003C2880(m);
            return;
        }
        func_L39_0061C1E0(m, -1);
        func_L40_0053D8C8(0x109F, func_L40_0040BCF0, func_L40_0040ABB8, func_L40_0040AA08);
        *(s32 *)(v + 0x348) = 1;
        m[0x30] = 0xFF;
        c = *(s32 *)(v + 0x2F0);
        if ((u32)c >= 2) {
            c = D_L40_00247244;
        } else {
            c = ((S_0040A4D0t *)D_L40_0035746C[0])->f88[*(s32 *)(v + 0x2B8)];
        }
        t = *(u8 **)(v + 0x270);
        if (t == 0 || t[0x20] == 0xFE || t[0x20] == 0xFD) {
            u8 *n = func_003C24B0(0x109E, 0);
            *(u8 **)(v + 0x270) = n;
            if (n != 0) {
                func_L01_00456160(n, m);
            }
        }
        *(f32 *)(m + 0x18) = func_003C3D30(m + 0x10, 0, 0, 0.5f);
        *(f32 *)(*(u8 **)(v + 0x270) + 0xF8) = *(f32 *)(m + 0xF8);
        func_003C2F58(m, 0, *(u8 **)(v + 0x270) + 0x10);
        m[0x7E] = ((m[0x7E] | 0x80) & 0x8F) | (c << 4);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F2FF8(m, 1);
        if (*(u8 **)(v + 0x270) != 0) {
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(v + 0x270) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = 0;
            func_L39_005F2FF8(*(u8 **)(v + 0x270), 1);
        }
    } else if (func_L40_0053F7F0((m - D_L40_0024845C) >> 8) != 0) {
        if (*(s32 *)(v + 0x348) == 1) {
            u8 *msg;
            u8 *q;

            msg = (u8 *)func_L39_0066C2B8();
            if (msg == 0) {
                return;
            }
            q = msg + func_L39_0066C280(0, func_00197498(2), D_001A5DF8[0] + 0x1F4, 0x109F, msg);
            *(s32 *)q = (m - D_L40_0024845C) >> 8;
            q += 4;
            *(s32 *)q = *(s32 *)(v + 0x2B8);
            q += 4;
            *(s32 *)msg = q - msg;
            *(s32 *)(v + 0x348) = 2;
            func_L40_0053D8C8(0x109F, func_L40_0040BCF0, func_L40_0040ABB8, func_L40_0040AA08);
        }
    } else if (*(s32 *)(v + 0x348) == 1) {
        *(s32 *)(v + 0x348) = 2;
        func_L40_0053D8C8(0x109F, func_L40_0040BCF0, func_L40_0040ABB8, func_L40_0040AA08);
    }

    if (m[0x20] == 0x25) {
        *(s32 *)(v + 0x2CC) = 0;
        if ((*(s32 *)(v + 0x3D8) * 5 + 2) / 6 < ++*(s32 *)(v + 0x34C)) {
            s32 idx;
            s32 r = func_003D4D00(m + 0x10, 1, 0, 0, 2.0f);
            *(s32 *)(v + 0x3D8) += 0x1F4;
            if (r == 0) {
                m[0x20] = 0;
                *(s32 *)(v + 0x360) = 0;
                idx = (m - D_L40_0024845C) >> 8;
                *(f32 *)(v + 0x30) = *(f32 *)(v + 0x3D0);
                *(s16 *)(v + 0x34) = *(f32 *)(v + 0x3D0);
                if (func_L40_0053F7F0(idx) != 0) {
                    u8 *msg;
                    u8 *q;

                    msg = (u8 *)func_L39_0066C2B8();
                    if (msg == 0) {
                        return;
                    }
                    q = msg + func_L39_0066C280(0, func_00197498(2), D_001A5DF8[0] + 0x1388, 0x109F, msg);
                    *(s32 *)q = (m - D_L40_0024845C) >> 8;
                    q += 4;
                    *(s32 *)q = *(s32 *)(v + 0x2B8);
                    q += 4;
                    *(s32 *)msg = q - msg;
                }
            }
        }
    }
    if (m[0x20] == 0x27) {
        u8 *msg;
        u8 *q;

        *(s32 *)(v + 0x2CC) = 0;
        *(s32 *)(v + 0x34C) += 1;
        m[0x20] = 0;
        *(s32 *)(v + 0x360) = 0;
        *(f32 *)(v + 0x30) = *(f32 *)(v + 0x3D0);
        *(s16 *)(v + 0x34) = *(f32 *)(v + 0x3D0);
        msg = (u8 *)func_L39_0066C2B8();
        if (msg == 0) {
            return;
        }
        q = msg + func_L39_0066C280(0, func_00197498(2), D_001A5DF8[0] + 0x1388, 0x109F, msg);
        *(s32 *)q = (m - D_L40_0024845C) >> 8;
        q += 4;
        *(s32 *)q = *(s32 *)(v + 0x2B8);
        q += 4;
        *(s32 *)msg = q - msg;
    }
}
/* localdecomp:end func_L40_0040A4D0 */

/* localdecomp:start func_L40_0040AA08 */
/* The frame counter where code reads it through $gp (func_L40_0040D678's near miss says why) */
__asm__(".extern D_L40_0024112C_b, 4");
extern s32 D_L40_0024112C_b;
extern s32 func_L40_0053F2D8(u8 *msg);
extern u8 *func_L40_0053F570(s32 cls, s32 uid, s32 sender, s32 a3, s32 index);
extern void func_L39_005F3488(s32 a0, s32 a1, u8 *m, s32 cls);
extern f32 func_003C3D30(void *pos, s32 a1, s32 a2, f32 f);
extern s32 func_L40_0053DAE8(s32 a0, s32 team);
extern void func_003C2F58(u8 *m, s32 a1, void *pos);
extern void func_003C7C38(u8 *m);
extern void func_L40_003D3D80(u8 *m, s32 cls);
extern void func_L40_00413158(u8 *m, s32 cls);

/* The Ranger class's network create callback: take (or spawn) the moby the message names, fill
   its pVar's pointer table, health and team, and add it to the target registry. */
u8 *func_L40_0040AA08(s32 a0, s32 a1, u8 *msg) {
    s32 index = *(s32 *)(msg + 0x18);
    u8 *m;
    u8 *v;
    s32 team;
    s32 *h = (s32 *)(msg + 8);

    m = func_L40_0053F570(0x109F, h[1], *(s32 *)(msg + 4), func_L40_0053F2D8(msg), index);
    if (m != 0) {
        if (D_L40_0024112C_b >= 61) {
            func_L39_005F3488(1, 0, m, 0x109F);
        }
        *(u8 *)(m + 0x30) = 0x7F;
        *(u16 *)(m + 0x34) |= 0x20;
        *(u16 *)(m + 0x32) = 0x7F;
        *(f32 *)(m + 0x18) = func_003C3D30(m + 0x10, 0, 0, 0.5f);
        v = *(u8 **)(m + 0x68);
        *(u8 **)(v + 0x1C) = v + 0x70;
        *(u8 **)(v + 0xC) = v + 0x220;
        *(u8 **)(v + 0x0) = v + 0x30;
        *(u8 **)(v + 0x10) = v + 0x160;
        *(s32 *)(v + 0x370) = -1;
        *(u8 *)(m + 0x20) = 0;
        *(s32 *)(v + 0x360) = 0;
        *(s32 *)(v + 0x34C) = 0;
        *(f32 *)(v + 0x30) = *(f32 *)(v + 0x3D0);
        *(s16 *)(v + 0x34) = *(f32 *)(v + 0x3D0);
        *(s32 *)(v + 0x2CC) = 0;
        team = *(s32 *)(msg + 0x1C);
        *(s32 *)(v + 0x2B8) = team;
        *(u8 *)(v + 0x3E) = 1;
        *(s32 *)(v + 0x36C) = 0;
        *(s32 *)(v + 0x290) = 0;
        if (team != -1) {
            *(s32 *)(v + 0x2F0) = team;
            if (team >= 2) {
                *(s32 *)(v + 0x2F0) = 6;
            }
        }
        if (*(s32 *)(v + 0x2F0) != -1) {
            func_L40_0053DAE8(a0, *(s32 *)(v + 0x2F0));
        }
        if (*(u8 **)(v + 0x270) != 0) {
            func_003C2F58(m, 0, *(u8 **)(v + 0x270) + 0x10);
        }
        func_003C7C38(m);
        if (*(u8 **)(v + 0x270) != 0) {
            func_003C7C38(*(u8 **)(v + 0x270));
        }
        func_L40_003D3D80(m, 0x109F);
        func_L40_00413158(m, 0x109F);
    }
    return m;
}
/* localdecomp:end func_L40_0040AA08 */

/* localdecomp:start func_L40_0040ABB8 */
/* The game mode where state 1 reads it, through $gp (the other read, through lui, is the
   plain name; func_L40_0040D678's near miss says why there are two). */
__asm__(".extern D_L40_002412DC_b, 4");
extern s32 D_L40_002412DC_b;
extern s32 D_L40_002412DC[] __attribute__((section(".sdata")));
extern s32 *D_L40_0028FD80[]; /* the map's paths: a count, then 16-byte points from +0x10 */
extern s32 D_001A5DF8[];
extern s32 func_L40_0053E1A8(u8 *m, s32 team, s32 a2, f32 range, f32 b, f32 c, void *a3);
extern u8 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);
extern s32 func_L40_0053E760(s32 uid, vu0_v4 *pos, s32 a2, s32 a3);
extern s32 func_L39_005B4398(s32 n);
extern s32 func_L39_005B43C8(s32 lo, s32 hi);

/* The Ranger class's network think callback: find a target (state 1) or keep it (state 2), and
   step along the path, telling the other consoles. */
void func_L40_0040ABB8(u8 *m) {
    u8 *v;
    s32 uid;
    vu0_v4 pos;

    if (m == 0) {
        return;
    }
    v = *(u8 **)(m + 0x68);
    uid = **(s32 **)(m + 0x90);
    if (*(s32 *)(v + 0x360) == 0) {
        *(s32 *)(v + 0x360) = 1;
    }
    switch (*(s32 *)(v + 0x360)) {
    case 1:
    {
        s32 t;
        s32 n;
        s32 i;
        s32 old;
        s32 *path;
        u8 *msg;
        u8 *p;
        f32 r;

        if (*(s32 *)(v + 0x2F0) == -1) {
            return;
        }
        r = -1.0f;
        if (D_L40_002412DC_b == 0x2D || D_L40_002412DC_b == 0x37) {
            r = 10.0f;
        }
        t = func_L40_0053E1A8(m, *(s32 *)(v + 0x2F0), 0, *(f32 *)(v + 0x2C0), -1.0f, r, *(void **)(v + 0x2A0));
        if (t != -1) {
            u8 *msg1;
            u8 *p1;

            msg1 = func_L39_0066C2B8();
            if (msg1 == 0) {
                return;
            }
            p1 = msg1 + func_L39_0066C280(1, uid, D_001A5DF8[0] + 500, 0, msg1);
            *(s32 *)p1 = t;
            p1 += 4;
            *(s32 *)msg1 = p1 - msg1;
            *(s32 *)(v + 0x2B4) = t;
            *(s32 *)(v + 0x360) = 2;
            return;
        }
        if (*(s32 *)(v + 0x2C8) == -1) {
            return;
        }
        path = D_L40_0028FD80[*(s32 *)(v + 0x2C8)];
        if (*(s32 *)(v + 0x370) != -1 && !(func_0038CF38(m + 0x10, (u8 *)path + 0x10 + *(s32 *)(v + 0x370) * 16) < 1.0f)) {
            return;
        }
        if (func_L39_005B4398(0x63)) {
            return;
        }
        if (*(s32 *)(v + 0x3DC) == 0) {
            *(s32 *)(v + 0x3DC) = 1;
        }
        n = path[0];
        i = *(s32 *)(v + 0x370) + *(s32 *)(v + 0x3DC);
        if (n - 1 < i) {
            *(s32 *)(v + 0x3DC) = -1;
            i = n - 2;
        }
        if (i < 0) {
            i = 0;
            *(s32 *)(v + 0x3DC) = 1;
        }
        old = *(s32 *)(v + 0x370);
        if (i == old) {
            return;
        }
        *(s32 *)(v + 0x370) = i;
        *(s32 *)(v + 0x36C) = i;
        msg = func_L39_0066C2B8();
        if (msg == 0) {
            return;
        }
        p = msg + func_L39_0066C280(1, uid, D_001A5DF8[0] + 500, 3, msg);
        *(s32 *)p = i;
        p += 4;
        *(s32 *)p = old;
        p += 4;
        *(s32 *)msg = p - msg;
        return;
    }
    case 2:
    {
        s32 t;
        s32 i;
        s32 old;
        s32 idx;
        s32 *path;
        u8 *msg;
        u8 *p;
        f32 r;
        f32 best;
        f32 d;
        s32 delay;

        path = 0;
        if (*(s32 *)(v + 0x2C8) != -1) {
            path = D_L40_0028FD80[*(s32 *)(v + 0x2C8)];
        }
        r = -1.0f;
        if (D_L40_002412DC[0] == 0x2D || D_L40_002412DC[0] == 0x37) {
            r = 10.0f;
        }
        t = func_L40_0053E1A8(m, *(s32 *)(v + 0x2F0), 0, *(f32 *)(v + 0x2C0) + 7.0f, -1.0f, r, *(void **)(v + 0x2A0));
        if (*(s32 *)(v + 0x2B4) != t) {
            msg = func_L39_0066C2B8();
            if (msg == 0) {
                return;
            }
            p = msg + func_L39_0066C280(1, uid, D_001A5DF8[0] + 500, 0, msg);
            *(s32 *)p = t;
            p += 4;
            *(s32 *)msg = p - msg;
            *(s32 *)(v + 0x360) = 2;
            *(s32 *)(v + 0x2B4) = t;
        }
        if (t == -1) {
            *(s32 *)(v + 0x360) = 1;
            return;
        }
        idx = *(s32 *)(v + 0x36C);
        if (*(s32 *)(v + 0x2C8) != -1 && path != 0 && func_0038CF38(m + 0x10, (u8 *)path + 0x10 + idx * 16) < 0.5f && !func_L39_005B4398(0x63)) {
            best = 99999.0f;
            if (!func_L40_0053E760(*(s32 *)(v + 0x2B4), &pos, -1, 1)) {
                return;
            }
            for (i = 0; i < path[0]; i++) {
                d = func_0038CF38(&pos, (u8 *)path + 0x10 + i * 16);
                if (d < best) {
                    best = d;
                    idx = i;
                }
            }
        }
        if (*(s32 *)(v + 0x2C8) == -1) {
            return;
        }
        old = *(s32 *)(v + 0x36C);
        if (idx == old) {
            return;
        }
        if (idx < old) {
            idx = old - 1;
        } else {
            idx = old + 1;
        }
        *(s32 *)(v + 0x36C) = idx;
        *(s32 *)(v + 0x370) = idx;
        msg = func_L39_0066C2B8();
        if (msg == 0) {
            return;
        }
        delay = func_L39_005B43C8(0, 300) + 500;
        p = msg + func_L39_0066C280(1, uid, D_001A5DF8[0] + delay, 2, msg);
        *(s32 *)p = idx;
        p += 4;
        *(s32 *)msg = p - msg;
        return;
    }
    }
}
/* localdecomp:end func_L40_0040ABB8 */

LINKER_REMNANT("asm/levels", func_L40_0040B050);

/* localdecomp:start func_L40_0040B058 */
__asm__(".extern D_L40_00247250, 4");
extern f32 D_L40_00247250;
extern s32 D_001A5DF8[];
extern void func_0038CE20(void *d, void *s, f32 k);
extern void func_L40_0040CEF8(u8 *a0, s32 a1, s32 a2, s32 a3);
extern s32 func_L40_0040D310(u8 *m, void *target, s32 mode, f32 yaw);

void func_L40_0040B058(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 d;
    s32 n;
    f32 len;

    vec_sub_ba(&d, v + 0x300, m + 0x10);
    n = (s32)((*(s32 *)(v + 0x2C4) + (s32)D_L40_00247250 - D_001A5DF8[0]) * 0.06f);
    if (n < 0) {
        n = 0;
    }
    func_0038CE20(v + 0x110, &d, 1.0f / (n + 1));
    len = func_0038CEA8(v + 0x110);
    if (len > 0.0f) {
        func_L40_0040CEF8(m, 10, 0, 0x11);
        *(f32 *)(*(u8 **)(v + 0x270) + 0xF8) = *(f32 *)(m + 0xF8);
    }
    if (len == 0.0f) {
        *(s32 *)(v + 0x25C) -= 1;
    } else {
        func_L40_0040D310(m, v + 0x300, 0, func_0038D160(*(f32 *)(v + 0x300) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x304) - *(f32 *)(m + 0x14)));
        *(s32 *)(v + 0x25C) -= 1;
    }
}
/* localdecomp:end func_L40_0040B058 */

INCLUDE_ASM("asm/levels", func_L40_0040B1D0);

/* localdecomp:start func_L40_0040B9C0 */
__asm__(".extern D_L40_00247268, 4");
__asm__(".extern D_L40_0024726C, 4");
__asm__(".extern D_L40_00247270, 4");
extern f32 D_L40_00247268; /* 2.2: a player this close stops the Ranger */
extern f32 D_L40_0024726C; /* 5.0: and one this close, */
extern f32 D_L40_00247270; /* 40.0: within this many degrees of its facing */
extern s32 D_L40_0024112C[] __attribute__((section(".sdata")));
extern u8 *D_L40_00249330[8] __attribute__((section(".sdata")));

/* 1 (and pVar+0x37C set) when a player stands in the Ranger's way. Checked on the frame that
   is this moby's turn (moby index mod 8); otherwise the last result stands. */
s32 func_L40_0040B9C0(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 i;
    f32 d;
    u8 *pm;

    if ((D_L40_0024112C[0] & 7) != (((s32)m >> 8) & 7)) {
        return *(s32 *)(v + 0x37C);
    }
    for (i = 0; i < 8; i++) {
        if (D_L40_00249330[i] == 0) {
            continue;
        }
        d = func_0038CF38(*(u8 **)(D_L40_00249330[i] + 0x2524) + 0x10, m + 0x10);
        if (d > D_L40_0024726C) {
            continue;
        }
        if (d <= D_L40_00247268) {
            *(s32 *)(v + 0x37C) = 1;
            return 1;
        }
        pm = *(u8 **)(D_L40_00249330[i] + 0x2524);
        if (func_0038DBA0(func_0038D160(*(f32 *)(pm + 0x10) - *(f32 *)(m + 0x10), *(f32 *)(pm + 0x14) - *(f32 *)(m + 0x14)), *(f32 *)(m + 0xF8)) <= D_L40_00247270 * 0.017453292f) {
            *(s32 *)(v + 0x37C) = 1;
            return 1;
        }
    }
    *(s32 *)(v + 0x37C) = 0;
    return 0;
}
/* localdecomp:end func_L40_0040B9C0 */

/* localdecomp:start func_L40_0040BAF0 */
extern s32 func_L40_0040D678(u8 *m, void *target, f32 yaw);
extern void func_L01_00448890(void *a0, f32 f12, f32 f13, f32 f14, f32 f15, void *a1, s32 a2);

void func_L40_0040BAF0(u8 *m, void *target, f32 yaw) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *pos = m + 0x10;
    u8 *mv = v + 0x70;
    vu0_v4 old = *(vu0_v4 *)pos;
    s32 flags;
    f32 dist;

    if (func_0038DBA0(*(f32 *)(v + 0x278), yaw) > 0.0872664601f) {
        *(f32 *)(v + 0x258) = yaw;
        *(s32 *)(v + 0x28C) += 1;
    }
    flags = *(s32 *)(v + 0xA8);
    *(s32 *)(v + 0xA8) = flags | 0x10;
    func_L40_0040D678(m, target, yaw);
    *(s32 *)(v + 0x374) = 0;
    dist = func_0038CF38(pos, target);
    if (dist > *(f32 *)(v + 0xA4) + *(f32 *)(v + 0xA4)) {
        func_L01_00448890(m + 0xF8, yaw, *(f32 *)(mv + 0x14), *(f32 *)(mv + 0x18), *(f32 *)(mv + 0x1C), v + 0x124, 0);
    }
    *(s32 *)(v + 0xA8) = flags;
}
/* localdecomp:end func_L40_0040BAF0 */

/* localdecomp:start func_L40_0040BC00 */
extern f32 func_L01_004482A0(void *a0, void *a1, f32 t, f32 a, f32 b, f32 c);

void func_L40_0040BC00(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    f32 t;

    t = func_0038CEA8(v + 0x110) / 0.120000005f;
    if (t > 1.1f) {
        t = 1.1f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    if (t < 0.7f) {
        t = 0.7f;
    }
    func_L01_004482A0(m + 0x48, v + 0x254, t, 0.1f, 0.1f, 0.0f);
    if (*(f32 *)(m + 0x48) == 0.0f) {
        func_0038CF38(m + 0x10, v + 0x310);
    }
}
/* localdecomp:end func_L40_0040BC00 */

/* localdecomp:start func_L40_0040BCF0 */
__asm__(".extern D_L40_00247244, 4");
__asm__(".extern D_L40_00247248, 4");
__asm__(".extern D_L40_0024725C, 4");
__asm__(".extern D_L40_00247260, 4");
__asm__(".extern D_L40_00247264, 4");
__asm__(".extern D_L40_00247274, 4");
__asm__(".extern D_L40_00247278, 4");
__asm__(".extern D_L40_0024727C, 4");
__asm__(".extern D_L40_00247280, 4");
__asm__(".extern D_L40_00247284, 4");
__asm__(".extern D_L40_00247288, 4");
__asm__(".extern D_L40_0024728C, 4");
__asm__(".extern D_L40_00247290, 4");
__asm__(".extern D_L40_0024846C, 4");
extern s32 D_L40_00247244;
extern s32 D_L40_00247248;
extern f32 D_L40_0024725C;
extern f32 D_L40_00247260;
extern s32 D_L40_00247264;
extern s32 D_L40_00247274;
extern s32 D_L40_00247278;
extern s32 D_L40_0024727C;
extern s32 D_L40_00247280;
extern s32 D_L40_00247284;
extern s32 D_L40_00247288;
extern f32 D_L40_0024728C;
extern f32 D_L40_00247290;
extern u8 *D_L40_0024846C;

extern u8 D_L40_00242960[] __attribute__((section(".sdata")));

extern u32 D_001A5CD8[];
extern void func_L40_0053F6E0();
extern s32 func_L40_0053F018(u8 *m);
extern void func_003C2880(void *);
extern s32 func_L40_0040C6F0(u8 *m, s32 a1);
extern s32 func_L01_004561B8(u8 *m);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_0045A748(u8 *, void *);
extern f32 func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_0044E1B8(u8 *, f32);
extern u8 *func_00382348(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00565750(u8 *, void *, void *, s32, s32, f32, f32, f32);
extern void func_L40_0040CF68(void *);
extern void func_L40_0040CD80(u8 *m);
extern u8 *func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 *func_L39_0061BFB0(u32);
extern void func_L39_0066C470(s32);
extern void func_L40_0040B058(u8 *m);
extern s32 func_L40_0040B9C0(u8 *m);
extern void func_L40_0040BAF0(u8 *m, void *target, f32 yaw);
extern void func_L40_0040BC00(u8 *m);

void func_L40_0040BCF0(u8 *m) {
    s32 *ctx;
    u8 *v;
    s32 uid;
    s32 st;
    s32 c;
    s32 sh;
    s16 s;
    u8 b;
    vu0_v4 B;
    vu0_v4 A;
    vu0_v4 D;
    vu0_v4 C;

    if (m == 0) {
        return;
    }
    ctx = *(s32 **)(m + 0x90);
    v = *(u8 **)(m + 0x68);
    uid = ctx[0];
    if ((u32)(*(u8 *)(m + 0x20) - 0x25) < 2) {
        func_L40_0053F6E0();
        if (*(u8 **)(v + 0x270) != 0 && *(s16 *)(*(u8 **)(v + 0x270) + 0xAA) == 0x109E) {
            func_003C2880(*(u8 **)(v + 0x270));
        }
        *(s32 *)(v + 0x270) = 0;
        return;
    }
    if (func_L40_0040C6F0(m, uid) != 0) {
        return;
    }
    st = *(u8 *)(m + 0x20);
    if ((u8)st == 0xFD || (u8)st == 0xFE) {
        return;
    }
    if ((u8)st == 0x25) {
        return;
    }
    if ((u8)st == 0x26) {
        return;
    }
    if (*(s32 *)(v + 0x2B8) != -1) {
        s32 tv = ((Team_0040BCF0 *)D_L40_0035746C[0])->f88[*(s32 *)(v + 0x2B8)];
        *(s32 *)(v + 0x2F0) = tv;
        ctx[6] = tv;
    }
    c = *(s32 *)(v + 0x2F0);
    if ((u32)c >= 2) {
        c = D_L40_00247244;
    }
    *(u8 *)(m + 0x7E) = (((*(u8 *)(m + 0x7E)) | 0x80) & 0x8F) | (c << 4);
    if (*(u8 **)(v + 0x270) != 0) {
        *(u8 *)(*(u8 **)(v + 0x270) + 0x7E) |= 0x80;
        *(u8 *)(*(u8 **)(v + 0x270) + 0x7E) &= 0x8F;
        *(u8 *)(*(u8 **)(v + 0x270) + 0x7E) |= c << 4;
    }
    if (*(s32 *)(m + 0x28) == 0 && m != D_L40_0024846C) {
        return;
    }
    if (func_L40_0053F018(m) != 0) {
        *(u8 *)(m + 0x30) = 0xFF;
        *(s16 *)(*(u8 **)(v + 0x270) + 0x32) = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
    } else {
        *(u8 *)(m + 0x30) = 0x46;
        *(s16 *)(*(u8 **)(v + 0x270) + 0x32) = 0x3C;
        *(s16 *)(m + 0x32) = 0x3C;
    }
    if (*(u8 **)(v + 0x270) != 0) {
        *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = 0;
    }
    switch (*(u8 *)(m + 0x20)) {
    case 2:
        if (func_L01_004561B8(m) != 0) {
            func_003C3A10(*(u8 **)(v + 0x270), 4, 0, 8);
        }
        if (*(s16 *)(v + 0x234) == 1) {
            if (*(s32 *)(v + 0x2C8) == -1) {
                u8 *p = v + 0x220;
                if (func_L01_0040E570(v + 0x240, p) < D_L40_00247260 && func_L40_0040B9C0(m) == 0) {
                    func_L01_0045A748(m, p);
                    func_L40_0040BC00(m);
                    *(f32 *)(m + 0x48) = 1.0f;
                }
            }
            {
                u8 *t = *(u8 **)(v + 0x270) + 0xF8;
                func_L01_00448728(t, func_0038D160(*(f32 *)(v + 0x220) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x224) - *(f32 *)(m + 0x14)),
                                  v + 0x284, 0.0100530973f, 0.00083775812f, 0.50265485f, 0);
            }
            if (func_L01_0044E1B8(*(u8 **)(v + 0x270), D_L40_0024725C) != 0) {
                func_003C2F58(*(u8 **)(v + 0x270), D_L40_00247248, &A);
                B = *(vu0_v4 *)(v + 0x220);
                if (*(s32 *)(v + 0x230) != 0) {
                    u8 *r = func_00382348(*(void **)(v + 0x230));
                    if (r != 0) {
                        func_0038CF68(&C, D_L40_00242960, *(f32 *)(r + 0x10));
                        vec_add_ab(&B, &B, &C);
                    }
                }
                vec_sub_ab(&D, &B, &A);
                func_0038CF68(&D, &D, 0.8000001f);
                {
                    s32 a7 = D_L40_00247274;
                    s32 a8 = D_L40_00247280;
                    if (*(s32 *)(v + 0x2F0) == 0) {
                        a7 = D_L40_00247278;
                        a8 = D_L40_00247284;
                    } else if (*(s32 *)(v + 0x2F0) == 1) {
                        a7 = D_L40_0024727C;
                        a8 = D_L40_00247288;
                    }
                    func_L39_00565750(m, &A, &D, a7, a8, *(f32 *)(v + 0x3D4), D_L40_0024728C, D_L40_00247290);
                }
            }
            if (*(s32 *)(v + 0x2C8) != -1) {
                u8 *path = (u8 *)D_L40_0028FD80[*(s32 *)(v + 0x2C8)];
                if (func_0038CF38(m + 0x10, path + (*(s32 *)(v + 0x290) * 16 + 0x10)) > 0.2f && func_L40_0040B9C0(m) == 0) {
                    if (*(u8 *)(m + 0x43) != 10) {
                        func_003C3A10(m, 10, 0, 8);
                    }
                    func_L01_0045A748(m, path + (*(s32 *)(v + 0x290) * 16 + 0x10));
                } else if (*(u8 *)(m + 0x43) != 4) {
                    func_003C3A10(m, 4, 0, 8);
                }
            }
        } else {
            func_L40_0040CEF8(m, 0, 0, 8);
            qzero(v + 0x110);
        }
        if (*(u16 *)(m + 0x96) >= 0x33 || (*(u8 *)(m + 0x60) & 2) != 0) {
            func_L01_004450F0(m, 3, -1);
        }
        break;
    case 3:
        {
            u8 *t = *(u8 **)(v + 0x270);
            if ((*(u8 *)(t + 0x60) & 2) != 0) {
                if (*(u8 *)(t + 0x43) == 4) {
                    if (*(s16 *)(v + 0x234) == 1) {
                        func_003C3A10(t, 5, 0, 8);
                    } else {
                        func_003C3A10(t, 0, 0, 8);
                    }
                } else if (*(u8 *)(t + 0x43) == 5) {
                    func_L01_004450F0(m, 2, -1);
                }
            }
        }
        {
            u8 *t = *(u8 **)(v + 0x270) + 0xF8;
            func_L01_00448728(t, func_0038D160(*(f32 *)(v + 0x220) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x224) - *(f32 *)(m + 0x14)),
                              v + 0x284, 0.0100530973f, 0.00083775812f, 0.50265485f, 0);
        }
        if ((D_L40_00247264 * 5 + 2) / 6 < *(u16 *)(m + 0x96)) {
            func_L01_004450F0(m, 2, -1);
        }
        if (*(s32 *)(v + 0x2C8) != -1) {
            u8 *path = (u8 *)D_L40_0028FD80[*(s32 *)(v + 0x2C8)];
            if (func_0038CF38(m + 0x10, path + (*(s32 *)(v + 0x290) * 16 + 0x10)) > 0.2f && func_L40_0040B9C0(m) == 0) {
                if (*(u8 *)(m + 0x43) != 10) {
                    func_003C3A10(m, 10, 0, 8);
                }
                func_L01_0045A748(m, path + (*(s32 *)(v + 0x290) * 16 + 0x10));
            } else {
                u8 *t = *(u8 **)(v + 0x270);
                if (*(u8 *)(m + 0x43) != *(u8 *)(t + 0x43)) {
                    func_003C3A10(m, *(u8 *)(t + 0x43), 0, 8);
                }
            }
        } else {
            if (*(u8 *)(m + 0x43) != 9) {
                func_003C3A10(m, 9, 0, 8);
            }
            if (*(s32 *)(v + 0x2EC) == 1) {
                s32 fl = *(s32 *)(v + 0xA8);
                *(s32 *)(v + 0xA8) = fl | 0x10;
                func_L40_0040BAF0(m, v + 0x310, *(f32 *)(v + 0x2E4));
                func_L40_0040BC00(m);
                *(f32 *)(m + 0x48) = 1.0f;
                *(s32 *)(v + 0xA8) = fl;
            }
        }
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            func_L40_0040CEF8(m, 0, 0, 0x11);
            func_003C2F58(m, 0, *(u8 **)(v + 0x270) + 0x10);
            *(f32 *)(*(u8 **)(v + 0x270) + 0xF0) = *(f32 *)(m + 0xF0);
            *(f32 *)(*(u8 **)(v + 0x270) + 0xF4) = *(f32 *)(m + 0xF4);
        }
        if (*(s32 *)(v + 0x2C8) != -1 && *(s32 *)(v + 0x340) != -1) {
            u8 *path = (u8 *)D_L40_0028FD80[*(s32 *)(v + 0x2C8)];
            if (func_0038CF38(m + 0x10, path + (*(s32 *)(v + 0x340) * 16 + 0x10)) > 0.8f && func_L40_0040B9C0(m) == 0) {
                if (*(u8 *)(m + 0x43) != 9) {
                    func_003C3A10(m, 9, 0, 8);
                }
                func_L01_0045A748(m, path + (*(s32 *)(v + 0x340) * 16 + 0x10));
                *(f32 *)(*(u8 **)(v + 0x270) + 0xF8) = *(f32 *)(m + 0xF8);
                break;
            }
            if ((*(u8 *)(m + 0x60) & 2) == 0) {
                if (*(u8 *)(m + 0x43) != 9) {
                    break;
                }
            }
        } else if ((*(u8 *)(m + 0x60) & 2) == 0) {
            break;
        }
        func_L40_0040CEF8(m, func_L39_005B43C8(0, 1), 0, 8);
        break;
    case 4:
        if (*(f32 *)(v + 0x30) <= 0.0f && func_L40_0053F018(m) != 0) {
            u8 *r;
            u8 *e;
            u32 w;
            func_L40_0040CD80(m);
            func_L40_0053F6E0(m);
            r = func_L01_003303B8(m + 0x10, 0, 5, 5, 5, 10, 10, 3, 1.0f, 0.0f, 0.0f, 2.0f,
                                  0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                                  0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            if (r != 0) {
                *(u8 **)(r + 0xB8) = m;
            }
            w = *(u32 *)(v + 0x2AC);
            if ((w >> 28) == D_001A5CD8[0]) {
                e = func_L39_0061BFB0(w);
                if (e != 0) {
                    *(u8 *)(e + 0x1A11) = 0;
                }
            }
            return;
        }
        break;
    case 5:
        func_L40_0040B058(m);
        break;
    }
    func_L40_0040CF68(m);
    if (*(f32 *)(m + 0x10) < 10.0f || *(f32 *)(m + 0x14) < 10.0f || *(f32 *)(m + 0x18) < 2.0f) {
        func_L39_0066C470(uid);
    }
    if (*(u8 **)(v + 0x270) != 0) {
        u8 *t = *(u8 **)(v + 0x270);
        *(s32 *)(t + 0x98) = *(s32 *)(*(u8 **)(t + 0x24) + 0x10);
    }
}
/* localdecomp:end func_L40_0040BCF0 */

/* localdecomp:start func_L40_0040C6F0 */
extern u8 D_L40_00249FC0[];
extern s32 func_L40_0040CA88(u8 *m);
extern void func_003C6FB0(u8 *m, s32 *a, s32 *b, s32 *c);
extern f32 func_L01_0040E548(void *a, void *b);
extern void func_L01_004472C0(u8 *m);
extern void func_L01_0043B9E8(u8 *m, s32 a, s32 b, s32 c);
extern void func_003C2F58(u8 *m, s32 a1, void *pos);
extern void func_0038D308(void *matrix, void *rot);
extern s32 func_L40_0040CF88(u8 *m, u8 *mb, s32 uid, s32 a3, s32 torso_hits);
extern void func_L40_0040B1D0(s32 a0, u8 *m);

/* The guber's update: the state-0 init on the first frame, then the torso follows the legs. */
s32 func_L40_0040C6F0(u8 *m, s32 a1) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 j0;
    s32 j1;
    s32 j2;

    if (*(u8 *)(m + 0x20) == 0) {
        func_L40_0040CA88(m);
        *(vu0_v4 *)(v + 0x350) = *(vu0_v4 *)(m + 0x10);
    }
    func_003C6FB0(m, &j0, &j1, &j2);
    if (v != 0 && *(u8 **)(v + 0x270) != 0) {
        if (*(u8 *)(m + 0x31) != 0 && func_L01_0040E548(D_L40_00249FC0, m + 0x10) < 256.0f) {
            func_L01_004472C0(m);
            *(u8 *)(m + 0x6F) = 0xF;
        }
        if (*(u8 *)(*(u8 **)(v + 0x270) + 0x31) != 0 && func_L01_0040E548(D_L40_00249FC0, *(u8 **)(v + 0x270) + 0x10) < 256.0f) {
            func_L01_004472C0(*(u8 **)(v + 0x270));
            *(u8 *)(*(u8 **)(v + 0x270) + 0x6F) = 0xF;
        }
        func_L01_0043B9E8(*(u8 **)(v + 0x270), j0, j1, j2);
        func_003C2F58(m, 0, *(u8 **)(v + 0x270) + 0x10);
        *(f32 *)(*(u8 **)(v + 0x270) + 0xF0) = *(f32 *)(m + 0xF0);
        *(f32 *)(*(u8 **)(v + 0x270) + 0xF4) = *(f32 *)(m + 0xF4);
        func_0038D308(*(u8 **)(v + 0x270) + 0xC0, *(u8 **)(v + 0x270) + 0xF0);
    }
    func_L40_0040CF88(m, v + 0x160, a1, 0, 0);
    func_L40_0040B1D0(a1, m);
    return 0;
}
/* localdecomp:end func_L40_0040C6F0 */

/* localdecomp:start func_L40_0040C878 */
extern s32 func_L39_005BE900(vu0_v4 *sphere, s32 a1, f32 dist);
extern s32 func_L39_005B4398(s32 n);
extern f32 func_L39_005B4410(f32 lo, f32 hi);
extern f32 func_L39_005B44C8(void);
extern f32 func_0038D098(f32 a);
extern f32 func_0038D0B0(f32 a);
extern void func_0038CE20(void *d, void *s, f32 k);
extern void func_L39_005CDE78(vu0_v4 *pos, vu0_v4 *vel, u32 colour, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f);

/* 60 sparks around `pos` (when it is in view). */
void func_L40_0040C878(vu0_v4 *pos) {
    vu0_v4 p;
    vu0_v4 off;
    vu0_v4 vel;
    s32 i;
    s32 up;
    f32 r;
    f32 a;

    p = *pos;
    p.w = 1.5f;
    if (func_L39_005BE900(&p, 0, 48.0f) == -1) {
        return;
    }
    for (i = 0; i < 60; i++) {
        up = func_L39_005B4398(2);
        r = func_L39_005B4410(0.0f, 0.4f);
        a = func_L39_005B44C8();
        off.x = func_0038D098(a) * r;
        off.y = func_0038D0B0(a) * r;
        off.z = 0.0f;
        off.z += func_L39_005B4410(0.3f, -0.3f);
        vec_add_ba(&off, &off, pos);
        vel = (vu0_v4){ 0.0f, 0.0f, func_L39_005B4410(0.5f, 1.5f) * 0.0200000014f, 0.0f };
        vel.z += (0.4f - r) * 0.0600000024f / 0.4f;
        if (up) {
            off.z += 2.0f;
            func_0038CE20(&vel, &vel, -1.0f);
        }
        func_L39_005CDE78(&off, &vel, 0x8020C040, 0x32, func_L39_005B4398(0xFF) & 0xFF, 0, 0x40, 0, 1.0f);
    }
}
/* localdecomp:end func_L40_0040C878 */

/* localdecomp:start func_L40_0040CA88 */
__asm__(".extern D_L40_00241120, 16");
extern s32 *D_L40_00241120;
extern s32 func_L01_0044E7D8(u8 *m);
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern u8 *func_003C24B0(s32 cls, s32 a1);
extern void func_L01_00456160(u8 *torso, u8 *m);
extern void func_L01_004450F0(u8 *m, s32 a1, s32 a2);

/* The Ranger legs' state-0 init: home position, movement and turn settings, the torso (spawned
   again if it is gone), and the sparks of its arrival. */
s32 func_L40_0040CA88(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *t;

    *(vu0_v4 *)(v + 0x240) = *(vu0_v4 *)(m + 0x10);
    *(f32 *)(v + 0x240) = *(f32 *)(m + 0x10);
    *(f32 *)(v + 0x244) = *(f32 *)(m + 0x14);
    *(f32 *)(v + 0x248) = *(f32 *)(m + 0x18);
    *(s32 *)(v + 0x2A4) = 0;
    *(s32 *)(v + 0x2A8) = func_L01_0044E7D8(m);
    *(u8 *)(v + 0x170) = 4;
    *(f32 *)(v + 0x19C) = 0.15f;
    *(u8 *)(v + 0x1A8) = 1;
    *(u8 *)(v + 0x1D7) = 1;
    *(u8 *)(v + 0x167) = 0x80;
    *(s16 *)(v + 0x16C) = 4;
    *(s16 *)(v + 0x16E) = 0xF;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x194) = 0.5f;
    *(s32 *)(v + 0x1DC) = -1;
    *(u8 *)(v + 0x168) = 0;
    *(u8 *)(v + 0x169) = 0;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 20;
        *(f32 *)(v + 0x30) = 20.0f;
    }
    *(f32 *)(v + 0x40) = 2.0f;
    *(f32 *)(v + 0x288) = *(f32 *)(m + 0xF8);
    *(f32 *)(v + 0x70) = 0.7f;
    *(f32 *)(v + 0x74) = 0.5f;
    *(f32 *)(v + 0x78) = 1.0f;
    *(f32 *)(v + 0x7C) = 1.0f;
    *(f32 *)(v + 0x80) = 1.9f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00392f;
    *(s32 *)(v + 0xAC) = -1;
    *(f32 *)(v + 0xA4) = 0.05f;
    func_L01_0045BD78(m, 0.0024f, 0.120000005f, 0.0100530973f, 0.50265485f);
    *(u8 *)(m + 0x30) = 0xFF;
    *(s16 *)(m + 0x32) = 0xFF;
    t = *(u8 **)(v + 0x270);
    if (t == 0 || *(s16 *)(t + 0xAA) != 0x109E || *(u8 *)(t + 0x20) == 0xFE || *(u8 *)(t + 0x20) == 0xFF) {
        *(u8 **)(v + 0x270) = func_003C24B0(0x109E, 0x80);
        func_L01_00456160(*(u8 **)(v + 0x270), m);
    }
    func_003C2F58(m, 0, *(u8 **)(v + 0x270) + 0x10);
    if (*D_L40_00241120 >= 2) {
        *(u8 *)(m + 0x62) = 1;
        *(u8 *)(*(u8 **)(v + 0x270) + 0x62) = 1;
    }
    *(u8 *)(*(u8 **)(v + 0x270) + 0x30) = 0xFF;
    *(s16 *)(*(u8 **)(v + 0x270) + 0x32) = 0xFF;
    *(s32 *)(v + 0x298) = 0;
    *(s32 *)(v + 0x294) = 0x10001;
    *(s32 *)(v + 0x340) = -1;
    func_L01_004450F0(m, 1, 0);
    func_L40_0040CEF8(m, 0, 0, 0);
    *(f32 *)(v + 0x278) = -10.0f;
    *(u16 *)(m + 0x34) &= 0xFFBE;
    *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
    *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
    if (*(u8 **)(v + 0x270) != 0) {
        *(u16 *)(*(u8 **)(v + 0x270) + 0x34) &= 0xFFBE;
        *(u16 *)(*(u8 **)(v + 0x270) + 0x34) |= *(u16 *)(*(u8 **)(*(u8 **)(v + 0x270) + 0x24) + 0x44) & 0x1000;
        *(s32 *)(*(u8 **)(v + 0x270) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(v + 0x270) + 0x24) + 0x10);
    }
    func_L40_0040C878((vu0_v4 *)(m + 0x10));
    return 0;
}
/* localdecomp:end func_L40_0040CA88 */

/* localdecomp:start func_L40_0040CD80 */
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 D_L40_00242930[] __attribute__((section(".sdata")));
extern void func_003C2880(void *);
extern void func_L39_005F2FF8(void *, s32);
void func_L40_0040CD80(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);

    func_L39_005F3488(3, 0, m, 0x109E);
    func_L01_00451FE0(m, 0xF, D_L40_00242930, 3.0f, 7.0f, 4.0f, 7.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    func_L01_00451FE0(*(u8 **)(v + 0x270), 0xF, D_L40_00242930, 3.0f, 7.0f, 4.0f, 7.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    func_003C2880(*(u8 **)(v + 0x270));
    *(s32 *)(v + 0x270) = 0;
    func_L01_004450F0(m, 0x25, -1);
    *(s32 *)(m + 0x98) = 0;
    *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
    func_L39_005F2FF8(m, 1);
}
/* localdecomp:end func_L40_0040CD80 */

/* localdecomp:start func_L40_0040CEF8 */
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L40_0040CEF8(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *v = *(u8 **)(a0 + 104);
    if (a0[67] != a1) {
        func_003C3A10(a0, a1, a2, a3);
    }
    a0 = *(u8 **)(v + 624);
    if (a0[67] != a1) {
        func_003C3A10(a0, a1, a2, a3);
    }
}
/* localdecomp:end func_L40_0040CEF8 */

/* localdecomp:start func_L40_0040CF68 */
void func_L40_0040CF68(void *arg0) {
    u16 temp_v1;

    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L40_0040CF68 */

INCLUDE_ASM("asm/levels", func_L40_0040CF88);

INCLUDE_ASM("asm/levels", func_L40_0040D310);

/* localdecomp:start func_L40_0040D4C0 */
extern s32 func_L01_0045B968(u8 *m, u8 *w);
extern s32 func_L01_0045BAC0(u8 *m, u8 *w);
extern f32 func_0038CED8(void *v);
extern void func_0038CFB8(void *d, void *s, f32 len);
extern void func_0038CAD0(void *p);

/* Move the moby by its walker's velocity (+0xA0), push it out of what it touches (up to 8 tries)
   and keep the velocity it really moved by, clamped to the walker's speed. */
void func_L40_0040D4C0(u8 *m, u8 *w, vu0_v4 *prev, void *a3) {
    vu0_v4 start;
    s32 moved;
    s32 i;
    s32 r;
    f32 len;
    f32 z;

    if ((*(long *)(w + 0x38) & 0x404) == 4) {
        *(s32 *)(w + 0xA8) = 0;
    }
    vec_add_ab(m + 0x10, m + 0x10, w + 0xA0);
    moved = 0;
    i = 0;
    start = *(vu0_v4 *)(m + 0x10);
    *(s32 *)(w + 0x84) = 0;
    qzero(w + 0x60);
    for (; i < 8; i++) {
        r = func_L01_0045B968(m, w);
        r |= func_L01_0045BAC0(m, w);
        moved |= r;
        if (r == 0) {
            break;
        }
    }
    if (moved) {
        vec_sub_ab(w + 0xA0, m + 0x10, prev);
        len = func_0038CED8(w + 0xA0);
        if (len > *(f32 *)(w + 0xB0)) {
            func_0038CFB8(w + 0xA0, w + 0xA0, *(f32 *)(w + 0xB0));
        } else {
            *(f32 *)(w + 0xB0) = len;
        }
        z = *(f32 *)(m + 0x18);
        if (z <= *(f32 *)(w + 0x90)) {
            if (z < prev->z) {
                *(f32 *)(m + 0x18) = prev->z;
            }
            if (*(f32 *)(w + 0xA8) < 0.0f) {
                *(f32 *)(w + 0xA8) = 0.0f;
            }
        }
        if (*(f32 *)(w + 0xB0) < *(f32 *)(w + 0x28) * 0.5f) {
            *(s32 *)(w + 0x80) += 1;
        } else {
            func_0038CAD0(w + 0x80);
        }
    } else {
        func_0038CAD0(w + 0x80);
    }
    vec_sub_ab(w + 0x70, m + 0x10, &start);
}
/* localdecomp:end func_L40_0040D4C0 */

INCLUDE_ASM("asm/levels", func_L40_0040D678);

/* localdecomp:start func_L40_0040D7D0 */
extern f32 func_0038CE68(void *a, void *b);
extern void func_003C4360(void *p, f32 target, f32 a, f32 b, f32 c);

/* Steer the walker towards `yaw` and the path (pVar+0x310), and keep it on the ground. */
void func_L40_0040D7D0(u8 *m, u8 *w, void *target, f32 yaw, vu0_v4 *a, vu0_v4 *b) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 z;
    vu0_v4 d;
    f32 diff;
    f32 dist;
    f32 h;

    if (!(*(s32 *)(w + 0x38) & 0x10)) {
        func_L01_00448890(m + 0xF8, yaw, *(f32 *)(w + 0x14), *(f32 *)(w + 0x18), *(f32 *)(w + 0x1C), w + 0xB4, 0);
    }
    diff = func_0038DBA0(*(f32 *)(m + 0xF8), yaw);
    if (!(*(s32 *)(w + 0x38) & 0x10) && diff > *(f32 *)(w + 0x30)) {
        qzero(&z);
        if (diff - *(f32 *)(w + 0x30) > *(f32 *)(w + 0xB4) * 25.0f) {
            *(s32 *)(w + 0x9C) |= 2;
        }
    }
    dist = func_0038CF38(m + 0x10, v + 0x330);
    vec_sub_ba(&d, v + 0x310, m + 0x10);
    *(s32 *)&d.z = 0;
    func_0038CE20(&d, &d, 0.0480000004f);
    vec_sub_ab(&d, &d, v + 0x110);
    if (dist > 1.29999995f) {
        func_0038CE20(&d, &d, 0.187199995f);
    } else {
        func_0038CE20(&d, &d, 0.360000014f);
    }
    d.z *= 0.879999995f;
    vec_add_ab(v + 0x110, v + 0x110, &d);
    if (*(s32 *)(w + 0x38) & 0x400) {
        *(f32 *)(w + 0xB0) = func_0038CEA8(w + 0xA0);
    } else {
        *(f32 *)(w + 0xB0) = func_0038CED8(w + 0xA0);
    }
    if (*(s32 *)(w + 0x38) & 4) {
        return;
    }
    if (*(f32 *)(w + 0x90) < *(f32 *)(m + 0x18)) {
        if (*(s16 *)(w + 0xC2) < 2) {
            if (*(f32 *)(m + 0x18) - *(f32 *)(w + 0x90) < 0.150000006f) {
                if (func_0038D160(*(f32 *)(w + 0x58), func_0038CED8(w + 0x50)) > 0.0872664601f) {
                    if (-func_0038CE68(w + 0xA0, w + 0x50) < *(f32 *)(w + 0xA8)) {
                        *(f32 *)(w + 0xA8) = -func_0038CE68(w + 0xA0, w + 0x50);
                    }
                }
            }
        }
        *(f32 *)(w + 0xA8) -= *(f32 *)(w + 0x2C);
        if (*(s16 *)(w + 0xC0) == 0) {
            *(s32 *)(w + 0x94) |= 0x20;
        }
    } else {
        h = *(f32 *)(w + 0x90) - *(f32 *)(m + 0x18);
        if (h < *(f32 *)(w + 0xA8)) {
            *(f32 *)(w + 0xA8) = h;
        } else if (*(f32 *)(w + 0xA8) < 0.0f) {
            *(f32 *)(w + 0xA8) = 0.0f;
        }
        func_003C4360(w + 0xA8, *(f32 *)(w + 0x90) - *(f32 *)(m + 0x18), 0.0160000008f, 0.0160000008f, 1.0f);
    }
}
/* localdecomp:end func_L40_0040D7D0 */
