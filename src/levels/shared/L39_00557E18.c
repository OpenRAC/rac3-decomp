#include "common.h"

/* localdecomp:start func_L39_00557E18 */
extern s32 D_L39_001DFB98;
s32 func_L39_00557E18(s32 a0) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if ((&D_L39_001DFB98)[i] == a0) return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00557E18 */

INCLUDE_ASM("asm/levels", func_L39_00557E48);

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

/* localdecomp:start func_L39_005598D8 */
extern f32 D_L39_001DFC84;
extern f32 func_0038CF38(u8 *, u8 *);
s32 func_L39_005598D8(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a0 + 104);
    u8 *e;
    s32 i;
    if (a1 == 0) {
        return 0;
    }
    for (i = 0; i < *(s32 *)s; i++) {
        e = ((u8 **)(s + 16))[i];
        if (e != 0 && e != a1 && func_0038CF38(e + 16, a1 + 16) < D_L39_001DFC84) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_005598D8 */

INCLUDE_ASM("asm/levels", func_L39_00559980);

INCLUDE_ASM("asm/levels", func_L39_00559A38);

INCLUDE_ASM("asm/levels", func_L39_0055A880);

INCLUDE_ASM("asm/levels", func_L39_0055AD78);
