#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* declared by functions of L39_00557E48.c, which this file was cut from */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CE68();
typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L39_005591C8);

INCLUDE_ASM("asm/levels", func_L39_00559268);

/* localdecomp:start func_L39_005593F8 */
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; } T_005593F8;
typedef struct { u8 p0[0x2524]; T_005593F8 *t; } G_005593F8;
typedef struct { u8 p0[8]; G_005593F8 *g; u8 p1[0x68]; f32 f74; u8 p2[8]; f32 f80; f32 f84; } V_005593F8;
typedef struct { u8 p0[0x68]; V_005593F8 *v; } M_005593F8;
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L39_005594C8(M_005593F8 *);
/* defined later in this file with its own (anonymous) struct pointer type: declared without a prototype */
extern void func_L39_005596F0();
__asm__(".extern D_L39_0024B2F8, 4");
__asm__(".extern D_L39_0024B36C, 4");
__asm__(".extern D_L39_0024B370, 4");
extern f32 D_L39_0024B2F8;
extern f32 D_L39_0024B36C;
extern f32 D_L39_0024B370;

void func_L39_005593F8(M_005593F8 *m) {
    V_005593F8 *v = m->v;
    f32 a;
    f32 deg;

    a = func_0038D160(v->g->t->f10 - v->f80, v->g->t->f14 - v->f84);
    deg = func_0038DBA0(a, v->f74) * 180.0f / 3.14159274f;
    func_L39_005594C8(m);
    func_L39_005596F0(m);
    if (deg > 1.0471976f) {
        D_L39_0024B2F8 = D_L39_0024B370 * D_L39_0024B36C;
    } else {
        D_L39_0024B2F8 = D_L39_0024B370;
    }
    *(u128_t *)&v->f80 = *(u128_t *)((u8 *)v->g->t + 0x10);
}
/* localdecomp:end func_L39_005593F8 */

INCLUDE_ASM("asm/levels", func_L39_005594C8);

INCLUDE_ASM("asm/levels", func_L39_00559588);
