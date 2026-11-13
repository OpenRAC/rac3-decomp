#include "common.h"

/* localdecomp:start func_L39_004C2588 */
/* best: 27 diff (3 wordings, all modes same). Retail frame 0x20 with $ra at 0x10 and ld $ra before $s0; body uses $a0 as base and $v0 for field, then move $a0,$v0. Ours: frame 0x10, $v0 base. Looks like a different compiler/flags (@ee29 rejects -fopt-stack). */
typedef struct {
    u8 pad0[0x94];
    void *f94;
    u8 pad98[0x14];
    void *fAC;
    u8 padB0[0x18];
    void *fC8;
    u8 padCC[0x2C];
    void *fF8;
    void *fFC;
} S_004C2588;
typedef struct { u8 pad0[0x54]; S_004C2588 *f54; } T_004C2588;
extern void func_L39_004DE9B8(void *);
extern void func_L39_004BEF28(void *);
extern void func_L39_004C2778(void *);
extern void func_0011D534(void *, s32, s32);

void func_L39_004C2588(T_004C2588 *arg0) {
    if (arg0->f54->fF8 != 0) {
        func_L39_004DE9B8(arg0->f54->fF8);
    }
    if (arg0->f54->fFC != 0) {
        func_L39_004DE9B8(arg0->f54->fFC);
    }
    if (arg0->f54->f94 != 0) {
        func_L39_004BEF28(arg0->f54->f94);
    }
    if (arg0->f54->fAC != 0) {
        func_L39_004BEF28(arg0->f54->fAC);
    }
    if (arg0->f54->fC8 != 0) {
        func_L39_004BEF28(arg0->f54->fC8);
    }
    func_L39_004C2778(arg0);
    func_0011D534(arg0->f54, 0, 0x198);
    func_L39_004BEF28(arg0->f54);
    arg0->f54 = 0;
}
/* localdecomp:end func_L39_004C2588 */

/* localdecomp:start func_L39_004C2648 */
typedef struct S3_004C2648 {
    u8 pad0[0x94];
    u8 *rbuf_buf;
    s32 rbuf_len;
    u8 pad9C[0x10];
    u8 *wbuf_buf;
    s32 wbuf_len;
    u8 padB4[4];
    s32 fB8;
    s32 fBC;
    u8 padC0[8];
    void *fC8;
    u8 padCC[0x2C];
    void *fF8;
    void *fFC;
    u8 pad100[0x14];
    s32 f114;
    s32 f118;
    s32 f11C;
    s32 f120;
    u8 pad124[0x198 - 0x124];
} S3_004C2648;

typedef struct S_004C2648 {
    s32 version;
    u8 pad4[0x48];
    s32 f4C;
    u8 pad50[4];
    S3_004C2648 *s3;
} S_004C2648;

extern void func_L39_004BEF28(void *);
extern void func_L39_004C2778(void *);
extern void func_L39_004C4E68(void *);
extern void *func_0011D534_004C2648(void *, s32, s32);

void func_L39_004C2648(S_004C2648 *s) {
    u8 *rp = s->s3->rbuf_buf;
    u8 *wp = s->s3->wbuf_buf;
    s32 rlen = s->s3->rbuf_len;
    s32 wlen = s->s3->wbuf_len;
    void *a = s->s3->fF8;
    void *b = s->s3->fFC;

    if (s->s3->fC8 != 0) {
        func_L39_004BEF28(s->s3->fC8);
        s->s3->fC8 = 0;
    }
    func_L39_004C2778(s);
    func_0011D534_004C2648(s->s3, 0, sizeof(S3_004C2648));
    s->s3->rbuf_len = rlen;
    s->s3->wbuf_len = wlen;
    s->s3->rbuf_buf = rp;
    s->s3->wbuf_buf = wp;
    s->s3->fF8 = a;
    s->s3->fFC = b;
    if (s->s3->rbuf_buf != 0) {
        func_0011D534_004C2648(s->s3->rbuf_buf, 0, s->s3->rbuf_len);
    }
    func_L39_004C4E68(s);
    s->f4C = 0;
    s->s3->f114 = 0;
    s->s3->f118 = 0;
    s->s3->f11C = 0;
    s->s3->f120 = 0;
    s->version = 0x300;
    s->s3->fB8 = 0;
    s->s3->fBC = 0;
}
/* localdecomp:end func_L39_004C2648 */

INCLUDE_ASM("asm/levels", func_L39_004C2778);

/* localdecomp:start func_L39_004C28F0 */
extern s32 func_L39_004DD5E0(s32);
extern s32 func_L39_004DD4C0(s32);
extern void func_L39_004DD250(s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004C28F0(s32 *arg0, s32 arg1) {
    s32 p = func_L39_004DD5E0(arg1);
    if (p == 0 || func_L39_004DD4C0(p) == 0) {
        func_L39_004BC6C8(0x14, 0xD6, 0x805, 0, 0);
        return 0;
    }
    if (*arg0 != 0) {
        func_L39_004DD250(*arg0);
    }
    *arg0 = p;
    return 1;
}
/* localdecomp:end func_L39_004C28F0 */

INCLUDE_ASM("asm/levels", func_L39_004C2978);

INCLUDE_ASM("asm/levels", func_L39_004C2C10);

INCLUDE_ASM("asm/levels", func_L39_004C3000);
