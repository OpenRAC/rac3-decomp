#include "common.h"

/* NTSC-U counterpart of func_L39_006DDF78 (src/levels/39_multiplayer_menu/L39_006DC228.c) */
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
s32 func_00120884(void *);
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006DB418 */
__asm__(".extern D_L39_0024D860, 16");
typedef struct { char pad[0x60]; char a; char pad2[3]; s32 v; s32 len; char text[1]; } T_006DDF78;
typedef struct { char pad[0x54]; T_006DDF78 *p; } S_006DDF78;
typedef struct { char pad[0x18]; s32 v; char text[0x100]; u8 end; } A_006DDF78;
extern void *D_L39_0024D860;
s32 func_00120D28(void *, void *, s32);
s32 func_00120884(void *);

void func_L39_006DB418(A_006DDF78 *arg0) {
    s32 v = arg0->v;
    T_006DDF78 *t = ((S_006DDF78 *)D_L39_0024D860)->p;
    t->v = v;
    if (v != 0) {
        t->text[0] = 0;
    } else {
        func_00120D28(&t->text[t->len], arg0->text, 0x100);
        if (arg0->end == 0) {
            t->len += func_00120884(arg0->text);
            return;
        }
    }
    t->a = 0;
}
/* localdecomp:end func_L39_006DB418 */
