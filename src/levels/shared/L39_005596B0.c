#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* localdecomp:start func_L39_005596B0 */
typedef struct { u8 p0[0x14C]; u8 f14C; u8 p1; s16 f14E; } V_005596B0;
typedef struct { u8 p0[0x68]; V_005596B0 *v; } M_005596B0;
void func_L39_005596B0(M_005596B0 *m) {
    V_005596B0 *v = m->v;
    if (v->f14C == 1) {
        v->f14E++;
        if (v->f14E >= 0xFB) {
            v->f14C = 0;
            v->f14E = 0;
        }
    }
}
/* localdecomp:end func_L39_005596B0 */

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
