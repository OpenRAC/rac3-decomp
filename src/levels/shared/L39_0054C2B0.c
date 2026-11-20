#include "common.h"

/* declared by functions of L39_0054A250.c, which this file was cut from */
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x28 - 0x22];
    f32 f28;
    u8 pad2C[0x80 - 0x2C];
} T_0054A250;
extern s32 func_L39_00648AE0(void *, s32);
extern T_0054A250 D_L39_0049C890[];

/* localdecomp:start func_L39_0054C2B0 */
typedef int u128_0054C2B0 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x2544];
    s32 w2544;
} A_0054C2B0;
typedef struct {
    u8 pad0[0x2548];
    s32 w2548;
} B_0054C2B0;
typedef struct {
    u8 pad0[0x54];
    s32 w54;
    A_0054C2B0 *p58;
} S_0054C2B0;
typedef struct {
    u8 pad0[0x10];
    u128_0054C2B0 pos;
    u8 pad20[0x68 - 0x20];
    S_0054C2B0 *p68;
} O_0054C2B0;
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x34 - 0x22];
    f32 f34;
    u8 pad38[0x80 - 0x38];
} T_0054C2B0;

extern void func_0038CE20(u128_0054C2B0 *, u128_0054C2B0 *, f32);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern s32 func_003D4D00(void *, f32, s32, void *, s32);
extern void func_L01_00447718(void *, void *, void *, s32, void *, s32, s32, s32, s32, f32, f32, f32);
extern B_0054C2B0 *D_L39_0024CE20[2];
__asm__(".extern D_L39_0024CE20, 16");
extern u8 D_L39_002637C0[];

static inline T_0054C2B0 *TabGet_0054C2B0(void *s, s32 mode) {
    T_0054C2B0 *e;
    if (func_L39_00648AE0(s, mode)) {
        e = &((T_0054C2B0 *)D_L39_0049C890)[((T_0054C2B0 *)((u8 *)D_L39_0049C890 + (mode << 7)))->b21];
    } else {
        e = (T_0054C2B0 *)((u8 *)D_L39_0049C890 + (mode << 7));
    }
    return e;
}

/* from func_L01_00384E68 */
void func_L39_0054C2B0(O_0054C2B0 *m, u128_0054C2B0 *dir, void *hit, s32 a3) {
    u128_0054C2B0 back;
    u128_0054C2B0 centre;
    S_0054C2B0 *s = m->p68;
    u128_0054C2B0 *pos;
    B_0054C2B0 *b;
    f32 splash;
    s32 count;
    s32 a;
    s32 fl;
    u128_0054C2B0 *cp;

    func_0038CE20(&back, dir, -3.0f);
    splash = TabGet_0054C2B0(s->p58, 4)->f34;
    pos = &m->pos;
    a = s->p58->w2544;
    b = D_L39_0024CE20[a];
    a = -1;
    if (b != 0) {
        a = b->w2548;
    }
    func_L39_005FFDF8(a);
    count = func_003D4D00(pos, 4.0f, 0x10, m, 0);
    func_L39_005FFE78();
    cp = &centre;
    centre = m->pos;
    fl = a3 ? 0x1010000 : 0x1010001;
    func_L01_00447718(m, cp, D_L39_002637C0, count, hit, fl, 3, 1, -1, splash, (f32)s->w54, 1.0f);
}
/* localdecomp:end func_L39_0054C2B0 */
