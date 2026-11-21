#include "common.h"
#include "vu0.h"


typedef struct {
    u8 pad0[0x30];
    s32 mode;
    s32 timer;
    u8 pad38[0xC];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u8 *mobys[6];
} G_407638;
typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    s32 i14;
    s32 i18;
    s32 i1C;
} P_407638;
extern G_407638 D_L23_001E5D80;
extern u8 *D_L23_00238930[];
extern s32 D_001D545C;
__asm__(".extern D_L23_001D6AB0, 4");
extern f32 D_L23_001D6AB0;
extern f32 D_L23_001D6AB4;
extern f32 D_L23_001D6AB8;
__asm__(".extern D_L23_001D6A90, 4");
extern P_407638 D_L23_001D6A90 __attribute__((section(".sdata")));
__asm__(".extern D_L23_001D6B90, 4");
extern u8 *D_L23_001D6B90;
__asm__(".extern D_L23_001D6B98, 8");
extern u8 D_L23_001D6B98[8];
__asm__(".extern D_L23_001D6BD8, 8");
extern u8 D_L23_001D6BD8[8];
extern f32 D_L23_001DEF80;
extern f32 D_L23_001DEF70;
extern void func_L01_00423AB8(void);
extern void func_003A58C0(void *, s32);
extern void func_003A7AF8(void *);
extern void func_L01_004048D0(void *, void *);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);
extern void func_L01_00424168(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L23_00406AC0(void *);
extern void func_L23_00406C48(void *);
extern void func_L23_00406D00(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void *func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L03_00411F50(void *, s32);
extern void func_L10_004079E0(void *);

/* localdecomp:start func_L23_00407638 */
void func_L23_00407638(void) {
    s32 i;
    u8 *o;
    s32 t;
    s32 i2;
    s32 k;
    G_407638 *g;
    u8 *a;
    u8 *b;
    P_407638 p;
    vu0_v4 v;
    f32 f;
    s32 r;

    func_L01_00423AB8();
    for (i = 0; i < D_L23_001E5D80.count; i++) {
        o = D_L23_001E5D80.mobys[i];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0xE29) {
            *(u16 *)(o + 0x34) |= 0x800;
        }
        if (*(s16 *)(o + 0xAA) == 0xD54) {
            o[0x63] = 0;
            for (i2 = 0; D_L23_00238930[i2] != 0; i2++) {
                if (D_L23_00238930[i2][0x63] != 0) {
                    D_L23_00238930[i2][0x63] = 1;
                }
            }
            func_003A58C0(o, 0);
            func_L01_004048D0(func_003A7AF8, o);
        }
        if (o == 0) {
            continue;
        }
        t = *(s16 *)(o + 0xAA);
        if (t == 0xFA0) {
            if (*(u8 **)(o + 0x68) != 0) {
                func_L01_00451DB8(o, *(u8 **)(o + 0x68) + 0xC, 0x80AAAAD2, 0x80396464, 0.073303834f);
            }
        } else if (t == 0x1DEE || t == 0x19BC) {
            func_L01_00451DB8(o, &D_L23_001D6AB0, 0x80505080, 0x80404038, 0.038397245f);
        } else if (t == 0x1977) {
            func_L01_00451DB8(o, &D_L23_001D6AB4, 0x8080AAAA, 0x80464646, 0.045378566f);
        } else if (t == 0x1766) {
            func_L01_00451DB8(o, &D_L23_001D6AB8, 0x80AAAAFF, 0x80646496, 0.13264504f);
        } else if (t == 0x195B || t == 0x1B58 || t == 0x195C || t == 0x175A) {
            func_L01_00404808(func_L01_00424168, o);
        }
    }
    if (D_001D545C == 0x17) {
        if (D_L23_001E5D80.mode == 0) {
            o = D_L23_001E5D80.mobys[3];
            if (o != 0) {
                func_L23_00406AC0(o);
                func_L01_00404808(func_L23_00406C48, o);
            }
            if (D_L23_001E5D80.timer >= 0x683 && D_L23_001E5D80.timer < 0x69A) {
                a = D_L23_001E5D80.mobys[0];
                p = D_L23_001D6A90;
                p.h0 = 0x14;
                p.h2 = 0xF;
                p.f4 = 0.4f;
                p.f8 = 0.2f;
                p.f10 = 0.2f;
                p.i1C = 8;
                b = D_L23_001E5D80.mobys[1];
                func_003C2F58(a, 2, &D_L23_001DEF70);
                func_003C2F58(b, 0, &D_L23_001DEF80);
                for (k = 0; k < p.i1C; k++) {
                    if (!(k & 1)) {
                        qzero(&v);
                        vec_sub_ba(&v, &D_L23_001DEF80, &D_L23_001DEF70);
                        func_0038CF68(&v, &v, 0.00320000015f);
                        func_003C4C18(&v, 0.00480000069f);
                        f = func_003824E0(p.f8, p.f4);
                        r = func_00382498(p.h2, p.h0);
                        func_L01_0046C470(&D_L23_001DEF70, &v, 0x80403080, f, r, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
                    }
                    qzero(&v);
                    vec_sub_ab(&v, &D_L23_001DEF70, &D_L23_001DEF80);
                    func_0038CF68(&v, &v, 0.008f);
                    func_003C4C18(&v, 0.012000001f);
                    f = func_003824E0(p.f8, p.f4);
                    r = func_00382498(p.h2, p.h0);
                    func_L01_0046C470(&D_L23_001DEF80, &v, 0x80403080, f, r, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
                }
                func_L01_00404808(func_L23_00406D00, a);
            }
            if (D_L23_001E5D80.timer >= 0x6CE) {
                o = D_L23_001E5D80.mobys[5];
                if (o != 0) {
                    func_L03_00411F50(o, 0);
                    func_L03_00411F50(o, 1);
                }
            }
        } else if (D_L23_001E5D80.mode == 1) {
            D_L23_001D6B90 = D_L23_001D6B98;
            func_L10_004079E0(D_L23_001D6BD8);
        }
    }
}
/* localdecomp:end func_L23_00407638 */
