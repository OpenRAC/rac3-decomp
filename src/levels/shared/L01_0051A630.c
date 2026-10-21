#include "common.h"

typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
typedef struct { u8 b[16]; } V16_003E6F50;

/* localdecomp:start func_L01_0051A630 */

extern u8 D_L01_001E2454;
extern void *func_L01_00519B90(HT_8 *, u32);
s32 func_L01_0051A630(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_L01_00519B90(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_L01_001E2454) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051A630 */

/* localdecomp:start func_L01_0051A700 */
extern s32 func_L01_0051A700(u8 *p, s32 a, s32 b);
extern void func_003EDAD0(void *, s32, s32);
extern s32 D_L01_001DC1E0_0051A700;

s32 func_L01_0051A700(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1E0_0051A700)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051A700 */

/* localdecomp:start func_L01_0051A768 */

extern u8 D_L01_001E244E;
extern void *func_L01_00519890(HT_8 *, u32);
s32 func_L01_0051A768(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_L01_00519890(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_L01_001E244E) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051A768 */

/* localdecomp:start func_L01_0051A838 */
extern s32 func_L01_0051A838(u8 *p, s32 a, u8 *out);
extern s32 func_003EDAF8();
extern s32 D_L01_001DC1E0_0051A838;

s32 func_L01_0051A838(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1E0_0051A838)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051A838 */

/* localdecomp:start func_L01_0051A8A0 */

extern u8 D_L01_001E244F;
extern void *func_L01_00519910(HT_8 *, u32);
s32 func_L01_0051A8A0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_L01_00519910(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_L01_001E244F) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051A8A0 */

/* localdecomp:start func_L01_0051A970 */
extern s32 func_L01_0051A970(u8 *p, s32 a, s32 b);
extern void func_003EDB08();
extern s32 D_L01_001DC1E0_0051A970;

s32 func_L01_0051A970(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1E0_0051A970)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051A970 */

/* localdecomp:start func_L01_0051A9D8 */
extern s32 func_L01_0051A9D8(u8 *p, s32 a, s32 b);
extern void func_003EDB40();
extern s32 D_L01_001DC1E0_0051A9D8;

s32 func_L01_0051A9D8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1E0_0051A9D8)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051A9D8 */

/* localdecomp:start func_L01_0051AA40 */

extern u8 D_L01_001E2450;
extern void *func_L01_00519990(HT_8 *, u32);
s32 func_L01_0051AA40(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_L01_00519990(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_L01_001E2450) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051AA40 */

INCLUDE_ASM("asm/levels", func_L01_0051AB10);

/* localdecomp:start func_L01_0051AB78 */
extern s32 func_L01_0051AB78(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);

extern s32 D_L01_001DC1E0_0051AB78;
extern V16_003E6F50 D_L01_001DC110;
s32 func_L01_0051AB78(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E6F50 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_L01_001DC1E0_0051AB78) != 0) {
        v = D_L01_001DC110;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051AB78 */

/* localdecomp:start func_L01_0051AC50 */

extern u8 D_L01_001E2451;
extern void *func_L01_00519A10(HT_8 *, u32);
s32 func_L01_0051AC50(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_L01_00519A10(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_L01_001E2451) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051AC50 */
