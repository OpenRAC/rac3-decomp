/* func_L24_0034FE28: 200 differences, nearly all one shifted instruction (level 24, file L24_0034F040.c, -mvu0-use-
   vf0-vf2 @ps2as; needs a config/levels/divs_nops.txt row 'func_L24_0034FE28 2 0', not committed). The beam effect
   (attachment point and matrix row 2, three func_L01_00446780 sparks, func_L24_0034FCF8 hit test and the
   D_L24_001E8F60 impact flash through func_L01_00464EC8, then the segment loop with VU0 adds) has retail's calls and
   blocks; this C hoists the 0.3f constant of the loop's last call into a saved FP register ($f25 saved, frame entries
   shifted), retail reloads it each pass. func_L24_00350288's extern for this function would need u8 * to match the
   definition. Tried: k + 1 as its own statement, a do/while loop. */
#include "common.h"
#include "vu0.h"
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L24_0034FCF8(u8 *, void *, void *, void *, s32, s32, s32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern u8 *func_L01_00464EC8(void *, void *, s32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C4C18(f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern vu0_q D_L24_001E8F60;
extern u8 D_001D66B0[];
__asm__(".extern D_L24_001DD4B4, 4");
__asm__(".extern D_L24_001DD4C4, 4");
__asm__(".extern D_L24_001DD4C8, 4");
__asm__(".extern D_L24_001DD4CC, 4");
extern f32 D_L24_001DD4B4;
extern f32 D_L24_001DD4C4;
extern s32 D_L24_001DD4C8;
extern f32 D_L24_001DD4CC;

void func_L24_0034FE28(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 m[16];
    f32 d[4];
    f32 p[4];
    f32 a[4];
    f32 b[4];
    f32 e[4];
    f32 c[4];
    f32 t[4];
    f32 len;
    f32 k;
    u8 *q;
    s32 i;

    func_003C2EC0(obj, 2, m);
    *(vu0_q *)d = *(vu0_q *)m;
    func_003C2F58(obj, 2, p);
    func_0038CF68(a, d, D_L24_001DD4CC);
    len = D_L24_001DD4CC;
    func_0038CF68(b, d, D_L24_001DD4C4 * 0.020000001f);
    vec_add_ba(b, b, s + 0x100);
    func_L01_00446780(obj, (u8 *)p, 0x8110000, 9, 1, 0, 0.3f, D_L24_001DD4B4, 1.0f);
    vec_add_ab(e, a, p);
    func_L01_00446780(obj, (u8 *)e, 0x8110000, 9, 1, 0, 0.6f, D_L24_001DD4B4, 1.0f);
    if (((s32 (*)(u8 *, void *, void *, s32, s32, s32, s32, f32, f32))func_L24_0034FCF8)(obj, p, e, 0x8110000, 9, 1, 0, D_L24_001DD4B4, 1.0f) != 0) {
        *(vu0_q *)a = D_L24_001E8F60;
        len = func_0038CF38(p, a);
        q = func_L01_00464EC8(a, D_001D66B0, 0, 0.2f);
        if (q != 0) {
            *(f32 *)(q + 0xC) = *(f32 *)(q + 0xC) * 4.0f;
        }
    }
    func_0038CE20(c, b, 1.0f / (f32)D_L24_001DD4C8);
    for (i = 0; i < D_L24_001DD4C8; ) {
        func_003C4C18(p, (f32)i * 0.02f);
        q = func_L01_00464EC8(p, a, i & 0xFF, len);
        if (q != 0) {
            *(s16 *)(q + 0xA) = (s32)(len / (D_L24_001DD4C4 * 0.020000001f)) + 6;
            q[0x3D] = q[0xA];
        }
        {
            vu0_q qa, qb, qr;
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)c));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)p));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)p) : "j"(qr));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)t) : "j"(qr));
        }
        i++;
        k = func_003824E0(0.1f, 0.9f);
        func_0038CE20(e, a, k);
        vec_add_ab(e, e, p);
        func_L01_00446780(obj, (u8 *)e, 0x8110000, 9, 1, 0, (k + 1.0f) * 0.3f, D_L24_001DD4B4, 1.0f);
    }
}
