#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

INCLUDE_ASM("asm/levels", func_L01_0035F480);

/* localdecomp:start func_L01_0035FEB8 */
void func_L01_0035FEB8(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_0035FEB8 */

INCLUDE_ASM("asm/levels", func_L01_0035FEC8);

/* localdecomp:start func_L01_00360170 */
#include "vu0.h"
extern f32 D_L01_001DD710;
__asm__(".extern D_L01_001DD710, 4");
extern u8 D_001A4C60[];
void func_L01_00360170(u8 *obj) {
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_003C4C18(void *, f32);
    extern void func_L01_00360398(void *, s32, s32, s32, f32, f32, f32);
    S_38C110v hero_pos;
    S_38C110v angles;
    S_38C110v forward;
    S_38C110v points[20];
    S_38C110v base;
    S_38C110v offset;
    S_38C110v transformed;
    S_38C110v dir;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 i;
    f32 t, scale, spread, angle_step;
    D_L01_001DD710 -= 0.0275f;
    t = D_L01_001DD710;
    if (t < 0.0f) t = 0.0f;
    *(s128 *)&hero_pos = *(s128 *)D_001A4C60;
    func_003C5180(&hero_pos, &angles, 1);
    angle_step = 0.31415927f;
    func_0038CF68(&forward, *(u8 **)(D_001A4C60 + 0x2540) + 0xc0, 1.0f);
    scale = (1.0f - t) * 10.0f + 0.05f;
    spread = (1.0f - t) * 0.5f;
    if (func_L01_004CB2D8()) func_L01_004CAB30(vars, vars);
    *(s128 *)&base = *(s128 *)vars;
    func_L01_004C7D98(obj + 0x10, &offset);
    func_0038CF68(&offset, &offset, 0.75f);
    vec_add_ab(&base, &offset, &base);
    for (i = 0; i < 20; i++) {
        func_003C4840(&dir, &angles, i * angle_step);
        func_0038D850(&transformed, &forward, &dir);
        func_0038CE20((s128 *)&transformed, (s128 *)&transformed, scale);
        func_003C4C18(&transformed, spread);
        vec_add_ab(&points[i], &base, &transformed);
    }
    func_L01_00360398(points, *(s32 *)(vars + 0x1c) * 5, *(s32 *)(vars + 0x1c) * 5, 20, 0.4f, 0.9f, 0.2f);
}
/* localdecomp:end func_L01_00360170 */

INCLUDE_ASM("asm/levels", func_L01_00360398);

/* localdecomp:start func_L01_003609D0 */
extern void func_L01_00361D60_003609D0(void *);
extern void func_L01_003609D0(void *);

extern void func_L01_00361AC0_003609D0();
void func_L01_003609D0(void *p) {
    func_L01_00361AC0_003609D0(p);
    func_L01_00361D60_003609D0(p);
}
/* localdecomp:end func_L01_003609D0 */

/* localdecomp:start func_L01_00360A00 */
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s16 D_001CFEC0[];

void func_L01_00360A00(void) {
    func_003A9440(66, 72);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], (s32)0x80808080);
}
/* localdecomp:end func_L01_00360A00 */

/* localdecomp:start func_L01_00360A48 */
#include "vu0.h"
typedef struct {
    u8 pad00[0x18];
    f32 f18;
    u8 pad1C[0x14];
    f32 f30;
    f32 f34;
} S_00360A48;
typedef struct {
    vu0_v4 p[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long tag0, texture, tag1, tag2;
} Strip_00360A48;
typedef struct { u8 p0; u8 kind; u8 pad[0xEE]; } Gun_00360A48;
extern f32 D_L01_001DD718;
extern f32 D_L01_001DD71C;
extern f32 D_L01_001DD720;
extern f32 D_L01_001DD724;
extern f32 D_L01_001DD728;
extern f32 D_L01_001DD72C;
__asm__(".extern D_L01_001DD718, 4");
__asm__(".extern D_L01_001DD71C, 4");
__asm__(".extern D_L01_001DD720, 4");
__asm__(".extern D_L01_001DD724, 4");
__asm__(".extern D_L01_001DD728, 4");
__asm__(".extern D_L01_001DD72C, 4");
extern u8 D_L01_001E2A40[];
extern u8 D_001A4EC0[];

void func_L01_00360A48(u8 *o) {
    extern u8 D_00142637[];
    extern Gun_00360A48 D_L01_002C5600_00360A48[];
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
    extern void func_L01_0040AAC8(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, s32);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_003A9440_00360A48(s32, unsigned long);
    extern void func_00389478(void *, f32 *, f32 *);
    vu0_v4 v00;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 v80;
    Strip_00360A48 pk;
    S_00360A48 *s;
    s32 c2, c4, c5, c6, c7;
    s32 kind;
    f32 d, t, a, b, w, ang, sn, cs;
    f32 *px, *py;
    u8 *pq;
    u8 *pp;
    s32 i, j, k;

    c4 = 0x7F400505;
    c2 = 0x7F200505;
    c5 = 0x35FF0032;
    c6 = 0x35804020;
    c7 = 0x357F2020;
    s = *(S_00360A48 **)(o + 0x68);
    D_L01_001DD718 = func_0038DAB8(D_L01_001DD718, func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    D_L01_001DD724 = func_0038DAB8(D_L01_001DD724, func_003824E0(-2.0f, -4.0f) * 0.017453292f);
    D_L01_001DD71C = func_0038DAB8(D_L01_001DD71C, func_003824E0(-1.0f, -3.0f) * 0.017453292f);
    D_L01_001DD728 = func_0038DAB8(D_L01_001DD728, func_003824E0(-3.0f, -5.0f) * 0.017453292f);
    D_L01_001DD720 = func_0038DAB8(D_L01_001DD720, func_003824E0(-1.0f, -3.0f) * 0.017453292f);
    D_L01_001DD72C = func_0038DAB8(D_L01_001DD72C, func_003824E0(-1.0f, -4.0f) * 0.017453292f);
    kind = ((Gun_00360A48 *)(D_00142637[0] * sizeof(Gun_00360A48) + (s32)D_L01_002C5600_00360A48))->kind;
    if (kind == 2) {
        c4 = 0x7F050510;
        c2 = 0x7F050520;
        c5 = 0x35104080;
        c6 = 0x35204080;
        c7 = 0x354080FF;
    } else if (kind == 3) {
        c4 = 0x7F050540;
        c2 = 0x7F050520;
        c5 = 0x3532007F;
        c6 = 0x35204080;
        c7 = 0x3520207F;
    }
    pq = o + 0x10;
    func_003D9508(pq, 0x49, c4, 0, s->f18 * 1.2f * 2.0f, 0.01f, D_L01_001DD728);
    func_003D9508(pq, 0x49, c2, 0, s->f18 * 1.1f * 2.0f, 0.01f, -D_L01_001DD72C);
    func_003D9508(pq, 0x49, c4, 0, s->f18 * 0.9f * 2.0f, 0.01f, D_L01_001DD724);
    func_003D9508(pq, 0x49, c2, 0, s->f18 * 2.0f, 0.01f, -D_L01_001DD724);
    func_003D9508(pq, 0x4A, c4, 0, s->f18 * 1.2f * 2.0f, 0.01f, -D_L01_001DD728);
    func_003D9508(pq, 0x4A, c2, 0, s->f18 * 1.1f * 2.0f, 0.01f, D_L01_001DD72C);
    func_003D9508(pq, 0x4A, c4, 0, s->f18 * 0.9f * 2.0f, 0.01f, -D_L01_001DD724);
    func_003D9508(pq, 0x4A, c2, 0, s->f18 * 2.0f, 0.01f, D_L01_001DD724);
    func_L01_0040AAC8(pq, 0x47, 0x48, c5, s->f18 * 1.4f * 2.0f, 1.0f, 1.0f, D_L01_001DD718, -D_L01_001DD724, 0.0f, 0);
    func_L01_0040AAC8(pq, 0x47, 0x48, c6, s->f18 * 1.4f * 2.0f, 1.0f, 1.0f, -D_L01_001DD71C, D_L01_001DD728, 0.05f, 0);
    func_L01_0040AAC8(pq, 0x47, 0x48, c7, s->f18 * 1.4f * 2.0f, 1.0f, 1.0f, D_L01_001DD720, -D_L01_001DD72C, 0.1f, 0);
    d = func_L01_0040E548(D_L01_001E2A40, pq);
    if (36.0f < d) {
        t = s->f34;
        if (1.0f < t) {
            s->f34 = 1.0f;
        } else if (t < 0.0f) {
            s->f34 = 0.0f;
        }
        a = func_0038D098(t * 3.1415927f);
        vec_sub_ba(&v10, D_L01_001E2A40, o + 0x10);
        w = (1.0f - a) * 0.5f * 0.6f;
        func_0038CF68(&v10, &v10, s->f34 + 2.0f);
        func_0038CF68(&v30, D_001A4EC0, 1.0f);
        func_0038CE90(&v30, &v10, &v30);
        func_0038CF68(&v30, &v30, s->f34 + 2.0f);
        func_0038CE90(&v20, &v30, &v10);
        func_0038CF68(&v20, &v20, s->f34 + 1.0f);
        func_0038CF68(&v00, &v30, -0.5f);
        vec_add_ba(&v40, o + 0x10, &v00);
        vec_add_ba(&v50, &v40, &v10);
        func_0038CE20(&v00, &v10, 0.5f);
        vec_add_ab(&v40, &v40, &v10);
        s->f30 = func_0038DAB8(s->f30, 0.0558505394f);
        ang = s->f30;
        i = 0;
        do {
            v70 = v40;
            sn = func_0038D098(ang);
            cs = func_0038D0B0(ang);
            if (sn != 0.0f) {
                func_0038CE20(&v80, &v30, sn);
                vec_add_ab(&v70, &v70, &v80);
            }
            if (cs != 0.0f) {
                func_0038CE20(&v80, &v20, cs);
                vec_add_ab(&v70, &v70, &v80);
            }
            if (i != 0) {
                func_003D93B0(&pk, 0x4D, 1, 0x80);
                pk.tag2 = 0x800000004AL;
                pk.p[0] = v60;
                pk.p[1] = v70;
                pk.c40 = pk.c44 = pk.c48 = pk.c4C = 0x80808080;
                pk.uv[0][0] = 0.0f;
                pk.uv[0][1] = 0.0f;
                pk.uv[1][0] = 1.0f;
                pk.uv[1][1] = 0.0f;
                pk.uv[2][0] = 0.0f;
                pk.uv[2][1] = 1.0f;
                pk.uv[3][0] = 1.0f;
                pk.uv[3][1] = 1.0f;
                pk.p[2] = v50;
                pk.p[3] = v50;
                func_003A9440_00360A48(0x47, 0x31001);
                func_003D2DA0(&pk, 0, 0);
                for (j = 0; j < 4; j++) {
                    func_00389478(&pk.p[j], &pk.uv[j][0], &pk.uv[j][1]);
                }
                v80.x = (pk.uv[0][0] + pk.uv[1][0]) * 0.5f;
                v80.y = (pk.uv[0][1] + pk.uv[1][1]) * 0.5f;
                for (k = 0; k < 2; k++) {
                    pk.uv[2 + k][0] += (v80.x - pk.uv[2 + k][0]) * w;
                    pk.uv[2 + k][1] += (v80.y - pk.uv[2 + k][1]) * w;
                }
                func_003D93B0(&pk, -1, 1, 0x80);
                pk.tag0 = 5;
                pk.tag2 = 0x8000000054L;
                func_003A9440_00360A48(0x47, 0x53001);
                func_003D2DA0(&pk, 0, 0);
                func_003A9440_00360A48(0x47, 0x5360B);
            }
            v60 = v70;
            ang = func_0038DAB8(ang, 0.19634955f);
            i++;
        } while (i < 33);
    }
}
/* localdecomp:end func_L01_00360A48 */

/* localdecomp:start func_L01_003612E0 */
extern f32 D_L01_0028C6B0[][3];
extern s32 D_L01_0028C8A8[];
extern f32 D_L01_0028C950[];
extern void func_003A9440_003612E0(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D3A24(s32, void *, void *, void *, s32);

void func_L01_003612E0(s128 *matrix, f32 degrees, f32 r1, f32 r2, s32 texture, f32 unused, s32 colour, s32 blend)
{
    S_38C110v v;
    S_38C110v out;
    f32 step, angle, t, u, rad, denom;
    s32 i;

    func_003A9440_003612E0(8, 0);
    func_003A9440_003612E0(20, 0xFF9000000260UL);
    func_003A9440_003612E0(71, 0x513F1);
    func_003A9440_003612E0(6, func_00389598(texture));
    if (blend) {
        func_003A9440_003612E0(66, 0x8000000048UL);
    } else {
        func_003A9440_003612E0(66, 0x8000000041UL);
    }
    rad = 0.017453292f;
    func_0038C750();
    denom = 20.0f;
    step = degrees * rad / denom;
    for (i = 0; i < 42; i += 2) {
        t = i / 2;
        angle = func_0038DB48(t * step);
        func_0038D098(angle);
        u = t / denom;
        D_L01_0028C8A8[i] = colour;
        D_L01_0028C8A8[i + 1] = colour;
        D_L01_0028C950[i * 2] = u;
        D_L01_0028C950[i * 2 + 1] = 0.0f;
        D_L01_0028C950[i * 2 + 2] = u;
        D_L01_0028C950[i * 2 + 3] = 1.0f;
        func_00382760(&v, 1.0f, angle, r1 * rad);
        v.w = 1.0f;
        func_0038D028(&out, &v, matrix);
        D_L01_0028C6B0[i][0] = out.x;
        D_L01_0028C6B0[i][1] = out.y;
        D_L01_0028C6B0[i][2] = out.z;
        func_00382760(&v, 1.0f, angle, r2 * rad);
        v.w = 1.0f;
        func_0038D028(&out, &v, matrix);
        D_L01_0028C6B0[i + 1][0] = out.x;
        D_L01_0028C6B0[i + 1][1] = out.y;
        D_L01_0028C6B0[i + 1][2] = out.z;
    }
    func_003D3A24(42, D_L01_0028C6B0, D_L01_0028C8A8, D_L01_0028C950, 1);
}
/* localdecomp:end func_L01_003612E0 */

/* localdecomp:start func_L01_00361568 */


extern void func_0038D328(s128 *, S_38C110v *);
extern void func_0038D640(s128 *, void *, s128 *);
extern void func_0038CE20(s128 *, s128 *, f32);
extern void func_L01_003612E0(s128 *, f32, f32, f32, s32, f32, s32, s32);

void func_L01_00361568(S_38C110v *a0, void *a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16, f32 f17) {
    S_38C110v v;
    s128 m1[4];
    s128 m2[4];

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = f12;
    v.w = 1.0f;
    func_0038D328(m1, &v);
    func_0038D640(m2, a1, m1);
    func_0038CE20(&m2[0], &m2[0], f13);
    func_0038CE20(&m2[1], &m2[1], f13);
    func_0038CE20(&m2[2], &m2[2], f13);
    *(S_38C110v *)&m2[3] = *a0;
    func_L01_003612E0(m2, f17, f14, f15, a2, f16, a3, 1);
}
/* localdecomp:end func_L01_00361568 */

INCLUDE_ASM("asm/levels", func_L01_00361690);

/* localdecomp:start func_L01_00361AC0 */
#include "vu0.h"
__asm__(".extern D_L01_001DD730, 4");
__asm__(".extern D_L01_001DD734, 4");
__asm__(".extern D_L01_001DD738, 4");
__asm__(".extern D_L01_001DD73C, 4");
__asm__(".extern D_L01_001DD740, 4");
__asm__(".extern D_L01_001DD744, 4");
__asm__(".extern D_L01_001DD748, 4");
__asm__(".extern D_L01_001DD704, 4");
typedef struct {
    S_38C110v p[4];
    s32 c40,c44,c48,c4C;
    f32 uv[4][2];
    unsigned long tag0, texture, tag1, tag2;
} Strip_00361AC0;
extern s32 D_L01_001DD730, D_L01_001DD734, D_L01_001DD738, D_L01_001DD73C, D_L01_001DD740, D_L01_001DD744;
extern s32 D_L01_001DD748;
extern f32 D_L01_001DD704;
extern u8 D_00142637[];
typedef struct { u8 p0; u8 kind; u8 pad[0xEE]; } Gun_00361AC0;
extern Gun_00361AC0 D_L01_002C5600[];
extern s16 D_L01_002B3080[][8];
extern S_38C110v D_L01_002B2B80[];
extern f32 D_L01_002B3480[][2];
extern f32 D_L01_002B3484[][2];
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_00361AC0;
extern Hero_00361AC0 D_001A4BE0_00361AC0;
void func_L01_00361AC0(u8 *moby) {
    extern long func_00389598(s32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_003D2DA0(void *, void *, s32);
    Strip_00361AC0 strip;
    S_38C110v basis[3];
    S_38C110v offset;
    s32 i,j;
    f32 *u0,*v0;
    u8 *vars=*(u8 **)(moby+0x68);
    strip.texture=func_00389598(D_L01_001DD744);
    strip.tag1=0xFF9000000260UL;
    strip.tag2=(long)D_L01_001DD730 | ((long)D_L01_001DD734<<2) | ((long)D_L01_001DD738<<4) | ((long)D_L01_001DD73C<<6) | ((long)D_L01_001DD740<<32);
    qzero(&basis[0]); qzero(&basis[1]); qzero(&basis[2]);
    strip.tag0=0;
    basis[0].x=*(f32 *)(vars+0x24)+*(f32 *)(vars+0x24);
    basis[1].y=*(f32 *)(vars+0x24)+*(f32 *)(vars+0x24);
    basis[2].z=*(f32 *)(vars+0x24)*0.25f;
    {
        s32 kind=((Gun_00361AC0 *)(D_00142637[0]*sizeof(Gun_00361AC0)+(s32)D_L01_002C5600))->kind;
        if(kind==1) D_L01_001DD748=0x300505;
        else if(kind==2) D_L01_001DD748=0x204080;
        else if(kind==3) D_L01_001DD748=0x204080;
    }
    strip.c40=strip.c44=strip.c48=strip.c4C=D_L01_001DD748+(*(s32 *)(vars+0x20)<<24);
    func_003C5180(vars,&offset,1);
    func_0038CE20((s128 *)&offset,(s128 *)&offset,0.25f);
    u0=&strip.uv[0][0];
    v0=&strip.uv[0][1];
    for(i=0;i<64;) {
        s32 next=i+1;
        s16 *row=&D_L01_002B3080[i][0];
        S_38C110v *dst=strip.p;
        f32 *v=v0;
        f32 *u=u0;
        for(j=3;j>=0;j--) {
            s32 uv=row[1];
            func_0038CE20((s128 *)dst,(s128 *)&D_L01_002B2B80[row[0]],D_L01_001DD704);
            *u=D_L01_002B3480[uv][0];
            *v=D_L01_002B3484[uv][0];
            func_0038D000(dst,dst,basis);
            func_0038D000(dst,dst,D_001A4BE0_00361AC0.moby+0xC0);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\tlqc2 $vf2, %0\n\tlqc2 $vf1, %3\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(*dst) : "m"(*dst),"m"(*(S_38C110v *)vars),"m"(offset) : "vf1", "vf2");
            row+=2; v+=2; u+=2; dst++;
        }
        func_003D2DA0(&strip,0,0);
        i=next;
    }
}
/* localdecomp:end func_L01_00361AC0 */

/* localdecomp:start func_L01_00361D60 */
#include "vu0.h"
__asm__(".extern D_L01_001DD730, 4");
__asm__(".extern D_L01_001DD734, 4");
__asm__(".extern D_L01_001DD738, 4");
__asm__(".extern D_L01_001DD73C, 4");
__asm__(".extern D_L01_001DD740, 4");
__asm__(".extern D_L01_001DD744, 4");
__asm__(".extern D_L01_001DD748, 4");
__asm__(".extern D_L01_001DD704, 4");
typedef struct {
    S_38C110v p[4];
    s32 c40,c44,c48,c4C;
    f32 uv[4][2];
    unsigned long tag0, texture, tag1, tag2;
} Strip_00361D60;
extern s32 D_L01_001DD730, D_L01_001DD734, D_L01_001DD738, D_L01_001DD73C, D_L01_001DD740, D_L01_001DD744;
extern s32 D_L01_001DD748;
extern f32 D_L01_001DD704;
extern s16 D_L01_002B3080[][8];
extern S_38C110v D_L01_002B2B80[];
extern f32 D_L01_002B3480[][2];
extern f32 D_L01_002B3484[][2];
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_00361D60;
extern Hero_00361D60 D_001A4BE0_00361D60;
void func_L01_00361D60(u8 *moby) {
    extern long func_00389598(s32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_003D2DA0(void *, void *, s32);
    Strip_00361D60 strip;
    S_38C110v basis[3];
    S_38C110v offset;
    s32 i,j;
    f32 *u0,*v0;
    u8 *vars=*(u8 **)(moby+0x68);
    strip.texture=func_00389598(D_L01_001DD744);
    strip.tag1=0xFF9000000260UL;
    strip.tag2=(long)D_L01_001DD730 | ((long)D_L01_001DD734<<2) | ((long)D_L01_001DD738<<4) | ((long)D_L01_001DD73C<<6) | ((long)D_L01_001DD740<<32);
    qzero(&basis[0]); qzero(&basis[1]); qzero(&basis[2]);
    strip.tag0=0;
    basis[0].x=*(f32 *)(vars+0x24);
    basis[1].y=*(f32 *)(vars+0x24);
    basis[2].z=*(f32 *)(vars+0x24)*0.125f;
    strip.c40=strip.c44=strip.c48=strip.c4C=D_L01_001DD748+(*(s32 *)(vars+0x20)<<24);
    func_003C5180(vars,&offset,1);
    func_0038CE20((s128 *)&offset,(s128 *)&offset,0.25f);
    u0=&strip.uv[0][0];
    v0=&strip.uv[0][1];
    for(i=0;i<64;) {
        s32 next=i+1;
        s16 *row=&D_L01_002B3080[i][0];
        S_38C110v *dst=strip.p;
        f32 *v=v0;
        f32 *u=u0;
        for(j=3;j>=0;j--) {
            s32 uv=row[1];
            func_0038CE20((s128 *)dst,(s128 *)&D_L01_002B2B80[row[0]],D_L01_001DD704);
            *u=D_L01_002B3480[uv][0];
            *v=D_L01_002B3484[uv][0];
            func_0038D000(dst,dst,basis);
            func_0038D000(dst,dst,D_001A4BE0_00361D60.moby+0xC0);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\tlqc2 $vf2, %0\n\tlqc2 $vf1, %3\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(*dst) : "m"(*dst),"m"(*(S_38C110v *)vars),"m"(offset) : "vf1", "vf2");
            row+=2; v+=2; u+=2; dst++;
        }
        func_003D2DA0(&strip,0,0);
        i=next;
    }
}
/* localdecomp:end func_L01_00361D60 */

/* localdecomp:start func_L01_00361FA8 */
typedef struct {
    vu0_v4 v0;
    u8 p10[0x20];
    vu0_v4 v30;
    u8 p40[4];
    s32 w44;
    s32 w48;
    s32 w4C;
    s32 w50;
    s32 w54;
    s32 w58;
} S_00361FA8;
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_00361FA8;
extern Hero_00361FA8 D_001A4BE0_00361FA8;
extern u8 *D_L01_001EAA18[];
extern s32 D_001D545C;
extern u8 D_L01_001DAFF0;
extern u8 D_L01_001EAA00_00361FA8[];
extern u8 D_L01_001EAA20[];
extern u8 D_L01_001EAA40[];
extern u8 D_L01_001DD750[8];
__asm__(".extern D_L01_001DD750, 8");
extern s32 D_L01_001E10F8_00361FA8;
__asm__(".extern D_L01_001E10F8_00361FA8, 4");
extern void func_L01_004471A8_00361FA8(void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_004C7D98_00361FA8(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_004C8688_00361FA8(s32, void *, s32);
extern void func_L01_004C7D40_00361FA8(void *, void *, f32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003C4B50();
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0040E790_00361FA8(void *, void *, void *);
extern s32 func_L01_003FB640_00361FA8(void *, s32, void *, f32);
extern f32 func_L01_0040E570_00361FA8(void *, void *);
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern void *func_L01_0035F340_00361FA8(s32, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);
extern void *func_L01_0038B9A8_00361FA8(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);
extern void func_003A52A0(s32, s32, s32);
extern void func_003C2880(void *);

void func_L01_00361FA8(u8 *o) {
    S_00361FA8 *s;
    vu0_v4 v20;
    vu0_v4 *p20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 m70[4];
    vu0_v4 vb0;
    u8 *hero;
    u8 *t;
    u8 *gq;
    f32 f;
    f32 g;
    s32 h;
    s32 idx;

    s = *(S_00361FA8 **)(o + 0x68);
    func_L01_004471A8_00361FA8(o, 0.75f);
    switch (o[0x20]) {
    case 0:
        *(f32 *)(o + 0xF0) = func_0038DAB8(*(f32 *)(o + 0xF0), 0.08377581f);
        *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), 0.22689281f);
        func_L01_004C7D98_00361FA8(o + 0x10, &v30);
        func_0038CF68(&v40, o + 0xE0, 1.0f);
        func_0038CE90(&v60, &v40, &v30);
        f = func_0038CE68(&v40, &v30) * 0.5f;
        func_0038CE20((s128 *)&v50, (s128 *)&v60, func_0038D0B0(f));
        v50.w = func_0038D098(f);
        func_0038D810(&v50, m70);
        func_0038D5F0(o + 0xC0, m70, o + 0xC0);
        p20 = &v20;
        *p20 = *(vu0_v4 *)(o + 0x10);
        vec_add_ab(o + 0x10, o + 0x10, s);
        func_L01_004C8688_00361FA8(s->w44, s, 0);
        func_L01_004C7D40_00361FA8(o + 0x10, s, 0.0048f);
        if (func_L01_004CB2D8() != 0) {
            func_L01_004CAB30(o + 0x10, o + 0x10);
        }
        *(s32 *)(D_001A4BE0_00361FA8.moby + 0x98) = 0;
        if (func_003D3CB0(p20, o + 0x10, 0, o, 0) != 0) {
            t = D_L01_001EAA18[0];
            if (t == 0) {
                goto l23c;
            }
            h = *(s16 *)(t + 0xAA);
            if (h == 0x1865 || h == 0 || h == 0x1885) {
                func_L01_004450F0(o, 0, -1);
            } else {
                if (func_003C4B50(t) != 0) {
                    goto l23c;
                }
                func_L01_004450F0(o, 1, -1);
            }
            goto l274;
l23c:
            func_L01_004450F0(o, 2, -1);
            s->w4C = 8;
            s->v30 = *(vu0_v4 *)D_L01_001EAA40;
            func_L01_0040E790_00361FA8(s, s, &s->v30);
        }
l274:
        hero = D_001A4BE0_00361FA8.moby;
        *(s32 *)(hero + 0x98) = *(s32 *)(*(u8 **)(hero + 0x24) + 0x10);
        if (func_L01_003FB640_00361FA8(o + 0x10, 0, D_001A4BE0_00361FA8.moby, 1.5f) != 0) {
            gq = D_L01_001EAA00_00361FA8;
            t = *(u8 **)(gq + 0x18);
            if (t != 0 && func_003C4B50(t) == 0) {
                t = *(u8 **)(gq + 0x18);
                if (t != 0 && *(u8 **)(t + 0x24) != 0 && *(u8 *)(*(u8 **)(t + 0x24) + 0x46) == 5) {
                    if (*(s16 *)(t + 0xAA) != 0x1AE6) {
                        func_L01_004450F0(o, 1, -1);
                    }
                }
            }
        }
        if (D_L01_001DAFF0 != 0) {
            if (D_001D545C == 5) {
                if (*(f32 *)(o + 0x18) <= 32.5f) {
                    func_L01_004450F0(o, 1, -1);
                } else {
                    g = func_L01_0040E570_00361FA8(D_L01_001DD750, o + 0x10);
                    if (400.0f < g) {
                        func_L01_004450F0(o, 1, -1);
                    }
                }
            }
        }
        func_L01_004C7D98_00361FA8(o + 0x10, &m70[3]);
        func_0038CF68(&m70[3], &m70[3], -1.0f);
        vec_add_ab(&m70[3], o + 0x10, &m70[3]);
        func_0038CAD0(&s->w48);
        if (s->w48 < 10) {
            if (func_003D3CB0(o + 0x10, &m70[3], 0, o, 0) != 0) {
                func_L01_004450F0(o, 1, -1);
            }
        }
        break;
    case 2:
        if (func_0038CAD0(&s->w4C) == 0) {
            vec_add_ab(o + 0x10, o + 0x10, s);
            func_L01_004C8688_00361FA8(s->w44, s, 0);
            func_L01_004C7D40_00361FA8(o + 0x10, s, 0.0048f);
            func_L01_004CAB30(o + 0x10, o + 0x10);
        } else {
            func_L01_004450F0(o, 1, -1);
        }
        break;
    case 1:
        func_L01_004C7D98_00361FA8(o + 0x10, &vb0);
        func_0038CF68(&vb0, &vb0, -20.0f);
        vec_add_ba(&vb0, &vb0, o + 0x10);
        if (func_003D3CB0(o + 0x10, &vb0, 2, o, 0) != 0) {
            vb0 = *(vu0_v4 *)D_L01_001EAA20;
        }
        if (s->w50 == 0) {
            func_L01_0035F340_00361FA8(s->w54, o + 0x10, &vb0, 0x18, 0x41, 0x1AFF2020, 0x1AFF2020, 0xFF2020, 0xFF2020, 100, s->w58,
                                       func_003824E0(0.017453294f, 0.03490659f), 0.09f, 5.0f, 1.5f);
        } else {
            func_L01_0038B9A8_00361FA8(o + 0x10, &vb0, s, 0x18, 0x41, 0x1AFF2020, 0x1AFF2020, 0xFF2020, 0xFF2020, 100,
                                       func_003824E0(0.017453294f, 0.03490659f), 0.09f, 5.0f, 1.5f);
        }
        func_003A52A0(0, 0, (s32)o);
        D_L01_001E10F8_00361FA8 = 0;
        func_003C2880(o);
        break;
    case 3:
        D_L01_001E10F8_00361FA8 = 0;
        func_003C2880(o);
        break;
    }
}
/* localdecomp:end func_L01_00361FA8 */

/* localdecomp:start func_L01_00362600 */
void func_L01_00362600(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_00362600 */

/* localdecomp:start func_L01_00362610 */
typedef struct {
    s128 velocity;        /* 0x00 */
    u8 pad_10[0x40 - 0x10];
    s32 ticks;            /* 0x40 */
    u8 pad_44[4];
    s32 timer;            /* 0x48 */
    u8 pad_4C[4];
    s32 eruptor;          /* 0x50: the Nitro Eruptor's charge (1) */
    void *target;         /* 0x54 */
    s32 flag_58;          /* 0x58 */
} NitroVars_362610;

typedef struct {
    u8 pad_0[0x10];
    s128 position;        /* 0x10 */
    u8 state;             /* 0x20 */
    u8 pad_21[0x24 - 0x21];
    u8 *pclass;           /* 0x24 */
    u8 pad_28[0x2C - 0x28];
    f32 scale;            /* 0x2C */
    u8 update_dist;       /* 0x30: names for 0x30-0x32 from Horizon Private Server's libuya */
    u8 drawn;             /* 0x31 */
    s16 draw_dist;        /* 0x32 */
    u8 pad_34[0x68 - 0x34];
    NitroVars_362610 *vars; /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    f32 rotation[4];      /* 0xF0 */
} NitroMoby_362610;

extern NitroMoby_362610 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C7C38(u8 *);
extern NitroMoby_362610 *D_L01_001E10F8;

/* nitro_charge_spawn: spawns a Nitro charge (class 0x185A) at position with its velocity,
 * turned at random, with its timer. */
NitroMoby_362610 *func_L01_00362610(s128 *position, s128 *velocity, void *target,
                                    s32 eruptor, s32 flag_58)
{
    NitroMoby_362610 *moby;
    NitroVars_362610 *vars;

    moby = func_003C24B0(0x185A, 0x80);
    if (moby != 0) {
        moby->update_dist = 0xFF;
        moby->draw_dist = 0x1FF;
        moby->drawn = 1;
        moby->state = 0;
        vars = moby->vars;
        moby->position = *position;
        vars->velocity = *velocity;
        vars->ticks = 0;
        moby->rotation[0] = func_003824E0(-3.1415927f, 3.1415927f);
        moby->rotation[1] = func_003824E0(-3.1415927f, 3.1415927f);
        moby->rotation[2] = func_003824E0(-3.1415927f, 3.1415927f);
        moby->rotation[3] = 0.0f;
        moby->scale = *(f32 *)(moby->pclass + 0x24) * 1.25f;
        vars->flag_58 = flag_58;
        func_003C7C38((u8 *)moby);
        D_L01_001E10F8 = moby;
        vars->timer = 42; /* NTSC-U's 50 frames at 60 Hz */
        vars->eruptor = eruptor;
        vars->target = target;
    }
    return moby;
}
/* localdecomp:end func_L01_00362610 */

/* localdecomp:start func_L01_00362758 */
#include "vu0.h"
typedef struct {
    u8 pad00[4];
    s32 w4;
    u8 pad08[8];
    vu0_v4 pos;
    f32 f20;
    u8 pad24[0x10];
    s32 w34;
    f32 f38;
    u8 pad3C[4];
    vu0_v4 v40;
    s32 w50;
    s32 w54;
    f32 f58;
} S_00362758;
typedef struct {
    u8 pad0[0x1210];
    s32 w1210;
    u8 pad1214[0xC];
    s32 w1220;
    u8 pad1224[0x3A8];
    s32 w15cc;
    u8 pad15d0[0x20];
    f32 f15f0;
    u8 pad15f4[0xBC];
    s32 w16b0;
    u8 pad16b4[0x20];
    s32 w16d4;
    s32 w16d8;
    u8 pad16dc[0xEE4];
    u8 *moby;
    s32 st;
    u8 pad25c8[0x20];
    unsigned long fl;
} H_00362758;
typedef struct { u8 p0; u8 b1; u8 pad2[0x6A]; f32 f6c; u8 pad70[0x80]; } Row_00362758;
extern H_00362758 D_001A4BE0_00362758;
extern Row_00362758 D_L01_002C5600_00362758[];
extern u8 D_001425C0_00362758[];
extern u8 *D_001D52FC_00362758;
extern s32 D_L01_001D6694_00362758;
extern u8 D_001A30B0_00362758[];
extern vu0_v4 D_L01_0028E3A0_00362758[];
extern s16 D_L01_001E1B12_00362758[4];
__asm__(".extern D_L01_001E1B12_00362758, 16");
extern f32 D_L01_001E1B34_00362758[2];
__asm__(".extern D_L01_001E1B34_00362758, 16");
extern f32 D_L01_001E1AE4_00362758;
extern s32 D_L01_001E1B28_00362758;
extern s32 D_L01_001E1B24_00362758;
extern f32 D_L01_001E29C0_00362758[];
extern f32 D_L01_001E29E0_00362758[];
extern s32 D_L01_001DD790;
extern f32 D_L01_001DD7A4_00362758;
extern s32 D_L01_001DD79C_00362758;
extern s32 D_L01_001DD798;
extern f32 D_L01_001DD7A0;
extern f32 D_L01_001DD7A8;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DD790, 4");
__asm__(".extern D_L01_001DD798, 4");
__asm__(".extern D_L01_001DD7A0, 4");
__asm__(".extern D_L01_001DD7A8, 4");
__asm__(".extern D_L01_001DFB40, 4");
__asm__(".extern D_001D52FC_00362758, 16");
__asm__(".extern D_L01_001D6694_00362758, 16");
__asm__(".extern D_L01_001E1B28_00362758, 16");
__asm__(".extern D_L01_001E1B24_00362758, 16");
__asm__(".extern D_L01_001E1AE4_00362758, 16");

void func_L01_00362758(u8 *o) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_003A4F28(s32);
    extern void func_L01_004EAA80(void);
    extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern void func_L01_00366240(void *);
    extern s32 func_003A52A0_00362758(s32, s32, void *);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_005003D0(s32, s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_004CB1F0(f32, f32);
    extern void func_L01_004CB128(void *, void *, s32);
    extern s32 func_L01_004BA800(void);
    extern s32 func_L01_004AA710(void *, s32);
    extern s32 func_L01_00457480(s32, s32);
    extern s32 func_L01_004572B0(void *, s32, void *);
    extern s32 func_L01_00451D38(void *, s32, s32, f32);
    extern u8 *func_L01_00450BB0(void *, void *, f32, f32, f32, f32, f32, s32);
    extern void func_L01_00444F38(void *, s32, s32, s32, s32);
    extern void func_L01_00421988(s32, s32, s32, s32, f32);
    extern void func_L01_003968F8(void *, s32, void *, void *, s32, s32);
    extern void func_L01_003839C8(void *, void *, void *, void *, s32, s32, f32);
    extern void func_L01_00364C20(void *, void *);
    extern s32 func_L01_00363DD0();
    extern s32 func_L01_00363D90();
    extern void func_L01_00363BF0(void *);
    extern void func_L01_00363690(void *);
    extern void func_L01_00363468(void *);
    extern void func_L01_003631C8(void *);
    extern s32 func_L01_00363170(s32 *);
    extern s32 func_L01_00363138();
    extern f32 func_003C4088(f32, f32, f32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_00382538(void);
    vu0_v4 v00;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    S_00362758 *s;
    Row_00362758 *row;
    u8 *r;
    u8 *q;
    f32 d, a;
    s32 b1, i, n, h, k;

    s = *(S_00362758 **)(o + 0x68);
    if (o[0x20] == 0) {
        s->f20 = 0.6f;
        o[0x20] = 1;
        func_003C2F58(o, 0, &s->pos);
        D_L01_0028E3A0_00362758[0] = s->pos;
        v00 = *(vu0_v4 *)(D_001A4BE0_00362758.moby + 0xC0);
        D_L01_001E1B28_00362758 = 0x11;
        for (i = 0; i < 9; i++) {
            vec_add_ab(&D_L01_0028E3A0_00362758[i + 1], &D_L01_0028E3A0_00362758[i], &v00);
            D_L01_001E1B12_00362758[i] = 0;
            D_L01_001E1AE4_00362758 = 1.0f;
            D_L01_001E1B34_00362758[i] = func_00382538();
        }
        s->w50 = func_L01_004572B0(o, 0, &v30);
        s->w54 = func_L01_00457480(*(s16 *)(o + 0xAA), s->w50);
    }
    b1 = D_L01_002C5600_00362758[D_001425C0_00362758[0x87]].b1;
    if (b1 == 0) {
        D_L01_001DD790 = 10;
    } else if (b1 == 1) {
        D_L01_001DD790 = 12;
    } else if (b1 == 2) {
        D_L01_001DD790 = 15;
    } else if (b1 == 3) {
        D_L01_001DD790 = 20;
    } else if (b1 > 3) {
        D_L01_001DD790 = 20;
    }
    if (b1 == 2) {
        *(s16 *)(o + 0x7C) = 3;
    } else if (b1 == 1) {
        *(s16 *)(o + 0x7C) = 1;
    } else if (b1 >= 3) {
        *(s16 *)(o + 0x7C) = 0x13;
    }
    if (o[0x42] == o[0x43]) {
        if (o[0x60] & 2) {
            func_L01_00444F38(o, 1, 0, 2, 0);
        }
    }
    if ((*(s32 *)(D_001D52FC_00362758 + 0x1A0) & D_001A4BE0_00362758.w1210) == 0) {
        if (D_001A4BE0_00362758.st != 0x7D) {
            if (func_L01_00363D90(o) != 0 || func_L01_00363DD0(o) != 0) {
                func_L01_004450F0(o, 1, -1);
            } else {
                n = s->w4;
                if (n != -1) {
                    q = D_001A30B0_00362758 + (n << 7);
                    if (*(u8 **)(q + 0xDC) == o && q[0xD0] != 0) {
                        func_003A4F28(n);
                    }
                }
                s->w4 = -1;
                func_L01_004EAA80();
                func_L01_004450F0(o, 2, -1);
            }
        }
    }
    if (D_L01_001D6694_00362758 == 6 || func_L01_004BA800() != 0 || D_001A4BE0_00362758.st == 0x65 ||
        D_001A4BE0_00362758.st == 0x74) {
        n = s->w4;
        if (n != -1) {
            q = D_001A30B0_00362758 + (n << 7);
            if (*(u8 **)(q + 0xDC) == o && q[0xD0] != 0) {
                func_003A4F28(n);
            }
        }
        s->w4 = -1;
    }
    if (o[0x20] == 1) {
        if ((*(s32 *)(D_001D52FC_00362758 + 0x1A0) & D_001A4BE0_00362758.w1210) == 0) {
            goto l474;
        }
        if (D_L01_001D6694_00362758 != 0) {
            goto l474;
        }
        if (D_001A4BE0_00362758.st == 0x74) {
            goto l474;
        }
        if ((D_001A4BE0_00362758.fl & 0xFF00000000FFUL) != 0) {
            goto l474;
        }
        if (D_001A4BE0_00362758.w1220 < 0xD) {
            goto l474;
        }
        if (D_001A4BE0_00362758.st == 0x7D) {
            goto l474;
        }
        func_003C2F58(o, 0, &s->pos);
        if (D_L01_001E1B28_00362758 == 0x13) {
            func_L01_004EA7D8(-1);
        }
        func_L01_00364C20(o, &s->pos);
        if (func_L01_004AA710(o, s->w4) == 0 && D_L01_001D6694_00362758 == 0) {
            if (D_001A4BE0_00362758.st != 0x74) {
                s->w4 = func_003A52A0_00362758(0, 4, o);
            }
        }
        if (o[0x43] != 2) {
            func_003C3A10(o, 2, 0, 0);
        }
        if (func_0038CAD0(&D_L01_001E1B28_00362758) != 0) {
            if ((D_L01_001DFB40 & 3) == 0) {
                func_L01_003631C8(o);
            }
            func_L01_00363BF0(o);
        }
        goto l4cc;
    l474:
        n = s->w4;
        if (n != -1) {
            q = D_001A30B0_00362758 + (n << 7);
            if (*(u8 **)(q + 0xDC) == o && q[0xD0] != 0) {
                func_003A4F28(n);
            }
        }
        s->w4 = -1;
        func_L01_004EAA80();
        D_L01_001E1B28_00362758 = 0x11;
        func_L01_00366240(o);
    }
l4cc:
    func_0038CAD0(&s->w34);
    if (o[0x20] == 2) {
        if (D_001A4BE0_00362758.st == 1) {
            func_L01_005003D0(0x1D, 1);
        }
        func_L01_00366240(o);
        func_003C2F58(o, 0, &s->pos);
        func_0038CF68(&v00, D_001A4BE0_00362758.moby + 0xC0, 1.0f);
        r = func_L01_00450BB0(&s->pos, &v00, 0.122173049f, 0.139626339f, 35.0f, 0.785398185f, 0.610865235f, 0);
        if (r != 0) {
            D_L01_001E1B24_00362758 = (s32)r;
            func_L01_004CB128(&v10, r, 0);
            vec_sub_ba(&v00, &v10, &s->pos);
            func_0038CF68(&v00, &v00, 20.0f);
            vec_add_ab(&s->v40, &v00, &s->pos);
            if (D_001A4BE0_00362758.st != 0x1D && D_001A4BE0_00362758.w16b0 == 0) {
                d = func_0038CF00(D_L01_001E29C0_00362758, &v10) / 150.0f;
                a = func_0038DAB8(s->f58, 0.0349065848f);
                s->f58 = a;
                func_L01_003F6F20(0, o, 0x600FFF0F, &v10, 0x26, -1, 4, fabs_asm(0.9f - d * 0.65f), -a, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            }
        } else {
            D_L01_001E1B24_00362758 = 0;
        }
        if (D_001A4BE0_00362758.st == 0x1D || D_001A4BE0_00362758.w16b0 != 0) {
            func_0038CF68(&v00, D_L01_001E29E0_00362758, 20.0f);
            k = func_L01_004CB1F0(0.97f, 150.0f);
            if (0.98f < D_001A4BE0_00362758.f15f0) {
                D_L01_001E1B24_00362758 = D_001A4BE0_00362758.w15cc;
            } else {
                D_L01_001E1B24_00362758 = 0;
            }
            func_L01_003F6F20(0, o, k, 0, 0x44, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        } else {
            if (r == 0) {
                D_001A4BE0_00362758.w16d4 = 0;
                D_001A4BE0_00362758.w16d8 = 0;
                func_0038CF68(&v00, D_001A4BE0_00362758.moby + 0xC0, 20.0f);
            } else {
                D_001A4BE0_00362758.w16d4 = 0;
                D_001A4BE0_00362758.w16d8 = 0;
            }
        }
        vec_add_ab(&s->v40, &v00, &s->pos);
        if ((*(s32 *)(D_001D52FC_00362758 + 0x1A0) & D_001A4BE0_00362758.w1210) != 0 && s->w34 <= 0 &&
            (D_001A4BE0_00362758.fl & 0xFF00000000FFUL) == 0) {
            func_0038CF68(&v10, &v00, 0.5f);
            vec_add_ba(&v20, &s->pos, &v10);
            func_0038CF68(&v00, &v00, 0.800000072f);
            h = func_L01_00363170((s32 *)&v30 + 1);
            if (h == -1) {
                func_L01_004450F0(o, 1, -1);
            } else {
                func_L01_00363468(o);
                func_003A52A0_00362758(2, 0, o);
                row = (Row_00362758 *)(D_001425C0_00362758[0x87] * sizeof(Row_00362758) + (s32)D_L01_002C5600_00362758);
                if (row->b1 >= 4) {
                    func_L01_003968F8(o, s->w50, &v20, &v00, 0, D_L01_001E1B24_00362758);
                    D_L01_001E1B24_00362758 = 0;
                } else {
                    func_L01_003839C8(o, &v00, &v20, (u8 *)&D_001A4BE0_00362758 + 0x90, h, D_L01_001E1B24_00362758, row->f6c);
                    D_L01_001E1B24_00362758 = 0;
                }
            }
            s->w34 = 0x19;
        }
    }
    n = func_L01_00363138(o);
    D_L01_001DD7A8 = 1.0f - (f32)n / (f32)D_L01_001DD790;
    a = func_003C4088(D_L01_001DD7A0, D_L01_001DD7A4_00362758, D_L01_001DD7A8);
    n = func_L01_00451D38(&s->f38, D_L01_001DD798, D_L01_001DD79C_00362758, a * 0.017453292f * 0.0200000014f);
    func_L01_00421988(1, n, 0, 0, D_L01_001DD7A8);
    func_L01_00363690(o);
}
/* localdecomp:end func_L01_00362758 */

/* localdecomp:start func_L01_00363138 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F160[];
s32 func_L01_00363138(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F160[i] != 0) n++;
    }
    return n;
}
/* localdecomp:end func_L01_00363138 */

/* localdecomp:start func_L01_00363170 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];
extern s32 D_L01_0028F160[];
s32 func_L01_00363170(s32 *out) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        s32 v = D_L01_0028F160[i];
        if (v != 0) {
            D_L01_0028F160[i] = 0;
            *out = D_L01_0028F0C0[i];
            D_L01_0028F0C0[i] = 0;
            return v;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_00363170 */

/* localdecomp:start func_L01_003631C8 */
typedef struct {
    u8 pad_0[0x18];
    u8 b18;            /* 0x18 */
    u8 b19;            /* 0x19 */
    s16 source_class;  /* 0x1A: the class of what hit */
    u8 pad_1C[0x30 - 0x1C];
} DamageInfo_3631C8;

typedef struct {
    u8 pad_0[0x4];
    s16 health;        /* 0x04 */
    u8 pad_6[0xF - 0x6];
    u8 takes_hits;     /* 0x0F */
} DamageRecord_3631C8;

typedef struct Moby_3631C8 {
    u8 pad_0[0x24];
    u8 *pclass;        /* 0x24 */
    u8 pad_28[0x68 - 0x28];
    u8 *vars;          /* 0x68 */
    u8 pad_6C[0x98 - 0x6C];
    void *coll_record; /* 0x98 */
    u8 pad_9C[0xAA - 0x9C];
    s16 class_id;      /* 0xAA */
} Moby_3631C8;

typedef struct {
    u8 pad_0[0x18];
    Moby_3631C8 *moby; /* 0x18: the moby the last test met */
} CollHit_3631C8;

typedef struct {
    u8 pos[0x20];      /* every other point of the vortex */
} SuckPoint_3631C8;

extern u8 D_001A4BE0[];
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];
extern s32 D_L01_0028F160[];
extern SuckPoint_3631C8 D_L01_0028E3C0[];
extern CollHit_3631C8 D_L01_001EAA00;
extern u8 D_L01_001D66B0[8];
extern s32 func_L01_003FB640(void *position, s32 mask, u8 *skip, f32 radius);
extern s32 func_003C4B50(Moby_3631C8 *moby);
extern DamageRecord_3631C8 *func_00382348(Moby_3631C8 *moby);
extern void func_L01_00446760(DamageInfo_3631C8 *info, u8 *attacker, s32 flags, void *push, f32 damage);
extern void func_L01_00446978(Moby_3631C8 *moby, DamageInfo_3631C8 *info);
extern s32 func_L01_00363E10(s32 value);

/* suck_crate_grab: as the Suck Cannon sucks, balls of 1.2, 1.4, 1.7 and 1.9 u at every other
 * point of its vortex look for a crate or a damageable moby to take in, into a free slot of
 * the held list (D_L01_0028F160: classes, D_L01_0028F0C0: mobys). */
void func_L01_003631C8(u8 *moby)
{
    DamageInfo_3631C8 info;
    Moby_3631C8 *hit;
    DamageRecord_3631C8 *record;
    u8 *hero = D_001A4BE0;
    s32 class_id;
    s32 i;

    /* not in states 0x35 and 0x36 */
    if ((u32)(*(s32 *)(hero + 0x25C4) - 0x35) < 2) {
        return;
    }
    for (i = 0; i < D_L01_001DD790; i++) {
        u8 *player = D_001A4BE0; /* the hero again: a second pointer, as retail */

        if (D_L01_0028F160[i] != 0) {
            continue;
        }
        /* the hero's moby out of the tests; its class's record is put back after */
        (*(Moby_3631C8 **)(player + 0x25C0))->coll_record = 0;
        if (func_L01_003FB640(&D_L01_0028E3C0[0], 1, moby, 1.2f) ||
            func_L01_003FB640(&D_L01_0028E3C0[1], 1, moby, 1.4f) ||
            func_L01_003FB640(&D_L01_0028E3C0[2], 1, moby, 1.7f) ||
            func_L01_003FB640(&D_L01_0028E3C0[3], 1, moby, 1.9f)) {
            /* what the ball met: an enemy (class category 5) or a crate (func_003C4B50) */
            if (D_L01_001EAA00.moby != 0 && D_L01_001EAA00.moby->class_id != 0 &&
                ((D_L01_001EAA00.moby->pclass != 0 && D_L01_001EAA00.moby->pclass[0x46] == 5) ||
                 func_003C4B50(D_L01_001EAA00.moby))) {
                class_id = D_L01_001EAA00.moby->class_id;
                /* never classes 0x1F8 and 0x1F7 */
                if (class_id != 0x1F8) {
                    if (class_id != 0x1F7) {
                        record = func_00382348(D_L01_001EAA00.moby);
                        /* a 1-damage hit with flag 0x8000000 */
                        func_L01_00446760(&info, moby, 0x8000000, D_L01_001D66B0, 1.0f);
                        info.b19 = 1;
                        info.source_class = *(s16 *)(moby + 0xAA);
                        info.b18 = 0;
                        if (func_003C4B50(D_L01_001EAA00.moby)) {
                            hit = D_L01_001EAA00.moby;
                            if (!func_L01_00363E10((s32)hit)) { /* not held yet */
                                *(s32 *)(hit->vars + 0xDC) |= 0x14;
                                D_L01_0028F0C0[i] = (s32)hit;
                                D_L01_0028F160[i] = hit->class_id;
                            }
                        } else if (record != 0 && record->takes_hits != 0) {
                            if (record->health >= 2) { /* only if it outlives it */
                                func_L01_00446978(D_L01_001EAA00.moby, &info);
                            }
                            if (!func_L01_00363E10((s32)D_L01_001EAA00.moby)) {
                                D_L01_0028F0C0[i] = (s32)D_L01_001EAA00.moby;
                                D_L01_0028F160[i] = D_L01_001EAA00.moby->class_id;
                            }
                        }
                    }
                }
            }
        }
        (*(Moby_3631C8 **)(player + 0x25C0))->coll_record =
            *(void **)((*(Moby_3631C8 **)(player + 0x25C0))->pclass + 0x10);
    }
}
/* localdecomp:end func_L01_003631C8 */

/* localdecomp:start func_L01_00363468 */
extern u8 D_L01_001D66B0[8];
extern u8 *func_L01_0046B458(u8 *position, s32 life, s32 colour, s32 roll_kind, s32 spin, void *velocity,
                             s32 delay, f32 size, f32 start_size, f32 unk);
extern u8 *func_L01_00470C78(u8 *position, s32 life, s32 colour, s32 a3, s32 spin, void *velocity, s32 t2,
                             s32 t3, s16 arg8, s32 arg9, f32 size, f32 start_size);

/* suck_take_in_sparkles: the Suck Cannon taking something in: at the muzzle four orange 0x35
 * sparkles (the Flux's muzzle sparkles) and three 0x5C bursts; D_L01_001D66B0 is a zero vector. */
void func_L01_00363468(u8 *moby)
{
    u8 *muzzle = *(u8 **)(moby + 0x68) + 0x10;

    func_L01_0046B458(muzzle, 14, 0xBF204080, 2, 4, D_L01_001D66B0, 1, 5.25f, 0.1f, 0.0f);
    func_L01_0046B458(muzzle, 14, 0xBF2040A0, 2, -4, D_L01_001D66B0, 1, 3.75f, 0.1f, 0.0f);
    func_L01_0046B458(muzzle, 14, 0xC0FFFFFF, 2, 4, D_L01_001D66B0, 1, 2.625f, 0.1f, 0.0f);
    func_L01_0046B458(muzzle, 14, 0xB0FFFFFF, 2, -4, D_L01_001D66B0, 1, 1.875f, 0.1f, 0.0f);
    func_L01_00470C78(muzzle, 17, 0x46787878, 2, 4, D_L01_001D66B0, 0, 2, 6, 1, 1.08f, 0.84000003f);
    func_L01_00470C78(muzzle, 17, 0x46787878, 2, -2, D_L01_001D66B0, 1, 2, 6, 1, 2.0400002f, 0.84000003f);
    func_L01_00470C78(muzzle, 17, 0x2D787878, 2, 2, D_L01_001D66B0, 1, 2, 6, 1, 2.4f, 1.8000001f);
}
/* localdecomp:end func_L01_00363468 */

INCLUDE_ASM("asm/levels", func_L01_00363690);

/* localdecomp:start func_L01_00363BF0 */
extern u8 *D_L01_001E0028_00363BF0;
extern u8 D_L01_0028E430_00363BF0[];
extern f32 func_0038CF00(void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_002F8D40_00363BF0(u8 *, u8 *, s32, f32, f32);

void func_L01_00363BF0(u8 *moby)
{
    u8 *p;
    for (p = D_L01_001E0028_00363BF0; p != 0; p = *(u8 **)(p + 0x28)) {
        if (func_0038CF00(p + 0x10, D_L01_0028E430_00363BF0) < 2.5f ||
            func_0038CF00(p + 0x10, D_L01_0028E430_00363BF0 - 0x30) < 1.7f ||
            func_0038CF00(p + 0x10, D_L01_0028E430_00363BF0 - 0x50) < 1.4f ||
            func_0038CF00(p + 0x10, D_L01_0028E430_00363BF0 - 0x70) < 1.2f) {
            if (p != 0 && *(u8 **)(p + 0x24) != 0 &&
                (*(u8 **)(p + 0x24))[0x46] == 0x13 && p[0x20] - 3 == 0) {
                f32 x = func_003824E0(-5.0f, 5.0f) * 0.017453292f;
                f32 y = func_003824E0(0.0f, 5.0f) * 0.017453292f;
                func_L01_002F8D40_00363BF0(p, moby, 1, x, y);
            }
        }
    }
}
/* localdecomp:end func_L01_00363BF0 */

/* localdecomp:start func_L01_00363D90 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F160[];

s32 func_L01_00363D90(void) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F160[i] != 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00363D90 */

/* localdecomp:start func_L01_00363DD0 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];

s32 func_L01_00363DD0(void) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F0C0[i] != 0) return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00363DD0 */

/* localdecomp:start func_L01_00363E10 */
__asm__(".extern D_L01_001DD790, 4");
extern s32 D_L01_001DD790;
extern s32 D_L01_0028F0C0[];

s32 func_L01_00363E10(s32 value) {
    s32 i;
    for (i = 0; i < D_L01_001DD790; i++) {
        if (D_L01_0028F0C0[i] == value) return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00363E10 */

LINKER_REMNANT("asm/levels", func_L01_00363E50);
