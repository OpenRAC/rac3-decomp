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

INCLUDE_ASM("asm/levels", func_L01_0037F860);

INCLUDE_ASM("asm/levels", func_L01_0037F948);

INCLUDE_ASM("asm/levels", func_L01_00380880);

INCLUDE_ASM("asm/levels", func_L01_00380CE0);

INCLUDE_ASM("asm/levels", func_L01_003812B0);

INCLUDE_ASM("asm/levels", func_L01_00381500);

INCLUDE_ASM("asm/levels", func_L01_00381720);

INCLUDE_ASM("asm/levels", func_L01_00382500);

/* localdecomp:start func_L01_00382578 */


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

INCLUDE_ASM("asm/levels", func_L01_003837B8);

INCLUDE_ASM("asm/levels", func_L01_003839C8);

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

INCLUDE_ASM("asm/levels", func_L01_00384F48);

INCLUDE_ASM("asm/levels", func_L01_00385188);

/* localdecomp:start func_L01_003851F8 */
extern s32 D_L01_001DDD8C;
extern void func_L01_00385188(s32, void *);
extern void func_L01_00409B08(void *, s32, s32);

void func_L01_003851F8(s32 a0) {
    s32 buf[4];
    func_L01_00385188(a0, buf);
    func_L01_00409B08(buf, D_L01_001DDD8C, 0);
}
/* localdecomp:end func_L01_003851F8 */

INCLUDE_ASM("asm/levels", func_L01_00385228);

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

INCLUDE_ASM("asm/levels", func_L01_00385EE0);

INCLUDE_ASM("asm/levels", func_L01_00386148);

INCLUDE_ASM("asm/levels", func_L01_00386410);

INCLUDE_ASM("asm/levels", func_L01_003868A0);

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
