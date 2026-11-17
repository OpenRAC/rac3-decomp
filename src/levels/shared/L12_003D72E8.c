#include "common.h"

typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; void *w68; } M_3D5548;
typedef struct {
    void (*fn0)(void *);
} Iface;
typedef struct {
    char pad0[0x30];
    int timer;
    char pad34[0x3E - 0x34];
    unsigned char b62;
    char pad3F[0x40 - 0x3F];
    float f64;
} Vars;
typedef struct {
    char pad0[0x30];
    unsigned char b48;
    char pad31[0x32 - 0x31];
    short h50;
} Obj;

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L12_003D4B18.c, which this file was cut from */
extern void func_L01_004450F0(Obj *, int, int);

/* localdecomp:start func_L12_003D72E8 */
extern void func_L12_003D7330(Obj *obj, Vars *v);
extern void func_L12_003D73C0(void);
extern void func_L01_00404808(void (*)(void), M_3D5548 *);

void func_L12_003D72E8(M_3D5548 *m) {
    void *p = m->w68;
    if (m->b20 == 0) {
        ((void (*)(M_3D5548 *, void *))func_L12_003D7330)(m, p);
    }
    func_L01_00404808(func_L12_003D73C0, m);
}
/* localdecomp:end func_L12_003D72E8 */

/* localdecomp:start func_L12_003D7330 */



extern Iface *func_L01_0043B548(int, int);
extern void func_L01_004450F0(Obj *, int, int);

void func_L12_003D7330(Obj *obj, Vars *v) {
    Iface *it;

    obj->b48 = 255;
    obj->h50 = 511;
    v->f64 = 1.0f;
    if (v->timer > 0) {
        it = func_L01_0043B548(6625, 108);
        v->timer = -1;
        v->b62 = 2;
        it->fn0(obj);
    } else {
        func_L01_004450F0(obj, 1, -1);
    }
}
/* localdecomp:end func_L12_003D7330 */

INCLUDE_ASM("asm/levels", func_L12_003D73C0);
