#include "common.h"

/* localdecomp:start func_L39_004DD250 */
typedef struct S_004DD250 {
    char _p0[0x4];
    void *f4;
    char _p8[0x4];
    void *fC;
    char f10[1];
} S_004DD250;
extern char D_L39_00476270[];
extern s32 func_L39_004BECF0(void *, s32, s32, char *, s32);
extern void func_L39_004BEF28(void *);
extern void func_L39_004E2D68(void *);
extern void func_L39_004E47F8(void *);

void func_L39_004DD250(S_004DD250 *p) {
    if (p == 0) {
        return;
    }
    if (func_L39_004BECF0(p->f10, -1, 0x17, D_L39_00476270, 0x70) > 0) {
        return;
    }
    if (p->fC != 0) {
        func_L39_004E2D68(p->fC);
    }
    if (p->f4 != 0) {
        func_L39_004E47F8(p->f4);
    }
    func_L39_004BEF28(p);
}
/* localdecomp:end func_L39_004DD250 */

/* localdecomp:start func_L39_004DD2D8 */
typedef struct R_004DD2D8 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 *data;
    s32 len;
} R_004DD2D8;
typedef struct S_004DD2D8 {
    s32 f0;
    void *store;
} S_004DD2D8;
extern s32 func_L39_004E4AE8(void *container, u32 category, u32 key, s32 *cursor, R_004DD2D8 **output, u32 flags);

u32 func_L39_004DD2D8(void *arg0) {
    R_004DD2D8 *r;
    s32 len = 0;

    if (func_L39_004E4AE8(((S_004DD2D8 *)arg0)->store, 0x12, 1, 0, &r, 0) == 0) {
        len = r->len;
        if (len > 0 && r->data[0] == 0) {
            len--;
        }
    }
    return len;
}
/* localdecomp:end func_L39_004DD2D8 */
