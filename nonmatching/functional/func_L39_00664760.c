/* functional: medium. Per-frame update of a multiplayer-menu player slot's network input record: pulls the queued record from the owner's list, replays its movement vector and command through func_L39_00637EC8 / the vtable, and bumps the frame counters. Control flow follows retail with gotos; the repeated keyed-table decodes of the protected command byte (g+0x19E4/0x19E6/0x19E7, table D_L39_004997E0) are one helper (0 when the key byte is 0, as retail). Medium because the long command-code ladder (0x76, 0x37, 0x16, 0x2B, 0x8F, 0x8E, 0x22, 0x31) was transcribed by hand and has no coverage evidence. */
#include "vu0.h"

extern s32 D_L39_0024112C;
extern u8 D_L39_004997E0[];
extern void func_0038CC88(void *, void *, s32);
extern void func_L39_005BA418(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern void func_L39_00633308(void *, s32, f32, f32, f32);
extern s32 func_L02_003E71A8(void *, void *);
extern void func_0019B478(void *);
extern void func_L39_00637EC8(void *, void *, void *, s32, s32, s32, s32);

static u32 n64_dec(u8 *key) {
    u32 b[2];
    u32 c = key[0];
    u32 base;
    s32 k;
    if (c == 0) return 0;
    base = ((u32)key - c) & 7;
    for (k = 0; k < 8; k++) {
        ((u8 *)b)[k] = D_L39_004997E0[c + 1 + ((base + k * 5) & 7) * 255];
    }
    b[0] ^= (u32)key;
    b[1] ^= b[0];
    return b[1];
}

void func_L39_00664760(u8 *g) {
    f32 v0[4];
    f32 v10[4];
    f32 v30[4];
    u8 w60[4];
    u8 *p;
    u8 *rec;
    u8 *n;
    u8 *obj30;
    s32 s64;
    s32 t;
    u32 w;
    u32 c20;
    u8 flag9;
    f32 f12;
    f32 d;

    p = *(u8 **)(g + 0x2558);
    rec = 0;
    t = *(s32 *)(p + 0xC44);
    if (t != 0) {
        if (p[0xC42] == 0 || !((D_L39_0024112C - *(s32 *)(p + 0xC3C)) < (s8)p[0xC41])) {
            rec = (u8 *)t;
        }
    }
    if (rec == 0) return;
    s64 = (*(u8 **)(g + 0x2558))[0xC31];
    if (s64 != 2) goto L5234;

    *(vu0_q *)(g + 0x4D40) = *(vu0_q *)(g + 0xA0);
    *(vu0_q *)(g + 0x4D70) = *(vu0_q *)(g + 0xB0);
    g[0x4D24] = (u8)n64_dec(g + 0x19E4);
    *(s32 *)(g + 0x4D88) = rec[0x16];
    n = 0;
    if (*(s32 *)(*(u8 **)(g + 0x2558) + 0xC44) != 0) {
        n = *(u8 **)(*(u8 **)(*(u8 **)(g + 0x2558) + 0xC44) + 0x98);
    }
    if (n == 0) goto L5234;
    if (n[0x16] != (u8)(rec[0x16] + 1)) goto L5234;
    v0[3] = 0;
    if (*(u32 *)(n + 0x14) & 0x1000000) {
        c20 = n[0x6C];
        func_0038CC88(v0, n + 0x6D, 0xC);
        w = n64_dec(g + 0x19E4);
        if (w == c20) goto L4F58;
        if (c20 != 0) {
            if ((n64_dec(g + 0x19E6) ^ 0x14) != 0) goto L4F58;
            if (c20 == 0x76) goto L4F58;
        }
        if ((n64_dec(g + 0x19E4) ^ 0x37) == 0) goto L4F58;
        if (c20 == 0x37) goto L4F58;
        if ((n64_dec(g + 0x19E4) ^ 0x66) == 0) goto L4F58;
        if (c20 == 0x16) goto L4F58;
        if (c20 == 0x2B) goto L4F58;
        if ((n64_dec(g + 0x19E4) ^ 0x8F) == 0) goto L4F58;
        if ((n64_dec(g + 0x19E4) ^ 0x8E) == 0) goto L4F58;
        if ((n64_dec(g + 0x19E4) ^ 0x22) == 0) goto L4F58;
        if ((n64_dec(g + 0x19E4) ^ 0x31) == 0) {
            if (*(s32 *)(g + 0x2F0) < 0x1F5) goto L4F58;
        }
        flag9 = 0;
        obj30 = *(u8 **)(g + 0x2530);
        if (obj30 != 0 && obj30[0x27B] != 0) {
            if ((n64_dec(g + 0x19E4) ^ 0x31) == 0) flag9 = 1;
        }
        if (flag9) goto L4F58;
        if (func_L39_00636F30(g, 0x8F, 0xA) != 0) goto L4F58;
        if ((n64_dec(g + 0x19E4) ^ 0x16) == 0 && *(s32 *)(g + 0x2F0) < 0x21) goto L4F58;
        if ((n64_dec(g + 0x19E6) ^ 0x14) == 0 && *(s32 *)(g + 0x2F0) < 0xB0) goto L4F58;
        (*(void (**)(void *, u32, s32, s32, s32))(*(u8 **)(g + 0x14) + 0x34))(g, c20, 1, 1, 1);
    } else {
        v0[0] = (f32)*(u16 *)(n + 0x10) * 0.015625f;
        v0[1] = (f32)*(u16 *)(n + 0x12) * 0.015625f;
        v0[2] = (f32)*(u16 *)(n + 0x14) * 0.015625f;
        goto L50C4;
    }
L4F58:
    func_0038CC88(w60, n + 0x68, 4);
    func_L39_005BA418(v10, w60);
    v10[3] = 0;
    w = n64_dec(g + 0x19E6);
    if ((w ^ 0xE) != 0) {
        d = func_0038DBA0(*(f32 *)(g + 0xB8), v10[2]);
        if (229.1831f < d) {
            *(f32 *)(g + 0xFD0) = v10[2];
            func_0038D308(v30, v10);
            *(vu0_q *)(g + 0xFC0) = *(vu0_q *)v30;
            func_L39_00633308(g, 0, 0.288f, 0.648f, 0.4886922f);
        }
    }
L50C4:
L50C8:
    f12 = 0.3f;
    if (*(u32 *)(n + 0x14) & 0x1000000) f12 = 0.2f;
    vec_sub_ab(g + 0x4D50, g + 0x4D30, v0);
    if ((n64_dec(g + 0x19E6) ^ 0xE) != 0) {
        if (func_L02_003E71A8(g + 0xA0, v0) == 0) {
            g[0x4D23] = 4;
            vec_sub_ab(g + 0x4D50, g + 0x4D30, g + 0x4D40);
            goto L5238;
        }
        if ((n64_dec(g + 0x19E6) ^ 0xE) != 0) g[0x4D23] = 0;
    } else {
        if ((n64_dec(g + 0x19E6) ^ 0xE) != 0) g[0x4D23] = 0;
    }
    goto L5234;
L5234:
L5238:
    if (s64 < (s32)g[0x255F]) goto L54EC;
    if (g[0x255E] != rec[0x16]) goto L54EC;
    w = n64_dec(g + 0x19E4);
    if (w == g[0x255D]) goto L54DC;
    v0[0] = *(f32 *)(g + 0x2560);
    v0[1] = *(f32 *)(g + 0x2564);
    v0[2] = *(f32 *)(g + 0x2568);
    v0[3] = 0;
    v10[0] = *(f32 *)(g + 0x256C);
    v10[1] = *(f32 *)(g + 0x2570);
    v10[2] = *(f32 *)(g + 0x2574);
    v10[3] = 0;
    if (g[0x255D] == 0x76) goto L54DC;
    if (g[0x255D] == 0x39) {
        if ((n64_dec(g + 0x19E4) ^ 0x8F) == 0) goto L54E0;
        if ((n64_dec(g + 0x19E4) ^ 0x39) == 0) goto L54DC;
        if ((n64_dec(g + 0x19E7) ^ 0x8F) == 0) goto L54E0;
    }
    func_L39_00637EC8(g, v0, v10, g[0x255D], 0, 0, 0);
L54DC:
    g[0x255D] = 0;
    g[0x255F] = 0xFF;
    goto L54EC;
L54E0:
    g[0x255D] = 0;
    g[0x255F] = 0xFF;
L54EC:
    p = *(u8 **)(g + 0x2558);
    p[0xC31] = p[0xC31] + 1;
    p = *(u8 **)(g + 0x2558);
    if (p[0xC31] != 4) return;
    func_0019B478(p);
    g[0x4D22] = g[0x4D22] + 1;
    if (g[0x4D22] >= 0xB) return;
    g[0x4D20] = 1;
}
