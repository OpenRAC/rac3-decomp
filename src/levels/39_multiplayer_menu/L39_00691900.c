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

/* localdecomp:start func_L39_00691E60 */
typedef struct {
    s32 type;
    char text[0x34];
    f32 x, y, w, h;
} H_00691E60;

typedef struct {
    H_00691E60 h;
    s32 x48;
    s32 x4C;
    void *help;
    s32 x54;
    s32 x58;
    s32 x5C;
    s32 x60;
    s32 x64;
    u8 pad68[8];
} B_00691E60;

typedef struct {
    H_00691E60 h;
    char str[0xC8];
    s32 x110;
    u8 x114;
    u8 x115;
    u8 x116;
    u8 pad117[9];
} T_00691E60;

typedef struct {
    H_00691E60 h;
    u8 pad48[8];
} A_00691E60;


typedef struct {
    H_00691E60 h;
    s32 x48;
    s32 x4C;
    void *items[5];
    u8 pad64[0x1D0 - 0x64];
} D_00691E60;

extern u8 D_L39_0047C968[];
extern char D_00247DD0[];
extern void *func_L39_00688388(void *);
extern void *func_00381FF0(s32);
extern void func_L39_0068CD28(u8 *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_00120D28(char *, char *, s32);
extern void func_L39_00689670(void *, void *);

static __inline__ void lab_00691E60(H_00691E60 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    t->type = 0;
    func_L39_0068CD28((u8 *)t, text, x, y, w, h);
}

static __inline__ void B_init_00691E60(B_00691E60 *t, void *text, void *help, f32 x, f32 y, f32 w, f32 h, s32 n) {
    lab_00691E60(&t->h, text, x, y, w, h);
    t->help = help;
    t->h.type = 5;
    t->x48 = 0;
    t->x4C = 0;
    t->x54 = n;
    t->x58 = 0;
    t->x5C = 0;
    t->x60 = -1;
    t->x64 = 0;
}

static __inline__ void T_init_00691E60(T_00691E60 *t, void *text, f32 x, f32 y, f32 w, f32 h, char *src, s32 n, u8 c0, u8 c1, u8 c2) {
    lab_00691E60(&t->h, text, x, y, w, h);
    t->h.type = 8;
    if (src == 0) {
        t->str[0] = 0;
    } else {
        func_00120D28(t->str, src, 0xC7);
        t->str[0xC7] = 0;
    }
    t->x114 = c0;
    t->x110 = n;
    t->x115 = c1;
    t->x116 = c2;
}

static __inline__ void A_init_00691E60(A_00691E60 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_00691E60(&t->h, text, x, y, w, h);
    t->h.type = 1;
}

static __inline__ void D_init_00691E60(D_00691E60 *t) {
    lab_00691E60(&t->h, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->x48 = 0x2E;
    t->x4C = 0;
    t->h.x = 0;
    t->h.y = 0;
    t->h.w = 1.0f;
    t->h.h = 1.0f;
}

void *func_L39_00691E60(s32 arg) {
    u8 *self = (u8 *)arg;
    B_00691E60 b0;
    B_00691E60 b1;
    B_00691E60 b2;
    T_00691E60 t;
    A_00691E60 a;
    D_00691E60 d;

    func_L39_00688388(self);
    *(u8 **)(self + 0x60) = D_L39_0047C968;
    *(u8 **)(self + 0x2A4) = self + 0x169C;

    B_init_00691E60(&b0, func_00381FF0(0x1001), func_00381FF0(0x1021), 0.155f, 0.2f, 0.76f, 0.2f, 5);
    B_init_00691E60(&b1, func_00381FF0(0x1002), func_00381FF0(0x1022), 0.09f, 0.4f, 0.825f, 0.2f, 5);
    B_init_00691E60(&b2, func_00381FF0(0x1003), func_00381FF0(0x1023), 0.14f, 0.6f, 0.775f, 0.2f, 5);
    T_init_00691E60(&t, func_00381FF0(0xFCA), 0.2f, 0.8f, 0.6f, 1.0f, D_00247DD0, 16, 0, 0, 0);
    A_init_00691E60(&a, func_00381FF0(0xFDA), 0.5f, 0.85f, 1.0f, 1.0f);
    D_init_00691E60(&d);
    d.items[0] = &b0;
    d.items[1] = &b1;
    d.items[2] = &b2;
    d.items[3] = &t;
    d.items[4] = &a;
    d.x4C = 5;
    func_L39_00689670(self, &d);
    return self;
}
/* localdecomp:end func_L39_00691E60 */

LINKER_REMNANT("asm/levels", func_L39_006921B0);
