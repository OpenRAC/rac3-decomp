#include "common.h"

typedef struct { u8 pad0[0x68]; struct { u8 pad[4]; s32 idx; } *p68; } O_B;

/* declared by functions of L07_003C0710.c, which this file was cut from */
extern u8 *D_001DE550_sda;
extern void func_L07_003C17C0(void *);
extern void func_L07_003C0F40(u8 *);
typedef struct {
    u8 b0;
    u8 pad1;
    s16 h2;
    u8 pad4[0x20];
} E_003C0F40;
extern E_003C0F40 D_L07_002BC920_003C0F40[];
extern u8 D_L07_001DE554;
extern u8 D_L07_001DE555;

/* localdecomp:start func_L07_003C1528 */
/* from rac3-decomp's func_L03_0032FE70 */
extern u8 *D_001D52FC;
extern u8 D_00142CA0[];
__asm__(".extern D_001DE550_sda, 4");
__asm__(".extern D_L07_001DE554, 1");
__asm__(".extern D_L07_001DE555, 1");
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_003A5348(s32, s32, s32);
extern void func_003A2CD8(void *);
extern void func_L01_00516558(s32, f32 *, f32 *);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_005170B8(s32, s32);

s32 func_L07_003C1528(void) {
    u8 *self;
    u8 *st;
    s32 r;
    u32 buttons;
    s32 id;
    f32 t;
    f32 u;
    f32 w;
    f32 buf[2];

    self = D_001DE550_sda;
    st = *(u8 **)(self + 0x68);
    r = 0;
    func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
    buttons = *(u32 *)(D_001D52FC + 0x1C4);
    if (buttons & 0x1000) {
        if (D_L07_001DE554 != 0) {
            func_003A5348(3, 0, 0);
            D_L07_001DE554 = D_L07_001DE554 - 1;
            if (D_L07_001DE554 < D_L07_001DE555) {
                D_L07_001DE555 = D_L07_001DE555 - 1;
            }
            func_L07_003C17C0(self);
        }
        func_003A2CD8(D_001D52FC);
    } else if (buttons & 0x4000) {
        if (D_L07_001DE554 < st[0x39] + st[0x3A] - 1) {
            func_003A5348(3, 0, 0);
            D_L07_001DE554 = D_L07_001DE554 + 1;
            if (D_L07_001DE554 - D_L07_001DE555 >= 5) {
                D_L07_001DE555 = D_L07_001DE555 + 1;
            }
            func_L07_003C17C0(self);
        }
        func_003A2CD8(D_001D52FC);
    } else if (buttons & 0x10) {
        r = 1;
        func_L07_003C0D00((s32)self);
        func_003A2CD8(D_001D52FC);
    } else if (buttons & 0x40) {
        E_003C0F40 *e = &D_L07_002BC920_003C0F40[st[0x38]];
        if (e->b0 == 0) {
            s32 idx = func_L07_00334A70(e->h2);
            if (idx != -1 && D_00142CA0[idx] == 0) {
                func_003A5348(5, 0, 0);
                return 2;
            }
        }
        func_003A5348(4, 0, 0);
        func_L07_003C0F40(self);
        func_003A2CD8(D_001D52FC);
        r = 3;
    }
    w = *(f32 *)(st + 0x28) + 0.060000002f;
    *(f32 *)(st + 0x28) = w;
    if (2.0f < w) {
        *(f32 *)(st + 0x28) = w - 2.0f;
    }
    id = 0x470024 + (D_L07_001DE554 - D_L07_001DE555);
    func_L01_00516558(id, &buf[0], &buf[1]);
    func_L01_00516470(0x470023, buf[0], buf[1]);
    t = *(f32 *)(st + 0x28);
    u = (t <= 1.0f) ? t : 2.0f - t;
    func_L01_005170B8(id, func_0038DBD8(0x66D6EEFA, 0x80FFFFFF, u));
    return r;
}
/* localdecomp:end func_L07_003C1528 */

/* localdecomp:start func_L07_003C17C0 */
typedef struct { u8 kind; u8 pad; s16 id; u8 pad4[0x10]; s32 name, desc; u8 tail[8]; } Entry_3C17C0;
typedef struct { u8 pad[0x68]; u8 *state; } Object_3C17C0;
extern Entry_3C17C0 D_L07_002BC920_003C17C0[];
extern u8 D_001426E0[];
typedef struct { u8 pad[0x20]; s32 f20; s32 f24; u8 pad28[0x10]; u8 b38; } St_3C17C0;
extern u8 D_L07_001DE590[];
extern u8 D_L07_001E1708[] __attribute__((section(".sdata")));
extern u8 D_L07_001E1710[] __attribute__((section(".sdata")));
extern void func_L07_003C19C8();
extern s32 func_L07_003C1B88(s32);
extern s32 func_L07_003C1C08(s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00516FD8(s32, void *);
extern s32 func_0011B2E8(void *, void *, ...);
extern s32 func_L07_003C1360(s32);
extern void func_L07_00334878(s32, s32 *, s32 *, s32 *);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00517190(s32, s32);
void func_L07_003C17C0(void *raw) {
    u8 *arg0 = raw;
    s32 values[3];
    s32 count;
    St_3C17C0 *s;
    Entry_3C17C0 *entry;
    s32 id;
    s32 i;
    s32 widget;
    count = 0;
    s = (St_3C17C0 *)((Object_3C17C0 *)arg0)->state;
    func_L07_003C19C8(arg0, s->f24, &count, 0x8066CCFF);
    func_L07_003C19C8(arg0, s->f20, &count, 0x80808080);
    entry = &D_L07_002BC920_003C17C0[s->b38];
    id = func_L07_003C1B88(s->b38);
    if (id == -1) {
        func_L01_00516FD8(0x47000F, (void *)func_00381FF0(entry->name));
    } else {
        func_L01_00516FD8(0x47000F, (void *)func_00381FF0(id));
    }
    id = func_L07_003C1C08(s->b38);
    if (id == -1) {
        func_L01_00516FD8(0x470012, (void *)func_00381FF0(entry->desc));
    } else {
        func_L01_00516FD8(0x470012, (void *)func_00381FF0(id));
    }
    func_0011B2E8(D_L07_001E1708, D_L07_001DE590, D_001426E0[s->b38 + 0x8E]);
    id = func_L07_003C1360(s->b38);
    func_0011B2E8(D_L07_001E1710, D_L07_001DE590, id);
    if (entry->kind == 0) {
        func_L07_00334878(entry->id, &values[0], &values[1], &values[2]);
    } else {
        values[2] = 0;
        values[1] = 0;
        values[0] = 0;
    }
    widget = 0x470014;
    for (i = 0; i < 3; i++) {
        if (values[i] == 0) {
            func_L01_00516AA0(widget, 1, 0);
        } else {
            func_L01_00516AA0(widget, 1, 1);
            func_L01_00517190(widget, values[i]);
        }
        widget++;
    }
    func_L01_00517190(0x47001C, s->b38 + 10);
}
/* localdecomp:end func_L07_003C17C0 */
