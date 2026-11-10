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

INCLUDE_ASM("asm/levels", func_L39_004C1318);

INCLUDE_ASM("asm/levels", func_L39_004C1478);

INCLUDE_ASM("asm/levels", func_L39_004C1660);

INCLUDE_ASM("asm/levels", func_L39_004C18B8);

INCLUDE_ASM("asm/levels", func_L39_004C19B8);

INCLUDE_ASM("asm/levels", func_L39_004C1BA8);
