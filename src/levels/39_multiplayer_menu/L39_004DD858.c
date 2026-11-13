#include "common.h"

/* declared by functions of L39_004D7740.c, which this file was cut from */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void *func_L39_004DBA08(void);

/* localdecomp:start func_L39_004DD858 */
void func_L39_004BC6C8(s32, s32, s32, s32, s32);
void *func_L39_004DBA08(void);
s32 func_L39_004DD858(s32 arg0) {
    s32 (*fn)(s32) = *(s32 (**)(s32))((u8 *)func_L39_004DBA08() + 0x28);
    if (fn == 0) {
        func_L39_004BC6C8(0xA, 0x6B, 0xE, 0, 0);
        return -1;
    }
    return fn(arg0);
}
/* localdecomp:end func_L39_004DD858 */

/* localdecomp:start func_L39_004DD8B0 */
s32 func_L39_004DD8B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 (*f)(s32, s32, s32, s32) = *(s32 (**)(s32, s32, s32, s32))((char *)func_L39_004DBA08() + 0x2C);

    if (f == 0) {
        func_L39_004BC6C8(0xA, 0x6A, 0xE, 0, 0);
        return -1;
    }
    return f(arg0, arg1, arg2, arg3);
}
/* localdecomp:end func_L39_004DD8B0 */

INCLUDE_ASM("asm/levels", func_L39_004DD938);

INCLUDE_ASM("asm/levels", func_L39_004DDA88);

INCLUDE_ASM("asm/levels", func_L39_004DDAE8);

INCLUDE_ASM("asm/levels", func_L39_004DDBF0);

INCLUDE_ASM("asm/levels", func_L39_004DDD68);

INCLUDE_ASM("asm/levels", func_L39_004DDDD8);

INCLUDE_ASM("asm/levels", func_L39_004DDEE0);

INCLUDE_ASM("asm/levels", func_L39_004DDFB0);

INCLUDE_ASM("asm/levels", func_L39_004DDFC8);

INCLUDE_ASM("asm/levels", func_L39_004DE050);

INCLUDE_ASM("asm/levels", func_L39_004DE0C8);

INCLUDE_ASM("asm/levels", func_L39_004DE0F0);

INCLUDE_ASM("asm/levels", func_L39_004DE120);

/* localdecomp:start func_L39_004DE150 */
typedef struct S_004DE150 {
    u64 pid;
    u64 err_buffer[16];
    char *err_data[16];
    s32 err_data_flags[16];
    char *err_file[16];
    s32 err_line[16];
    s32 top;
    s32 bottom;
} S_004DE150;

extern S_004DE150 *func_L39_004BC8B0(void);
extern char D_L39_004762B0[];
extern char D_L39_004762B8[];

u64 func_L39_004DE150(s32 inc, char **file, s32 *line, char **data, s32 *flags) {
    S_004DE150 *es;
    s32 i;
    u64 ret;

    es = func_L39_004BC8B0();

    if (es->bottom == es->top) {
        return 0;
    }
    i = (es->bottom + 1) % 16;

    ret = es->err_buffer[i];
    if (inc) {
        es->bottom = i;
        es->err_buffer[i] = 0;
    }

    if ((file != 0) && (line != 0)) {
        if (es->err_file[i] == 0) {
            *file = D_L39_004762B0;
            *line = 0;
        } else {
            *file = es->err_file[i];
            *line = es->err_line[i];
        }
    }

    if (data != 0) {
        if (es->err_data[i] == 0) {
            *data = D_L39_004762B8;
            if (flags != 0) {
                *flags = 0;
            }
        } else {
            *data = es->err_data[i];
            if (flags != 0) {
                *flags = es->err_data_flags[i];
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004DE150 */

/* localdecomp:start func_L39_004DE280 */
extern char D_L39_004762C0[];
extern void *func_L39_004DBA08(void);
extern s32 func_L39_004BEDB0(void);
extern s32 func_L39_004BECC0(void);
extern s32 func_L39_004BCD28(s32, void *);
extern void func_L39_004BCBB0(void *);
extern void func_L39_004DDFC8(s32);

typedef struct {
    char _p0[0x8];
    s32 f8;
} S_004DE280;
typedef struct {
    char _p0[0x30];
    long f30;
} S2_004DE280;
typedef struct {
    long f0;
    char _p8[0x188];
} B_004DE280;

void func_L39_004DE280(s32 arg0) {
    B_004DE280 buf;
    S_004DE280 *p = (S_004DE280 *)func_L39_004DBA08();
    s32 r;

    if (p->f8 != 0) {
        if (arg0 == 0) {
            arg0 = func_L39_004BEDB0();
        }
        buf.f0 = arg0;
        ((void (*)(s32, s32, char *, s32))func_L39_004BECC0)(9, 1, D_L39_004762C0, 0x27C);
        r = func_L39_004BCD28(p->f8, &buf);
        if (((S2_004DE280 *)p->f8)->f30 == 0) {
            func_L39_004BCBB0((S2_004DE280 *)p->f8);
            p->f8 = 0;
        }
        ((void (*)(s32, s32, char *, s32))func_L39_004BECC0)(10, 1, D_L39_004762C0, 0x28E);
        if (r != 0) {
            func_L39_004DDFC8(r);
        }
    }
}
/* localdecomp:end func_L39_004DE280 */

INCLUDE_ASM("asm/levels", func_L39_004DE348);

INCLUDE_ASM("asm/levels", func_L39_004DE458);

/* localdecomp:start func_L39_004DE550 */
extern s32 func_L39_004DE458(void *);
extern void func_L39_004BEF28(void *);
extern void *func_L39_004BEED8(s32);

void *func_L39_004DE550(void) {
    void *p = func_L39_004BEED8(0x90);
    s32 *obj = p;
    if (obj != 0) {
        obj[0] = 0; obj[0x78 / 4] = 0; obj[0x74 / 4] = 0; obj[0x7C / 4] = 0; obj[0x80 / 4] = 0; *(s64 *)&obj[0x88 / 4] = 0;
        if (func_L39_004DE458(obj) != 0) return obj;
    }
    if (p != 0) func_L39_004BEF28(p);
    func_L39_004BC6C8(6, 0x6D, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004DE550 */

INCLUDE_ASM("asm/levels", func_L39_004DE5D0);

INCLUDE_ASM("asm/levels", func_L39_004DE650);

/* localdecomp:start func_L39_004DE6D0 */
extern void *func_0011D380(void *, const void *, unsigned int);

typedef struct S_004DE6D0 S_004DE6D0;
typedef struct {
    s32 f0;
    s32 f4;
    char _p8[0x14 - 0x8];
    void (*f14)(S_004DE6D0 *, s32, u8 *, s32);
} V_004DE6D0;
struct S_004DE6D0 {
    V_004DE6D0 *f0;
    s32 f4;
    s32 f8;
    char _pC[0x4C - 0xC];
    u8 f4C[32];
};

void func_L39_004DE6D0(S_004DE6D0 *self, s32 out, s32 *outLen, u8 *in, s32 len) {
    s32 i, j, bl;

    i = self->f8;
    bl = self->f0->f4;
    *outLen = 0;
    if ((len == 0) && (i != bl)) {
        return;
    }
    if (i != 0) {
        if (i + len < bl) {
            func_0011D380((u8 *)(i + (s32)self) + 0x4C, in, len);
            self->f8 += len;
            return;
        } else {
            j = bl - i;
            if (j != 0) {
                func_0011D380((u8 *)(i + (s32)self) + 0x4C, in, j);
            }
            self->f0->f14(self, out, self->f4C, bl);
            len -= j;
            in += j;
            out += bl;
            *outLen += bl;
        }
    }
    i = len % bl;
    len -= i;
    if (len > 0) {
        self->f0->f14(self, out, in, len);
        *outLen += len;
    }
    if (i != 0) {
        func_0011D380(self->f4C, &(in[len]), i);
    }
    self->f8 = i;
}
/* localdecomp:end func_L39_004DE6D0 */

INCLUDE_ASM("asm/levels", func_L39_004DE828);

INCLUDE_ASM("asm/levels", func_L39_004DE868);
