#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 b0C;
    u8 b0D;
    u8 b0E;
} S_006618D8;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x128 - 8];
    s32 w128;
    u8 pad12C[0x170 - 0x12C];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} S_1A5CD0_006618D8;

/* localdecomp:start func_L39_006617C8 */
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648A20(void *, s32, s32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 D_L39_0024112C;
typedef struct { u8 pad0[0x18]; f32 f18; u8 pad1C[0x15]; u8 b31; u8 pad32[2]; u16 h34; } E_006617C8;
extern E_006617C8 *D_L39_00264B68[];

void func_L39_006617C8(u8 *p) {
    s32 i;
    E_006617C8 *e;
    if (D_L39_0024112C & 0x3F) return;
    if (D_L39_0024112C == 0) return;
    if (func_L39_00648840(p, 8) != 0) return;
    for (i = 0; i < 32; i++) {
        e = D_L39_00264B68[i];
        if (e == 0) break;
        if (e->b31 == 0) continue;
        if (e->h34 & 1) continue;
        if (3.0f < *(f32 *)(p + 0xA8) - e->f18) continue;
        if (func_L01_0040E570(p + 0xA0, (u8 *)e + 0x10) < 289.0f) {
            func_L39_00648A20(p, 8, 9);
        }
    }
}
/* localdecomp:end func_L39_006617C8 */

/* localdecomp:start func_L39_006618D8 */
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);


extern S_1A5CD0_006618D8 D_001A5CD0;

void func_L39_006618D8(u8 *p, f32 *v, s32 a2, s8 a3, s32 a4) {
    S_006618D8 s;
    u8 b;

    s.b0D = p[0x2544];
    s.b0C = p[0x44ED];
    b = p[0x44EE];
    s.b0E = b;
    if (a2 != 0) {
        s.b0E = b | 0x40;
    }
    if (a4 != 0) {
        s.b0E |= 0x20;
    }
    s.b0D |= (a3 + 1) << 4;
    s.f0 = v[0];
    s.f4 = v[1];
    s.f8 = v[2];
    if (D_001A5CD0.w170 == 0) {
        func_0014AD08(D_001A5CD0.b7D4 | 0x80, D_001A5CD0.w4, -1,
                    *(s32 *)0x2405E4, 0x10, &s);
    }
}
/* localdecomp:end func_L39_006618D8 */

/* localdecomp:start func_L39_00661988 */
extern s32 D_001A58D0[];
extern s32 D_001A5930[];
extern s32 D_001A5990[];
extern S_1A5CD0_006618D8 D_001A5CD0;

void func_L39_00661988(u8 *p) {
    s32 a = *(s32 *)(p + 0x2544);
    s32 *s1 = &D_001A58D0[a];
    s32 *s2 = &D_001A5930[a];
    s32 *s3 = &D_001A5990[a];
    u8 *o = *(u8 **)(*(u8 **)(p + 0x2558) + 4);
    u8 *dp = o + 0x70;
    s32 i;
    s32 x;

    for (i = 0; i < 3; i++) {
        *(s32 *)(dp - 0x18) = s1[0];
        *(s32 *)(dp - 0xC) = s2[0];
        *(s32 *)(dp) = s3[0];
        s1 += 8;
        s2 += 8;
        s3 += 8;
        dp += 4;
    }
    x = D_001A5CD0.w128;
    if (*(s32 *)(o + 0x4C) < x - 0x4B0) {
        *(s32 *)(o + 0x4C) = x;
    }
}
/* localdecomp:end func_L39_00661988 */
