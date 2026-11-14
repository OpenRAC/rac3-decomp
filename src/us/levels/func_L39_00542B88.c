#include "common.h"
/* localdecomp:start func_L39_00542B88 */
#include "vu0.h"

typedef int Q_00530490 __attribute__((mode(TI)));

extern f32 func_00388770(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00389468(f32, f32);
extern void func_L01_00445558(void *, s32, f32, f32);
extern f32 func_L01_004455F0(void *, f32, void *, f32, f32, f32, s32);
extern void func_L39_005429F0(u8 *);
extern void func_L39_00543220(u8 *);
extern void func_L39_00667AC0(void *, f32);

void func_L39_00542B88(u8 *a0) {
    vu0_v4 v;
    u8 *g;
    u8 *c;
    u8 *t;
    f32 len;
    f32 sc;
    f32 k;
    f32 ang;

    g = *(u8 **)(a0 + 0x68);
    c = *(u8 **)(g + 0x384);
    if (!(*(s32 *)(c + 0x2F8) & 2)) {
        t = *(u8 **)(c + 0x2D8);
        if (t != 0 && t[0x1A14] == 0 && (*(s32 *)(*(u8 **)(t + 0x2558) + 0x1AC) & 4)) {
            vec_sub_ab(&v, t + 0x4D30, a0 + 0x10);
            len = func_00388770(&v);
            sc = 0.0f;
            if (len < 1.5f) {
                sc = 1.0f;
            } else if (len < 3.0f) {
                sc = 1.75f;
            } else if (len < 5.0f) {
                sc = 2.5f;
            }
            if (0.0f < sc) {
                func_003886E8(&v, &v, sc / 10.0f);
            }
            vec_add_ab(a0 + 0x10, a0 + 0x10, &v);
            *(f32 *)(g+0x368)=*(f32 *)(a0+0x18);
            ang = func_00389468(*(f32 *)(a0 + 0xF8), *(f32 *)(c + 0x208));
            k = 10.0f;
            if (0.7853982f < ang) {
                k = 120.0f;
            }
            func_L01_00445558(a0 + 0xF8, 0, *(f32 *)(t + 0x4D68), k * 0.017453292f * 0.0166666675f);
        } else {
            vec_sub_ba(&v, c + 0x1F0, a0 + 0x10);
            func_003886E8(&v, &v, 0.1f);
            vec_add_ab(a0 + 0x10, a0 + 0x10, &v);
            *(f32 *)(g+0x368)=*(f32 *)(a0+0x18);
            ang = func_00389468(*(f32 *)(a0 + 0xF8), *(f32 *)(c + 0x208));
            k = 10.0f;
            if (0.7853982f < ang) {
                k = 120.0f;
            }
            func_L01_00445558(a0 + 0xF8, 0, *(f32 *)(c + 0x208), k * 0.017453292f * 0.0166666675f);
        }
    }
    if (*(s32 *)(c + 0x2F8) & 2) {
        vec_sub_ab(g+0x290,c+0xB0,a0+0x10);
        *(Q_00530490 *)(c+0x270)=*(Q_00530490 *)(g+0x290);
        *(f32 *)(c+0x310)=func_00388770(g+0x290);
        if (*(f32 *)(c+0x310)<0.0016666668234393f) *(f32 *)(c+0x310)=0.0f;
        func_L39_00543220(a0);
        func_L39_00667AC0(c,50.0f);
        func_L01_004455F0(a0+0xF0,*(f32 *)(c+0x200),c+0x280,0.002036217600107193f,0.009999999776482582f,0.1745329350233078f,0);
        func_L01_004455F0(a0+0xF4,*(f32 *)(c+0x204),c+0x284,0.002036217600107193f,0.009999999776482582f,0.1745329350233078f,0);
        func_L01_004455F0(a0+0xF8,*(f32 *)(c+0x208),c+0x288,0.002036217600107193f,0.009999999776482582f,0.1745329350233078f,0);
    } else {
        func_L39_005429F0(a0);
    }
}
/* localdecomp:end func_L39_00542B88 */
