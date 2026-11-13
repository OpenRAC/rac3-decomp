#include "common.h"

/* localdecomp:start func_L39_005FC688 */
#include "vu0.h"

typedef struct { u8 p0[0xC]; f32 fC; u8 p10[0x24]; u16 h34; u8 p36[0xA]; u8 b40; u8 b41; u8 p42[2]; f32 f44; u8 p48[0x19]; u8 b61; u8 p62; u8 b63; u8 p64[4]; u8 *w68; u8 p6C[3]; u8 b6F; u8 p70[0x44]; s16 hB4; } O_005FC688;
typedef struct { u8 p0[0x34]; s32 w34; s32 w38; s32 w3C; s16 h40; u8 p42[2]; s16 h44; u8 p46[2]; s16 h48; u8 p4A[0x16]; s8 b60; u8 p61[0x13F]; O_005FC688 *arr[1]; } G_005FC688;
typedef struct { u8 p0[0x1A4]; s32 w1A4; } P_005FC688;

extern G_005FC688 D_L39_0025CEC0;
extern u8 D_L39_0025F500[];
extern f32 D_L39_0024B9D0;
extern s32 D_L39_00240468;
extern P_005FC688 *D_L39_00241164;
extern s32 D_001A5810[];
extern s16 D_L39_00225664[];

extern void func_00392C48(void *);
extern s32 func_L39_005BF840(s32, s32);
extern void func_L39_005FBDD8(void);
extern void func_L04_00433E40(void);
extern void func_003CD058(void);
extern void func_L39_005F3828(void);
extern void func_003CD350(void);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L39_005C18C8(void);
extern s32 func_L39_0059A4A8(void *);
extern void func_L39_005C2B10(s32);
extern void func_L39_005A4C78(void);
extern s32 func_L39_005A4BE8(s32);
extern s32 func_L39_005FC4C0(void);
extern void func_003C29B0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7C38(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_L01_004472C0(void *);
extern void func_L39_0059E8D0(void);
extern void func_L39_005F1718(void);
extern void func_003D0B20(void);
extern void func_L39_005ABA28(void);
extern void func_L39_005FBE08(void);

void func_L39_005FC688(void) {
    s32 k;
    s32 lim;
    s32 done;
    s32 end;
    s32 r;
    s32 i;
    vu0_v4 a, b;

    if (D_L39_0025CEC0.b60 != 0) {
        return;
    }
    if (D_L39_0025CEC0.h40 == 0) {
        func_00392C48(D_L39_0025F500);
        D_L39_0025CEC0.b60 = 1;
        func_L39_005BF840(0, 0);
        return;
    }
    if (D_L39_0025CEC0.h40 < D_L39_0025CEC0.w34 + 15) {
        k = D_L39_0025CEC0.h40 - 15;
        D_L39_0024B9D0 = (f32)(D_L39_0025CEC0.w34 - k) * 0.06666667f;
    }
    func_L39_005FBDD8();
    func_L04_00433E40();
    func_003CD058();
    func_L39_005F3828();
    func_003CD350();
    D_L39_0025CEC0.w38++;
    D_L39_0025CEC0.w34++;
    if (D_L39_0025CEC0.w34 < 25) {
        func_003C4138(&D_L39_0024B9D0, 0.0f, 0.048000004f);
        if (D_L39_0024B9D0 > 1.0f) {
            D_L39_0024B9D0 = 1.0f;
        }
    }
    if (D_L39_0025CEC0.w34 >= D_L39_0025CEC0.h48) {
        func_L39_005C18C8();
    }
    done = 0;
    end = D_L39_0025CEC0.w34 >= D_L39_0025CEC0.h40;
    if (D_L39_0025CEC0.w34 >= 15 && D_L39_0024B9D0 == 0.0f) {
        if (!(D_L39_00240468 & 0x80)) {
            s32 f = D_L39_00240468 & ~0xC0;
            if (f != 2) {
                if (f == 0 && (D_L39_00241164->w1A4 & 0x9FF)) {
                    done = 1;
                } else {
                    s32 m = D_L39_00241164->w1A4 & 0x800;
                    done = m != 0;
                }
            }
        }
    }
    if (done) {
        D_L39_00240468 &= ~0x80;
        D_L39_0025F500[0x64] = 1;
        func_00392C48(D_L39_0025F500);
        D_L39_0025CEC0.b60 = 1;
        func_L39_005BF840(0, 0);
    } else if (end) {
        D_L39_00240468 &= ~0x80;
        D_L39_0025CEC0.b60 = 1;
        if (func_L39_0059A4A8(D_L39_0025F500) == 0) {
            func_L39_005BF840(0, 0);
        }
    } else {
        lim = 0x60;
        if (D_001A5810[0]) {
            lim = 0x50;
        }
        if (D_L39_0025CEC0.w38 >= lim) {
            D_L39_0025CEC0.w3C++;
            if (D_L39_00225664[0] != 0) {
                func_L39_005C2B10(1);
            }
            func_L39_005A4C78();
            func_L39_005A4BE8(D_L39_0025CEC0.w3C + 1);
        }
        r = func_L39_005FC4C0();
        for (i = 0; i < D_L39_0025CEC0.h44; i++) {
            O_005FC688 *o = D_L39_0025CEC0.arr[i];
            u8 *base;
            s32 h = D_L39_0025CEC0.w38 >> 1;
            o->b41 = h + 1;
            o->b40 = h;
            func_003C29B0(o);
            o->f44 = (f32)(D_L39_0025CEC0.w38 & 1) * 0.5f;
            if (r != 0 && (D_L39_0025CEC0.w38 & 1) && o->hB4 == 0) {
                o->f44 = 1.0f;
            }
            base = o->w68;
            func_0038CE20(&a, base + o->b40 * 16, 1.0f - o->f44);
            func_0038CE20(&b, base + o->b41 * 16, o->f44);
            vec_add_ab((u8 *)o + 0x10, &a, &b);
            o->b61 = 0xFF;
            func_003C7C38(o);
            if (o->b63) {
                if (D_L39_0025CEC0.w3C != 0 && D_L39_0025CEC0.w38 < 16) {
                    f32 d = func_0038CF00(o, (u8 *)o + 0xF0);
                    if (d < 20.0f) {
                        f32 s = (f32)D_L39_0025CEC0.w38 * 0.0625f;
                        func_0038CDF8(o, (u8 *)o + 0xF0, o, s);
                        o->fC += d * (1.0f - s);
                    }
                } else {
                    *(vu0_q *)((u8 *)o + 0xF0) = *(vu0_q *)o;
                    o->h34 |= 0x100;
                }
            }
            if (o->b6F) {
                func_L01_004472C0(o);
            }
        }
    }
    func_L39_0059E8D0();
    func_L39_005F1718();
    func_003D0B20();
    func_L39_005ABA28();
    func_L39_005FBE08();
}
/* localdecomp:end func_L39_005FC688 */
