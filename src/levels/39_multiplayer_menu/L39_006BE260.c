#include "common.h"

/* declared by functions of L39_006BA5C0.c, which this file was cut from */
extern u8 *D_L39_0024D760;

/* localdecomp:start func_L39_006BE260 */
__asm__(".extern D_L39_0024D760, 16");

typedef struct S_006BE260_item {
    char pad0[0x1C];
    s32 f1C;
    char pad20[0x2C];
    char f4C[0x12];
    u8 f5E;
} S_006BE260_item;

typedef struct S_006BE260_entry {
    s32 f0;
    s32 f4;
    S_006BE260_item **f8;
} S_006BE260_entry;

typedef struct S_006BE260_mgr {
    char pad0[0x18];
    s32 f18;
    u8 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    S_006BE260_entry f2C[1];
} S_006BE260_mgr;

typedef struct S_006BE260_list S_006BE260_list;

typedef struct S_006BE260_vt {
    char pad0[0x28];
    void (*f28)(S_006BE260_list *, f32, f32);
    char pad2C[0x40];
    void (*f6C)(S_006BE260_list *, s32, char **);
    char pad70[0x18];
    void (*f88)(S_006BE260_list *, s32);
    s32 (*f8C)(S_006BE260_list *);
    void (*f90)(S_006BE260_list *, f32);
    char pad94[0x50];
    void (*fE4)(S_006BE260_list *, f32);
} S_006BE260_vt;

struct S_006BE260_list {
    char pad0[0x60];
    S_006BE260_vt *f60;
};

typedef struct S_006BE260_self {
    char pad0[0x12C];
    char *f12C;
    S_006BE260_list *f130;
    char pad134[0x15C];
    s32 f290;
    char pad294[0x84];
    s32 f318;
    char pad31C[0x7EE8];
    u8 f8204;
    s32 f8208;
    s32 f820C;
    S_006BE260_item *f8210[0xE0];
    u8 f8590[4];
} S_006BE260_self;

extern s32 func_L39_006D5AB8(u8 *);
extern char *func_00381FF0(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_L39_006CCA88(u8 *, S_006BE260_item *, s32);
extern s32 func_00120884(char *);
extern void func_L39_005958F8(char *, char *, s32);
extern u8 D_L39_002494F0[];
extern char D_L39_00380FC8[][0x40];

void func_L39_006BE260(S_006BE260_self *self)
{
    char *names[0xE0];
    S_006BE260_mgr *m = *(S_006BE260_mgr **)(D_L39_0024D760 + 0x70);
    S_006BE260_entry *entry;
    s32 sel;
    s32 selIdx;
    s32 count;
    s32 i;
    s32 j;
    s32 r;
    s32 id;
    s32 cur;

    entry = 0;
    if (m->f18 >= 0) {
        entry = &m->f2C[m->f18];
    }
    if (self->f8204 == 1 && !m->f1C && !self->f318) {
        func_L39_006D5AB8((u8 *)m);
        id = m->f24;
        self->f8204 = 0;
        self->f8208 = id;
    }
    self->f130->f60->f28(self->f130, 0.725f, 0.315f);
    self->f130->f60->f90(self->f130, 0.0575f);
    if (entry && m->f24 != self->f8208) {
        sel = -1;
        selIdx = 0;
        func_00120048((u8 *)self->f12C + 0x14, D_L39_002494F0, func_00381FF0(0x1006), entry->f4);
        cur = m->f24;
        self->f820C = 0;
        self->f8208 = cur;
        count = entry->f4;
        r = self->f130->f60->f8C(self->f130);
        if (r != -1) {
            S_006BE260_item *p = self->f8210[r];
            if (p) {
                sel = p->f1C;
            }
        }
        for (i = 0; i < count && self->f820C < 0xE0; i++) {
            S_006BE260_item *item = entry->f8[i];
            if (func_L39_006CCA88(self->f8590, item, 0)) {
                self->f8210[self->f820C] = item;
                item->f5E = 0;
                names[self->f820C] = item->f4C;
                if (sel == item->f1C) {
                    selIdx = self->f820C;
                }
                self->f820C++;
            }
        }
        for (j = 0; j < self->f820C; j++) {
            func_L39_005958F8(D_L39_00380FC8[j], names[j], func_00120884(names[j]));
            names[j] = D_L39_00380FC8[j];
        }
        self->f130->f60->f6C(self->f130, self->f820C, names);
        self->f130->f60->f88(self->f130, selIdx);
        self->f130->f60->fE4(self->f130, 0.23f);
        if (self->f290 == 8 && self->f820C == 0) {
            self->f290 = 7;
        }
    }
}
/* localdecomp:end func_L39_006BE260 */
