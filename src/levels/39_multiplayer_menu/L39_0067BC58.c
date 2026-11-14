#include "common.h"

typedef struct { int a, b, c; } T;

/* localdecomp:start func_L39_0067BC58 */
typedef struct S_0067BC58 {
    s16 lo;
    s16 hi;
    u8 pad[12];
} S_0067BC58;

S_0067BC58 *func_L39_0067BC58(s32 key, S_0067BC58 *tab, u32 n) {
    u32 i;
    S_0067BC58 *ret = 0;
    for (i = 0; i < n; i++, tab++) {
        if (tab->lo <= key && key <= tab->hi) {
            ret = tab;
            break;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_0067BC58 */

/* localdecomp:start func_L39_0067BCA8 */
#include "assert.h"

typedef struct S_0067BCA8_E {
    s16 lo;
    s16 hi;
    s32 s0;
    s32 s1;
    s32 s2;
} S_0067BCA8_E;

typedef struct S_0067BCA8_A {
    s32 type;
    s32 key;
} S_0067BCA8_A;

extern S_0067BC58 D_L39_004AD890[];
extern S_0067BC58 D_L39_004AD910[];
extern char D_L39_00246780[];
extern char *func_00381FF0(s32);
extern s32 func_0011FFA8(char *, s32, const char *, ...);
extern void func_00120D28(char *, char *, s32);
extern s32 func_001206F4(void *, char *);


void func_L39_0067BCA8(S_0067BCA8_A *a, char *out) {
    S_0067BCA8_E *e = 0;
    ASSERT(a->type == 6 || a->type == 7);

    if (a->type == 6) {
        e = (S_0067BCA8_E *)func_L39_0067BC58(a->key, D_L39_004AD890, 8);
    } else if (a->type == 7) {
        e = (S_0067BCA8_E *)func_L39_0067BC58(a->key, D_L39_004AD910, 11);
    }
    if (e != 0) {
        func_0011FFA8(out, 0x50, e->s0 != -1 ? func_00381FF0(e->s0) : D_L39_00246780, a->key);
        out[0x4F] = 0;
        func_00120D28(out + 0x50, e->s1 != -1 ? func_00381FF0(e->s1) : D_L39_00246780, 0xA0);
        out[0xEF] = 0;
        func_00120D28(out + 0xF0, e->s2 != -1 ? func_00381FF0(e->s2) : D_L39_00246780, 0xA0);
        out[0x18F] = 0;
    } else {
        func_001206F4(out, func_00381FF0(0x11B1));
    }
}
/* localdecomp:end func_L39_0067BCA8 */

INCLUDE_ASM("asm/levels", func_L39_0067BE08);

INCLUDE_ASM("asm/levels", func_L39_0067C408);

/* localdecomp:start func_L39_0067C8E8 */
typedef struct { u8 pad[0x25C]; T t; } S_0067C8E8;
extern S_0067C8E8 D_L39_0025D6C0;
extern void func_L39_0067ED40(void);
extern void func_L39_00685FF0(void);
extern void func_L39_006D78F8(void);
extern void func_00392260(s32, s32, s32);

void func_L39_0067C8E8(void) {
    func_L39_0067ED40();
    func_00392260(D_L39_0025D6C0.t.a, D_L39_0025D6C0.t.b, D_L39_0025D6C0.t.c);
    func_L39_00681470();
    func_L39_00685FF0();
    func_L39_006D78F8();
    func_001953B8(0);
    func_001953D0(0);
}
/* localdecomp:end func_L39_0067C8E8 */
