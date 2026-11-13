#include "common.h"

/* declared by functions of L39_0066C808.c, which this file was cut from */
typedef struct {
    u8 pad0[52];
    u16 unk34;
} Src669F78;
typedef struct {
    u8 pad0[8];
    s32 unk8;
} Info669F78;
extern Info669F78 *func_L39_005C1018(Src669F78 *);

/* localdecomp:start func_L39_0066CDD0 */
typedef struct { u8 p0[8]; s32 w8; u8 pC[0xC]; Src669F78 *w18; u8 p1C[4]; void (*fn20)(Src669F78 *); s32 w24; u8 p28[4]; u8 b2C; u8 p2D[3]; s32 w30; u8 p34[0x10]; s32 w44; s32 w48; s32 w4C; u8 p50; u8 b51; } O_0066CDD0;
typedef struct { u8 p0[8]; s32 w8; u8 pC[0x11C]; s32 w128; } G_0066CDD0;
typedef struct { u8 p0[0x14]; void (*fn14)(Src669F78 *, s32); } V_0066CDD0;
extern s32 D_001A5CD0[];
extern s32 D_001A5DF8[];
extern s32 D_L39_00246334;
__asm__(".extern D_L39_00246334, 4");
__asm__(".extern D_L39_00246338, 4");
extern f32 D_L39_00246338;
extern s32 *D_L39_00241120;
extern s32 D_L39_0024112C;
extern Info669F78 *func_L39_005C1018(Src669F78 *);
extern s32 func_L39_0066CB78(void *);
extern s32 func_L39_0066D028(void *, f32 *, f32 *);
extern void func_L39_0066DA90(s32 *, s32, u8, u8);
extern void func_L39_0066DB50(s32 *, s32, u8, u8);
extern void func_L39_0066DC28(s32 *, u8, u8);
void func_L39_0066CDD0(O_0066CDD0 *o) {
    f32 pos[2];
    s32 n;
    s32 same;
    s32 *g;
    if (o->w18 == 0) return;
    if (o->w24 >= 0 && o->w24 <= D_001A5DF8[0]) {
        o->w24 = -1;
        ((V_0066CDD0 *)func_L39_005C1018(o->w18))->fn14(o->w18, 0);
    }
    if (o->fn20 != 0) o->fn20(o->w18);
    if (o->b2C == 0) return;
    if (o->w8 == 2) return;
    g = D_001A5CD0;
    if (!(D_L39_00246334 + 3000 < g[0x128 / 4])) return;
    if (o->w44 == -1) o->w44 = func_L39_0066CB78(o);
    same = 1;
    if (*D_L39_00241120 >= 3) { s32 t = ((s32)o->w18 >> 8 ^ D_L39_0024112C) & 0xF; same = t == 0; }
    if (!same) return;
    if (o->w44 != g[2]) return;
    if (o->w30 + 3000 >= g[0x128 / 4] && o->w48 != -1) return;
    n = func_L39_0066D028(o, &pos[0], &pos[1]);
    if (o->w48 == -1) {
        if (n != -1) {
            func_L39_0066DA90((s32 *)o, n, o->b51, ((u8 *)g)[8]);
            o->w4C = -1;
            o->w48 = n;
            o->b51++;
            return;
        }
    } else if (n == -1) {
        func_L39_0066DC28((s32 *)o, o->b51, ((u8 *)g)[8]);
        o->w48 = n;
        o->w4C = -1;
        o->b51++;
        return;
    }
    if (o->w48 == n) return;
    if (o->w48 == -1) return;
    if (n == -1) return;
    if (pos[1] > D_L39_00246338 && (pos[0] < D_L39_00246338 || pos[0] < pos[1] * 0.5f)) {
        s32 old;
        u8 *q = (u8 *)D_001A5CD0;
        func_L39_0066DB50((s32 *)o, n, o->b51, q[8]);
        old = o->w48;
        o->w48 = n;
        o->w4C = old;
        o->b51 = o->b51 + 1;
    }
}
/* localdecomp:end func_L39_0066CDD0 */

INCLUDE_ASM("asm/levels", func_L39_0066D028);
