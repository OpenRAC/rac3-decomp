#include "common.h"

/* localdecomp:start func_L39_004CC440 */
typedef struct { s32 n; void *p; } S_004CC440;
extern void *func_0011D534(void *, s32, u32);

void func_L39_004CC440(S_004CC440 *arg0) {
    if (arg0 != 0 && arg0->n > 0) {
        func_0011D534(arg0->p, 0, arg0->n * 4);
        arg0->n = 0;
    }
}
/* localdecomp:end func_L39_004CC440 */

INCLUDE_ASM("asm/levels", func_L39_004CC480);

/* localdecomp:start func_L39_004CC510 */
extern void func_L39_004CC480(void *);
extern void func_L39_004CC538(void *);

void func_L39_004CC510(void *arg0) {
    func_L39_004CC480(arg0);
    func_L39_004CC538(arg0);
}
/* localdecomp:end func_L39_004CC510 */

/* localdecomp:start func_L39_004CC538 */
typedef struct { void *f0; void *f4; } S_004CC538;
extern void func_L39_004BEF28(void *);

void func_L39_004CC538(void *arg0) {
    S_004CC538 *p = arg0;
    if (p != 0) {
        if (p->f4 != 0) {
            func_L39_004BEF28(p->f4);
        }
        func_L39_004BEF28(p);
    }
}
/* localdecomp:end func_L39_004CC538 */

/* localdecomp:start func_L39_004CC588 */
extern void *func_L39_004CC5B8(void);

void *func_L39_004CC588(s32 id) {
    void *r;
    if (id == 0x301) {
        r = func_L39_004CC5B8();
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_004CC588 */

INCLUDE_ASM("asm/levels", func_L39_004CC5B8);

/* localdecomp:start func_L39_004CC710 */
s32 func_L39_004CC710(void) {
    return 7200;
}
/* localdecomp:end func_L39_004CC710 */

/* localdecomp:start func_L39_004CC718 */
extern char D_L39_004657D0[];

void *func_L39_004CC718(void) {
    return D_L39_004657D0;
}
/* localdecomp:end func_L39_004CC718 */

/* localdecomp:start func_L39_004CC728 */
typedef struct S_004CC728 S_004CC728;
typedef struct { u8 pad[8]; void (*fn)(S_004CC728 *); } V_004CC728;
struct S_004CC728 { u8 pad[8]; V_004CC728 *vt; };
extern s32 func_L39_004C24C8(S_004CC728 *);

s32 func_L39_004CC728(S_004CC728 *arg0) {
    if (func_L39_004C24C8(arg0) == 0) {
        return 0;
    }
    arg0->vt->fn(arg0);
    return 1;
}
/* localdecomp:end func_L39_004CC728 */

INCLUDE_ASM("asm/levels", func_L39_004CC770);

/* localdecomp:start func_L39_004CC778 */
/* OpenSSL t1_lib.c's tls1_clear: ssl3_clear(s), then s->version = TLS1_VERSION */
typedef struct S_004CC778 {
    s32 version;
} S_004CC778;

extern void func_L39_004C2648(S_004CC778 *);

void func_L39_004CC778(S_004CC778 *s) {
    func_L39_004C2648(s);
    s->version = 0x301;
}
/* localdecomp:end func_L39_004CC778 */

/* localdecomp:start func_L39_004CC7A8 */
extern void func_L39_004E4CA8(s32);
extern void func_L01_00415DC8(s32);
extern void func_L01_0047DAD0(s32);
extern void func_L39_004E5250(s32);
extern void func_L39_004E52A0(s32);
extern void func_L39_004E4CB8();
extern void func_L39_004E4D18();
extern void func_L39_004E4DC8();
extern void func_L39_004E4E78();
extern void func_L39_004E4ED8();

s32 func_L39_004CC7A8(void) {
    func_L39_004E4CA8((s32)func_L39_004E4CB8);
    func_L01_00415DC8((s32)func_L39_004E4D18);
    func_L01_0047DAD0((s32)func_L39_004E4DC8);
    func_L39_004E5250((s32)func_L39_004E4E78);
    func_L39_004E52A0((s32)func_L39_004E4ED8);
    return 1;
}
/* localdecomp:end func_L39_004CC7A8 */

/* localdecomp:start func_L39_004CC800 */
typedef struct S_004CC800_inner {
    u8 pad0[0x14];
    s32 field14;
} S_004CC800_inner;

typedef struct S_004CC800 {
    s32 pad0;
    S_004CC800_inner *field4;
} S_004CC800;

s32 func_L39_004CC800(S_004CC800 *arg0) {
    return arg0->field4->field14;
}
/* localdecomp:end func_L39_004CC800 */

INCLUDE_ASM("asm/levels", func_L39_004CC810);

INCLUDE_ASM("asm/levels", func_L39_004CCBD8);

INCLUDE_ASM("asm/levels", func_L39_004CCD18);
