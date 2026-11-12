#include "common.h"

/* localdecomp:start func_L03_004121B8 */
typedef struct O_004121B8 {
    char pad0[0x34];
    unsigned short flags;
    char pad1[0x63 - 0x36];
    unsigned char b63;
    char pad2[4];
    int p68;
    char pad2b[3];
    unsigned char b6f;
    char pad3[0xAA - 0x70];
    short id;
} O_004121B8;
typedef struct G_004121B8 {
    char pad0[0x30];
    int v30;
    int v34;
    char pad1[0x44 - 0x38];
    short n;
    char pad2[0x1A0 - 0x46];
    O_004121B8 *list[8];
} G_004121B8;
extern G_004121B8 D_L03_001E6800;
extern O_004121B8 *D_L03_00238E70[];
__asm__(".extern D_L03_00238E70, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_L03_001D6AB0[4];
__asm__(".extern D_L03_001D6AB0, 4");
extern u8 D_L03_001D6AB4;
__asm__(".extern D_L03_001D6AB4, 16");
extern u8 D_L03_001D6AB8;
__asm__(".extern D_L03_001D6AB8, 16");

extern void func_L01_00423AB8();
extern void func_003A58C0();
extern void func_L01_004048D0();
extern void func_003A7AF8();
extern void func_L01_00451DB8(void *, void *, unsigned, unsigned, float);
extern void func_L01_00404808();
extern void func_L01_00424168();
extern void func_L03_00411BD0();
extern void func_L03_00411C40();
extern void func_L03_00411E60();
extern void func_L03_00411F50();
extern void func_L03_00411778();

void func_L03_004121B8(void) {
    int i;
    O_004121B8 *o;
    int j;
    func_L01_00423AB8();
    for (i = 0; i < D_L03_001E6800.n; i++) {
        o = D_L03_001E6800.list[i];
        if (o != 0 && o->id == 0xE29) o->flags |= 0x800;
        if (o->id == 0xD54) {
            o->b63 = 0;
            for (j = 0; D_L03_00238E70[j] != 0; j++) {
                if (D_L03_00238E70[j]->b63 != 0) D_L03_00238E70[j]->b63 = 1;
            }
            func_003A58C0(o, 0);
            func_L01_004048D0(func_003A7AF8, o);
        }
        if (o != 0) {
            if (o->id == 0xFA0) {
                if (o->p68 != 0)
                    func_L01_00451DB8(o, o->p68 + 12, 0x80AAAAD2, 0x80396464, 0.07330383f);
            } else if (o->id == 0x1DEE || o->id == 0x19BC) {
                func_L01_00451DB8(o, D_L03_001D6AB0, 0x80505080, 0x80404038, 0.038397245f);
            } else if (o->id == 0x1977) {
                func_L01_00451DB8(o, &D_L03_001D6AB4, 0x8080AAAA, 0x80464646, 0.045378566f);
            } else if (o->id == 0x1766) {
                func_L01_00451DB8(o, &D_L03_001D6AB8, 0x80AAAAFF, 0x80646496, 0.13264504f);
            } else if (o->id == 0x195B || o->id == 0x1B58 || o->id == 0x195C || o->id == 0x175A) {
                func_L01_00404808(func_L01_00424168, o);
            }
        }
    }
    if (D_001D545C == 3) {
        G_004121B8 *g = &D_L03_001E6800;
        O_004121B8 *t;
        if (g->v30 == 0) {
            g->list[2]->b6f = 0;
            g->list[4]->b6f = 0;
            g->list[5]->b6f = 0;
            g->list[3]->b63 = 0;
            if (g->v34 < 0xC0) func_L03_00411BD0(3);
        } else if (g->v30 == 0xB) {
            func_L03_00411C40(g->list[4], 0x96, 0x40400000, 0x40404040);
            func_L03_00411C40(g->list[5], 0xC8, 0x40400000, 0x40404040);
            func_L03_00411E60(g->list[4], 0xD56, 0xD5C);
            func_L03_00411E60(g->list[5], 0xD56, 0xD5C);
        } else if (g->v30 == 0xC) {
            if (g->v34 >= 0) {
                t = g->list[5];
                if (t != 0) {
                    func_L03_00411F50(t, 0);
                    func_L03_00411F50(t, 1);
                }
            }
        } else if (g->v30 == 0xD) {
            if (g->v34 < 0x167) {
                t = g->list[5];
                if (t != 0) {
                    func_L03_00411F50(t, 0);
                    func_L03_00411F50(t, 1);
                }
            }
        } else if (g->v30 == 0x11) {
            func_L03_00411778(0xCAD, 0xD09);
            if (g->v34 >= 0x7D0) {
                t = g->list[7];
                if (t != 0) {
                    func_L03_00411F50(t, 0);
                    func_L03_00411F50(t, 1);
                }
            }
        }
    }
}
/* localdecomp:end func_L03_004121B8 */
