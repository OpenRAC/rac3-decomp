#include "common.h"

/* localdecomp:start func_L39_0050D5B0 */
typedef struct { u8 pad[0x10]; char *name; } S_0050D5B0;
extern void func_L39_0050D780(char **);
extern s32 func_L39_004F7648(char *);
extern char *func_L39_004F75B0(char *, s32);
extern char *func_L39_004F7538(char *, char *, s32);
extern char *func_L39_004F7510(char *, char *, s32);
s32 func_L39_0050D5B0(s32 ret, S_0050D5B0 *obj, char *name0, u32 n, char **out) {
    char *buf;
    char *p;
    s32 digits;
    s32 len1;
    s32 len2;
    u32 t;
    char *name = name0;

    buf = name;
    if (obj->name != 0) {
        digits = 0;
        if (n != (u32)-1) {
            digits = 3;
            for (t = n; t > 10; t /= 10) {
                digits++;
            }
        }
        if (digits != 0) {
            func_L39_0050D780(&name);
        }
        len1 = 0;
        if (name != 0) {
            len1 = func_L39_004F7648(name) + 1;
        }
        len2 = func_L39_004F7648(obj->name);
        buf = func_L39_004F75B0(name, len2 + (len1 + digits) + 1);
        if (buf == 0) {
            *out = 0;
            return ret;
        }
        if (len1 != 0) {
            p = buf + (digits + len2);
            func_L39_004F7538(p + 1, buf, len1 + 1);
            *p = '.';
        } else {
            buf[len2 + digits] = 0;
        }
        func_L39_004F7510(buf, obj->name, len2);
        if (n != (u32)-1) {
            digits--;
            buf[len2 + digits] = ']';
            do {
                digits--;
                p = &buf[len2 + digits];
                *p = n % 10 + '0';
                n = n / 10;
            } while (n != 0);
            buf[len2] = '[';
        }
    }
    *out = buf;
    return ret;
}
/* localdecomp:end func_L39_0050D5B0 */

/* localdecomp:start func_L39_0050D780 */
extern void func_L39_004F7620(void *);

void func_L39_0050D780(char **arg0) {
    char *p;
    s32 i;
    s32 len;

    p = *arg0;
    if (p == 0)
        return;
    for (i = 0; (*arg0)[i] != '.' && (*arg0)[i] != 0; i++)
        ;
    if ((*arg0)[i] == 0) {
        func_L39_004F7620(*arg0);
        *arg0 = 0;
    } else {
        len = func_L39_004F7648(*arg0 + i + 1) + 1;
        func_L39_004F7538(*arg0, *arg0 + i + 1, len);
    }
}
/* localdecomp:end func_L39_0050D780 */

INCLUDE_ASM("asm/levels", func_L39_0050D838);

INCLUDE_ASM("asm/levels", func_L39_0050D890);

/* localdecomp:start func_L39_0050D938 */
extern s32 func_L39_0050D890(s32 code);
extern s32 func_L39_0050DE78(void *a0, void *a1);

s32 func_L39_0050D938(void *a0, void *a1)
{
    return func_L39_0050D890(func_L39_0050DE78(a0, a1));
}
/* localdecomp:end func_L39_0050D938 */

/* localdecomp:start func_L39_0050D958 */
extern s32 func_L39_0050D890(s32 code);
extern s32 func_L39_0050DC08(void *a0);

s32 func_L39_0050D958(void *a0)
{
    return func_L39_0050D890(func_L39_0050DC08(a0));
}
/* localdecomp:end func_L39_0050D958 */

/* localdecomp:start func_L39_0050D978 */
extern s32 func_L39_0050D890(s32 code);
extern s32 func_L39_0050DBB0(const void *src, void *dst);

s32 func_L39_0050D978(const void *src, void *dst)
{
    return func_L39_0050D890(func_L39_0050DBB0(src, dst));
}
/* localdecomp:end func_L39_0050D978 */

/* localdecomp:start func_L39_0050D998 */
extern s32 func_L39_0050D890(s32 code);
extern s32 func_L39_0050DF38(const void *input, void *output);

s32 func_L39_0050D998(const void *input, void *output)
{
    return func_L39_0050D890(func_L39_0050DF38(input, output));
}
/* localdecomp:end func_L39_0050D998 */

/* localdecomp:start func_L39_0050D9B8 */
extern s32 func_L39_0050D890(s32 code);
extern s32 func_L39_0050DC88(void *a0, void *a1, void *a2, void *a3);

s32 func_L39_0050D9B8(void *a0, void *a1, void *a2, void *a3)
{
    return func_L39_0050D890(func_L39_0050DC88(a0, a1, a2, a3));
}
/* localdecomp:end func_L39_0050D9B8 */

/* localdecomp:start func_L39_0050D9D8 */
extern s32 func_L39_0050D890(s32 code);
extern s32 func_L39_0050DBC8(void *a0, void *a1, void *a2, void *a3);

s32 func_L39_0050D9D8(void *a0, void *a1, void *a2, void *a3)
{
    return func_L39_0050D890(func_L39_0050DBC8(a0, a1, a2, a3));
}
/* localdecomp:end func_L39_0050D9D8 */

/* localdecomp:start func_L39_0050D9F8 */
extern s32 func_L39_0050DFA0(void *a0, void *a1, void *a2, void *a3);

s32 func_L39_0050D9F8(void *a0, void *a1, void *a2, void *a3)
{
    return func_L39_0050D890(func_L39_0050DFA0(a0, a1, a2, a3));
}
/* localdecomp:end func_L39_0050D9F8 */

/* localdecomp:start func_L39_0050DA18 */
extern s32 func_L39_0050DE20(void *a0, void *a1, void *a2, void *a3);

s32 func_L39_0050DA18(void *a0, void *a1, void *a2, void *a3)
{
    return func_L39_0050D890(func_L39_0050DE20(a0, a1, a2, a3));
}
/* localdecomp:end func_L39_0050DA18 */

/* localdecomp:start func_L39_0050DA38 */
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_0050DB08(void *, void *);
extern s32 func_L39_00510298(void *, void *);
extern s32 func_L39_0050D890(s32);
extern s32 func_L39_005103A0(void *, s32, s32, void **);
extern void func_L39_005102E8(void *);
extern void func_L39_004F7620(void *);

s32 func_L39_0050DA38(s32 a0, s32 a1, s32 a2, void *a3) {
    u8 key[8];
    u8 ctx[0x20];
    void *out;
    s32 r;

    func_L39_004F74E8(key, 0, sizeof(key));
    func_L39_004F74E8(ctx, 0, sizeof(ctx));
    func_L39_0050DB08(key, a3);
    r = func_L39_0050D890(func_L39_00510298(ctx, key));
    if (r == 0) {
        out = 0;
        r = func_L39_0050D890(func_L39_005103A0(ctx, a0, a2, &out));
        if (out != 0) {
            func_L39_004F7620(out);
        }
        func_L39_005102E8(ctx);
    }
    return r;
}
/* localdecomp:end func_L39_0050DA38 */

INCLUDE_ASM("asm/levels", func_L39_0050DB08);

INCLUDE_ASM("asm/levels", func_L39_0050DB28);

/* localdecomp:start func_L39_0050DBB0 */
typedef struct {
    u8 *data;
    u32 remaining;
} Cursor_0050DBB0;
typedef struct {
    u8 prefix[12];
    Cursor_0050DBB0 cursor;
} Input_0050DBB0;

s32 func_L39_0050DBB0(const void *src, void *dst) {
    *(Cursor_0050DBB0 *)dst = ((const Input_0050DBB0 *)src)->cursor;
    return 0;
}
/* localdecomp:end func_L39_0050DBB0 */

/* localdecomp:start func_L39_0050DBC8 */
typedef struct S_0050DBC8 { u8 *p; s32 n; } S_0050DBC8;
extern s32 func_L39_0050CC00(void *, s32, s32, u8 *, s32);

s32 func_L39_0050DBC8(void *a0, void *a1, void *a2, void *a3)
{
    S_0050DBC8 *s = a3;

    if (s == 0 || s->p == 0)
        return 0;
    return func_L39_0050CC00(a0, (s32)a1, (s32)a2, s->p, s->n);
}
/* localdecomp:end func_L39_0050DBC8 */

INCLUDE_ASM("asm/levels", func_L39_0050DC08);
