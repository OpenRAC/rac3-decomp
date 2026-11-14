#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L24_003515A8 (src/levels/24_insomniac_museum/) */
/* localdecomp:start func_L24_00350620 */
typedef struct {
    vu0_q dir;
    u8 *owner;
    s32 flags;
    u8 b58;
    u8 b59;
    u16 h5A;
    f32 f5C;
    s32 f60;
} Hit_00350620;
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(f32 *, void *, f32);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00460318(void *, void *, u32, u32, s32, s32, s32, s32);
extern void func_L01_0044E108(void *, void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, s32, void *);
extern s32 func_L01_003F9498(void *, s32, s32, f32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_00447D00(void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003CF790(void *, s32, s32, void *, f32);
extern void func_003BD360(void *);

void func_L24_00350620(u8 *obj) {
    u8 *pos = obj + 0x10;
    u8 *s = *(u8 **)(obj + 0x68);
    f32 a20[4];
    f32 from[4];
    f32 v40[4];
    f32 v50[4];
    f32 v60[4];
    s32 r0;
    s32 r1;
    f32 f;

    *(vu0_q *)a20 = *(vu0_q *)pos;
    *(vu0_q *)from = *(vu0_q *)pos;
    if (obj[0x20] == 0) {
        *(vu0_q *)(v60) = 0;
        v60[0] = func_0037E250(-1.0f, 1.0f);
        v60[1] = func_0037E250(-1.0f, 1.0f);
        v60[2] = func_0037E250(-1.0f, 1.0f);
        *(vu0_q *)(v50) = *(vu0_q *)(v60);
        func_00388830(v50, v50, func_0037E250(0.1f, 0.2f) * 0.016666668f);
        func_00388830(v40, s, -func_0037E250(0.0016666668f, 0.016666668f));
        vec_add_ba(v50, v50, v40);
        func_003886E8(v40, s, func_0037E250(0.0f, 1.0f));
        vec_add_ab(v40, v40, pos);
        r0 = func_0037E208(0x1C, 0x28);
        r1 = func_0037E208(0x28, 0x46);
        func_L01_00460318(v40, v50, 0x6F00AFFF, 0x100000FF, r0, 0x28, r1, 1);
        vec_add_ba(pos, pos, s);
        *(f32 *)(obj + 0xF8) = func_00388A28(*(f32 *)s, *(f32 *)(s + 4));
        *(f32 *)(obj + 0xF4) = -func_00388A28(func_003887A0(s), *(f32 *)(s + 8));
        func_L01_0044E108(obj, s, s, *(f32 *)(s + 0x18));
        ((Hit_00350620 *)v40)->owner = obj;
        ((Hit_00350620 *)v40)->flags = 0x10001;
        ((Hit_00350620 *)v40)->f5C = *(f32 *)(s + 0x20);
        ((Hit_00350620 *)v40)->f60 = 1;
        *(vu0_q *)v40 = *(vu0_q *)s;
        func_00388830(v40, v40, *(f32 *)(s + 0x24));
        v40[3] = 5627.925f;
        ((Hit_00350620 *)v40)->b58 = s[0x28];
        ((Hit_00350620 *)v40)->b59 = s[0x2C];
        ((Hit_00350620 *)v40)->h5A = *(u16 *)(obj + 0xAA);
        if (func_003CE740(from, pos, 0, *(s32 *)(s + 0x10), v40) != 0
            || func_L01_003F9498(pos, 0, *(s32 *)(s + 0x10), 0.2f) != 0) {
            func_0039FE80(0, 0, obj);
            f = *(f32 *)(s + 0x14);
            func_L01_00447D00(obj, s, 0, (s32)(f * 5.0f), (s32)(f * 4.0f), (s32)(f * 10.0f), -1, 1, 1, -1, 0,
                              0x01010001, 0.0f, 0.0f, f * 4.0f, f + f, 9.0f, *(f32 *)(s + 0x14), f * 15.0f);
            func_003CF790(pos, 0x10, *(s32 *)(s + 0x10), v40, *(f32 *)(s + 0x14) * 4.0f);
            func_003BD360(obj);
            return;
        }
    }
    if (*(f32 *)(obj + 0x10) < 2.0f || 1021.0f < *(f32 *)(obj + 0x10) || *(f32 *)(obj + 0x14) < 2.0f
        || 1021.0f < *(f32 *)(obj + 0x14) || *(f32 *)(obj + 0x18) < 2.0f || 1021.0f < *(f32 *)(obj + 0x18)) {
        func_003BD360(obj);
    }
}
/* localdecomp:end func_L24_00350620 */
