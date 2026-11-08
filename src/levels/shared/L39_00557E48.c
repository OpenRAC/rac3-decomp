#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* localdecomp:start func_L39_00557E48 */
extern u8 *D_L39_0024BF68;
__asm__(".extern D_L39_0024BF68, 16");
extern f32 func_0038CF00(void *, void *);
void *func_L39_00557E48(u8 *pos) {
    u8 *best = 0;
    u8 *o;
    f32 min = 9999.0f;
    f32 d;
    for (o = D_L39_0024BF68; o != 0; o = *(u8 **)(o + 0x28)) {
        if (*(s16 *)(o + 0xAA) == 0x166F) {
            d = func_0038CF00(pos + 0x10, o + 0x10);
            if (d < min) {
                min = d;
                best = o;
            }
        }
    }
    return best;
}
/* localdecomp:end func_L39_00557E48 */

INCLUDE_ASM("asm/levels", func_L39_00557EF0);

INCLUDE_ASM("asm/levels", func_L39_00557FD0);

INCLUDE_ASM("asm/levels", func_L39_00558118);

INCLUDE_ASM("asm/levels", func_L39_00558438);

INCLUDE_ASM("asm/levels", func_L39_00558508);

INCLUDE_ASM("asm/levels", func_L39_005585B0);

INCLUDE_ASM("asm/levels", func_L39_005587D0);

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

INCLUDE_ASM("asm/levels", func_L39_00558CA0);

/* localdecomp:start func_L39_00558D80 */
extern f32 func_0038CE68();

s32 func_L39_00558D80(void) {
    if (func_0038CE68() < 0.0f) {
        return 1;
    }
    return -1;
}
/* localdecomp:end func_L39_00558D80 */

INCLUDE_ASM("asm/levels", func_L39_00558DB8);

INCLUDE_ASM("asm/levels", func_L39_00558E68);

INCLUDE_ASM("asm/levels", func_L39_00559018);

INCLUDE_ASM("asm/levels", func_L39_005591C8);

INCLUDE_ASM("asm/levels", func_L39_00559268);

INCLUDE_ASM("asm/levels", func_L39_005593F8);

INCLUDE_ASM("asm/levels", func_L39_005594C8);

INCLUDE_ASM("asm/levels", func_L39_00559588);

INCLUDE_ASM("asm/levels", func_L39_005596B0);

/* localdecomp:start func_L39_005596F0 */
typedef struct { s32 w0; u8 p0[0x74]; s32 w78; u8 p1[0xC4]; s32 w140; } V_558C78;
typedef struct { u8 p0[0x68]; V_558C78 *v; } M_558C78;
extern void func_L39_00559588(M_558C78 *);
void func_L39_005596F0(M_558C78 *m) {
    V_558C78 *v = m->v;
    s32 s;
    if (v->w78 != 0) {
        s = v->w0;
        if (s == 5 || v->w140 == 1) {
            if (s != 0) {
                func_L39_00559588(m);
            }
        }
    }
}
/* localdecomp:end func_L39_005596F0 */

INCLUDE_ASM("asm/levels", func_L39_00559740);
