#include "common.h"

/* localdecomp:start func_L39_004EAD18 */
typedef struct {
    u8 pad0[0x44];
    u32 f44;
    u8 pad48[4];
    u32 f4C;
    u8 pad50[0xC];
    u8 *f5C;
} S2_004EAD18;
typedef struct {
    u8 pad0[0x50];
    S2_004EAD18 *f50;
    u8 pad54[0x1C];
    void *f70;
    u8 pad74[8];
    void *f7C;
} S_004EAD18;
extern u32 func_L39_004DE908(void *);
extern void func_L39_00504A30(void *, u8 *, u8 *, s32);

void func_L39_004EAD18(S_004EAD18 *s, s32 send) {
    void *ctx;
    unsigned long n;

    if (send) {
        ctx = s->f7C;
        n = s->f50->f4C;
    } else {
        ctx = s->f70;
        n = s->f50->f44;
    }
    if (ctx == 0) {
        return;
    }
    if (func_L39_004DE908(ctx) == 8) {
        n = (n + 7) / 8 * 8;
    }
    func_L39_00504A30(ctx, s->f50->f5C, s->f50->f5C, n);
}
/* localdecomp:end func_L39_004EAD18 */

/* localdecomp:start func_L39_004EADC0 */
typedef struct {
    u8 pad0[0x48];
    s32 f48;
    s32 pad4C;
    s32 f50;
    s32 f54;
    s32 f58;
    u8 pad5C[0x64 - 0x5C];
    s32 f64;
    s32 f68;
    u8 pad6C[0xD8 - 0x6C];
    u64 fD8;
    u64 fE0;
} S2_004EADC0;

typedef struct {
    u8 pad0[0x50];
    S2_004EADC0 *s2;
    u8 pad54[0x6C - 0x54];
    void *read_ctx;
    void *enc;
    void *pad74;
    void *write_ctx;
} S_004EADC0;

extern s32 func_L39_004DD690(void *, void *);
extern s32 func_L39_004DE918(void *);
extern void func_L39_004DD778(void *, void *, s32);
extern void func_L39_004DD7A8(void *, void *, void *);

void func_L39_004EADC0(S_004EADC0 *s, u8 *md, s32 send) {
    void *c;
    u8 sequence[4], *p, *sec, *act;
    u64 seq;
    u32 len;

    if (send) {
        c = s->write_ctx;
        seq = s->s2->fE0;
        sec = (u8 *)s->s2->f68;
        len = s->s2->f50;
        act = (u8 *)s->s2->f58;
    } else {
        c = s->read_ctx;
        seq = s->s2->fD8;
        sec = (u8 *)s->s2->f64;
        len = s->s2->f48;
        act = (u8 *)s->s2->f54;
    }
    p = sequence;
    *(p++) = (u8)((seq >> 24) & 0xff);
    *(p++) = (u8)((seq >> 16) & 0xff);
    *(p++) = (u8)((seq >> 8) & 0xff);
    *(p++) = (u8)(seq & 0xff);
    func_L39_004DD690(c, 0);
    func_L39_004DD778(c, sec, func_L39_004DE918(s->enc));
    func_L39_004DD778(c, act, len);
    func_L39_004DD778(c, sequence, 4);
    func_L39_004DD7A8(c, md, 0);
}
/* localdecomp:end func_L39_004EADC0 */
