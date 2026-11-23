#include "common.h"

/* localdecomp:start func_L07_003DC598 */
extern void func_0038CC88(void *, void *, s32);
extern f32 func_003C4088(f32, f32, f32);
extern int func_L01_00448070(int, int, f32);

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    u8 pad[8];
} S_3DC598;

void func_L07_003DC598(S_3DC598 *dst, S_3DC598 *a, S_3DC598 *b, f32 t) {
    if (a == b || t <= 0.0f) {
        func_0038CC88(dst, a, 0x20);
    } else if (t >= 1.0f) {
        func_0038CC88(dst, b, 0x20);
    } else {
        dst->f0 = func_003C4088(a->f0, b->f0, t);
        dst->f4 = func_003C4088(a->f4, b->f4, t);
        dst->f8 = func_003C4088(a->f8, b->f8, t);
        dst->fC = func_003C4088(a->fC, b->fC, t);
        dst->f10 = func_003C4088(a->f10, b->f10, t);
        dst->b14 = func_L01_00448070(a->b14, b->b14, t);
        dst->b15 = func_L01_00448070(a->b15, b->b15, t);
        dst->b16 = func_L01_00448070(a->b16, b->b16, t);
        dst->b17 = func_L01_00448070(a->b17, b->b17, t);
    }
}
/* localdecomp:end func_L07_003DC598 */

/* localdecomp:start func_L07_003DC6E8 */
typedef int Q_3DC6E8 __attribute__((mode(TI)));

typedef struct {
    u8 p0[0x10];
    Q_3DC6E8 pos;
} M_3DC6E8;

typedef struct {
    u8 p0[0x68];
    u8 *f68;
    u8 p6C[0xB8 - 0x6C];
    M_3DC6E8 *fB8;
} S_3DC6E8;

typedef struct {
    u8 p0[0xE0];
    Q_3DC6E8 aE0;
    u8 pF0[0x25C0 - 0xF0];
    M_3DC6E8 *a25C0;
} H_3DC6E8;

extern f32 func_L01_0040E548(void *, void *);
extern void func_L07_003DC790(S_3DC6E8 *, M_3DC6E8 *, Q_3DC6E8 *, f32);
extern M_3DC6E8 *D_L07_0021C460[];
extern H_3DC6E8 D_001A4BE0;

void func_L07_003DC6E8(S_3DC6E8 *self) {
    f32 d;
    s32 i;
    M_3DC6E8 *m;
    Q_3DC6E8 q;

    d = func_L01_0040E548(self->f68, self->f68 + 0x70);
    for (i = 0; (m = D_L07_0021C460[i]) != 0; i++) {
        if (m != self->fB8) {
            q = m->pos;
            func_L07_003DC790(self, m, &q, d);
        }
    }
    q = D_001A4BE0.aE0;
    func_L07_003DC790(self, D_001A4BE0.a25C0, &q, d);
}
/* localdecomp:end func_L07_003DC6E8 */

/* localdecomp:start func_L07_003DC790 */
void func_L07_003DC790(S_3DC6E8 *m, M_3DC6E8 *other, Q_3DC6E8 *position, f32 radius) {
    extern f32 func_L01_0040E570(void *, void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L01_00446630(void *, void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
    Q_3DC6E8 direction, projected, point;
    u8 *vars=m->f68;
    s32 point_address=(s32)&point;
    s32 projected_address;
    s32 direction_address;
    s32 best=0;
    s32 i, neighbor, offset;
    u8 *cur;
    f32 closest, d, prev;
    point=*position;
    closest=func_L01_0040E570((void *)point_address,(u8 *)m+0x10);
    if (radius < closest) return;
    cur=vars+16;
    i=1;
    projected_address=(s32)&projected;
    for (;i<7;i++,cur+=16) {
        d=func_L01_0040E570((void *)point_address,cur);
        if (d<closest) { closest=d; best=i; }
    }
    offset=best*16;
    prev=func_L01_0040E570((void *)point_address,vars+(offset-16));
    neighbor=best+1;
    d=func_L01_0040E570((void *)point_address,vars+(offset+16));
    if (prev<d) neighbor=best-1;
    func_L01_00446630((void *)projected_address,vars+best*16,vars+neighbor*16,(void *)point_address);
    d=func_L01_0040E548((void *)point_address,(void *)projected_address);
    if (1.0f < d) return;
    __asm__ __volatile__("lqc2 $vf1, 0x80(%0)\n\tlqc2 $vf2, 0(%0)" : : "r"(vars+best*16) : "vf1", "vf2");
    direction_address=(s32)&direction;
    __asm__ __volatile__("vsub.xyz $vf2, $vf2, $vf1" : : : "vf1", "vf2");
    __asm__("sqc2 $vf2, %0" : "=m"(direction) : : "vf2");
    func_0038CE20((void *)direction_address,(void *)direction_address,1.0f);
    func_L01_00446A70(other,m,0x10001,(void *)projected_address,(void *)direction_address,*(f32 *)(vars+0x11C));
}
/* localdecomp:end func_L07_003DC790 */

/* localdecomp:start func_L07_003DC940 */
typedef int Q_003DC940 __attribute__((mode(TI)));
extern void func_L07_003DCFF8(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_L07_003DCB60(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L07_003DC940(u8 *o)
{
    u8 *s;
    s32 i;
    Q_003DC940 *q;
    f32 x, y;
    Q_003DC940 a, b;

    if (o == 0 || o[0x20] == 0xFE || o[0x20] == 0xFD) {
        return;
    }
    s = *(u8 **)(o + 0x68);
    *(f32 *)(s + 0x120) += 0.1f;
    if (*(f32 *)(s + 0x120) >= 4.0f) {
        *(f32 *)(s + 0x120) -= 4.0f;
    }
    q = (Q_003DC940 *)(s + 0x10);
    for (i = 0; i < 7; i++) {
        a = q[-1];
        b = q[0];
        q++;
        func_L07_003DCFF8(o, &a, &b);
    }
    x = func_003824E0(0.03f, 0.05f);
    y = func_003824E0(3.0f, 5.0f);
    if (o[0x95] == 1) {
        x = func_003824E0(0.05f, 0.07f);
        y = func_003824E0(3.0f, 5.0f);
    }
    func_L07_003DCB60(s, 7, 79, 0x7F7F7F, 0xFF2020, 0, x, y);
}
/* localdecomp:end func_L07_003DC940 */
