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
extern S_00683550 *func_L39_0067EE40(void *, void *);
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L39_00683718 */
typedef struct {
    char _p0[0x64];
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
} S_683718;

/* from rac4-decomp's func_L00_004F7328 */
void func_L39_00683718(S_683718 *arg0) {
    arg0->f64 = -1;
    arg0->f68 = -1;
    arg0->f6C = -1;
    arg0->f70 = -1;
}
/* localdecomp:end func_L39_00683718 */

/* localdecomp:start func_L39_00683730 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_00683730(void *arg0, s32 arg1) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x64);

    if (v != -1) {
        return func_003E7F20(v, arg1);
    }
    return 0;
}
/* localdecomp:end func_L39_00683730 */

/* localdecomp:start func_L39_00683760 */
extern s32 func_L01_00518010(s32, s32);
extern s32 func_003E8898(s32, f32, f32);

s32 func_L39_00683760(S_00683550 *o, s32 arg1, f32 a, f32 b) {
    if (o->f64 != -1) {
        if (func_L01_00518010(o->f64, arg1) != 0) {
            if (arg1 != 0) {
                return func_003E8898(o->f64, a, b);
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00683760 */

/* localdecomp:start func_L39_006837E8 */
s32 func_L39_006837E8(void *arg0, s32 arg1, s32 arg2) {
    s32 v;
    *(s32 *)((u8 *)arg0 + 0x74) = arg1;
    v = *(s32 *)((u8 *)arg0 + 0x64);
    if (v != -1) {
        return func_L01_00516C78(v, arg1, arg2);
    }
    return 0;
}
/* localdecomp:end func_L39_006837E8 */

/* localdecomp:start func_L39_00683818 */
extern s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00683818(void *arg0, s32 arg1, s32 arg2) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x64);

    if (v != -1) {
        return func_L01_00516AA0(v, arg1, arg2);
    }
    return 0;
}
/* localdecomp:end func_L39_00683818 */

INCLUDE_ASM("asm/levels", func_L39_00683848);

/* localdecomp:start func_L39_00683A30 */
extern u8 D_L39_0047BE48[];

void *func_L39_00683A30(void *self, void *o) {
    func_L39_0067EE40(self, o);
    *(void **)((u8 *)self + 0x60) = D_L39_0047BE48;
    *(s32 *)((u8 *)self + 0xB4) = -1;
    *(s32 *)((u8 *)self + 0xB8) = -1;
    *(s32 *)((u8 *)self + 0xBC) = -1;
    *(u8 *)((u8 *)self + 0x64) = 0;
    *(s32 *)((u8 *)self + 0xC4) = 0;
    *(s32 *)((u8 *)self + 0xC8) = 0x8066CCFF;
    *(u8 *)((u8 *)self + 0xCC) = 0;
    return self;
}
/* localdecomp:end func_L39_00683A30 */

/* localdecomp:start func_L39_00683A90 */
extern u8 D_L39_0047BE48[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00683A90(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047BE48;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00683A90 */

/* localdecomp:start func_L39_00683AB8 */
extern s32 func_L01_00516C78(s32, s32, s32);

s32 func_L39_00683AB8(void *arg0, s32 arg1, s32 arg2) {
    s32 var_s2 = 0;

    if (*(s32 *)((u8 *)arg0 + 0xB4) != -1) {
        var_s2 = func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0xB4), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0xB8) != -1) {
        var_s2 |= func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0xB8), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0xBC) != -1) {
        var_s2 |= func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0xBC), arg1, arg2);
    }
    return var_s2 != 0;
}
/* localdecomp:end func_L39_00683AB8 */

/* localdecomp:start func_L39_00683B50 */
s32 func_L39_00683B50(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0xCC) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00683B50 */

/* localdecomp:start func_L39_00683B60 */
extern s32 func_L39_00611628(s32);

s32 func_L39_00683B60(void *arg0, s32 *out) {
    s32 r = 0;
    s32 id;

    out[2] = 0;
    out[3] = 0;
    out[0] = 0;
    out[1] = 0;
    id = *(s32 *)((u8 *)arg0 + 0xBC);
    if (id != -1) {
        r = func_L39_00611628(id);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00683B60 */

/* localdecomp:start func_L39_00683BA8 */
s32 func_L01_00517538(s32, f32, f32);

s32 func_L39_00683BA8(void *arg0, f32 fa, f32 fb) {
    s32 r;

    r = 0;
    if (*(s32 *)((u8 *)arg0 + 0xB4) != -1) {
        r = func_L01_00517538(*(s32 *)((u8 *)arg0 + 0xB4), fa, fb);
    }
    if (*(s32 *)((u8 *)arg0 + 0xB8) != -1) {
        r |= func_L01_00517538(*(s32 *)((u8 *)arg0 + 0xB8), fa, fb);
    }
    if (*(s32 *)((u8 *)arg0 + 0xBC) != -1) {
        r |= func_L01_00517538(*(s32 *)((u8 *)arg0 + 0xBC), fa, fb);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00683BA8 */

/* localdecomp:start func_L39_00683C40 */
s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00683C40(void *arg0, s32 arg1, s32 arg2) {
    s32 r;

    r = 0;
    if (*(s32 *)((u8 *)arg0 + 0xB4) != -1) {
        r = func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xB4), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0xB8) != -1) {
        r |= func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xB8), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0xBC) != -1) {
        r |= func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xBC), arg1, arg2);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00683C40 */

/* localdecomp:start func_L39_00683CD8 */
s32 func_L39_00683CD8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0xC8) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00683CD8 */

/* localdecomp:start func_L39_00683CE8 */
typedef struct {
    u8 pad0[0x48];
    s32 f48;
    f32 f4C;
    u8 pad50[0x14];
    u8 name[0x50];
    u8 padB4[0x10];
    s32 fC4;
} S_00683CE8;

extern void func_00120D28(u8 *, s32, s32);
extern s32 func_00120884(u8 *);
extern void func_0038E150(s32);
extern s32 func_0038E548(u8 *, s32, f32);
extern f32 D_L39_00245C38;
__asm__(".extern D_L39_00245C38, 16");

void func_L39_00683CE8(S_00683CE8 *o, s32 arg1) {
    s32 i;
    s32 len;

    func_00120D28(o->name, arg1, 0x50);
    o->name[0x4F] = 0;
    i = func_00120884(o->name);
    if (i != 0) {
        i--;
        while (o->name[i] == ' ' && !(o->name[(i > 0) * (i - 1)] & 0x80)) {
            i--;
        }
        o->name[i + 1] = 0;
    }
    if (o->f48 != 0) {
        func_0038E150(o->fC4 == 1);
        len = func_00120884(o->name);
        if (o->f4C < (f32)func_0038E548(o->name, func_00120884(o->name), 1.0f) * (1.0f / D_L39_00245C38)) {
            do {
                o->name[len - 1] = '.';
                o->name[len] = '.';
                o->name[len + 1] = '.';
                o->name[len + 2] = 0;
                len--;
            } while (o->f4C < (f32)func_0038E548(o->name, func_00120884(o->name), 1.0f) * (1.0f / D_L39_00245C38));
        }
    }
}
/* localdecomp:end func_L39_00683CE8 */

INCLUDE_ASM("asm/levels", func_L39_00683EB8);
