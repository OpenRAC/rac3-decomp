#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003D3228 */
typedef struct {
    u8 pad0[0x84];
    s32 w84;
    u8 pad88[8];
    s32 w90;
    u8 pad94[4];
    s32 w98;
    u8 pad9C[0x1C];
    f32 fB8;
    u8 padBC[0x18];
    s32 wD4;
    u8 padD8[0x18];
    u8 padF0[0x48];
    f32 f138;
    u8 pad13C[0x7C];
    f32 f1B8;
} St_3D3228;

typedef struct {
    u8 pad0[0x19E0];
    u8 *p19E0;
    u8 pad19E4[0xFFC];
} Hero_3D3228;

extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 4");
extern f32 D_L04_001DEB80;
__asm__(".extern D_L04_001DEB80, 4");
extern f32 D_L04_001DEBB4;
__asm__(".extern D_L04_001DEBB4, 4");
extern Hero_3D3228 D_001A4BE0;
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00446BC8(void *, void *, s32, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004EDE10(void);
extern void func_L01_00456230(void *, s32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_L04_003D37F8(void *, void *);
extern void func_L04_003D3520(void *, void *);

s32 func_L04_003D3228(u8 *o, u8 *s) {
    St_3D3228 *st = (St_3D3228 *)s;
    u8 *a;
    u8 *h;
    s32 b;
    s32 idx;
    f32 f;

    func_L01_0044ABD0(o, s + 0x1F0);
    if (o[0x20] == 5) {
        *(s32 *)(o + 0x78) = 0;
        b = o[0x43];
        if ((u32)(b - 1) < 2 || (u8)b == 5 || (u8)b == 4) {
            if (o[0x60] & 2) {
                func_003C3A10(o, 0, 0, 5);
            }
        }
        if (st->wD4 != 0) {
            idx = *(s32 *)(*(u8 **)(st->wD4 + 0x68) + 0x50);
            if (idx == -1) {
                st->wD4 = 0;
            } else {
                a = D_L04_001DFD9C + (idx << 8);
                if (a == 0 || a[0x20] == 0xFE || a[0x20] == 0xFD) {
                    st->wD4 = 0;
                } else {
                    func_L01_00446BC8(a, o, 0x10001, o + 0x10, 9999.0f);
                }
            }
        }
        if (st->w90 != 0) {
            if (st->w98 != 0) {
                if (func_0038CAD0(&st->w98) != 0) {
                    func_L01_004EDE10();
                    func_L01_00456230(o, 0);
                    st->w98 = 0;
                }
            }
        } else {
            st->f138 = st->f138 + 0.008726646f;
            f = st->f138;
            if (0.6981317f < st->f138) {
                st->f138 = 0.6981317f;
            }
            st->f1B8 = st->f138;
            func_L01_0044E850(o, s + 0xF0, 2, 0.0432f, 0.43200004f);
            func_L01_0044E850(o, s + 0x170, 3, 0.0432f, 0.43200004f);
        }
        *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + (st->fB8 - D_L04_001DEB80 - *(f32 *)(o + 0x18)) * 0.11f;
        func_L04_003D37F8(o, s);
        return 0;
    }
    h = func_L01_00447490(o, 1, 0);
    if (h != 0) {
        if (func_0038CAD0(s + 0x84) != 0) {
            if (o[0x20] == 3) {
                *(f32 *)(h + 0x2C) = *(f32 *)(h + 0x2C) * D_L04_001DEBB4;
            }
            f = *(f32 *)(s + 0x30) - *(f32 *)(h + 0x2C);
            *(f32 *)(s + 0x30) = f;
            if (f < 0.0f) {
                *(f32 *)(s + 0x30) = 0.0f;
            }
            s[0x1F7] = 0xFF;
            func_003C4A40(o, s + 0x1F0);
            if (D_001A4BE0.p19E0 == o) {
                *(s16 *)((u8 *)&D_001A4BE0 + 0x21C) = 0xF;
            }
            st->w84 = 0x1E;
        }
        o[0xA8] = 0xFF;
        if (*(f32 *)(s + 0x30) == 0.0f) {
            func_L04_003D3520(o, s);
            return 0;
        }
        return 1;
    }
    func_0038CAD0(s + 0x84);
    return 1;
}
/* localdecomp:end func_L04_003D3228 */
