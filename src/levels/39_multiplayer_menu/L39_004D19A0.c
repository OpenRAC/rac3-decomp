#include "common.h"

/* declared by functions of L39_004D14C8.c, which this file was cut from */
extern u8 D_L39_0046A090[];
extern s32 func_L39_004D0D68(void *, void *);

/* localdecomp:start func_L39_004D19A0 */
typedef struct {
    s32 w[3];
} A_004D19A0;
typedef struct {
    u8 a[8];
    u8 b[8];
    u8 c[8];
} K_004D19A0;
typedef struct {
    u8 b[8];
} B_004D19A0;
typedef struct {
    s32 a;
    s32 b;
} C_004D19A0;

extern A_004D19A0 D_L39_00476068 __attribute__((section(".data")));
extern B_004D19A0 D_L39_00476078 __attribute__((section(".data")));
extern B_004D19A0 D_L39_00476080 __attribute__((section(".data")));
extern u8 D_L39_0046A090[];
extern u8 D_L39_004F7050[];
extern s32 func_L39_004D0D68(void *, void *);
extern s32 func_L39_004D14E0(void *, void *, s32, s32, void *, void *, s32);

static __inline__ void copy_004D19A0(u8 *d, u8 *s, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        d[i] = s[i];
    }
}

s32 func_L39_004D19A0(u8 *a0, u8 *a1, u8 *a2, s32 a3, s32 a4) {
    A_004D19A0 name;
    K_004D19A0 buf;
    C_004D19A0 info;
    B_004D19A0 n1;
    B_004D19A0 n2;
    s32 id1;
    s32 id2;
    s32 ret;

    name = D_L39_00476068;
    n1 = D_L39_00476078;
    n2 = D_L39_00476080;
    copy_004D19A0(buf.a, a0, 8);
    copy_004D19A0(buf.b, a1, 8);
    copy_004D19A0(buf.c, a2, 8);
    info.a = a3;
    info.b = 8;
    id1 = func_L39_004D0D68(D_L39_0046A090, &n1);
    id2 = func_L39_004D0D68(D_L39_0046A090, &n2);
    ret = func_L39_004D14E0(&buf, &name, id1, id2, &info, D_L39_004F7050, a4);
    {
        u8 *p = (u8 *)&buf + sizeof(buf) - 1;
        s32 n = sizeof(buf);

        while (--n >= 0) {
            *p-- = 0;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004D19A0 */
