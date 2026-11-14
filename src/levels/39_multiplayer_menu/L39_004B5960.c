#include "common.h"

/* localdecomp:start func_L39_004B5960 */
extern u32 D_L39_003E4384[];
extern u32 D_L39_003E4388[];
extern u32 D_L39_003E4390[];
extern u32 D_L39_003E43A0[];
extern u32 D_L39_003E43A4[];
extern u32 D_L39_003E43A8[];
extern u32 D_L39_003E43B0[];

u32 func_L39_004B5960(u32 arg0) {
    u32 cur = D_L39_003E4388[0];
    u32 next = cur + (arg0 << D_L39_003E4390[0]);
    u32 t;

    if (next > D_L39_003E4384[0]) {
        return 0;
    }
    D_L39_003E4388[0] = next;
    t = ((next + D_L39_003E43A0[0]) >> D_L39_003E4390[0]) - D_L39_003E43A4[0];
    D_L39_003E43A8[0] = t - 1;
    return t < D_L39_003E43B0[0] ? cur : 0;
}
/* localdecomp:end func_L39_004B5960 */

/* localdecomp:start func_L39_004B59D8 */
typedef struct S_004B59D8 {
    struct S_004B59D8 *next;
    struct S_004B59D8 *prev;
    u32 addr;
    u32 pad;
    u32 size;
} S_004B59D8;

extern u32 D_L39_003E4394;
extern S_004B59D8 *D_L39_003E43B8;
extern s32 *D_L39_003E43AC;
extern s32 D_L39_003E43E4;
extern u32 D_L39_003E4400;
extern u32 D_L39_003E4404;
extern u32 D_L39_003E4408;
extern u32 D_L39_003E438C;
extern u32 D_L39_003E43FC;
extern S_004B59D8 *D_L39_003E43E8;
extern void func_0011D534(void *, s32, s32);
extern void func_L39_004B6808(S_004B59D8 *);

u32 func_L39_004B59D8(u32 size)
{
    S_004B59D8 *node;
    S_004B59D8 *found;
    u32 ptr;
    u32 i;
    s32 idx;

    size = (size + D_L39_003E4394) & ~D_L39_003E4394;
    ptr = 0;
    found = 0;
    for (node = D_L39_003E43B8; node != 0; node = node->next) {
        if (node->size >= size) {
            if (node->size == size) {
                ptr = node->addr;
                if (node->next != 0) {
                    node->next->prev = node->prev;
                }
                node->prev->next = node->next;
                found = node;
            } else {
                node->size -= size;
                ptr = node->addr;
                node->addr = ptr + size;
            }
            break;
        }
    }
    size >>= D_L39_003E4390[0];
    if (ptr == 0) {
        ptr = func_L39_004B5960(size);
    }
    if (ptr != 0) {
        idx = ((ptr + D_L39_003E43A0[0]) >> D_L39_003E4390[0]) - D_L39_003E43A4[0];
        D_L39_003E43AC[idx] = 2;
        for (i = 1; i < size; i++) {
            D_L39_003E43AC[idx + i] = 3;
        }
        if (D_L39_003E43E4 != 0) {
            func_0011D534((void *)ptr, 0xD0, size << D_L39_003E4390[0]);
        }
        D_L39_003E4400 += size;
        if (D_L39_003E4408 < D_L39_003E4400) {
            D_L39_003E4408 = D_L39_003E4400;
            D_L39_003E4404 = D_L39_003E4408 * D_L39_003E438C;
        }
        D_L39_003E43FC += size * D_L39_003E438C;
    }
    if (found != 0) {
        if (D_L39_003E43E8 == 0) {
            D_L39_003E43E8 = found;
        } else {
            func_L39_004B6808(found);
        }
    }
    return ptr;
}
/* localdecomp:end func_L39_004B59D8 */

INCLUDE_ASM("asm/levels", func_L39_004B5BE8);

INCLUDE_ASM("asm/levels", func_L39_004B5F68);

INCLUDE_ASM("asm/levels", func_L39_004B6108);

INCLUDE_ASM("asm/levels", func_L39_004B6808);

INCLUDE_ASM("asm/levels", func_L39_004B7418);

/* localdecomp:start func_L39_004B76F8 */
extern s32 D_L39_004646F0;
extern s32 D_L39_003E4398;
void func_00126270(s32);
void func_L39_004B76F8(void) {
    if (--D_L39_004646F0 == 0) {
        func_00126270(D_L39_003E4398);
    }
}
/* localdecomp:end func_L39_004B76F8 */

INCLUDE_ASM("asm/levels", func_L39_004B7748);

INCLUDE_ASM("asm/levels", func_L39_004B7A80);

INCLUDE_ASM("asm/levels", func_L39_004B7C20);

/* localdecomp:start func_L39_004B7FF0 */
extern u32 D_L39_003E438C;
extern s32 func_L39_004B7748(u32);

s32 func_L39_004B7FF0(u32 x, u32 y) {
    u32 m;

    if (D_L39_003E438C < x) {
        return 0;
    }
    for (m = 2; m < D_L39_003E438C; m <<= 1) {
        if (x & m) {
            if (x & ~m) {
                return 0;
            }
            break;
        }
    }
    return func_L39_004B7748(y < x ? x : y);
}
/* localdecomp:end func_L39_004B7FF0 */

/* localdecomp:start func_L39_004B80A0 */
extern s32 D_L39_00464688;
extern s32 D_L39_00464784_004B80A0;
extern void func_00126290(s32);

s32 func_L39_004B80A0(void) {
    func_00126290(D_L39_00464688);
    D_L39_00464784_004B80A0 = -1;
    return 0;
}
/* localdecomp:end func_L39_004B80A0 */

/* localdecomp:start func_L39_004B80D8 */
typedef struct S_004B80D8 {
    u8 pad0[0x410];
    long x410;
    u8 pad418[0x106F8 - 0x418];
    s32 x106F8;
} S_004B80D8;
typedef struct S2_004B80D8 {
    s32 id;
    s32 pad[3];
} S2_004B80D8;
extern S_004B80D8 D_L39_00453FB0;
extern S2_004B80D8 D_L39_00464784;
extern s32 D_L39_004B80A0[];
extern s32 func_0012E2B8(long, void *, s32);

s32 func_L39_004B80D8(void) {
    S_004B80D8 *g = &D_L39_00453FB0;
    S2_004B80D8 *p;

    if (g->x410 != 0) {
        p = &D_L39_00464784;
        if (p->id < 0 && g->x106F8 == 0) {
            return p->id = func_0012E2B8(g->x410, D_L39_004B80A0, 0);
        }
    }
    return -1;
}
/* localdecomp:end func_L39_004B80D8 */

/* localdecomp:start func_L39_004B8150 */
extern s32 func_0012E4D8(s32);

s32 func_L39_004B8150(void) {
    S2_004B80D8 *p = &D_L39_00464784;
    s32 v = p->id;
    if (v >= 0) {
        func_0012E4D8(v);
        p->id = -1;
    }
}
/* localdecomp:end func_L39_004B8150 */

/* localdecomp:start func_L39_004B8190 */
extern void func_L39_004B8208();
extern void func_L39_004B8A30();
extern void func_L39_004B9078();
extern void func_L39_004B92B8();
extern void func_L39_004B9350();
extern void func_L39_004B93F8();
extern void func_L39_004B9570();
extern void func_L39_004B96D0();
extern void func_L39_004B9C78();

s32 func_L39_004B8190(void **tbl) {
    tbl[0] = func_L39_004B8208;
    tbl[1] = func_L39_004B8A30;
    tbl[2] = func_L39_004B9078;
    tbl[3] = func_L39_004B92B8;
    tbl[4] = func_L39_004B9350;
    tbl[5] = func_L39_004B93F8;
    tbl[6] = func_L39_004B9570;
    tbl[7] = func_L39_004B96D0;
    tbl[8] = func_L39_004B9C78;
    return 0;
}
/* localdecomp:end func_L39_004B8190 */

INCLUDE_ASM("asm/levels", func_L39_004B8208);
