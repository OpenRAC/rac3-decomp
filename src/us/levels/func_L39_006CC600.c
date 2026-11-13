#include "common.h"

/* NTSC-U counterpart of func_L39_006CED88 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void func_0011D534(void *, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern void *D_L39_0024D860;
void *func_001206F4(void *, void *);
void func_001962F8(void);
extern u8 D_001A5E50[];

/* localdecomp:start func_L39_006CC600 */
typedef struct {
    s32 f0;
    u8 f4[0x24];
    s32 f28[3];
    u8 f34;
    u8 f35;
    u8 pad36[2];
    s32 f38;
    u8 f3C[0x20];
    u8 f5C;
    u8 pad5D[3];
    s32 f60;
} T_006CED88;
typedef struct {
    u8 pad0[0x30];
    s32 *f30;
    u8 pad34[4];
    T_006CED88 *f38;
} G_006CED88;
typedef struct {
    u8 pad0[0x38];
    s32 f38;
    u8 f3C[0x20];
    u8 f5C;
    u8 f5D;
    u8 pad5E[0x22];
    u8 f80;
    u8 pad81[0x28];
    u8 fA9;
    u8 padAA[2];
    s32 fAC;
} S_006CED88;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    u8 pad20[4];
    u8 f24[0x20];
    s32 f44;
    u8 f48[0x20];
    s32 f68[3];
} A_006CED88;
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern u8 D_L39_00249D60[];
extern void *func_001206F4(void *, void *);
extern void func_0011D534(void *, s32, s32);
extern void func_001962F8(void);
extern void func_L39_00594648(s32, s32, s32);
extern void func_L39_006CC598(u8 *, s32 *);

void func_L39_006CC600(A_006CED88 *a) {
    G_006CED88 *g = (G_006CED88 *)D_L39_0024D860;
    T_006CED88 *t = g->f38;
    s32 *cur = g->f30;
    u8 buf[0x20];
    s32 on = a->f18;

    t->f60 = on;
    if (on != 0) {
        S_006CED88 *s = (S_006CED88 *)D_001A5E50;
        s->f38 = -1;
        t->f0 = -1;
        func_001206F4(t->f4, D_L39_00249D60);
        func_001206F4(s->f3C, D_L39_00249D60);
        t->f34 = 0;
        s->f5D = 0;
        t->f35 = 0;
        func_0011D534(t->f28, 0, 0xC);
        t->f38 = -1;
        t->f3C[0] = D_L39_00249D60[0];
        s->fAC = -1;
        s->f80 = 0;
        s->fA9 = 0;
        func_001962F8();
    } else {
        S_006CED88 *s = (S_006CED88 *)D_001A5E50;
        s32 id = a->f1C;
        s->f38 = id;
        t->f0 = id;
        func_L39_00594648((s32)buf, (s32)a->f24, 0x20);
        func_001206F4(t->f4, buf);
        func_001206F4(s->f3C, buf);
        if (a->f44 == *cur) {
            t->f34 = 1;
            s->f5D = 1;
        } else {
            t->f34 = 0;
            s->f5D = 0;
        }
        func_L39_006CC598((u8 *)a->f68, t->f28);
        t->f38 = a->f44;
        func_001206F4(t->f3C, a->f48);
    }
    t->f5C = 0;
}
/* localdecomp:end func_L39_006CC600 */
