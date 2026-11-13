#include "common.h"

/* NTSC-U counterpart of func_L39_0066BBB8 (src/levels/shared/L39_0066BB58.c) */
typedef struct N_0066BB58 N_0066BB58;
struct N_0066BB58 {
    s32 pad0[2];
    s32 f8;
    s32 fC;
    u8 pad10[0x74];
    N_0066BB58 *f84;
};
extern N_0066BB58 *D_L39_0024D064;
extern void func_L39_00669AC0(N_0066BB58 *, N_0066BB58 **);

/* localdecomp:start func_L39_006692B0 */
typedef struct N_0066BBB8 {
    s32 w0;
    s32 w4;
    s32 type;
    s32 wC;
    s32 time;
    s32 n;
    s32 data[(0x84 - 0x18) / 4];
    struct N_0066BBB8 *next;
} N_0066BBB8;
typedef struct { s32 id; s32 a; s32 data[10]; } E_0066BBB8;
typedef struct { s32 id; s32 w4; s32 w8; s32 (*fn)(s32, s32, N_0066BBB8 *); } H_0066BBB8;
typedef struct { u8 pad[0x128]; s32 w128; } G_0066BBB8;
extern E_0066BBB8 D_L39_0033BA90[];
extern H_0066BBB8 D_L39_0033B9F0[];
extern G_0066BBB8 D_001A5E50;
extern struct N_0066BB58 *D_L39_0024D064;
extern void func_L39_00669AC0(struct N_0066BB58 *, struct N_0066BB58 **);
extern s32 func_L39_00669B20(s32);
extern s32 func_L39_00669730(void);
void func_L39_006692B0(void) {
    N_0066BBB8 *p;
    s32 *q;
    s32 *src;
    s32 i;
    s32 j;
    s32 idx;
    for (p = (N_0066BBB8 *)D_L39_0024D064; p != 0; ) {
        q = &p->type;
        switch (p->type) {
        default:
            p = p->next;
            continue;
        case 0:
            if (q[2] > D_001A5E50.w128) {
                p = p->next;
                continue;
            }
            idx = func_L39_00669B20(q[3]);
            if (idx < 0) {
                continue;
            }
            (*D_L39_0033B9F0[idx].fn)(q[1], q[3], p);
            break;
        case 3:
            if (q[2] > D_001A5E50.w128) {
                p = p->next;
                continue;
            }
            for (i = 0; i < 40; i++) {
                if (D_L39_0033BA90[i].id == 0) {
                    break;
                }
            }
            if (i == 40) {
                i = func_L39_00669730();
                if (i == -1) {
                    return;
                }
            }
            src = &q[4];
            D_L39_0033BA90[i].id = q[1];
            D_L39_0033BA90[i].a = q[3];
            for (j = 0; j < q[3]; j++) {
                D_L39_0033BA90[i].data[j] = *src++;
            }
            break;
        }
        p = ((N_0066BBB8 *(*)(N_0066BBB8 *, void *))func_L39_00669AC0)(p, &D_L39_0024D064);
    }
}
/* localdecomp:end func_L39_006692B0 */
