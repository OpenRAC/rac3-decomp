#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* declared by functions of L39_00681758.c, which this file was cut from */
extern void func_L39_0067EEC8(u8 *, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516818(s32);
extern S_00683550 *func_L39_0067EE40(void *, void *);
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00517538(s32, f32, f32);

/* localdecomp:start func_L39_00684488 */
void func_0011D534(s32, s32, s32);

void func_L39_00684488(s32 arg0) {
    func_0011D534(arg0 + 0x64, 0, 0x50);
}
/* localdecomp:end func_L39_00684488 */

/* localdecomp:start func_L39_006844B0 */
void func_L39_006844B0(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x58) = fparg0;
    *(s32 *)((u8 *)arg0 + 0xC0) = 1;
}
/* localdecomp:end func_L39_006844B0 */

/* localdecomp:start func_L39_006844C0 */
void func_L39_006844C0(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x4C) = fparg0;
    *(s32 *)((u8 *)arg0 + 0x48) = 1;
}
/* localdecomp:end func_L39_006844C0 */

/* localdecomp:start func_L39_006844D0 */
s32 func_L39_006844D0(s32 arg0) {
    return arg0 + 0x64;
}
/* localdecomp:end func_L39_006844D0 */

LINKER_REMNANT("asm/levels", func_L39_006844D8);

/* localdecomp:start func_L39_006844E0 */
extern S_00683550 *func_L39_0067EE40(void *, void *);
extern u8 D_L39_0047BF38[];

void *func_L39_006844E0(void *arg0, void *arg1) {
    func_L39_0067EE40(arg0, arg1);
    *(s32 *)((u8 *)arg0 + 0x468) = -1;
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047BF38;
    *(s32 *)((u8 *)arg0 + 0x464) = 0;
    *(s32 *)((u8 *)arg0 + 0x46C) = 0;
    return arg0;
}
/* localdecomp:end func_L39_006844E0 */

/* localdecomp:start func_L39_00684528 */
extern u8 D_L39_0047BF38[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00684528(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047BF38;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00684528 */

/* localdecomp:start func_L39_00684550 */
void func_L39_00684550(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x464) = arg1;
}
/* localdecomp:end func_L39_00684550 */

/* localdecomp:start func_L39_00684558 */
s32 func_L39_00684558(void *arg0, f32 fa, f32 fb) {
    if (*(s32 *)((u8 *)arg0 + 0x468) != -1) {
        *(f32 *)((u8 *)arg0 + 0x58) = fa;
        *(f32 *)((u8 *)arg0 + 0x5C) = fb;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00684558 */

/* localdecomp:start func_L39_00684580 */
void func_L39_00684580(void *arg0, f32 fa, f32 fb) {
    if (*(s32 *)((u8 *)arg0 + 0x468) != -1) {
        *(f32 *)((u8 *)arg0 + 0x50) = fa;
        *(f32 *)((u8 *)arg0 + 0x54) = fb;
    }
}
/* localdecomp:end func_L39_00684580 */

/* localdecomp:start func_L39_006845A0 */
extern s32 func_L01_00516818(s32);

s32 func_L39_006845A0(void *arg0) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x468);

    if (v != -1) {
        return func_L01_00516818(v);
    }
    return 0;
}
/* localdecomp:end func_L39_006845A0 */

/* localdecomp:start func_L39_006845D0 */
extern s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_006845D0(void *arg0, s32 arg1, s32 arg2) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x468);

    if (v != -1) {
        return func_L01_00516AA0(v, arg1, arg2);
    }
    return 0;
}
/* localdecomp:end func_L39_006845D0 */

/* localdecomp:start func_L39_00684600 */
extern s32 func_L01_00518670(s32);

s32 func_L39_00684600(void *arg0) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x468);

    if (v != -1) {
        return func_L01_00518670(v);
    }
    return 0;
}
/* localdecomp:end func_L39_00684600 */

/* localdecomp:start func_L39_00684630 */
s32 func_L39_00610CA8(s32);

s32 func_L39_00684630(void *arg0) {
    s32 temp_a0;
    s32 var_v1;

    temp_a0 = *(s32 *)((u8 *)arg0 + 0x468);
    var_v1 = 0;
    if (temp_a0 != -1) {
        var_v1 = func_L39_00610CA8(temp_a0);
    }
    return var_v1;
}
/* localdecomp:end func_L39_00684630 */

/* localdecomp:start func_L39_00684668 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_00684668(void *arg0, s32 arg1) {
    s32 mode;

    *(s32 *)((u8 *)arg0 + 0x46C) = arg1;
    mode = 2;
    if (arg1 == 1) {
        mode = 1;
    }
    if (*(s32 *)((u8 *)arg0 + 0x468) != -1) {
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x468), mode);
    }
    return 1;
}
/* localdecomp:end func_L39_00684668 */

/* localdecomp:start func_L39_006846B0 */
extern s32 func_L39_0067F1B0(void);
extern void func_003EA778(s32);
extern s32 func_003E7F20(s32, s32);
extern void func_003E8630(s32, s32);
extern s32 D_001DBC5C_sda;

void func_L39_006846B0(void *arg0) {
    s32 mode = (*(s32 *)((u8 *)arg0 + 0x46C) == 1) ? 1 : 2;

    if (*(s32 *)((u8 *)arg0 + 0x468) == -1) {
        *(s32 *)((u8 *)arg0 + 0x468) = func_L39_0067F1B0();
        func_003EA778(*(s32 *)((u8 *)arg0 + 0x468));
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x468), mode);
        func_003E8630(D_001DBC5C_sda, *(s32 *)((u8 *)arg0 + 0x468));
    }
}
/* localdecomp:end func_L39_006846B0 */

/* localdecomp:start func_L39_00684728 */
void func_L39_00684728(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x468) = -1;
}
/* localdecomp:end func_L39_00684728 */

/* localdecomp:start func_L39_00684738 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);

void func_L39_00684738(void *arg0) {
    f32 v[2];
    f32 fb;

    if (*(s32 *)((u8 *)arg0 + 0x468) == -1) {
        return;
    }
    if (*(s32 *)((u8 *)arg0 + 0x4) == 0) {
        func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x468), 1, 0);
        return;
    }
    func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x468), 1, 1);
    (*(s32 (**)(void *, void *, void *))((u8 *)(*(void **)((u8 *)arg0 + 0x60)) + 0x30))(arg0, v, &v[1]);
    if (*(s32 *)((u8 *)arg0 + 0x464) != 0) {
        func_L01_00516FD8(*(s32 *)((u8 *)arg0 + 0x468), *(s32 *)((u8 *)arg0 + 0x464));
    } else {
        func_L01_00516FD8(*(s32 *)((u8 *)arg0 + 0x468), (s32)((u8 *)arg0 + 0x64));
    }
    func_L01_00517538(*(s32 *)((u8 *)arg0 + 0x468), *(f32 *)((u8 *)arg0 + 0x58), *(f32 *)((u8 *)arg0 + 0x5C));
    fb = v[1];
    func_L01_00516470(*(s32 *)((u8 *)arg0 + 0x468), v[0], fb);
    func_L01_005170B8(*(s32 *)((u8 *)arg0 + 0x468), 0x8066CCFF);
}
/* localdecomp:end func_L39_00684738 */

/* localdecomp:start func_L39_006847F8 */
void func_0011D534(s32, s32, s32);

void func_L39_006847F8(s32 arg0) {
    func_0011D534(arg0 + 0x64, 0, 0x400);
}
/* localdecomp:end func_L39_006847F8 */

/* localdecomp:start func_L39_00684820 */
void func_00120D28(s32, s32, s32);
void func_L39_00684820(void *arg0, s32 arg1) {
    func_00120D28(arg0 + 0x64, arg1, 0x400);
    *(s8 *)((u8 *)arg0 + 0x463) = 0;
}
/* localdecomp:end func_L39_00684820 */

/* localdecomp:start func_L39_00684850 */
s32 func_L39_00684850(s32 arg0) {
    return arg0 + 0x64;
}
/* localdecomp:end func_L39_00684850 */

LINKER_REMNANT("asm/levels", func_L39_00684858);

/* localdecomp:start func_L39_00684860 */
typedef struct {
    u8 pad0[0x60];
    void *vt;
    u8 pad64[0x130 - 0x64];
    s32 s130, s134, s138, s13C, s140;
    u8 pad144[4];
    u8 f148;
    u8 pad149[0x164 - 0x149];
    u8 f164;
    u8 pad165[0x230 - 0x165];
    s32 f230, f234, f238, f23C, f240, f244;
    u8 f248;
} S_00684860;
extern S_00683550 *func_L39_0067EE40(void *, void *);
extern u8 D_L39_0047C028[];
extern void func_00120D28(s32, s32, s32);
extern u8 *D_001DC0A4_sda;
extern u8 *D_001DC0C4_sda;
extern u8 *D_001DC0D4_sda;
extern u8 *D_001DC0EC_sda;

void *func_L39_00684860(void *arg0, void *arg1) {
    S_00684860 *o = arg0;
    u8 *obj = arg0;
    u8 *src = arg1;
    u8 *str;
    u8 *p;
    s32 n;

    func_L39_0067EE40(arg0, arg1);
    o->vt = D_L39_0047C028;
    o->f164 = 0;
    o->f230 = 0;
    o->f234 = 0;
    o->f238 = 0;
    o->s130 = -1;
    o->s134 = -1;
    o->s138 = -1;
    o->s13C = -1;
    o->s140 = -1;
    o->f23C = 0;
    o->f240 = 0;
    if (src + 0x48 == 0) {
        *(u8 *)(obj + 0x64) = 0;
    } else {
        func_00120D28((s32)(obj + 0x64), (s32)(src + 0x48), 0xC8);
        *(u8 *)(obj + 0x12B) = 0;
    }
    n = *(s32 *)(src + 0x110);
    *(s32 *)(obj + 0x12C) = n;
    *(u8 *)(obj + 0x3DB) = *(u8 *)(src + 0x114);
    *(u8 *)(obj + 0x4A4) = *(u8 *)(src + 0x115);
    if (n >= 200) {
        *(s32 *)(obj + 0x12C) = 199;
    }
    str = D_001DC0A4_sda;
    if (str != 0 && *str != 0) {
        p = str;
        do {
            (*(void (**)(u8 *, s32))(*(u8 **)(obj + 0x60) + 0xC8))(obj, *p);
            p++;
        } while (str != 0 && *p != 0);
    }
    str = D_001DC0C4_sda;
    if (str != 0 && *str != 0) {
        p = str;
        do {
            (*(void (**)(u8 *, s32))(*(u8 **)(obj + 0x60) + 0xC8))(obj, *p);
            p++;
        } while (str != 0 && *p != 0);
    }
    str = D_001DC0D4_sda;
    if (str != 0 && *str != 0) {
        p = str;
        do {
            (*(void (**)(u8 *, s32))(*(u8 **)(obj + 0x60) + 0xC8))(obj, *p);
            p++;
        } while (str != 0 && *p != 0);
    }
    str = D_001DC0EC_sda;
    if (str != 0 && *str != 0) {
        p = str;
        do {
            (*(void (**)(u8 *, s32))(*(u8 **)(obj + 0x60) + 0xC8))(obj, *p);
            p++;
        } while (str != 0 && *p != 0);
    }
    o->f148 |= 1;
    o->f244 = 0;
    o->f248 = 0;
    *(u8 *)(obj + 0x4A5) = *(u8 *)(src + 0x116);
    return obj;
}
/* localdecomp:end func_L39_00684860 */

/* localdecomp:start func_L39_00684A68 */
extern u8 D_L39_0047C028[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00684A68(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C028;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00684A68 */

/* localdecomp:start func_L39_00684A90 */
extern s32 func_L01_00517538(s32, f32, f32);

s32 func_L39_00684A90(void *arg0, f32 fa, f32 fb) {
    u8 *base = (u8 *)arg0;
    s32 r = 0;

    if (*(s32 *)(base + 0x130) != -1) {
        r = func_L01_00517538(*(s32 *)(base + 0x130), fa, fb);
    }
    if (*(s32 *)(base + 0x134) != -1) {
        r |= func_L01_00517538(*(s32 *)(base + 0x134), fa, fb);
    }
    if (*(s32 *)(base + 0x138) != -1) {
        r |= func_L01_00517538(*(s32 *)(base + 0x138), fa, fb);
    }
    if (*(s32 *)(base + 0x13C) != -1) {
        r |= func_L01_00517538(*(s32 *)(base + 0x13C), fa, fb);
    }
    if (*(s32 *)(base + 0x140) != -1) {
        r |= func_L01_00517538(*(s32 *)(base + 0x140), fa, fb);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00684A90 */

/* localdecomp:start func_L39_00684B58 */
s32 func_L39_00684B58(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0x248) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00684B58 */

/* localdecomp:start func_L39_00684B68 */
extern s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00684B68(void *arg0, s32 fa, s32 fb) {
    u8 *base = (u8 *)arg0;
    s32 r = 0;

    if (*(s32 *)(base + 0x130) != -1) {
        r = func_L01_00516AA0(*(s32 *)(base + 0x130), fa, fb);
    }
    if (*(s32 *)(base + 0x134) != -1) {
        r |= func_L01_00516AA0(*(s32 *)(base + 0x134), fa, fb);
    }
    if (*(s32 *)(base + 0x138) != -1) {
        r |= func_L01_00516AA0(*(s32 *)(base + 0x138), fa, fb);
    }
    if (*(s32 *)(base + 0x13C) != -1) {
        r |= func_L01_00516AA0(*(s32 *)(base + 0x13C), fa, fb);
    }
    if (*(s32 *)(base + 0x140) != -1) {
        r |= func_L01_00516AA0(*(s32 *)(base + 0x140), fa, fb);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00684B68 */

/* localdecomp:start func_L39_00684C30 */
extern s32 func_L01_00517538(s32, f32, f32);

s32 func_L39_00684C30(void *arg0, f32 fparg0, f32 fparg1) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x138);

    if (v != -1) {
        return func_L01_00517538(v, fparg0, fparg1);
    }
    return 0;
}
/* localdecomp:end func_L39_00684C30 */

/* localdecomp:start func_L39_00684C60 */
extern s32 func_L01_00516C78(s32, s32, s32);

s32 func_L39_00684C60(void *arg0, s32 a1, s32 a2) {
    
    s32 r = 0;

    if (*(s32 *)((u8 *)arg0 + 0x130) != -1) {
        r = func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x130), a1, a2);
    }
    if (*(s32 *)((u8 *)arg0 + 0x134) != -1) {
        r |= func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x134), a1, a2);
    }
    if (*(s32 *)((u8 *)arg0 + 0x138) != -1) {
        r |= func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x138), a1, a2);
    }
    if (*(s32 *)((u8 *)arg0 + 0x13C) != -1) {
        r |= func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x13C), a1, a2);
    }
    if (*(s32 *)((u8 *)arg0 + 0x140) != -1) {
        r |= func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x140), a1, a2);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00684C60 */

/* localdecomp:start func_L39_00684D28 */
typedef struct {
    u8 pad0[0x64];
    u8 name[0xC8];
    s32 max;
    u8 pad12C[0x144 - 0x130];
    u8 bits[0x20];
    u8 active;
    u8 text[0xCB];
    s32 len;
    s32 cur;
    u8 pad238[0x4A4 - 0x238];
    u8 f4A4;
    u8 f4A5;
} S_00684D28;

extern s32 func_L39_00688340(s32, s32, s32);
extern void *func_001206F4(void *, void *);
extern void *func_0011D380(void *, const void *, unsigned int);
extern void func_L39_00687450(s32, void *, void *, s32, s32, u8, u8);
__asm__(".extern D_L39_00247914, 16");
extern s32 D_L39_00247914;
extern u8 D_L39_00247848[];

s32 func_L39_00684D28(S_00684D28 *o, s32 key) {
    u8 tmp[32];
    s32 cur;
    s32 c4;
    s32 c3;
    s32 j;
    u8 c;
    u8 start1;
    u8 start2;
    s32 ret;

    ret = 0;

    if (key == 7) {
        func_L39_00688340(4, 0, 0);
        func_001206F4(tmp, o->name);
        func_L39_00687450(D_L39_00247914, D_L39_00247848, o->name, 0, o->max, o->f4A4, o->f4A5);
        ret = 1;
    } else if (key == 5) {
        if (o->active == 1) {
            o->active = 0;
            ret = 1;
        }
    } else if (o->active != 0) {
        if (key == 11) {
            if (o->cur > 0) {
                o->cur = o->cur - 1;
            }
        } else if (key == 14) {
            if (o->cur < o->len - 1) {
                o->cur = o->cur + 1;
            } else if (o->cur < o->max - 1) {
                o->len = o->len + 1;
                o->cur = o->cur + 1;
                o->text[o->cur] = ' ';
            }
        }
        if (key == 4) {
            if (o->cur < o->max - 1) {
                if (o->cur < o->max - 2) {
                    for (j = o->max - 1; o->cur < j; j--) {
                        o->text[j] = o->text[j - 1];
                    }
                    if (o->len < o->max) {
                        o->len = o->len + 1;
                    }
                }
                c4 = o->cur;
                o->cur = c4 + 1;
                if (o->cur == 0) {
                    o->text[0] = 'A';
                } else {
                    o->text[o->cur] = o->text[c4];
                }
                if (o->len - 1 < o->cur) {
                    o->len = o->cur + 1;
                }
            }
        } else if (key == 3) {
            c3 = o->cur;
            if (c3 < 0) {
                goto done;
            }
            if (c3 < o->len - 1) {
                if (c3 > 0) {
                    func_0011D380((u8 *)(c3 + (s32)o + 0x164), (u8 *)(c3 + (s32)o + 0x165), o->max - c3);
                    o->cur = o->cur - 1;
                    o->len = o->len - 1;
                } else {
                    func_0011D380(&o->text[0], &o->text[1], o->max - 1);
                    o->len = o->len - 1;
                }
            } else {
                o->len = o->len - 1;
                o->cur = c3 - 1;
            }
        }
        cur = o->cur;
        if (o->cur >= 0) {
            if (key == 1) {
                c = o->text[cur];
                start1 = c;
                do {
                    if (c < 0xFF) {
                        c++;
                    } else {
                        c = 0;
                    }
                    if ((o->bits[c >> 3] >> (c & 7)) & 1) {
                        break;
                    }
                } while (c != start1);
                o->text[o->cur] = c;
            } else if (key == 2) {
                c = o->text[cur];
                start2 = c;
                do {
                    if (c != 0) {
                        c--;
                    } else {
                        c = 0xFF;
                    }
                    if ((o->bits[c >> 3] >> (c & 7)) & 1) {
                        break;
                    }
                } while (c != start2);
                o->text[o->cur] = c;
            } else if (key == 12) {
                if (o->text[cur] >= 'A' && o->text[cur] <= 'Z') {
                    o->text[o->cur] = o->text[cur] + 0x20;
                } else if (o->text[cur] >= 'a' && o->text[cur] <= 'z') {
                    o->text[o->cur] = o->text[cur] - 0x20;
                } else {
                    o->text[cur] = 'A';
                }
            } else if (key == 15) {
                if (o->text[cur] < '0' || o->text[cur] > '9') {
                    o->text[cur] = '0';
                }
            }
        }
done:
        ret = 1;
    }
    return ret;
}
/* localdecomp:end func_L39_00684D28 */

/* localdecomp:start func_L39_006850F8 */
extern s32 func_L39_0067F1B0(void);
extern s32 func_003E5360(s32);
extern void func_003E8630(s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 D_0024736C;
__asm__(".extern D_0024736C, 16");
extern s32 D_00247388;
__asm__(".extern D_00247388, 16");

void func_L39_006850F8(void *arg0) {
    s32 mode = (*(s32 *)((u8 *)arg0 + 0x240) == 1) ? 1 : 2;

    if (*(s32 *)((u8 *)arg0 + 0x130) == -1) {
        *(s32 *)((u8 *)arg0 + 0x130) = func_L39_0067F1B0();
        func_003E5360(*(s32 *)((u8 *)arg0 + 0x130));
        func_003E8630(D_0024736C, *(s32 *)((u8 *)arg0 + 0x130));
        func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x130), 1, 3);
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x130), mode);
    }
    if (*(s32 *)((u8 *)arg0 + 0x134) == -1) {
        *(s32 *)((u8 *)arg0 + 0x134) = func_L39_0067F1B0();
        func_003E5360(*(s32 *)((u8 *)arg0 + 0x134));
        func_L01_00516FD8(*(s32 *)((u8 *)arg0 + 0x134), (s32)&D_00247388);
        func_003E8630(D_0024736C, *(s32 *)((u8 *)arg0 + 0x134));
        func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x134), 1, 3);
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x134), mode);
    }
    if (*(s32 *)((u8 *)arg0 + 0x138) == -1) {
        *(s32 *)((u8 *)arg0 + 0x138) = func_L39_0067F1B0();
        func_003E5360(*(s32 *)((u8 *)arg0 + 0x138));
        func_003E8630(D_0024736C, *(s32 *)((u8 *)arg0 + 0x138));
        func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x138), 1, 3);
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x138), mode);
    }
    if (*(s32 *)((u8 *)arg0 + 0x13C) == -1) {
        *(s32 *)((u8 *)arg0 + 0x13C) = func_L39_0067F1B0();
        func_003E5360(*(s32 *)((u8 *)arg0 + 0x13C));
        func_003E8630(D_0024736C, *(s32 *)((u8 *)arg0 + 0x13C));
        func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x13C), 1, 3);
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x13C), mode);
    }
    if (*(s32 *)((u8 *)arg0 + 0x140) == -1) {
        *(s32 *)((u8 *)arg0 + 0x140) = func_L39_0067F1B0();
        func_003E5360(*(s32 *)((u8 *)arg0 + 0x140));
        func_003E8630(D_0024736C, *(s32 *)((u8 *)arg0 + 0x140));
        func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x140), 1, 3);
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x140), mode);
    }
}
/* localdecomp:end func_L39_006850F8 */

/* localdecomp:start func_L39_006852C8 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_006852C8(void *arg0, s32 arg1) {
    s32 v;

    *(s32 *)((u8 *)arg0 + 0x240) = arg1;
    v = 2;
    if (arg1 == 1) {
        v = 1;
    }
    if (*(s32 *)((u8 *)arg0 + 0x130) != -1) {
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x130), v);
    }
    if (*(s32 *)((u8 *)arg0 + 0x134) != -1) {
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x134), v);
    }
    if (*(s32 *)((u8 *)arg0 + 0x138) != -1) {
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x138), v);
    }
    if (*(s32 *)((u8 *)arg0 + 0x13C) != -1) {
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x13C), v);
    }
    if (*(s32 *)((u8 *)arg0 + 0x140) != -1) {
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x140), v);
    }
    return 1;
}
/* localdecomp:end func_L39_006852C8 */

/* localdecomp:start func_L39_00685378 */
void func_L39_00685378(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x130) = -1;
    *(s32 *)((u8 *)arg0 + 0x134) = -1;
    *(s32 *)((u8 *)arg0 + 0x138) = -1;
    *(s32 *)((u8 *)arg0 + 0x13C) = -1;
    *(s32 *)((u8 *)arg0 + 0x140) = -1;
}
/* localdecomp:end func_L39_00685378 */
