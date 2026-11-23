#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 396690.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_00396838(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
extern E_38ED00 *D_001D9EA4[];
s32 func_00392F68(s32);

typedef struct { u8 p0[0x18]; void (*f18)(void *); u8 p1c[0x74]; } S_391FD8;
extern S_391FD8 D_00331AE0_00396838[];
extern s32 D_001D9EC0;
extern s32 D_001D9BDC;
extern s32 D_001D9E94;
extern s32 D_001D9DF8;
extern s32 D_001D9DFC;
extern s32 D_001D9E00;
extern s32 D_001D5B94;

/* localdecomp:start func_00396968 */
typedef struct { s16 a; s16 b; } P_392108;
typedef struct { s32 w; s32 pad; } W_392108;
extern u8 D_001D5EA5;
extern P_392108 *D_001D9EA8[];
extern W_392108 *D_001D9EAC[];
extern W_392108 *D_001D9EB0[];
s32 func_00396968(s32 key, s32 n) {
    s32 r;
    s32 idx;
    u32 mask;
    E_38ED00 *e;
    P_392108 *p;
    if (D_001D5EA5 == 0) {
        r = func_00392F68(key);
        D_001D5EA5 = (u32)r >> 31;
        e = (E_38ED00 *)((r << 3) + (s32)D_001D9EA4[0]);
        if (e->x0 != 0xFFFF && n < e->x2) {
            idx = e->x4 + n;
            p = (P_392108 *)((idx << 2) + (s32)D_001D9EA8[0]);
            if ((D_001D9EB0[0][p->a].w & 0x80000000) == 0) {
                return (D_001D9EAC[0][p->b].w & 0x80000000) ? 0 : idx;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_00396968 */
