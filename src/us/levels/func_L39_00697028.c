#include "common.h"

/* NTSC-U counterpart of func_L39_00699838 (src/levels/39_multiplayer_menu/L39_00699838.c) */
/* localdecomp:start func_L39_00697028 */
/* from func_L39_006ABC38 (same file family: same a/b arrays, typed init helpers) */
typedef struct {
    s32 type;
    char text[0x34];
    f32 x, y, w, h;
} H_00699838;

typedef struct {
    H_00699838 h;
    char str[0xC8];
    s32 x110;
    u8 x114, x115, x116;
    u8 pad117;
} T_00699838;

typedef struct {
    H_00699838 h;
    s32 count;
    s32 *values;
    s32 x50;
    u8 pad54[0x70 - 0x54];
} S_00699838;

typedef struct {
    H_00699838 h;
    s32 x48, x4C, x50, x54, x58, x5C, x60;
    u8 pad64[0x70 - 0x64];
} N_00699838;

typedef struct {
    H_00699838 h;
    u8 b48;
    u8 pad49[3];
    s32 x4C;
} A_00699838;

typedef struct {
    H_00699838 h;
    s32 x48;
    s32 x4C;
    void *items[0x60];
} D_00699838;

extern u8 D_L39_0047D098[];
extern char D_L39_00248290[];
extern char D_001DCA08_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DCA08_sda, 8");
extern void *func_L39_006857E0(void *);
extern void *func_L39_006C9630(void *);
extern s32 func_0037DF98(s32);
extern void func_0019AFA0(void);
extern void func_00120D28(char *, char *, s32);
extern void func_L39_0068A638(u8 *, void *, f32, f32, f32, f32);
extern void func_L39_00686AC8(void *, void *);

static __inline__ void lab_00699838(H_00699838 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    t->type = 0;
    func_L39_0068A638((u8 *)t, text, x, y, w, h);
}

static __inline__ void T_init_00699838(T_00699838 *t, void *text, f32 x, f32 y, f32 w, f32 h, char *src, s32 n, u8 c0, u8 c1, u8 c2) {
    lab_00699838(&t->h, text, x, y, w, h);
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

static __inline__ void S_init_00699838(S_00699838 *t, void *text, f32 x, f32 y, f32 w, f32 h, s32 count, s32 *values) {
    lab_00699838(&t->h, text, x, y, w, h);
    t->h.type = 3;
    t->count = count;
    t->values = values;
    t->x50 = 0;
}

static __inline__ void N_init_00699838(N_00699838 *t, void *text, f32 x, f32 y, f32 w, f32 h, s32 v48, s32 v4C, s32 a, s32 b, s32 c, s32 d, s32 e) {
    lab_00699838(&t->h, text, x, y, w, h);
    t->h.type = 6;
    t->x48 = v48;
    t->x4C = v4C;
    t->x50 = a;
    t->x54 = b;
    t->x58 = c;
    t->x60 = e;
    t->x5C = d;
}

static __inline__ void C_init_00699838(A_00699838 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_00699838(&t->h, text, x, y, w, h);
    t->h.type = 2;
}

static __inline__ void A_init_00699838(A_00699838 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_00699838(&t->h, text, x, y, w, h);
    t->h.type = 1;
}

static __inline__ void B_init_00699838(A_00699838 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_00699838(&t->h, text, x, y, w, h);
    t->h.type = 4;
    t->b48 = 0;
}

static __inline__ void D_init_00699838(D_00699838 *t) {
    lab_00699838(&t->h, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->x48 = 0x2E;
    t->x4C = 0;
    t->h.x = 0;
    t->h.y = 0;
    t->h.w = 1.0f;
    t->h.h = 1.0f;
}

void *func_L39_00697028(u8 *self) {
    ((void (*)(void *))func_L39_006857E0)(self);
    *(void **)(self + 0x60) = D_L39_0047D098;
    func_L39_006C9630(self + 0x384);
    *(void **)(self + 0x2A4) = self + 0x62C;
    {
        s32 a[10] = { func_0037DF98(0xBB1), func_0037DF98(0xBB2), func_0037DF98(0xDA), func_0037DF98(0xBB4), func_0037DF98(0xD8), func_0037DF98(0xD4), func_0037DF98(0x18C4), func_0037DF98(0x18C5), func_0037DF98(0x18C6), func_0037DF98(0x18C7) };
        s32 b[3] = { func_0037DF98(0x1024), func_0037DF98(0x10E2), func_0037DF98(0x1026) };
        T_00699838 i0;
        S_00699838 i1, i2;
        N_00699838 i3, i4, i5, i6, i7;
        A_00699838 i8, i9, i10, i11, i12, i13;
        D_00699838 d;
        s32 i;
        s32 rows12 = 8;
        s32 rows13 = 0x12;
        u8 *p;

        func_0019AFA0();
        *(s32 *)(self + 0x2A8) = 0;
        *(s32 *)(self + 0x2EC) = -1;
        *(s32 *)(self + 0x2F0) = -1;
        *(s32 *)(self + 0x2F4) = -1;
        *(u8 *)(self + 0x2E8) = 1;
        *(s32 *)(self + 0x2E0) = 20;
        *(s32 *)(self + 0x2E4) = 3;
        *(s32 *)(self + 0x2AC) = 0;
        *(s32 *)(self + 0x2B0) = 0;
        *(s32 *)(self + 0x2DC) = 0;
        *(s32 *)(self + 0x2B4) = 0;
        *(s32 *)(self + 0x2B8) = 1;
        *(s32 *)(self + 0x2BC) = 1;
        *(s32 *)(self + 0x2C0) = 0;
        *(s32 *)(self + 0x2C4) = 1;
        *(s32 *)(self + 0x2C8) = 0;
        *(s32 *)(self + 0x2CC) = 0;
        *(s32 *)(self + 0x2D0) = 0;
        i = 7;
        p = self + 0x2DB;
        for (; i >= 0; i--) {
            *p-- = 1;
        }
        T_init_00699838(&i0, (void *)func_0037DF98(0xFE6), 0.10800001f, 0.17267853f, 0.37f, 0.05f, D_L39_00248290, 16, 0, 1, 0);
        S_init_00699838(&i1, (void *)func_0037DF98(0xFE9), 0.10800001f, 0.2230357f, 0.37f, 0.05f, 10, a);
        S_init_00699838(&i2, (void *)func_0037DF98(0xFBB), 0.10800001f, 0.27339286f, 0.37f, 0.05f, 3, b);
        N_init_00699838(&i3, (void *)func_0037DF98(0x1005), 0.10800001f, 0.32375f, 0.37f, 0.05f, 8, 2, 8, 1, -1, -1, -1);
        N_init_00699838(&i4, (void *)func_0037DF98(0x1176), 0.10800001f, 0.37410712f, 0.37f, 0.05f, 0, 0, 7, 1, -1, -1, -1);
        N_init_00699838(&i5, (void *)func_0037DF98(0x1177), 0.10800001f, 0.4244643f, 0.37f, 0.05f, 0, 0, 7, 1, -1, -1, -1);
        N_init_00699838(&i6, (void *)func_0037DF98(0xFE7), 0.10800001f, 0.47482142f, 0.37f, 0.05f, 1, 1, 2, 1, -1, -1, -1);
        N_init_00699838(&i7, (void *)func_0037DF98(0x10E7), 0.10800001f, 0.52517855f, 0.37f, 0.05f, 0, 0, 0x23, 5, 0x102C, 0x116B, 0x116B);
        C_init_00699838(&i8, (void *)func_0037DF98(0x132A), 0.10800001f, 0.5755357f, 0.37f, 0.05f);
        A_init_00699838(&i9, D_L39_00248290, 0.293f, 0.6258929f, 0.37f, 0.05f);
        A_init_00699838(&i10, (void *)func_0037DF98(0x116D), 0.293f, 0.67625f, 0.37f, 0.05f);
        A_init_00699838(&i11, (void *)func_0037DF98(0x10E3), 0.293f, 0.72660714f, 0.37f, 0.05f);
        B_init_00699838(&i12, D_001DCA08_sda, 0.708f, 0.266f, 0.385f, 0.235f);
        i12.x4C = rows12;
        B_init_00699838(&i13, D_001DCA08_sda, 0.708f, 0.631f, 0.385f, 0.44099998f);
        i13.x4C = rows13;
        D_init_00699838(&d);
        d.x4C = 0xE;
        d.items[0] = &i0;
        d.items[1] = &i1;
        d.items[2] = &i2;
        d.items[3] = &i3;
        d.items[4] = &i4;
        d.items[5] = &i5;
        d.items[6] = &i6;
        d.items[7] = &i7;
        d.items[8] = &i8;
        d.items[9] = &i9;
        d.items[10] = &i10;
        d.items[11] = &i11;
        d.items[12] = &i12;
        d.items[13] = &i13;
        func_L39_00686AC8(self, &d);
    }
    return self;
}
/* localdecomp:end func_L39_00697028 */
