#include "common.h"

typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
typedef struct { u32 key; void *val; } HE_003E4890;
typedef struct { s32 f0; s32 n; HE_003E4890 e[3]; } HT_003E4890;

/* localdecomp:start func_L01_005195E0 */
extern void func_L01_00516438_005195E0();
 
void func_L01_005195E0(void) {
    func_L01_00516438_005195E0();
}
/* localdecomp:end func_L01_005195E0 */

/* localdecomp:start func_L01_00519600 */
extern u8 D_L01_001E2449;
void *func_L01_00519600(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E2449) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519600 */

/* localdecomp:start func_L01_00519680 */
extern u8 D_L01_001E244A;
void *func_L01_00519680(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E244A) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519680 */

/* localdecomp:start func_L01_00519700 */
extern u8 D_L01_001E244B;
void *func_L01_00519700(HT_003E4890 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_L01_001E244B;
    off = 0;
    for (; i < 3; i++) {
        h = ((key % three) + off) % three;
        v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != sent) return v;
        u = off + 1;
        off = (key & 1) + u;
    }
    return 0;
}
/* localdecomp:end func_L01_00519700 */

/* localdecomp:start func_L01_00519788 */
extern u8 D_L01_001E244C;
void *func_L01_00519788(HT_003E4890 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_L01_001E244C;
    off = 0;
    for (; i < 3; i++) {
        h = ((key % three) + off) % three;
        v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != sent) return v;
        u = off + 1;
        off = (key & 1) + u;
    }
    return 0;
}
/* localdecomp:end func_L01_00519788 */

/* localdecomp:start func_L01_00519810 */
extern u8 D_L01_001E244D;
void *func_L01_00519810(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E244D) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519810 */

/* localdecomp:start func_L01_00519890 */
extern u8 D_L01_001E244E;
void *func_L01_00519890(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E244E) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519890 */

/* localdecomp:start func_L01_00519910 */
extern u8 D_L01_001E244F;
void *func_L01_00519910(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E244F) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519910 */

/* localdecomp:start func_L01_00519990 */
extern u8 D_L01_001E2450;
void *func_L01_00519990(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E2450) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519990 */

/* localdecomp:start func_L01_00519A10 */
extern u8 D_L01_001E2451;
void *func_L01_00519A10(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E2451) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519A10 */

/* localdecomp:start func_L01_00519A90 */
extern u8 D_L01_001E2452;
void *func_L01_00519A90(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E2452) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519A90 */

/* localdecomp:start func_L01_00519B10 */
extern u8 D_L01_001E2453;
void *func_L01_00519B10(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E2453) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519B10 */

/* localdecomp:start func_L01_00519B90 */
extern u8 D_L01_001E2454;
void *func_L01_00519B90(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E2454) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519B90 */

/* localdecomp:start func_L01_00519C10 */
extern u8 D_L01_001E2455;
void *func_L01_00519C10(HT_003E4890 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_L01_001E2455;
    off = 0;
    for (; i < 3; i++) {
        h = ((key % three) + off) % three;
        v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != sent) return v;
        u = off + 1;
        off = (key & 1) + u;
    }
    return 0;
}
/* localdecomp:end func_L01_00519C10 */

/* localdecomp:start func_L01_00519C98 */
extern u8 D_L01_001E2456;
void *func_L01_00519C98(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E2456) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519C98 */

/* localdecomp:start func_L01_00519D18 */
extern u8 D_L01_001E2457;
void *func_L01_00519D18(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E2457) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519D18 */

/* localdecomp:start func_L01_00519D98 */
extern u8 D_L01_001E2458;
void *func_L01_00519D98(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E2458) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519D98 */

/* localdecomp:start func_L01_00519E18 */
extern u8 D_L01_001E2459;
void *func_L01_00519E18(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E2459) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519E18 */

/* localdecomp:start func_L01_00519E98 */
extern u8 D_L01_001E245A;
void *func_L01_00519E98(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_L01_001E245A) return v;
    }
    return 0;
}
/* localdecomp:end func_L01_00519E98 */
