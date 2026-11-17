/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_005341F0, the NTSC-U twin of func_L39_00534880, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" when tried; not with src/levels/shared/L39_00534030.c's current line.
 * Worker's note: MATCH (check_native, 203 words) with -mvu0-use-vf0-vf2 and @ps2as added to the PAL line (-O2 -G8 -fopt-stack -mno-check-zero-division) AND the divs row: NEEDS divs row 'func_L39_005341F0 2 2' (the medium note's '2 3' was wrong: both div.s are preceded by two nops). Only change vs the medium draft: t
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_005341F0 */
/* Needs -mvu0-use-vf0-vf2 (vec_* helpers) and @ps2as (float immediates) beyond the PAL file's flags. */
typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 pad20;
} Pad_005341F0;

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    u8 b20;
    u8 pad21[0x47];
    u8 *p68;
} Obj_005341F0;

extern u8 *D_L39_00296918[];
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern s32 func_0019D650(void);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_L39_005B2498(s32);
extern void func_003BF6A8(f32 *, f32);
extern u8 *func_L39_005C5838(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L39_005341F0(Obj_005341F0 *obj, vu0_v4 *pa, vu0_v4 *pb) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 v30;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 v60;
    u8 *st;
    u8 *fp;
    f32 len;
    s32 n;
    s32 i;

    a = *pa;
    b = *pb;
    if (obj != 0 && obj->b20 != 0xFE && obj->b20 != 0xFD) {
        st = obj->p68;
        fp = *(u8 **)(st + 0x28);
        len = func_00388770(st);
        n = (s32)(len / 0.1f);
        c = b;
        vec_sub_ab(&d, &a, &b);
        func_00388830(&d, &d, len / (f32)n);
        for (i = n; i > 0; i--) {
            s32 life = (s32)func_L39_005B2568(1.0f, 3.0f);
            s32 r;
            s32 size;
            s32 color;
            u8 *p;
            f32 s = func_L39_005B2510(0.1f, 0.3f) * 0.016666668f;
            func_003886E8(&v30, fp + 0x250, -s);
            r = func_L39_005B24C8(3, 6);
            if (func_0019D650() & 2) {
                size = 0x40;
                color = 0x407FFF;
            } else {
                size = 0x60;
                color = 0x4040FF;
            }
            p = func_L01_00466F98(&c, &v30, r, size, color, life, 42000.0f, 1000.0f, 1.0f, 0.0f, 0.0f);
            vec_add_ab(&c, &c, &d);
            if (p != 0) {
                if (func_L39_005B2498(2)) {
                    p[2] = D_L39_00296918[0x184 / 4][4];
                } else {
                    p[2] = D_L39_00296918[0x184 / 4][5];
                }
                p[3] = (size == 0x40) ? 0x48 : 0x44;
            }
        }
        func_003886E8(&v60, st, -0.033333335f);
        {
            s32 color;
            s32 x;
            u8 *p;
            color = 0x7F80DFFF;
            func_003BF6A8(&v60.x, 0.10000001f);
            v60.z += 0.050000004f;
            if (func_L39_005B2498(2)) color = 0x7F407FFF;
            x = func_L39_005B24C8(10, 20);
            p = func_L39_005C5838(obj->pos, &v60, color, 0xFF, x, 0, -1, -1, 0, 94500.0f);
            if (p != 0) {
                *(f32 *)(p + 0x2C) = 0.0016666667f;
                p[2] = *D_L39_00296918[0xD4 / 4];
            }
        }
    }
}
/* localdecomp:end func_L39_005341F0 */
