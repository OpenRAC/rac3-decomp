#include "common.h"

/* declared by functions of L39_006BA5C0.c, which this file was cut from */
void func_L39_006CC158(void *, s32);

/* declared by functions of L39_006BBB38.c, which this file was cut from */
extern u8 *D_L39_0024D760;

/* localdecomp:start func_L39_006BDE00 */
/* best: 80 diff with --as ps2as (file flags lack @ps2as: lui/ori float consts need it).
 * Remaining: (1) retail loads game+0x164 into $v1 after func_L39_006DAB18, mine $v0;
 * (2) retail copies found ($t1) to $v0 before 'beql' in the 2nd loop, like an inlined
 * helper's return value (list-contains-id search); a scoped temp gets propagated away.
 * Everything else lines up (the rest of the diff is the 2-instruction shift). */
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern char D_L39_002494F0[];
extern char D_L39_0037D7C8[][0x40];
typedef struct { s32 w[0x23]; } S_006BDE00;
typedef struct { s32 f0; s32 count; u8 **items; } L_006BDE00;
typedef struct { u8 pad[0x178]; L_006BDE00 lists[1]; } G_006BDE00;
typedef struct { u8 pad[0x28]; L_006BDE00 lists[1]; } O_006BDE00;
s32 func_L39_006DAB18(void *);
s32 func_00381FF0(s32);
s32 func_00120048(void *, char *, ...);
s32 func_00120884(char *);
void func_L39_005958F8(void *, void *, s32);
void func_L39_006BE580(s32 *, s32 *);
void func_L39_006BE598(s32 *, s32 *);
void func_L39_006BE5B0(S_006BDE00 *, S_006BDE00 *);

typedef struct {
    u8 pad0[0x134];
    u8 *f134;
    u8 *f138;
    u8 pad13C[0x314 - 0x13C];
    u8 f314;
    u8 pad315[3];
    s32 f318;
    s32 f31C;
    s32 count;
    s32 ids[0xE0];
    u8 pad6A4[0x784 - 0x6A4];
    S_006BDE00 entries[0xE0];
} M_006BDE00;

void func_L39_006BDE00(M_006BDE00 *arg0) {
    char *names[0xE0];
    u8 *game = *(u8 **)(D_L39_0024D760 + 0x4C);
    u8 *list = 0;
    u8 *other;
    u8 *obj;
    s32 sel;
    s32 cur;
    s32 best;
    s32 i;
    s32 k;
    s32 v;
    s32 n;
    s32 j;
    s32 m;

    if (*(s32 *)(game + 0x170) >= 0) {
        list = (u8 *)&((G_006BDE00 *)game)->lists[*(s32 *)(game + 0x170)];
    }
    other = *(u8 **)(D_L39_0024D760 + 0x34);
    if (arg0->f314 == 1 && *(u8 *)(game + 0x15D) == 0 && arg0->f318 == 0) {
        func_L39_006DAB18(game);
        sel = (arg0->f31C = *(s32 *)(game + 0x164));
        arg0->f314 = 0;
    }
    obj = arg0->f138;
    (*(void (**)(void *, f32, f32))(*(u8 **)(obj + 0x60) + 0x28))(obj, 0.725f, 0.685f);
    obj = arg0->f138;
    (*(void (**)(void *, f32))(*(u8 **)(obj + 0x60) + 0x90))(obj, 0.049f);

    if (list == 0 || *(s32 *)(game + 0x164) == arg0->f31C) {
        return;
    }
    func_00120048(arg0->f134 + 0x14, D_L39_002494F0, func_00381FF0(0x1005), *(s32 *)(list + 4));
    arg0->f31C = *(s32 *)(game + 0x164);
    n = *(s32 *)(list + 4);
    arg0->count = n;
    if (n > 0xE0) {
        arg0->count = 0xE0;
    }
    obj = arg0->f138;
    sel = (*(s32 (**)(void *))(*(u8 **)(obj + 0x60) + 0x8C))(obj);
    cur = -1;
    if (sel != -1) {
        cur = arg0->ids[sel];
    }
    best = 0;
    for (j = 0; j < arg0->count; j++) {
        u8 *e = (*(u8 ***)(list + 8))[j];
        names[j] = (char *)(e + 0x20);
        arg0->ids[j] = *(s32 *)(e + 0x1C);
        arg0->entries[j] = *(S_006BDE00 *)(e + 0x40);
        if (cur == *(s32 *)(e + 0x1C)) {
            best = j;
        }
    }
    k = 0;
    for (i = 0; i < arg0->count; i++) {
        s32 id = arg0->ids[i];
        s32 found = 0;
        u8 *q = 0;
        if (*other != 0 && *(s32 *)(other + 4) >= 0) {
            q = (u8 *)&((O_006BDE00 *)other)->lists[*(s32 *)(other + 4)];
        }
        if (q != 0) {
            s32 t;
            for (t = 0; t < *(s32 *)(q + 4); t++) {
                if (*(s32 *)((*(u8 ***)(q + 8))[t] + 0x1C) == id) {
                    found = 1;
                    break;
                }
            }
        }
        sel = found;
        if (sel) {
            func_L39_006BE580((s32 *)&names[k], (s32 *)&names[i]);
            func_L39_006BE598(&arg0->ids[k], &arg0->ids[i]);
            func_L39_006BE5B0(&arg0->entries[k], &arg0->entries[i]);
            k++;
        }
    }
    for (m = 0; m < arg0->count; m++) {
        func_L39_005958F8(D_L39_0037D7C8[m], names[m], func_00120884(names[m]));
        names[m] = D_L39_0037D7C8[m];
    }
    obj = arg0->f138;
    (*(void (**)(void *, s32, char **))(*(u8 **)(obj + 0x60) + 0x6C))(obj, arg0->count, names);
    obj = arg0->f138;
    (*(void (**)(void *, s32))(*(u8 **)(obj + 0x60) + 0x88))(obj, best);
    obj = arg0->f138;
    (*(void (**)(void *, f32))(*(u8 **)(obj + 0x60) + 0xE4))(obj, 0.31f);
}
/* localdecomp:end func_L39_006BDE00 */
