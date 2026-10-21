#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003CE450 */
typedef struct { u8 pad[0x20]; s16 *arr[1]; } S_3C8B28;
extern S_3C8B28 *D_001DA5F0_003CE450;
extern s32 D_001DA610[2];
extern void func_0038D728(void *, void *);
s32 func_003CE450(s32 idx, s32 n) {
    f32 v[4] __attribute__((aligned(16)));
    s16 *p = D_001DA5F0_003CE450->arr[idx];
    if (n > 0) {
        s32 dx = (u16)p[5], dy = (u16)p[6], dz = (u16)p[7];
        s32 a, b, c;
        s32 x = (u16)p[2], y = (u16)p[3], z = (u16)p[4];
        do {
            a = x + dx;
            b = y + dy;
            c = z + dz;
            x = a;
            y = b;
            z = c;
        } while (--n);
        p[4] = c;
        p[3] = b;
        p[2] = a;
    }
    __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(v));
    if (p[2] != 0) v[0] = p[2] * 9.58738019107841e-05f;
    if (p[3] != 0) v[1] = p[3] * 9.58738019107841e-05f;
    if (p[4] != 0) v[2] = p[4] * 9.58738019107841e-05f;
    func_0038D728(D_001DA610, v);
}
/* localdecomp:end func_003CE450 */
