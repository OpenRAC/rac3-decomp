#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 392F68.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_00393538();
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331AE0[];
extern s32 func_00392F68(s32 key);

/* localdecomp:start func_00393808 */
typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p1[0x48]; s32 f58; s32 f5C; s32 f60; u8 p2[0x10]; s32 f74; s32 f78; } S;
void func_00393808(void *arg) {
    S *s = (S *)arg;
    s32 *q;
    s32 n, x, a, t;
    q = s->fC;
    if (q != 0 && ((s32)q & 3) == 0) {
        s->f78 = *q;
        if (s->f8 < s->f78) s->f78 = s->f8;
        s->f74 = s->f78;
    } else {
        s->f78 = 99999;
        s->f74 = 99999;
    }
    n = 0;
    x = s->f8;
    a = s->f60;
    t = s->f5C;
    if (x >= 10) {
        do { x /= 10; n++; } while (x >= 10);
    }
    if ((a & 3) == 0 && (a & 0xC) != 0) {
        s->f5C = t + (n + 1) * 12;
        if (s->f58 < 0xE) s->f58 = 0xE;
    } else {
        if (t < 12) s->f5C = 12;
        s->f58 = s->f58 + (n + 1) * 14;
    }
}
/* localdecomp:end func_00393808 */

/* US draft of func_003938F8 (rac3-uya-decomp func_0038F0C0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003938F8 */
extern void func_00393808(void *);
 
void func_003938F8(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0xB4;
    *(s16 *)((u8 *)p + 0x48) = 0;
    *(s16 *)((u8 *)p + 0x4A) = 0;
    func_00393808(p);
}
/* localdecomp:end func_003938F8 */

LINKER_REMNANT("asm/remnants", func_00393928);

/* localdecomp:start func_00393930 */
#include "vu0.h"
extern int abs(int);
typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p10[0x5C]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_00393930;
void func_00393930(S_00393930 *p) {
    extern s32 func_003963D0();
    u8 *b = p->b70;
    s32 n, step;
    if (p->fC != 0) {
        s32 initial = *p->fC;
        if (initial < 0) initial = 0;
        p->f78 = initial;
        if (p->f8 < initial) p->f78 = p->f8;
    }
    if (p->f74 != p->f78) {
        p->f7C = 150;
        if (p->f6C >= 24) {
            n = abs(p->f74 - p->f78);
            if (n != 0) {
                step = (s32)(sqrt_asm((f32)n / 25.0f) * 5.0f);
                { s32 quarter = n / 4; if (quarter > step) step = quarter; }
                if (step > 121) step = 121;
                else if (step < 1) step = 1;
                b[3] += step;
                if (b[3] >= 3) {
                    u32 accum = b[3];
                    s32 current = p->f74;
                    step = accum >> 1;
                    if (p->f78 < current) p->f74 = current - step;
                    else p->f74 = current + step;
                    b[3] -= step * 2;
                }
            }
        }
    }
    if (p->f7C >= 4) {
        if (b[0] < 7) b[0]++;
        else if (b[1] < 7) b[1]++;
    } else {
        if (b[1] != 0 || b[0] != 0) p->f6C = 1;
        if (b[1] != 0) b[1]--;
        else if (b[0] != 0) b[0]--;
    }
    func_003963D0((u8 *)p + 0x40);
}
/* localdecomp:end func_00393930 */

typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p10[0x5C]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_38F0F8;
extern s32 func_003963D0();

LINKER_REMNANT("asm/remnants", func_00393AF0);
