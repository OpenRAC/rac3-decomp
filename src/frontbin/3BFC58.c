#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003BFC58();
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
extern void func_003BFD60(S_3BA368 *p);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BA748;
typedef int Q_3BA748 __attribute__((mode(TI)));
typedef struct { s8 p0[0x20]; s8 b20; } O_3BA748;
typedef struct { O_3BA748 *obj; s32 f4; u8 p8[5]; u8 b0D; u8 pE[2]; V_3BA748 v10; } B_3BA748;
typedef struct { u8 p0[4]; s32 f4; u8 b8; u8 p9; s16 h0A; f32 fC; V_3BA748 v10; B_3BA748 b; } P_3BA748;
extern s32 func_0038CB00();
extern void func_003CD250(s32);
extern void func_0038D000(void *, void *, void *);
/* localdecomp:start func_003BFC58 */
typedef struct { u8 on; f32 scale; } S_003BFC58;
extern S_003BFC58 D_001DA33C;
extern void func_003C2EC0(u8 *, s32, u8 *);
void func_003BFC58(P_3BA748 *p) {
    B_3BA748 *q;
    V_3BA748 m[4];
    Q_3BA748 x, y;
    O_3BA748 *o;
    q = &p->b;
    if (p->h0A >= 0) {
        if (func_0038CB00(&p->h0A) != 0) {
            func_003CD250((s32)p);
            return;
        }
    }
    o = q->obj;
    if (o != 0) {
        if (o->b20 < 0) {
            func_003CD250((s32)p);
            return;
        }
        func_003C2EC0((u8 *)o, q->f4, (u8 *)m);
        func_0038D000(&p->v10, &q->v10, m);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->v10));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m[3]));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(p->v10) : "j"(x));
        p->v10.w = 0;
    } else {
        p->v10 = q->v10;
    }
    if (D_001DA33C.on != 0) {
        p->f4 = (p->f4 & 0xFFFFFF) | ((s32)(D_001DA33C.scale * 128.0f) << 24);
    }
    p->fC = p->fC * q->v10.w;
    p->b8 = p->b8 + q->b0D;
}
/* localdecomp:end func_003BFC58 */

extern u8 *D_001DA31C_003BFD60[2];
extern u8 D_00380060[];
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850;
extern u8 D_001DA318[8];
extern f32 D_001D8E64;
extern s32 D_001D8E68;
extern f32 D_001D8E6C;
extern f32 D_001D8E70;
extern u8 *func_003BFAC8(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
/* localdecomp:start func_003BFD60 */
/* US draft of func_003BFD60 (rac3-uya-decomp func_003C0010, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


__asm__(".extern D_001D8E64_003BFD60, 4");
__asm__(".extern D_001D8E68_003BFD60, 4");
__asm__(".extern D_001D8E6C_003BFD60, 4");
__asm__(".extern D_001D8E70_003BFD60, 4");
extern u8 *D_001DA31C_003BFD60_003BFD60[2];
extern u8 D_00380060_003BFD60[];
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850_003BFD60;
extern u8 D_001DA318_003BFD60[8];
extern f32 D_001D8E64_003BFD60;
extern s32 D_001D8E68_003BFD60;
extern f32 D_001D8E6C_003BFD60;
extern f32 D_001D8E70_003BFD60;
extern u8 *func_003BFAC8_003BFD60(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_003BFD60(S_3BA368 *a) {
    s32 i;
    u8 **p = D_001DA31C_003BFD60_003BFD60;
    u8 *e = D_00380060_003BFD60;
    u8 *r;
    for (i = 5; i >= 0; i--) {
        if (*p == 0) {
            r = func_003BFAC8_003BFD60(e, (s32)a, D_001D8E68_003BFD60, 0, 0, -1, 0, -1, 0, 0, D_001D8E6C_003BFD60 * 210000.0f, D_001D8E70_003BFD60, 1.0f);
            *p = r;
            if (r != 0) r[3] = 0x44;
        }
        e += 0x10;
        p++;
    }
    { S_3BA850_003BFD60 *q = (S_3BA850_003BFD60 *)D_001DA318_003BFD60; q->f1C = D_001D8E64_003BFD60 * 0.020000002f; }
}
/* localdecomp:end func_003BFD60 */
