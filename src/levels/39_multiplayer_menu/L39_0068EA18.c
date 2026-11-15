#include "common.h"

/* declared by functions of L39_0068DDC8.c, which this file was cut from */
extern u8 *func_00381FF0(s32);

/* localdecomp:start func_L39_0068EA18 */
extern u8 D_L39_00247CA0[];
__asm__(".extern D_001DC5A8_sda, 4");
__asm__(".extern D_001DC598_sda, 4");
extern f32 D_001DC5A8_sda;
extern f32 D_001DC598_sda;
extern f32 D_L39_00247CAC;
extern f32 D_L39_00247CB0;
extern f32 D_L39_00247CB4;
extern f32 D_L39_00247CBC;
extern f32 D_L39_00247CC0;
extern f32 D_L39_00247CC4;
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern u8 *func_00381FF0(s32);
extern void func_L39_00689BD8(void *, u8 *);
extern void func_L39_00689D28(void *, u8 *);
extern void func_L39_00689DB8(void *, u8 *);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A7B8(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068AAB8(void *);
extern void func_L39_0068FA28(void *);

typedef struct {
    s32 unk0;
    u8 pad4[0x24];
} E_0068EA18;

extern E_0068EA18 D_001FD630[];

void func_L39_0068EA18(u8 *self) {
    u8 *one[1];
    s32 i;
    s32 found;
    f32 scale = 1.0f;
    u8 **q;
    s32 j;

    one[0] = D_L39_00247CA0;
    func_L39_0067F100(0x240000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(self, func_00381FF0(0x10FE));
    func_L39_00689D28(self, func_00381FF0(0x124));
    func_L39_00689DB8(self, func_00381FF0(0xCD5));
    func_L39_0068A6D0(self, 0, 0.273f, 0.5f, 0.367f, 0.72f, 0x332299DE);
    func_L39_0068A7B8(self, 0, D_001DC5A8_sda, D_L39_00247CBC, D_L39_00247CC0, D_L39_00247CC4, 0x331465B7);
    func_L39_0068A4A8(self, 0, 10, 0.273f, 0.2747f, 0.056f, 0.35f, 0x332299DE);
    func_L39_0068A6D0(self, 1, 0.687f, 0.773f, 0.45f, 0.172f, 0x332299DE);
    func_L39_0068A4A8(self, 1, 2, D_001DC598_sda, D_L39_00247CAC, D_L39_00247CB0, D_L39_00247CB4, 0x332299DE);
    func_L39_0068A6D0(self, 2, 0.687f, 0.411f, 0.45f, 0.539f, 0x332299DE);
    func_L39_0068A4A8(self, 2, 10, 0.687f, 0.203f, 0.047f, 0.4f, 0x332299DE);
    func_L39_0068AAB8(self);
    q = (u8 **)(self + 0x124);
    for (i = 0; i < 11; i++, q++) {
        {
            u8 *o = *q;
            (*(void (**)(void *, f32, f32))(*(u8 **)(o + 0x60) + 0x38))(o, scale, scale);
        }
        {
            u8 *o = *q;
            (*(void (**)(void *, s32))(*(u8 **)(o + 0x60) + 0x40))(o, 1);
        }
        {
            u8 *o = *q;
            (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x4C))(o, 0x40, 1);
        }
        {
            u8 *o = *q;
            (*(void (**)(void *))(*(u8 **)(o + 0x60) + 0xB4))(o);
        }
    }
    {
        u8 *o = *(u8 **)(self + 0x150);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 0, 0);
    }
    {
        u8 *o = *(u8 **)(self + 0x154);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 0, 0);
    }
    {
        u8 *o = *(u8 **)(self + 0x158);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 0, 0);
    }
    {
        u8 *o = *(u8 **)(self + 0x15C);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 0, 0);
    }
    {
        u8 *o = *(u8 **)(self + 0x120);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x4C))(o, 0x40, 1);
    }
    {
        u8 *o = *(u8 **)(self + 0x114);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x4C))(o, 0x40, 1);
    }
    {
        u8 *o = *(u8 **)(self + 0x118);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x4C))(o, 0x40, 1);
    }
    {
        u8 *o = *(u8 **)(self + 0x11C);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x4C))(o, 0x40, 1);
    }
    {
        u8 *o = *(u8 **)(self + 0x120);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 1, 0);
    }
    {
        u8 *o = *(u8 **)(self + 0x120);
        (*(void (**)(void *, f32, f32))(*(u8 **)(o + 0x60) + 0x38))(o, 0.8f, scale);
    }
    {
        u8 *o = *(u8 **)(self + 0x110);
        (*(s32 (**)(void *, s32, u8 **))(*(u8 **)(o + 0x60) + 0x6C))(o, 1, one);
    }
    {
        u8 *o = *(u8 **)(self + 0x110);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 2, 0);
    }
    {
        u8 *o = *(u8 **)(self + 0x110);
        (*(void (**)(void *, s32))(*(u8 **)(o + 0x60) + 0x84))(o, 1);
    }
    {
        u8 *o = *(u8 **)(self + 0x110);
        (*(void (**)(void *, f32))(*(u8 **)(o + 0x60) + 0x90))(o, 0.059f);
    }
    {
        u8 *o = *(u8 **)(self + 0x110);
        (*(void (**)(void *, f32))(*(u8 **)(o + 0x60) + 0x94))(o, 0.8f);
    }
    {
        u8 *o = *(u8 **)(self + 0x110);
        (*(void (**)(void *, f32))(*(u8 **)(o + 0x60) + 0xE4))(o, 0.34f);
    }
    {
        u8 *o = *(u8 **)(self + 0x110);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x4C))(o, 0x40, 1);
    }
    {
        u8 *args[2] = { D_L39_00247CA0, func_00381FF0(0x100D) };
        u8 *o = *(u8 **)(self + 0x110);
        (*(s32 (**)(void *, s32, u8 **))(*(u8 **)(o + 0x60) + 0x6C))(o, 2, args);
    }
    {
        u8 *o = *(u8 **)(self + 0x110);
        (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 2, 0);
    }
    found = 0;
    for (j = 0; !found && j < 11; j++) {
        s32 t = found | (D_001FD630[j].unk0 >= 0);
        found = t != 0;
    }
    if (found) {
        {
            u8 *o = *(u8 **)(self + 0x118);
            (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 3, 0);
        }
        {
            u8 *o = *(u8 **)(self + 0x118);
            (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x4C))(o, 0x40, 1);
        }
    } else {
        {
            u8 *o = *(u8 **)(self + 0x118);
            (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x1C))(o, 2, 0);
        }
        {
            u8 *o = *(u8 **)(self + 0x118);
            (*(void (**)(void *, s32, s32))(*(u8 **)(o + 0x60) + 0x4C))(o, 0x40, 0);
        }
    }
    func_L39_0068FA28(self);
    self[0x2A8] = 1;
}
/* localdecomp:end func_L39_0068EA18 */
