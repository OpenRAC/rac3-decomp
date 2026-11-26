/* PAL near miss (k6 a5, 2026-11-26): phkmalloc's irealloc() as Sony's DNAS allocator has it (five
 * protected blocks). 1 difference: the delay slot of the `(ptr + D_L39_003E43A0) & D_L39_003E4394`
 * test, where retail has `beqz` + the loop's first `addiu $a1, $a1, 4` and this gives `beql`
 * (annulled). The same branch-likely choice is left in func_L39_004B6808 and appears in
 * func_L39_004B5BE8 under -fno-strict-aliasing, so it looks like a reorg (delay-slot) question,
 * not a C one. Tried without effect: the size loop as for/while/do with ++mp before or after the
 * check, -fno-sched-interblock/-spec, -fno-thread-jumps; ~40,000 permuter iterations. */
#include "common.h"
/* localdecomp:start func_L39_004B6108 */
/* irealloc() of phkmalloc (FreeBSD's malloc), as Sony's DNAS allocator has it */
extern u32 D_L39_003E43A8[];
extern s32 D_L39_003E43D4;
extern void func_0011D380(void *, void *, u32);
extern void func_L39_004B5958(char *);

void *func_L39_004B6108(void *ptr, u32 size) {
    void *p;
    u32 osize;
    u32 index;
    s32 *mp;
    u32 i;

    if (D_L39_003E43D0 != 0) {
        for (;;) {
        }
    }
    index = (((u32)ptr + D_L39_003E43A0[0]) >> D_L39_003E4390[0]) - D_L39_003E43A4[0];
    DNAS_BEGIN(func_L39_004B6108, 0, func_L39_004BD350);
    if (index < D_L39_003E4390[0]) {
        func_L39_004B5958(DNAS_STRING("junk pointer, too low to make sense."));
        return 0;
    }
    if (index > D_L39_003E43A8[0]) {
        func_L39_004B5958(DNAS_STRING("junk pointer, too high to make sense."));
        return 0;
    }
    DNAS_END_ONCE(func_L39_004B6108, 0);
    mp = &D_L39_003E43AC[index];
    if (*mp == 2) {
        if (((u32)ptr + D_L39_003E43A0[0]) & D_L39_003E4394) {
            DNAS_BEGIN(func_L39_004B6108, 1, func_L39_004BD350);
            func_L39_004B5958(DNAS_STRING("modified (page-) pointer."));
            DNAS_END_ONCE(func_L39_004B6108, 1);
            return 0;
        }
        for (osize = D_L39_003E438C, mp++; *mp == 3; mp++) {
            osize += D_L39_003E438C;
        }
        if (!D_L39_003E43D4 && size <= osize && size > osize - D_L39_003E438C) {
            return ptr;
        }
    } else if ((u32)*mp >= 4) {
        P_004B5BE8 *info = (P_004B5BE8 *)*mp;
        if (((u32)ptr + D_L39_003E43A0[0]) & (info->size - 1)) {
            DNAS_BEGIN(func_L39_004B6108, 2, func_L39_004BD350);
            func_L39_004B5958(DNAS_STRING("modified (page-) pointer."));
            DNAS_END_ONCE(func_L39_004B6108, 2);
            return 0;
        }
        i = (((u32)ptr + D_L39_003E43A0[0]) & D_L39_003E4394) >> info->shift;
        if (info->bitmap[i / 32] & (1 << (i % 32))) {
            DNAS_BEGIN(func_L39_004B6108, 3, func_L39_004BD350);
            func_L39_004B5958(DNAS_STRING("chunk is already free."));
            DNAS_END_ONCE(func_L39_004B6108, 3);
            return 0;
        }
        osize = info->size;
        if (!D_L39_003E43D4 && size < osize && (size > osize / 2 || osize == 16)) {
            return ptr;
        }
    } else {
        DNAS_BEGIN(func_L39_004B6108, 4, func_L39_004BD350);
        func_L39_004B5958(DNAS_STRING("pointer to wrong page."));
        DNAS_END_ONCE(func_L39_004B6108, 4);
        return 0;
    }
    p = func_L39_004B5F68(size);
    if (p) {
        if (!size || !osize)
            ;
        else if (osize < size)
            func_0011D380(p, ptr, osize);
        else
            func_0011D380(p, ptr, size);
        func_L39_004B6808((S_004B59D8 *)ptr);
    }
    return p;
}
/* localdecomp:end func_L39_004B6108 */
