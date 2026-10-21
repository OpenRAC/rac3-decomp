#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B13A8 */
typedef struct { u8 p0[8]; s32 f8; s32 fC; unsigned long f10; unsigned long f18; } O_ABA48;
extern s32 D_001DA0B4_003B13A8;
extern u8 D_001D87C8[];
extern s32 func_003B2958_003B13A8();
extern s32 func_003B2A00_003B13A8();
extern s32 func_003B03F8();
extern s32 func_003B2978_003B13A8();
extern s32 func_003B1590();
s32 func_003B13A8(s32 unused, O_ABA48 *obj, u8 *buf) {
    s32 v[4];
    s32 t, p, q, w, q2, n;
    t = *(s32 *)(buf + 0x50008);
    p = obj->f8;
    q = obj->fC;
    w = (s32)buf + t - p;
    w = (q < w) ? q : w;
    q2 = q - w;
    func_003B2958_003B13A8(D_001DA0B4_003B13A8, &v[0], &v[1], &v[2], &v[3]);
    n = func_003B1590((v[0] & 0xFFFFFFF) | 0x20000000, v[1], (v[2] & 0xFFFFFFF) | 0x20000000, v[3], p, w, buf, q2);
    if (n > 0) {
        if (func_003B2A00_003B13A8(D_001DA0B4_003B13A8, obj->f10, obj->f18, v[0], n) == 0) {
            func_003B03F8(D_001D87C8);
        }
    }
    func_003B2978_003B13A8(D_001DA0B4_003B13A8, n);
    return n > 0;
}
/* localdecomp:end func_003B13A8 */

/* localdecomp:start func_003B14C0 */
typedef struct { u8 p0[8]; u32 f8; s32 fC; } O_ABB60;
extern s32 D_001DA0B8;
extern s32 func_003B1590();
s32 func_003B14C0(s32 unused, O_ABB60 *obj, u8 *buf) {
    s32 v[4];
    s32 a0, a1, a2, a3;
    s32 t, q, q2, w, res;
    u32 p, end;
    t = *(s32 *)(buf + 0x50008);
    p = obj->f8 + 4;
    end = (u32)buf + t;
    p = (p >= end) ? p - t : p;
    q = obj->fC - 4;
    w = end - p;
    w = (q < w) ? q : w;
    q2 = q - w;
    func_003B05D0(D_001DA0B8, v, &v[1], &v[2], &v[3]);
    a1 = v[1];
    a0 = v[0];
    a2 = v[2];
    a3 = v[3];
    res = func_003B1590(a0, a1, a2, a3, p, w, buf, q2);
    func_003B06A0(D_001DA0B8, res);
    return res > 0;
}
/* localdecomp:end func_003B14C0 */
