/* PAL near miss, 99 diff (b37 W8; b36 W1's port was 160): PAL port of the NTSC-U draft of func_L01_00301A90, checked with the file's flags and the divs row 'func_L01_00301C38 2 2'.
 * Lever found: PAL scales the frame-count divisor like the other 50/60 Hz code: d = 1.0f - (f32)h[i] / (f32)((D_L01_001DC4CC * 5 + 2) / 6) (retail: sll/addu/addiu 2, div by 6, mflo, cvt.s.w): 160 -> 99.
 * Left: retail keeps the loop bases inside the loop (addiu v0,s5,0x60 / addiu v0,s5,0x58 computed per iteration, then move s1,v0 / move s0,v0, a1 = v0 + s4 for fa[i]) and hoists only st+0x58 as the pointer iv s7 (plus s4 = i*4, s6 = i*2 and a down counter in fp); ours hoists fp = st+0x60 and s7. st sits in s5 in retail (s4 here).
 * Tried: first use of the base through a cast expression before the variable assignment (139-190 diff). */
#include "common.h"
/* localdecomp:start func_L01_00301C38 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00301C38;
typedef struct {
    V4_00301C38 a;
    V4_00301C38 b;
    s32 found;
} Loc_00301C38;

extern V4_00301C38 D_L01_001E29C0_00301C38;
extern u8 *D_L01_00221098[];
extern f32 D_L01_001DC530[2];
__asm__(".extern D_L01_001DC530, 8");
extern f32 D_L01_001DC540[2];
__asm__(".extern D_L01_001DC540, 8");
extern f32 D_L01_001DC550[2];
__asm__(".extern D_L01_001DC550, 8");
extern s32 D_L01_001DC518;
__asm__(".extern D_L01_001DC518, 4");
extern s32 D_L01_001DC51C;
__asm__(".extern D_L01_001DC51C, 4");
extern s32 D_L01_001DC520;
__asm__(".extern D_L01_001DC520, 4");
extern s32 D_L01_001DC524;
__asm__(".extern D_L01_001DC524, 4");
extern s32 D_L01_001DC528;
__asm__(".extern D_L01_001DC528, 4");
extern s32 D_L01_001DC52C;
__asm__(".extern D_L01_001DC52C, 4");
extern s32 D_L01_001DC4CC;
__asm__(".extern D_L01_001DC4CC, 4");

extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CB00(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 *func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);

s32 func_L01_00301C38(u8 *obj) {
    V4_00301C38 va;
    V4_00301C38 vb;
    s32 found;
    u8 *st;
    s16 *h;
    f32 *fa;
    s32 i;
    s32 col;
    s32 al;
    s32 ah;
    f32 f1;
    f32 z;
    f32 d;
    f32 t;
    f32 keep;
    u8 *r;

    st = *(u8 **)(obj + 0x68);
    vec_sub_ab(&va, &D_L01_001E29C0_00301C38, obj + 0x10);
    func_0038CF68(&va, &va, -0.3f);
    found = 0;
    func_0038CF68(&vb, &va, 0.1f);
    vec_add_ba(&va, &va, obj + 0x10);
    z = va.z;
    for (i = 0; i < 4; i++) {
        if (func_0038CB00(st + 0x58 + i * 2) != 0) {
            continue;
        }
        h = (s16 *)(st + 0x58);
        fa = (f32 *)(st + 0x60);
        f1 = fa[i] + D_L01_001DC530[i];
        if (h[i] >= 0x29) {
            found = 1;
        }
        fa[i] = f1;
        if (255.0f <= f1) {
            fa[i] = f1 - 255.0f;
        } else if (f1 <= 0.0f) {
            fa[i] = f1 + 255.0f;
        }
        keep = fabs_asm(0.5f - (f32)(0xD4 - h[i]) / 212.0f);
        if (st[0x57] != 0) {
            col = func_0038DBD8(D_L01_001DC520, D_L01_001DC524, keep);
        } else {
            col = func_0038DBD8(D_L01_001DC518, D_L01_001DC51C, keep);
        }
        d = 1.0f - (f32)h[i] / (f32)((D_L01_001DC4CC * 5 + 2) / 6);
        al = col >> 24;
        va.z = z + D_L01_001DC550[i];
        t = 1.0f - d;
        ah = (s32)((f32)al * t) << 24;
        r = func_L01_0046C2E8(&va, (col & 0xFFFFFF) | ah,
                              (u8)(s32)fa[i], D_L01_001DC52C, 0, 2, 1, 0,
                              D_L01_001DC540[i] * d);
        if (r != 0) {
            r[2] = *D_L01_00221098[0xF8 / 4];
        }
        r = func_L01_0046C2E8(&va, ah | 0xFFFFFF,
                              (u8)(s32)fa[i], D_L01_001DC52C, D_L01_001DC528, 2, 1, 0,
                              D_L01_001DC540[i] * (d * 0.7f));
        if (r != 0) {
            r[2] = *D_L01_00221098[0xF8 / 4];
        }
        vec_add_ab(&va, &va, &vb);
    }
    return found;
}
/* localdecomp:end func_L01_00301C38 */
