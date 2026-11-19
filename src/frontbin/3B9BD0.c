#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern s32 func_003B9C68();
extern s32 func_003B9E30(void *, s32, s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B9BD0 */
typedef struct { u8 b[0xB4]; } E_3B46F0;
extern E_3B46F0 D_00280CF0[];
extern s32 D_001DA1A8;
extern void func_003B9A90(E_3B46F0 *);
s32 *func_003B9BD0(s32 idx) {
    s32 i;
    E_3B46F0 *p;
    if (D_001DA1A8 == 0) {
        p = D_00280CF0;
        i = 3;
        do { func_003B9A90(p); i--; p++; } while (i != -1);
        D_001DA1A8 = 1;
    }
    return (s32 *)&D_00280CF0[idx];
}
/* localdecomp:end func_003B9BD0 */

/* localdecomp:start func_003B9C58 */
s32 func_003B9C58(s32 *p) {
    return p[1] + p[2];
}
/* localdecomp:end func_003B9C58 */

/* localdecomp:start func_003B9C68 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_3B4788;
typedef struct { u8 f0; u8 p1[3]; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; s32 f1C; f32 a20[4]; f32 a30[4]; f32 a40[4]; f32 f50; f32 f54; s32 f58; u8 p5C[0x4C]; u8 fA8; u8 fA9; u8 pAA[2]; f32 fAC; s32 fB0; } O_3B4788;
extern void func_003B9EC8();
extern void func_0038CB78();
extern void func_003BA340();
s32 func_003B9C68(O_3B4788 *o, S_3B4788 *s) {
    s32 size;
    s32 ret = 1;
    s32 i, j, k;
    o->fA8 = 0;
    o->fA9 = 0;
    { s32 t = s->fC * 0x44; size = s->f14 * t; }
    if (size >= s->f0) {
        ret = 0;
    } else {
        o->f4 = 0;
        o->f8 = 0;
        o->fC = s->fC;
        o->f10 = s->f10;
        o->f14 = s->f14;
        o->f18 = s->f8;
        o->f1C = 0;
        for (k = 0; k < 4; k++) {
            o->a20[k] = s->a24[k];
            o->a30[k] = s->a44[k];
            o->a40[k] = s->a34[k];
        }
        o->f50 = s->f1C;
        o->f54 = s->f20;
        o->fAC = s->f18;
        o->fB0 = s->f4;
        func_003B9EC8(o);
        o->f0 = 1;
    }
    func_0038CB78(o->fB0, 0, size);
    for (i = 0; i < o->f14; i++) {
        for (j = 0; j < o->fC; j++) {
            *(s32 *)((u8 *)func_003B9E30(o, i, j) + 0x40) = 0;
        }
    }
    func_003BA340(o, 0x8066CCFF, 0x80808080, 0x666690CC, 0x80FFFFFF);
    o->f58 = 0;
    return ret;
}
/* localdecomp:end func_003B9C68 */

/* localdecomp:start func_003B9E30 */
s32 func_003B9E30(void *p, s32 x, s32 y) {
    return *(s32 *)((u8 *)p + 0xB0) + (*(s32 *)((u8 *)p + 0x14) * y + x) * 0x44;
}
/* localdecomp:end func_003B9E30 */

/* localdecomp:start func_003B9E50 */
s32 func_003B9E50(void *p, s32 x, s32 y) {
    y += 0x4F0000;
    return x * (*(s32 *)((u8 *)p + 0x14) * *(s32 *)((u8 *)p + 0x10)) + y;
}
/* localdecomp:end func_003B9E50 */

/* localdecomp:start func_003B9E70 */
s32 func_003B9E70(s32 a0, s32 a1) {
    return a1 + 0x4F0048;
}
/* localdecomp:end func_003B9E70 */

/* localdecomp:start func_003B9E80 */
s32 func_003B9E80(s32 a0, s32 a1) {
    return a1 + 0x4F00A9;
}
/* localdecomp:end func_003B9E80 */

/* localdecomp:start func_003B9E90 */
extern s32 func_003E85A8();
 
s32 func_003B9E90(u8 *p) {
    s32 r = 0;
    if (p[0] != 0) {
        p[0] = 0;
        func_003E85A8(*(s32 *)(p + 0x18));
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003B9E90 */
