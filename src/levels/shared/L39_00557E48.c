#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* localdecomp:start func_L39_00557E48 */
extern u8 *D_L39_0024BF68;
__asm__(".extern D_L39_0024BF68, 16");
extern f32 func_0038CF00(void *, void *);
void *func_L39_00557E48(u8 *pos) {
    u8 *best = 0;
    u8 *o;
    f32 min = 9999.0f;
    f32 d;
    for (o = D_L39_0024BF68; o != 0; o = *(u8 **)(o + 0x28)) {
        if (*(s16 *)(o + 0xAA) == 0x166F) {
            d = func_0038CF00(pos + 0x10, o + 0x10);
            if (d < min) {
                min = d;
                best = o;
            }
        }
    }
    return best;
}
/* localdecomp:end func_L39_00557E48 */

/* localdecomp:start func_L39_00557EF0 */
extern u8 *func_L39_0066B870(s32 a0);
extern u8 *func_L39_0066B8A8(u8 *a0, s32 *a1);
typedef struct { s32 w0; } W_00557EF0;
typedef struct { u8 p0[0x90]; W_00557EF0 *w90; } E_00557EF0;
typedef struct { u8 p0[0x68]; u8 *sub; } B_00557EF0;
typedef struct { u8 p0[0x70]; s32 w70[1]; } BS_00557EF0;
typedef struct { u8 p0[0x2AC]; s32 w2AC; u8 p1[0x4C]; s32 w2FC; u8 p2[0x10]; E_00557EF0 *w310[1]; } V_00557EF0;
typedef struct { u8 p0[0x68]; V_00557EF0 *v; } M_00557EF0;
typedef struct { u8 p0[0x68]; BS_00557EF0 *s; } Best_00557EF0;
void func_L39_00557EF0(M_00557EF0 *m, s32 a1) {
    V_00557EF0 *v = m->v;
    Best_00557EF0 *best;
    u8 *it;
    u8 *r;
    E_00557EF0 *e;
    s32 i;
    s32 k = 0;
    v->w2FC = 0;
    best = func_L39_00557E48((u8 *)m);
    it = func_L39_0066B870(v->w2AC);
    for (i = 0; (r = func_L39_0066B8A8(it, &i)) != 0 && (e = *(E_00557EF0 **)(r + 0x1C)) != 0; i++) {
        v->w310[v->w2FC] = e;
        if (best != 0 && a1 == 0) {
            best->s->w70[k++] = e->w90->w0;
        }
        v->w2FC++;
    }
}
/* localdecomp:end func_L39_00557EF0 */
