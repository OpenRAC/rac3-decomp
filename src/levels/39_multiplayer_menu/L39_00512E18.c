#include "common.h"

/* declared by functions of L39_005128F8.c, which this file was cut from */
extern void func_L39_005128E8(s32 *);

/* localdecomp:start func_L39_00512E18 */
typedef struct { s32 unk0; s32 unk4; unsigned long *unk8; } S_00512E18;
extern void func_L39_005128E8(s32 *);
extern s32 func_L39_00512A40(s32, S_00512E18 *);
extern s32 func_L39_00513178(s32, S_00512E18 *, s32, s32, s32);
extern void func_L39_005128F8(S_00512E18 *);
s32 func_L39_00512E18(s32 a0, s32 a1, s32 a2, s32 a3) {
    S_00512E18 s;
    s32 r;
    func_L39_005128E8((s32 *)&s);
    do {
        r = func_L39_00512A40(1, &s);
        if (r != 0) break;
        *s.unk8 = 1;
        s.unk4 = 1;
        r = func_L39_00513178(a0, &s, a1, a2, a3);
    } while (0);
    func_L39_005128F8(&s);
    return r;
}
/* localdecomp:end func_L39_00512E18 */
