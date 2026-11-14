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

INCLUDE_ASM("asm/levels", func_L39_0050D780);

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

INCLUDE_ASM("asm/levels", func_L39_0050D9F8);

INCLUDE_ASM("asm/levels", func_L39_0050DA18);

INCLUDE_ASM("asm/levels", func_L39_0050DA38);

INCLUDE_ASM("asm/levels", func_L39_0050DB08);

INCLUDE_ASM("asm/levels", func_L39_0050DB28);

INCLUDE_ASM("asm/levels", func_L39_0050DBB0);

INCLUDE_ASM("asm/levels", func_L39_0050DBC8);

INCLUDE_ASM("asm/levels", func_L39_0050DC08);
