#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 w8;
} S_1A1ED0;
typedef struct {
    u8 pad0[0x150];
    s16 h150;
    s16 h152;
} S_1CFEC0;

INCLUDE_ASM("asm/levels", func_L01_0037EFC8);

/* localdecomp:start func_L01_0037F860 */
typedef int Q_0037F860 __attribute__((mode(TI)));
typedef struct {f32 x,y,z,w;} __attribute__((aligned(16))) V_0037F860;
extern s32 D_L01_001E1DC0;
extern f32 D_L01_001DDB84;
extern f32 D_L01_001E1DD0;
extern Q_0037F860 D_L01_0028F5A0[];
extern s32 D_L01_001DDBE8,D_L01_001DDBF0,D_L01_001DDBF4;
extern s32 D_L01_001E1DD4;
extern s32 D_L01_001E1E84;
extern u8 D_L01_001E1E80[3] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1E80, 16");
extern Q_0037F860 D_L01_001E1E10[3] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1E10, 48");
__asm__(".extern D_L01_001DDB84, 4");
__asm__(".extern D_L01_001E1DD0, 4");
__asm__(".extern D_L01_001DDBE8, 4");
__asm__(".extern D_L01_001DDBF0, 4");
__asm__(".extern D_L01_001DDBF4, 4");
__asm__(".extern D_L01_001E1DC0, 16");
__asm__(".extern D_L01_001E1DD4, 16");
__asm__(".extern D_L01_001E1E84, 16");
void func_L01_0037F860(u8 *m) {
 extern void func_0038CE20(Q_0037F860 *,Q_0037F860 *,f32);
 V_0037F860 step;
 Q_0037F860 *v=*(Q_0037F860 **)(m+0x68);
 s32 i,j;
 Q_0037F860 *p;
 if(D_L01_001E1DC0) {
  D_L01_001E1DC0=0;
  D_L01_001E1DD0=D_L01_001DDB84/12.0f;
  func_0038CE20((Q_0037F860 *)&step,(Q_0037F860 *)(m+0xC0),-D_L01_001E1DD0);
  D_L01_0028F5A0[0]=v[0];
  p=D_L01_0028F5A0+1;
  i=10;
  do {
   __asm__ __volatile__("lqc2 vf2,%0\n\tlqc2 vf1,%1\n\tvadd.xyz vf2,vf2,vf1" : : "m"(p[-1]), "m"(step) : "vf1","vf2");
   i--;
   __asm__ __volatile__("sqc2 vf2,%0" : "=m"(p[0]) : : "vf2");
   p++;
  } while(i>=0);
  D_L01_001DDBE8=0;D_L01_001DDBF0=0;D_L01_001DDBF4=0;
  D_L01_001E1DD4=0;D_L01_001E1E84=0;
  for(j=0;j<3;j++) {
   D_L01_001E1E10[j]=*(Q_0037F860 *)&step;
   D_L01_001E1E80[j]=0;
  }
 }
}
/* localdecomp:end func_L01_0037F860 */

INCLUDE_ASM("asm/levels", func_L01_0037F948);

/* localdecomp:start func_L01_00380880 */
/* the level copy of func_L39_00526FC0 (src/levels/shared/L39_00524E00.c), with its constants in $gp globals */
#include "vu0.h"
typedef struct {
    vu0_v4 pos[4];
    u32 col[4];
    f32 uv[4][2];
    long a;
    long tex;
    long c;
    long d;
} S_00380880;
typedef struct W_00380880 {
    u8 pad0;
    u8 b1;
    u8 pad2[0xF0 - 2];
} W_00380880;
typedef struct I_00380880 {
    u8 pad0[0x8F];
    u8 b8F;
} I_00380880;
extern I_00380880 D_001425C0_00380880;
extern W_00380880 D_L01_002C5600_00380880[];
extern vu0_v4 D_L01_0028F660_00380880[];
extern vu0_v4 D_L01_0028F720_00380880[];
extern vu0_v4 D_L01_0028F6A0_00380880[][20];
extern vu0_v4 D_L01_001E29C0_00380880;
extern void func_L01_00380CE0(vu0_v4 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_003812B0(u8 *);
extern void func_L01_00381500(u8 *);
extern long func_00389598(s32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003D2DA0(void *, s32, s32);
__asm__(".extern D_L01_001DDC58, 4");
__asm__(".extern D_L01_001DDC54, 4");
__asm__(".extern D_L01_001DDC3C, 4");
__asm__(".extern D_L01_001DDC40, 4");
__asm__(".extern D_L01_001DDC44, 4");
__asm__(".extern D_L01_001DDC48, 4");
__asm__(".extern D_L01_001DDC4C, 4");
__asm__(".extern D_L01_001DDC5C, 4");
__asm__(".extern D_L01_001DDC60, 4");
__asm__(".extern D_L01_001DDC64, 4");
__asm__(".extern D_L01_001DDBE0, 4");
__asm__(".extern D_L01_001DDBE4, 4");
__asm__(".extern D_L01_001DDBE8, 4");
__asm__(".extern D_L01_001DDBEC, 4");
__asm__(".extern D_L01_001DDBF0, 4");
__asm__(".extern D_L01_001DDBF4, 4");
__asm__(".extern D_L01_001DDBF8, 4");
extern f32 D_L01_001DDC58;
extern f32 D_L01_001DDC54;
extern s32 D_L01_001DDC3C;
extern s32 D_L01_001DDC40;
extern f32 D_L01_001DDC44;
extern f32 D_L01_001DDC48;
extern f32 D_L01_001DDC4C;
extern s32 D_L01_001DDC5C;
extern s32 D_L01_001DDC60;
extern s32 D_L01_001DDC64;
extern f32 D_L01_001DDBE0;
extern f32 D_L01_001DDBE4;
extern f32 D_L01_001DDBE8_00380880;
extern f32 D_L01_001DDBEC;
extern f32 D_L01_001DDBF0_00380880;
extern f32 D_L01_001DDBF4_00380880;
extern f32 D_L01_001DDBF8;
__asm__(".extern D_L01_001DDBE8_00380880, 4");
__asm__(".extern D_L01_001DDBF0_00380880, 4");
__asm__(".extern D_L01_001DDBF4_00380880, 4");

static __inline__ void qcopy_00380880(vu0_v4 *d, vu0_v4 *s) { *d = *s; }

void func_L01_00380880(u8 *m) {
    S_00380880 s;
    vu0_v4 d0;
    vu0_v4 d1;
    vu0_v4 n;
    vu0_v4 e;
    u32 col;
    s32 c1;
    s32 c2;
    s32 i, j, k;
    f32 y, u0, u1;

    D_L01_001DDC54 -= D_L01_001DDC58 * 1.2f;
    if (D_L01_001DDC54 <= -8.0f) D_L01_001DDC54 += 8.0f;
    c1 = 0xFF3F10;
    c2 = 0x7F1010;
    if ((D_L01_002C5600_00380880 + D_001425C0_00380880.b8F)->b1 >= 4) {
        c1 = 0x103FFF;
        c2 = 0x4080FF;
    }
    func_L01_00380CE0(D_L01_0028F660_00380880, D_L01_001DDC3C, D_L01_001DDC40, 0xC, c1, D_L01_001DDC44, D_L01_001DDC48, D_L01_001DDC4C);
    func_L01_00380CE0(D_L01_0028F720_00380880, D_L01_001DDC3C, D_L01_001DDC40, 0xC, c2, D_L01_001DDC44, D_L01_001DDC48, D_L01_001DDC4C);
    func_L01_003812B0(m);
    func_L01_00381500(m);
    col = (D_L01_002C5600_00380880 + D_001425C0_00380880.b8F)->b1 >= 4 ? D_L01_001DDC60 : D_L01_001DDC5C;
    s.tex = func_00389598(D_L01_001DDC64);
    s.c = 0xFF9000000260;
    s.d = 0x8000000048;
    s.a = 0;
    s.col[3] = col;
    s.col[2] = col;
    s.col[1] = col;
    s.col[0] = col;

    y = D_L01_001DDBE8_00380880;
    D_L01_001DDBE8_00380880 = y - D_L01_001DDBEC * 1.2f;
    if (D_L01_001DDBE8_00380880 <= -8.0f) D_L01_001DDBE8_00380880 += 8.0f;
    D_L01_001DDBF0_00380880 -= D_L01_001DDBF8 * 1.2f;
    if (D_L01_001DDBF0_00380880 <= -7.0f) D_L01_001DDBF0_00380880 += 7.0f;
    D_L01_001DDBF4_00380880 += D_L01_001DDBF8 * 1.2f;
    if (D_L01_001DDBF4_00380880 >= 5.0f) D_L01_001DDBF4_00380880 -= 5.0f;

    for (i = 2; i < 12; i++) {
        u0 = D_L01_001DDBF0_00380880;
        u1 = D_L01_001DDBF4_00380880;
        for (j = 0; j < 20; j++) {
            k = (j + 1) % 20;
            qcopy_00380880(&s.pos[0], D_L01_0028F6A0_00380880[i + 1] + j);
            qcopy_00380880(&s.pos[1], D_L01_0028F6A0_00380880[i + 1] + k);
            qcopy_00380880(&s.pos[2], D_L01_0028F6A0_00380880[i] + j);
            qcopy_00380880(&s.pos[3], D_L01_0028F6A0_00380880[i] + k);
            vec_sub_ba(&d0, &s.pos[0], &s.pos[1]);
            vec_sub_ab(&d1, &s.pos[2], &s.pos[1]);
            func_0038CE90(&n, &d1, &d0);
            vec_sub_ab(&e, &s.pos[1], &D_L01_001E29C0_00380880);
            if (func_0038CE68(&n, &e) >= 0.0f) {
                u0 += D_L01_001DDBE4;
                u1 += D_L01_001DDBE4;
            } else {
                f32 x;
                if (i == 11) {
                    s.col[0] = s.col[1] = D_L01_001DDC5C & 0xFFFFFF;
                }
                s.uv[0][0] = y;
                s.uv[0][1] = u0;
                s.uv[1][0] = y;
                s.uv[1][1] = u0 + D_L01_001DDBE4;
                s.uv[2][0] = y - D_L01_001DDBE0;
                s.uv[2][1] = u0;
                s.uv[3][0] = y - D_L01_001DDBE0;
                s.uv[3][1] = u0 + D_L01_001DDBE4;
                u0 += D_L01_001DDBE4;
                func_003D2DA0(&s, 0, 0);
                s.uv[0][0] = y;
                s.uv[0][1] = u1;
                s.uv[1][0] = y;
                s.uv[1][1] = u1 + D_L01_001DDBE4;
                s.uv[2][0] = y - D_L01_001DDBE0;
                s.uv[2][1] = u1;
                s.uv[3][0] = y - D_L01_001DDBE0;
                s.uv[3][1] = u1 + D_L01_001DDBE4;
                u1 += D_L01_001DDBE4;
                func_003D2DA0(&s, 0, 0);
            }
        }
        y += D_L01_001DDBE0;
    }
}
/* localdecomp:end func_L01_00380880 */

INCLUDE_ASM("asm/levels", func_L01_00380CE0);

/* localdecomp:start func_L01_003812B0 */
#include "structs/weapon.h"
typedef struct {
    Q_0037F860 v[4];
    s32 c[4];
    f32 uv[8];
    long t70, tex0, t80, t88;
} Quad_3812B0;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
__asm__(".extern D_L01_001DDC30, 4");
__asm__(".extern D_L01_001DDC34, 4");
extern s32 D_L01_001DDC30;
extern s32 D_L01_001DDC34;
extern Q_0037F860 D_L01_001DDC80[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DDC80, 4");
extern f32 D_L01_001E1E70[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1E70, 12");
extern f32 D_L01_001E1E50[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1E50, 12");
extern Q_0037F860 D_L01_001E1DE0[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1DE0, 48");
extern Q_0037F860 D_001A4EC0_3812B0;
void func_L01_003812B0(u8 *moby) {
    extern long func_00389598(s32);
    extern void func_0038CE20(Q_0037F860 *, Q_0037F860 *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    Quad_3812B0 quad;
    Q_0037F860 rows[4];
    Q_0037F860 scaled;
    s32 base;
    s32 i;
    s32 k;
    s32 alpha;

    quad.tex0 = func_00389598(8);
    quad.t88 = 0x8000000048L;
    quad.t80 = 0xFF9000000260L;
    quad.t70 = 0;
    quad.uv[0] = 0.0f;
    quad.uv[1] = 0.0f;
    quad.uv[2] = 0.0f;
    quad.uv[3] = 1.0f;
    quad.uv[4] = 1.0f;
    quad.uv[5] = 0.0f;
    quad.uv[6] = 1.0f;
    quad.uv[7] = 1.0f;
    base = ((D_L01_002C5600 + D_001425C0[0x8F])->level >= 4 ? D_L01_001DDC34 : D_L01_001DDC30);
    for (i = 0; i < 3; i++) {
        if (D_L01_001E1E80[i] == 0) continue;
        alpha = (s32)D_L01_001E1E50[i];
        quad.c[0] = quad.c[1] = quad.c[2] = quad.c[3] = (base & 0xFFFFFF) | (alpha << 24);
        rows[3] = D_L01_001E1DE0[i];
        rows[0] = D_L01_001E1E10[i];
        func_0038CE20(&rows[2], &D_001A4EC0_3812B0, -1.0f);
        func_0038CE90(&rows[1], &rows[0], &rows[2]);
        func_0038CF68(&rows[1], &rows[1], 1.0f);
        func_0038CE90(&rows[2], &rows[1], &rows[0]);
        for (k = 0; k < 4; k++) {
            func_0038CE20(&scaled, &D_L01_001DDC80[k], D_L01_001E1E70[i]);
            func_0038D028(&quad.v[k], &scaled, rows);
        }
        func_003D2DA0(&quad, 0, 0);
    }
}
/* localdecomp:end func_L01_003812B0 */

/* localdecomp:start func_L01_00381500 */
#include "vu0.h"
typedef int Q_00381500 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00381500;
typedef struct { Q_00381500 pos[4]; s32 color[4]; f32 uv[8]; long zero, texture, tex1, alpha; } Quad_00381500;
extern Q_00381500 D_L01_001DDC80[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DDC80, 4");
extern f32 D_L01_001DDCC0;
extern f32 D_L01_001DDCC4;
extern f32 D_L01_001DDCC8;
extern s32 D_L01_001DDCCC;
__asm__(".extern D_L01_001DDCC0, 4");
__asm__(".extern D_L01_001DDCC4, 4");
__asm__(".extern D_L01_001DDCC8, 4");
__asm__(".extern D_L01_001DDCCC, 4");
extern V_00381500 D_L01_0028F5A0_00381500;
extern V_00381500 D_L01_001E29C0_00381500;
extern Q_00381500 D_001A4EC0_00381500;
void func_L01_00381500(u8 *moby) {
    extern long func_00389598(s32);
    extern void func_0038CE20_00381500(Q_00381500 *, Q_00381500 *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    Quad_00381500 q;
    Q_00381500 matrix[4];
    struct { Q_00381500 temp, dir; } v;
    s32 i;
    q.texture = func_00389598(11);
    q.alpha = 0x8000000048L;
    q.tex1 = 0xFF9000000260L;

    q.zero = 0;
    q.uv[0] = 0.0f; q.uv[1] = 0.0f;
    q.uv[2] = 0.0f; q.uv[3] = 1.0f;
    q.uv[4] = 1.0f; q.uv[5] = 0.0f;
    q.uv[6] = 1.0f; q.uv[7] = 1.0f;
    q.color[0] = q.color[1] = q.color[2] = q.color[3] = D_L01_001DDCCC;
    func_0038CF68(&v.dir, moby + 0xD0, D_L01_001DDCC8);
    vec_add_ba(&(matrix[3]), &D_L01_0028F5A0_00381500, &(v.dir));
    vec_sub_ab(&(v.dir), &D_L01_001E29C0_00381500, &(matrix[3]));
    func_0038CF68(&matrix[0], &v.dir, 1.0f);
    func_0038CE90(&matrix[1], &matrix[0], &D_001A4EC0_00381500);
    func_0038CF68(&matrix[1], &matrix[1], -1.0f);
    func_0038CE90(&matrix[2], &matrix[1], &matrix[0]);
    for (i = 0; i < 4; i++) {
        func_0038CE20_00381500(&v.temp, &D_L01_001DDC80[i], D_L01_001DDCC0);
        func_0038D028(&q.pos[i], &v.temp, matrix);
    }
    func_003D2DA0(&q, 0, 0);
    q.color[0] = q.color[1] = q.color[2] = q.color[3] = -1;
    for (i = 0; i < 4; i++) {
        func_0038CE20_00381500(&v.temp, &D_L01_001DDC80[i], D_L01_001DDCC4);
        func_0038D028(&q.pos[i], &v.temp, matrix);
    }
    func_003D2DA0(&q, 0, 0);
}
/* localdecomp:end func_L01_00381500 */

INCLUDE_ASM("asm/levels", func_L01_00381720);

/* localdecomp:start func_L01_00382500 */
#include "vu0.h"
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00382578(s32 a0, s32 a1, s32 alpha);
extern u8 D_L01_001DDCE0[8];
__asm__(".extern D_L01_001DDCE0, 8");
extern s32 D_L01_001E1E94;

void func_L01_00382500(u8 *a0) {
    vu0_v4 v;

    func_0038D000(&v, D_L01_001DDCE0, a0 + 0xC0);
    vec_add_ab(&v, a0 + 0x10, &v);
    ((void (*)(void *, s32, s32, f32, f32, f32, f32))func_L01_00382578)(&v, 0x78, D_L01_001E1E94 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_00382500 */

/* localdecomp:start func_L01_00382578 */


__asm__(".extern D_L01_001DDCF0, 4");
__asm__(".extern D_L01_001DDCF8, 4");
__asm__(".extern D_L01_001DDCFC, 4");
__asm__(".extern D_L01_001DDD00, 4");
__asm__(".extern D_L01_001DDD04, 4");
__asm__(".extern D_L01_001DDD08, 4");
__asm__(".extern D_L01_001DDD0C, 4");
__asm__(".extern D_L01_001DDD10, 4");
__asm__(".extern D_L01_001DDD14, 4");
__asm__(".extern D_L01_001DDD18, 4");
__asm__(".extern D_L01_001DDD1C, 4");
__asm__(".extern D_L01_001DDD20, 4");
__asm__(".extern D_L01_001DDD24, 4");
__asm__(".extern D_L01_001DDD28, 4");
extern S_1A1ED0 D_001A1ED0[];
extern S_1CFEC0 D_001CFEC0[];
extern s32 D_L01_001DDCF0;
extern s32 D_L01_001DDCF8;
extern s32 D_L01_001DDCFC;
extern s32 D_L01_001DDD00;
extern s32 D_L01_001DDD04;
extern s32 D_L01_001DDD08;
extern s32 D_L01_001DDD0C;
extern s32 D_L01_001DDD10;
extern s32 D_L01_001DDD14;
extern s32 D_L01_001DDD18;
extern s32 D_L01_001DDD1C;
extern s32 D_L01_001DDD20;
extern s32 D_L01_001DDD24;
extern s32 D_L01_001DDD28;

extern void func_L01_004C5E28(void);
extern void func_003A9440(s32 reg, long value);
extern void func_003D1030(void);
extern long func_00389598(s32);
extern void func_0038B4D0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, long c, long d);

void func_L01_00382578(s32 a0, s32 a1, s32 alpha) {
    S_1A1ED0 *z;
    S_1CFEC0 *s;
    s32 color;
    long tex;

    func_L01_004C5E28();
    z = D_001A1ED0;
    func_003A9440(0x4E, (long)(z->w8 >> 13) | 0x1000000 | 0x100000000L);
    func_003A9440(0x42, (long)D_L01_001DDCFC | ((long)D_L01_001DDD00 << 2) | ((long)D_L01_001DDD04 << 4)
                  | ((long)D_L01_001DDD08 << 6) | (0x80L << 32));
    func_003D1030();
    tex = func_00389598(D_L01_001DDCF0);
    s = D_001CFEC0;
    color = (alpha << 24) | 0x7F7F7F;
    func_0038B4D0(0, 0, (s32)(s->h150 * 0.5f), (s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_0038B4D0(s->h150, 0, -(s32)(s->h150 * 0.5f), (s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_0038B4D0(0, s->h152, (s32)(s->h150 * 0.5f), -(s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_0038B4D0(s->h150, s->h152, -(s32)(s->h150 * 0.5f), -(s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_003A9440(0x42, (long)D_L01_001DDCFC | ((long)D_L01_001DDD00 << 2) | ((long)D_L01_001DDD04 << 4)
                  | ((long)D_L01_001DDD08 << 6) | (0x80L << 32));
    func_003A9440(0x42, (long)D_L01_001DDD0C | ((long)D_L01_001DDD10 << 2) | ((long)D_L01_001DDD14 << 4)
                  | ((long)D_L01_001DDD18 << 6) | (0x80L << 32));
    func_0038B4D0(0, 0, s->h150, s->h152, D_L01_001DDD1C, D_L01_001DDD20, D_L01_001DDD24, D_L01_001DDD28, D_L01_001DDCF8, func_00389598(-7));
    func_003A9440(0x4E, 0x1000000 | (long)(z->w8 >> 13));
}
/* localdecomp:end func_L01_00382578 */

LINKER_REMNANT("asm/levels", func_L01_00382888);

INCLUDE_ASM("asm/levels", func_L01_00382890);

INCLUDE_ASM("asm/levels", func_L01_00382CF8);

/* localdecomp:start func_L01_003837A8 */
void func_L01_003837A8(u8 *a) {
    a[0x20] = 1;
}
/* localdecomp:end func_L01_003837A8 */

/* localdecomp:start func_L01_003837B8 */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003837B8;
extern Vec_003837B8 D_L01_001E29C0_003837B8;
void func_L01_003837B8(f32 *position) {
    extern f32 func_0038D160(f32,f32);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_L01_00443A18(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_00382760_003837B8(void *,f32,f32,f32);
    extern void func_L01_0046A610_003837B8(void *,void *,s32,s32,s32,s32,f32,f32,f32,f32,f32);
    Vec_003837B8 delta,velocity,spawn;
    f32 angle;
    s32 i;
    vec_sub_ab(&delta, &D_L01_001E29C0_003837B8, (Vec_003837B8 *)position);
    angle=func_0038D160(delta.x,delta.y);
    for(i=19;i>=0;i--) {
        f32 speed=func_003824E0(0.5f,1.0f);
        s32 kind=(s32)func_L01_00443A18(1.0f,2.0f);
        f32 pitch, yaw;
        f32 scale=210000.0f;
        func_003824E0(0.1f,0.3f);
        pitch=func_003824E0(0.0f,1.3962634f);
        yaw=func_L01_00443A18(0.0f,1.3962634f);
        yaw=func_0038DAB8(angle,yaw);
        func_00382760_003837B8(&velocity,speed*0.020000001f,yaw,pitch);
        spawn.x=position[0]+func_L01_00443A18(0.0f,0.2f);
        spawn.y=position[1]+func_L01_00443A18(0.0f,0.2f);
        spawn.z=position[2]+func_L01_00443A18(0.0f,0.2f);
        func_L01_0046A610_003837B8(&spawn,&velocity,25,127,0x7f7f7f,kind,func_003824E0(0.05f,0.2f)*scale,500.0f,1.0f,0.0f,1.0f);
    }
}
/* localdecomp:end func_L01_003837B8 */

/* localdecomp:start func_L01_003839C8 */
#include "structs/weapon.h"
#include "structs/moby.h"

typedef int u128_3839C8 __attribute__((mode(TI)));
typedef struct {
    u128_3839C8 start;      /* 0x00 */
    void *owner;            /* 0x10 */
    f32 speed;              /* 0x14 */
    u8 pad_18[8];
    f32 drag;               /* 0x20 */
    s32 unk_24;
    s32 unk_28;
    s32 flags;              /* 0x2C */
    u8 pad_30[4];
    s32 kind;               /* 0x34 */
    s32 shadow;             /* 0x38 */
    s32 target;             /* 0x3C */
} SuckShot_3839C8;
typedef struct {
    u8 pad_0[0x10];
    u128_3839C8 position;
    u8 state;
    u8 pad_21[3];
    struct MobyClass *pclass;
    u8 pad_28[4];
    f32 scale;
    u8 b30;
    u8 b31;
    s16 draw_dist;
    long d38;
    u8 pad_40[0x68 - 0x40];
    SuckShot_3839C8 *pvar;
    u8 pad_6C[0x98 - 0x6C];
    void *coll_record;
    u8 pad_9C[0xAA - 0x9C];
    s16 oclass;
    u8 pad_AC[0xF0 - 0xAC];
    u128_3839C8 rotation;
} MobyQ_3839C8;
typedef struct {
    u8 pad_0[0x25C0];
    MobyQ_3839C8 *hero_moby;
} H_3839C8;

typedef struct {
    s32 w[0x2900 / 4];
} Hw_3839C8;
extern Hw_3839C8 D_001A4BE0;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern MobyQ_3839C8 *func_003C24B0(s32 oclass, s32 a1);
extern s32 func_L01_00445F40(void *moby, s32 target);
extern f32 func_0038CEA8(void *pvar);
extern void func_L01_004CAC78(void *out, void *from, f32 speed, f32 range, f32 max_angle);
extern s32 func_L01_004C85C8(void *moby, s32 a1, f32 x, f32 y, f32 z);
extern void func_003C7C38(void *moby);

/* suck_shot_spawn: spawns the Suck Cannon's shot, class 0x1872 given the model of what it took in at 0.7 of its class's scale */
MobyQ_3839C8 *func_L01_003839C8(f32 speed, void *owner, u128_3839C8 *start, u128_3839C8 *position, u128_3839C8 *rotation, s32 target, s32 kind) {
    MobyQ_3839C8 *m;
    SuckShot_3839C8 *shot;

    m = func_003C24B0(0x1872, 0x80);
    if (m != 0) {
        m->b30 = 0xFF;
        m->draw_dist = 0xFF;
        m->b31 = 1;
        m->state = 0;
        shot = m->pvar;
        m->d38 = ((MobyQ_3839C8 *)D_001A4BE0.w[0x25C0 / 4])->d38;
        m->position = *position;
        m->rotation = *rotation;
        func_L01_00445F40(m, target);
        shot->target = target;
        m->oclass = 0x1872;
        m->scale = m->pclass->scale * 0.7f;
        shot->start = *start;
        shot->owner = owner;
        shot->speed = speed;
        shot->drag = 0.15f;
        shot->kind = kind;
        if ((D_L01_002C5600 + D_001425C0[0x87])->level >= 2) {
            shot->flags = 0x110000;
        } else {
            shot->flags = 0x10000;
        }
        if (D_001A4BE0.w[0x16B0 / 4] != 0) {
            func_L01_004CAC78(shot, position, func_0038CEA8(shot), 30.0f, 0.34906584f);
        }
        shot->shadow = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
        shot->unk_24 = 0;
        func_003C7C38(m);
    }
    m->coll_record = 0;
    return m;
}
/* localdecomp:end func_L01_003839C8 */

INCLUDE_ASM("asm/levels", func_L01_00383BA0);

INCLUDE_ASM("asm/levels", func_L01_00383FB8);

LINKER_REMNANT("asm/levels", func_L01_00384510);

INCLUDE_ASM("asm/levels", func_L01_00384518);

/* localdecomp:start func_L01_00384E68 */
#include "structs/weapon.h"

typedef int u128_384E68 __attribute__((mode(TI)));
typedef struct {
    u8 pad_0[0x10];
    u128_384E68 position;
} Moby_384E68;

extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_L01_001EEA80[];
extern void func_0038CE20(u128_384E68 *out, u128_384E68 *in, f32 scale);
extern s32 func_003D4D00(void *centre, f32 radius, s32 kinds, void *skip, s32 extra);
extern void func_L01_00447718(void *source, void *centre, void *mobys, s32 count, void *skip,
                              s32 flags, s32 a6, s32 a7, s32 a8, f32 damage, f32 push_out, f32 push_up);

/* ryno_missile_blast: the RY3NO V1 missile's blast: every moby within 4 u but the one it hit
   takes the row's splash damage (+0x70), pushed 4 out and 6 up */
void func_L01_00384E68(Moby_384E68 *missile, u128_384E68 *dir, void *hit) {
    u128_384E68 back;
    u128_384E68 centre;
    f32 splash;
    s32 count;

    func_0038CE20(&back, dir, -3.0f);
    /* item 0x97's current row: the RY3NO's */
    splash = (D_L01_002C5600 + D_001425C0[0x97])->damage_more[0];
    count = func_003D4D00(&missile->position, 4.0f, 0x10, missile, 0);
    centre = missile->position;
    func_L01_00447718(missile, &centre, D_L01_001EEA80, count, hit, 0x1010000, 3, 1, -1, splash, 4.0f, 6.0f);
}
/* localdecomp:end func_L01_00384E68 */

LINKER_REMNANT("asm/levels", func_L01_00384F40);

/* localdecomp:start func_L01_00384F48 */
#include "vu0.h"
extern u8 *D_L01_00221098[];
extern u8 D_001A4EC0[];
extern s32 D_L01_001DDD80;
extern s32 D_L01_001DDD84;
__asm__(".extern D_L01_001DDD80, 4");
__asm__(".extern D_L01_001DDD84, 4");
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
extern u8 *func_L01_0046A610_00384F48(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L01_00384F48(u8 *m, u128_384E68 *input) {
    u128_384E68 v[4];
    f32 distance;
    s32 count, i, spin, life, color, alpha;
    f32 size, speed;
    u8 *particle;

    v[0] = *input;
    distance = *(f32 *)(*(u8 **)(m + 0x68) + 0x18);
    v[2] = v[0];
    count = (s32)(distance / 0.1f) / 4;
    vec_sub_ab(&v[3], m + 0x10, &v[0]);
    func_0038CF68(&v[3], &v[3], distance / count);
    for (i = 0; i < count; i++) {
        spin = func_L01_00443A18(1.0f, 3.0f);
        speed = func_003824E0(0.2f, 1.0f) * 0.020000001f;
        func_0038CE20(&v[1], (u128_384E68 *)D_001A4EC0, -speed);
        life = func_00382498(30, 50);
        size = func_003824E0(200.0f, 1000.0f);
        if (func_0013D3E0() & 2) {
            alpha = 0x50;
            color = 0x404040;
        } else {
            alpha = 0x50;
            color = 0x7F7F7F;
        }
        particle = func_L01_0046A610_00384F48(&v[2], &v[1], (life * 5 + 2) / 6, alpha, color, spin, 21000.0f, size, 1.0f, 0.0f, 1.0f);
        vec_add_ab(&v[2], &v[2], &v[3]);
        if (particle) {
            particle[2] = D_L01_00221098[D_L01_001DDD80][D_L01_001DDD84];
            particle[3] = alpha == 0x40 ? 0x48 : 0x44;
        }
    }
}
/* localdecomp:end func_L01_00384F48 */

/* localdecomp:start func_L01_00385188 */
#include "vu0.h"
extern void func_0038D000(void *, void *, void *);
extern f32 D_L01_001DDD88;
__asm__(".extern D_L01_001DDD88, 4");

void func_L01_00385188(s32 a0, void *a1) {
    vu0_v4 r;
    vu0_v4 v;

    *(vu0_q *)&v = 0;
    v.x = D_L01_001DDD88;
    v.w = 1.0f;
    *(vu0_q *)&r = *(vu0_q *)&v;
    func_0038D000(&r, &r, (u8 *)a0 + 0xC0);
    vec_add_ba(a1, &r, (u8 *)a0 + 0x10);
}
/* localdecomp:end func_L01_00385188 */

/* localdecomp:start func_L01_003851F8 */
__asm__(".extern D_L01_001DDD8C, 4");
extern s32 D_L01_001DDD8C;
extern void func_L01_00385188(s32, void *);
extern void func_L01_00409B08(void *, s32, s32);

void func_L01_003851F8(s32 a0) {
    s32 buf[4];
    func_L01_00385188(a0, buf);
    func_L01_00409B08(buf, D_L01_001DDD8C, 0);
}
/* localdecomp:end func_L01_003851F8 */

/* localdecomp:start func_L01_00385228 */
#include "vu0.h"
#include "structs/weapon.h"
typedef int Q_00385228 __attribute__((mode(TI)));
typedef struct {
    s32 index;          /* 0x00 */
    u8 pad_4[0xC];
    s32 unk_10;
    s32 a14;
    s32 a18;
    void *target;       /* 0x1C */
    f32 vel[3];         /* 0x20 */
    f32 speed;          /* 0x2C */
    s32 shadow;         /* 0x30 */
    s32 ticks;          /* 0x34 */
    f32 inv_ticks;      /* 0x38 */
    s32 unk_3C;
    f32 unk_40;
} Vars_00385228;
typedef struct {
    u8 pad_0[0x10];
    Q_00385228 position;
    u8 state;
    u8 pad_21[3];
    u8 *pclass;
    u8 pad_28[4];
    f32 scale;
    u8 b30;
    u8 b31;
    s16 draw_dist;
    u16 h34;
    u8 pad_36[0x68 - 0x36];
    u8 *pvar;
    u8 pad_6C[0xAA - 0x6C];
    s16 oclass;
    u8 pad_AC[0xB8 - 0xAC];
    void *owner;
    u8 pad_BC[0xD0 - 0xBC];
    Q_00385228 d0;
} Moby_00385228;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern Q_00385228 D_001A4C60;
extern f32 D_L01_001DDD98;
extern s32 D_L01_001DDD90, D_L01_001DDD94_00385228;
__asm__(".extern D_L01_001DDD90, 4");
__asm__(".extern D_L01_001DDD94_00385228, 4");
__asm__(".extern D_L01_001DDD98, 4");
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004CB128(void *, void *, s32);
extern void func_L01_004CAC78(void *, void *, f32, f32, f32);
extern u8 *func_00382348_00385228(void *);
extern s32 func_L01_00457458(s32, s32);
extern void func_003C2880(void *);
extern s32 func_L01_004C85C8_00385228(void *, f32, f32, f32, s32);
extern void func_L01_00385EE0_00385228(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_003C7C38(void *);
Moby_00385228 *func_L01_00385228(Q_00385228 *position, Moby_00385228 *owner, Moby_00385228 *target)
{
    Q_00385228 temp;
    Moby_00385228 *moby = (Moby_00385228 *)func_003C24B0(0x1881, 0x80);
    Vars_00385228 *vars;
    f32 speed;
    s32 ticks;
    Hw_3839C8 *h;
    u8 *hit;
    if (moby) {
        vars = (Vars_00385228 *)moby->pvar;
        moby->b30 = 255;
        moby->h34 = 0x100;
        moby->draw_dist = 255;
        moby->b31 = 1;
        moby->owner = owner;
        moby->state = 0;
        vars->unk_3C = 0;
        h = &D_001A4BE0;
        speed = (D_L01_002C5600 + D_001425C0[0x2F])->shot_speed * 0.020000001f;
        if (((s16 *)h->w)[0x2874 / 2] == 1) {
            func_0038CF68(vars->vel, &owner->d0, -speed);
            moby->position = *position;
        } else if (target) {
            func_L01_004CB128(&temp, target, 0);
            vec_sub_ab(vars->vel, &temp, position);
            func_0038CF68(vars->vel, vars->vel, speed);
            moby->position = *position;
        } else {
            if (h->w[0x16B0 / 4]) {
                func_L01_004CAC78(vars->vel, position, speed, 35.0f, 1.3962634f);
            } else {
                func_0038CF68(vars->vel, &h->w[0x6F0 / 4], speed);
            }
            moby->position = *position;
        }
        ticks = (s32)(30.0f / speed) + 30;
        vars->speed = speed;
        vars->ticks = ticks;
        vars->inv_ticks = 1.0f / ticks;
        moby->scale = *(f32 *)(moby->pclass + 0x24) * D_L01_001DDD98;
        moby->state = 0;
        vars->target = target;
        if (target) {
            hit = func_00382348_00385228(target);
            if (hit) *(u16 *)(hit + 0x1E) |= 0x80;
        }
        vars->unk_40 = 1.0f;
        vars->a14 = *(s16 *)(owner->pvar + 0x5A);
        vars->a18 = owner->oclass;
        if (!func_L01_00457458(vars->a18, vars->a14)) {
            func_003C2880(moby);
            return 0;
        }
        vars->unk_10 = 0;
        D_L01_001DDD94_00385228 = 0;
        if ((u32)D_L01_001DDD90 >= 16) D_L01_001DDD90 = 0;
        vars->index = D_L01_001DDD90;
        D_L01_001DDD90 = D_L01_001DDD90 + 1;
        if (D_L01_001DDD90 >= 16) D_L01_001DDD90 = 0;
        temp = moby->position;
        moby->position = D_001A4C60;
        vars->shadow = func_L01_004C85C8_00385228(moby, 1.0f, 1.0f, 1.0f, 0);
        moby->position = temp;
        func_L01_00404A10(func_L01_00385EE0_00385228, moby);
        func_003C7C38(moby);
    }
    return moby;
}
/* localdecomp:end func_L01_00385228 */

INCLUDE_ASM("asm/levels", func_L01_003854F8);

/* localdecomp:start func_L01_00385EA0 */
extern void func_L01_004C8668(int);
extern void func_003C2880(void *);
void func_L01_00385EA0(char *m)
{
    char *v = *(char **)(m + 104);
    if (v != 0) {
        func_L01_004C8668(*(int *)(v + 48));
    }
    func_003C2880(m);
}
/* localdecomp:end func_L01_00385EA0 */

/* localdecomp:start func_L01_00385EE0 */
#include "structs/moby.h"

typedef int u128_385EE0 __attribute__((mode(TI)));
/* an N90 bullet's pvars: what its tail keeps */
typedef struct {
    s32 slot;                      /* 0x00: the bullet's row in the tail table */
    u8 pad_04[0x10 - 0x4];
    s32 points;                    /* 0x10: points kept, up to 40 */
    s32 key_b;                     /* 0x14 */
    s32 key_a;                     /* 0x18 */
    u8 pad_1C[0x30 - 0x1C];
    s32 glow;                      /* 0x30 */
    s32 fade;                      /* 0x34: frames left of the fade once the bullet ends */
} Bullet_385EE0;

__asm__(".extern D_L01_001DDD94, 4");
extern f32 D_L01_001DDD94;
extern u128_385EE0 **func_L01_00457480(s32 a, s32 b);
extern void func_L01_004C8668(s32);
extern void func_003C2880(void *);
extern void func_L01_004CAB30(void *, void *);
extern void func_L01_00386148(void *points, s32 a1, s32 a2, s32 count, s32 colour_end, s32 colour_start, f32 f0, f32 f1, f32 scroll);

/* n90_bullet_tail_record: keeps where the N90 bullet was over its last 20 frames, for its tail */
void func_L01_00385EE0(struct Moby *m) {
    Bullet_385EE0 *b;
    u128_385EE0 **table;
    u128_385EE0 *row;
    s32 slot;
    s32 i;
    s32 j;
    s32 count;
    s32 tail;
    s32 head;
    s32 pts;
    f32 scroll;
    f32 fade;

    b = m->pvar;
    if (m == 0) return;
    if ((u8)m->state == 0xFE) return;
    if ((u8)m->state == 0xFD) return;
    if (b == 0) return;
    slot = b->slot;
    table = func_L01_00457480(b->key_a, b->key_b);
    if (table == 0) {
        func_L01_004C8668(b->glow);
        func_003C2880(m);
        return;
    }
    for (i = 0; i < b->points; i++) {
        func_L01_004CAB30(table[slot] + i, table[slot] + i);
    }
    if ((u8)m->state == 0) {
        b->points++;
        if (b->points >= 40) b->points = 40;
        for (j = b->points - 1; j > 0; j--) {
            table[slot][j] = table[slot][j - 1];
        }
        table[slot][0] = *(u128_385EE0 *)&m->position;
        ((f32 *)table[slot])[3] = 0.05f;
    }
    scroll = D_L01_001DDD94 - 0.1f;
    D_L01_001DDD94 = scroll;
    if (scroll <= -7.0f) {
        D_L01_001DDD94 = scroll + 7.0f;
    }
    pts = b->points;
    if (pts < 2) return;
    count = 20;
    if (pts <= count - 1) {
        count = pts;
    }
    tail = 0x40;
    head = 0xFF;
    if ((u8)m->state == 1) {
        fade = (f32)b->fade / 5.0f;
        head = (s32)(head * fade);
        tail = (s32)(tail * fade);
    }
    func_L01_00386148(table[slot], 0x17, 0xE, count, (head << 24) | 0xFFFFFF, (tail << 24) | 0x707070, 0.0f, 4.0f, D_L01_001DDD94);
}
/* localdecomp:end func_L01_00385EE0 */

INCLUDE_ASM("asm/levels", func_L01_00386148);

INCLUDE_ASM("asm/levels", func_L01_00386410);

/* localdecomp:start func_L01_003868A0 */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003868A0;
extern Vec_003868A0 D_L01_001E29C0;
void func_L01_003868A0(u8 *obj, Vec_003868A0 *pos) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(Vec_003868A0 *, f32, f32, f32);
    extern void func_L01_0046A610(Vec_003868A0 *, Vec_003868A0 *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    Vec_003868A0 delta, velocity, origin;
    u8 *state;
    f32 angle;
    s32 count;
    s32 i;
    state = *(u8 **)(obj + 0x68);
    vec_sub_ab(&delta, &D_L01_001E29C0, pos);
    angle = func_0038D160(delta.x, delta.y);
    count = 2;
    if (*(s32 *)(state + 0x3C) <= 1) count = 5;
    for (i = 0; i < count; i++) {
        f32 speed = func_003824E0(0.5f, 1.0f);
        s32 type = (s32)func_L01_00443A18(1.0f, 2.0f);
        f32 spread;
        f32 yaw;
        f32 duration;
        duration = func_003824E0(0.05f, 0.2f) * 210000.0f;
        spread = func_003824E0(0.0f, 1.39626336f);
        yaw = func_L01_00443A18(0.0f, 1.39626336f);
        yaw = func_0038DAB8(angle, yaw);
        func_00382760(&velocity, speed * 0.0200000014f, yaw, spread);
        origin.x = pos->x + func_L01_00443A18(0.0f, 0.1f);
        origin.y = pos->y + func_L01_00443A18(0.0f, 0.1f);
        origin.z = pos->z + func_L01_00443A18(0.0f, 0.1f);
        duration = func_003824E0(0.05f, 0.2f) * 210000.0f;
        func_L01_0046A610(&origin, &velocity, 25, 127, 0x7F7F7F, type, duration, 500.0f, 1.0f, 0.0f, 1.0f);
    }
}
/* localdecomp:end func_L01_003868A0 */

/* localdecomp:start func_L01_00386AD8 */
extern s32 func_003C4B50(s32);
extern f32 *func_00382348(s32);

s32 func_L01_00386AD8(s32 a0) {
    f32 *p;

    if (func_003C4B50(a0)) return 0;
    p = func_00382348(a0);
    if (p == 0) return 0;
    if (*p > 0.0f) return 0;
    return 1;
}
/* localdecomp:end func_L01_00386AD8 */
