#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 8010A8.c's earlier functions (tools/port_from_us.py) */
extern int func_00801080(void);
extern void func_00801090(void);
extern void func_00801138(void);
extern int func_008014A0(int);
typedef int (*putc_fn_8015A0)(void *, int *, int);
extern int func_008024B8_008015A0(void *, void *, int *, const char *, ...);
extern int func_00801510_008015A0(unsigned long);
typedef int (*putc_fn_801778)(void *, int *, int);
typedef char *va_list_801778;
extern int func_008015A0(putc_fn_801778, void *, int *, double);
#define VA_ARG_801778(ap, T) (*(T *)((ap += 8) - 8))
#define ISDIGIT_801778(c) ((unsigned)((unsigned char)(c) - '0') < 10)

/* localdecomp:start func_00802490 */
extern void func_008014D8(int);
int func_00802490(void *ctx, int unused, int c) {
    if (c) func_008014D8(c);
    return 1;
}
/* localdecomp:end func_00802490 */

/* localdecomp:start func_008024B8 */
/* Sony 2.9-ee library code: varargs wrapper around the printf core (func_00801778) that
   takes the space left from *p and subtracts what was written. va_start is written out the
   way GCC 2.95's va-mips.h does it for EABI single-float with 64-bit registers. */
typedef int (*putc_fn_8024B8)(void *, unsigned int *, int);
typedef char *va_list_8024B8;
extern int func_00801778_008024B8(putc_fn_8024B8, void *, unsigned int, const char *, va_list_8024B8);
int func_008024B8(putc_fn_8024B8 out, void *ctx, unsigned int *p, const char *fmt, ...) {
    va_list_8024B8 ap;
    int n;
    ap = (char *)__builtin_next_arg(fmt)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    n = func_00801778_008024B8(out, ctx, *p, fmt, ap);
    *p -= n;
    return n;
}
/* localdecomp:end func_008024B8 */

/* localdecomp:start func_00802508 */
/* Sony 2.9-ee library code: printf to the SIO console, through the printf core with
   func_00802490 as the output callback and no size limit. va_start as in func_008024B8. */
typedef int (*putc_fn_802508)(void *, unsigned int *, int);
typedef char *va_list_802508;
extern int func_00802588(void);
extern void func_008025D8(void);
extern int func_00801778_00802508(putc_fn_802508, void *, unsigned int, const char *, va_list_802508);
void func_00802508(const char *fmt, ...) {
    int ctx = 0;
    int r;
    va_list_802508 ap;
    r = func_00802588();
    ap = (char *)__builtin_next_arg(fmt)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    func_00801778_00802508((putc_fn_802508)func_00802490, &ctx, (unsigned int)-1, fmt, ap);
    if (r)
        func_008025D8();
}
/* localdecomp:end func_00802508 */

ASM_FUNC("asm/i5bootn/handwritten", func_00802588);

ASM_FUNC("asm/i5bootn/handwritten", func_008025D8);

LINKER_REMNANT("asm/i5bootn/remnants", func_008025F0);
