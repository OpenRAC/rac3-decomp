#include "common.h"

/* localdecomp:start func_L39_0061E3B8 */
struct S_0061E3B8;

typedef struct {
    u8 pad[8];
    void (*init)(struct S_0061E3B8 *);
    void (*fn)(struct S_0061E3B8 *);
} V_0061E3B8;

typedef struct S_0061E3B8 {
    u32 uid;
    struct S_0061E3B8 *next;
    struct S_0061E3B8 *prev;
    V_0061E3B8 *vt;
} S_0061E3B8;

/* The used and free list heads of the 8 guber types, as one table. */
typedef struct {
    S_0061E3B8 *used[8];
    S_0061E3B8 *free[8];
} Lists_0061E3B8;

extern Lists_0061E3B8 D_L39_0024CEA0_0061E3B8 __attribute__((section(".sdata")));
extern u8 *D_L39_0024CEE0[8] __attribute__((section(".sdata")));
extern const s32 D_L39_00245FB0_0061E3B8[8] __attribute__((section(".sdata")));
extern s32 D_L39_00245FD0[8] __attribute__((section(".sdata")));
extern S_0061E3B8 D_L39_0034DB28[];
extern V_0061E3B8 D_L39_00245F98[] __attribute__((section(".sdata")));

void func_L39_0061E3B8(s32 type) {
    s32 i;
    S_0061E3B8 *p;

    D_L39_0024CEA0_0061E3B8.used[type] = 0;
    D_L39_0024CEE0[type] = (u8 *)D_L39_0034DB28;
    D_L39_0024CEA0_0061E3B8.free[type] = D_L39_0034DB28;
    for (i = 0; i < D_L39_00245FB0_0061E3B8[type]; i++) {
        p = (S_0061E3B8 *)(D_L39_0024CEE0[type] + i * D_L39_00245FD0[type]);
        p->vt = D_L39_00245F98;
        if (i == 0) {
            p->prev = 0;
        } else {
            p->prev = (S_0061E3B8 *)(D_L39_0024CEE0[type] + (i - 1) * D_L39_00245FD0[type]);
        }
        if (i == D_L39_00245FB0_0061E3B8[type] - 1) {
            p->next = 0;
        } else {
            p->next = (S_0061E3B8 *)(D_L39_0024CEE0[type] + (i + 1) * D_L39_00245FD0[type]);
        }
    }
}
/* localdecomp:end func_L39_0061E3B8 */

/* localdecomp:start func_L39_0061E4D0 */
struct S_0061E4D0;

typedef struct {
    u8 pad[8];
    void (*init)(struct S_0061E4D0 *);
    void (*fn)(struct S_0061E4D0 *);
} V_0061E4D0;

typedef struct S_0061E4D0 {
    u32 uid;
    struct S_0061E4D0 *next;
    struct S_0061E4D0 *prev;
    V_0061E4D0 *vt;
} S_0061E4D0;

/* The used and free list heads of the 8 guber types, as one table. */
typedef struct {
    S_0061E4D0 *used[8];
    S_0061E4D0 *free[8];
} Lists_0061E4D0;

extern Lists_0061E4D0 D_L39_0024CEA0_0061E4D0 __attribute__((section(".sdata")));
extern u8 *D_L39_0024CEE0_0061E4D0[8] __attribute__((section(".sdata")));
extern const s32 D_L39_00245FB0_0061E4D0[8] __attribute__((section(".sdata")));
extern s32 D_L39_00245FD0_0061E4D0[8] __attribute__((section(".sdata")));
extern S_0061E4D0 D_L39_0034DB40_0061E4D0[];
extern V_0061E4D0 D_L39_00245F50_0061E4D0[] __attribute__((section(".sdata")));

void func_L39_0061E4D0(s32 type) {
    s32 i;
    S_0061E4D0 *p;

    D_L39_0024CEA0_0061E4D0.used[type] = 0;
    D_L39_0024CEE0_0061E4D0[type] = (u8 *)D_L39_0034DB40_0061E4D0;
    D_L39_0024CEA0_0061E4D0.free[type] = D_L39_0034DB40_0061E4D0;
    for (i = 0; i < D_L39_00245FB0_0061E4D0[type]; i++) {
        p = (S_0061E4D0 *)(D_L39_0024CEE0_0061E4D0[type] + i * D_L39_00245FD0_0061E4D0[type]);
        p->vt = D_L39_00245F50_0061E4D0;
        if (i == 0) {
            p->prev = 0;
        } else {
            p->prev = (S_0061E4D0 *)(D_L39_0024CEE0_0061E4D0[type] + (i - 1) * D_L39_00245FD0_0061E4D0[type]);
        }
        if (i == D_L39_00245FB0_0061E4D0[type] - 1) {
            p->next = 0;
        } else {
            p->next = (S_0061E4D0 *)(D_L39_0024CEE0_0061E4D0[type] + (i + 1) * D_L39_00245FD0_0061E4D0[type]);
        }
    }
}
/* localdecomp:end func_L39_0061E4D0 */

/* localdecomp:start func_L39_0061E5E8 */
struct S_0061E5E8;
typedef struct {
    u8 pad[8];
    void (*init)(struct S_0061E5E8 *);
    void (*fn)(struct S_0061E5E8 *);
} V_0061E5E8;
typedef struct S_0061E5E8 {
    u32 uid;
    struct S_0061E5E8 *next;
    struct S_0061E5E8 *prev;
    V_0061E5E8 *vt;
} S_0061E5E8;
typedef struct {
    S_0061E5E8 *used[8];
    S_0061E5E8 *free[8];
} Lists_0061E5E8;

extern Lists_0061E5E8 D_L39_0024CEA0_0061E5E8 __attribute__((section(".sdata")));
extern u8 *D_L39_0024CEE0_0061E5E8[8] __attribute__((section(".sdata")));
extern const s32 D_L39_00245FB0_0061E5E8[8] __attribute__((section(".sdata")));
extern s32 D_L39_00245FD0_0061E5E8[8] __attribute__((section(".sdata")));
extern S_0061E5E8 D_L39_0034DB38_0061E5E8[];
extern V_0061E5E8 D_L39_00245F68_0061E5E8[] __attribute__((section(".sdata")));

void func_L39_0061E5E8(s32 type) {
    s32 i;
    S_0061E5E8 *p;

    D_L39_0024CEA0_0061E5E8.used[type] = 0;
    D_L39_0024CEE0_0061E5E8[type] = (u8 *)D_L39_0034DB38_0061E5E8;
    D_L39_0024CEA0_0061E5E8.free[type] = D_L39_0034DB38_0061E5E8;
    for (i = 0; i < D_L39_00245FB0_0061E5E8[type]; i++) {
        p = (S_0061E5E8 *)(D_L39_0024CEE0_0061E5E8[type] + i * D_L39_00245FD0_0061E5E8[type]);
        p->vt = D_L39_00245F68_0061E5E8;
        if (i == 0) {
            p->prev = 0;
        } else {
            p->prev = (S_0061E5E8 *)(D_L39_0024CEE0_0061E5E8[type] + (i - 1) * D_L39_00245FD0_0061E5E8[type]);
        }
        if (i == D_L39_00245FB0_0061E5E8[type] - 1) {
            p->next = 0;
        } else {
            p->next = (S_0061E5E8 *)(D_L39_0024CEE0_0061E5E8[type] + (i + 1) * D_L39_00245FD0_0061E5E8[type]);
        }
    }
}
/* localdecomp:end func_L39_0061E5E8 */

/* localdecomp:start func_L39_0061E700 */
extern s32 D_L39_00245FD0_0061E700[8] __attribute__((section(".sdata")));
struct S_0061E3B8_0061E700;

typedef struct {
    u8 pad[8];
    void (*init)(struct S_0061E3B8_0061E700 *);
    void (*fn)(struct S_0061E3B8_0061E700 *);
} V_0061E3B8_0061E700;

typedef struct S_0061E3B8_0061E700 {
    u32 uid;
    struct S_0061E3B8_0061E700 *next;
    struct S_0061E3B8_0061E700 *prev;
    V_0061E3B8_0061E700 *vt;
} S_0061E3B8_0061E700;

/* The used and free list heads of the 8 guber types, as one table. */
typedef struct {
    S_0061E3B8_0061E700 *used[8];
    S_0061E3B8_0061E700 *free[8];
} Lists_0061E3B8_0061E700;

extern Lists_0061E3B8_0061E700 D_L39_0024CEA0_0061E700 __attribute__((section(".sdata")));
extern u8 *D_L39_0024CEE0_0061E700[8] __attribute__((section(".sdata")));
extern const s32 D_L39_00245FB0_0061E3B8[8] __attribute__((section(".sdata")));
extern S_0061E3B8_0061E700 D_L39_0034DB30_0061E700[];
extern V_0061E3B8_0061E700 D_L39_00245F80_0061E700[] __attribute__((section(".sdata")));

void func_L39_0061E700(s32 type) {
    s32 i;
    S_0061E3B8_0061E700 *p;

    D_L39_0024CEA0_0061E700.used[type] = 0;
    D_L39_0024CEE0_0061E700[type] = (u8 *)D_L39_0034DB30_0061E700;
    D_L39_0024CEA0_0061E700.free[type] = D_L39_0034DB30_0061E700;
    for (i = 0; i < D_L39_00245FB0_0061E3B8[type]; i++) {
        p = (S_0061E3B8_0061E700 *)(D_L39_0024CEE0_0061E700[type] + i * D_L39_00245FD0_0061E700[type]);
        p->vt = D_L39_00245F80_0061E700;
        if (i == 0) {
            p->prev = 0;
        } else {
            p->prev = (S_0061E3B8_0061E700 *)(D_L39_0024CEE0_0061E700[type] + (i - 1) * D_L39_00245FD0_0061E700[type]);
        }
        if (i == D_L39_00245FB0_0061E3B8[type] - 1) {
            p->next = 0;
        } else {
            p->next = (S_0061E3B8_0061E700 *)(D_L39_0024CEE0_0061E700[type] + (i + 1) * D_L39_00245FD0_0061E700[type]);
        }
    }
}
/* localdecomp:end func_L39_0061E700 */

/* localdecomp:start func_L39_0061E818 */
struct S_0061E818;

typedef struct {
    u8 pad[8];
    void (*init)(struct S_0061E818 *);
    void (*fn)(struct S_0061E818 *);
} V_0061E818;

typedef struct S_0061E818 {
    u32 uid;
    struct S_0061E818 *next;
    struct S_0061E818 *prev;
    V_0061E818 *vt;
} S_0061E818;

/* The used and free list heads of the 8 guber types, as one table. */
typedef struct {
    S_0061E818 *used[8];
    S_0061E818 *free[8];
} Lists_0061E818;

extern Lists_0061E818 D_L39_0024CEA0_0061E818 __attribute__((section(".sdata")));
extern u8 *D_L39_0024CEE0[8] __attribute__((section(".sdata")));
extern const s32 D_L39_00245FB0_0061E818[8] __attribute__((section(".sdata")));
extern s32 D_L39_00245FD0[8] __attribute__((section(".sdata")));
extern S_0061E818 D_L39_0034DB48[];
extern V_0061E818 D_L39_00245F38[] __attribute__((section(".sdata")));

void func_L39_0061E818(s32 type) {
    s32 i;
    S_0061E818 *p;

    D_L39_0024CEA0_0061E818.used[type] = 0;
    D_L39_0024CEE0[type] = (u8 *)D_L39_0034DB48;
    D_L39_0024CEA0_0061E818.free[type] = D_L39_0034DB48;
    for (i = 0; i < D_L39_00245FB0_0061E818[type]; i++) {
        p = (S_0061E818 *)(D_L39_0024CEE0[type] + i * D_L39_00245FD0[type]);
        p->vt = D_L39_00245F38;
        if (i == 0) {
            p->prev = 0;
        } else {
            p->prev = (S_0061E818 *)(D_L39_0024CEE0[type] + (i - 1) * D_L39_00245FD0[type]);
        }
        if (i == D_L39_00245FB0_0061E818[type] - 1) {
            p->next = 0;
        } else {
            p->next = (S_0061E818 *)(D_L39_0024CEE0[type] + (i + 1) * D_L39_00245FD0[type]);
        }
    }
}
/* localdecomp:end func_L39_0061E818 */

/* localdecomp:start func_L39_0061E930 */
struct S_0061E930;

typedef struct {
    u8 pad[8];
    void (*init)(struct S_0061E930 *);
    void (*fn)(struct S_0061E930 *);
} V_0061E930;

typedef struct S_0061E930 {
    u32 uid;
    struct S_0061E930 *next;
    struct S_0061E930 *prev;
    V_0061E930 *vt;
} S_0061E930;

/* The used and free list heads of the 8 guber types, as one table. */
typedef struct {
    S_0061E930 *used[8];
    S_0061E930 *free[8];
} Lists_0061E930;

extern Lists_0061E930 D_L39_0024CEA0_0061E930 __attribute__((section(".sdata")));
extern u8 *D_L39_0024CEE0[8] __attribute__((section(".sdata")));
extern const s32 D_L39_00245FB0_0061E930[8] __attribute__((section(".sdata")));
extern s32 D_L39_00245FD0[8] __attribute__((section(".sdata")));
extern S_0061E930 D_L39_0034DB50[];
extern V_0061E930 D_L39_00246370[] __attribute__((section(".sdata")));

void func_L39_0061E930(s32 type) {
    s32 i;
    S_0061E930 *p;

    D_L39_0024CEA0_0061E930.used[type] = 0;
    D_L39_0024CEE0[type] = (u8 *)D_L39_0034DB50;
    D_L39_0024CEA0_0061E930.free[type] = D_L39_0034DB50;
    for (i = 0; i < D_L39_00245FB0_0061E930[type]; i++) {
        p = (S_0061E930 *)(D_L39_0024CEE0[type] + i * D_L39_00245FD0[type]);
        p->vt = D_L39_00246370;
        if (i == 0) {
            p->prev = 0;
        } else {
            p->prev = (S_0061E930 *)(D_L39_0024CEE0[type] + (i - 1) * D_L39_00245FD0[type]);
        }
        if (i == D_L39_00245FB0_0061E930[type] - 1) {
            p->next = 0;
        } else {
            p->next = (S_0061E930 *)(D_L39_0024CEE0[type] + (i + 1) * D_L39_00245FD0[type]);
        }
    }
}
/* localdecomp:end func_L39_0061E930 */

/* localdecomp:start func_L39_0061EA48 */
struct S_0061EA48;

typedef struct {
    u8 pad[8];
    void (*init)(struct S_0061EA48 *);
    void (*fn)(struct S_0061EA48 *);
} V_0061EA48;

typedef struct S_0061EA48 {
    u32 uid;
    struct S_0061EA48 *next;
    struct S_0061EA48 *prev;
    V_0061EA48 *vt;
} S_0061EA48;

/* The used and free list heads of the 8 guber types, as one table. */
typedef struct {
    S_0061EA48 *used[8];
    S_0061EA48 *free[8];
} Lists_0061EA48;

extern Lists_0061EA48 D_L39_0024CEA0_0061EA48 __attribute__((section(".sdata")));
extern u8 *D_L39_0024CEE0[8] __attribute__((section(".sdata")));
extern const s32 D_L39_00245FB0_0061EA48[8] __attribute__((section(".sdata")));
extern s32 D_L39_00245FD0[8] __attribute__((section(".sdata")));
extern S_0061EA48 D_L39_0034DB58[];
extern V_0061EA48 D_L39_00245F20[] __attribute__((section(".sdata")));

void func_L39_0061EA48(s32 type) {
    s32 i;
    S_0061EA48 *p;

    D_L39_0024CEA0_0061EA48.used[type] = 0;
    D_L39_0024CEE0[type] = (u8 *)D_L39_0034DB58;
    D_L39_0024CEA0_0061EA48.free[type] = D_L39_0034DB58;
    for (i = 0; i < D_L39_00245FB0_0061EA48[type]; i++) {
        p = (S_0061EA48 *)(D_L39_0024CEE0[type] + i * D_L39_00245FD0[type]);
        p->vt = D_L39_00245F20;
        if (i == 0) {
            p->prev = 0;
        } else {
            p->prev = (S_0061EA48 *)(D_L39_0024CEE0[type] + (i - 1) * D_L39_00245FD0[type]);
        }
        if (i == D_L39_00245FB0_0061EA48[type] - 1) {
            p->next = 0;
        } else {
            p->next = (S_0061EA48 *)(D_L39_0024CEE0[type] + (i + 1) * D_L39_00245FD0[type]);
        }
    }
}
/* localdecomp:end func_L39_0061EA48 */

/* localdecomp:start func_L39_0061EB60 */
struct S_0061EB60;

typedef struct {
    u8 pad[8];
    void (*init)(struct S_0061EB60 *);
    void (*fn)(struct S_0061EB60 *);
} V_0061EB60;

typedef struct S_0061EB60 {
    u32 uid;
    struct S_0061EB60 *next;
    struct S_0061EB60 *prev;
    V_0061EB60 *vt;
} S_0061EB60;

/* The used and free list heads of the 8 guber types, as one table. */
typedef struct {
    S_0061EB60 *used[8];
    S_0061EB60 *free[8];
} Lists_0061EB60;

extern Lists_0061EB60 D_L39_0024CEA0_0061EB60 __attribute__((section(".sdata")));
extern u8 *D_L39_0024CEE0[8] __attribute__((section(".sdata")));
extern const s32 D_L39_00245FB0_0061EB60[8] __attribute__((section(".sdata")));
extern s32 D_L39_00245FD0[8] __attribute__((section(".sdata")));
extern S_0061EB60 D_L39_0034DB60[];
extern V_0061EB60 D_L39_00246388[] __attribute__((section(".sdata")));

void func_L39_0061EB60(s32 type) {
    s32 i;
    S_0061EB60 *p;

    D_L39_0024CEA0_0061EB60.used[type] = 0;
    D_L39_0024CEE0[type] = (u8 *)D_L39_0034DB60;
    D_L39_0024CEA0_0061EB60.free[type] = D_L39_0034DB60;
    for (i = 0; i < D_L39_00245FB0_0061EB60[type]; i++) {
        p = (S_0061EB60 *)(D_L39_0024CEE0[type] + i * D_L39_00245FD0[type]);
        p->vt = D_L39_00246388;
        if (i == 0) {
            p->prev = 0;
        } else {
            p->prev = (S_0061EB60 *)(D_L39_0024CEE0[type] + (i - 1) * D_L39_00245FD0[type]);
        }
        if (i == D_L39_00245FB0_0061EB60[type] - 1) {
            p->next = 0;
        } else {
            p->next = (S_0061EB60 *)(D_L39_0024CEE0[type] + (i + 1) * D_L39_00245FD0[type]);
        }
    }
}
/* localdecomp:end func_L39_0061EB60 */

ASM_FUNC("asm/levels", func_L39_0061EC78);
