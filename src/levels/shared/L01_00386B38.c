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

INCLUDE_ASM("asm/levels", func_L01_00389810);

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

INCLUDE_ASM("asm/levels", func_L01_0038C9B0);

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

INCLUDE_ASM("asm/levels", func_L01_0038CE18);

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
