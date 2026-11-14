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

INCLUDE_ASM("asm/levels", func_L39_004C27E0);

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

INCLUDE_ASM("asm/levels", func_L39_004C29F0);

INCLUDE_ASM("asm/levels", func_L39_004C2C10);

/* localdecomp:start func_L39_004C2D18 */
typedef struct {
    u8 pad0[8];
    s64 f8;
} S_004C2D18;

s32 func_L39_004C2D18(S_004C2D18 *a, u8 *out) {
    if (out != 0) {
        s64 v = a->f8;
        if ((v & 0xFF000000) != 0x3000000) {
            return 0;
        }
        out[1] = v;
        out[0] = v >> 8;
    }
    return 2;
}
/* localdecomp:end func_L39_004C2D18 */

LINKER_REMNANT("asm/levels", func_L39_004C2D58);

/* localdecomp:start func_L39_004C2D60 */
typedef struct {
    u8 pad0[0x10C];
    s32 alert_dispatch;
} S3_004C2D60;
typedef struct {
    u8 pad0[0x2C];
    s32 shutdown;
    s32 state;
    u8 pad34[0x20];
    S3_004C2D60 *s3;
} S_004C2D60;

extern s32 func_L39_004C3E28(void *, s32, s32, s32);
extern s32 func_L39_004C9F50(void *, s32, s32);
extern s32 func_L39_004CA000(void *);
extern s32 func_L39_004C9678(void *, s32, void *, s32);

s32 func_L39_004C2D60(S_004C2D60 *s) {
    s32 ret;

    if ((func_L39_004C3E28(s, 0x20, 0, 0) & 0x20000)
        || (s->state == 0x4000 && (func_L39_004C3E28(s, 0x20, 0, 0) & 0x40000))) {
        s->shutdown = 3;
        return 1;
    }
    if (!(s->shutdown & 1)) {
        s->shutdown |= 1;
        ret = func_L39_004C9F50(s, 1, 0);
        if (ret <= 0) {
            return ret;
        }
    } else if (s->s3->alert_dispatch) {
        ret = func_L39_004CA000(s);
        if (ret <= 0) {
            return ret;
        }
    }
    if ((s->shutdown & 1) && (func_L39_004C3E28(s, 0x20, 0, 0) & 0x40000)) {
        return 1;
    }
    if (!(s->shutdown & 2)) {
        ret = func_L39_004C9678(s, 0, 0, 0);
        if (ret <= 0) {
            return ret;
        }
    }
    if (s->shutdown == 3 && !s->s3->alert_dispatch) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_004C2D60 */

/* localdecomp:start func_L39_004C2EA8 */
typedef struct {
    s64 flags;
    s32 delay_buf_pop_ret;
    u8 padC[0x114 - 0xC];
    s32 renegotiate;
} S3_004C2EA8;
typedef struct {
    u8 pad0[0x10];
    void *wbio;
    void *bbio;
    s32 rwstate;
    u8 pad1C[0x54 - 0x1C];
    S3_004C2EA8 *s3;
} S_004C2EA8;

extern s32 *func_0011A6E0(void);
extern s32 func_L39_004C31D8(void *);
extern s32 func_L39_004C91C0(void *, s32, const void *, s32);
extern s64 func_L39_004DAE48(void *, s32, s32, void *);

s32 func_L39_004C2EA8(S_004C2EA8 *s, const void *buf, s32 len) {
    s32 ret, n;

    *func_0011A6E0() = 0;
    if (s->s3->renegotiate) {
        func_L39_004C31D8(s);
    }
    if ((s->s3->flags & 4) && s->wbio == s->bbio) {
        if (s->s3->delay_buf_pop_ret == 0) {
            ret = func_L39_004C91C0(s, 0x17, buf, len);
            if (ret <= 0) {
                return ret;
            }
            s->s3->delay_buf_pop_ret = ret;
        }
    flush:
        s->rwstate = 2;
        n = func_L39_004DAE48(s->wbio, 0xB, 0, 0);
        if (n <= 0) {
            return n;
        }
        s->rwstate = 1;
        func_L39_004C4E68(s);
        s->s3->flags &= ~4;
        ret = s->s3->delay_buf_pop_ret;
        s->s3->delay_buf_pop_ret = 0;
    } else {
        ret = func_L39_004C91C0(s, 0x17, buf, len);
        if (ret <= 0) {
            return ret;
        }
        if ((s->s3->flags & 4) && s->wbio == s->bbio) {
            s->s3->delay_buf_pop_ret = ret;
            goto flush;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004C2EA8 */

/* localdecomp:start func_L39_004C3000 */
typedef struct {
    u8 pad0[0x114];
    s32 renegotiate;
    u8 pad118[8];
    s32 in_read_app_data;
} S3_004C3000;
typedef struct {
    u8 pad0[0x1C];
    s32 in_handshake;
    u8 pad20[0x54 - 0x20];
    S3_004C3000 *s3;
} S_004C3000;

extern s32 *func_0011A6E0(void);
extern s32 func_L39_004C31D8(void *);
extern s32 func_L39_004C9678(void *, s32, void *, s32);
extern long func_L39_004DE0F0(void);

s32 func_L39_004C3000(S_004C3000 *s, void *buf, s32 len) {
    s32 ret;

    *func_0011A6E0() = 0;
    if (s->s3->renegotiate) {
        func_L39_004C31D8(s);
    }
    s->s3->in_read_app_data = 1;
    ret = func_L39_004C9678(s, 0x17, buf, len);
    if (ret == -1 && s->s3->in_read_app_data == 0) {
        func_L39_004DE0F0();
        s->s3->in_read_app_data = 0;
        s->in_handshake++;
        ret = func_L39_004C9678(s, 0x17, buf, len);
        s->in_handshake--;
    } else {
        s->s3->in_read_app_data = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_004C3000 */

/* localdecomp:start func_L39_004C30E0 */
typedef struct {
    s32 type;
    u32 length;
    s32 off;
    u8 *data;
} R_004C30E0;
typedef struct {
    u8 pad0[0xB4];
    R_004C30E0 rrec;
} S3_004C30E0;
typedef struct {
    u8 pad0[0x54];
    S3_004C30E0 *s3;
} S_004C30E0;

extern void *func_0011D380(void *, const void *, unsigned int);

s32 func_L39_004C30E0(S_004C30E0 *s, u8 *buf, u32 len) {
    R_004C30E0 *rr = &s->s3->rrec;
    u32 n;

    if (rr->length == 0 || rr->type != 0x17) {
        n = func_L39_004C3000((void *)s, buf, 1);
        if ((s32)n <= 0) {
            return n;
        }
        rr->length++;
        rr->off--;
    }
    n = len;
    if (rr->length < n) {
        n = rr->length;
    }
    func_0011D380(buf, rr->data + rr->off, n);
    return n;
}
/* localdecomp:end func_L39_004C30E0 */
