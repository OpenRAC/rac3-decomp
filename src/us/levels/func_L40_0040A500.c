#include "common.h"

/* NTSC-U counterpart of func_L40_0040ABB8 (src/levels/shared/L40_0040A4D0.c) */
#include "vu0.h"
extern f32 func_00388800(void *a, void *b);

/* localdecomp:start func_L40_0040A500 */
/* The game mode where state 1 reads it, through $gp (the other read, through lui, is the
   plain name; func_L40_0040D678's near miss says why there are two). */
__asm__(".extern D_L40_0024145C_b, 4");
extern s32 D_L40_0024145C_b;
extern s32 D_L40_0024145C[] __attribute__((section(".sdata")));
extern s32 *D_L40_0028FF00[]; /* the map's paths: a count, then 16-byte points from +0x10 */
extern s32 D_001A5F78[];
extern s32 func_L40_0053B8F8(u8 *m, s32 team, s32 a2, f32 range, f32 b, f32 c, void *a3);
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);
extern s32 func_L40_0053BEB0(s32 uid, vu0_v4 *pos, s32 a2, s32 a3);
extern s32 func_L39_005B2498(s32 n);
extern s32 func_L39_005B24C8(s32 lo, s32 hi);

/* The Ranger class's network think callback: find a target (state 1) or keep it (state 2), and
   step along the path, telling the other consoles. */
void func_L40_0040A500(u8 *m) {
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
        if (D_L40_0024145C_b == 0x2D || D_L40_0024145C_b == 0x37) {
            r = 10.0f;
        }
        t = func_L40_0053B8F8(m, *(s32 *)(v + 0x2F0), 0, *(f32 *)(v + 0x2C0), -1.0f, r, *(void **)(v + 0x2A0));
        if (t != -1) {
            u8 *msg1;
            u8 *p1;

            msg1 = func_L39_006699B0();
            if (msg1 == 0) {
                return;
            }
            p1 = msg1 + func_L39_00669978(1, uid, D_001A5F78[0] + 500, 0, msg1);
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
        path = D_L40_0028FF00[*(s32 *)(v + 0x2C8)];
        if (*(s32 *)(v + 0x370) != -1 && !(func_00388800(m + 0x10, (u8 *)path + 0x10 + *(s32 *)(v + 0x370) * 16) < 1.0f)) {
            return;
        }
        if (func_L39_005B2498(0x63)) {
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
        msg = func_L39_006699B0();
        if (msg == 0) {
            return;
        }
        p = msg + func_L39_00669978(1, uid, D_001A5F78[0] + 500, 3, msg);
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
            path = D_L40_0028FF00[*(s32 *)(v + 0x2C8)];
        }
        r = -1.0f;
        if (D_L40_0024145C[0] == 0x2D || D_L40_0024145C[0] == 0x37) {
            r = 10.0f;
        }
        t = func_L40_0053B8F8(m, *(s32 *)(v + 0x2F0), 0, *(f32 *)(v + 0x2C0) + 7.0f, -1.0f, r, *(void **)(v + 0x2A0));
        if (*(s32 *)(v + 0x2B4) != t) {
            msg = func_L39_006699B0();
            if (msg == 0) {
                return;
            }
            p = msg + func_L39_00669978(1, uid, D_001A5F78[0] + 500, 0, msg);
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
        if (*(s32 *)(v + 0x2C8) != -1 && path != 0 && func_00388800(m + 0x10, (u8 *)path + 0x10 + idx * 16) < 0.5f && !func_L39_005B2498(0x63)) {
            best = 99999.0f;
            if (!func_L40_0053BEB0(*(s32 *)(v + 0x2B4), &pos, -1, 1)) {
                return;
            }
            for (i = 0; i < path[0]; i++) {
                d = func_00388800(&pos, (u8 *)path + 0x10 + i * 16);
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
        msg = func_L39_006699B0();
        if (msg == 0) {
            return;
        }
        delay = func_L39_005B24C8(0, 300) + 500;
        p = msg + func_L39_00669978(1, uid, D_001A5F78[0] + delay, 2, msg);
        *(s32 *)p = idx;
        p += 4;
        *(s32 *)msg = p - msg;
        return;
    }
    }
}
/* localdecomp:end func_L40_0040A500 */
