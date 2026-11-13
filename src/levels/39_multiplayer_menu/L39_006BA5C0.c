#include "common.h"

/* localdecomp:start func_L39_006BA5C0 */
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern char D_L39_002493A8[];
typedef struct { s32 f0; u8 pad[0x24]; } T_006BA5C0;
extern T_006BA5C0 D_001FD630[];
typedef struct { u8 pad[0x60]; void **vt; } O_006BA5C0;
typedef struct {
    u8 pad0[8];
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad1C[0xC];
    s32 f28;
    s32 f2C;
    s32 f30;
    u8 pad34[0x190 - 0x34];
} I_006BA5C0;
s32 func_L39_006D6E50(void *, s32, s32, void *);
u8 *func_L39_006D31B8(void *, s32, s32);
u8 *func_L39_006D6CF8(void *, s32, s32, s32);
u8 *func_L39_006D98C8(void *, s32);
extern s32 func_L39_006D9328(void *, void *);
s32 func_L39_006DF598(f32, f32);
s32 func_00381FF0(s32);
s32 func_00120048(void *, char *, ...);

typedef void (*SetText_006BA5C0)(void *, void *);
typedef void (*Show_006BA5C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x140];
    O_006BA5C0 *objs[15];
    u8 pad17C[0x290 - 0x17C];
    u32 f290;
    u8 pad294[0x2AC - 0x294];
    s32 cur;
    s32 want;
} M_006BA5C0;

void func_L39_006BA5C0(M_006BA5C0 *arg0) {
    I_006BA5C0 info;
    char text[0x100];
    u8 *d = D_L39_0024D760;
    void *list = *(void **)(d + 0x48);
    void *db = *(void **)(d + 0x44);
    u8 *a;
    u8 *b;
    s32 state;
    s32 count;
    s32 i;

    if (arg0->f290 < 12) {
        arg0->want = D_001FD630[arg0->f290 - 1].f0;
    }
    if (arg0->want < 0) {
        O_006BA5C0 **p = arg0->objs;
        s32 n;
        for (n = 10; n >= 0; n--) {
            ((void (*)(void *))(*p)->vt[0xB4 / 4])(*p);
            p++;
        }
        ((Show_006BA5C0)arg0->objs[11]->vt[0x1C / 4])(arg0->objs[11], 0, 0);
        ((Show_006BA5C0)arg0->objs[12]->vt[0x1C / 4])(arg0->objs[12], 0, 0);
        ((Show_006BA5C0)arg0->objs[13]->vt[0x1C / 4])(arg0->objs[13], 0, 0);
        ((Show_006BA5C0)arg0->objs[14]->vt[0x1C / 4])(arg0->objs[14], 0, 0);
        return;
    }
    if (arg0->want == arg0->cur) {
        return;
    }
    arg0->cur = arg0->want;
    if (func_L39_006D6E50(db, arg0->cur, 0, &info)) {
        u8 *e = 0;
        u8 *p;

        if (info.f30 >= 0) {
            e = func_L39_006D31B8(*(void **)(d + 0x38), arg0->cur, info.f30);
        }
        if (e) {
            ((SetText_006BA5C0)arg0->objs[2]->vt[0xB8 / 4])(arg0->objs[2], e + 0x20);
        } else {
            ((SetText_006BA5C0)arg0->objs[2]->vt[0xB8 / 4])(arg0->objs[2], (void *)func_00381FF0(0x1328));
        }
        p = func_L39_006D6CF8(db, arg0->cur, 1, 0);
        if (p) {
            func_00120048(text, D_L39_002493A8, *(s32 *)(p + 0x1C));
        } else {
            text[0] = 0;
        }
        ((SetText_006BA5C0)arg0->objs[3]->vt[0xB8 / 4])(arg0->objs[3], text);
        func_00120048(text, D_L39_002493A8, info.f8);
        ((SetText_006BA5C0)arg0->objs[6]->vt[0xB8 / 4])(arg0->objs[6], text);
        func_00120048(text, D_L39_002493A8, info.fC);
        ((SetText_006BA5C0)arg0->objs[7]->vt[0xB8 / 4])(arg0->objs[7], text);
        func_00120048(text, D_L39_002493A8, info.f14);
        ((SetText_006BA5C0)arg0->objs[8]->vt[0xB8 / 4])(arg0->objs[8], text);
        func_00120048(text, D_L39_002493A8, info.f18);
        ((SetText_006BA5C0)arg0->objs[9]->vt[0xB8 / 4])(arg0->objs[9], text);
        func_00120048(text, D_L39_002493A8, info.f28);
        ((SetText_006BA5C0)arg0->objs[10]->vt[0xB8 / 4])(arg0->objs[10], text);
        func_00120048(text, D_L39_002493A8, info.f2C);
        ((SetText_006BA5C0)arg0->objs[5]->vt[0xB8 / 4])(arg0->objs[5], text);
    }
    state = 0;
    a = func_L39_006D98C8(list, arg0->cur);
    b = (u8 *)func_L39_006D9328(list, (void *)arg0->cur);
    if (a) {
        if (*(s32 *)(a + 0x40) == 0) {
            state = 3;
        } else if (*(s32 *)(a + 0x40) == 1) {
            state = 2;
        }
    } else if (b) {
        state = *(s32 *)(b + 0x40);
    }
    if (b) {
        f32 *f = (f32 *)(b + 0x48);
        count = 1;
        for (i = 3; i >= 0; i--) {
            if (0.0f < f[0]) {
                count = count > func_L39_006DF598(f[0], f[4]) ? count : func_L39_006DF598(f[0], f[4]);
            }
            f++;
        }
        ((Show_006BA5C0)arg0->objs[11]->vt[0x1C / 4])(arg0->objs[11], 0 < count, 0);
        ((Show_006BA5C0)arg0->objs[12]->vt[0x1C / 4])(arg0->objs[12], count >= 2, 0);
        ((Show_006BA5C0)arg0->objs[13]->vt[0x1C / 4])(arg0->objs[13], count >= 3, 0);
        ((Show_006BA5C0)arg0->objs[14]->vt[0x1C / 4])(arg0->objs[14], count >= 4, 0);
    }
    if (**(s32 **)(D_L39_0024D760 + 0x30) == arg0->cur) {
        ((SetText_006BA5C0)arg0->objs[0]->vt[0xB8 / 4])(arg0->objs[0], (void *)func_00381FF0(0xFAE));
        ((SetText_006BA5C0)arg0->objs[1]->vt[0xB8 / 4])(arg0->objs[1], (void *)func_00381FF0(0xFAC));
    } else if (state == 0) {
        ((SetText_006BA5C0)arg0->objs[0]->vt[0xB8 / 4])(arg0->objs[0], (void *)func_00381FF0(0xFAD));
        ((SetText_006BA5C0)arg0->objs[1]->vt[0xB8 / 4])(arg0->objs[1], (void *)func_00381FF0(0xFAD));
    } else if (state == 1) {
        ((SetText_006BA5C0)arg0->objs[0]->vt[0xB8 / 4])(arg0->objs[0], (void *)func_00381FF0(0xFAE));
        ((SetText_006BA5C0)arg0->objs[1]->vt[0xB8 / 4])(arg0->objs[1], (void *)func_00381FF0(0xF76));
    } else if (state == 2) {
        ((SetText_006BA5C0)arg0->objs[0]->vt[0xB8 / 4])(arg0->objs[0], (void *)func_00381FF0(0xFAE));
        ((SetText_006BA5C0)arg0->objs[1]->vt[0xB8 / 4])(arg0->objs[1], (void *)func_00381FF0(0xFAF));
    } else if (state == 3) {
        ((SetText_006BA5C0)arg0->objs[0]->vt[0xB8 / 4])(arg0->objs[0], (void *)func_00381FF0(0xFAE));
        ((SetText_006BA5C0)arg0->objs[1]->vt[0xB8 / 4])(arg0->objs[1], (void *)func_00381FF0(0xFB1));
    }
}
/* localdecomp:end func_L39_006BA5C0 */

LINKER_REMNANT("asm/levels", func_L39_006BAAF8);

INCLUDE_ASM("asm/levels", func_L39_006BAB00);
