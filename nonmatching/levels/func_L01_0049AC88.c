/* func_L01_0049AC88: 5 diff (PAL port of the NTSC-U draft; needs the file's context L01_0049A748.c: @ps2as line, D_L01_001D9340 sdata array, func_00381FF0 etc.).
/* b37 W8: reproduced 5 diff; more argument-order variants (temp for the axis2 product, o->y copy, reordered multiplications) give 5-87 */
 * Differences from the NTSC-U C: PAL constants (0.02f frame step, `* 1.2f` on the axis0 term), frontbin callees func_0038DAB8/func_0038DB00, per-arm locals scale/r vs scale2/r2 (stops the cross-jump
 * that merges the two r tails; 123 -> 18), `r = a / s; r += ...` form, v clamp with the D_L01_001D93DC * 0.017453292f expression written out (no `max` local), D_001D52FC alias `[1]` with `.extern 16`,
 * D_L01_001D9340 alias `[1]` + `.extern 4` for the gp-relative `addiu $gp`, and a divs_nops row (2 2). Left: in the mode != 0 arm, before the o->y call, retail schedules `lui/lw D_001D52FC` before
 * `lwc1 $f12,0xf4($s0)`; ours loads $f12 first (5 words rotated). The o->z call just above matches. Tried: r/v temps for the argument, swapped multiplication order. */
#include "common.h"
/* localdecomp:start func_L01_0049AC88 */
typedef struct {
    char pad[0x144];
    f32 axis0;
    f32 axis1;
    f32 axis2;
    char p[0x74];
    s32 buttons;
} In_0049AC88;
typedef struct {
    char pad[0x24];
    char *model;
    char p28[4];
    f32 scale;
    char p30[0xC0];
    f32 x;
    f32 y;
    f32 z;
} Ob_0049AC88;
typedef struct {
    s32 a;
    s32 b;
    s32 mode;
    s32 text;
} Row_0049AC88;
extern In_0049AC88 *D_001D52FC_0049AC88[1];
__asm__(".extern D_001D52FC_0049AC88, 16");
extern s32 D_L01_001D9340_0049AC88[1];
__asm__(".extern D_L01_001D9340_0049AC88, 4");
extern s32 D_L01_001D9380;
extern s32 D_L01_001D9384;
extern f32 D_L01_001D93D4;
__asm__(".extern D_L01_001D93D4, 4");
extern f32 D_L01_001D93D8;
__asm__(".extern D_L01_001D93D8, 4");
extern f32 D_L01_001D93DC;
__asm__(".extern D_L01_001D93DC, 4");
extern f32 D_L01_001D93D0;
__asm__(".extern D_L01_001D93D0, 4");
extern f32 D_L01_001D93C0;
__asm__(".extern D_L01_001D93C0, 4");
extern f32 D_L01_001D93C4;
__asm__(".extern D_L01_001D93C4, 4");
extern f32 D_L01_001D93CC;
__asm__(".extern D_L01_001D93CC, 4");
extern Row_0049AC88 D_L01_002EBDE8[];
extern void func_L01_00516090_0049AC88(void *);
extern s32 func_L01_0049B428(s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L01_0049AC88(void *arg) {
    Ob_0049AC88 *o;
    f32 v;
    f32 max;
    f32 scale;
    f32 r;
    f32 scale2;
    f32 r2;

    if (D_001D52FC_0049AC88[0]->buttons & 0x910) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090_0049AC88(arg);
    }
    if (D_001D52FC_0049AC88[0]->buttons & 4) {
        D_L01_001D9380 = D_L01_001D9384;
        D_L01_001D9384 = func_L01_0049B428(D_L01_001D9384);
    } else if (D_001D52FC_0049AC88[0]->buttons & 8) {
        D_L01_001D9380 = D_L01_001D9384;
        D_L01_001D9384 = func_L01_0049B490(D_L01_001D9384);
    }
    if (D_L01_001D9384 != -1) {
        o = (Ob_0049AC88 *)D_L01_001D9340_0049AC88[D_L01_001D9384];
        if (o) {
            if (D_L01_002EBDE8[D_L01_001D9384].mode == 0) {
                o->x = func_0038DAB8(o->x, D_001D52FC_0049AC88[0]->axis1 * (-(D_L01_001D93D4 * 0.017453292f * 0.020000001f)));
                v = func_0038DB00(o->y, 1.57079637f);
                v = func_0038DAB8(v, D_001D52FC_0049AC88[0]->axis2 * (-D_L01_001D93D8 * 0.017453292f * 0.020000001f));
                if (v > D_L01_001D93DC * 0.017453292f) v = D_L01_001D93DC * 0.017453292f; else if (v < -(D_L01_001D93DC * 0.017453292f)) v = -(D_L01_001D93DC * 0.017453292f);
                o->y = func_0038DAB8(1.57079637f, v);
                scale = *(f32 *)(o->model + 36);
                r = o->scale / scale;
                r += D_001D52FC_0049AC88[0]->axis0 * (-D_L01_001D93D0 * 1.2f);
                if (r > D_L01_001D93C4) r = D_L01_001D93C4;
                if (r < D_L01_001D93C0) r = D_L01_001D93C0;
                o->scale = scale * r;
            } else {
                o->z = func_0038DAB8(o->z, D_001D52FC_0049AC88[0]->axis1 * (D_L01_001D93D4 * 0.017453292f * 0.020000001f));
                o->y = func_0038DAB8(o->y, D_001D52FC_0049AC88[0]->axis2 * (-D_L01_001D93D8 * 0.017453292f * 0.020000001f));
                max = D_L01_001D93DC * 0.017453292f;
                if (o->y > max) o->y = max; else if (o->y < -max) o->y = -max;
                scale2 = *(f32 *)(o->model + 36) * D_L01_001D93CC;
                r2 = o->scale / scale2;
                r2 += D_001D52FC_0049AC88[0]->axis0 * (-D_L01_001D93D0 * 1.2f);
                if (r2 > D_L01_001D93C4) r2 = D_L01_001D93C4;
                if (r2 < D_L01_001D93C0) r2 = D_L01_001D93C0;
                o->scale = scale2 * r2;
            }
        }
        func_L01_00516FD8(0x4D0003, func_00381FF0(D_L01_002EBDE8[D_L01_001D9384].text));
        func_L01_00516D60(0x4D0003, 1);
    } else {
        func_L01_00516D60(0x4D0003, 0);
    }
}
/* localdecomp:end func_L01_0049AC88 */
