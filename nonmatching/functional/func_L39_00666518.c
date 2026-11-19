/* functional: high. Spawns/initialises one multiplayer-menu player slot object; every read, write and call in retail order. The four protected-variable stores (counter touch + keyed 8-byte scramble into D_L39_004997E0/D_L39_00483A00) and the one decode are written out as retail does. Differs from retail only in scheduling and register use. */
#include "vu0.h"

extern u8 D_L39_00310900[];
extern u8 D_L39_0047B338[];
extern u8 D_L39_0047A6C0[];
extern u8 D_L39_0049C750[];
extern u8 D_L39_0049C890[];
extern u8 D_L39_002461B0[];
extern u8 D_L39_004997E0[];
extern u8 D_L39_00483A00[];
extern u32 D_L39_0024B9C8;
extern u32 D_L39_0024CE20[];
extern u8 *D_00241640;
extern u8 D_001A58D0[];
extern u8 D_001A5930[];
extern u8 D_001A5990[];
extern void func_L39_00620BE8(void);
extern void func_L39_00662510(void *);
extern s32 func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_001206F4(void *, void *);
extern void func_L39_0055D598(void *);
extern void func_003C7C38(void *);
extern void func_L39_0061C1E0(u8 *, s32);
extern void func_L39_0061ECE0(void *, void *, s32);
extern void func_0038D308(void *, void *);
extern void func_0038D328(void *, void *);
extern void func_L39_00632180(u8 *, f32 *, s32, f32, f32, f32);
extern void func_0038CC88(void *, void *, s32);
extern void func_L01_00412E70(void *, void *, s32, f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L39_00673A80(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L39_00666518(u8 *a) {
    u32 b10[4];  /* sp+0x00..0x0F: vector, then key buffer at +0x10 below */
    f32 vec[4];
    u32 kb[2];   /* 8-byte scramble buffer (sp+0x10) */
    u32 kc[2];   /* second scramble buffer (sp+0x20) */
    u8 *g;
    u8 *o;
    u8 *x;
    u8 *a4;
    s32 idx;
    s32 i;
    s32 k;
    u32 c;
    u32 word;
    u32 base;
    s32 v;
    f32 f1;
    f32 f0;
    s16 h;

    func_L39_00620BE8();
    a4 = *(u8 **)(a + 4);
    idx = *(s32 *)(a4 + 0x54);
    g = D_L39_00310900 + idx * 0x4DC0;
    func_L39_00662510(g);
    *(u8 **)(g + 0x14) = D_L39_0047B338;
    o = (u8 *)func_003C24B0(*(s32 *)(D_L39_0047A6C0 + *(s16 *)(D_00241640 + idx * 2 + 0xC0) * 4), 0x80);
    func_L01_00456160(o, 0);
    o[0x7E] = (u8)(((o[0x7E] | 0x80) & 0x8F) | (*(s16 *)(D_00241640 + idx * 2 + 0xD0) << 4));
    a4 = *(u8 **)(a + 4);
    vec[0] = *(f32 *)(a4 + 0x10);
    vec[1] = *(f32 *)(a4 + 0x14);
    vec[2] = *(f32 *)(a4 + 0x18);
    vec[3] = 0;
    (*(void (**)(void *, void *, void *, void *, s32))(*(u8 **)(g + 0x14) + 0x24))(g, o, a4, vec, idx);

    a4 = *(u8 **)(a + 4);
    g[0x255F] = 0xFF;
    g[0x251A] = a4[0x3C];
    *(u8 **)(g + 0x2520) = D_L39_0049C750 + a4[0x3C] * 0x70;
    *(s32 *)g = *(s32 *)(a4 + 0x38);
    *(s32 *)(g + 0x2548) = *(s32 *)(a4 + 0x40);
    a4 = *(u8 **)(a + 4);
    f0 = *(f32 *)(a4 + 0x44);

    /* protected store 1: key at g+0x2476, value f0 */
    x = g + 0x2476;
    if (x[0] == 0) {
        D_L39_004997E0[0] = D_L39_004997E0[0] + 1;
        x[0] = D_L39_004997E0[0];
    } else {
        u8 t = x[0];
        x[0] = D_L39_004997E0[1];
        D_L39_004997E0[1] = t;
    }
    word = ((u32 *)D_L39_004997E0)[((u32)x * D_L39_0024B9C8) % 510];
    *(f32 *)&kb[1] = f0;
    kb[1] ^= word;
    kb[0] = (u32)x ^ word;
    c = x[0];
    base = ((u32)x - c) & 7;
    for (k = 0; k < 8; k++) {
        D_L39_004997E0[c + 1 + ((base + k * 5) & 7) * 255] = ((u8 *)kb)[k];
    }

    /* protected store 2: key at g+0x2554, same value */
    a4 = *(u8 **)(a + 4);
    f0 = *(f32 *)(a4 + 0x44);
    x = g + 0x2554;
    if (x[0] == 0) {
        D_L39_004997E0[0] = D_L39_004997E0[0] + 1;
        x[0] = D_L39_004997E0[0];
    } else {
        u8 t = x[0];
        x[0] = D_L39_004997E0[1];
        D_L39_004997E0[1] = t;
    }
    word = ((u32 *)D_L39_004997E0)[((u32)x * D_L39_0024B9C8) % 510];
    *(f32 *)&kb[1] = f0;
    kb[1] ^= word;
    kb[0] = (u32)x ^ word;
    c = x[0];
    base = ((u32)x - c) & 7;
    for (k = 0; k < 8; k++) {
        D_L39_004997E0[c + 1 + ((base + k * 5) & 7) * 255] = ((u8 *)kb)[k];
    }

    for (i = 0; i < 3; i++) {
        *(s32 *)(D_001A58D0 + idx * 4 + i * 32) = *(s32 *)(*(u8 **)(a + 4) + 0x58 + i * 4);
        *(s32 *)(D_001A5930 + idx * 4 + i * 32) = *(s32 *)(*(u8 **)(a + 4) + 0x64 + i * 4);
        *(s32 *)(D_001A5990 + idx * 4 + i * 32) = *(s32 *)(*(u8 **)(a + 4) + 0x70 + i * 4);
    }
    func_001206F4(a + 0x1B0, D_00241640 + idx * 16);
    func_L39_0055D598(g);
    o = *(u8 **)(g + 0x2524);
    *(s32 *)(g + 0x4D84) = 0;
    if (o != 0) {
        u8 *p68 = *(u8 **)(o + 0x68);
        *(u8 **)p68 = p68 + 0x30;
        x = g + 0x2476;
        if (x[0] != 0) {
            c = x[0];
            base = ((u32)x - c) & 7;
            for (k = 0; k < 8; k++) {
                ((u8 *)kb)[k] = D_L39_004997E0[c + 1 + ((base + k * 5) & 7) * 255];
            }
            kb[0] ^= (u32)x;
            kb[1] ^= kb[0];
            f1 = *(f32 *)&kb[1];
        } else {
            f1 = 0.0f;
        }
        o = *(u8 **)(g + 0x2524);
        p68 = *(u8 **)(o + 0x68);
        *(f32 *)(p68 + 0x30) = f1;
        p68 = *(u8 **)(*(u8 **)(g + 0x2524) + 0x68);
        *(s16 *)(p68 + 0x34) = 0xF;
        p68 = *(u8 **)(*(u8 **)(g + 0x2524) + 0x68);
        *(f32 *)(p68 + 0x40) = 0.65f;
        p68 = *(u8 **)(*(u8 **)(g + 0x2524) + 0x68);
        p68[0x38] = g[0x2548];
        p68 = *(u8 **)(*(u8 **)(g + 0x2524) + 0x68);
        p68[0x3E] = 1;
        p68 = *(u8 **)(*(u8 **)(g + 0x2524) + 0x68);
        *(u8 **)(p68 + 0x70) = g;
        o = *(u8 **)(g + 0x2524);
        *(u16 *)(o + 0x34) |= 0x1020;
        o = *(u8 **)(g + 0x2524);
        *(u16 *)(o + 0x34) |= 0x46;
        o = *(u8 **)(g + 0x2524);
        o[0x7E] |= 2;
        o = *(u8 **)(g + 0x2524);
        (*(u8 **)(o + 0x24))[0x46] = 5;
        o = *(u8 **)(g + 0x2524);
        o[0x62] = 0;
        o = *(u8 **)(g + 0x2524);
        *(vu0_q *)(o + 0x10) = *(vu0_q *)(g + 0xA0);
        o = *(u8 **)(g + 0x2524);
        *(vu0_q *)(o + 0xF0) = *(vu0_q *)(g + 0xB0);
        func_003C7C38(*(void **)(g + 0x2524));
    }
    *(s32 *)(g + 0x234C) = 0;
    *(s32 *)(g + 0x2348) = 0;
    v = g[0x251A];
    *(f32 *)(g + 0x1F4) = *(f32 *)(D_L39_0049C750 + v * 0x70 + 0x10);
    *(f32 *)(g + 0x1E0) = *(f32 *)(D_L39_0049C750 + v * 0x70 + 0x14);
    *(f32 *)(g + 0x1E4) = *(f32 *)(D_L39_0049C750 + v * 0x70 + 0x18);
    func_L39_0061C1E0(*(u8 **)(g + 0x2524), *(s32 *)(g + 0x2544));
    if (*(s32 *)(g + 0x2548) == 0) {
        o = *(u8 **)(g + 0x2524);
        o[0xBE] |= 0x10;
        o = *(u8 **)(g + 0x2524);
        o[0xBE] &= 0xF7;
    } else if (*(s32 *)(g + 0x2548) == 1) {
        o = *(u8 **)(g + 0x2524);
        o[0xBE] |= 0x8;
        o = *(u8 **)(g + 0x2524);
        o[0xBE] &= 0xEF;
    }
    D_L39_0024CE20[idx] = (u32)g;
    *(u8 **)(g + 0x2558) = a;
    a4 = *(u8 **)(a + 4);
    vec[0] = *(f32 *)(a4 + 0);
    vec[1] = *(f32 *)(a4 + 4);
    vec[2] = *(f32 *)(a4 + 8);
    *(u8 **)(a + 0x100) = D_L39_002461B0 + g[0x251A] * 0x28;
    func_L39_0061ECE0(a + 0x10, vec, *(s32 *)(a4 + 0x1C));
    *(vu0_q *)(*(u8 **)(g + 0x2530) + 0x10) = *(vu0_q *)(g + 0xB0);
    *(vu0_q *)(g + 0x23B0) = *(vu0_q *)(g + 0xB0);
    func_0038D308(*(u8 **)(g + 0x2530) + 0x380, g + 0xB0);
    func_0038D328(g + 0x20, g + 0xB0);
    func_0038D308(*(u8 **)(g + 0x2524) + 0xC0, g + 0xB0);
    *(s32 *)(g + 0x1200) = 0;
    f0 = *(f32 *)(g + 0xB8);
    f1 = *(f32 *)(g + 0x1200);
    *(f32 *)(g + 0x11E0) = f0;
    *(vu0_q *)(g + 0x1290) = *(vu0_q *)(g + 0x20);
    func_L39_00632180(g, (f32 *)(g + 0xE0), 1, f1, f1, 0.7f);
    func_0038CC88(g + 0x23C0, *(u8 **)(g + 0x2530) + 0x380, 0x30);
    func_L01_00412E70(g + 0x11A0, g + 0xA0, *(s32 *)(g + 0x424), *(f32 *)(g + 0xB8), f1);
    *(s32 *)(g + 0x12CC) = 0;
    *(s32 *)(g + 0x12D8) = *(s32 *)(g + 0x2544);
    func_00382760(g + 0x1290, 1.0f, *(f32 *)(g + 0x11E0), -*(f32 *)(g + 0x1200));
    func_L39_00673A80(g + 0x1A40, 1);

    /* protected store 3: key at g+0x1A53, 16-bit value D_L39_0049C890+0x9E, table D_L39_00483A00 */
    h = *(s16 *)(D_L39_0049C890 + 0x9E);
    x = g + 0x1A53;
    if (x[0] == 0) {
        D_L39_00483A00[0] = D_L39_00483A00[0] + 1;
        x[0] = D_L39_00483A00[0];
    } else {
        u8 t = x[0];
        x[0] = D_L39_00483A00[1];
        D_L39_00483A00[1] = t;
    }
    word = ((u32 *)D_L39_00483A00)[((u32)x * D_L39_0024B9C8) % 418];
    kc[1] = (((u32)h & 0xFFFF) | ((u32)h << 16)) ^ word;
    kc[0] = (u32)x ^ word;
    c = x[0];
    base = ((u32)x - c) & 7;
    for (k = 0; k < 8; k++) {
        D_L39_00483A00[c + 1 + ((base + k * 3) & 7) * 209] = ((u8 *)kc)[k];
    }

    /* protected store 4: key at g+0x19E4, value 0 */
    x = g + 0x19E4;
    if (x[0] == 0) {
        D_L39_004997E0[0] = D_L39_004997E0[0] + 1;
        x[0] = D_L39_004997E0[0];
    } else {
        u8 t = x[0];
        x[0] = D_L39_004997E0[1];
        D_L39_004997E0[1] = t;
    }
    word = ((u32 *)D_L39_004997E0)[((u32)x * D_L39_0024B9C8) % 510];
    kc[1] = word;
    kc[0] = (u32)x ^ word;
    c = x[0];
    base = ((u32)x - c) & 7;
    for (k = 0; k < 8; k++) {
        D_L39_004997E0[c + 1 + ((base + k * 5) & 7) * 255] = ((u8 *)kc)[k];
    }
    func_003C3A10(*(u8 **)(g + 0x2524), 0, 0, -1);
}
