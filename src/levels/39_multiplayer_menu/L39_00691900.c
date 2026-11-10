#include "common.h"

/* localdecomp:start func_L39_00691900 */
typedef struct VT_00691900 {
    u8 pad0[0x1C];
    void (*setVisible)(void *, s32, s32);
    u8 pad20[0x24];
    void (*setScale)(void *, s32, f32, f32);
    u8 pad48[0x44];
    s32 (*getSel)(void *);
    u8 pad90[0x28];
    void (*setText)(void *, void *);
} VT_00691900;

typedef struct Obj_00691900 {
    u8 pad[0x60];
    VT_00691900 *vt;
} Obj_00691900;

typedef struct Info_00691900 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    u8 pad[0x190 - 0x34];
} Info_00691900;

typedef struct Stats_00691900 {
    f32 a[4];
    f32 b[4];
    u8 rest[0x14];
} Stats_00691900;


extern u8 *D_L39_0024D760;
extern char D_L39_00247D70[];
extern s32 func_L39_006D6E50(void *, s32, s32, void *);
extern u8 *func_L39_006D31B8(void *, s32, s32);
extern void *func_00381FF0(s32);
extern u8 *func_L39_006D6CF8(void *, s32, s32, s32);
extern void func_00120048(char *, char *, ...);
extern u8 *func_L39_006D98C8(void *, s32);
extern u8 *func_L39_006D9328(void *, s32);
extern s32 func_L39_006DF598(f32, f32);

typedef struct Self_00691900 {
    u8 pad[0x2B4];
    s32 ids[1];
} Self_00691900;

void func_L39_00691900(u8 *self) {
    Info_00691900 info;
    char buf[0x100];
    Stats_00691900 st;
    Obj_00691900 *o;
    u8 *mgr;
    void *list;
    void *list2;
    u8 *p;
    u8 *a;
    u8 *b;
    s32 idx;
    s32 id;
    s32 mode;
    s32 count;
    s32 i;
    f32 *pa;
    f32 *pb;

    if (*(s32 *)(self + 0x2B0) == 0) {
        return;
    }

    idx = (*(Obj_00691900 **)(self + 0x110))->vt->getSel(*(Obj_00691900 **)(self + 0x110));
    if (idx == -1) {
        return;
    }
    id = ((Self_00691900 *)self)->ids[idx];
    *(s32 *)(self + 0x27C0) = id;
    if (id == *(s32 *)(self + 0x27C4)) {
        return;
    }
    mgr = D_L39_0024D760;
    list = *(void **)(mgr + 0x44);
    *(s32 *)(self + 0x27C4) = id;
    if (!func_L39_006D6E50(list, id, 0, &info)) {
        return;
    }
    p = 0;
    if (info.f30 >= 0) {
        p = func_L39_006D31B8(*(void **)(mgr + 0x38), *(s32 *)(self + 0x27C0), info.f30);
    }
    if (p) {
                (*(Obj_00691900 **)(self + 0x12C))->vt->setText(*(Obj_00691900 **)(self + 0x12C), p + 0x20);
    } else {
                (*(Obj_00691900 **)(self + 0x12C))->vt->setText(*(Obj_00691900 **)(self + 0x12C), func_00381FF0(0x12C6));
    }
        (*(Obj_00691900 **)(self + 0x12C))->vt->setScale(*(Obj_00691900 **)(self + 0x12C), 1, 1.0f, 0.0f);

    p = func_L39_006D6CF8(list, *(s32 *)(self + 0x27C0), 1, 0);
    if (p) {
        func_00120048(buf, D_L39_00247D70, *(s32 *)(p + 0x1C));
    } else {
        buf[0] = 0;
    }
    mode = 0;
        (*(Obj_00691900 **)(self + 0x130))->vt->setText(*(Obj_00691900 **)(self + 0x130), buf);
    func_00120048(buf, D_L39_00247D70, info.f8);
        (*(Obj_00691900 **)(self + 0x13C))->vt->setText(*(Obj_00691900 **)(self + 0x13C), buf);
    func_00120048(buf, D_L39_00247D70, info.fC);
        (*(Obj_00691900 **)(self + 0x140))->vt->setText(*(Obj_00691900 **)(self + 0x140), buf);
    func_00120048(buf, D_L39_00247D70, info.f14);
        (*(Obj_00691900 **)(self + 0x144))->vt->setText(*(Obj_00691900 **)(self + 0x144), buf);
    func_00120048(buf, D_L39_00247D70, info.f18);
        (*(Obj_00691900 **)(self + 0x148))->vt->setText(*(Obj_00691900 **)(self + 0x148), buf);
    func_00120048(buf, D_L39_00247D70, info.f28);
        (*(Obj_00691900 **)(self + 0x14C))->vt->setText(*(Obj_00691900 **)(self + 0x14C), buf);
    func_00120048(buf, D_L39_00247D70, info.f2C);
        (*(Obj_00691900 **)(self + 0x138))->vt->setText(*(Obj_00691900 **)(self + 0x138), buf);

    list2 = *(void **)(mgr + 0x48);
    a = func_L39_006D98C8(list2, *(s32 *)(self + 0x27C0));
    b = func_L39_006D9328(list2, *(s32 *)(self + 0x27C0));
    if (a) {
        if (*(s32 *)(a + 0x40) == 0) {
            mode = 3;
        } else if (*(s32 *)(a + 0x40) == 1) {
            mode = 2;
        } else {
            mode = 0;
        }
    } else if (b) {
        mode = *(s32 *)(b + 0x40);
    }
    if (b) {
        st = *(Stats_00691900 *)(b + 0x48);
        count = 1;
        pb = st.b;
        pa = st.a;
        for (i = 3; i >= 0; i--) {
            if (0.0f < *pa) {
                count = (func_L39_006DF598(*pa, *pb) < count) ? count : func_L39_006DF598(*pa, *pb);
            }
            pb++;
            pa++;
        }
        (*(Obj_00691900 **)(self + 0x150))->vt->setVisible(*(Obj_00691900 **)(self + 0x150), count > 0, 0);
                (*(Obj_00691900 **)(self + 0x154))->vt->setVisible(*(Obj_00691900 **)(self + 0x154), count >= 2, 0);
                (*(Obj_00691900 **)(self + 0x158))->vt->setVisible(*(Obj_00691900 **)(self + 0x158), count >= 3, 0);
                (*(Obj_00691900 **)(self + 0x15C))->vt->setVisible(*(Obj_00691900 **)(self + 0x15C), count >= 4, 0);
    }

    if (**(s32 **)(D_L39_0024D760 + 0x30) == *(s32 *)(self + 0x27C0)) {
                (*(Obj_00691900 **)(self + 0x124))->vt->setText(*(Obj_00691900 **)(self + 0x124), func_00381FF0(0xFAE));
                (*(Obj_00691900 **)(self + 0x128))->vt->setText(*(Obj_00691900 **)(self + 0x128), func_00381FF0(0xFAC));
    } else if (mode == 0) {
                (*(Obj_00691900 **)(self + 0x124))->vt->setText(*(Obj_00691900 **)(self + 0x124), func_00381FF0(0xFAD));
                (*(Obj_00691900 **)(self + 0x128))->vt->setText(*(Obj_00691900 **)(self + 0x128), func_00381FF0(0xFAD));
    } else if (mode == 1) {
                (*(Obj_00691900 **)(self + 0x124))->vt->setText(*(Obj_00691900 **)(self + 0x124), func_00381FF0(0xFAE));
                (*(Obj_00691900 **)(self + 0x128))->vt->setText(*(Obj_00691900 **)(self + 0x128), func_00381FF0(0xF76));
    } else if (mode == 2) {
                (*(Obj_00691900 **)(self + 0x124))->vt->setText(*(Obj_00691900 **)(self + 0x124), func_00381FF0(0xFAE));
                (*(Obj_00691900 **)(self + 0x128))->vt->setText(*(Obj_00691900 **)(self + 0x128), func_00381FF0(0xFAF));
    } else if (mode == 3) {
                (*(Obj_00691900 **)(self + 0x124))->vt->setText(*(Obj_00691900 **)(self + 0x124), func_00381FF0(0xFAE));
                (*(Obj_00691900 **)(self + 0x128))->vt->setText(*(Obj_00691900 **)(self + 0x128), func_00381FF0(0xFB1));
    }
}
/* localdecomp:end func_L39_00691900 */

LINKER_REMNANT("asm/levels", func_L39_00691E48);

INCLUDE_ASM("asm/levels", func_L39_00691E60);

LINKER_REMNANT("asm/levels", func_L39_006921B0);
