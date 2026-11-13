#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* declared by functions of L39_00557E48.c, which this file was cut from */
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DAB8(f32, f32);

/* localdecomp:start func_L39_005589F0 */
typedef struct { u8 pad[612]; s32 w612; } Sub_00557F78;
typedef struct { u8 pad0[104]; Sub_00557F78 *sub; u8 pad1[62]; s16 h170; } Obj_00557F78;
typedef struct { s32 n; s32 pad[3]; Obj_00557F78 *list[1]; } Tbl_00557F78;
typedef struct { u8 pad[104]; Tbl_00557F78 *tbl; } Moby_00557F78;
Obj_00557F78 *func_L39_005589F0(Moby_00557F78 *m, s32 a1) {
    Tbl_00557F78 *t = m->tbl;
    s32 i;
    for (i = 0; i < t->n; i++) {
        Obj_00557F78 *o = t->list[i];
        if (o->h170 == a1 && a1 == 4253 && o->sub->w612 == 1337) return o;
    }
    return 0;
}
/* localdecomp:end func_L39_005589F0 */

INCLUDE_ASM("asm/levels", func_L39_00558A58);

/* localdecomp:start func_L39_00558CA0 */
typedef struct { s32 n; u8 p0[0xC]; void *list[8]; } Out_00558CA0;
extern f32 D_L39_0024B308;
__asm__(".extern D_L39_0024B308, 4");
extern void *D_L39_002637C0[];
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
void func_L39_00558CA0(u8 *obj, Out_00558CA0 *out, void *m) {
    s32 n;
    s32 i;
    n = func_003D4D00(obj + 0x10, 0, obj, 0, D_L39_0024B308);
    out->n = 0;
    for (i = 0; i < n; i++) {
        if (func_L39_00558438(m, (s32)obj, D_L39_002637C0[i])) {
            out->list[out->n] = D_L39_002637C0[i];
            if (++out->n >= 8) break;
        }
    }
}
/* localdecomp:end func_L39_00558CA0 */

/* localdecomp:start func_L39_00558D80 */
extern f32 func_0038CE68();

s32 func_L39_00558D80(void) {
    if (func_0038CE68() < 0.0f) {
        return 1;
    }
    return -1;
}
/* localdecomp:end func_L39_00558D80 */
