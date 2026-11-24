#include "common.h"
/* localdecomp:start func_L39_004BD428 */
typedef struct { u32 key; s32 off; } E_4BD428;
typedef struct { s32 count; E_4BD428 ent[1]; } T_4BD428;
extern T_4BD428 func_L39_004BE388 __attribute__((section(".sdata")));

void func_L39_004BD428(u32 key, s32 *out0, s32 *out1, s32 *out2) {
    T_4BD428 *t;
    u32 z = 0;
    s32 off;
    s32 i;
    s32 *b = 0;
    T_4BD428 *c;
    if (key > z) {
        t = &func_L39_004BE388;
        if (t == 0) t = 0;
        off = -1;
        c = t;
        for (i = 0; i < c->count; i++) {
            if ((t->ent[i].key >> 1) == key) {
                off = t->ent[i].off;
                break;
            }
        }
        if (off >= 0) {
            b = (s32 *)c;
            b = (s32 *)&((T_4BD428 *)b)->ent[((T_4BD428 *)b)->count];
            b = (s32 *)((u8 *)b + off);
            *out0 = b[0];
            *out1 = b[1];
            *out2 = (s32)&b[2];
            return;
        }
    }
    *out0 = 0;
    *out1 = 0;
    *out2 = 0;
}
/* localdecomp:end func_L39_004BD428 */
