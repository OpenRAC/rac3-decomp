#include "common.h"

typedef struct {
    u8 pad0[104];
    u8 *inner;
} Obj3899C0;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q[5];
} S_2BEE10;

INCLUDE_ASM("asm/levels", func_L01_00386B38);

INCLUDE_ASM("asm/levels", func_L01_003882A0);

INCLUDE_ASM("asm/levels", func_L01_003884D8);

INCLUDE_ASM("asm/levels", func_L01_003886E8);

INCLUDE_ASM("asm/levels", func_L01_00388AC8);

INCLUDE_ASM("asm/levels", func_L01_00388EE0);

/* localdecomp:start func_L01_00389798 */
typedef struct {
    u8 pad_0[0x10];
    u8 position[0x10];
} ShotVars_389798;
typedef struct {
    u8 pad_0[0x68];
    ShotVars_389798 *vars;
} Moby_389798;

/* The screen warp's timer: 6 frames for an uncharged shot, 27 charged (0x1E1F20 on NTSC-U) */
extern s32 D_L01_001E1EA0;
extern void func_L01_00389810(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d);

/* shock_cannon_warp: the Shock Cannon's screen warp each frame its timer runs: texture 66 at
   5 x the timer; the four floats (1, 0, 0, 0.9) aren't read */
void func_L01_00389798(Moby_389798 *shot) {
    func_L01_00389810(shot->vars->position, 0x42, D_L01_001E1EA0 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_00389798 */

/* localdecomp:start func_L01_003897E8 */
/* The charged lance's beam state (0x1E1F50 on NTSC-U); declared small so its address is one la,
   as retail builds it. */
extern u8 D_L01_001E1ED0[8];
/* The beam's numbers: fade times, half width, texture spacing (0x2B3C90 on NTSC-U) */
extern u8 D_L01_002B3C10[];
extern void func_L01_0040B858(void *beam, void *numbers);

/* shock_cannon_beam_draw: draws the Shock Cannon's charged lance beam with fx_beam_rings:
   texture 69 from the gun 40 u along the aim */
void func_L01_003897E8(void) {
    func_L01_0040B858(D_L01_001E1ED0, D_L01_002B3C10);
}
/* localdecomp:end func_L01_003897E8 */

/* localdecomp:start func_L01_00389810 */
extern s32 D_001D5520;
extern s16 D_001CFEC0[];
extern s32 D_L01_001DDE38;
__asm__(".extern D_L01_001DDE38, 4");
extern s32 D_L01_001DDE40;
__asm__(".extern D_L01_001DDE40, 4");
extern s32 D_L01_001DDE44;
__asm__(".extern D_L01_001DDE44, 4");
extern s32 D_L01_001DDE48;
__asm__(".extern D_L01_001DDE48, 4");
extern s32 D_L01_001DDE4C;
__asm__(".extern D_L01_001DDE4C, 4");
extern s32 D_L01_001DDE50;
__asm__(".extern D_L01_001DDE50, 4");
extern s32 D_L01_001DDE54;
__asm__(".extern D_L01_001DDE54, 4");
extern s32 D_L01_001DDE58;
__asm__(".extern D_L01_001DDE58, 4");
extern s32 D_L01_001DDE5C;
__asm__(".extern D_L01_001DDE5C, 4");
extern s32 D_L01_001DDE60;
__asm__(".extern D_L01_001DDE60, 4");
extern s32 D_L01_001DDE64;
__asm__(".extern D_L01_001DDE64, 4");
extern s32 D_L01_001DDE68;
__asm__(".extern D_L01_001DDE68, 4");
extern s32 D_L01_001DDE6C;
__asm__(".extern D_L01_001DDE6C, 4");
extern s32 D_L01_001DDE70;
__asm__(".extern D_L01_001DDE70, 4");
extern s32 D_L01_001DDE94;
__asm__(".extern D_L01_001DDE94, 4");
extern void func_L01_004C5E28(void);
/* the file's earlier blocks declare it with a 32-bit value; these calls pass the full 64-bit GS register */
extern void func_003A9440(s32, s32);
extern long func_00389598(s32 a);
extern void func_0038B4D0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, long i, long j);

/* shock_cannon_warp_draw: the screen warp, texture 66 into the frame's alpha in four mirrored quarters, then the frame's copy mixed in */
void func_L01_00389810(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d) {
    long tex, col;

    func_L01_004C5E28();
    if (D_001D5520 != 0) {
        D_L01_001DDE94 = -1;
        D_L01_001DDE6C = 0xEC;
        D_L01_001DDE70 = 0xF0;
    }
    ((void (*)(s32, long))func_003A9440)(0x47, 0x513F1);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE44 | ((long)D_L01_001DDE48 << 2) | ((long)D_L01_001DDE4C << 4) | ((long)D_L01_001DDE50 << 6)) | (0x8000L << 24));
    tex = func_00389598(D_L01_001DDE38);
    col = (s32)((alpha << 24) | 0x7F7F7F);
    func_0038B4D0(0, 0, (s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], 0, -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(0, D_001CFEC0[0xA9], (s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], D_001CFEC0[0xA9], -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE44 | ((long)D_L01_001DDE48 << 2) | ((long)D_L01_001DDE4C << 4) | ((long)D_L01_001DDE50 << 6)) | (0x8000L << 24));
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE54 | ((long)D_L01_001DDE58 << 2) | ((long)D_L01_001DDE5C << 4) | ((long)D_L01_001DDE60 << 6)) | (0x8000L << 24));
    func_0038B4D0(0, 0, D_001CFEC0[0xA8], D_001CFEC0[0xA9], D_L01_001DDE64, D_L01_001DDE68, D_L01_001DDE6C, D_L01_001DDE70, D_L01_001DDE40, func_00389598(D_L01_001DDE94));
}
/* localdecomp:end func_L01_00389810 */

INCLUDE_ASM("asm/levels", func_L01_00389B00);

INCLUDE_ASM("asm/levels", func_L01_00389C28);

INCLUDE_ASM("asm/levels", func_L01_0038A0F8);

INCLUDE_ASM("asm/levels", func_L01_0038A4B8);

INCLUDE_ASM("asm/levels", func_L01_0038A708);

/* localdecomp:start func_L01_0038ACE8 */

extern s32 func_L01_005119E0(s32);
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);

void func_L01_0038ACE8(Obj3899C0 *obj) {
    u8 *p = obj->inner;
    if (*(s32 *)(p + 36) == 0) {
        return;
    }
    if (func_L01_005119E0(-1)) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0038ACE8 */

INCLUDE_ASM("asm/levels", func_L01_0038AD40);

INCLUDE_ASM("asm/levels", func_L01_0038B280);

/* localdecomp:start func_L01_0038B950 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_0038B950(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0038B950 */

/* localdecomp:start func_L01_0038B988 */
extern void func_L01_0036E578_0038B988();
 
void func_L01_0038B988(void) {
    func_L01_0036E578_0038B988();
}
/* localdecomp:end func_L01_0038B988 */

INCLUDE_ASM("asm/levels", func_L01_0038B9A8);

INCLUDE_ASM("asm/levels", func_L01_0038BB10);

/* localdecomp:start func_L01_0038C9A0 */
void func_L01_0038C9A0(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_0038C9A0 */

/* localdecomp:start func_L01_0038C9B0 */
typedef int s128_9B0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_38C9B0;
typedef struct { f32 x, y, z; } V3_38C9B0;
typedef struct { f32 u, v; } Uv_38C9B0;
extern V3_38C9B0 D_L01_00291360[];
extern s32 D_L01_00291558[];
extern Uv_38C9B0 D_L01_00291600[];
/* the file's earlier blocks declare it with a 32-bit value; these calls pass the full 64-bit GS register */
extern void func_003A9440(s32, s32);
extern long func_00389598(s32 a);
extern void func_0038C750(void);
extern f32 func_0038DB48(f32 a);
extern void func_0038D098(f32 a);
extern void func_00382760(V4_38C9B0 *v, f32 a, f32 b, f32 c);
extern void func_0038D028(void *a, void *b, void *c);
extern void func_003D3A24(s32 n, void *a, void *b, void *c, s32 d);

/* eruptor_band: a band of the unit ball, 21 pairs of points, u along it */
void func_L01_0038C9B0(s128_9B0 *matrix, f32 span, f32 from_lat, f32 to_lat, s32 texture, f32 unused_f, s32 colour, s32 added) {
    V4_38C9B0 v;
    V4_38C9B0 w;
    f32 step, lon, u, rad, twenty;
    s32 i, k;

    ((void (*)(s32, unsigned long))func_003A9440)(8, 0);
    ((void (*)(s32, unsigned long))func_003A9440)(0x14, 0xFF9000000260UL);
    ((void (*)(s32, unsigned long))func_003A9440)(0x47, 0x513F1);
    ((void (*)(s32, unsigned long))func_003A9440)(6, func_00389598(texture));
    if (added != 0) {
        ((void (*)(s32, unsigned long))func_003A9440)(0x42, 0x8000000048UL);
    } else {
        ((void (*)(s32, unsigned long))func_003A9440)(0x42, 0x8000000041UL);
    }
    rad = 0.0174532924f;
    func_0038C750();
    twenty = 20.0f;
    step = span * rad / twenty;
    for (i = 0; i < 42; i += 2) {
        k = i / 2;
        lon = func_0038DB48((f32)k * step);
        func_0038D098(lon);
        u = (f32)k / twenty;
        D_L01_00291558[i] = colour;
        D_L01_00291558[i + 1] = colour;
        D_L01_00291600[i].u = u;
        D_L01_00291600[i].v = 0.0f;
        D_L01_00291600[i + 1].u = u;
        D_L01_00291600[i + 1].v = 1.0f;
        func_00382760(&v, 1.0f, lon, from_lat * rad);
        v.w = 1.0f;
        func_0038D028(&w, &v, matrix);
        D_L01_00291360[i].x = w.x;
        D_L01_00291360[i].y = w.y;
        D_L01_00291360[i].z = w.z;
        func_00382760(&v, 1.0f, lon, to_lat * rad);
        v.w = 1.0f;
        func_0038D028(&w, &v, matrix);
        D_L01_00291360[i + 1].x = w.x;
        D_L01_00291360[i + 1].y = w.y;
        D_L01_00291360[i + 1].z = w.z;
    }
    func_003D3A24(0x2A, D_L01_00291360, D_L01_00291558, D_L01_00291600, 1);
}
/* localdecomp:end func_L01_0038C9B0 */

INCLUDE_ASM("asm/levels", func_L01_0038CC38);

/* localdecomp:start func_L01_0038CDC8 */
typedef struct {
    u8 pad_0[0x10];
    u8 position[0x10];
} Moby_38CDC8;

/* The warp's timer, set at the spawn from the last burst's 30 less its distance from the camera,
   kept within 15 to 30 (0x1E1F9C on NTSC-U) */
extern s32 D_L01_001E1F1C;
extern void func_L01_0038CE18(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d);

/* eruptor_warp: the screen warp while its timer runs, as the Shock Cannon's: texture 66 at
   5 x the timer; the four floats (1, 0, 0, 0.9) aren't read */
void func_L01_0038CDC8(Moby_38CDC8 *blast) {
    func_L01_0038CE18(blast->position, 0x42, D_L01_001E1F1C * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_0038CDC8 */

/* localdecomp:start func_L01_0038CE18 */
extern s32 D_001D5520;
extern s16 D_001CFEC0[];
extern s32 D_L01_001DDF50;
__asm__(".extern D_L01_001DDF50, 4");
extern s32 D_L01_001DDF54;
__asm__(".extern D_L01_001DDF54, 4");
extern s32 D_L01_001DDF58;
__asm__(".extern D_L01_001DDF58, 4");
extern s32 D_L01_001DDF5C;
__asm__(".extern D_L01_001DDF5C, 4");
extern s32 D_L01_001DDF60;
__asm__(".extern D_L01_001DDF60, 4");
extern s32 D_L01_001DDF64;
__asm__(".extern D_L01_001DDF64, 4");
extern s32 D_L01_001DDF68;
__asm__(".extern D_L01_001DDF68, 4");
extern s32 D_L01_001DDF6C;
__asm__(".extern D_L01_001DDF6C, 4");
extern s32 D_L01_001DDF70;
__asm__(".extern D_L01_001DDF70, 4");
extern s32 D_L01_001DDF74;
__asm__(".extern D_L01_001DDF74, 4");
extern s32 D_L01_001DDF78;
__asm__(".extern D_L01_001DDF78, 4");
extern s32 D_L01_001DDF7C;
__asm__(".extern D_L01_001DDF7C, 4");
extern s32 D_L01_001DDF80;
__asm__(".extern D_L01_001DDF80, 4");
extern s32 D_L01_001DDF84;
__asm__(".extern D_L01_001DDF84, 4");
extern s32 D_L01_001DDF88;
__asm__(".extern D_L01_001DDF88, 4");
extern void func_L01_004C5E28(void);
/* the file's earlier blocks declare it with a 32-bit value; these calls pass the full 64-bit GS register */
extern void func_003A9440(s32, s32);
extern long func_00389598(s32 a);
extern void func_0038B4D0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, long i, long j);

/* eruptor_warp_draw: the screen warp, texture 66 into the frame's alpha in four mirrored quarters, then the frame's copy mixed in */
void func_L01_0038CE18(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d) {
    long tex, col;

    func_L01_004C5E28();
    if (D_001D5520 != 0) {
        D_L01_001DDF88 = -1;
        D_L01_001DDF80 = 0xEC;
        D_L01_001DDF84 = 0xF0;
    }
    ((void (*)(s32, long))func_003A9440)(0x47, 0x513F1);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDF58 | ((long)D_L01_001DDF5C << 2) | ((long)D_L01_001DDF60 << 4) | ((long)D_L01_001DDF64 << 6)) | (0x8000L << 24));
    tex = func_00389598(D_L01_001DDF50);
    col = (s32)((alpha << 24) | 0x7F7F7F);
    func_0038B4D0(0, 0, (s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], 0, -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(0, D_001CFEC0[0xA9], (s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], D_001CFEC0[0xA9], -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDF58 | ((long)D_L01_001DDF5C << 2) | ((long)D_L01_001DDF60 << 4) | ((long)D_L01_001DDF64 << 6)) | (0x8000L << 24));
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDF68 | ((long)D_L01_001DDF6C << 2) | ((long)D_L01_001DDF70 << 4) | ((long)D_L01_001DDF74 << 6)) | (0x8000L << 24));
    func_0038B4D0(0, 0, D_001CFEC0[0xA8], D_001CFEC0[0xA9], D_L01_001DDF78, D_L01_001DDF7C, D_L01_001DDF80, D_L01_001DDF84, D_L01_001DDF54, func_00389598(D_L01_001DDF88));
}
/* localdecomp:end func_L01_0038CE18 */

/* localdecomp:start func_L01_0038D108 */
extern void func_L01_0038E720_0038D108(void *);
extern void func_L01_0038D108(void *);

extern void func_L01_0038E4D0_0038D108();
void func_L01_0038D108(void *p) {
    func_L01_0038E4D0_0038D108(p);
    func_L01_0038E720_0038D108(p);
}
/* localdecomp:end func_L01_0038D108 */

/* localdecomp:start func_L01_0038D138 */
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s16 D_001CFEC0[];

void func_L01_0038D138(void) {
    func_003A9440(66, 72);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], (s32)0x80808080);
}
/* localdecomp:end func_L01_0038D138 */

INCLUDE_ASM("asm/levels", func_L01_0038D180);

/* localdecomp:start func_L01_0038D498 */


extern void func_0038D328(s128 *, S_38C110v *);
extern void func_0038D640(s128 *, void *, s128 *);
extern void func_0038CE20(s128 *, s128 *, f32);
extern void func_L01_0038C9B0(s128 *, f32, f32, f32, s32, f32, s32, s32);

void func_L01_0038D498(S_38C110v *a0, void *a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16, f32 f17) {
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
    func_L01_0038C9B0(m2, f17, f14, f15, a2, f16, a3, 1);
}
/* localdecomp:end func_L01_0038D498 */

INCLUDE_ASM("asm/levels", func_L01_0038D5C0);

INCLUDE_ASM("asm/levels", func_L01_0038DF00);

LINKER_REMNANT("asm/levels", func_L01_0038E4C8);

INCLUDE_ASM("asm/levels", func_L01_0038E4D0);

INCLUDE_ASM("asm/levels", func_L01_0038E720);

/* localdecomp:start func_L01_0038E968 */

extern S_2BEE10 D_L01_002BEDD0;
extern void func_L01_003006C0(S_2BEE10 *, u8 *, s32, s32);

void func_L01_0038E968(u8 *a0) {
    S_2BEE10 m = D_L01_002BEDD0;

    func_L01_003006C0(&m, a0 + 16, 0, 0);
}
/* localdecomp:end func_L01_0038E968 */

INCLUDE_ASM("asm/levels", func_L01_0038E9C8);
