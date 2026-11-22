#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B0B80(s32 *);
extern s32 func_003B0A60();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B0A60 */
extern void func_0011F0A0(s32);
extern s32 func_0011F1E0(s32 *, s32);
s32 func_003B0A60(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 s[4];
    s32 r;
    if (a3 <= 0) return 0;
    func_0011F0A0(0);
    s[0] = a2; s[1] = a1; s[2] = a3; s[3] = 0;
    do { r = func_0011F1E0(s, 1); } while (r == 0);
    return a3;
}
/* localdecomp:end func_003B0A60 */

/* localdecomp:start func_003B0AE0 */
extern void func_11F0A0();
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern void func_13D180();
void func_003B0AE0(u8 *o, s32 a, s32 b, s32 c) {
    s32 s[4];
    s32 h;
    func_11F0A0(0);
    s[0] = a;
    s[1] = *(s32 *)(o + 0x48);
    s[2] = b;
    s[3] = 0;
    do {
        h = func_11F1E0(s, 1);
    } while (h == 0);
    do {
    } while (func_11F1C0(h) >= 0);
    func_13D180(b, c);
}
/* localdecomp:end func_003B0AE0 */

/* localdecomp:start func_003B0B80 */
typedef struct { s32 x0; u8 p4[0x30]; s32 x34; s32 x38; s32 x3C; s32 x40; s32 x44; s32 x48; s32 x4C; s32 x50; s32 x54; s32 x58; } S_3AB220;
extern u32 func_13D158();
void func_003B0B80(s32 *arg0) {
    S_3AB220 *o = (S_3AB220 *)arg0;
    s32 s0, s1, s2, s3;
    s32 n = 0;
    s32 base, pos;
    s32 v, sz, mod, len, rest;
    s32 t;
    switch (o->x0) {
    case 1:
        s0 = o->x48 + o->x50 % o->x4C;
        s1 = o->x4C - o->x50;
        s2 = 0;
        s3 = 0;
        break;
    case 2:
        t = func_13D158() & 0xFFFFFF;
        func_003B0828(&s0, &s1, &s2, &s3, o, t - o->x48);
        break;
    case 3:
        return;
    }
    v = o->x3C;
    sz = v / 1024 * 1024;
    mod = (o->x38 - v + o->x40) % o->x40;
    len = o->x40 - mod;
    if (sz < len) len = sz;
    rest = sz - len;
    base = o->x34;
    pos = base + mod;
    if (s1 + s3 >= 0x400 && len + rest >= 0x400) {
        n = func_003B08E8(o, s0, s1, s2, s3, pos, len, base, rest);
    }
    o->x3C -= n;
    o->x50 += n;
    o->x58 = (o->x58 + n) % o->x4C;
}
/* localdecomp:end func_003B0B80 */
