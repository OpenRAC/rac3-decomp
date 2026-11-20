#include "common.h"

/* declared by functions of L39_006BA5C0.c, which this file was cut from */
void func_L39_006CC158(void *, s32);

/* declared by functions of L39_006BBB38.c, which this file was cut from */
extern u8 *D_L39_0024D760;
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);
void func_L39_0068B2F8(void *, s32, s32);

/* localdecomp:start func_L39_006BBD80 */
/* the widgets' virtual methods, by the offset of their slot in the vtable */
typedef void (*VI_006BBD80)(void *, s32);
typedef void (*VII_006BBD80)(void *, s32, s32);
typedef void (*VS_006BBD80)(void *, char *);
typedef void (*VFF_006BBD80)(void *, f32, f32);
typedef void (*VPP_006BBD80)(void *, f32 *, f32 *);
typedef s32 (*GET_006BBD80)(void *);
typedef void (*VF_006BBD80)(void *, f32);

typedef struct O_006BBD80 {
    u8 pad0[0x60];
    u8 *vt;
} O_006BBD80;

typedef struct S_006BBD80 {
    u8 pad0[0x110];
    O_006BBD80 *objs[12];
    u8 pad140[0x150];
    s32 state;          /* 0x290 */
    u8 pad294[0x14];
    s32 f2A8;
    char name[0x44];    /* 0x2AC */
    s32 mode;           /* 0x2F0 */
    s32 f2F4;
    s32 f2F8;
    s32 f2FC;
    s32 f300;
    s32 f304;
    s32 f308;
    s32 f30C;
    u8 pad310[0x4];
    u8 f314;
    u8 pad315[0xB];
    s32 count;          /* 0x320 */
    s32 ids[1];         /* 0x324, count entries */
    u8 pad328[0x7EDC];
    u8 f8204;
    u8 pad8205[0x7];
    s32 f820C;
    u8 *f8210[1];       /* 0x8210, one per list row */
    u8 pad8214[0x550];
    s32 f8764;
} S_006BBD80;

__asm__(".extern D_L39_00249414, 4");
__asm__(".extern D_L39_00249418, 4");
__asm__(".extern D_L39_00249424, 4");
__asm__(".extern D_L39_0024942C, 4");
__asm__(".extern D_L39_00249430, 4");
__asm__(".extern D_L39_00249448, 4");
__asm__(".extern D_L39_0024944C, 4");
__asm__(".extern D_L39_00249450, 4");
extern f32 D_L39_00249414;
extern f32 D_L39_00249418;
extern f32 D_L39_00249424;
extern f32 D_L39_0024942C;
extern f32 D_L39_00249430;
extern f32 D_L39_00249448;
extern f32 D_L39_0024944C;
extern f32 D_L39_00249450;
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern s32 *D_L39_00247914;
extern s32 D_L39_0024D158;
extern u32 D_L39_0024D15C[] __attribute__((section(".sdata")));
extern u8 D_001A5CD0[];
extern char D_L39_00249468[];
extern char D_L39_002494C8[];
extern char D_L39_002494D0[];
extern char D_L39_002494D8[];

extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_00195410(void);
extern s32 func_00120048(char *, char *, ...);
extern void *func_0011D534(void *, s32, s32);
extern s32 func_001205B0(char *, char *);
long func_L39_006BBBE0(void *);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);
void func_L39_0068B2F8(void *, s32, s32);
s32 func_L39_006BBC08(void *);
void func_L39_006BDCF0(void *);
void func_L39_006BDE00(void *);
void func_L39_006BE260(void *);
s32 func_L39_006DC3D0(void *, s32 *);
s32 func_L39_006DBD58(void *, s32, void *, void *);
void func_L39_006BD988(u8 *);
void func_L39_00689BD8(void *, char *);
s32 func_L39_006DB948(void *, s32, s32, s32, s32);
void func_L39_006BD408(void *, s32);
void func_L39_006BD788(void *);
s32 func_L39_00688340(s32, s32, s32);
s32 func_L39_0068AEF8(void *, s32);
void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
void func_L39_006B5288(void *, s32, s32);
u8 *func_L39_006DE380(void *, s32, s32);
void func_L39_0069B960(void *, s32, s32, s32, s32);
void func_L39_006A2138(void *, s32, s32);
s32 func_L39_006877B0(void *, s32);
s32 func_L39_00687450(void *, char *, char *, s32, s32, s32, s32);
s32 func_L39_006DA090(void *, char *);
void func_L39_0067F3B8(s32, char *);
s32 func_L39_006BDAB8(u8 *, s32, s32, s32);
s32 func_L39_006BDCC8(void);

s32 func_L39_006BBD80(u8 *arg0, s32 input) {
    S_006BBD80 *self = (S_006BBD80 *)arg0;
    char text[0x20];
    char entry[0x40];
    char msg[0x70];
    s32 err0;
    s32 slot;
    s32 err1;
    s32 slot2;
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    s32 st;

    (*(VFF_006BBD80 *)(self->objs[11]->vt + 0x28))(self->objs[11], 0.885f, 0.173f);
    if (!func_L39_006BBBE0(self)) {
        *(s32 *)((u8 *)D_L39_00247914 + 0x284) = 0x19;
        return 0;
    }
    if (!func_L39_006BBC08(self)) {
        return 1;
    }
    func_L39_006BDCF0(self);
    func_L39_006BDE00(self);
    func_L39_006BE260(self);

    if (self->mode != 0) {
        if (self->mode != 1) {
            (*(VII_006BBD80 *)(self->objs[5]->vt + 0x20))(self->objs[5], 0, 0);
            func_00120048(text, D_L39_002494C8, *(u8 **)(D_L39_0024D760 + 0x38) + 4);
        } else {
            u8 *net = *(u8 **)(D_L39_0024D760 + 0x4C);
            (*(VII_006BBD80 *)(self->objs[5]->vt + 0x20))(self->objs[5], 3, 0);
            self->f2F8 = func_L39_006DBD58(net, self->f2A8, &self->f2FC, &self->f300);
            func_00120048(text, D_L39_002494D0, self->name, self->f2F8 + 1);
            func_L39_006BD988(arg0);
        }
        (*(VS_006BBD80 *)(self->objs[0]->vt + 0x24))(self->objs[0], text);
        (*(VI_006BBD80 *)(self->objs[0]->vt + 0x40))(self->objs[0], 2);
        func_L39_00689BD8(self, self->name);
    } else {
        if (func_L39_006DC3D0(*(u8 **)(D_L39_0024D760 + 0x4C), &err0)) {
            *(s32 *)((u8 *)D_L39_00247914 + 0x284) = 0x19;
        }
        return 1;
    }

    if (self->state == 0 && self->mode == 1 && self->f314 == 0 && self->f8204 == 0) {
        slot = -1;
        (*(VII_006BBD80 *)(self->objs[1]->vt + 0x1C))(self->objs[1], self->f2FC != 0, 0);
        (*(VII_006BBD80 *)(self->objs[2]->vt + 0x1C))(self->objs[2], self->f300 != 0, 0);
        if (self->f2FC != 0 && input == 0xB) {
            u8 *a = *(u8 **)(D_L39_0024D760 + 0x4C);
            u8 *b = *(u8 **)(D_L39_0024D760 + 0x70);
            s32 ok = 1;
            s32 start;

            a[0x168] = 0;
            b[0x10] = 0;
            start = func_00130760(func_0012DCB0(), 0x24000);
            while (a[0x199] && b[0x1C] && a[0x15D]) {
                func_00195410();
                if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start >= 15001) {
                    ok = 0;
                    goto end1;
                }
            }
            end1:;
            if (ok) {
                if (func_L39_006DB948(a, self->f2F4, (s32)&slot, self->f2F8, 0)) {
                    ((void (*)(void *, s32))func_L39_006BD408)(self, slot);
                    func_L39_006BD788(self);
                    *(s32 *)(D_001A5CD0 + 0x78) = slot;
                }
            }
            {
                s32 lim = 10000;
                u8 on = 1;
                a[0x168] = on;
                *(s32 *)(a + 0x16C) = lim;
                b[0x10] = on;
                *(s32 *)(b + 0x14) = lim;
            }
            return 1;
        }
        if (self->f300 != 0 && input == 0xC) {
            u8 *a = *(u8 **)(D_L39_0024D760 + 0x4C);
            u8 *b = *(u8 **)(D_L39_0024D760 + 0x70);
            s32 ok = 1;
            s32 start;

            a[0x168] = 0;
            b[0x10] = 0;
            start = func_00130760(func_0012DCB0(), 0x24000);
            while (a[0x199] && b[0x1C] && a[0x15D]) {
                func_00195410();
                if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start >= 15001) {
                    ok = 0;
                    goto end2;
                }
            }
            end2:;
            if (ok) {
                if (func_L39_006DB948(a, self->f2F4, (s32)&slot, self->f2F8, 1)) {
                    ((void (*)(void *, s32))func_L39_006BD408)(self, slot);
                    func_L39_006BD788(self);
                    *(s32 *)(D_001A5CD0 + 0x78) = slot;
                }
            }
            {
                s32 lim = 10000;
                u8 on = 1;
                a[0x168] = on;
                *(s32 *)(a + 0x16C) = lim;
                b[0x10] = on;
                *(s32 *)(b + 0x14) = lim;
            }
            return 1;
        }
    } else {
        (*(VII_006BBD80 *)(self->objs[1]->vt + 0x20))(self->objs[1], 0, 0);
        (*(VII_006BBD80 *)(self->objs[2]->vt + 0x20))(self->objs[2], 0, 0);
    }

    if (input == 3 || input == 4) {
        st = self->state;
        if (st == 7) {
            if (self->mode != 2 && self->mode != 3) {
                func_L39_0068B2F8(self, 0, 0);
            } else {
                func_L39_0068B2F8(self, self->f8764, 0);
            }
        } else if (st == 9) {
            func_L39_0068B2F8(self, self->f8764, 0);
        } else if (st == 0) {
            func_L39_0068B2F8(self, 7, 0);
        } else if (st >= 4 && st <= 6) {
            self->f8764 = st;
            func_L39_0068B2F8(self, 9, 0);
        }
        func_L39_00688340(3, 0, 0);
        return 1;
    }

    if (self->state == 8) {
        if (input == 1 && (*(GET_006BBD80 *)(self->objs[8]->vt + 0x8C))(self->objs[8]) == 0) {
            return 1;
        }
        if (input == 2) {
            s32 sel = (*(GET_006BBD80 *)(self->objs[self->state]->vt + 0x8C))(self->objs[self->state]);
            if (sel == (*(GET_006BBD80 *)(self->objs[self->state]->vt + 0x78))(self->objs[self->state]) - 1) {
                return 1;
            }
        }
    }
    if (self->state == 10) {
        if (input == 1 && (*(GET_006BBD80 *)(self->objs[10]->vt + 0x8C))(self->objs[10]) == 0) {
            return 1;
        }
        if (input == 2) {
            s32 sel = (*(GET_006BBD80 *)(self->objs[self->state]->vt + 0x8C))(self->objs[self->state]);
            if (sel == (*(GET_006BBD80 *)(self->objs[self->state]->vt + 0x78))(self->objs[self->state]) - 1) {
                return 1;
            }
        }
    }

    if (input == 0xF) {
        s32 sel = (*(GET_006BBD80 *)(self->objs[3]->vt + 0x8C))(self->objs[3]);
        s32 cnt = (*(GET_006BBD80 *)(self->objs[3]->vt + 0x78))(self->objs[3]);
        s32 page = (*(GET_006BBD80 *)(self->objs[3]->vt + 0x74))(self->objs[3]);
        s32 last = cnt - 1;
        s32 t = (sel / page + 2) * page - 1;
        (*(VI_006BBD80 *)(self->objs[3]->vt + 0x88))(self->objs[3], last < t ? last : t);
        return 1;
    }
    if (input == 0xE) {
        s32 sel = (*(GET_006BBD80 *)(self->objs[3]->vt + 0x8C))(self->objs[3]);
        s32 page = (*(GET_006BBD80 *)(self->objs[3]->vt + 0x74))(self->objs[3]);
        s32 q = sel / page;
        if (q == 0) {
            return 1;
        }
        (*(VI_006BBD80 *)(self->objs[3]->vt + 0x88))(self->objs[3], (q - 1) * page);
        return 1;
    }
    if (input == 5) {
        st = self->state;
        if (st == 10) {
            func_L39_00688340(0x17, 0, 0);
            (*(VI_006BBD80 *)(self->objs[10]->vt + 0x80))(self->objs[10], 0);
            (*(VII_006BBD80 *)(self->objs[10]->vt + 0x20))(self->objs[10], 2, 0);
            func_L39_0068B2F8(self, 9, 0);
            return 1;
        }
        if (st == 8) {
            func_L39_00688340(0x17, 0, 0);
            (*(VI_006BBD80 *)(self->objs[8]->vt + 0x80))(self->objs[8], 0);
            (*(VII_006BBD80 *)(self->objs[8]->vt + 0x20))(self->objs[8], 2, 0);
            func_L39_0068B2F8(self, 7, 0);
            return 1;
        }
        if (self->mode == 2 || self->mode == 3) {
            if (*(u8 *)(*(u8 **)(D_L39_0024D760 + 0x38) + 0x34)) {
                *(s32 *)((u8 *)D_L39_00247914 + 0x284) = 9;
            } else {
                *(s32 *)((u8 *)D_L39_00247914 + 0x284) = 6;
            }
        } else {
            func_L39_00688340(0x17, 0, 0);
            if (func_L39_006DC3D0(*(u8 **)(D_L39_0024D760 + 0x4C), &err1)) {
                *(s32 *)((u8 *)D_L39_00247914 + 0x284) = 0x19;
            }
            return 1;
        }
    }
    if (input == 7) {
        st = self->state;
        if (st == 9 && self->count > 0) {
            func_L39_00688340(4, 0, 0);
            (*(VI_006BBD80 *)(self->objs[10]->vt + 0x80))(self->objs[10], 1);
            (*(VII_006BBD80 *)(self->objs[10]->vt + 0x20))(self->objs[10], 3, 0);
            func_L39_0068B2F8(self, 10, 0);
            (*(VI_006BBD80 *)(self->objs[10]->vt + 0x84))(self->objs[10], 1);
            (*(VI_006BBD80 *)(self->objs[10]->vt + 0x88))(self->objs[10], 0);
            return 1;
        }
        if (st == 7 && self->f820C > 0) {
            func_L39_00688340(4, 0, 0);
            (*(VI_006BBD80 *)(self->objs[8]->vt + 0x80))(self->objs[8], 1);
            (*(VII_006BBD80 *)(self->objs[8]->vt + 0x20))(self->objs[8], 3, 0);
            (*(VI_006BBD80 *)(self->objs[10]->vt + 0x84))(self->objs[10], 1);
            func_L39_0068B2F8(self, 8, 0);
            (*(VI_006BBD80 *)(self->objs[8]->vt + 0x88))(self->objs[8], 0);
            return 1;
        }
    }
    if (input == 1) {
        st = self->state;
        if (st == 7) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8(self, 9, 0);
            return 1;
        }
        if (st == 0) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8(self, 6, 0);
            return 1;
        }
        if (st == 4) {
            func_L39_00688340(3, 0, 0);
            if (self->mode != 2 && self->mode != 3) {
                func_L39_0068B2F8(self, 0, 0);
            } else {
                func_L39_0068B2F8(self, 6, 0);
            }
            return 1;
        }
        if (st == 9) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8(self, 7, 0);
            return 1;
        }
        if (st == 5) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8(self, 4, 0);
            return 1;
        }
        if (st == 6) {
            func_L39_00688340(3, 0, 0);
            if (self->mode != 1) {
                func_L39_0068B2F8(self, 4, 0);
            } else {
                func_L39_0068B2F8(self, 5, 0);
            }
            return 1;
        }
    }
    if (input == 2) {
        st = self->state;
        if (st == 7) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8(self, 9, 0);
            return 1;
        }
        if (st == 9) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8(self, 7, 0);
            return 1;
        }
        if (st == 6) {
            func_L39_00688340(3, 0, 0);
            if (self->mode != 2 && self->mode != 3) {
                func_L39_0068B2F8(self, 0, 0);
            } else {
                func_L39_0068B2F8(self, 4, 0);
            }
            return 1;
        }
        if (st == 0) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8(self, 4, 0);
            return 1;
        }
        if (st == 4) {
            func_L39_00688340(3, 0, 0);
            if (self->mode != 1) {
                func_L39_0068B2F8(self, 6, 0);
            } else {
                func_L39_0068B2F8(self, 5, 0);
            }
            return 1;
        }
        if (st == 5) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8(self, 6, 0);
            return 1;
        }
    }

    if (D_L39_0024D158 != 0) {
        s32 ok = 1;
        s32 i;

        for (i = 0; ok && i < D_L39_0024D158; i++) {
            switch (D_L39_0024D15C[i]) {
            case '/':
            case '\\':
            case '`':
            case '~':
                ok = 0;
                break;
            }
        }
        if (ok) {
            input = 7;
            self->state = 4;
        }
    }

    if (input == 7) {
        st = self->state;
        if (st == 3) {
            (*(VI_006BBD80 *)(self->objs[3]->vt + 0x14))(self->objs[3], 7);
        } else if (st == 10) {
            s32 sel;
            func_L39_00688340(4, 0, 0);
            sel = (*(GET_006BBD80 *)(self->objs[10]->vt + 0x8C))(self->objs[10]);
            if (sel >= 0 && sel < self->count && self->ids[sel] != -1) {
                func_L39_006B5288(*(void **)((u8 *)D_L39_00247914 + 0xD0), self->ids[sel], 1);
                *(s32 *)((u8 *)D_L39_00247914 + 0x284) = 0x1B;
            }
            return 1;
        } else if (st == 8) {
            s32 sel;
            func_L39_00688340(4, 0, 0);
            sel = (*(GET_006BBD80 *)(self->objs[8]->vt + 0x8C))(self->objs[8]);
            if (sel >= 0) {
                if (self->f8210[sel] != 0) {
                    s32 id = *(s32 *)(self->f8210[sel] + 0x1C);
                    if (id >= 0) {
                        s32 who = **(s32 **)(D_L39_0024D760 + 0x4C);
                        s32 extra = 0;
                        u8 *r = func_L39_006DE380(*(void **)(D_L39_0024D760 + 0x54), 0, id);
                        u8 *g;
                        u8 *dst;
                        s32 v;
                        if (r != 0) {
                            extra = *(s32 *)(r + 0x24);
                        }
                        v = *(s32 *)(self->f8210[sel] + 0x48);
                        g = (u8 *)D_L39_00247914;
                        dst = *(u8 **)(g + 0xA4);
                        *(s32 *)(dst + 0x2A8) = id;
                        *(s32 *)(dst + 0x2AC) = extra;
                        *(s32 *)(dst + 0x2B0) = who;
                        *(s32 *)(dst + 0x2B4) = v;
                        *(s32 *)(g + 0x284) = 0x10;
                    }
                }
            }
            return 1;
        } else if (st == 6) {
            void *menu;
            func_L39_00688340(4, 0, 0);
            menu = *(void **)((u8 *)D_L39_00247914 + 0x94);
            if (self->mode == 1) {
                func_L39_0069B960(menu, 1, -1, -1, -1);
            } else if (self->mode == 2) {
                func_L39_0069B960(menu, 2, -1, -1, -1);
            } else if (self->mode == 3) {
                func_L39_0069B960(menu, 3, self->f304, self->f308, self->f30C);
            }
            *(s32 *)((u8 *)D_L39_00247914 + 0x284) = 0xC;
            return 1;
        } else if (st == 5) {
            void *menu;
            func_L39_00688340(4, 0, 0);
            menu = *(void **)((u8 *)D_L39_00247914 + 0xA0);
            if (self->mode == 1) {
                func_L39_006A2138(menu, 1, self->f2F4);
            } else if (self->mode == 2 || self->mode == 3) {
                func_L39_006A2138(menu, 2, **(s32 **)(D_L39_0024D760 + 0x38));
            }
            *(s32 *)((u8 *)D_L39_00247914 + 0x284) = 0xF;
            return 1;
        } else if (st == 0) {
            s32 mode;
            func_L39_00688340(4, 0, 0);
            mode = self->mode;
            if (mode == 1) {
                s32 room = func_L39_006877B0(D_L39_00247914, 1);
                if (room >= 0x28 && room < 0x64) {
                    u8 *g = D_001A5CD0;
                    if (room != *(s32 *)(g + 0x7C)) {
                        s32 ok;
                        slot2 = -1;
                        ok = func_L39_006BDAB8(arg0, (s32)D_L39_00249468, (s32)&slot2, room);
                        if (ok == 1 && ((s32 (*)(void *, s32))func_L39_006BDCC8)(self, slot2) == 1) {
                            *(s32 *)(g + 0x7C) = room;
                            ((void (*)(void *, s32))func_L39_006BD408)(self, slot2);
                            func_L39_006BD788(self);
                        }
                    }
                }
            }
            return 1;
        } else if (st == 4) {
            u8 *g;
            s32 ok;
            func_L39_00688340(4, 0, 0);
            g = D_001A5CD0;
            ok = 1;
            if ((f32)*(s32 *)(g + 0x2E0) > 50.0f) {
                switch (*(s32 *)(g + 0x2DC)) {
                case 2:
                case 13:
                case 35:
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                s32 n = 0;
                s32 i;

                func_0011D534(entry, 0, 0x40);
                for (i = 0; i < D_L39_0024D158; i++) {
                    u32 c = D_L39_0024D15C[i];
                    if (c != 8 && c != 0x1B && c != 9 && c != 10 && !(c & 0x80000000)
                        && (c >= 0x20 && c <= 0x100)) {
                        entry[n++] = D_L39_0024D15C[i];
                    }
                }
                entry[n] = 0;
                func_L39_00687450(D_L39_00247914, D_L39_00249468, entry, 0, 0x3E, 0, 0);
                if (func_001205B0(entry, D_L39_00249468)) {
                    func_00120048(msg, D_L39_002494D8, *(u8 **)(D_L39_0024D760 + 0x30) + 4, entry);
                    if (func_L39_006DA090(*(u8 **)(D_L39_0024D760 + 0x4C), entry)) {
                        func_L39_0067F3B8(0, msg);
                    }
                }
                return 1;
            }
        }
    }

    if (func_L39_0068AEF8(self, input) == 1) {
        return 1;
    }

    st = self->state;
    if (st == 8 || st == 10) {
        f32 k;
        s32 sel;
        s32 last;
        s32 arrow;

        (*(VPP_006BBD80 *)(self->objs[st]->vt + 0x9C))(self->objs[st], &x, &y);
        (*(VPP_006BBD80 *)(self->objs[self->state]->vt + 0xA0))(self->objs[self->state], &w, &h);
        if (self->state == 8) {
            k = D_L39_00249450;
            y += -0.005f;
        } else {
            k = D_L39_0024942C;
            y += -0.001f;
        }
        func_L39_00689F00(self, 0, 3, 3, x + w * 0.5f, y, w * D_L39_00249424, h * 0.75f, k, D_L39_00249430);
        arrow = 3;
        sel = (*(GET_006BBD80 *)(self->objs[self->state]->vt + 0x8C))(self->objs[self->state]);
        last = (*(GET_006BBD80 *)(self->objs[self->state]->vt + 0x78))(self->objs[self->state]) - 1;
        if (sel == 0) {
            arrow = 2;
            if (last == 0) {
                arrow = 0;
            }
        } else if (sel == (*(GET_006BBD80 *)(self->objs[self->state]->vt + 0x78))(self->objs[self->state]) - 1) {
            arrow = 1;
        }
        func_L39_0068A2D0(self, arrow, 3, 3, x + w * 0.5f + 0.001f, y);
    } else if (st == 7 || st == 9) {
        (*(VPP_006BBD80 *)(self->objs[st]->vt + 0x30))(self->objs[st], &x, &y);
        (*(VPP_006BBD80 *)(self->objs[self->state]->vt + 0x34))(self->objs[self->state], &w, &h);
        func_L39_00689F00(self, 0, 3, 3, x, y, w, h, D_L39_00249448, D_L39_0024944C);
        func_L39_0068A2D0(self, 0, 1, 3, x + -0.005f, y);
    } else {
        s32 arrow;
        switch (st) {
        case 4:
            arrow = 2;
            break;
        case 5:
            arrow = 3;
            break;
        case 6:
            arrow = 1;
            break;
        default:
            arrow = 0;
            break;
        }
        (*(VPP_006BBD80 *)(self->objs[st]->vt + 0x30))(self->objs[st], &x, &y);
        (*(VPP_006BBD80 *)(self->objs[self->state]->vt + 0x34))(self->objs[self->state], &w, &h);
        func_L39_00689F00(self, 0, 3, 3, x, y, w, h * 1.15f, D_L39_00249414, D_L39_00249418);
        func_L39_0068A2D0(self, arrow, 3, 3, x, y);
    }
    (*(VFF_006BBD80 *)(self->objs[3]->vt + 0x28))(self->objs[3], 0.31f, 0.44f);
    (*(VFF_006BBD80 *)(self->objs[3]->vt + 0x38))(self->objs[3], 0.4f, 0.44f);
    (*(VF_006BBD80 *)(self->objs[3]->vt + 0x94))(self->objs[3], 1.0f);
    (*(VF_006BBD80 *)(self->objs[3]->vt + 0x90))(self->objs[3], 0.045f);
    (*(VF_006BBD80 *)(self->objs[8]->vt + 0xE4))(self->objs[8], 0.23f);
    return 0;
}
/* localdecomp:end func_L39_006BBD80 */

/* localdecomp:start func_L39_006BD290 */
void func_L39_006CC120(void *);
void func_L39_006CC648(void *, s32);
s32 func_L39_006CC350(void *, s32);
void func_L39_0068B058(void *);

typedef struct S_006BD290 {
    u8 pad0[0x130];
    u8 *list;
    u8 pad134[0xC];
    u8 *icons[4][4];
    u8 pad180[0x8210 - 0x180];
    s32 ids[1];
} S_006BD290;

void func_L39_006BD290(u8 *arg0) {
    S_006BD290 *self = (S_006BD290 *)arg0;
    u8 buf[0x1E0];
    s32 i;
    s32 j;
    s32 n;
    s32 base;
    s32 idx;
    s32 id;
    u8 *o;
    u8 **row;
    u8 **row2;

    func_L39_006CC120(buf);
    o = self->list;
    base = (*(s32 (**)(void *))(*(u8 **)(o + 0x60) + 0xEC))(o);
    for (i = 0; i < 4; i++) {
        idx = base + i;
        o = self->list;
        if ((*(s32 (**)(void *, s32))(*(u8 **)(o + 0x60) + 0xF0))(o, idx)) {
            id = self->ids[idx];
            if (id == 0) {
                n = 0;
            } else {
                func_L39_006CC648(buf, id);
                n = func_L39_006CC350(buf, 3);
                if (n >= 9) {
                    n -= 8;
                }
            }
        } else {
            n = 0;
        }
        row = (u8 **)(arg0 + i * 16) + 0x50;
        row2 = row;
        for (j = 0; j < 4; j++) {
            if (j < n) {
                o = *row;
                (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 1, 0);
            } else {
                o = *row2;
                (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 0, 0);
            }
            row2++;
            row++;
        }
    }
    func_L39_0068B058(arg0);
    func_L39_006CC158(buf, 2);
}
/* localdecomp:end func_L39_006BD290 */

/* localdecomp:start func_L39_006BD408 */
typedef struct {
    char _p0[0x2A8];
    s32 f2A8;
    char f2AC[0x2EB - 0x2AC];
    u8 f2EB;
    char _p2EC[0x2F0 - 0x2EC];
    s32 f2F0;
    s32 f2F4;
    char _p2F8[0x304 - 0x2F8];
    s32 f304;
    s32 f308;
    s32 f30C;
} S_006BD408;
typedef struct {
    s32 f0;
    s32 n;
    s32 **list;
} L_006BD408;
typedef struct {
    u8 f0;
    char _p1[0xD - 0x1];
    u8 fD;
    char _pE[0x14 - 0xE];
    L_006BD408 f14;
} N_006BD408;
typedef struct {
    s32 f0;
    char f4[1];
} M_006BD408;
typedef struct {
    char _p0[0x78];
    N_006BD408 *f78;
} G_006BD408;

__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern u8 D_001A5CD0[];
extern G_006BD408 *D_001E2050_sda;
extern char D_L39_002493B0[];
extern char D_L39_002493B8[];
extern char D_L39_002494E0[];
extern u8 *func_L39_006DB750(s32 *, s32);
extern s32 func_001200E0(void *, char *, ...);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_00195410(void);
extern s32 func_L39_006D7018(void *);
extern void func_L39_006D8B88(void *);
extern void *func_00120D28(void *, void *, s32);
extern s32 func_L39_006CEA18(void *, s32);
extern s32 func_L39_006D2F18(void *, s32 *, s32 *);
extern u8 *func_L39_006D31B8(void *, s32, s32);
extern s32 func_00120884(char *);
extern void func_L39_005958F8(char *, char *, s32);
extern s32 func_0011FFA8(char *, s32, const char *, ...);
extern s32 func_00381FF0(s32);

void func_L39_006BD408(void *arg0, s32 arg1) {
    S_006BD408 *a = (S_006BD408 *)arg0;
    char buf[0x40];
    s32 x;
    s32 y;
    s32 *px;
    s32 *py;
    u8 *p;
    u8 *q;
    s32 kind;

    a->f2A8 = arg1;
    if (*(s32 *)(D_001A5CD0 + 0x2DC) != 0) {
        return;
    }
    p = func_L39_006DB750(*(s32 **)(D_L39_0024D760 + 0x4C), arg1);
    a->f2AC[0] = 0;
    a->f2F0 = 0;
    if (p == 0) {
        return;
    }
    q = p + 0x1C;
    px = &x;
    py = &y;
    kind = 8;
    if (q[0] == 'C') {
        if (q[1] == 'Y') {
            kind = 1;
            func_001200E0(p + 0x1E, D_L39_002493B0, px, py);
        } else if (q[1] == 'R') {
            kind = 4;
            func_001200E0(p + 0x1E, D_L39_002493B0, px, py);
        } else if (q[1] == 'C') {
            kind = 2;
            func_001200E0(p + 0x1E, D_L39_002493B8, px, py);
        }
    } else if (q[0] == 'H') {
        kind = 6;
        func_001200E0(p + 0x1E, D_L39_002493B0, px, py);
    }
    switch (kind) {
    case 1: {
        N_006BD408 *n = D_001E2050_sda->f78;
        s32 id = x + 0x28;
        L_006BD408 *l = n->fD ? &n->f14 : 0;
        s32 start = func_00130760(func_0012DCB0(), 0x24000);
        s32 i;
        s32 cnt;
        s32 *e;

        while (l == 0) {
            func_L39_006D7018(n);
            while (n->f0 != 0) {
                func_00195410();
                if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start >= 0x3A99) {
                    return;
                }
                if (D_001E2050_sda != 0) {
                    func_L39_006D8B88(D_001E2050_sda);
                }
            }
            l = n->fD ? &n->f14 : 0;
        }
        for (i = 0; i < l->n; i++) {
            e = l->list[i];
            if (e[0x18 / 4] == id) {
                func_00120D28(a->f2AC, (u8 *)e + 0x1C, 0x40);
                a->f2F4 = id;
                a->f2F0 = 1;
                a->f2EB = 0;
                break;
            }
        }
        break;
    }
    case 2: {
        M_006BD408 *m = *(M_006BD408 **)(D_L39_0024D760 + 0x38);
        u8 *r;

        if (func_L39_006CEA18(m, 0) == 0) {
            return;
        }
        a->f304 = m->f0;
        if (func_L39_006D2F18(m, &a->f308, &a->f30C) != 0) {
            r = func_L39_006D31B8(m, a->f30C, a->f308);
            if (r != 0) {
                func_L39_005958F8(buf, (char *)r + 0x20, func_00120884((char *)r + 0x20));
                func_0011FFA8(a->f2AC, 0x40, D_L39_002494E0, m->f4, buf);
            } else {
                func_0011FFA8(a->f2AC, 0x40, m->f4);
            }
        } else {
            func_0011FFA8(a->f2AC, 0x40, m->f4);
        }
        a->f2EB = 0;
        a->f2F0 = 3;
        break;
    }
    case 4: {
        M_006BD408 *m = *(M_006BD408 **)(D_L39_0024D760 + 0x38);

        if (func_L39_006CEA18(m, 0) == 0) {
            return;
        }
        if (m->f0 == -1) {
            return;
        }
        func_0011FFA8(a->f2AC, 0x40, (char *)func_00381FF0(0x14A0), m->f4);
        a->f2F0 = 2;
        a->f2EB = 0;
        break;
    }
    }
}
/* localdecomp:end func_L39_006BD408 */

/* localdecomp:start func_L39_006BD788 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_0024D764, 16");
__asm__(".extern D_L39_0024D76C, 16");
extern u8 D_L39_0024D764;
extern u8 *D_L39_0024D760;
extern s32 D_L39_0024D76C;
extern s32 D_001E2058_sda;
extern s32 func_00381FF0(s32);
extern void *func_0011D534(void *, s32, s32);
void func_L39_006CC120(void *);
void func_L39_006CC158(void *, s32);
void func_L39_006CC8F0(void *, s32, s32, s32);
s32 func_L39_006CC930(void *);
void func_L39_00689BB0(void *, s32, s32);

void func_L39_006BD788(void *arg) {
    u8 *arg0 = arg;
    u8 buf[0x1E0];
    s32 a;
    s32 b;
    u8 *o;
    u8 *s1;
    u8 *s2;
    u8 *g;
    u8 on = 1;

    a = func_00381FF0(0x1009);
    o = *(u8 **)(arg0 + 0x138);
    (*(void (**)(void *, s32, void *))(*(u8 **)(o + 0x60) + 0x6C))(o, 1, &a);
    o = *(u8 **)(arg0 + 0x138);
    (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 2, 0);
    b = func_00381FF0(0x1008);
    o = *(u8 **)(arg0 + 0x130);
    (*(void (**)(void *, f32))(*(u8 **)(o + 0x60) + 0xE4))(o, 1.0f);
    o = *(u8 **)(arg0 + 0x130);
    (*(void (**)(void *, s32, void *))(*(u8 **)(o + 0x60) + 0x6C))(o, 1, &b);
    o = *(u8 **)(arg0 + 0x130);
    (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 2, 0);
    o = *(u8 **)(arg0 + 0x11C);
    (*(void (**)(void *))(*(u8 **)(o + 0x60) + 0x68))(o);
    o = *(u8 **)(arg0 + 0x11C);
    (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 2, 0);
    func_0011D534(arg0 + 0x8210, 0, 0x380);
    g = D_L39_0024D760;
    D_L39_0024D76C = 0;
    s1 = *(u8 **)(g + 0x4C);
    s2 = *(u8 **)(g + 0x70);
    D_001E2058_sda = 0;
    func_L39_006CC120(buf);
    func_L39_006CC8F0(buf, 2, 2, *(s32 *)s1);
    func_L39_006CC8F0(buf, 3, 0, 8);
    func_L39_006CC930(buf);
    s1[0x168] = on;
    *(s32 *)(s1 + 0x16C) = 10000;
    s2[0x10] = on;
    *(s32 *)(s2 + 0x14) = 10000;
    arg0[0x314] = on;
    arg0[0x8204] = on;
    o = *(u8 **)(arg0 + 0x130);
    (*(void (**)(void *, s32))(*(u8 **)(o + 0x60) + 0x84))(o, 1);
    o = *(u8 **)(arg0 + 0x138);
    (*(void (**)(void *, s32))(*(u8 **)(o + 0x60) + 0x84))(o, 1);
    o = *(u8 **)(arg0 + 0x11C);
    (*(void (**)(void *, s32))(*(u8 **)(o + 0x60) + 0x84))(o, 1);
    o = *(u8 **)(arg0 + 0x11C);
    (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 3, 0);
    func_L39_00689BB0(arg0, 0x40, 1);
    D_L39_0024D764 = on;
    func_L39_006CC158(buf, 2);
}
/* localdecomp:end func_L39_006BD788 */
