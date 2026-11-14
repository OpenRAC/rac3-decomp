#include "common.h"

/* localdecomp:start func_L39_004EA410 */
typedef struct S_004EA410 {
    char _p0[0x4];
    void *f4;
    char _p8[0x4];
    void *fC;
    char f10[0x8];
    void *f18;
} S_004EA410;
extern char D_L39_00477538[];
extern s32 func_L39_004BECF0(void *, s32, s32, char *, s32);
extern void func_L39_004BEF28(void *);
extern void func_L39_004E2D68(void *);
extern void func_L39_004E47F8(void *);

void func_L39_004EA410(S_004EA410 *p) {
    if (p == 0) {
        return;
    }
    if (func_L39_004BECF0(p->f10, -1, 9, D_L39_00477538, 0xDB) > 0) {
        return;
    }
    if (p->fC != 0) {
        func_L39_004E2D68(p->fC);
    }
    if (p->f4 != 0) {
        func_L39_004E47F8(p->f4);
    }
    if (p->f18 != 0) {
        func_L39_004BEF28(p->f18);
    }
    func_L39_004BEF28(p);
}
/* localdecomp:end func_L39_004EA410 */

/* localdecomp:start func_L39_004EA4A8 */
extern void *(*D_L39_0046D3AC[])(void);
extern void *func_L39_005059C0(void *);

void *func_L39_004EA4A8(void) {
    return func_L39_005059C0(D_L39_0046D3AC[0]());
}
/* localdecomp:end func_L39_004EA4A8 */

LINKER_REMNANT("asm/levels", func_L39_004EA4D8);

/* localdecomp:start func_L39_004EA4E0 */
typedef struct {
    char _p0[0xC];
    s32 fC;
    s32 f10;
} R_004EA4E0;
typedef struct {
    char _p0[4];
    void *f4;
} S_004EA4E0;
extern s32 func_L39_004E4AE8(void *container, u32 category, u32 key, s32 *cursor, R_004EA4E0 **output, u32 flags);

s32 func_L39_004EA4E0(S_004EA4E0 *p, u32 key, s32 *a, s32 *b) {
    R_004EA4E0 *r;

    func_L39_004E4AE8(p->f4, 0x10, key, 0, &r, 0);
    if (r != 0) {
        if (a != 0) {
            *a = r->fC;
        }
        if (b != 0) {
            *b = r->f10;
        }
        return 0;
    }
    if (a != 0) {
        *a = 0;
    }
    if (b != 0) {
        *b = 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004EA4E0 */
