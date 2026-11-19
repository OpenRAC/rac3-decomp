#include "common.h"
#include "dnas.h"

/* the first library's driver: driver(block, k1, k2, k3) (include/dnas.h) */
extern void func_L39_004BD350(s32, s32, s32, u32);

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

/* localdecomp:start func_L39_004B5F68 */
extern s32 D_L39_003E43D0;
extern s32 D_L39_003E43CC;
extern s32 D_L39_003E43E0;
extern void *func_L39_004B5BE8(u32);
extern void func_L39_004B5950(char *);

void *func_L39_004B5F68(u32 size) {
    void *r;

    if (D_L39_003E43D0 != 0) {
        for (;;) {
        }
    }
    if (size + D_L39_003E438C < size) {
        r = 0;
    } else if (size <= D_L39_003E438C >> 1) {
        r = func_L39_004B5BE8(size);
    } else {
        r = (void *)func_L39_004B59D8(size);
    }
    if (D_L39_003E43CC != 0 && r == 0) {
        DNAS_BEGIN(func_L39_004B5F68, 0, func_L39_004BD350);
        func_L39_004B5950(DNAS_STRING("allocation failed."));
        DNAS_END_ONCE(func_L39_004B5F68, 0);
    }
    if (D_L39_003E43E0 != 0 && r != 0) {
        func_0011D534(r, 0, size);
    }
    return r;
}
/* localdecomp:end func_L39_004B5F68 */

INCLUDE_ASM("asm/levels", func_L39_004B6108);

INCLUDE_ASM("asm/levels", func_L39_004B6808);

/* localdecomp:start func_L39_004B7418 */
typedef struct S_004B7418 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    void *f14;
} S_004B7418;

extern s32 D_L39_004646F0;
extern u32 D_L39_004646F4;
extern s32 D_L39_003E4398;
extern s32 D_L39_003E43F0;
extern s32 D_L39_003E43F4;
extern s32 D_L39_003E43F8;
extern u8 D_L39_003E4440[];
extern s32 D_L39_003E43D4;
extern u32 D_L39_003E4380;
extern u8 D_L39_00474AE0[];
extern s32 func_00126260(S_004B7418 *);
/* func_0011D534 is memset; the file declares it void, but it returns its first argument in $v0 */
typedef void *(*memset_004B7418)(void *, s32, s32);

s32 func_L39_004B7418(void)
{
    S_004B7418 s;
    s32 n;
    s32 r;
    u32 a;

    if (D_L39_004646F0 != 0) {
        D_L39_004646F0++;
        return 0;
    }
    ((memset_004B7418)func_0011D534)(D_L39_003E4440, 0, 0x5E800);
    ((memset_004B7418)func_0011D534)(&D_L39_003E43B8, 0, 0x14);
    D_L39_003E43A8[0] = 0;
    D_L39_004646F4 = 0x10;
    D_L39_003E43D0 = 0;
    D_L39_003E438C = 0x1000;
    D_L39_003E4394 = 0xFFF;
    for (D_L39_003E4390[0] = 0; (1L << D_L39_003E4390[0]) != D_L39_003E438C; D_L39_003E4390[0]++) {
    }
    D_L39_003E4380 = (u32)D_L39_003E4440;
    D_L39_003E4384[0] = (u32)D_L39_003E4440 + 0x5E800;
    D_L39_003E4388[0] = (u32)D_L39_003E4440;
    if (D_L39_003E43E0 != 0) {
        D_L39_003E43E4 = 1;
    }
    if (D_L39_003E43E4 != 0) {
        D_L39_003E43D4 = 1;
    }
    D_L39_003E43AC = (s32 *)D_L39_003E4380;
    n = (u32)(0x5E800 >> D_L39_003E4390[0]) / (D_L39_003E438C >> 2) + 1;
    ((memset_004B7418)func_0011D534)((void *)D_L39_003E4380, 0, n * D_L39_003E438C);
    n *= D_L39_003E438C;
    D_L39_003E4388[0] += n;
    a = (D_L39_003E4388[0] + D_L39_003E4394) & ~D_L39_003E4394;
    D_L39_003E43A0[0] = a - D_L39_003E4388[0];
    D_L39_003E43A4[0] = (a >> D_L39_003E4390[0]) - D_L39_003E4390[0];
    D_L39_003E43B0[0] = (u32)n >> 2;
    if (D_L39_004646F4 == 0) {
        D_L39_004646F4 = 1;
    }
    D_L39_004646F4 <<= D_L39_003E4390[0];
    D_L39_003E43E8 = func_L39_004B5F68(0x14);
    ((memset_004B7418)func_0011D534)(&s, 0, 0x18);
    s.f8 = 1;
    s.f4 = 1;
    s.f14 = D_L39_00474AE0;
    r = func_00126260(&s);
    D_L39_003E4398 = r;
    if (r < 0) {
        return -1;
    }
    D_L39_004646F0++;
    D_L39_003E43F0 = 0;
    D_L39_003E43F4 = 0;
    D_L39_003E43F8 = 0;
    D_L39_003E4400 = 0;
    D_L39_003E43FC = 0;
    D_L39_003E4404 = 0;
    D_L39_003E4408 = 0;
    return 0;
}
/* localdecomp:end func_L39_004B7418 */

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

/* localdecomp:start func_L39_004B7748 */
extern s32 D_L39_003E4398;
extern s32 D_L39_003E43F0;
extern char *D_L39_003E43EC;
extern s32 D_L39_003E439C;
extern s32 D_L39_004646F0;
extern s32 D_L39_003E43DC;
extern s32 D_L39_003E43D8;
extern s32 func_001262A0(s32);
extern s32 func_00126280(s32);
extern void func_L39_004B5958(char *);
extern void func_L39_004B5950(char *);
extern void *func_L39_004B5F68(u32);

void *func_L39_004B7748(u32 size) {
    void *r;
    s32 old;
    char *name;

    DNAS_BEGIN(func_L39_004B7748, 0, func_L39_004BD350);
    func_001262A0(D_L39_003E4398);
    D_L39_003E43F0++;
    name = DNAS_STRING(" in _sce_dnas_malloc():");
    D_L39_003E43EC = name;
    old = D_L39_003E439C;
    if (++D_L39_003E439C != 1) {
        func_L39_004B5958(DNAS_STRING("recursive call."));
        D_L39_003E439C = old;
        goto fail;
    }
    if (D_L39_004646F0 == 0) {
        func_L39_004B5958(DNAS_STRING("call _sce_dnas_malloc_init() first."));
        goto fail;
    }
    DNAS_END_ONCE(func_L39_004B7748, 0);
    if (D_L39_003E43DC != 0 && size == 0) {
        r = 0;
    } else {
        r = func_L39_004B5F68(size);
    }
    D_L39_003E439C--;
    do { func_00126280(D_L39_003E4398); } while (0);
    if (r == 0 && (size != 0 || D_L39_003E43DC == 0) && D_L39_003E43D8 != 0) {
        DNAS_BEGIN(func_L39_004B7748, 1, func_L39_004BD350);
        func_L39_004B5950(DNAS_STRING("out of memory."));
        DNAS_END_ONCE(func_L39_004B7748, 1);
    }
    return r;
fail:
    do { func_00126280(D_L39_003E4398); } while (0);
    return 0;
}
/* localdecomp:end func_L39_004B7748 */

/* localdecomp:start func_L39_004B7A80 */
extern s32 D_L39_003E4398;
extern s32 D_L39_003E43F8;
extern char *D_L39_003E43EC;
extern s32 D_L39_003E439C;
extern s32 func_001262A0(s32);
extern s32 func_00126280(s32);
extern void func_L39_004B5958(char *);

void func_L39_004B7A80(S_004B59D8 *ptr) {
    s32 old;
    char *name;

    DNAS_BEGIN(func_L39_004B7A80, 0, func_L39_004BD350);
    func_001262A0(D_L39_003E4398);
    D_L39_003E43F8++;
    name = DNAS_STRING(" in _sce_dnas_free():");
    D_L39_003E43EC = name;
    old = D_L39_003E439C;
    if (++D_L39_003E439C != 1) {
        func_L39_004B5958(DNAS_STRING("recursive call."));
        D_L39_003E439C = old;
        goto out;
    }
    func_L39_004B6808(ptr);
    D_L39_003E439C--;
    DNAS_END_ONCE(func_L39_004B7A80, 0);
out:
    do { func_00126280(D_L39_003E4398); } while (0);
}
/* localdecomp:end func_L39_004B7A80 */

/* localdecomp:start func_L39_004B7C20 */
extern s32 D_L39_003E43F4;
extern void *func_L39_004B6108(void *, u32);

void *func_L39_004B7C20(void *ptr, u32 size) {
    void *r;
    s32 old;
    char *name;

    DNAS_BEGIN(func_L39_004B7C20, 0, func_L39_004BD350);
    func_001262A0(D_L39_003E4398);
    D_L39_003E43F4++;
    name = DNAS_STRING(" in _sce_dnas_realloc():");
    D_L39_003E43EC = name;
    old = D_L39_003E439C;
    if (++D_L39_003E439C != 1) {
        func_L39_004B5958(DNAS_STRING("recursive call."));
        D_L39_003E439C = old;
        goto fail;
    }
    if (ptr != 0 && D_L39_004646F0 == 0) {
        func_L39_004B5958(DNAS_STRING("malloc() has never been called."));
        ptr = 0;
    }
    if (D_L39_004646F0 == 0) {
        func_L39_004B5958(DNAS_STRING("call _sce_dnas_malloc_init() first."));
        goto fail;
    }
    DNAS_END_ONCE(func_L39_004B7C20, 0);
    if (D_L39_003E43DC != 0 && size == 0) {
        func_L39_004B6808(ptr);
        r = 0;
    } else if (ptr == 0) {
        r = func_L39_004B5F68(size);
    } else {
        r = func_L39_004B6108(ptr, size);
    }
    D_L39_003E439C--;
    do { func_00126280(D_L39_003E4398); } while (0);
    if (r == 0 && (size != 0 || D_L39_003E43DC == 0) && D_L39_003E43D8 != 0) {
        DNAS_BEGIN(func_L39_004B7C20, 1, func_L39_004BD350);
        func_L39_004B5950(DNAS_STRING("out of memory."));
        DNAS_END_ONCE(func_L39_004B7C20, 1);
    }
    return r;
fail:
    do { func_00126280(D_L39_003E4398); } while (0);
    return 0;
}
/* localdecomp:end func_L39_004B7C20 */

/* localdecomp:start func_L39_004B7FF0 */
extern u32 D_L39_003E438C;

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
    return (s32)func_L39_004B7748(y < x ? x : y);
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
