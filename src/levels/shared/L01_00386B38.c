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
extern void func_003A9440(s32, unsigned long);
extern unsigned long func_00389598(s32 a);
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
