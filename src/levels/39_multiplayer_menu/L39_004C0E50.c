#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004C0E50 */
typedef struct C_004C0E50 {
    s32 length;
    u8 *data;
} C_004C0E50;
typedef struct E_004C0E50 {
    u8 _00[0x90];
    s32 conn_id_length;
    u8 conn_id[16];
} E_004C0E50;
typedef struct S_004C0E50 {
    u8 _00[0x30];
    s32 state;
    u8 _34[0x3C - 0x34];
    C_004C0E50 *init_buf;
    s32 init_num;
    s32 init_off;
    u8 _48[0x50 - 0x48];
    E_004C0E50 *s2;
} S_004C0E50;
extern void *func_0011D380(void *, const void *, unsigned int);
extern s32 func_L39_004C6020(S_004C0E50 *);

s32 func_L39_004C0E50(S_004C0E50 *s) {
    u8 *p;

    if (s->state == 0x1040) {
        p = s->init_buf->data;
        *(p++) = 3;
        func_0011D380(p, s->s2->conn_id, (unsigned int)s->s2->conn_id_length);

        s->state = 0x1041;
        s->init_num = s->s2->conn_id_length + 1;
        s->init_off = 0;
    }
    return func_L39_004C6020(s);
}
/* localdecomp:end func_L39_004C0E50 */

INCLUDE_ASM("asm/levels", func_L39_004C0EC8);

/* localdecomp:start func_L39_004C1318 */
typedef struct P_004C1318 {
    u8 pad0[0x6C];
    s32 len;
    u8 data[1];
} P_004C1318;

typedef struct B_004C1318 {
    s32 pad0;
    u8 *buf;
} B_004C1318;

typedef struct S_004C1318 {
    u8 pad0[0x30];
    s32 state;
    u8 pad34[0x3C - 0x34];
    B_004C1318 *b;
    s32 pos;
    u8 pad44[0x50 - 0x44];
    P_004C1318 *p;
} S_004C1318;

extern s32 func_L39_004C52B0(S_004C1318 *, u8 *, s32);
extern s32 func_L39_004C5F70(S_004C1318 *, s32, s32);
extern void func_L39_004C6100(S_004C1318 *, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_11D2EC(void *, void *, s32);

s32 func_L39_004C1318(S_004C1318 *s) {
    u8 *buf = s->b->buf;
    s32 n;

    if (s->state == 0x1060) {
        n = func_L39_004C52B0(s, buf + s->pos, 1 - s->pos);
        if (n < 1 - s->pos) {
            return func_L39_004C5F70(s, 0x6E, n);
        }
        s->pos = 0;
        s->state = 0x1061;
        if (buf[0] != 5) {
            if (buf[0] != 0) {
                func_L39_004C6100(s, 0);
                func_L39_004BC6C8(0x14, 0x6E, 0xD4, 0, 0);
            } else {
                func_L39_004BC6C8(0x14, 0x6E, 0xC8, 0, 0);
            }
            return -1;
        }
    }
    n = func_L39_004C52B0(s, buf + s->pos, s->p->len - s->pos);
    if (n < s->p->len - s->pos) {
        return func_L39_004C5F70(s, 0x6E, n);
    }
    if (func_11D2EC(buf, s->p->data, s->p->len)) {
        func_L39_004C6100(s, 0);
        func_L39_004BC6C8(0x14, 0x6E, 0x88, 0, 0);
        return -1;
    }
    return 1;
}
/* localdecomp:end func_L39_004C1318 */

INCLUDE_ASM("asm/levels", func_L39_004C1478);

INCLUDE_ASM("asm/levels", func_L39_004C1660);

INCLUDE_ASM("asm/levels", func_L39_004C18B8);

INCLUDE_ASM("asm/levels", func_L39_004C19B8);

INCLUDE_ASM("asm/levels", func_L39_004C1BA8);
