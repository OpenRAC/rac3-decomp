#include "common.h"

/* localdecomp:start func_L39_00500A90 */
extern s32 func_L39_00500C78(void *, s32, s32);
extern s32 func_L39_00506198(void);
extern s32 func_L39_005061B8(void);
extern s32 func_11C090(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
s32 func_L39_00500A90(void *self, s32 a1, s32 a2, long a3) {
    void *p = ((void **)self)[3];
    s32 r = 0;
    if (a1 == 2) {
        if (a3 == 3) {
            r = func_L39_00500C78(p, func_L39_00506198(), 1);
            if (r == 0) {
                func_L39_004BC6C8(0xB, 0xD7, 0x9C, 0, 0);
            } else {
                r = func_L39_00500C78(p, func_11C090(func_L39_005061B8()), 1);
            }
        } else {
            r = func_L39_00500C78(p, a2, a3);
        }
    }
    return r;
}
/* localdecomp:end func_L39_00500A90 */

/* localdecomp:start func_L39_00500B50 */
extern void *func_L39_004BEED8(s32 size);
extern s32 func_L39_004DB110(void);
extern void func_L39_004BEF28(void *p);
typedef struct S_00500B50 { s32 a0, a4, a8, aC, a10; } S_00500B50;
s32 func_L39_00500B50(void *self) {
    S_00500B50 *p = func_L39_004BEED8(0x14);
    if (p == 0) return 0;
    p->a0 = func_L39_004DB110();
    if (p->a0 == 0) { func_L39_004BEF28(p); return 0; }
    p->a4 = 0; p->a8 = 0; p->aC = 0; p->a10 = 0;
    ((s32 *)self)[3] = (s32)p;
    return 1;
}
/* localdecomp:end func_L39_00500B50 */

INCLUDE_ASM("asm/levels", func_L39_00500BC8);

INCLUDE_ASM("asm/levels", func_L39_00500C78);

/* localdecomp:start func_L39_00500EC8 */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_120884(const char *);
extern s32 func_120048(char *, const char *, ...);
extern s32 func_126A58(const char *, void *);
__asm__(".extern D_L39_004794A0, 16");
extern char D_L39_004794A0[1];
extern char D_L39_004794A8[];
extern char D_L39_004794B8[];
typedef struct S_004DB110_00500EC8 {
    s32 unk0;
    char *buf;
} S_004DB110_00500EC8;
typedef struct L_00500EC8 {
    s32 unk0;
    s32 count;
    char **names;
    s32 *values;
    s32 capacity;
} L_00500EC8;
typedef struct T_00500EC8 {
    s32 unk0;
    s32 unk4;
} T_00500EC8;
typedef struct S_00500EC8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    L_00500EC8 *list;
    T_00500EC8 *unk10;
} S_00500EC8;
typedef struct A_00500EC8 {
    s32 unk0;
    void *unk4;
    char pad8[0x14];
    char unk1C[0x14];
    void *unk30;
    char pad34[0x1C];
} A_00500EC8;
typedef struct C_00500EC8 {
    s32 mode;
    void *arg;
} C_00500EC8;

extern void func_L39_004DB168(S_004DB110_00500EC8 *);
extern s32 func_L39_004DB1C0(S_004DB110_00500EC8 *, s32);
extern long func_L39_004F1800(void *);
extern s32 func_L39_00501200(S_00500EC8 *, char *, s32);
extern s32 func_L39_004BECC0(s32, s32, char *, s32);
extern s32 *func_L39_004BCDE0(s32, C_00500EC8 *);
s32 func_L39_00500EC8(S_00500EC8 *self, s32 mode, void *arg, s32 *out) {
    A_00500EC8 a;
    char st[0x70];
    C_00500EC8 c;
    s32 result;
    long id;
    S_004DB110_00500EC8 *ctx;
    L_00500EC8 *list;
    s32 i;
    s32 j;
    s32 *r;

    ctx = 0;
    result = 0;
    if (arg == 0) {
        return 0;
    }
    c.mode = mode;
    if (mode == 1) {
        a.unk30 = arg;
        a.unk4 = a.unk1C;
        c.arg = &a;
    } else if (mode != 2) {
        func_L39_004BC6C8(0xB, 0xD8, 0xA5, 0, 0);
        goto end;
    }
    ctx = (S_004DB110_00500EC8 *)func_L39_004DB110();
    if (ctx == 0) {
        func_L39_004BC6C8(0xB, 0xD8, 0x807, 0, 0);
        goto end;
    }
    list = self->list;
    id = func_L39_004F1800(arg);
    for (i = 0; i < list->count; i++) {
        if (func_L39_004DB1C0(ctx, func_120884(list->names[i]) + 0x11) == 0) {
            func_L39_004BC6C8(0xB, 0xD8, 0x21, 0, 0);
            goto end;
        }
        j = 0;
        for (;;) {
            func_120048(ctx->buf, D_L39_004794A8, list->names[i], id, D_L39_004794A0, j);
            j++;
            if (func_126A58(ctx->buf, st) < 0) {
                break;
            }
            if (mode == 1) {
                if (func_L39_00501200(self, ctx->buf, list->values[i]) == 0) {
                    break;
                }
            }
        }
        func_L39_004BECC0(5, 0xB, D_L39_004794B8, 0x135);
        r = func_L39_004BCDE0(self->unk10->unk4, &c);
        func_L39_004BECC0(6, 0xB, D_L39_004794B8, 0x138);
        if (r != 0) {
            result = 1;
            out[0] = r[0];
            out[1] = r[1];
            goto end;
        }
    }
end:
    if (ctx != 0) {
        func_L39_004DB168(ctx);
    }
    return result;
}
/* localdecomp:end func_L39_00500EC8 */
